#include  <avr/io.h>
#include  <util/delay.h>
#include  <stdint.h>

void      LCD_HW_Init(void)
{                    //RW,RS                            EN                       Data(상위4비트만사용 - 명령, 출력)
            DDRA   =   0xC0;     DDRG   =  0x04;    DDRC   =   0xF0;
            PORTA  =   0x00;     PORTG =  0x00;    PORTC  =   0x00;            
}

void      LCD_SW_Init(void)
{
            _delay_ms(50);
            LCD_Command(0x20);  _delay_ms(1);
            LCD_Command(0x28);  _delay_ms(1);
            LCD_Command(0x0C);  _delay_ms(1);
            LCD_Command(0x06);  _delay_ms(1);
            LCD_Command(0x01);  _delay_ms(1);
            _delay_ms(50);
}

void      LCD_Pulse_Enable(void)
{
            PORTG  =  0x04;  _delay_ms(1);
            PORTG  =  0x00;  _delay_ms(1);
}
void      LCD_Command(uint8_t  cmd)
{
            PORTA  =  0x00;    PORTC  =  (cmd          &  0xF0);    LCD_Pulse_Enable();
            PORTA  =  0x00;    PORTC  =  ((cmd<<4)  &  0xF0);    LCD_Pulse_Enable();
            _delay_ms(5);
}
void      LCD_Data(char  data)
{
            PORTA  =  0x40;    PORTC  =  (data          &  0xF0);    LCD_Pulse_Enable();
            PORTA  =  0x40;    PORTC  =  ((data<<4)  &  0xF0);    LCD_Pulse_Enable();
            _delay_ms(5);
}
void      LCD_Char_xy(char   x,  char  y)
{
            uint8_t  pos;
            pos   =   y  ?  ( 0xC0  +  x)   :  (0x80  +  x);
            LCD_Command(pos);
}
void      LCD_String(char  x, char y, char *String)
{
            LCD_Char_xy(x,   y);
            while(*String){
                 LCD_Data(*String++);
                 _delay_ms(1);
            }
}
void      LCD_Scroll(char  Direction)
{
            uint8_t   shift  =  0;                        // 0000 0110
            if(Direction == 1)   shift  =  0x1C;   // 0001 1100
            if(Direction == 0)   shift  =  0x18;   // 0001 1000
            LCD_Command(shift);
}
