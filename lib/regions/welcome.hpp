#pragma once
#include "utils/display_region.hpp"

class Welcome: Region {

    public:
        Welcome(DBYTE *x_start, DBYTE *y_start);
        void update(void) const override;
};