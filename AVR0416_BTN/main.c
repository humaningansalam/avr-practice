#include <avr/io.h>
#include <util/delay.h>

void LED_Init(void)
{
	DDRF =  0xFC;
	PORTF = 0xFC;
}

void BUTTON_Init(void)
{
	DDRE = 0x0F;
	PORTE = 0xF0;
}

int main(void)
{
	LED_Init();
	BUTTON_Init();

	while(1){
		_delay_ms(40); //1000ms = 1sec, 40ms = 0.04sec
		PORTF = PINE;  //PORTF.4567 <--- PORTE : PINE.4567
	
	}
	return 0;
}
