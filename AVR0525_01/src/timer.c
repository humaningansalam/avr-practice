#include  <avr/io.h>
#include  <avr/interrupt.h>
#include  <stdint.h>

uint16_t  TIMER_100ms   =   0;   // Timer/Count0 --> 8bit T/C(TCNT0 : 0,1,2,3,4,--,255), OCR0(비교일치레지스터)
uint8_t    TIMER_Flag      =   0;   // Timer/Count2 --> 8bit T/C(TCNT2 : 0,1,2,3,4,--,255), OCR2(비교일치레지스터)
                                               // Timer/Count1 --> 16bit T/C(TCNT1AH, TCNT1AL,  : 0,1,2,3,4,--,65535)
                                               // OCR1AH  +  OCR1AL(비교일치레지스터) : 0 ~ 65535값을 결정함.
                                               // Timer/Count3 --> 16bit T/C(TCNT3AH, TCNT3AL : 0,1,2,3,4,--,65535)
                                               // OCR3AH  +  OCR3AL(비교일치레지스터) : 0 ~ 65535값을 결정함.
void       TIMER_Init(void)
{                                         // hgfe  dcba                              mlba
             TCCR1A    =  0x00;  // 0000 0000  :  1) : CTC Mode -> 0100
                                          //                                        kj i
                                          // ponm l kj i    2) : 분주비 ->100 -> 256분주
             TCCR1B    =  0x0C;  // 0000  1100    3) : 원하는 시간(○), 출력 바깥으로 보낼 것인지(x) 선택 
                                          //                           00 00  00
                                          //                           hg fe   dc
                                          //                            A  B    C
                                          //                            ○ x     x
                                          //                      4)원하는시간 = T = 1/f = (1/8000000) * 256 * 3125  = (1/8*10^6) * 8*10^5 =0.1sec
                                          //                                                       = 100msec 
             OCR1AH   =  0x0C;    
             OCR1AL    =  0x35;  // OCR1A  = OCR1AH + OCR1AL = 0x0C35 = 0b0000110000110101 = 3125 비교일치값

             TIMSK      |=  (1<<OCIE1A);  // 0001 0000, TCNT1A = OCR1A --> 인터럽트서비스루틴가라.(명령)
}
ISR(TIMER1_COMPA_vect)  //0.1 = 100msec
{
       static  uint16_t  Count  =  0;
       Count++;
       FND_Write(Count          %  10, 0,  0);    //1의 자리값
       FND_Write(Count/10     %  10, 1,  0);    //10의 자리값
       FND_Write(Count/100    %  10, 2,  0);    //100의 자리값
       FND_Write(Count/1000  %  10, 3,  0);    //1000의 자리값
}
void       TIMER_Start(void);
void       TIMER_Stop(void);
void       TIMER_Reset(void);
uint16_t  TIMER_GetTime(void);  // 값 : 0 - 65535기억시킬 수 있다.(65536개)
