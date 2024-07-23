#include <avr/io.h>
#include <stdint.h>


void Init(void);


int main(void){

	Init();
	LCD_String(0,0, "Hello World!!~~");
	LCD_String(0,0, "LCD Display Welcome Test!");


	return 0;
}


void Init(void){


	LCD_HW_Init();
	LCD_SW_Init();
}
