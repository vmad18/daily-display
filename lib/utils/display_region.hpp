#pragma once

extern "C" {
    #include "utils.h"
    #include "cstdint"
}

class Region {

    public:
        Region(DBYTE* x, DBYTE* y, DBYTE z); // x_starts, y_starts, length
        virtual ~Region() = default;
        virtual void update(void) const = 0;
        DBYTE *x_starts;
        DBYTE *y_starts;
        DBYTE length;

};