#ifndef     _TIMER_H_
#define    _TIMER_H_
#include  <stdint.h>

void        TIMER_Init(void);
void        TIMER_Start(void);
void        TIMER_Stop(void);
void        TIMER_Reset(void);
uint16_t   TIMER_GetTime(void);

#endif
