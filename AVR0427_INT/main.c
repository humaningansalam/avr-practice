#include <avr/io.h>
#include <avr/interrupt.h>

#include "fnd.h"
#include "key.h"

void Init(void);

int main(void){

	Init();
    sei();       // 인터럽트를 가동(인가)해주세요.
    while(1); //  ---> while(1); 이렇게도 작성한다.

	return 0;
}

void   Init(void){
         FND_Init();
         KEY_Init();
}
