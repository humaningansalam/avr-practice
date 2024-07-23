#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


void UART_Init(void)
{
	UCSR0A = 0x00;
	UCSR0B = 0x98;
	UCSR0C = 0x06;
	UBRR0H = 0;
	UBRR0L = 12;
}

void UART_PutChar(uint8_t Data){

	while((UCSR0A & 0x20) == 0);
	UDR0 = Data;
}

void UART_PutString( const char *String){
	
	while(*String){
		UART_PutChar(*String);
		String++;
	}
}
