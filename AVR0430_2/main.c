#include  <avr/io.h>
#include  <avr/interrupt.h>

typedef   unsigned  long  byte4;
typedef   unsigned  char  byte;

void        Delay(byte4  Delay);

void        Init(void);
void        LED_Init(void);
void        KEY_Init(void);
void        BUZZER_Init(void);

void        LED_On(byte  Data);
byte        KEY_Read(void);
void        BUZZER_On(byte OnOff);

int          main(void)
{
             Init();

}
void        Delay(byte4  Delay)
{
              volatile  byte4  i;
              for(i=0; i<Delay; i++);
}
void        Init(void)
{
              LED_Init();
              KEY_Init();
              BUZZER_Init();
}
void        LED_Init(void)
{
              DDRF  |=  0xFC;
}
void        KEY_Init(void)
{
              DDRE  &=  0x0F;    PORTE  |=  0xF0;
              DDRE   |=   0x0F;    PORTE  &=0xF0;
              EICRB    =   0xAA;   EIMSK   =  0xF0;
}
void        BUZZER_Init(void)
{
              DDRB    |=  0x01;
              PORTB &=  0x00;
}
void        LED_On(byte  Data)
{
              PORTF =  (PORTF |  0xFC)  & (~(Data<<2) );
}
byte        KEY_Read(void)
{
              return  ~(PINE >> 4)  &  0x0F;
}
void        BUZZER_On(byte OnOff)
{
              if(OnOff == 1)  PORTB  |=   OnOff;
              if(OnOff == 0)  PORTB  &=  OnOff;
}
ISR(INT4_vect)
{
             LED_On(1<<0);
             BUZZER_On(0x01);  Delay(10000);  BUZZER_On(0x00);
}
ISR(INT5_vect)
{
             LED_On(1<<1);
             BUZZER_On(0x01);  Delay(10000);  BUZZER_On(0x00);
}
ISR(INT6_vect)
{
             LED_On(1<<2);
             BUZZER_On(0x01);  Delay(10000);  BUZZER_On(0x00);
}
ISR(INT7_vect)
{
             LED_On(1<<3);
             BUZZER_On(0x01);  Delay(10000);  BUZZER_On(0x00);
}

