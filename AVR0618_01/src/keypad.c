#include  <avr/io.h>
#include  <avr/interrupt.h>
#include  <stdint.h>

uint8_t      Row_Pattern[4]  =  {0x0E, 0x0D, 0x0B, 0x07};
uint8_t      KEYPAD_Value;
uint8_t      KEYPAD_Flag    =   0;
static  uint8_t  Row           =   0;

void        KEYPAD_Init(void)
{
              DDRE    &=    0x0F;     PORTE   |=     0xF0;
              DDRE      |=    0x0F;     PORTE  &=    0xF0;
              EICRB       =   0xAA;     EIMSK    =     0xF0;
              TCCR0      =   0x0F;
              OCR0       =   0xF9;
              TIMSK     |=   (1<<OCIE0);  //분주비, (CTC)mode, 내부타이머(TCNT0), 비교일치
}
ISR(TIMER0_COMP_vect)   //30msec
{           
             Row++;
             Row      %=    4;
             PORTE     =    (PORTE  &  0xF0)   |   Row_Pattern[Row];
}
ISR(INT4_vect)
{
            KEYPAD_Value   =   Row  +  12;
            KEYPAD_Flag     =   1;
}
ISR(INT5_vect)
{
            KEYPAD_Value   =   Row  +  8;
            KEYPAD_Flag     =   1;
}
ISR(INT6_vect)
{
            KEYPAD_Value   =   Row  +  4;
            KEYPAD_Flag     =   1;
}
ISR(INT7_vect)
{
            KEYPAD_Value   =   Row  +  0;
            KEYPAD_Flag     =   1;
}
uint8_t    KEYPAD_GetKey(uint8_t  *key)
{
            if(KEYPAD_Flag){
                *key               =  KEYPAD_Value;
                KEYPAD_Flag  =   0;
                return                 1;
            }else{
                return                 0;
           }
}
