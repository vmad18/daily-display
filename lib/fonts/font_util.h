#ifndef FONT_UTIL_H
#define FONT_UTIL_H

#include "ep_display.h"
#include "utils.h"

typedef struct {
    const DBYTE width;
    const DBYTE height;
    const DBYTE pad;
    const BYTE character[256];
} FontCharacter8px;

typedef struct {
    const DBYTE width;
    const DBYTE height;
    const DBYTE pad;
    const BYTE character[256];
} FontCharacter16px;

typedef struct {
    const DBYTE width;
    const DBYTE height;
    const DBYTE pad;
    const BYTE character[256];
} FontCharacter24px;

typedef struct {
    const DBYTE width;
    const DBYTE height;
    const DBYTE pad;
    const BYTE character[256];
} FontCharacter32px;

typedef struct {
    const DBYTE width;
    const DBYTE height;
    const DBYTE pad;
    const BYTE character[512];
} FontCharacter48px;

typedef struct {
    const DBYTE width;
    const DBYTE height;
    const DBYTE pad;
    const BYTE character[512];
} FontCharacter64px;

const FontCharacter8px *char_map8[256] = {NULL};

const FontCharacter16px *char_map16[256] = {NULL};

const FontCharacter24px *char_map24[256] = {NULL};

const FontCharacter32px *char_map32[256] = {NULL};

const FontCharacter48px *char_map48[256] = {NULL};

const FontCharacter64px *char_map64[256] = {NULL};

DBYTE SPACE_PX;

extern void load();

DBYTE (*display_text)(const char *, DBYTE, DBYTE, DBYTE); 

const FontCharacter8px* map_char8(BYTE character) {
    return char_map8[character];
}

const FontCharacter16px* map_char16(BYTE character) {
    return char_map16[character];
}

const FontCharacter24px* map_char24(BYTE character) {
    return char_map24[character];
}

const FontCharacter32px* map_char32(BYTE character) {
    return char_map32[character];
}

const FontCharacter48px* map_char48(BYTE character) {
    return char_map48[character];
}

const FontCharacter64px* map_char64(BYTE character) {
    return char_map64[character];
}

DBYTE display_text8(const char * text, DBYTE x_pos, DBYTE y_pos, DBYTE pad_amount) { 
    DBYTE padding = 0;
    for(int i = 0; text[i]; i++) {
      const FontCharacter8px *glyph = map_char8(text[i]);
      if(text[i] == ' ') {
        padding += SPACE_PX;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
      } else {
        insert_in_grid(glyph->character, x_pos + padding, y_pos, glyph->width, glyph->height);
        padding += glyph->width - glyph->pad;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
        padding += pad_amount;
      }

    }

    return padding;
}

DBYTE display_text16(const char * text, DBYTE x_pos, DBYTE y_pos, DBYTE pad_amount) { 
    DBYTE padding = 0;
    for(int i = 0; text[i]; i++) {
      const FontCharacter16px *glyph = map_char16(text[i]);
      if(text[i] == ' ') {
        padding += SPACE_PX;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
      } else {
        insert_in_grid(glyph->character, x_pos + padding, y_pos, glyph->width, glyph->height);
        padding += glyph->width - glyph->pad;
        // padding += padding % 8 ? 8 - padding % 8 : 0;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
        padding += pad_amount;
      }

    }

    return padding;
}

DBYTE display_text24(const char * text, DBYTE x_pos, DBYTE y_pos, DBYTE pad_amount) { 
    DBYTE padding = 0;
    for(int i = 0; text[i]; i++) {
      const FontCharacter24px *glyph = map_char24(text[i]);
      if(text[i] == ' ') {
        x_pos += SPACE_PX;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
      } else {
        insert_in_grid(glyph->character, x_pos, y_pos, glyph->width, glyph->height);
        x_pos += glyph->width - glyph->pad;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
      }

    }

    return padding;
}

DBYTE display_text32(const char * text, DBYTE x_pos, DBYTE y_pos, DBYTE pad_amount) { 
    DBYTE padding = 0;
    for(int i = 0; text[i]; i++) {
      const FontCharacter32px *glyph = map_char32(text[i]);
      if(text[i] == ' ') {
        padding += SPACE_PX;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
      } else {
        insert_in_grid(glyph->character, x_pos + padding, y_pos, glyph->width, glyph->height);
        padding += glyph->width - glyph->pad;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
        padding += pad_amount;
      }

    }

    return padding;
}

DBYTE display_text48(const char * text, DBYTE x_pos, DBYTE y_pos, DBYTE pad_amount) { 
    DBYTE padding = 0;
    for(int i = 0; text[i]; i++) {
      const FontCharacter48px *glyph = map_char48(text[i]);
      if(text[i] == ' ') {
        padding += SPACE_PX;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
      } else {
        insert_in_grid(glyph->character, x_pos + padding, y_pos, glyph->width, glyph->height);
        padding += glyph->width - glyph->pad;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
        padding += pad_amount;
      }

    }

    return padding;
}


DBYTE display_text64(const char * text, DBYTE x_pos, DBYTE y_pos, DBYTE pad_amount) { 
    DBYTE padding = 0;
    for(int i = 0; text[i]; i++) {
      const FontCharacter64px *glyph = map_char64(text[i]);
      if(text[i] == ' ') {
        padding += SPACE_PX;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
      } else {
        insert_in_grid(glyph->character, x_pos + padding, y_pos, glyph->width, glyph->height);
        padding += glyph->width - glyph->pad;
        padding -= padding % 8 > 8 - padding % 8 ? -(8 - padding % 8) : padding % 8; // 8 bit alignment
        padding += pad_amount;
      }

    }

    return padding;
}


#endif


// DBYTE display_text(const char * text, DBYTE x_pos, DBYTE y_pos, DBYTE pad_amount) { 
//     load();

//     DBYTE padding = 0;
//     for(int i = 0; text[i]; i++) {
//       const FontCharacter32px *glyph = map_char32(text[i]);
//       if((x_pos + padding) % 8 == 1 || (x_pos + padding) % 8 == 0) {
//         insert_in_grid(glyph->character, x_pos + padding - 8, y_pos, glyph->width, glyph->height);
//         padding += glyph->width - 3 - 8 + pad_amount;
//       } else {
//         insert_in_grid(glyph->character, x_pos + padding, y_pos, glyph->width, glyph->height);
//         padding += glyph->width - 3 + pad_amount;
//       }

//     }

//     return padding;
// }