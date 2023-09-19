/*
 * tempreture_app.c
 *
 * Created: 8/16/2022 3:23:30 AM
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
U16 app_reading;
U16 mv;
U16 temp;
int main(void)
{
	direction_and_port_init();
	
	
	init_lcd();
	write_command(clear_screen);
	
	ADC_VoidInit();
	
    /* Replace with your application code */
    while (1) 
    {
		write_command(clear_screen);
		_delay_ms(1);
		ADC_U16StartConversionSync(SINGLE_ENDED_INPUT_ADC1 , &app_reading);
		mv = (((U32)app_reading *5000UL)/1024UL) ;
		temp = mv /10;
		send_number_lcd(temp , 3);
		_delay_ms(500);
		
		
    }
}

