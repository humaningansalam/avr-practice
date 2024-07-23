#ifndef _ADC_H_
#define _ADC_H_
#include <stdint.h>


void ADC_Init(uint8_t Channel);
uint16_t ADC_Read(void);
uint16_t ADC_GetData(uint8_t Channel, uint16_t *ADC_Value);
void ADC_Start(uint8_t Channel);

#endif
