#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>


uint16_t Value;
uint8_t adc[];

void Init(void);
void Delay(uint32_ Delay;
void ADC_Process(void);

int main(void){

	Init();
	sei();
	while(1){
		ADC_Process();
		
	}

	return 0;
}



void Init(void){

	 UART_Init();
	 ADC_Init();

}
void Delay(uint32_ Delay{

	volatile uint32_t i;
	for(i=0;<Delay;i++);
}

void ADC_Process(void){

	uint16_t ADC_Value;
	ADC_Start(0);

	while(ADC_GetData(0, &ADC_Value) == 0);

	while(ADCSRA & (1<<ADSC));  //<-- 하드웨어 적으로 초기화

	Value = ADC_Value;
	sprintf(adc, "%d", Value);  //65432
}
