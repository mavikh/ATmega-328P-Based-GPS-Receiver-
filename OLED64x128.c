#include "OLED64x128.h"
#include "i2c.h"

const unsigned char font_6x8 [][5] =
{				      //          Decimal code
     { 0x00, 0x00, 0x00, 0x00, 0x00}, // sp 	        32
     { 0x00, 0x00, 0x2f, 0x00, 0x00}, // !		33
     { 0x00, 0x07, 0x00, 0x07, 0x00}, // "		34
     { 0x14, 0x7f, 0x14, 0x7f, 0x14}, // #		35
     { 0x24, 0x2a, 0x7f, 0x2a, 0x12}, // $		36
     { 0xc4, 0xc8, 0x10, 0x26, 0x46}, // %		37
     { 0x36, 0x49, 0x55, 0x22, 0x50}, // &		38
     { 0x00, 0x05, 0x03, 0x00, 0x00}, // '		39
     { 0x00, 0x1c, 0x22, 0x41, 0x00}, // (		40
     { 0x00, 0x41, 0x22, 0x1c, 0x00}, // )		41
     { 0x14, 0x08, 0x3E, 0x08, 0x14}, // *		42
     { 0x08, 0x08, 0x3E, 0x08, 0x08}, // +		43
     { 0x00, 0x00, 0x50, 0x30, 0x00}, // ,		44
     { 0x10, 0x10, 0x10, 0x10, 0x10}, // -		45
     { 0x00, 0x60, 0x60, 0x00, 0x00}, // .		46
     { 0x20, 0x10, 0x08, 0x04, 0x02}, // /		47
     { 0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0		48
     { 0x00, 0x42, 0x7F, 0x40, 0x00}, // 1		49
     { 0x42, 0x61, 0x51, 0x49, 0x46}, // 2		50
     { 0x21, 0x41, 0x45, 0x4B, 0x31}, // 3		51
     { 0x18, 0x14, 0x12, 0x7F, 0x10}, // 4		52
     { 0x27, 0x45, 0x45, 0x45, 0x39}, // 5		53
     { 0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6		54
     { 0x01, 0x71, 0x09, 0x05, 0x03}, // 7		55
     { 0x36, 0x49, 0x49, 0x49, 0x36}, // 8		56
     { 0x06, 0x49, 0x49, 0x29, 0x1E}, // 9		57
     { 0x00, 0x36, 0x36, 0x00, 0x00}, // :		58
     { 0x00, 0x56, 0x36, 0x00, 0x00}, // ;		59
     { 0x08, 0x14, 0x22, 0x41, 0x00}, // <		60
     { 0x14, 0x14, 0x14, 0x14, 0x14}, // =		61
     { 0x00, 0x41, 0x22, 0x14, 0x08}, // >		62
     { 0x02, 0x01, 0x51, 0x09, 0x06}, // ?		63
     { 0x32, 0x49, 0x59, 0x51, 0x3E}, // @		64
     { 0x7E, 0x11, 0x11, 0x11, 0x7E}, // A		65
     { 0x7F, 0x49, 0x49, 0x49, 0x36}, // B		66
     { 0x3E, 0x41, 0x41, 0x41, 0x22}, // C		67
     { 0x7F, 0x41, 0x41, 0x22, 0x1C}, // D		68
     { 0x7F, 0x49, 0x49, 0x49, 0x41}, // E		69
     { 0x7F, 0x09, 0x09, 0x09, 0x01}, // F		70
     { 0x3E, 0x41, 0x49, 0x49, 0x7A}, // G		71
     { 0x7F, 0x08, 0x08, 0x08, 0x7F}, // H		72
     { 0x00, 0x41, 0x7F, 0x41, 0x00}, // I		73
     { 0x20, 0x40, 0x41, 0x3F, 0x01}, // J		74
     { 0x7F, 0x08, 0x14, 0x22, 0x41}, // K		75
     { 0x7F, 0x40, 0x40, 0x40, 0x40}, // L		76
     { 0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M		77
     { 0x7F, 0x04, 0x08, 0x10, 0x7F}, // N		78
     { 0x3E, 0x41, 0x41, 0x41, 0x3E}, // O		79
     { 0x7F, 0x09, 0x09, 0x09, 0x06}, // P		80
     { 0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q		81
     { 0x7F, 0x09, 0x19, 0x29, 0x46}, // R		82
     { 0x46, 0x49, 0x49, 0x49, 0x31}, // S		83
     { 0x01, 0x01, 0x7F, 0x01, 0x01}, // T		84
     { 0x3F, 0x40, 0x40, 0x40, 0x3F}, // U		85
     { 0x1F, 0x20, 0x40, 0x20, 0x1F}, // V		86
     { 0x3F, 0x40, 0x38, 0x40, 0x3F}, // W		87
     { 0x63, 0x14, 0x08, 0x14, 0x63}, // X		88
     { 0x07, 0x08, 0x70, 0x08, 0x07}, // Y		89
     { 0x61, 0x51, 0x49, 0x45, 0x43}, // Z		90
     { 0x00, 0x7F, 0x41, 0x41, 0x00}, // [		91
     { 0x55, 0x2A, 0x55, 0x2A, 0x55}, // \		92
     { 0x00, 0x41, 0x41, 0x7F, 0x00}, // ]		93
     { 0x04, 0x02, 0x01, 0x02, 0x04}, // ^		94
     { 0x40, 0x40, 0x40, 0x40, 0x40}, // _		95
     { 0x00, 0x01, 0x02, 0x04, 0x00}, // '		96
     { 0x20, 0x54, 0x54, 0x54, 0x78}, // a		97
     { 0x7F, 0x48, 0x44, 0x44, 0x38}, // b		98
     { 0x38, 0x44, 0x44, 0x44, 0x20}, // c		99
     { 0x38, 0x44, 0x44, 0x48, 0x7F}, // d		100
     { 0x38, 0x54, 0x54, 0x54, 0x18}, // e		101
     { 0x08, 0x7E, 0x09, 0x01, 0x02}, // f		102
     { 0x0C, 0x52, 0x52, 0x52, 0x3E}, // g		103
     { 0x7F, 0x08, 0x04, 0x04, 0x78}, // h		104
     { 0x00, 0x44, 0x7D, 0x40, 0x00}, // i		105
     { 0x20, 0x40, 0x44, 0x3D, 0x00}, // j		106
     { 0x7F, 0x10, 0x28, 0x44, 0x00}, // k		107
     { 0x00, 0x41, 0x7F, 0x40, 0x00}, // l		108
     { 0x7C, 0x04, 0x18, 0x04, 0x78}, // m		109
     { 0x7C, 0x08, 0x04, 0x04, 0x78}, // n		110
     { 0x38, 0x44, 0x44, 0x44, 0x38}, // o		111
     { 0x7C, 0x14, 0x14, 0x14, 0x08}, // p		112
     { 0x08, 0x14, 0x14, 0x18, 0x7C}, // q		113
     { 0x7C, 0x08, 0x04, 0x04, 0x08}, // r		114
     { 0x48, 0x54, 0x54, 0x54, 0x20}, // s		115
     { 0x04, 0x3F, 0x44, 0x40, 0x20}, // t		116
     { 0x3C, 0x40, 0x40, 0x20, 0x7C}, // u		117
     { 0x1C, 0x20, 0x40, 0x20, 0x1C}, // v		118
     { 0x3C, 0x40, 0x30, 0x40, 0x3C}, // w		119
     { 0x44, 0x28, 0x10, 0x28, 0x44}, // x		120
     { 0x0C, 0x50, 0x50, 0x50, 0x3C}, // y		121
     { 0x44, 0x64, 0x54, 0x4C, 0x44}, // z		122
     { 0x08, 0x6C, 0x6A, 0x19, 0x08}, // { (lighting)	123
     { 0x0C, 0x12, 0x24, 0x12, 0x0C}, // | (heart)	124
     { 0x7E, 0x7E, 0x7E, 0x7E, 0x7E}, // square		125
 };

void send_OLED_command(char cmnd){
	TWI_Start();
	// _delay_ms(1000);//?
	TWI_Transmit_Add(OLED_I2C_Add);
	TWI_Transmit_byte(0x00); // 0x00 for command, 0x40 for data
	TWI_Transmit_byte(cmnd);
	TWI_Stop();
 }

void send_OLED_data(char data){
	TWI_Transmit_byte(data);
 }

/*
 * Initialize OLED:
 * Vcc generated by internal DC/DC circuit
 * Horizontal addressing mode
 * */
void OLED_init(){//in func. ro ba sample code haye SSD1306.cpp va OLED.ino moghayese kardam eyne hame****************
	send_OLED_command(0xAE);// Set Display Off
	send_OLED_command(0xD5);// Set DisplayClk Divide Ratio(Osc. Freq.)
	send_OLED_command(0x80);
	send_OLED_command(0xA8);// Set Multiples Ratio
	send_OLED_command(0x3F);
	send_OLED_command(0xD3);// Set Display Offset
	send_OLED_command(0x00);
	send_OLED_command(0x40);// Set Display Start Line
	send_OLED_command(0x8D);// Set Charge Pump
	send_OLED_command(0x14);// Vcc generated by internal DC/DC circuit

	// Set memory addressing mode: Horizontal addressing mode
	send_OLED_command(0x20);// SSD1306_MEMORYMODE
	send_OLED_command(0x00);// horizontal addressing mode

	send_OLED_command(0xA1);// Set Segment Re-Map
	send_OLED_command(0xC8);// Set COM Output Scan Direction
	send_OLED_command(0xDA);// Set COM Pins Hardware Configuration
	send_OLED_command(0x12);
	send_OLED_command(0x81);// Set Contrast Cntl
	send_OLED_command(0xCF);// Vcc generated by internal DC/DC circuit
	send_OLED_command(0xD9);// Set Pre-Charge Period
	send_OLED_command(0xF1);// Vcc generated by internal DC/DC circuit
	send_OLED_command(0xDB);// Set VCOMH Deselect Level
	send_OLED_command(0x40);
	send_OLED_command(0xA4);// Set Entire Display On/Off, entire display:on
	send_OLED_command(0xA6);// Set Normal/Inverse Display, set to normal     // Non-inverted display
	send_OLED_command(0xAF);// Set Display On // Turn display back on
}


/*
 * GDDRAM = 128 x 64 bits and devided to 8 pages
 * When one data byte is written into GDDRAM, all the rows image data of the same
 * page of the current column(8 bits) pointed by the column address pointer are filled.
 * Data bit D0 is written into the top row, while data bit D7 is written into bottom row.
 * */
void update_screen() {
      set_column_add();
      set_page_add();

      for(int page = 0; page < 8; page++) {
       	 TWI_Start();
     	 TWI_Transmit_Add(OLED_I2C_Add);
       	 TWI_Transmit_byte(0x40); // 0x00 for command, 0x40 for data
          for(int column = 0; column < 128; column++) {
           	 TWI_Transmit_byte(buffer[128*page + column]);
          }
          TWI_Stop();
      }
  }

/*
 * Fills all the buffer with 0 to clear the screen
 * */
void clear_screen() {
	memset(buffer, 0, 1024);
	update_screen();
}

/*
 * Column_add: 3 bytes
 * Setup column start and end address
 * 128 column: Each column in one page is 8bit
 * */
void set_column_add(){
	send_OLED_command(0x21);// column add
	send_OLED_command(0x00);// start column
	send_OLED_command(0x7F);// end column=128
}

/*
 * Page_add: 3 bytes
 * Setup page start and end address
 * 8 pages: each page = 128 column x 8 row
 * */
void set_page_add(){
	send_OLED_command(0x22);// page add
	send_OLED_command(0x00);// start page
	send_OLED_command(0x07);// end page
}

/*
 * This function write each character from 'fon_6x8' look up table and adds one byte 0x00 after each character
 * Depending on value of row and column, index is calculated and depending on index, character is written on related page
 * Each character cantains 5 bytes(5column)
 * 1byte empty: 1column equal to 0x00
 * Each byte fills one column of the page
 * index:(0~1023) number of each column on screen
 * 0~127:page0, 128~255:page1, 256~383:page2, 384~511:page3, 512~639:page4, 640~767:page5
 * 768~895:page6, 896~1023:page7
 * row  :(0~7) for each page
 * col*6: to protect characters from being written on each other;
 *      : the next character from same row is writen on next 6 columns
 * */
void write_character(unsigned char row, unsigned char col, unsigned char ch) {
     unsigned int index = 0;
     unsigned int i = 0;
  //   col -= 1;
  //   row -= 1;

     // check for out off range
     if ((col > OLED_WIDTH)||(col < 0)) return;
     if ((row > 7)||(row < 0)) return;

     index = (unsigned int) col * 6  + (unsigned int) row * OLED_WIDTH; // determines which byte(column) on screen

     // write character (5bytes + 1byte empty):
	 for (i = 0; i < 6; i++)
	 {
		 if (i==5)
		   buffer[index++] = 0x00; // write one column empty after character
		 else
		   buffer[index++] = font_6x8[ch - 32][i]; // write character
	 }
}


void OLED_write_text(unsigned char row, unsigned char *dataPtr) {   //print small font text, text to print, should the text be scrollable(0/1)
   unsigned char col = 0;         // variable for col coordinate
 //  printf("Value of *dataPtr variable: %d\n", *dataPtr);  //prints value of x

   if (row < 0) row = 0;
   if (row <= (OLED_HIGHTH/8 - 1)) {
     while (*dataPtr) {           // loop to the end of string
       write_character(row, col, *dataPtr);
 //      printf("Address stored in dataPtr variable: %x\n", dataPtr);	//prints add of x where it is stored in memory

       col++;
       dataPtr++;
     }
  }
  return;
}