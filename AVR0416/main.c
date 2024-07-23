#include  <avr/io.h>
void  LED_Init(void);
void  LED_OnOff(unsigned  char  Data);
void  Delay(unsigned  long  Delay);
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
void  LED_Init(void)
{       DDRF   =  0xFC;    // 1111  1100
        PORTF  =  0xFC;   // 1111  1100
}
void  LED_OnOff(unsigned  char  Data)
{
        PORTF  =  (PORTF  |  0xFC)  &  (~(Data<<2) ); //~ : ƿƮ( ~1010 -->0101 )
}                                                                          //��Ʈ ����(~)���Ѷ�.
void  Delay(unsigned  long  Delay)
{       volatile  unsigned  long  i;                             // volatile --> ����ȭ��Ű�� ����� ��.
        for(i=0; i<Delay; i++);                                   //�ᱹ : �ð� �����ϴ� ��. = MCU=CPU = clock�ٷ��.
}
