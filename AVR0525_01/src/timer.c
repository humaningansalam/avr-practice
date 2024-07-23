#include  <avr/io.h>
#include  <avr/interrupt.h>
#include  <stdint.h>

uint16_t  TIMER_100ms   =   0;   // Timer/Count0 --> 8bit T/C(TCNT0 : 0,1,2,3,4,--,255), OCR0(����ġ��������)
uint8_t    TIMER_Flag      =   0;   // Timer/Count2 --> 8bit T/C(TCNT2 : 0,1,2,3,4,--,255), OCR2(����ġ��������)
                                               // Timer/Count1 --> 16bit T/C(TCNT1AH, TCNT1AL,  : 0,1,2,3,4,--,65535)
                                               // OCR1AH  +  OCR1AL(����ġ��������) : 0 ~ 65535���� ������.
                                               // Timer/Count3 --> 16bit T/C(TCNT3AH, TCNT3AL : 0,1,2,3,4,--,65535)
                                               // OCR3AH  +  OCR3AL(����ġ��������) : 0 ~ 65535���� ������.
void       TIMER_Init(void)
{                                         // hgfe  dcba                              mlba
             TCCR1A    =  0x00;  // 0000 0000  :  1) : CTC Mode -> 0100
                                          //                                        kj i
                                          // ponm l kj i    2) : ���ֺ� ->100 -> 256����
             TCCR1B    =  0x0C;  // 0000  1100    3) : ���ϴ� �ð�(��), ��� �ٱ����� ���� ������(x) ���� 
                                          //                           00 00  00
                                          //                           hg fe   dc
                                          //                            A  B    C
                                          //                            �� x     x
                                          //                      4)���ϴ½ð� = T = 1/f = (1/8000000) * 256 * 3125  = (1/8*10^6) * 8*10^5 =0.1sec
                                          //                                                       = 100msec 
             OCR1AH   =  0x0C;    
             OCR1AL    =  0x35;  // OCR1A  = OCR1AH + OCR1AL = 0x0C35 = 0b0000110000110101 = 3125 ����ġ��

             TIMSK      |=  (1<<OCIE1A);  // 0001 0000, TCNT1A = OCR1A --> ���ͷ�Ʈ���񽺷�ƾ����.(���)
}
ISR(TIMER1_COMPA_vect)  //0.1 = 100msec
{
       static  uint16_t  Count  =  0;
       Count++;
       FND_Write(Count          %  10, 0,  0);    //1�� �ڸ���
       FND_Write(Count/10     %  10, 1,  0);    //10�� �ڸ���
       FND_Write(Count/100    %  10, 2,  0);    //100�� �ڸ���
       FND_Write(Count/1000  %  10, 3,  0);    //1000�� �ڸ���
}
void       TIMER_Start(void);
void       TIMER_Stop(void);
void       TIMER_Reset(void);
uint16_t  TIMER_GetTime(void);  // �� : 0 - 65535����ų �� �ִ�.(65536��)
