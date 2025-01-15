#ifndef SPI_UTILS_H
#define SPI_UTILS_H

#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "stdio.h"
#include "utils.h"

#define BAUD_RATE 2000000
#define SPI_PORT spi0

extern DBYTE RST_PIN;
extern DBYTE DC_PIN;
extern DBYTE CS_PIN;
extern DBYTE BUSY_PIN;
extern DBYTE PWR_PIN;
extern DBYTE CLK_PIN;
extern DBYTE MOSI_PIN;

// GPIO stuff
void gpio_mode(DBYTE, DBYTE);
void digital_write(DBYTE, BYTE);
BYTE digital_read(DBYTE);

// SPI stuff
BYTE spi_gpio_init(DBYTE, DBYTE, DBYTE, DBYTE, DBYTE, DBYTE, DBYTE);
void spi_write_byte(BYTE, BYTE);
void spi_write_byte_arr(BYTE*, FBYTE, BYTE);


// other utils
void delay_ms(FBYTE);

#endif