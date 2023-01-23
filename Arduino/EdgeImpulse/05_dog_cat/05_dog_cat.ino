/*
* Пример использования Edge Impulse (версия января 2023 года).
* Была сгенерирована библиотека из среды Edge Impulse и затем доработана для использования в Arduino.
*/


#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "soc/soc.h" // Disable brownout problems
#include "soc/rtc_cntl_reg.h" // Disable brownout problems
#include <a2023_dog_cat_inferencing.h>
#include "edge-impulse-sdk/dsp/image/image.hpp"

#include "esp_camera.h"
#include <fb_gfx.h>
#include "img_converters.h"
#include "image_util.h"

#include <SPI.h>
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
#include <TFT_eFEX.h>
TFT_eFEX  fex = TFT_eFEX(&tft);

bool stream_or_display = true;

dl_matrix3du_t *resized_matrix = NULL;
size_t out_len = EI_CLASSIFIER_INPUT_WIDTH * EI_CLASSIFIER_INPUT_HEIGHT;
ei_impulse_result_t result = {0};
camera_fb_t * fb = NULL;
static esp_err_t cam_err;

// Select camera model
//#define CAMERA_MODEL_WROVER_KIT // Has PSRAM
//#define CAMERA_MODEL_ESP_EYE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_PSRAM // Has PSRAM
//#define CAMERA_MODEL_M5STACK_V2_PSRAM // M5Camera version B Has PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_ESP32CAM // No PSRAM
#define CAMERA_MODEL_AI_THINKER // Has PSRAM
//#define CAMERA_MODEL_TTGO_T_JOURNAL // No PSRAM

#include "camera_pins.h"

class aFrameBuffer: public Adafruit_GFX {
  public:
    uint8_t *buffer = NULL;
    uint32_t size;
    int w;
    int h;

    aFrameBuffer(int16_t ww, int16_t hh): Adafruit_GFX(ww, hh)   {   w = ww;  h = hh;  size = h*w;    }

    void setBuffer(uint8_t *b)   {   buffer = b;  }

    void drawPixel(int16_t x, int16_t y, uint16_t color)
    {
      if (x<0 || x >= w || y <0 || y >=h)  return;
      buffer[x +y*w] = color;
    }

    uint8_t get(int16_t x, int16_t y)
    {
      if (x<0 || x >= w || y <0 || y >=h)  return 0;
      return buffer[x +y*w];
    }
};

aFrameBuffer OSD(320, 240);

// Функция показа информации освободной памяти
void  showMemory()
{ 
  Serial.println("Memory (bytes) --------");	
  Serial.print("FreeHeap=");Serial.print(ESP.getFreeHeap()); 
  Serial.print("  MinFreeHeap=");Serial.print(ESP.getMinFreeHeap()); 
  Serial.print("  HeapSize=");Serial.print(ESP.getHeapSize()); 
  Serial.print("  MaxAllocHeap=");Serial.println(ESP.getMaxAllocHeap()); 
}

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);//disable brownout
  // Set all chip selects high to avoid bus contention during initialisation of each
  digitalWrite( TFT_CS, HIGH); // SD card chips select, must use GPIO 5 (ESP32 SS)
  Serial.begin(115200);
  Serial.println("\r\nClassification into two classes of dog-cat (Edge Impulse).");
  Serial.println("Initialisation done.");
  
  
  SPI.begin(TFT_SCLK,TFT_MISO,TFT_MOSI,TFT_CS);
  tft.begin();
  tft.setRotation(0);  // 0 & 2 Portrait. 1 & 3 landscape
  tft.setTextSize(1);
  delay(500);

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format =  PIXFORMAT_JPEG;
  
  //init with high specs to pre-allocate larger buffers
  if (psramFound()) {
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  // camera init
  cam_err = esp_camera_init(&config);
  if (cam_err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", cam_err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_QVGA);
  s->set_vflip(s, 1);
  
  tft.setTextColor(TFT_GREEN, TFT_BLACK);    tft.setTextFont(1);

  digitalWrite(4, LOW);
  showMemory();
  Serial.println("Send byte to serial for contine");
}

int raw_feature_get_data(size_t offset, size_t out_len, float *signal_ptr)
{
  size_t pixel_ix = offset * 3;
  size_t bytes_left = out_len;
  size_t out_ptr_ix = 0;

  // read byte for byte
  while (bytes_left != 0) {
    // grab the values and convert to r/g/b
    uint8_t r, g, b;
    r = resized_matrix->item[pixel_ix];
    g = resized_matrix->item[pixel_ix + 1];
    b = resized_matrix->item[pixel_ix + 2];

    // then convert to out_ptr format
    float pixel_f = (r << 16) + (g << 8) + b;
    signal_ptr[out_ptr_ix] = pixel_f;

    // and go to the next pixel
    out_ptr_ix++;
    pixel_ix += 3;
    bytes_left--;
  }
  return 0;
}


void classify()
{
  Serial.println("Getting signal...");
  signal_t signal;
  signal.total_length = EI_CLASSIFIER_INPUT_WIDTH * EI_CLASSIFIER_INPUT_WIDTH;
  signal.get_data = &raw_feature_get_data;

  Serial.println("Run classifier...");
  // Feed signal to the classifier
  EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false /* debug */);

  // Returned error variable "res" while data object.array in "result"
  ei_printf("run_classifier returned: %d\n", res);
  if (res != 0)
    return;

  // print the predictions
  tft.setCursor(0, 0, 2);
  tft.println("results");
  ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
            result.timing.dsp, result.timing.classification, result.timing.anomaly);
  for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
    ei_printf("    %s: \t%f\r\n", result.classification[ix].label, result.classification[ix].value);
    tft.setTextSize(0);
    tft.print(result.classification[ix].label); tft.print(": "); tft.println(result.classification[ix].value);
