#include <stdio.h>
#include "pico/stdlib.h"
extern "C" {
    #include "ep_display.h"
    #include "lib/fonts/jetbrains-mono16px/include_all.h"
}

int main() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    spi_gpio_init(21, 20, 17, 22, 16, 18, 19);

    init_display();


    load();

    int values[] = {0, 0, 0, 0, 0, 0, 0};
    int height[] = {10, 10 + 48, 10 + 48 * 2, 10 + 48 * 3, 10 + 48 * 4, 10 + 48 * 5, 10 + 48 * 6};
    for(int i =0; i < 7; i++) {
        display_text("Shit", values[i], height[i], 4);
        draw_pixel_at(300 + i, 100);
        draw_pixel_at(300 + i, 101);
        draw_pixel_at(300 + i, 102);
        draw_pixel_at(300 + i, 103);
        draw_pixel_at(300 + i, 104);
        draw_pixel_at(300 + i, 105);
    }
    // insert_in_grid(character_A.character, 200, 200, 24, 48);

    // DBYTE padding = 0;
    // FontCharacter32px chars[] = {character_one, character_zero, character_colon, character_five, character_eight};
    // for(int i = 0; i < 5; i++) {
    //   insert_in_grid(chars[i].character, 200 + padding, 200, 32, 32);
    //   padding += chars[i].width + 5;
    // }

    display_from_grid();
    sleep_ms(5000);
    
    gpio_put(LED_PIN, 1);
    sleep_ms(3000);
    gpio_put(LED_PIN, 0);

    // clear();
    return 0;
}