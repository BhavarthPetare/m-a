#include <reg51.h>
#define LCD P2

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_init();
void delay();

void main() {
	lcd_init();
	lcd_data('H');
	lcd_data('E');
	lcd_data('L');
	lcd_data('L');
	lcd_data('O');
	
	lcd_cmd(0xC0);
	lcd_data('W');
	lcd_data('O');
	lcd_data('R');
	lcd_data('L');
	lcd_data('D');
	
	while(1);
}

void lcd_cmd(unsigned char cmd) {
	LCD = cmd;
	RS = 0;
	RW = 0;
	EN = 1;
	delay();
	EN = 0;
}

void lcd_data(unsigned char dat) {
	LCD = dat;
	RS = 1;
	RW = 0;
	EN = 1;
	delay();
	EN = 0;
}

void lcd_init() {
	lcd_cmd(0x38); //8-bit mode
	lcd_cmd(0x0C); //display on
	lcd_cmd(0x06); //auto inc
	lcd_cmd(0x01); //clear display
	lcd_cmd(0x80); //cursor at start
}

void delay() {
	unsigned int i, j;
	for(i=0; i<200; i++) {
		for(j=0; j<200; j++);
	}
}