//    OSD.print(result.classification[ix].label); OSD.print(": "); OSD.println(result.classification[ix].value);
//    tft.println(" %s: \t%f\r\n", result.classification[ix].label, result.classification[ix].value);
  }
#if EI_CLASSIFIER_HAS_ANOMALY == 1
  ei_printf("    anomaly score: %f\r\n", result.anomaly);
#endif
}

void classify_obj()
{
  Serial.println("Getting signal...");
  signal_t signal;
  signal.total_length = EI_CLASSIFIER_INPUT_WIDTH * EI_CLASSIFIER_INPUT_WIDTH;
  signal.get_data = &raw_feature_get_data;

  Serial.println("Run classifier...");
  // Feed signal to the classifier
  EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false /* debug */);

  // Returned error variable "res" while data object.array in "result"
  ei_printf("run_classifier returned: %d\n", res);
  if (res != 0)
    return;

#if EI_CLASSIFIER_HAS_ANOMALY == 1
  ei_printf("    anomaly score: %f\r\n", result.anomaly);
#endif
}


void rgb_print(dl_matrix3du_t *image_matrix, uint32_t color, const char * str, int y){
               fb_data_t fb;
               fb.width = image_matrix->w;
               fb.height = image_matrix->h;
               fb.data = image_matrix->item;
               fb.bytes_per_pixel = 3;
               fb.format = FB_BGR888;
//               fb_gfx_print(&fb, (fb.width - (strlen(str) * 14)) / 2, y, color, str);
               fb_gfx_print(&fb, (2+ (strlen(str) * 4)) / 2, y, color, str);
}



void loop()
{


if(stream_or_display) {  //Показ картинки с камеры на дисплее
  fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
  }
  fex.drawJpg((const uint8_t*)fb->buf, fb->len, 0, 6);
  esp_camera_fb_return(fb);
  }
  
if(Serial.available()>0) // Если что то послано
{
  while(Serial.available()) Serial.read(); // Очиста буфера
	
  delay(200);
  stream_or_display = !stream_or_display;
  Serial.println("Send byte to serial for contine");
  if(!stream_or_display){

  //take phot and stream.
  Serial.println("Capture image");
  fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
//    return ESP_FAIL;
  }
  fex.drawJpg((const uint8_t*)fb->buf, fb->len, 0, 6);
  Serial.println("Converting to RGB888...");

  // Allocate rgb888_matrix buffer
  //do some file stuff here
  dl_matrix3du_t *rgb888_matrix = dl_matrix3du_alloc(1, fb->width, fb->height, 3);
  fmt2rgb888(fb->buf, fb->len, fb->format, rgb888_matrix->item);

  Serial.println("Resizing the frame buffer...");
  resized_matrix = dl_matrix3du_alloc(1, EI_CLASSIFIER_INPUT_WIDTH, EI_CLASSIFIER_INPUT_HEIGHT, 3);
  image_resize_linear(resized_matrix->item, rgb888_matrix->item, EI_CLASSIFIER_INPUT_WIDTH, EI_CLASSIFIER_INPUT_HEIGHT, 3, fb->width, fb->height);
  
  dl_matrix3du_free(rgb888_matrix); // --- Free memory ---
  classify(); // Классификация
  showMemory();  // В конце работы сети показать свободную память
 
 
  //print to image
  rgb888_matrix = dl_matrix3du_alloc(1, fb->width, fb->height, 3);
  fmt2rgb888(fb->buf, fb->len, fb->format, rgb888_matrix->item);

    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        char tmp[32];
        sprintf(tmp, "%s: %0.2f", result.classification[ix].label, result.classification[ix].value);
        rgb_print(rgb888_matrix, 0x000000FF, tmp, ix*15 + 2);
      }
  esp_camera_fb_return(fb);
  fb = NULL;
}


}


}
