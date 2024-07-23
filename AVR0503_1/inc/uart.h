#ifndef _UART_H_
#define _UART_H_

typedef unsigned char byte;

void UART_Init(void);
void UART_PutChar(byte Data);
void UART_PutString(const char *String);
byte UART_GetChar(byte *Data);

#endif
