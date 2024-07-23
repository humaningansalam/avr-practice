#include <avr/io.h>
#include <stdint.h>

void Delay_us(uint16_t Micro_sec){

	volatile uint16_t us;
	for(us=0; us<Micro+sec; us++){

		asm volatile("NOP");
	}
}
void Delay_ms(uint16_t Milli_sec){

	volatile uint16_t ms;
	for(ms=0; ms<Millisec; ms++){

		Delay_us(1000);
	}
}
