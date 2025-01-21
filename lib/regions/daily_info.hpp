#pragma once
#include "display_region.hpp"

class DailyInfo: Region {

    public:
        DailyInfo(DBYTE *x_start, DBYTE *y_start);
        void update(void) const override;
        int16_t temp_to_y(DBYTE min_temp, DBYTE max_temp, DBYTE min_y, DBYTE max_y, float temp) const;
};