
#include <Adafruit_GFX.h>
#include "soc/soc.h" // Disable brownout problems
#include "soc/rtc_cntl_reg.h" // Disable brownout problems
#include <Car_Detection_inferencing.h>
#include "esp_camera.h"
#include <fb_gfx.h>
#include "img_converters.h"
#include "image_util.h"

#define index_ov2640_html_gz_len 4316
const uint8_t index_ov2640_html_gz[] = {
0x1f,0x8b,0x08,0x08,0xe8,0xd6,0xd7,0x5e,0x00,0xff,0x69,0x6e,0x64,0x65,0x78,0x2e,0x68,0x74,0x6d,0x6c,0x2e,0x67,0x7a,0x00,0xdd,0x58,0x6b,0x6f,0xdb,0xc8,0xd5,0xfe,0x2c,0xfd,0x8a,0x59,0xf6,0x2d,0x4c,0x21,0x12,0x65,0x25,0xc5,0xc2,0x50,0x24,0x17,0xb9,0x38,0x8d,0x81,0xb4,0xbb,0x58,0x6f,0xbb,0x05,0x16,0x8b,0xec,0x88,0x3c,0x94,0x26,0x21,0x39,0xec,0xcc,0xc8,0xb2,0xba,0xf0,0x7f,0xdf,0xe7,0xcc,0xf0,0x22,0x29,0xb6,0xd3,0xf7,0x53,0x81,0x4a,0x82,0x44,0xce,0x9c,0xfb,0x3c,0xe7,0x42,0x2d,0xbe,0xc9,0x74,0xea,0xf6,0x35,0x89,0x8d,0x2b,0x8b,0xcb,0xe1,0xa2,0xfd,0x21,0x99,0xe1,0xa7,0x24,0x27,0x45,0xba,0x91,0xc6,0x92,0x5b,0x46,0x5b,0x97,0x4f,0x2e,0xa2,0x76,0xb9,0x92,0x25,0x2d,0xa3,0x5b,0x45,0xbb,0x5a,0x1b,0x17,0x89,0x54,0x57,0x8e,0x2a,0x90,0xed,0x54,0xe6,0x36,0xcb,0x8c,0x6e,0x55,0x4a,0x13,0x7f,0x33,0x56,0x95,0x72,0x4a,0x16,0x13,0x9b,0xca,0x82,0x96,0x33,0x96,0xe1,0x94,0x2b,0xe8,0xf2,0x86,0x8a,0x5c,0x91,0x78,0x23,0x4b,0xf1,0x0f,0x48,0x22,0xb3,0x98,0x86,0x8d,0xe1,0xc2,0xba,0x3d,0xff,0xae,0x74,0xb6,0x17,0xbf,0x0d,0x05,0xbf,0x72,0xa8,0x98,0xe4,0xb2,0x54,0xc5,0x7e,0x2e,0x5e,0x19,0x48,0x1c,0x8b,0xf7,0x54,0xdc,0x92,0x53,0xa9,0x1c,0x0b,0x2b,0x2b,0x3b,0xb1,0x64,0x54,0xfe,0x32,0xd0,0xaf,0x64,0xfa,0x79,0x6d,0xf4,0xb6,0xca,0xe6,0xe2,0x0f,0xb3,0x0b,0x7e,0x37,0x3b,0x99,0xb2,0x75,0x21,0x21,0x65,0x6d,0x54,0xf6,0x72,0x38,0xe0,0x9f,0x89,0xa3,0x12,0x8b,0x8e,0x26,0xa9,0x2e,0xb6,0x65,0x65,0xe7,0xc2,0x50,0x4d,0xd2,0xc5,0x72,0xeb,0xf4,0x24,0x57,0x6e,0x2c,0x4a,0x55,0x95,0xf2,0x2e,0x9e,0x5d,0x9c,0xd7,0x77,0x63,0x31,0xcb,0xcd,0x68,0xd4,0x72,0xaf,0x65,0x3d,0x17,0x33,0x2a,0x5f,0x0e,0xef,0x87,0x99,0xba,0x85,0xcd,0x83,0x5a,0x5b,0xf8,0xad,0x2b,0x16,0x04,0xc1,0xea,0x96,0xb0,0x97,0xa8,0x52,0xae,0x29,0xb8,0xe4,0xa3,0x03,0xae,0xf3,0xf3,0x3f,0x7a,0xc3,0x36,0xa4,0xd6,0x1b,0x37,0x17,0xac,0x90,0xe5,0x24,0x19,0x15,0xe4,0x1a,0xe2,0x13,0x7f,0xf2,0xfc,0xc5,0xf9,0x8b,0x3f,0xb5,0x9e,0x6a,0x93,0x91,0x99,0x18,0x99,0xa9,0x2d,0xec,0x86,0xc0,0xfa,0xae,0xd9,0x82,0x33,0xda,0x78,0xfa,0x36,0x2c,0x8e,0xee,0xdc,0x44,0x16,0x6a,0x0d,0xc3,0x52,0x1c,0x19,0x99,0x66,0xa3,0x50,0x15,0x4d,0x5a,0x1b,0x66,0x17,0xbd,0x88,0xad,0xb1,0x2c,0xa3,0xd6,0x2a,0x50,0x0f,0x70,0xd9,0xba,0x26,0x57,0x16,0xe1,0x72,0x84,0xd5,0x7f,0x4f,0x54,0x95,0xd1,0x9d,0xd7,0x8f,0x5b,0xa7,0x39,0x22,0xde,0x92,0x81,0x69,0x84,0xf2,0xdd,0x40,0xc0,0xb5,0xc5,0xb4,0x39,0xe0,0x01,0x8e,0x3a,0x35,0xaa,0x76,0x97,0x43,0x60,0x71,0x5b,0xc2,0xa0,0x44,0x66,0xd9,0xd5,0x2d,0x2e,0x3e,0x28,0x0b,0x4c,0x91,0x89,0xa3,0xb7,0xdf,0xfd,0xf5,0x4d,0x00,0xd8,0x07,0x2d,0x33,0xca,0xa2,0xb1,0xc8,0xb7,0x55,0xca,0x26,0xc4,0xc4,0xa4,0x23,0x1f,0xa4,0x5b,0x69,0x10,0x25,0x4b,0xef,0xb5,0x75,0x62,0x29,0x3a,0x81,0x85,0x4e,0x11,0x7f,0x5d,0x25,0x1a,0x86,0xa8,0x8a,0xfd,0x02,0x5e,0x41,0xf3,0xd3,0xcd,0xc7,0xbf,0xff,0xf0,0x01,0xa4,0xd1,0xce,0xce,0xa7,0xd3,0x48,0x3c,0xc3,0xa1,0x54,0x99,0xde,0xf5,0x2c,0x1b,0x96,0xf5,0x4c,0x44,0xd3,0x9d,0x8d,0x7a,0xc6,0x9d,0x05,0x53,0x45,0x3b,0xf1,0x13,0xad,0x6e,0x74,0xfa,0x99,0x5c,0x1c,0x64,0x01,0x10,0x20,0xda,0xd9,0x44,0x57,0xba,0xa6,0x0a,0x54,0xf1,0x48,0x2c,0x2f,0x9b,0x33,0x64,0x66,0x5d,0x10,0xa4,0xaf,0xe3,0x5f,0xe1,0x51,0x45,0xa9,0xa3,0x4c,0x38,0x2d,0xfe,0xef,0xb7,0xc0,0x7f,0xff,0x2b,0x24,0x08,0x71,0xcf,0x5f,0x5e,0x4a,0x49,0xd6,0x32,0x62,0x96,0xa2,0xbb,0x6a,0xa5,0xa9,0x5c,0xc4,0x9c,0xbd,0x3a,0x6f,0xf7,0x92,0x4c,0x22,0x37,0x97,0x4b,0x38,0x64,0x9d,0x51,0xd5,0x3a,0x0a,0x81,0x69,0xa9,0x0f,0xc9,0x12,0xbb,0x5d,0x81,0x28,0x3e,0x1f,0x8b,0x0b,0x98,0x08,0x16,0x43,0xa5,0xbe,0xa5,0x6c,0xce,0x4c,0x62,0x3a,0x15,0xb9,0x2a,0x08,0xd8,0xf5,0x8b,0x22,0x37,0xba,0x14,0x37,0xdf,0x5f,0xbf,0x7b,0x77,0x03,0x00,0x88,0x41,0x58,0x0f,0x19,0xfc,0x0e,0x7b,0x37,0xa9,0x21,0xaa,0x1e,0xd4,0x70,0x81,0x34,0x11,0xc3,0xc1,0xa0,0x31,0xe4,0x5e,0x50,0x61,0xe9,0x29,0x7b,0xbe,0x0d,0xf6,0x00,0x07,0xad,0x35,0x9d,0x39,0x7e,0x8d,0x03,0x76,0x60,0x0a,0xd6,0x82,0x1d,0x3f,0xea,0x27,0xac,0xf8,0xb6,0xb1,0xa2,0xd6,0xf5,0x96,0xf3,0xfc,0xba,0x5c,0x3b,0xb9,0x8e,0x23,0x55,0xae,0x3f,0x46,0xcf,0x1e,0xe5,0x80,0xe2,0x4f,0x5b,0x9c,0x38,0x94,0x08,0xb7,0x21,0x7f,0xe8,0xba,0xc2,0xaf,0xc6,0x5a,0x51,0x08,0xb9,0x96,0xaa,0xfa,0xc2,0x39,0xa4,0x7f,0xb8,0x0f,0x70,0xa9,0xa5,0x01,0x0e,0x0f,0x21,0xc9,0x85,0xad,0xc9,0xaf,0xee,0xb5,0xdb,0xb0,0x87,0x71,0x20,0x4e,0x72,0x65,0xac,0x7b,0x83,0xa5,0xac,0x3f,0xc3,0xc3,0xd7,0x17,0x64,0x49,0x38,0x92,0x38,0x18,0x9d,0x16,0x24,0x2b,0x6f,0x71,0x0d,0xbf,0x4e,0xf8,0xef,0x61,0x70,0x48,0x17,0x0e,0x6a,0x81,0x3c,0xe3,0x23,0xbc,0xba,0xf9,0xfe,0xc5,0xf3,0x1e,0x68,0x3e,0x16,0x5e,0x16,0x13,0x08,0xa0,0x8c,0x89,0x6d,0x40,0x42,0xa0,0x2d,0xd4,0x67,0x12,0x53,0x44,0x70,0x96,0x7c,0xaa,0xd7,0x7c,0xf1,0xbc,0xbd,0x78,0xc1,0x17,0x47,0x6a,0xae,0xdf,0x72,0xd2,0x7c,0xa1,0xb0,0x89,0x36,0xc0,0x1a,0xcf,0x46,0x09,0x0a,0xb3,0x72,0x71,0x34,0x8d,0x82,0x17,0xc1,0x25,0x30,0xc1,0x49,0x31,0x15,0xb2,0xf2,0x87,0x50,0x09,0x4f,0x86,0x73,0x10,0xcc,0x4c,0xff,0xda,0x72,0x74,0xa7,0xac,0x0d,0x3c,0x5f,0xd5,0xd7,0xab,0xf0,0xf6,0x35,0xb4,0x49,0xae,0xcd,0x95,0x4c,0x37,0x71,0x57,0x59,0x14,0x5a,0xc2,0x08,0x27,0xe9,0x8f,0x72,0x3a,0x65,0xc0,0xf2,0xd2,0x01,0x50,0x67,0x23,0xf1,0x0d,0x80,0xfa,0x31,0x1a,0xf9,0x84,0x41,0x4d,0xd5,0x86,0xad,0xe5,0x30,0x59,0x27,0x8d,0x83,0x57,0xa8,0x28,0x6e,0x23,0x50,0xb5,0xc9,0xd8,0x14,0xdb,0x90,0x37,0xe8,0x44,0xa9,0x2a,0x2d,0xb6,0x19,0xd9,0x38,0xfa,0xe8,0x20,0x25,0x88,0x71,0x1b,0xf4,0x1f,0xa9,0x0a,0xe1,0x7b,0x85,0xc5,0xd9,0x81,0xe5,0x01,0x94,0x7b,0xfb,0xd8,0x87,0x41,0x38,0xcf,0xfb,0xc6,0xa1,0x63,0x84,0x5b,0x00,0xa2,0x05,0xa7,0xff,0x0d,0xdf,0xa7,0xe9,0x27,0x14,0x80,0x2a,0xab,0x94,0xab,0xc9,0xeb,0x42,0xaf,0x5a,0xd0,0xc1,0x1e,0x1f,0xd1,0xad,0x29,0xbe,0x5b,0x7d,0x42,0xbd,0x42,0x4c,0x51,0xa7,0x12,0x98,0x00,0x15,0x61,0x09,0xf7,0x47,0xb2,0x1a,0x85,0xcc,0xea,0x5d,0xb8,0xf6,0x51,0x33,0x29,0x58,0x3b,0x31,0x81,0x84,0x6d,0xf1,0xb5,0x0e,0x9f,0x36,0xee,0x9c,0x6a,0x27,0x9e,0x5a,0x7f,0x7b,0xfd,0xb6,0x35,0x2a,0x64,0x55,0x58,0xe5,0x2e,0x71,0x98,0x59,0x00,0x83,0xd9,0x83,0x1f,0x3a,0x34,0x5a,0x07,0x27,0x1a,0x9f,0xb4,0xef,0x70,0xe4,0x3c,0x96,0xd9,0x9e,0x43,0x96,0xe0,0xcb,0x55,0x41,0x7c,0x17,0x47,0xe8,0xdf,0x1e,0x1b,0x4c,0x2e,0x37,0x86,0xf2,0xaf,0xd0,0x4b,0x50,0x0f,0x02,0x79,0xe7,0xee,0x13,0xe4,0x48,0x8e,0x43,0x83,0x42,0x93,0xff,0x0a,0x8f,0xad,0x65,0xe5,0x6d,0x1a,0x0e,0x07,0x7c,0x1a,0x68,0x51,0x55,0x81,0x56,0x78,0x9d,0x81,0xa9,0x8d,0x0e,0x0a,0x00,0x26,0x98,0x94,0x02,0x98,0xc6,0xc0,0x65,0x0e,0x4c,0x71,0x1e,0xb5,0xe4,0xa1,0x86,0x2a,0xeb,0xc7,0xb7,0x4c,0xdc,0xe1,0x05,0x9a,0xd9,0xf3,0x26,0x59,0x3b,0x67,0x13,0x4c,0x7c,0xaf,0x1c,0x92,0x72,0x85,0xd6,0x1e,0x9f,0xf1,0xf2,0x19,0xe4,0x21,0xaf,0xe1,0xde,0xf4,0xcf,0x2a,0x5b,0x86,0xaa,0xd9,0x9b,0xc1,0xb6,0x3d,0xc2,0x1e,0xb5,0x54,0x30,0xe9,0x98,0x61,0x38,0xe8,0xe1,0x91,0x16,0xd2,0x5a,0x3e,0x4b,0x6e,0xff,0x1c,0x24,0x6c,0xb4,0x61,0xea,0xa9,0x14,0xfb,0xdb,0x94,0xec,0xd6,0x6d,0x08,0x3a,0x45,0x59,0x84,0x56,0x1d,0x2a,0x72,0x1f,0xdd,0x53,0x0d,0x61,0xa7,0x55,0x71,0x40,0xe7,0x75,0xf4,0xc2,0x4f,0x76,0xbf,0x1c,0x4e,0xd2,0x42,0xa5,0x9f,0x0f,0x27,0x92,0xbe,0x5e,0xa3,0x83,0x5b,0xaa,0x3a,0x65,0x73,0x1e,0x30,0x3a,0x2c,0x37,0x19,0x10,0x02,0xd1,0xc7,0x4e,0xd6,0x98,0x1b,0x32,0x5f,0xd1,0xe3,0xce,0xaf,0x50,0x0d,0x17,0xf2,0x72,0x01,0xdf,0x2f,0x17,0x53,0xc9,0x93,0x53,0x18,0xda,0x02,0x9c,0x8f,0xd8,0x3a,0x61,0x0d,0x1b,0x00,0x7d,0x79,0xc8,0xbb,0x98,0xf2,0xca,0x53,0x12,0x7a,0x87,0x47,0x09,0x0f,0x8c,0xcd,0xf4,0xc5,0xa1,0xfd,0x67,0xf4,0x88,0x50,0xc6,0x28,0xae,0x9a,0x9f,0xa0,0x21,0xa8,0xe8,0x13,0xf5,0x48,0x49,0xab,0xb9,0xb1,0x92,0x33,0xf5,0x32,0x49,0x92,0xc5,0xd4,0x5f,0x71,0x65,0x38,0x29,0x0c,0x8f,0xcc,0x1c,0x3e,0x4a,0x2a,0x43,0xa9,0x46,0xa5,0xe4,0xec,0x78,0x30,0x0b,0xd7,0xe4,0x9a,0x74,0x7a,0xbd,0xbf,0x6e,0x42,0x0b,0xa6,0x23,0xf4,0x84,0x9e,0xda,0x90,0x1d,0xf7,0xd3,0xa6,0x13,0x35,0x9d,0x9c,0x47,0x7c,0x6e,0x46,0xcd,0x63,0x0f,0xd7,0xe8,0x53,0x63,0x4f,0xe6,0x0c,0xcc,0x0d,0xd7,0x5e,0x0f,0xec,0x64,0x79,0x37,0x68,0x0d,0xc8,0x45,0xbf,0x36,0xe4,0x02,0xff,0x9f,0x1a,0x7e,0x20,0xc8,0xd7,0xfe,0xc3,0x99,0xf2,0x00,0x2f,0xed,0x96,0x13,0xe5,0xfe,0x3d,0x9e,0xe7,0xd0,0x7d,0x9a,0x91,0xb5,0xb9,0xe3,0xb6,0x00,0xe0,0xf5,0x54,0x3f,0x70,0x1f,0xf5,0xb5,0x94,0xa9,0x9a,0xbb,0xf8,0xec,0x20,0xe9,0xcf,0x9e,0xf5,0xca,0xc7,0x3c,0xe3,0xf0,0xf4,0x85,0xc7,0xc1,0x8d,0xc6,0x23,0xc9,0xd9,0x5f,0xae,0x7e,0x3c,0x1b,0x87,0x35,0x7e,0x80,0x84,0x8a,0x79,0xaf,0xbb,0xd9,0x28,0x75,0x46,0x20,0x45,0x1f,0xb4,0x2d,0x6d,0x8a,0x9e,0xcb,0x6b,0x19,0xe5,0x72,0x5b,0x38,0xbf,0xdc,0x35,0x33,0x6f,0x60,0x4e,0x0e,0x6d,0xb9,0x33,0x70,0x14,0xf8,0x12,0x1e,0x04,0xe2,0xd8,0x90,0xad,0xe1,0x00,0xf9,0x29,0xbb,0xbd,0x49,0x56,0xe8,0x60,0xf1,0xe8,0x98,0xb2,0xdc,0x87,0xbe,0xe6,0xe7,0x67,0xee,0xa8,0xa7,0x55,0xe3,0xc1,0xb6,0x16,0x98,0x42,0x63,0x1d,0xb0,0x51,0x3c,0xe3,0xf1,0x41,0x3f,0x7e,0xd6,0x08,0xad,0x3f,0xe2,0x57,0x18,0x0f,0xbb,0x16,0x1e,0xba,0x68,0x50,0xe9,0x07,0x93,0x57,0xc6,0xc8,0x7d,0xc2,0xc3,0x54,0xfc,0xc0,0x51,0xdb,0xd7,0xfb,0x37,0x5c,0xaf,0xfe,0x86,0x42,0xdd,0x55,0x43,0xaf,0xbd,0x31,0xfb,0x89,0x81,0xe5,0x70,0xd2,0x3b,0x45,0xd5,0xcf,0xbf,0xbc,0xc4,0xaa,0x07,0x5c,0xb7,0xfc,0x73,0x18,0x45,0xb2,0x5f,0x9e,0x4a,0x97,0x40,0xf2,0x5f,0x80,0x5c,0xa3,0xf9,0x7f,0x09,0x6f,0x5d,0xc0,0xff,0x5f,0xc0,0xe3,0x47,0x8a,0x06,0x80,0xc3,0xa1,0x5f,0x40,0xb1,0x0d,0xcf,0xce,0x30,0x1b,0x37,0xcd,0xdf,0x36,0xa1,0x7a,0xe2,0x3e,0x5c,0x60,0xdd,0xff,0xab,0xf3,0x3b,0x57,0xcd,0xab,0xd7,0xed,0x11,0x00,0x00
};

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

// CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22


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

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);//disable brownout
  // Set all chip selects high to avoid bus contention during initialisation of each
  digitalWrite( TFT_CS, HIGH); // SD card chips select, must use GPIO 5 (ESP32 SS)
  Serial.begin(115200);
  
  SPI.begin(TFT_SCLK,TFT_MISO,TFT_MOSI,TFT_CS);
  tft.begin();
  tft.setRotation(0);  // 0 & 2 Portrait. 1 & 3 landscape
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
  
  tft.setTextColor(TFT_GREEN, TFT_BLACK);   
  tft.setTextFont(1);

  digitalWrite(4, LOW);
   
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
  Serial.print("push button state now stream or display = ");
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
