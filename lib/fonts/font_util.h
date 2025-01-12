#ifndef FONT_UTIL_H
#define FONT_UTIL_H

#include "spi_utils.h"

typedef struct {
    const BYTE character[512];
    const DBYTE width;
    const DBYTE right_pad;
} FontCharacter;

#endif