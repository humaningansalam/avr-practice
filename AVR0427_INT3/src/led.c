#include <avr/io.h>

#include "led.h"

void      LED_Init(void){
            DDRF  =  0xFC;   // 1111 1100
            PORTF =  0xFC;  //  1111 1100
}
void      LED_On(byte  Data){                                 
            PORTF  =  (PORTF | 0xFC)  &  (~(Data<<2));
//                       ???? ???? | 1111 1100 --> 1111 11 ??              V
//         0x20                                            0010 0000
//                                                            1000 0000(<<2)
//                                                             0111 1111(~)        V
//                                                            0111 11?? -->        최종적인 값(0x20)
}//                                                           1011 11?? -->         0x30
 //                                                            1101 11??-->         0x38
 //                                                            1110 11??-->         0x3C

void      Delay(byte4  Delay){                          // 0  0   0   0  1   0  1   1  (>>)
            volatile  byte4 i;                                 // 1  1   1   1  0   1  0   0  (~)
            for(i=0; i<Delay; i++);                        //  0  0   0   0  1   1  1   1  (&)
}    



