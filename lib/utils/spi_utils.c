#include "spi_utils.h"

DBYTE RST_PIN = 0; 
DBYTE DC_PIN = 0; 
DBYTE CS_PIN = 0;
DBYTE BUSY_PIN = 0; 
DBYTE PWR_PIN = 0;
DBYTE CLK_PIN = 0; 
DBYTE MOSI_PIN = 0;

void gpio_mode(DBYTE pin, DBYTE mode) {
    gpio_init(pin);
    
    if(!mode) {
        gpio_set_dir(pin, GPIO_IN);
    } else {
        gpio_set_dir(pin, GPIO_OUT);
    }
}

void digital_write(DBYTE pin, BYTE level) {
    gpio_put(pin, level);
}

BYTE digital_read(DBYTE pin) {
    return gpio_get(pin);
}

void delay_ms(FBYTE delay) {
    sleep_ms(delay);
}

BYTE spi_gpio_init(
                DBYTE rst, DBYTE dc, DBYTE cs, 
                DBYTE busy, DBYTE pwr, DBYTE clk, DBYTE mosi) {

    stdio_init_all();
    
    // define spi pins
    RST_PIN = rst; 
    DC_PIN = dc; 
    CS_PIN = cs;
    BUSY_PIN = busy;
    PWR_PIN = pwr;
    CLK_PIN = clk; 
    MOSI_PIN = mosi;


    gpio_mode(RST_PIN, 1);
    gpio_mode(DC_PIN, 1);
    gpio_mode(CS_PIN, 1);
    gpio_mode(BUSY_PIN, 0);

    gpio_mode(PWR_PIN, 1);
    digital_write(PWR_PIN, 1);

    gpio_set_function(CLK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(MOSI_PIN, GPIO_FUNC_SPI);

    // initialize spi
    spi_init(SPI_PORT, BAUD_RATE);
    spi_set_format(
        SPI_PORT,
        8,
        0,
        0,
        SPI_MSB_FIRST
    );
    
    return 0;
}

// mode = PIN_LOW (command), PIN_HIGH (data)
void spi_write_byte(BYTE data, BYTE mode) {
    spi_write_byte_arr(&data, 1, mode);
}

void spi_write_byte_arr(BYTE *data, FBYTE len, BYTE mode) {
     
    if(mode == PIN_HIGH) gpio_put(DC_PIN, PIN_HIGH); 
    else gpio_put(DC_PIN, PIN_LOW);

    digital_write(CS_PIN, PIN_LOW);
    spi_write_blocking(SPI_PORT, data, len);
    digital_write(CS_PIN, PIN_HIGH);
}