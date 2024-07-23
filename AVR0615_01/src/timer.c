#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


uint16_t TIMER_100ms = 0;
uint8_t TIMER_Flag = 1;

void TIMER_Init(void){

              TCCR1A     =    0x00;              //분주비, (  )Mode, (내부 타이머/ 외부 pwm), 비교일치
              TCCR1B     =    0x0C;              // TCNT1AH / TCNT1AL = 16bit timer
              OCR1AH    =    0x0C;              // 0x0C34
              OCR1AL     =    0x34;
              TIMSK      |=    (1<<OCIE1A);   //100msec  =  0.1sec
}

ISR(TIMER1_COMPA_vect){
	
	if(TIMER_Flag = 1) TIMER_100ms++;
}
void TIMER_Start(void){
	TIMER_Flag = 1;

}
void TIMER_Stop(void){
	TIMER_Flag = 0;

}
void TIMER_Reset(void){

	TIMER_Flag = 0;
	TIMER_100ms = 0;
}
uint16_t TIMER_GetTime(void){

	
	return TIMER_100ms;
}
