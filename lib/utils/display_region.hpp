#pragma once

extern "C" {
    #include "utils.h"
}

class Region {

    private:
        DBYTE *x_starts;
        DBYTE *y_starts;
        DBYTE length;

    public:
        Region(DBYTE*, DBYTE*, DBYTE); // x_starts, y_starts, length
        ~Region() = default;
        virtual void update(void) const;
};