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
        PORTF  =  (PORTF  |  0xFC)  &  (~(Data<<2) ); //~ : 틸트( ~1010 -->0101 )
}                                                                          //비트 반전(~)시켜라.
void  Delay(unsigned  long  Delay)
{       volatile  unsigned  long  i;                             // volatile --> 최적화시키지 말라는 뜻.
        for(i=0; i<Delay; i++);                                   //결국 : 시간 지연하는 것. = MCU=CPU = clock다룬다.
}
