
#ifndef _LED_H_
#define _LED_H_

void LED_Init(void){
{        
         DDRF  =  0xFC;
         PORTF =  0xFC;    
}

}
//void LED_OnOff(void);


#endif

