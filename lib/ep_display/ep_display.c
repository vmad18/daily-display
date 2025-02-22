#include "ep_display.h"
#include "stdlib.h"

// maybe dynamically allocate this?
static BYTE grid[48000] = {~0x00};
static DBYTE max_x = 0; 
static DBYTE max_y = 0;

void init_display(void) {
    static BYTE LUT_VCOM[]={	
        0x0,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x0,	0xF,	0x1,	0xF,	0x1,	0x2,	
        0x0,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    };						

    static BYTE LUT_WW[]={	
        0x10,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x84,	0xF,	0x1,	0xF,	0x1,	0x2,	
        0x20,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    };

    static BYTE LUT_BW[]={	
        0x10,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x84,	0xF,	0x1,	0xF,	0x1,	0x2,	
        0x20,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    };

    static BYTE LUT_WB[]={	
        0x80,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x84,	0xF,	0x1,	0xF,	0x1,	0x2,	
        0x40,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    };

    static BYTE LUT_BB[]={	
        0x80,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x84,	0xF,	0x1,	0xF,	0x1,	0x2,	
        0x40,	0xF,	0xF,	0x0,	0x0,	0x1,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
        0x0,	0x0,	0x0,	0x0,	0x0,	0x0,	
    };

    for(DBYTE i = 0; i < 48000; i++) {
        *(grid + i) = ~(0x00);
    }

    reset();

    spi_write_byte(0x01, PIN_LOW);  // power setting
	spi_write_byte(0x17, PIN_HIGH);  // p1 
    spi_write_byte(0x17, PIN_HIGH); // set VGH/VGL
    spi_write_byte(0x3F, PIN_HIGH); 
    spi_write_byte(0x3F, PIN_HIGH); 
    spi_write_byte(0x11, PIN_HIGH); 
    
    spi_write_byte(0x82, PIN_LOW); // set VCOM DC
    spi_write_byte(0x24, PIN_HIGH);

    spi_write_byte(0x06, PIN_LOW); // set Booster
    spi_write_byte(0x27, PIN_HIGH);
    spi_write_byte(0x27, PIN_HIGH);
    spi_write_byte(0x2F, PIN_HIGH);
    spi_write_byte(0x17, PIN_HIGH);

    spi_write_byte(0x30, PIN_LOW); // PLL setting
    spi_write_byte(0x6, PIN_HIGH);
	
    spi_write_byte(0x04, PIN_LOW); // PWR on

    delay_ms(100);
    hang_till_done();

    spi_write_byte(0x00, PIN_LOW); // pannel setting    
    spi_write_byte(0x3F, PIN_HIGH);

    spi_write_byte(0x61, PIN_LOW); // set display dims
    // set width 800 0x0320
    spi_write_byte(0x03, PIN_HIGH);
    spi_write_byte(0x20, PIN_HIGH);
    // set height 480 0x01E0
    spi_write_byte(0x01, PIN_HIGH);
    spi_write_byte(0xE0, PIN_HIGH);

    spi_write_byte(0x15, PIN_LOW); // some command
    spi_write_byte(0x00, PIN_HIGH);

    spi_write_byte(0x50, PIN_LOW); // some command
    spi_write_byte(0x10, PIN_HIGH);
    spi_write_byte(0x00, PIN_HIGH); 
    
    spi_write_byte(0x60, PIN_LOW); // TCON settings
    spi_write_byte(0x22, PIN_HIGH);

    spi_write_byte(0x65, PIN_LOW); // resolution setting
    spi_write_byte(0x00, PIN_HIGH);
    spi_write_byte(0x00, PIN_HIGH);
    spi_write_byte(0x00, PIN_HIGH);
    spi_write_byte(0x00, PIN_HIGH);

    BYTE count;

	spi_write_byte(0x20, PIN_LOW); //VCOM	
	for(count=0; count<42; count++)
		spi_write_byte(LUT_VCOM[count], PIN_HIGH);

	spi_write_byte(0x21, PIN_LOW); //LUTBW
	for(count=0; count<42; count++)
		spi_write_byte(LUT_WW[count], PIN_HIGH);

	spi_write_byte(0x22, PIN_LOW); //LUTBW
	for(count=0; count<42; count++)
		spi_write_byte(LUT_BW[count], PIN_HIGH);

	spi_write_byte(0x23, PIN_LOW); //LUTWB
	for(count=0; count<42; count++)
		spi_write_byte(LUT_WB[count], PIN_HIGH);

	spi_write_byte(0x24, PIN_LOW); //LUTBB
	for(count=0; count<42; count++)
		spi_write_byte(LUT_BB[count], PIN_HIGH);
}

