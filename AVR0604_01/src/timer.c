#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


uint16_t TIMER_1000ms = 0;
uint8_t TIMER_Flag = 1;
uint8_t AM = 1;

void TIMER_Init(void){

	TCCR1A = 0x00;
	TCCR1B = 0x0C;
	OCR1AH = 0x7A;
	OCR1AL = 0x12;
	TIMSK |= (1<<OCIE1A);

}

ISR(TIMER1_COMPA_vect){

	if(TIMER_Flag){
		TIMER_1000ms++;
		if(TIMER_1000ms==43200){
			TIMER_1000ms = 0;
			AM++;
		}
	}
}

void TIMER_Start1(void){

	TIMER_Flag = 1;

}
void TIMER_Start2(void){

	TIMER_Flag = 1;
	TIMER_1000ms = 42950;

}
void TIMER_Stop(void){

	TIMER_Flag = 0;

}
void TIMER_Reset(void){

	TIMER_Flag = 0;
	TIMER_1000ms = 0;
	AM = 1;

}
uint16_t TIMER_GetTime1(void){

	return TIMER_1000ms;
}
uint8_t TIMER_GetTime2(void){

	return AM;
}
