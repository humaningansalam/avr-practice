#ifndef   _LCD_H_
#define  _LCD_H_
#include  <stdint.h>

void      LCD_HW_Init(void);
void      LCD_SW_Init(void);

void      LCD_Pulse_Enable(void);
void      LCD_Command(uint8_t  cmd);
void      LCD_Data(char  data);
void      LCD_Char_xy(char   x,  char  y);
void      LCD_String(char  x, char y, char *String);

void      LCD_Scroll(char  Direction);

#endif
