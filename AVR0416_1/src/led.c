#include  <avr/io.h>

void  LED_Init(void)
{       DDRF   =  0xFC;    // 1111  1100
        PORTF  =  0xFC;   // 1111  1100
}

void  LED_OnOff(unsigned  char  Data)
{
        PORTF  =  (PORTF  |  0xFC)  &  (~(Data<<2) ); //~ : ƿƮ( ~1010 -->0101 )
}      
                                                                    //��Ʈ ����(~)���Ѷ�.
void  Delay(unsigned  long  Delay)
{       volatile  unsigned  long  i;                             // volatile --> ����ȭ��Ű�� ����� ��.
        for(i=0; i<Delay; i++);                                   //�ᱹ : �ð� �����ϴ� ��. = MCU=CPU = clock�ٷ��.
}
