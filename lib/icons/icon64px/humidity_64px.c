#include "../utils/utils.h"
// 64 x 64
const BYTE humidity_64px[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
  0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff,
  0xff, 0xff, 0xf8, 0x00, 0x0e, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf0,
  0x1c, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf8, 0x1c, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xe7, 0xbc, 0x18, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x1c,
  0x38, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x1c, 0x30, 0x03, 0xff, 0xff,
  0xff, 0xff, 0xc7, 0x1c, 0x70, 0x03, 0xff, 0xff, 0xff, 0xff, 0x87, 0x1c,
  0x70, 0x01, 0xff, 0xff, 0xff, 0xff, 0x87, 0x3c, 0xe0, 0x01, 0xff, 0xff,
  0xff, 0xff, 0x87, 0xf8, 0xe0, 0x01, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf9,
  0xc0, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0xf1, 0xc7, 0xc0, 0xff, 0xff,
  0xff, 0xff, 0x00, 0x03, 0x8f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x03,
  0x9f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x07, 0x1c, 0xf0, 0xff, 0xff,
  0xff, 0xff, 0x00, 0x07, 0x1c, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x80, 0x06,
  0x1c, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0e, 0x1c, 0xf1, 0xff, 0xff,
  0xff, 0xff, 0x80, 0x0c, 0x1c, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1c,
  0x1e, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1c, 0x0f, 0xe3, 0xff, 0xff,
  0xff, 0xff, 0xe0, 0x38, 0x07, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x38,
  0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff,
  0xff, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00,
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};