#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"

void      KEY_Init(void){
            DDRE  &=  0x0F;    PORTE  |=  0xF0;   //상위비트E.7654 --> 입력용, 초기값1
            DDRE  |=    0x0F;    PORTE  &=0xF0;   //하위비트E.3210 --> 출력용, 초기값0
            EICRB   =  0xAA;                                //1010 1010 --> E.7654 --> 버튼을 누를 때 인터럽트서비스루틴으로 가라.
            EIMSK   =  0xF0;                                // 1111 0000 --> E.7654 --> 인터럽트 인식핀으로 사용하겠다.
}
byte      KEY_Read(void){                                //E7 E6 E5 E4 E3 E2 E1 E0
            return  ~(PINE>>4) &  0x0F;              // 1  1   1   1  x   x   x   x
}                                                                  // 1  0   1   1  x   x   x   x
                                                                  // 0  0   0   0   0  1  0   0 (return시킬 값)
ISR(INT4_vect){
            LED_On(0x20);  Delay(1000);
}
ISR(INT5_vect){
             LED_On(0x30);  Delay(1000);
}
ISR(INT6_vect){
             LED_On(0x38);  Delay(1000);
}
ISR(INT7_vect){
              LED_On(0x3C);  Delay(1000);
}


