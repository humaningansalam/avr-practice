#include  <avr/io.h>
#include  <avr/interrupt.h>
#include  <stdint.h>

uint16_t   ADC_Buffer[2];
uint8_t    ADC_Flag[2]     =  {0, 0};

void        ADC_Init(void)
{
              ADMUX   =  0x00;   // 0000 0000, F.0_7, 저장방식, ADC_Reaad 기준전압
              ADCSRA  =  0x8B;   // 1000 1011, 준주비,int', FreeRunning
}
void        ADC_Start(uint8_t   Channel)
{
              while(ADCSRA  &  (1<<ADSC));
              ADMUX    =  (ADMUX  &  0xE0)  |  Channel;    
              ADCSRA   |=  (1<<ADSC);       
}
ISR(ADC_vect)
{
             uint8_t  Channel;
             Channel                    =   ADMUX  &  0x1F;
             ADC_Buffer[Channel]  =  ADCL  + ((uint16_t)ADCH<<8);
             ADC_Flag[Channel]     =  1;
}
uint8_t    ADC_GetData(uint8_t  Channel,  uint16_t  *ADC_Value)
{
             if(ADC_Flag[Channel]){
                    *ADC_Value               =   ADC_Buffer[Channel];
                    ADC_Flag[Channel]     =  0;
                    return     1;
             }
             else  return     0;
}
