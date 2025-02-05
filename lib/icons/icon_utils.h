#ifndef ICON_UTIL
#define ICON_UTIL
#include "../utils/utils.h"

typedef struct {
    const char *code;   /* OWM code string, e.g., "01d", "01n", etc. */
    const BYTE *icon;   /* Pointer to the corresponding bitmap array */
} WeatherIconEntry;

#define NUM_WEATHER_ICONS 18
WeatherIconEntry weatherIconMap[NUM_WEATHER_ICONS];

#include <stdio.h>
#include <string.h>

const char* getWeatherIconCode(const char *condition, int isDay) {
    if (strcmp(condition, "clear_sky") == 0) {
        if (isDay)
            return "01d";
        else
            return "01n";
    } else if (strcmp(condition, "few_clouds") == 0) {
        if (isDay)
            return "02d";
        else
            return "02n";
    } else if (strcmp(condition, "scattered_clouds") == 0) {
        if (isDay)
            return "03d";
        else
            return "03n";
    } else if (strcmp(condition, "broken_clouds") == 0) {
        if (isDay)
            return "04d";
        else
            return "04n";
    } else if (strcmp(condition, "shower_rain") == 0) {
        if (isDay)
            return "09d";
        else
            return "09n";
    } else if (strcmp(condition, "rain") == 0) {
        if (isDay)
            return "10d";
        else
            return "10n";
    } else if (strcmp(condition, "thunderstorm") == 0) {
        if (isDay)
            return "11d";
        else
            return "11n";
    } else if (strcmp(condition, "snow") == 0) {
        if (isDay)
            return "13d";
        else
            return "13n";
    } else if (strcmp(condition, "mist") == 0) {
        if (isDay)
            return "50d";
        else
            return "50n";
    } else {
        // If the condition is unknown, default to clear sky
        return isDay ? "01d" : "01n";
    }
}

const BYTE* getWeatherIcon(const char *code) {
    for (int i = 0; i < NUM_WEATHER_ICONS; i++) {
        if (strcmp(weatherIconMap[i].code, code) == 0) {
            return weatherIconMap[i].icon;
        }
    }
    return weatherIconMap[0].icon; // fallback icon
}

// /* Example usage */
// int main(void) {
//     const char *condition = "scattered_clouds";
//     int isDay = 1; // Change to 0 for nighttime

//     const char *iconCode = getWeatherIconCode(condition, isDay);
//     printf("For condition \"%s\" and isDay=%d, the icon code is: %s\n",
//            condition, isDay, iconCode);

//     return 0;
// }

#endif