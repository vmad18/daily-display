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
