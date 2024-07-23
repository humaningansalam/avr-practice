#ifndef _ADC_H_
#define _ADC_H_
#include <stdint.h>


void ADC_Init(void);
void ADC_Start(uint8_t Channel);
uint8_t ADC_GetData(uint8_t Channel, uint16_t *ADC_Value);


#endif
