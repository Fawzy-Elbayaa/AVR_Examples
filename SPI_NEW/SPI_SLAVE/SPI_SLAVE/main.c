/*
 * SPI_SLAVE.c
 *
 * Created: 3/24/2023 4:23:42 AM
 * Author : fawzy
 */ 

#define  F_CPU   8000000
#include <util/delay.h>
#include "STD_TYPES.h"
#include "utilities.h"
#include "memory_map.h"
#include "port_config.h"
#include "GPIO.h"
#include "SPI_INTERFACE.h"



int main(void)
{
	U8 Local_U8Receivedata;
	direction_and_port_init();
	SPI_VoidInitSlave();
	
	/* Replace with your application code */
	while (1)
	{
		Local_U8Receivedata = SPI_U8Transceive(10);
		_delay_ms(10);
		if(Local_U8Receivedata == 1)
		{
			setbit(PORTA , 0);
			//gpio_set_pin_value(PORT_A , 0 , 1);
		}
		
	}
}

