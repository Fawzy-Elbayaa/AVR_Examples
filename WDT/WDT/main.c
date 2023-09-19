/*
 * WDT.c
 *
 * Created: 2/13/2023 1:15:00 PM
 * Author : fawzy
 */ 

#define  F_CPU   8000000
#include "STD_TYPES.h"
#include "utilities.h"
#include "port_initial.h"
#include "WDT_INTERFACE.h"
#include <util/delay.h>
#include "GPIO.h"





int main(void)
{
	direction_and_port_init();
	
	gpio_set_pin_value(PORT_A , 0 , 1);
	_delay_ms(100);
	
	gpio_set_pin_value(PORT_A , 0 , 0);
	_delay_ms(100);
	
	WDT_VoidEnable();
	WDT_voidSleep(WDT_RESSET_AFTER1000ms);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