void refresh_display(void) {
    spi_write_byte(0x12, PIN_LOW); // refresh
    delay_ms(100);
    hang_till_done();
}

void hang_till_done(void) {
    BYTE busy = 0; 

    do {
        spi_write_byte(0x71, PIN_LOW); // get status
        busy = digital_read(BUSY_PIN);
    } while (!busy);
    
    delay_ms(20);
}

void display_img_buff(const BYTE *buff) {
    spi_write_byte(0x13, PIN_LOW);

    for(EBYTE y = 0; y < HEIGHT; y++) {
        for(EBYTE x = 0; x < WIDTH / 8; x++) {
            EBYTE idx = y * WIDTH / 8 + x; 
            spi_write_byte(~(*(buff + idx)), PIN_HIGH);
        }
    }

    refresh_display();
}

void display_buff_at(
                const BYTE *buff, 
                EBYTE x_start, 
                EBYTE y_start, 
                EBYTE width, 
                EBYTE height) {
    spi_write_byte(0x13, PIN_LOW);

    for(EBYTE y = 0; y < HEIGHT; y++) {
        for(EBYTE x = 0; x < WIDTH / 8; x++) {
            if(y >= y_start && y < (y_start + height) && 8 * x >= x_start && 8 * x < (x_start + width)) {                
                EBYTE idx = (y - y_start) * width / 8 + x - x_start / 8;
                spi_write_byte(~(*(buff + idx)), PIN_HIGH);
            } else {
                spi_write_byte(0x00, PIN_HIGH);
            }
        }
    }

    refresh_display();
}

void display_from_grid(void) {
    spi_write_byte(0x13, PIN_LOW);

    for(EBYTE y = 0; y < HEIGHT; y++) {
        for(EBYTE x = 0; x < WIDTH / 8; x++) {
            EBYTE idx = y * WIDTH / 8 + x; 
            spi_write_byte(~(*(grid + idx)), PIN_HIGH);
        }
    }
    
    refresh_display();
}

void draw_pixel_at(const EBYTE x, const EBYTE y)  {
    EBYTE idx = y * WIDTH / 8 + x / 8;
    grid[idx] |= (0x80 >> (x % 8));
    grid[idx] = ~grid[y * WIDTH / 8 + x];
}

void draw_line_between(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = x1 < x2 ? 1 : -1;  // Step in x direction
    int sy = y1 < y2 ? 1 : -1;  // Step in y direction
    
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    
    while (1) {
        draw_pixel_at(x1, y1);
        if (x1 == x2 && y1 == y2) {
            break;
        }
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dy) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_dotted_horizontal(int x1, int x2, int y) {
    for(EBYTE x = x1 / 4 ; x <= x2 / 4; x+=4) {
        draw_pixel_at(4*x, y);
    }
}


void insert_in_grid(const BYTE *buff, EBYTE x_start, EBYTE y_start, EBYTE width, EBYTE height) {
    
    max_x = max_x > (x_start + width) ? max_x : (x_start + width); 
    max_y = max_y > y_start + height ? max_y : y_start + height;

    x_start = x_start % 8 ? x_start + 8 - (x_start % 8) : x_start;

    EBYTE x_end = x_start + width;
    // x_end += x_end % 8 ? x_end + 8 - (x_end % 8) : x_end;

    for(EBYTE y = y_start; y < y_start + height; y++) {
        for(EBYTE x = x_start / 8; x < x_end / 8; x++) {
            // if(8*(x - x_start) < width) {
                EBYTE grid_idx = y * WIDTH / 8 + x;
                EBYTE buff_idx = (y - y_start) * width / 8 + x - x_start / 8;
                *(grid + grid_idx) = *(buff + buff_idx);
           //  }
        }
    }
}

void clear(void) {
    spi_write_byte(0x13, PIN_LOW);

    for(DBYTE i = 0; i < HEIGHT; i++) {
        for(DBYTE j = 0; j < WIDTH; j++) {
            spi_write_byte(0x00, PIN_HIGH);
            if(j < WIDTH / 8) {
                *(grid + i * WIDTH / 8 + j) = ~(0x00);
            }
        }
    }
    
    refresh_display();
}

void reset(void) {
    digital_write(RST_PIN, PIN_HIGH);
    delay_ms(20); 
    digital_write(RST_PIN, PIN_LOW);  
    delay_ms(4);
    digital_write(RST_PIN, PIN_HIGH);
    delay_ms(20);   
}

void sleep(void) {
    spi_write_byte(0X02, PIN_LOW);
    hang_till_done();
    spi_write_byte(0X07, PIN_LOW);
    spi_write_byte(0xA5, PIN_HIGH);
}
