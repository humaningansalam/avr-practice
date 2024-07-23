#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

uint16_t ADC_Buffer[2]; // adc0, adc1
uint8_t ADC_Flag[2] = {0,0};

void ADC_Init(void){

	ADMUX = 0x00;    //00/0/0 0000
	ADCSRA = 0x8B;   //1/0/0/0 /1/011

void ADC_Start(uint8_t Channel){

	while(ADCSRA & (1<<ADCS));
	ADMUX = (ADMUX & 0xE0) | Channel;
	ADCSRA |= (1<<ADCS);
}

ISR(ADC_vect){

	uint8_t Channel;
	Channel = ADMUX & 0x1F;

	ADC_Buffer[Channel] = ADCL + (uint16_t)ADCH<<8; 
    ADC_Flag[Channel]         = 1

}

uint8_t ADC_GetData(uint8_t Channel, uint16_t *ADC_Value){

	if(ADC_Flag[Channel]){
		*ADC_Value = ADC_Buffer[Channel];
		ADC_Falg[Channel] = 0;
		return 1;
	}else{

		return 0;
	}
}


