#ifndef _UART_H_
#define _UART_H_
#include <stdint.h>

void UART_Init(void);
void UART_PutChar(uint8_t Data);
void UART_PutString(const char *String);
uint8_t UART_GetChar(uint8_t Data);

#endif
