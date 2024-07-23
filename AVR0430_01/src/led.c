#include <avr/io.h>



void LED_Init(void){

	DDRF |= 0xFC;  //DDRF = DDRF | 0xFC
	               //111111?? = ???? ???? | 1111 1100
}


void LED_On(byte Data){

	PORTF = (PORTF | 0xFC) & (~(Data<<2));
}



