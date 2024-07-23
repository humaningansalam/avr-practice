#ifndef     _KEYPAD_H_
#define    _KEYPAD_H_
#include  <stdint.h>

void        KEYPAD_Init(void);
uint8_t    KEYPAD_GetKey(uint8_t  *key);

#endif
