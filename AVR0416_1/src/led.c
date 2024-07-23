#include  <avr/io.h>

void  LED_Init(void)
{       DDRF   =  0xFC;    // 1111  1100
        PORTF  =  0xFC;   // 1111  1100
}

void  LED_OnOff(unsigned  char  Data)
{
        PORTF  =  (PORTF  |  0xFC)  &  (~(Data<<2) ); //~ : 틸트( ~1010 -->0101 )
}      
                                                                    //비트 반전(~)시켜라.
void  Delay(unsigned  long  Delay)
{       volatile  unsigned  long  i;                             // volatile --> 최적화시키지 말라는 뜻.
        for(i=0; i<Delay; i++);                                   //결국 : 시간 지연하는 것. = MCU=CPU = clock다룬다.
}
