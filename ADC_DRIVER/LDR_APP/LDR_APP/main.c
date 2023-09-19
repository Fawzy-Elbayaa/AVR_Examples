/*
 * LDR_APP.c
 *
 * Created: 8/16/2022 6:23:17 PM
 * Author : fawzy
 */ 

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "utilities.h"
#include "memory_map.h"
#include "ADC_interface.h"
#include "port_config.h"
#include "port_initial.h"
#include "ADC_private.h"
#include "GPIO.h"
#include "lcd.h"
#include <util/delay.h>


U16 app_read;
U8 i;
int main(void)
{
   direction_and_port_init();
   
   
   init_lcd();
   write_command(clear_screen);
   
   ADC_VoidInit();
    while (1) 
    {
		write_command(clear_screen);
		_delay_ms(1);
		 ADC_U16StartConversionSync(SINGLE_ENDED_INPUT_ADC2 ,  &app_read);
		 
		if (app_read >0 && app_read <34)
		{
			PORTC = 0b11111111;
		}
		
		 
		else if ((app_read >34 && app_read <60))
		{
			PORTC = 0b01111111;
		}
		else if ((app_read >60 && app_read <97))
		{
			PORTC = 0b00111111;
		}
		else if ((app_read >97 && app_read <154))
		{
			PORTC = 0b00011111;
		}
		else if ((app_read >154 && app_read <193))
		{
			PORTC = 0b00001111;
		}
		else if ((app_read >193 && app_read <220))
		{
			PORTC = 0b00000111;
		}
		else if ((app_read >220 && app_read <241))
		{
			PORTC = 0b00000011;
		}
		else if ((app_read >241 && app_read <248))
		{
			PORTC = 0b00000001;
		}
		else if ((app_read >248 && app_read <255))
		{
			PORTC = 0b00000000;
		}
		
		
		send_number_lcd(app_read , 5);
		_delay_ms(500);
		
		
		
		
    }
}

