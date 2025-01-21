#include "welcome.hpp"
#include "stdio.h"

Welcome::Welcome(DBYTE *x_start, DBYTE *y_start): Region(x_start, y_start, 10) {};
void Welcome::update(void) const {}