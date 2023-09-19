/*
 * POT_APP(2).c
 *
 * Created: 8/16/2022 2:37:34 AM
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
#include "GIE_INTERFACE.h"
#include <util/delay.h>


U16 app_reading;
U16 Value_AdcChannel;
U8 Number_led;

void notification_ISR(void);
int main(void)
{
	direction_and_port_init();
	
	
	init_lcd();
	GIE_ENABLE();
	write_command(clear_screen);
	
	ADC_VoidInit();

	/* Replace with your application code */
	while (1)
	{
		//sync
		/*write_command(clear_screen);
		_delay_ms(1);
		ADC_U16StartConversionSync(SINGLE_ENDED_INPUT_ADC0 , &app_reading);
		// Value_AdcChannel = app_reading;
		Number_led = mapping(0 , 1 , 1023 , 8 ,  app_reading);
		send_number_lcd(app_reading , 5);
		if (Number_led ==1)
		{
			PORTC = 0x01;
		}
		else if (Number_led ==2)
		{
			PORTC =0x03;
		}
		else if (Number_led ==3)
		{
			PORTC =0x07;
		}
		else if (Number_led ==4)
		{
			PORTC =0x0f;
		}
		else if (Number_led ==5)
		{
			PORTC =0x1f;
		}
		else if (Number_led ==6)
		{
			PORTC =0x3f;
		}
		else if (Number_led ==7)
		{
			PORTC =0x7f;
		}
		else
		{
			PORTC = 0xff;
			
		}
		position_xy(1,0);
		send_number_lcd(Number_led , 3);
		_delay_ms(500);*/
        //async
		write_command(clear_screen);
		_delay_ms(1);
		ADC_U16StartConversionASync(SINGLE_ENDED_INPUT_ADC0 , &app_reading , &notification_ISR);
		send_number_lcd(app_reading , 5);
		_delay_ms(500);
		
		
		
	}
}
void notification_ISR(void)
{
	PORTC =0x01;
	_delay_ms(500);
	PORTC=0x00;
}

