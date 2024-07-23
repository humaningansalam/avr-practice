#include <avr/io.h>

void FND_Init(void)
{
	DDRG = 0b00011011;  //0x1B <== FND �ڸ��� ����(��¿� ����)
	DDRD = 0b11111111;  //0xFF <== FND �� ����(��¿� ����)
	PORTG = 0b11100100; //0xE4 <== �ʱⰪ ����
	PORTD = 0b11111111; //0xFF <== �ʱⰪ ����

}

void Delay(unsigned long Delay)
{
  volatile unsigned long i;
  for(i=0; i<Delay; i++);
}

int main(void)
{
	FND_Init();
	PORTG = 0x10; //1�� �ڸ��� ���� :����� 1�� �ڸ��� ��µ�
	PORTD = 0xC0; Delay(100000);
	PORTD = 0xF9; Delay(100000);
	PORTD = 0xA4; Delay(100000);
	PORTD = 0xB0; Delay(100000);
	PORTD = 0x99; Delay(100000);
	PORTD = 0x92; Delay(100000);

	while(1);

	return 0;
}
