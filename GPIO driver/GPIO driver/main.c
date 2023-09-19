/*
 * GPIO driver.c
 *
 * Created: 7/6/2022 2:02:18 AM
 * Author : fawzy
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "Memory_Map.h"
#include "Utilities.h"
#include "GPIO.h"




int main(void)
{
	
	 gpio_set_port_direction(PORT_A ,1);
	 gpio_set_pin_direction(PORT_B ,0 ,1);
	// gpio_set_pin_value(PORT_A ,0 ,1);
	 //gpio_set_port_value(PORT_A ,0xff);
	 gpio_set_port_direction(PORT_C ,direction_input);
	
	 
	
   // gpio_set_pin_direction(PORT_A , pin0,direction_output);
   // gpio_set_pin_value(PORT_A , pin0 , 1);
   PORTA=0x00;
  
   
    while (1) 
    {
		// pull up res
		if (readbit(PINC,0)==0)
		{
				setbit(PORTA,0);

		}
		else
		{
			clearbit(PORTA,0);
		}
		if (readbit(PINC,7)==1)
		{
			setbit(PORTA,7);
		}
		else
		{
			clearbit(PORTA,7);
		}
    }
}

