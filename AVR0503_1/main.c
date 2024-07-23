#include  <avr/io.h>
#include  <avr/interrupt.h>
#include  "uart.h"

void   UART_Control(void);
int     main(void)
{
        UART_Init();     
        UART_PutChar('A'); UART_PutChar('V'); UART_PutChar('R'); 
        UART_PutChar('\r'); UART_PutChar('\n'); 
        UART_PutString("===================\r\n");
        UART_PutString("ATmega128 Test Programming\r\n");
        UART_PutString("ATmega128 -- Welcome!!\r\n");
        UART_PutString("===================\r\n");
        sei();    //SREG.7  =  1;
        while(1){
           UART_Control();
        }
        return  0;
}
void   UART_Control(void){
        byte  Data;
        if(UART_GetChar(&Data) == 0)   return;
        UART_PutChar(Data);
}
