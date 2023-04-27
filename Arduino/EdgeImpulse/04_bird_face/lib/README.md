ВНИМАНИЕ! sdk esp32 2.0.5 or 2.0.8.!!!!
Тестировался в arduino ide 1.8.9 (1.8.19), sdk esp32 2.0.5. Выбрана плата "ESPЗ2 Dev Module", PSARAM "Enable" <br>
27/04/23 протестировано ide 1.8.9, sdk esp32 2.0.8. Выбрана плата "ESPЗ2 Wrover Module" Flash QIO, 80MHz<br>
<br>
Тестировался в arduino ide 1.8.9 (1.8.19), sdk esp32 2.0.5. Выбрана плата "ESPЗ2 Dev Module", PSARAM "Enable" <br>
Библиотека полученна из среды Edge Impulse в январе 2023 года(файл bird_classification_3_inferencing.zip) требует корректировки:<br>
1. В файле bird_classification_3_inferencing/src/edge-impulse-sdk/porting/espressif/ESP-NN/src/common/common_functions.h<br>
Необходимо удалить код двух функций (оставить только их определение):<br>
static void esp_nn_aligned_s8_pad_with_value(const int8_t *src, int8_t *dst,. . .<br>
static void esp_nn_aligned_s8_pad_end_with_value(const int8_t *src, int8_t *dst,. . .<br>
В итоге должно получиться:<br>
void esp_nn_aligned_s8_pad_with_value(const int8_t *src, int8_t *dst,<br>
                                             const uint16_t input_wd,<br>
                                             const uint16_t input_ht,<br>
                                             const uint16_t channels,<br>
                                             const int32_t pad_val,<br>
                                             const uint16_t pad_wd,<br>
                                             const uint16_t pad_ht);<br>
void esp_nn_aligned_s8_pad_end_with_value(const int8_t *src, int8_t *dst,<br>
                                                 const uint16_t input_wd,<br>
                                                 const uint16_t input_ht,<br>
                                                 const uint16_t channels,<br>
                                                 const int32_t pad_val,<br>
                                                 const uint16_t pad_wd,<br>
                                                 const uint16_t pad_ht);<br>
Самой реализации этих двух функций в файле не будет (только определения!).
<br>
2. В файле bird_classification_3_inferencing/src/edge-impulse-sdk/porting/espressif/ESP-NN/src/convolution/esp_nn_conv_esp32s3.c<br>
В строке<br>
static void esp_nn_conv_s8_pad_valid_3x3(const int8_t *input_data,<br>
удалить ключевое слово static<br>
В итоге будет void esp_nn_conv_s8_pad_valid_3x3(const int8_t *input_data,<br>
<br>
После этого либа должна компилиться.<br>
<br>
ВНИМАНИЕ! Такая корректировка скорее всего потребуется для всех библиотек полученных из Edge Impulse.
<br>
