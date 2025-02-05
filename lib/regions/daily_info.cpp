#include "daily_info.hpp"
#include "stdio.h"

#include <string>
#include <algorithm>

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
    #include "network.h"
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
    char text[30] = {'\0'};

    sprintf(text, "%s %s", data.curr_date, data.curr_time);
    
    load16(); 
    std::string buff_date(text);

    std::replace(buff_date.begin(), buff_date.end(), '_', ' ');

    display_text(buff_date.c_str(), 850 - strlen(buff_date.c_str()) * 12, 40, 0);

    load32(); 
    char buff_loc[] = "College Park, MD";
    display_text(buff_loc, 850 - strlen(buff_loc) * 19, 0, 0);

    loadWeatherIcons128();
    insert_in_grid(getWeatherIcon(getWeatherIconCode(data.curr_desc, data.day)), 5, 5, 128, 128);
    printf("%s\n", getWeatherIconCode(data.curr_desc, data.day));

    load16();
    sprintf(text, "Feels like %d", data.feel_temp);    
    DBYTE old_pos = display_text(text, 125, 65 + 25, 2);
    insert_in_grid(fahrenheit_32px, 125 + old_pos - 8, 65 + 25, 32, 32);
    old_pos = display_text(text, 125, 65 + 25, 2);
    
    load64();    
    sprintf(text, "%d", data.temp);
    DBYTE new_pos = display_text(text, 128 + 10, 5, 2);
    insert_in_grid(fahrenheit_48px, 128 + new_pos, 35, 48, 48);
    new_pos = display_text(text, 128 + 10, 5, 2);

    load16();
    sprintf(text, "%s am", data.sunrise);
    insert_in_grid(sunrise_56px, 20, 150, 56, 56);
    display_text(text, 74, 160, 2);
    display_text("Sunrise", 74, 145, 2);

    sprintf(text, "%s pm", data.sunset);
    insert_in_grid(sunset_56px, 155, 150, 56, 56);
    display_text(text, 210, 160, 2);
    display_text("Sunset", 210, 145, 2);

    sprintf(text, "%dm/s", data.wind);
    insert_in_grid(strong_wind_56px, 20, 150 + GAP, 56, 56);
    new_pos = display_text(text, 74, 170 + GAP, 0);
    display_text("Wind Speed", 74, 155 + GAP, 2);

    sprintf(text, "%d%%", data.humidity);
    insert_in_grid(humidity_56px, 155, 150 + GAP, 56, 56);
    new_pos = display_text(text, 210, 170 + GAP, 0);
    display_text("Humidity", 210, 155 + GAP, 2);

    if(data.uv >= 0 && data.uv <= 2) {
        sprintf(text, "%d Low", data.uv);
    } else if(data.uv > 2 && data.uv <= 5) {
        sprintf(text, "%d Mod", data.uv);
    } else if(data.uv > 5 && data.uv <= 7) {
        sprintf(text, "%d High", data.uv);
    } else if(data.uv > 8) {
        sprintf(text, "%d Very High", data.uv);
    }
    insert_in_grid(day_sunny_56px, 20, 150 + 2 * GAP, 56, 56);
    new_pos = display_text(text, 74, 170 + 2 * GAP, 2);
    display_text("UV Index", 74, 155 + 2 * GAP, 2);

    sprintf(text, "%d psi", data.pressure);
    insert_in_grid(barometer_56px, 155, 150 + 2 * GAP, 56, 56);
    new_pos = display_text(text, 210, 170 + 2 * GAP, 2);
    display_text("Pressure", 210, 155 + 2 * GAP, 2);

    if(data.aqi >= 0 && data.aqi <= 50) {
        sprintf(text, "%d Low", data.aqi);
    } else if(data.aqi > 50 && data.aqi <= 100) {
        sprintf(text, "%d Mod", data.aqi);
    } else if(data.aqi > 100 && data.aqi <= 150) {
        sprintf(text, "%d High", data.aqi);
    } else if(data.aqi > 150) {
        sprintf(text, "%d Very High", data.aqi);
    }
    insert_in_grid(dust_56px, 20, 150 + 3 * GAP, 56, 56);
    new_pos = display_text(text, 74, 170 + 3 * GAP, 2);
    display_text("AQI", 74, 155 + 3 * GAP, 2);

    sprintf(text, "%.2f mi", data.visibility);
    insert_in_grid(fog_56px, 155, 150 + 3 * GAP, 56, 56);
    new_pos = display_text(text, 210, 170 + 3 * GAP, 2);
    display_text("Visibility", 210, 155 + 3 * GAP, 2);


    DBYTE start_txt = 332 + 48;
    DBYTE start_icon = 322 + 48;
    DBYTE start_height = 80;

    for(int i = 0; i < 5; i++) {
        data.days[i].day[3] = '\0';
    }

    loadWeatherIcons48();
    sprintf(text, "%d|%d", data.days[0].high, data.days[0].low);
    insert_in_grid(getWeatherIcon(getWeatherIconCode(data.days[0].desc, 1)), start_icon, start_height + HEIGHT_SHIFT, 48, 48);
    DBYTE padding = display_text(text, start_txt - 8, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 14, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text(text, start_txt - 8, start_height + HEIGHT_SHIFT + 38, 2);
    display_text(data.days[0].day, start_txt, start_height, 2); 
    
    sprintf(text, "%d|%d", data.days[1].high, data.days[1].low);
    insert_in_grid(getWeatherIcon(getWeatherIconCode(data.days[1].desc, 1)), start_icon + X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text(text, start_txt - 8 + X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 15 + X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text(text, start_txt - 8 + X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text(data.days[1].day, start_txt + X_GAP, start_height, 2); 

    sprintf(text, "%d|%d", data.days[2].high, data.days[2].low);
    insert_in_grid(getWeatherIcon(getWeatherIconCode(data.days[2].desc, 1)), start_icon + 2 * X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text(text, start_txt - 12 + 2 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 20 + 2 * X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text(text, start_txt - 12 + 2 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text(data.days[2].day, start_txt + 2 * X_GAP, start_height, 0); 

    sprintf(text, "%d|%d", data.days[3].high, data.days[3].low);
    insert_in_grid(getWeatherIcon(getWeatherIconCode(data.days[3].desc, 1)), start_icon + 3 * X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text(text, start_txt - 8 + 3 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 20 + 3 * X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text(text, start_txt - 8 + 3 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text(data.days[3].day, start_txt + 3 * X_GAP, start_height, 0); 

    sprintf(text, "%d|%d", data.days[4].high, data.days[4].low);
    insert_in_grid(getWeatherIcon(getWeatherIconCode(data.days[4].desc, 1)), start_icon + 4 * X_GAP, start_height + HEIGHT_SHIFT, 48, 48);
    padding = display_text(text, start_txt - 8 + 4 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    insert_in_grid(fahrenheit_32px, start_txt + padding - 15 + 4 * X_GAP, start_height + HEIGHT_SHIFT + 38, 32, 32);
    display_text(text, start_txt - 8 + 4 * X_GAP, start_height + HEIGHT_SHIFT + 38, 2);
    display_text(data.days[4].day, start_txt + 4 * X_GAP, start_height, 2); 


    int min_temp = 1000; 
    int max_temp = -1000;

    for(int i = 0; i < 4; i++) {
        min_temp = data.hours[i] < min_temp ? data.hours[i] : min_temp;
        max_temp = data.hours[i] > max_temp ? data.hours[i] : max_temp;
    }

    min_temp += (5 - min_temp % 5) - 20;
    max_temp += (5 - max_temp % 5) + 10;

    DBYTE scale_step = (max_temp - min_temp) / 5;
    
    DBYTE gap = 35; 
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
    DBYTE y_val1 = temp_to_y(min_temp, max_temp, min_y, max_y, data.hours[0]);

    DBYTE x_val2 = 350 + chunk * 3.5;
    DBYTE y_val2 = temp_to_y(min_temp, max_temp, min_y, max_y, data.hours[1]);
    draw_line_between(x_val1, y_val1, x_val2, y_val2);


    DBYTE x_val3 = 350 + chunk * 7.5;
    DBYTE y_val3 = temp_to_y(min_temp, max_temp, min_y, max_y, data.hours[2]);
    draw_line_between(x_val2, y_val2, x_val3, y_val3);

    DBYTE x_val4 = 350 + chunk * 11.5;
    DBYTE y_val4 = temp_to_y(min_temp, max_temp, min_y, max_y, data.hours[3]);
    draw_line_between(x_val3, y_val3, x_val4, y_val4);

    for(int i = 1; i < 3; i++) {
        draw_line_between(355, 400+i, 750, 400+i);
    }

}
