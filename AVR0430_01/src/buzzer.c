#include <avr/io.h>
#include "led.h"
#include "key.h"


void BUZZER_Init(void){

	DDRB |= 0x01;
	PORTB &= 0x00;

}


void BUZZER_On(byte OnOff){

	if(Onoff == 0x01) PORTB |= Onoff;	
	if(Onoff == 0x00) PORTB &= Onoff;		
}
