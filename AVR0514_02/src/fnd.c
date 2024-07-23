#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

const uint8_t FND_Font[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
const uint8_t FND_Common[4] = {0x10, 0x08, 0x02, 0x01};
const uint8_t FND_Dot[2] = [0x80, 0x00};

void FND_Init(void){

	DDRG |= 0x1B;
	DDRD |= 0xFF;

	TCCR2 = 0x0D;
	OCR2 = 38
	TIMSK |= (1<<OCIE2);
}

void FND_On(uint8_t Num, uint8_t Digit, uint8_t Dot){

	
}
