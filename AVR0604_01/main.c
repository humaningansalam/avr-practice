#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


void Init(void);
void Stop_Watch_Display(void);
void UART_Control(void);


int main(void){

	Init();
	sei();
	while(1){

		Stop_Watch_Display();
		UART_Control();
	}

	return 0;
}


void Init(void){

	UART_Init();
	FND_Init();
	UART_Init();
}



void Stop_Watch_Display(void){

	uint16_t Time;
	uint8_t AM;
	Time = TIMER_GetTime1();
	AM = TIMER_GetTime2();
	if((Time %10) % 2 == 0) FND_Write(Time/60 % 10, 0, 0); //분 :1의자리_짝수
	else  FND_Write(Time/60 % 10, 0, 1); //분 :1의자리_홀수
	FND_Write(Time/600 % 06, 1, 0); //분 : 10의 자리
	
	if(AM % 2 == 0) FND_Write(Time/3600, 2, 0); //시간 : 1의자리_짝수
	else FND_Write(Time/3600, 2, 1); //시간 : 1의자리_짝수

	FND_Write(Time/36000 % 10, 2, 1); //분 : 10의 자리
}
void UART_Control(void){

	uint8_t Data;
	if(UART_GetChar(&Data) == 0) return;
	UART_PutChar(Data);
	switch(Data){
		case'1' : TIMER_Start1(); break;
		case '2' : TIMER_Stop(); break;
		case '3' : TIMER_Reset(); break;
		case '4' : TIMER_Start2(); break;
		default : break;
	}
}
