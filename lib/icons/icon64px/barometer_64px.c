#include "../utils/utils.h"
// 64 x 64
const BYTE barometer_64px[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x07,
  0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0x7c, 0x1f, 0xff, 0xff,
  0xff, 0xff, 0xf0, 0x7f, 0x7e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
  0x7d, 0x87, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0x79, 0x83, 0xff, 0xff,
  0xff, 0xff, 0xc3, 0x3f, 0x73, 0xc3, 0xff, 0xff, 0xff, 0xff, 0x87, 0x9f,
  0xf3, 0xe1, 0xff, 0xff, 0xff, 0xff, 0x87, 0xcf, 0xe3, 0xe1, 0xff, 0xff,
  0xff, 0xff, 0x8f, 0xff, 0xc7, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff,
  0xc7, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0x8f, 0xf0, 0xff, 0xff,
  0xff, 0xff, 0x08, 0x7f, 0x8c, 0x30, 0xff, 0xff, 0xff, 0xff, 0x08, 0x3f,
  0x0c, 0x30, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xfc, 0x1f, 0xf0, 0xff, 0xff,
  0xff, 0xff, 0x8f, 0xf8, 0x1f, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xf8,
  0x1f, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x87, 0xf8, 0x1f, 0xe1, 0xff, 0xff,
  0xff, 0xff, 0x87, 0xf8, 0x1f, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xfc,
  0x3f, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xc3, 0xff, 0xff,
  0xff, 0xff, 0xe1, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff,
  0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xfc, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xf8, 0x0f, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00,
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};