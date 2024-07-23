#include <avr/io.h>

void KEY_Init(void)
{
	DDRE = 0x0F;  //입력용-출력용
    PORTE = 0xF0; //1111(입력5V) 0000(출력0V)
}

unsigned char KEY_Read(void)
{
  return ~(PINE >> 4);
}
