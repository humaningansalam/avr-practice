#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

const  uint8_t  FND_Font[10]  = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};   
const  uint8_t  FND_Common[4] = {0x10, 0x08, 0x02, 0x01};
const  uint8_t  FND_Dot[2] = {0x80, 0x00};
         uint8_t   FND_Buffer[4] = {0xFF, 0xFF, 0xFF, 0xFF};

void     FND_Init(void)
{
           DDRD     |=   0xFF;
           DDRG     |=   0x1B;
           TCCR2     =   0x0D; //분주비, CTC mode, 내부 타이머, TCNT2(0-255)
           OCR2      =   38;     //TCNT2(0-255)
           TIMSK    |=   (1<<OCIE2);
}
void     FND_On(uint8_t Num, uint8_t Digit, uint8_t Dot)
{
           PORTD  =  (FND_Font[Num]  &  0x7F)  |  FND_Dot[Dot];
           PORTG  =  (PORTG               &   0xE4)  |  FND_Common[Digit];
}
ISR(TIMER2_COMP_vect)
{
          static  uint8_t  Digit   =  0;
          Digit++;
          Digit    %=   4;
          PORTD   =   FND_Buffer[Digit];
          PORTG   =   (PORTG  &   0xE4)  |  FND_Common[Digit];
}
void     FND_Write(uint8_t Num, uint8_t Digit, uint8_t Dot)
{
           if(Dot)  FND_Buffer[Digit]  =  FND_Font[Num]  &  0x7F;
           else      FND_Buffer[Digit]  =  FND_Font[Num];
}
