#include <avr/io.h>

void KEY_Init(void)
{
	DDRE = 0x0F;  //�Է¿�-��¿�
    PORTE = 0xF0; //1111(�Է�5V) 0000(���0V)
}

unsigned char KEY_Read(void)
{
  return ~(PINE >> 4);
}
