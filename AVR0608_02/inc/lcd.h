#ifndef _DELAY_H_
#define _DELAY_H_
#include <stdint.h>

void LCD_HW_Init(void);          //hardware ���� �ʱ�ȭ
void LCD_SW_Init(void);          //software ���� �ʱ�ȭ
void LCD_Pulse_Enable(void);     //���� ��Ű�� ����Լ�
void LCD_Command(uint8_t cmd);   //��� ������
void LCD_Data(char Data);        //���÷��� ������ ����
void LCD_Char_xy(char x, char y);//���÷����� ��ġ: ����, �Ʒ���, ��°ĭ
void LCD_String(char x, char y, char *str); //���ڿ��� ���÷���

#endif
