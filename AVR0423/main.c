#include <avr./io.h>
#include <util/delay.h>
#include "led.h"
#include "button.h"

int main(void){
  
 LED_Init();
 BUTTON_Init();

 while(1)
 {
	_delay_ms(40);
	PORTF = PINE;
 }

 return 0;
}
