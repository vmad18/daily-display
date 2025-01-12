#include "../font_util.h"
// 64 x 64
const FontCharacter character_w = {{
  0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
  0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x03, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x80, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
  0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x01, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x80, 0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
  0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xc0, 0x01, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x00, 0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
  0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xc0, 0x01, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x00, 0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
  0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xe0, 0x00, 0xff, 0xfc,
  0x00, 0x3f, 0xff, 0x00, 0xe0, 0x00, 0xff, 0xf8, 0x00, 0x3f, 0xfe, 0x00,
  0xe0, 0x00, 0xff, 0xf8, 0x00, 0x3f, 0xfe, 0x00, 0xe0, 0x00, 0xff, 0xf8,
  0x00, 0x1f, 0xfe, 0x00, 0xe0, 0x00, 0xff, 0xf0, 0x00, 0x1f, 0xfe, 0x00,
  0xf0, 0x00, 0xff, 0xf0, 0x00, 0x1f, 0xfe, 0x00, 0xf0, 0x00, 0x7f, 0xf0,
  0x00, 0x0f, 0xfe, 0x00, 0xf0, 0x00, 0x7f, 0xe0, 0x00, 0x0f, 0xfe, 0x00,
  0xf0, 0x00, 0x7f, 0xe0, 0x00, 0x0f, 0xfc, 0x00, 0xf0, 0x00, 0x7f, 0xe0,
  0x00, 0x0f, 0xfc, 0x00, 0xf0, 0x00, 0x7f, 0xe0, 0x00, 0x07, 0xfc, 0x00,
  0xf8, 0x00, 0x7f, 0xc0, 0x00, 0x07, 0xfc, 0x00, 0xf8, 0x00, 0x7f, 0xc0,
  0x00, 0x07, 0xfc, 0x00, 0xf8, 0x00, 0x3f, 0xc0, 0x00, 0x03, 0xfc, 0x00,
  0xf8, 0x00, 0x3f, 0x80, 0x00, 0x03, 0xf8, 0x00, 0xf8, 0x00, 0x3f, 0x80,
  0x10, 0x03, 0xf8, 0x00, 0xf8, 0x00, 0x3f, 0x80, 0x10, 0x01, 0xf8, 0x00,
  0xfc, 0x00, 0x3f, 0x00, 0x18, 0x01, 0xf8, 0x00, 0xfc, 0x00, 0x3f, 0x00,
  0x18, 0x01, 0xf8, 0x00, 0xfc, 0x00, 0x3f, 0x00, 0x38, 0x00, 0xf8, 0x00,
  0xfc, 0x00, 0x3e, 0x00, 0x38, 0x00, 0xf8, 0x00, 0xfc, 0x00, 0x1e, 0x00,
  0x3c, 0x00, 0xf0, 0x00, 0xfe, 0x00, 0x1e, 0x00, 0x7c, 0x00, 0xf0, 0x00,
  0xfe, 0x00, 0x1c, 0x00, 0x7c, 0x00, 0x70, 0x00, 0xfe, 0x00, 0x1c, 0x00,
  0x7e, 0x00, 0x70, 0x00, 0xfe, 0x00, 0x1c, 0x00, 0xfe, 0x00, 0x70, 0x00,
  0xfe, 0x00, 0x18, 0x00, 0xfe, 0x00, 0x30, 0x00, 0xfe, 0x00, 0x18, 0x00,
  0xfe, 0x00, 0x30, 0x00, 0xff, 0x00, 0x18, 0x01, 0xff, 0x00, 0x30, 0x00,
  0xff, 0x00, 0x18, 0x01, 0xff, 0x00, 0x10, 0x01, 0xff, 0x00, 0x10, 0x01,
  0xff, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x01,
  0xff, 0x00, 0x00, 0x03, 0xff, 0x80, 0x00, 0x01, 0xff, 0x00, 0x00, 0x03,
  0xff, 0x80, 0x00, 0x01, 0xff, 0x80, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x01,
  0xff, 0x80, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x03, 0xff, 0x80, 0x00, 0x07,
  0xff, 0xc0, 0x00, 0x03, 0xff, 0x80, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x03,
  0xff, 0x80, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x03, 0xff, 0x80, 0x00, 0x0f,
  0xff, 0xe0, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x07,
  0xff, 0xc0, 0x00, 0x1f, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x1f,
  0xff, 0xf0, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xf0, 0x00, 0x07,
  0xff, 0xc0, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x3f,
  0xff, 0xf8, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x0f,
  0xff, 0xe0, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x0f
}, 64, 0};