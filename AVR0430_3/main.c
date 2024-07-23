// UART 관련 코딩
#include  <avr/io.h>
#include  <avr/interrupt.h>

typedef  unsigned  char  byte;

byte  UART_Buffer;
byte  UART_Flag     =   0;

void  UART_Init(void);
void  UART_PutChar(byte  Data);
void  UART_PutString(const char *String);
byte  UART_GetChar(byte  *Data);
void  UART_Control(void);

int    main(void)
{
       UART_Init();
       UART_PutChar('A');  UART_PutChar('V');  UART_PutChar('R');  UART_PutChar('\r');  UART_PutChar('\n');
       UART_PutString("===============");
       UART_PutString("\r\nATmega128 Test Programming");
       UART_PutString("\r\nWelcome!!");
       UART_PutString("\r\n===============\r\n");
       sei();
       while(1){
               UART_Control();
       }
       return  0;
}
void  UART_Init(void)
{                                        //1
        UCSR0A  =  0x00;  // 00(0)0 0000
        UCSR0B  =  0x98;  // 1001 1000
        UCSR0C  =  0x06;  // 0000 0110
        UBRR0H =  0;       //  (8000000 / 614400) -1 = 12
        UBRR0L  =  12;     //  보드 시스템클럭 : 8MHz, 38400bps통신, 614400=16x38400
}
void  UART_PutChar(byte  Data)       //아스키코드 --> 1문자이다. Uart는 결국 아스키코드값을 통신한거다.
{                                                    // Data = 'k'   --> 'o'              
       while((UCSR0A & 0x20) == 0);   // 0000 0000   ---> 만약 참이면 --> 우체통에 편지가 남아있는 거다.
       UDR0  =  Data;                        // 0010 0000  &  ---> 1 == 0 상태 --> false(우체통이 비어있다.)
}
void  UART_PutString(const char *String)  //const char *String = "korea"
{
        while(*String){                                //포인터변수 기능 4가지  --> 1. 주소를 기억시킨다. (int* ptr = &a;)
            UART_PutChar(*String);               //                                       2. 값 -- 읽기 기능  ( *String )       
            String++;                                   //                                       3. 값 -- 저장 기능  ( *String = *ptr;)
        }                                                   //                                       4.  주소 -- 읽기/저장/증가/감소( ptr =  string)
}
byte  UART_GetChar(byte  *Data)
{
        if(UART_Flag){
           *Data         =  UART_Buffer;
           UART_Flag  =  0;
          return  1;
       }else{
          return  0;
       }
}
ISR(USART0_RX_vect)
{
     UART_Buffer  =  UDR0;
     UART_Flag     =  1;
}
void  UART_Control(void)
{
        byte  Data;
        if(UART_GetChar(&Data) == 0)  return;
        UART_PutChar(Data);
}

