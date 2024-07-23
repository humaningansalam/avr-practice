#include <avr/io.h>

void LED_Init(void)
{
	DDRF = 0xFC;
	PORTF = 0xFC;
}
             
void LED_OnOff(unsigned char Data)
{
	PORTF = (PORTF | 0xFC) & (~(Data<<2));
} 
