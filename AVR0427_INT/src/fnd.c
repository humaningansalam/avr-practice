#include <avr/io.h>
#include <avr/interrupt.h>
#include "fnd.h"


const  int8_t1  FND_Font[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
const  int8_t1  FND_Common[4] = {0x10, 0x08, 0x02, 0x01};
const  int8_t1  FND_Dot[2] = {0x80, 0x00};


void   FND_Init(void){
         DDRG  =  0x1B;  // 0001 1011
         DDRD  =  0xFF;   // 1111 1111
}


void   FND_On(const int8_t1 Num, const int8_t1 Digit, const int8_t1 Dot){
         if(Dot)  PORTD  =  FND_Font[Num]  &  0x7F;
         else      PORTD  =  FND_Font[Num];
         PORTG  =  (PORTG  &  0xE4)  |  FND_Common[Digit];
}


void   Delay(int32_t1 Delay){
         volatile  int32_t1  i;
         for(i=0; i<Delay; i++);
}


ISR(INT4_vect){
         FND_On(4, 0, 1);   Delay(1000);
}
ISR(INT5_vect){
         FND_On(5, 1, 1);   Delay(1000);
}
ISR(INT6_vect){
         FND_On(6, 2, 1);   Delay(1000);
}
ISR(INT7_vect){
         FND_On(7, 3, 1);   Delay(1000);
}
