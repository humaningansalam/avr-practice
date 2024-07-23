#include <avr/io.h>
#include <avr/interrupt.h>
#include  "uart.h"

byte     UART_Buffer;
byte     UART_Flag      =   0;


void UART_Init(void){

	UCSR0A = 0x00; // 00(1)0 0000  ---->  UDRE0(��ü���� ����ִ� --> 1)
	UCSR0B = 0x98; // 1001 1000    ---->  �����Ҷ� ���ͷ�Ʈ�� Ȱ���ϰڴ� �ۼ����� ����ϰڴ�.
	UCSR0C = 0x06; // 0000 0110    ----> ������ �ۼ����� 8��Ʈ�� Ȱ���ϰڴ�.
	
	UBRR0H = 0;
	UBRR0L = 12;   // ����� ����  ----> (8000000 / (16*38400)) - 1 = 12
}

void UART_PutChar(byte Data){
                                    //  ??(1/0)? ????
	while((UCSR0A & 0x20) == 0);    //  0010     0000 &
	                                //  00(0/1)0 0000
	UDR0 = Data;

}

void      UART_PutString(const char  *String)        // const char  *String = "korea"(null)
{
            while(*String){
                 UART_PutChar(*String);
                 String++;
           }
}

ISR(USART0_RX_vect){
            UART_Buffer  =  UDR0;
            UART_Flag     =  1;
}

byte      UART_GetChar(byte  *Data)
{
            if(UART_Flag){
                 *Data         =  UART_Buffer;
                 UART_Flag  =  0;
                 return   1;
            }else{
                 return   0;
            }
}

