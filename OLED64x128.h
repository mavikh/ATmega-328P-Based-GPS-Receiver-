#ifndef OLED64x128_H
#define	OLED64x128_H


#define OLED_I2C_Add	0x78 
#define OLED_WIDTH		128
#define OLED_HIGHTH		64
#define OLED_pages		8
#define OLED_BUFFERSIZE OLED_WIDTH*OLED_HIGHTH/8 //1024: number of total bytes (columns)
						// each page:8rowx128column
#include <stdio.h>
#include <string.h>

void OLED_init();
void *memset(void *ptr, int x, size_t n);
void clear_screen();
void send_OLED_command(char cmnd);
void send_OLED_data(char data);
void set_column_add();
void set_page_add();
void update_screen();
void write_character(unsigned char row, unsigned char col, unsigned char ch);
void OLED_write_text(unsigned char row, unsigned char *dataPtr);

//uint8_t buffer[1024];
// Each byte = one column of a page = 8 pixels on the screen
char buffer[1024];//1024= 8page x 127column in each page(each column:8bits) = number of total bytes in OLED

#endif
