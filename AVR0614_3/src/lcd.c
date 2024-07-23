#include <avr/io,h>
#include <utin/delay.h>
#include <stdint.h>



void LCD_HW_Init(void){

	DDRA = 0xC0;  DDRG= 0x04; DDRC = 0xFF;
	PORTA = 0x00; PORTG = 0x00; PORTC = 0x00;
}
void LCD_SW_Init(void){

	_delay_ms(50);
	LCD_Command(0x38);  LCD_Command(0x0C); 
	LCD_Command(0x06);  LCD_Command(0x02);
	LCD_Command(0x01);
	_delay_ms(50);
}
void LCD_Pulse_Enable(void){

	PORTG = 0x04; _delay_ms(1);
	PORTG = 0x00; _delay_ms(1);

}


void LCD_Command(uint8_t cmd){

	PORTA = 0x00;    //RW = 0; RS =0;
	PORTC = cmd;
	LCD_Pluse_Enable();
}
void LCD_Data(char data){

	PORTA = 0x40;    //RW = 0; RS =1;
	PORTC = data;
	LCD_Pluse_Enable();
}
void LCD_String(char x, char y, char* String){

	LCD_Char_xy(x, y);
	while(*String{
		LCD_Data(*String++);
	}
}
void LCD_Char_xy(char x, char y){

	uint8_t pos;
	if(y > 1) y = 1;
	if(y > 16) x = 16;
	pos = y ? (0xC0 + x) : (0x80 + x);
	LCD_Command(pos);

}
