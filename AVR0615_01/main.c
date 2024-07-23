#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "buzzer.h"
#include "fnd.h"
#include "keypad.h"
#include "led.h"
#include "timer.h"


void Init(void);
void Delay(uint32_t Delay);
void KEYPAD_Control(void);
void StopWatch_Display(void);
void WatchTime_Display(void);

int main(void){
	
	Init();
	LED_On(0x2A); Delay(100000);
	FND_On(1,0,0); Delay(100000);
	sei();

	while(1){

		#if 1
			KEYPAD_Control();
		#endif
		#if 0
			StopWatch_Display();
		#endif
		#if 0
			WatchTime_display();
		#endif
	}
	return 0;
}





void Init(void){

	BUZZER_Init();
	FND_Init();
	KEYPAD_Init();
	LED_Init();
	TIMER_Init();
}
void Delay(uint32_t Delay){

	volatile uint32_t i;
	for(i=0; i<Delay; i++);
}
void KEYPAD_Control(void){

	uint8_t key;
	if(KEYPAD_GetKey(&key) == 0) return ;
	FND_Write(key % 10, 2, 0); Delay(10000);
	FND_Write(key / 10, 3, 0); Delay(10000);
}
void StopWatch_Display(void){

	uint16_t time;
	time = TIMER_GetTime();
	FND_Write(time      % 10, 0, 0);
	FND_Write(time/10   % 10, 1, 0);
	FND_Write(time/100  % 10, 2, 0);
	FND_Write(time/1000 % 10, 3, 0);
}
void WatchTime_Display(void){


	uint16_t time;
	time = TIMER_GetTime();
	FND_Write(time      % 10, 0, 1);
	FND_Write(time/60   % 06, 1, 0);
	FND_Write(time/600  % 10, 2, 1);  //min 1
	FND_Write(time/3600 % 06, 3, 0);  //min 10
}

