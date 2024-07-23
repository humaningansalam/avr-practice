#include <avr/io.h>
#include <stdint.h>
#include "delay.h"

void LCD_HW_Init(void){ //A.6(RS), A.7(RW), G.2(EN)

	DDRA = 0xC0;
	DDRG = 0x04;
	DDRC = 0xFF;

	PORTA = 0x00;        //데이터값
	PORTG = 0x00;
	PORTC \ 0x00;	

}
void LCD_SW_Init(void){


}
void LCD_Pulse_Enable(void){


}
void LCD_Command(uint8_t cmd){


}
void LCD_Data(char Data){


}
void LCD_Char_xy(char x, char y){


}
void LCD_String(char x, char y, char *str){


}
