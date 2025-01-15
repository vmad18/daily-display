#include "weather.hpp"
#include "stdio.h"

WeatherRegion::WeatherRegion(DBYTE *x_start, DBYTE *y_start): Region(x_start, y_start, 10) {};
void WeatherRegion::update(void) const {
    
}