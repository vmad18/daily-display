#pragma once
#include "utils/display_region.hpp"

class WeatherRegion: Region {

    public:
        WeatherRegion(DBYTE *x_start, DBYTE *y_start);
        void update(void) const override;
};