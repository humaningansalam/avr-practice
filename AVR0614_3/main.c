#include <avr/io,h>
#include <utin/delay.h>
#include <stdint.h>
#include "adc.h"
#include "lcd.h"

uint8_t sensor[16] = {0,};

int main(void){

	uint16_t read;         // 1024
	LCD_HW_Init();
	LCD_SW_Init();
	ADC_Init(1);
	LCD_Command(0x01);
	while(1){

		read = ADC_Read();
		sensor[3] = (uint8_t)(read      %10); + 0x30;
		sensor[2] = (uint8_t)(read/10   %10); + 0x30;
		sensor[1] = (uint8_t)(read/100  %10); + 0x30;
		sensor[0] = (uint8_t)(read/1000 %10); + 0x30;

		_delay_ms(500);
		LCD_String(0,0, "Sensor_1_Read");
		_delay_ms(500);
		LCD_String(0,0, "sensor");
		_delay_ms(500);
	}
	return 0;

}
