#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"
#include "key.h"
#include "buzzer.h"

void Init(void);

int main(void){

	Init();
	LED_On(0x2A);
	sei();
	while(1);
	return 0;
}

void Init(void){


	LED_Init();
	KEY_Init();
	BUZZER_Init();

}
