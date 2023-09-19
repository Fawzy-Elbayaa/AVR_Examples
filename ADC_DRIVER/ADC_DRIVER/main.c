/*
 * ADC_DRIVER.c
 *
 * Created: 8/5/2022 2:55:12 PM
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
		ADC_U16StartConversionSync(SINGLE_ENDED_INPUT_ADC0 , &app_reading);
		PORTC = (app_reading);  
		send_number_lcd(app_reading , 5);
		_delay_ms(500);
		
    }
}

