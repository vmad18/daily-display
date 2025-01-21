#ifndef EP_DISPLAY_H
#define EP_DISPLAY_H

#ifndef SPI_UTILS_H
    #include "spi_utils.h"
#endif

#define HEIGHT 480
#define WIDTH 800

void init_display(void); 
void hang_till_done(void);
void refresh_display(void);

void display_img_buff(const BYTE*);
void display_buff_at(const BYTE*, EBYTE, EBYTE, EBYTE, EBYTE);

void display_from_grid(void);
void draw_pixel_at(const EBYTE, const EBYTE);
void draw_line_between(int x1, int y1, int x2, int y2);
void draw_dotted_horizontal(int x1, int x2, int y);
void insert_in_grid(const BYTE*, EBYTE, EBYTE, EBYTE, EBYTE);

void clear(void); 
void sleep(void);
void reset(void);

#endif