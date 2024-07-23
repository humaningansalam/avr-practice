#include  <avr/io.h>
#include "led.h"


unsigned  char  LED_Pattern[18] = 
{0x00, 0x20, 0x30, 0x38, 0x3C, 0x3E, 0x3F, 0x3E, 0x3C,
0x38, 0x30, 0x20, 0x00, 0x15, 0x2A, 0x15, 0x2A, 0x3F};


int   main(void){
       unsigned  char  i;
       LED_Init();
       LED_OnOff(0x2A);
       Delay(100000);
       while(1){
	for(i=0; i<18; i++){
		LED_OnOff(LED_Pattern[i]);
		Delay(100000);
              }
      }
      return   0;
}
