#include <avr/io.h>
#include <avr/interrupt.h>


void   KEY_Init(void){
         DDRE  &=  0x0F;    // ???? ???? & 0000 1111 -->
         PORTE |=   0xF0;    // ???? ???? |   1111 0000 -->
         DDRE  |=    0x0F;   //  ???? ???? |   0000 1111 -->
         PORTE &=  0xF0;   //  ???? ???? &   1111 0000 -->
         EICRB   =    0xAA;  //   1010 1010 --> 
         EIMSK  =    0xF0;   //   1111 0000 --> E7, E6, E5, E4를 인터럽트 인지핀으로 사용하겠다.(입력용)
}
