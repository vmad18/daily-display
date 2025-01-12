#include <stdio.h>
#include "pico/stdlib.h"
extern "C" {
    #include "ep_display.h"
    #include "spi_utils.h"
    #include "lib/fonts/liberation_mono/include_all.h"
}

int main() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    spi_gpio_init(21, 20, 17, 22, 16, 18, 19);

    init_display();

    FontCharacter chars[] = {character_h, character_e, character_l, character_l, character_o};
    DBYTE padding = 0; 

    for(int i = 0; i < 5; i++) {
      insert_in_grid(chars[i].character, 200 + padding, 200, 64, 64);
      padding += chars[i].width - chars[i].right_pad;
    }


    display_from_grid();
    sleep_ms(5000);
    // insert_in_grid(IMAGE_DATA, 200, 200, 160, 160);
    // display_from_grid();
    // sleep_ms(2000);
    
    gpio_put(LED_PIN, 1);
    sleep_ms(3000);
    gpio_put(LED_PIN, 0);

    // clear();
    return 0;
}