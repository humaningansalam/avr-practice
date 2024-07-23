#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "uart.h"

const uint8_t Test[12] = {0x30, 0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x0D ,0x0A};
//                         '0'  '1'   '2'  '3'  '4'  '5'  '6'  '7'  '8'  '9'  '\r'  '\n'  <==ASCII


void TIMER_init(void);

int main(void){

	UART_Init();
	TIMER_Init();
	UART_PutString("\r\n\r\n--- 안녕!! --- \r\n\r\n");

	sei();    //Global interrupt enable -->  인터럽트 사용이 여러개 동시에 이루어지는데 그것을 사용하게 하라

	while(1);

	return 0;
}

void TIMER_Init(void){

	TCCR2 = 0x0D;	
	OCR2 = 38;
	TIMSK |= (1<OCIE2);	
}

ISR(TIMER2_COMP_vect)   //5msec
{
        static  uint8_t  Count         =   0;
        static  uint8_t  Count_1sec  =  0;

        Count++;
        if(Count == 200){  //5m * 200 = 1000msec = 1000 * 0.001 = 1sec
               UDR0  = Test[Count_1sec];
               if(Count_1sec == 12)  Count_1sec  =  0;
               Count_1sec++;
               Count   =     0; 
        }

}
