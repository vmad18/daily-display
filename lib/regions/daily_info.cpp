#include "daily_info.hpp"
#include "stdio.h"

extern "C" {
    #include "../fonts/jetbrains_mono64px/include_all.h"
    #include "../fonts/jetbrains_mono48px/include_all.h"
    #include "../fonts/jetbrains_mono32px/include_all.h"
    #include "../fonts/jetbrains_mono24px/include_all.h"
    #include "../fonts/jetbrains_mono16px/include_all.h"
    #include "../fonts/jetbrains_mono8px/include_all.h"
    #include "../icons/icon16px/include_all.h"
    #include "../icons/icon40px/include_all.h"
    #include "../icons/icon48px/include_all.h"
    #include "../icons/icon128px/include_all.h"
    #include "../icons/icon256px/include_all.h"
    #include "../icons/icon32px/include_all.h"
    #include "../icons/icon56px/include_all.h"
    #include "../icons/icon192px/include_all.h"
    #include "string.h"
}

#define GAP 60
#define X_GAP 70
#define HEIGHT_SHIFT 25

int16_t DailyInfo::temp_to_y(DBYTE min_temp, DBYTE max_temp, DBYTE min_y, DBYTE max_y, float temp) const {
    DBYTE dy = max_y - min_y;
    temp -= min_temp; 
    temp /= (max_temp - min_temp);

    return -temp * max_y + min_y;
}

