/*
 * lcd.c
 *
 * Created: 3/14/2022 8:13:50 PM
 *  Author: fawzy
 */ 

#include "lcd.h"


void init_lcd(void)
{
	#ifdef EIGHT_BIT_MODE
	_delay_ms(35);      //wait for more than 30ms for power
	write_command(fun_set) ;  //set 2line and 5*8 dots
	_delay_ms(1);
	write_command(Disp_on);
	_delay_ms(1);
	write_command(clear_screen);
	_delay_ms(2);
	
	write_command(Entry_mode_set);
	
	#endif
	#ifdef FOUR_BIT_MODE 
	_delay_ms(35);      //wait for more than 30ms for power
	write_command(0b0010<<4) ;  //set 2line and 5*8 dots
	
	write_command(0b0010<<4) ;  //set 2line and 5*8 dots
	
	write_command(0b1000<<4) ;  //set 2line and 5*8 dots
	_delay_ms(1);               //wait for more than 37 microsecond
	write_command(0b0000<<4) ;  //disp on
	write_command(0b1100<<4) ;  //disp on
	_delay_ms(1);               //wait for more than 37 microsecond
	write_command(0b0000<<4) ; //clear screen
	write_command(0b0001<<4) ; //clear screen
	_delay_ms(2);              //wait for more than 1.5 ms
	write_command(0b0000<<4) ;  //entry mode
	write_command(0b0010<<4) ;
	 
    #endif
}
void write_command(unsigned char cmd)
{
	#ifdef EIGHT_BIT_MODE
	clearbit(PORTB,RS);
	clearbit(PORTB,RW);
	PORTD =cmd;
	enable_tick();
    #endif
	
	#ifdef FOUR_BIT_MODE
	clearbit(PORTB,RS);
	clearbit(PORTB,RW);
	PORTA =cmd<<4;
	enable_tick();
	#endif
	
	
	
}
void write_char(unsigned char data)
{
	#ifdef EIGHT_BIT_MODE
	setbit(PORTB,RS);
	clearbit(PORTB,RW);
	PORTD =data;
	enable_tick();
    #endif
	
	#ifdef FOUR_BIT_MODE
	setbit(PORTB,RS);
	clearbit(PORTB,RW);
	PORTA =data<<4;
	enable_tick();
	#endif
	
	
}
void  write_string( char *str , unsigned char row, unsigned char column)
{
	
	
	while(*str!=0)
	{
		if (row == 0 )
		{
			write_command(Begin_first_line+column);
		}
		else if (row==1)
		{
			write_command(Begin_second_line+column);
			
		}
		
			write_char(*str);
			str++;
			column++;
			if ( (row ==0) && (column == 16))
			{
				row=1;
				column =0;
				write_command(Begin_second_line+column);
			}
			
			
	}
	
}

 void enable_tick(void)
{
	setbit(PORTB,E);
	_delay_ms(1);
	clearbit(PORTB,E);
	
}

void position_xy(unsigned char row ,unsigned char column)
{
	unsigned char add;
	
	
	if (row == 0)
	{
		write_command(Begin_first_line);
		add = 0x40 * row +column ;
	}
	else if (row==1)
	{
		write_command(Begin_second_line);
		add = 0x40 * row +column ;
	}
	write_command(add |(1<<7));  // to display in DDRAM
}
void spechial_char(unsigned char *arr ,unsigned char block_number , unsigned char x, unsigned char y)
{
	unsigned char i;
	unsigned char add = block_number *8;       /* calculate CGRAM address which each block contains 8 byte */
	write_command(add | (1<<6));               /* send CGRAM address command to LCD ,with bit 6 is 1 to send command of CGRAM*/
	for (i=0;i<8 ;i++)
	{
		write_char(arr[i]);
	}
	position_xy(x,y);
	write_char(block_number);
	
}
void send_number_lcd(U16 number , U8 digits)
{
	U8 x,y,z,w,e,r,t,u;
	switch(digits)
	{
		
		
	   case 3:
	    
	    x = (number/100);      x=x+48;           write_char(x); 
	    y = (number%100)/10;   y = y+48;         write_char(y);
	    z = (number%100)%10;   z= z+48;          write_char(z);
	    break;
	    
	    case 5:
	    w = (number/10000);                  w= w+48;          write_char(w);
	    e = (number%10000)/1000;             e=e+48;           write_char(e);
	    r=  ((number%10000)%1000)/100;       r= r+48;		   write_char(r);
	    t = ((number%10000)%1000)%100/10;    t= t+48;		   write_char(t);
	    u = ((number%10000)%1000)%100%10;    u= u+48;		   write_char(u);
	    break;
	}
}


