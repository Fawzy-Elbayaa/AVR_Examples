/*
 * lcd.h
 *
 * Created: 3/14/2022 8:13:33 PM
 *  Author: fawzy
 */ 




#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "memory_map.h"
#include "utilities.h"
#include "STD_TYPES.h"



#define  clear_screen                 0b00000001
#define  Return_home                  0b00000010
#define Entry_mode_set                0b00000110
#define  Disp_on                      0b00001100
#define disp_off                      0b00001000
#define  fun_set                      0b00111000
#define Begin_second_line             0b11000000
#define Begin_first_line              0b10000000

#define  EIGHT_BIT_MODE
//#define  FOUR_BIT_MODE

#define  RS                 0
#define  RW                 1
#define  E                  2
void init_lcd(void);
void write_command(unsigned char cmd);
void write_char(unsigned char data);
void write_string( char *str , unsigned char row, unsigned char column);
void position_xy(unsigned char row ,unsigned char column);
void enable_tick(void);
void spechial_char(unsigned char *arr ,unsigned char block_number , unsigned char x, unsigned char y);
void send_number_lcd(U16 number , U8 digits);






#endif /* LCD_H_ */