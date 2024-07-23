#ifndef _UART_H_
#define _UART_H_
#include <stdint.h>

void TIMER_Init(void);
void TIMER_Start1(void);
void TIMER_Start2(void);
void TIMER_stop(void);
void TIMER_Reset(void);
uint16_t TIMER_GetTime1(void);
uint8_t TIMER_GetTime2(void);

#endif
