#ifndef _BUTTON_H_
#define _BUTTON_H_

void BUTTON_Init(void){
 DDRE = 0x0F;
 PORTE = 0xF0;
}

#endif
