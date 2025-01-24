#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/regions/daily_info.hpp"

extern "C" {
    #include "ep_display.h"
    #include "network.h"
}

int main() {
    stdio_init_all();
    
    #ifndef _PICO_CYW43_ARCH_H
        const uint8_t LED_PIN = 25;
        gpio_init(LED_PIN);
        gpio_set_dir(LED_PIN, GPIO_OUT);
    #endif

    printf("Starting program... \n");
    sleep_ms(3000);

    if(start_ap()) {
        printf("could not start UDP server!\n");
        return 0;
    }

    spi_gpio_init(21, 20, 17, 22, 16, 18, 19);

    init_display();

    DBYTE x_start[] = {20};
    DBYTE y_start[] = {30};
    
    DailyInfo clock(x_start, y_start);

    clock.update();

    // int values[] = {0, 0, 0, 0, 0, 0, 0};
    // int height[] = {10, 10 + 48, 10 + 48 * 2, 10 + 48 * 3, 10 + 48 * 4, 10 + 48 * 5, 10 + 48 * 6};
    // for(int i =0; i < 7; i++) {
    //     char str[50] = {'\0'};
    //     sprintf(str, "Hello WOrld HELLOOOOOOOOOO %d", 59 + i + height[i]);
    //     display_text(str, values[i], height[i], 2);
    //     draw_pixel_at(300 + i, 100);
    //     draw_pixel_at(300 + i, 101);
    //     draw_pixel_at(300 + i, 102);
    //     draw_pixel_at(300 + i, 103);
    //     draw_pixel_at(300 + i, 104);
    //     draw_pixel_at(300 + i, 105);
    // }

    // // const EBYTE xy0[] = {300, 50};
    // // const EBYTE xy1[] = {650, 100};
    // draw_line_between(300, 50, 650, 100);
    // draw_line_between(300, 51, 650, 101);
    // draw_line_between(299, 50, 649, 100);

    // draw_line_between(650, 100, 750, 200);

    // insert_in_grid(character_A.character, 200, 200, 24, 48);

    // DBYTE padding = 0;
    // FontCharacter32px chars[] = {character_one, character_zero, character_colon, character_five, character_eight};
    // for(int i = 0; i < 5; i++) {
    //   insert_in_grid(chars[i].character, 200 + padding, 200, 32, 32);
    //   padding += chars[i].width + 5;
    // }

    // display_from_grid();

    // while(1) {
    //     cyw43_arch_poll(); // Keep the WiFi stack running
    //     cyw43_arch_wait_for_work_until(make_timeout_time_ms(1000));
        
    //     LED_GPIO_PUT(LED_PIN, 1);
    //     sleep_ms(250);
    //     LED_GPIO_PUT(LED_PIN, 0);
    //     sleep_ms(1000);

        
    // }
    // clear();

    display_from_grid();
    uint64_t start_time = time_us_64();
    
    while (1) {
        // cyw43_arch_poll(); // Poll for WiFi events
        LED_GPIO_PUT(LED_PIN, 1);
        sleep_ms(250);
        LED_GPIO_PUT(LED_PIN, 0);
        sleep_ms(1000);
        
        cyw43_arch_wait_for_work_until(make_timeout_time_ms(10000));
        uint64_t curr_time = time_us_64();

        if(curr_time - start_time > 30 * 3000000){
            clear();
            clock.update();
            display_from_grid();
            start_time = curr_time;
        }
    }
    return 0;
}