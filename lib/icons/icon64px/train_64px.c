#include "../utils/utils.h"
// 64 x 64
const BYTE train_64px[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xf8, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xf8, 0x3f, 0xff, 0xff,
  0xff, 0x80, 0x00, 0x3f, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f,
  0xf8, 0x3f, 0xff, 0xff, 0xff, 0xe3, 0xe0, 0x7e, 0x78, 0x3f, 0xff, 0xff,
  0xff, 0xe7, 0xf0, 0x7c, 0x38, 0x3f, 0xff, 0xff, 0xff, 0xe7, 0xf0, 0x00,
  0x00, 0x03, 0xff, 0xff, 0xff, 0xe7, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xff,
  0xff, 0xe7, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xe7, 0xf0, 0x00,
  0x00, 0x01, 0xff, 0xff, 0xff, 0xe7, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xff,
  0xff, 0xe3, 0xe0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00,
  0x00, 0x01, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff,
  0xff, 0xe0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00,
  0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
  0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x00,
  0x00, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x03, 0x00, 0x40, 0x08, 0x1f, 0xff,
  0xff, 0xf0, 0x02, 0x00, 0x40, 0x08, 0x1f, 0xff, 0xff, 0xf0, 0x07, 0x00,
  0x40, 0x08, 0x0f, 0xff, 0xff, 0xf8, 0x07, 0x00, 0xe0, 0x18, 0x07, 0xff,
  0xff, 0xf8, 0x0f, 0x80, 0xe0, 0x38, 0x03, 0xff, 0xff, 0xfe, 0x1f, 0xc3,
  0xf8, 0x78, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
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