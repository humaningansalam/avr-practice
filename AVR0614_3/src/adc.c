#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>




void ADC_Init(uint8_t Channel){

	ADMUX |= (1<<REFS0);
	ADMUX |= ((ADMUX |= 0xE0) | Channel);
	ADCSRA |= 0x03;
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADFR);
	ADCSRA |= (1<<	
}
uint16_t ADC_Read(void){

	while(ADCSRA & ( 1<<ADIF)) == 0);  //������� <ADC Read --> ing/end
	ADCSRA |= (1<<ADIF);               //�ϵ���� Ŭ����
	return ADCW;                       //5V --> 10bit, 3.3V --> 12bit

}
uint16_t ADC_GetData(uint8_t Channel, uint16_t *ADC_Value){


}
void ADC_Start(uint8_t Channel){

	while(ADCSRA & (1<<ADSC);  //ADC�� �а� �ִ���? �ϰ��ִ� ���̸� 1
	ADMUX = (ADMUX & 0xE0) | Channel;
	ADCSRA |= ( 1<<ADSC);
}
