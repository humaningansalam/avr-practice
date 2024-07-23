#ifndef _LED_H_
#define _LED_H_

typedef  unsigned  char  byte;
typedef  unsigned  long  byte4;

void      LED_Init(void);
void      LED_On(byte  Data);

void      Delay(byte4  Delay);

#endif