DailyInfo::DailyInfo(DBYTE *x_starts, DBYTE *y_starts): Region(x_starts, y_starts, 10) {};
void DailyInfo::update(void) const {
    // insert_in_grid(cloud_40px, 20, 20, 40, 40);
    // insert_in_grid(cloud_40px, 60, 20, 40, 40);

    load16(); 
    char buff_date[] = "Sunday, Sept 29th";
    display_text(buff_date, 850 - strlen(buff_date) * 12, 40, 0);


    load32(); 
    char buff_loc[] = "College Park, MD";
    display_text(buff_loc, 850 - strlen(buff_loc) * 19, 0, 0);

    insert_in_grid(rain_wind_128px, 5, 5, 128, 128);
    
    load16();
    DBYTE old_pos = display_text("Feels like 105", 125, 65 + 25, 2);
    insert_in_grid(fahrenheit_32px, 125 + old_pos - 8, 65 + 25, 32, 32);
    old_pos = display_text("Feels like 105", 125, 65 + 25, 2);
    
    load64();    
    DBYTE new_pos = display_text("88", 128 + 10, 5, 2);
    insert_in_grid(fahrenheit_48px, 128 + new_pos, 35, 48, 48);
    new_pos = display_text("88", 128 + 10, 5, 2);

    load16();
    insert_in_grid(sunrise_56px, 20, 150, 56, 56);
    display_text("07:15am", 74, 160, 2);
    display_text("Sunrise", 74, 145, 2);

    insert_in_grid(sunset_56px, 155, 150, 56, 56);
    display_text("09:15pm", 210, 160, 2);
    display_text("Sunset", 210, 145, 2);

    insert_in_grid(strong_wind_56px, 20, 150 + GAP, 56, 56);
    new_pos = display_text("69m/s", 74, 170 + GAP, 0);
    display_text("Wind Speed", 74, 155 + GAP, 2);

    insert_in_grid(humidity_56px, 155, 150 + GAP, 56, 56);
    new_pos = display_text("69%", 210, 170 + GAP, 0);
    display_text("Humidity", 210, 155 + GAP, 2);

    insert_in_grid(day_sunny_56px, 20, 150 + 2 * GAP, 56, 56);
    new_pos = display_text("10 Low", 74, 170 + 2 * GAP, 2);
    display_text("UV Index", 74, 155 + 2 * GAP, 2);

    insert_in_grid(barometer_56px, 155, 150 + 2 * GAP, 56, 56);
    new_pos = display_text("15 psi", 210, 170 + 2 * GAP, 2);
    display_text("Pressure", 210, 155 + 2 * GAP, 2);

    insert_in_grid(dust_56px, 20, 150 + 3 * GAP, 56, 56);
    new_pos = display_text("32 Low", 74, 170 + 3 * GAP, 2);
    display_text("AQI", 74, 155 + 3 * GAP, 2);

    insert_in_grid(fog_56px, 155, 150 + 3 * GAP, 56, 56);
    new_pos = display_text(">10km", 210, 170 + 3 * GAP, 2);
    display_text("Visibility", 210, 155 + 3 * GAP, 2);


    DBYTE start_txt = 332;
    DBYTE start_icon = 322;
    DBYTE start_height = 80;

    insert_in_grid(day_cloudy_high_48px, start_icon, start_height + HEIGHT_SHIFT, 48, 48);
    DBYTE padding = display_text("30|19", start_txt - 8, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 14, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text("30|19", start_txt - 8, start_height + HEIGHT_SHIFT + 38, 2);
    display_text("Mon", start_txt, start_height, 2); 

    insert_in_grid(day_cloudy_48px, start_icon + X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text("69|42", start_txt - 8 + X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 15 + X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text("69|42", start_txt - 8 + X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text("Tue", start_txt + X_GAP, start_height, 2); 


    insert_in_grid(day_sunny_48px, start_icon + 2 * X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text("99|95", start_txt - 12 + 2 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 20 + 2 * X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text("99|95", start_txt - 12 + 2 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text("Wed", start_txt + 2 * X_GAP, start_height, 0); 

    insert_in_grid(rain_wind_48px, start_icon + 3 * X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text("82|80", start_txt - 8 + 3 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 20 + 3 * X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text("82|80", start_txt - 8 + 3 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text("Thu", start_txt + 3 * X_GAP, start_height, 0); 

    insert_in_grid(day_showers_48px, start_icon + 4 * X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text("72|52", start_txt - 8 + 4 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 15 + 4 * X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text("72|52", start_txt - 8 + 4 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text("Fri", start_txt + 4 * X_GAP, start_height, 2); 

    // draw_line_between(325, 325, 400, 340);
    // draw_line_between(400, 340, 475, 325);

    DBYTE gap = 35; 

    DBYTE min_temp = 10; 
    DBYTE max_temp = 75;

    DBYTE scale_step = (max_temp - min_temp) / 5;

    for(int i = 0; i < 6; i++) {
        char str[4] = {'\0'};
        sprintf(str, "%d", scale_step * i + min_temp); 
        display_text(str, 320, 385 - gap * i, 0); 
        if(i) {
            draw_dotted_horizontal(355, 750, 370 - gap * (i - 1));
        } 
    }



    float sec_chunk = (775 - 350) / 12; 
    int chunk = (int) sec_chunk; 

    for(int i = 0; i < 12; i++) {
        char str[4] = {'\0'};
        if(i < 10) { sprintf(str, "0%d", i); }
        else { sprintf(str, "%d", i); }

        display_text(str, 350 + chunk * i, 402, 0);
    }
    
    DBYTE min_y = 410; 
    DBYTE max_y = 192; 

    DBYTE x_val1 = 350; 
    DBYTE y_val1 = temp_to_y(min_temp, max_temp, min_y, max_y, 28.0f);

    DBYTE x_val2 = 350 + chunk * 2;
    DBYTE y_val2 = temp_to_y(min_temp, max_temp, min_y, max_y, 30.0f);


    draw_line_between(x_val1, y_val1, x_val2, y_val2);

    DBYTE x_val3 = 350 + chunk * 3;
    DBYTE y_val3 = temp_to_y(min_temp, max_temp, min_y, max_y, 35.0f);

    draw_line_between(x_val2, y_val2, x_val3, y_val3);

    DBYTE x_val4 = 350 + chunk * 5;
    DBYTE y_val4 = temp_to_y(min_temp, max_temp, min_y, max_y, 45.0f);

    draw_line_between(x_val3, y_val3, x_val4, y_val4);

    DBYTE x_val5 = 350 + chunk * 8;
    DBYTE y_val5 = temp_to_y(min_temp, max_temp, min_y, max_y, 42.0f);

    draw_line_between(x_val4, y_val4, x_val5, y_val5);

    DBYTE x_val6 = 350 + chunk * 10;
    DBYTE y_val6 = temp_to_y(min_temp, max_temp, min_y, max_y, 50.0f);

    draw_line_between(x_val5, y_val5, x_val6, y_val6);

    for(int i = 1; i < 3; i++) {
        draw_line_between(355, 400+i, 750, 400+i);
    }

}




    // display_text("10", 320, 390, 0);

    // display_text("15", 320, 390 - 35, 0);
    // draw_dotted_horizontal(355, 750, 390 - 20);
    // // draw_line_between(360, 350, 420, 320);

    // display_text("20", 320, 390 - 70, 0);
    // draw_dotted_horizontal(355, 750, 390 - 55);
    // // draw_line_between(420, 320, 500, 330);

    // display_text("25", 320, 390 - 105, 0);
    // draw_dotted_horizontal(355, 750, 390 - 90);
    
    // display_text("30", 320, 390 - 145, 0);
    // draw_dotted_horizontal(355, 750, 390 - 130);
    
    // display_text("35", 320, 390 - 185, 0);
    // draw_dotted_horizontal(355, 750, 390 - 160);