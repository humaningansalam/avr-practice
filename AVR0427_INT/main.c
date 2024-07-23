#include <avr/io.h>
#include <avr/interrupt.h>

#include "fnd.h"
#include "key.h"

void Init(void);

int main(void){

	Init();
    sei();       // ���ͷ�Ʈ�� ����(�ΰ�)���ּ���.
    while(1); //  ---> while(1); �̷��Ե� �ۼ��Ѵ�.

	return 0;
}

void   Init(void){
         FND_Init();
         KEY_Init();
}
