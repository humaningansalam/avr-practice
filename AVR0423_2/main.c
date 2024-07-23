#include <avr/io.h>

#include "led.h"
#include "key.h"

void Init(void);
int main(void)
{
	unsigned char KEYValue;
	Init();

	while(1){
	KEYValue = KEY_Read();
	LED_OnOff(KEYValue);
	}

	return 0;

}

void Init(void)
{
	LED_Init();
	KEY_Init();
}
