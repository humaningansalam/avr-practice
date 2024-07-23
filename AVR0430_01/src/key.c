#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"
#include "key.h"

void Delay(byte4 Delay){

	volatile byte4 i;
	for(i=0;i<Delay;i++)

	
}

void KEY_Init(void){

	DDRE &= 0x0F; PORTE |= 0xF0;
	DDRE |= 0x0F; PORTE &= 0xF0;
	EICRB = 0xAA;
	EIMSK = 0xF0;
}


byte KEY_Read(void){

	return ~(PINE>>4) & 0x0F;

}

ISR(INT4_vect){

	LED_On(1<<0);
	BUZZER_On(0x01); Delay(10000); BUZZER_On(0x00);
}



ISR(INT5_vect){

	LED_On(1<<1);
	BUZZER_On(0x01); Delay(10000); BUZZER_On(0x00);
}



ISR(INT6_vect){

	LED_On(1<<2);
	BUZZER_On(0x01); Delay(10000); BUZZER_On(0x00);
}



ISR(INT7_vect){

	LED_On(1<<3);
	BUZZER_On(0x01); Delay(10000); BUZZER_On(0x00);
}



