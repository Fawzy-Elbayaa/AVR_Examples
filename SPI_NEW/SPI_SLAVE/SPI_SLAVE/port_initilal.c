/*
 * port_initilal.c
 *
 * Created: 3/31/2022 11:43:11 PM
 *  Author: fawzy
 */ 

#include "memory_map.h"
#include "port_config.h"
#include "port_initial.h"

void direction_and_port_init(void)
{
	DDRA = DDRA_DIRECTION;
	DDRB = DDRB_DIRECTION;
	DDRC = DDRC_DIRECTION;
	DDRD = DDRD_DIRECTION;
	
	PORTA = PORTA_VALUE;
	PORTB = PORTB_VALUE;
	PORTC = PORTC_VALUE;  
	PORTD = PORTD_VALUE;
}
