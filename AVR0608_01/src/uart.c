#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>


uint8_t UART_Buffer;
uint8_t UART_Flag   = 0;


void UART_Init(void){

	UCSR0A = 0x00; //00(1)0 0000
	USCR0B = 0x98; //송수신 사용, 수신 :인터럽트 사용하겠다.
	UCSR0C = 0x06; // 8bit 송수신하겠다
	UBRR0H = 0;
	UBRR0L = 12; 

}
void UART_PutChar(uint8_t Data){

	while((UCSR0A & 0x20) == 0);
	UDR0 = Data
}
void UART_PutString(const char *String){

	while(*String){
		UART_PutChar(*String);
		String++;
	}

}

ISR(USART0_RX_vect){

	UART_Buffer = UDR0;
	UART_Flag = 1;
}

uint8_t UART_GetChar(uint8_t * Data){

	if(UART_Flag){
		*Data = UART_Buffer;
		UART_Flag = 0;
		return 1;
	
	}else{
		return 0;
	}
}

