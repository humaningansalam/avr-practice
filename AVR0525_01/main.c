#include  <avr/io.h>
#include  <avr/interrupt.h>
#include  <stdint.h>

/*
#include  "buzzer.h"
#include  "fnd.h"
#include  "led.h"
#include  "timer.h"
#include  "uart.h"
*/
void        Init(void);
void        Delay(uint32_t  Delay);
void        UART_Control(void);

int          main(void)
{
              Init();
              LED_On(0x2A);
              FND_On(9, 0, 0);  Delay(100000);  FND_On(8, 1, 0);  Delay(100000);  
              FND_On(7, 2, 0);  Delay(100000);  FND_On(6, 3, 0);  Delay(100000);  
              UART_PutChar('\r');  UART_PutChar('\n');  
              UART_PutChar('H');  UART_PutChar('e'); UART_PutChar('l');  UART_PutChar('l'); UART_PutChar('o');
              UART_PutChar('\r');  UART_PutChar('\n');  
              UART_PutString("\r\n ~~~~ ATmege128 Timer1 Excution Test ~~~~ \r\n");
              BUZZER_On(1);  Delay(100000); BUZZER_On(0);  
              sei();
              while(1){
                     UART_Control();
              }
              return 0;
}
void        Init(void)
{
              BUZZER_Init();
              FND_Init();
              LED_Init();
              TIMER_Init();
              UART_Init();
}
void        Delay(uint32_t  Delay)
{
              volatile  uint32_t  i;
              for(i=0; i<Delay;  i++);
}
void        UART_Control(void)
{
              uint8_t  Data;
              if(UART_GetChar(&Data)  == 0)   return;
              UART_PutChar(Data);
}

