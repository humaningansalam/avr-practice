#include <stdint.h>
#include <avr/io.h>


void BUZZER_Init(void){

	DDRB  |= 0x01;
	PORTB &= 0xFE;


}

void BUZZER_On(uint8_t OnOff){

	if(OnOff) PORTB |= 0x01;
	else	PORTB &= 0xF0;

}
