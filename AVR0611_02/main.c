#include  <avr/io.h>
#include  <util/delay.h>
#include  <stdint.h>


uint8_t  LCD_Hangle_Font[48]  =  {
 0x0A, 0x1E, 0x0A, 0x17, 0x16, 0x0A, 0x10, 0x1E,  // DDRAM data_0,1,2,3,4,5,6
 0x1E, 0x02, 0x02, 0x1F, 0x04, 0x1E, 0x02, 0x02,

 0x02, 0x0A, 0x16, 0x16, 0x16, 0x0A, 0x10, 0x1E,
 0x04, 0x0A, 0x0A, 0x04, 0x00, 0x1F, 0x04, 0x04,

 0x09, 0x17, 0x15, 0x17, 0x09, 0x06, 0x09, 0x06,
 0x05, 0x0D, 0x17, 0x15, 0x01, 0x06, 0x09, 0x06 };  // '한', '국', 인' <--한글 끌꼴 만들기, CGRAM data, 철, 핳

/*
// 0x0A, 0x1E, 0x0A, 0x17, 0x16, 0x0A, 0x10, 0x1E
00001010
00011110
00001010
00010111
00010110
00001010
00010000
00011110
*/

int    main(void)
{
       char   i;
       LCD_HW_Init();
       LCD_SW_Init();
       LCD_String(0, 0, "Hello World");
       LCD_String(0, 1, "Hangle Font Display");
       _delay_ms(100);
       for(i=0; i<48; i++){                                                         // CGRAM address 문법
                LCD_Command(0x40  +  i);
                LCD_Data( LCD_Hangle_Font[i] );
       }
       _delay_ms(100);
       LCD_Command(0x01);
       _delay_ms(50);
       LCD_Char_xy(3,0);  LCD_Data(0x00);         _delay_ms(1);     //DDRAM data 0 
       LCD_Char_xy(5,0);  LCD_Data(0x01);         _delay_ms(1);     //DDRAM data 1     
       LCD_Char_xy(7,0);  LCD_Data(0x02);         _delay_ms(1);     //DDRAM data 2  
       LCD_Char_xy(3,1);  LCD_Data(0x03);         _delay_ms(1);     //DDRAM data 3     
       LCD_Char_xy(5,1);  LCD_Data(0x04);         _delay_ms(1);     //DDRAM data 4   
       LCD_Char_xy(7,1);  LCD_Data(0x05);         _delay_ms(1);     //DDRAM data 5     

       return  0;
}
