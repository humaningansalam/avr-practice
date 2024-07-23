#include <avr/io.h>

void FND_Init(void)
{
	DDRG = 0b00011011;  //0x1B <== FND 자리수 결정(출력용 방향)
	DDRD = 0b11111111;  //0xFF <== FND 값 결정(출력용 방향)
	PORTG = 0b11100100; //0xE4 <== 초기값 제공
	PORTD = 0b11111111; //0xFF <== 초기값 제공

}

void Delay(unsigned long Delay)
{
  volatile unsigned long i;
  for(i=0; i<Delay; i++);
}

int main(void)
{
	FND_Init();
	PORTG = 0x10; //1의 자리만 선택 :출력은 1의 자리만 출력됨
	PORTD = 0xC0; Delay(100000);
	PORTD = 0xF9; Delay(100000);
	PORTD = 0xA4; Delay(100000);
	PORTD = 0xB0; Delay(100000);
	PORTD = 0x99; Delay(100000);
	PORTD = 0x92; Delay(100000);

	while(1);

	return 0;
}
