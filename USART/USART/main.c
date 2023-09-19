/*
 * USART.c
 *
 * Created: 2/23/2023 6:26:49 PM
 * Author : fawzy
 */ 
#define  F_CPU 8000000
#include "STD_TYPES.h"
#include "memory_map.h"
#include "utilities.h"
#include "GPIO.h"
#include "port_initial.h"
#include "USART_INTERFACE.h"
#include <util/delay.h> 






int main(void)
{
	U8 Data;
	direction_and_port_init();
	USART_VoidInit();
    /* Replace with your application code */
    while (1) 
    {
		Data = USART_U8Receive();
		//_delay_ms(100);
		
		if(Data =='1')
		{
			setbit(PORTA , 0);
			//gpio_set_pin_value(PORT_A , 0 , 1);
		}
		else if (Data =='2')
		{
			clearbit(PORTA , 0); 
			//gpio_set_pin_value(PORT_A , 0 , 0);
		}
		USART_VoidSend('D');
		
		
		
		
		
    }
}

