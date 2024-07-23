#include <avr/io.h>
#include <stdint.h>

void LED_Init(void){

	DDRF |= 0xFC;
	PORTF &= 0xFC;
}

void LED_On(uint8_t OnOff){

	PORTF  =  (PORTF  |  0xFC)  &  (~(OnOff<<2));

}

