#ifndef _DELAY_H_
#define _DELAY_H_
#include <stdint.h>

void LCD_HW_Init(void);          //hardware 관련 초기화
void LCD_SW_Init(void);          //software 관련 초기화
void LCD_Pulse_Enable(void);     //전달 시키는 명령함수
void LCD_Command(uint8_t cmd);   //명령 데이터
void LCD_Data(char Data);        //디스플레이 데이터 셋팅
void LCD_Char_xy(char x, char y);//디스플레이할 위치: 윗줄, 아래줄, 몇째칸
void LCD_String(char x, char y, char *str); //문자열을 디스플레이

#endif
