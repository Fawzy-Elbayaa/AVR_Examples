/*
 * DAC_APP.c
 *
 * Created: 8/16/2022 2:07:20 AM
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



int main(void)
{
	U8  i=0;
	DDRC = 0xff;
	while(1)
	{
			PORTC = i;
			_delay_ms(100);
			i++;
	}
	
}



