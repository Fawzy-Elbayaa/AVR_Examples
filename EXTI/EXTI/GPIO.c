/*
 * GPIO.c
 *
 * Created: 3/23/2022 10:03:07 PM
 *  Author: fawzy
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>
#include "GPOIO.h"
#include "memory_map.h"
#include "utilities.h"
void gpio_set_port_direction(unsigned char portnumber ,unsigned char direction)
{
	switch(portnumber)
	{
		case PORT_A :
		if (direction ==direction_input)
		{
			DDRA = 0x00;
		}
		else
		{
			DDRA =0xff;
		}
		break;
		
		case PORT_B :
		if (direction ==direction_input)
		{
			DDRB = 0x00;
		}
		else
		{
			DDRB =0xff;
		}
		break;
		
		case PORT_C :
		if (direction ==direction_input)
		{
			DDRC = 0x00;
		}
		else
		{
			DDRC =0xff;
		}
		break;
		
		case PORT_D :
		if (direction ==direction_input)
		{
			DDRD = 0x00;
		}
		else
		{
			DDRD =0xff;
		}
		break;
		
		default:
		break;
		
		
		
	}
}

void gpio_set_pin_direction(unsigned char portnumber ,unsigned char pin ,unsigned char direction)
{
	switch(portnumber)
	{
		case PORT_A :
		if (direction ==direction_input)
		{
			clearbit(DDRA ,pin);
		}
		else
		{
			setbit(DDRA ,pin);
		}
		break;
		
		case PORT_B :
		if (direction ==direction_input)
		{
			clearbit(DDRB ,pin);
		}
		else
		{
			setbit(DDRB ,pin);
		}
		break;
		
		case PORT_C :
		if (direction ==direction_input)
		{
			clearbit(DDRC ,pin);
		}
		else
		{
			setbit(DDRC ,pin);
		}
		break;
		
		case PORT_D :
		if (direction ==direction_input)
		{
			clearbit(DDRD ,pin);
		}
		else
		{
			setbit(DDRD ,pin);
		}
		break;
		
		default:
		break;
	}
}

void gpio_set_pin_value(unsigned char portnumber ,unsigned char pin ,unsigned char value)
{
	switch(portnumber)
	{
		case PORT_A :
		if (value ==1)
		{
			setbit(PORTA ,pin);
		}
		else
		{
			clearbit(PORTA,pin);
		}
		break;
		
		case PORT_B :
		if (value ==1)
		{
			setbit(PORTB ,pin);
		}
		else
		{
			clearbit(PORTB,pin);
		}
		break;
		
		case PORT_C :
		if (value ==1)
		{
			setbit(PORTC ,pin);
		}
		else
		{
			clearbit(PORTC,pin);
		}
		break;
		
		case PORT_D :
		if (value ==1)
		{
			setbit(PORTD ,pin);
		}
		else
		{
			clearbit(PORTD,pin);
		}
		break;
		
		default:
		break;
	}
}

void gpio_set_port_value(unsigned char portnumber ,unsigned char value)
{
	switch(portnumber)
	{
		case PORT_A :
		      PORTA = value;
		      break;
		case PORT_B :
			  PORTB = value;
			  break;
			  
		case PORT_C :
		      PORTC = value;
		      break;
			  
		case PORT_D :
			  PORTD = value;
			  break;	
			  
		default:
		break;	    
	}
}

unsigned char get_pin_value(unsigned char portnumber ,unsigned char pin)
{
	unsigned char ret_val;
	switch(portnumber)
	{
		case PORT_A :
		ret_val = readbit(PINA ,pin);
		break;
		
		case PORT_B :
		ret_val = readbit(PINB ,pin);
		break;
		
		case PORT_C :
		ret_val = readbit(PINC ,pin);
		break;
		
		case PORT_D :
		ret_val = readbit(PIND ,pin);
		break;
		
		default:
		break;
	}
	return ret_val;
}

unsigned char get_port_value(unsigned char portnumber)
{
	unsigned char ret_port;
	switch(portnumber)
	{
		case PORT_A :
		ret_port = PINA;
		break;
		
		case PORT_B :
		ret_port = PINB;
		break;
		
		case PORT_C :
		ret_port = PINC;
		break;
		
		case PORT_D :
		ret_port = PIND;
		break;
		
		default: 
		break;
		
	}
	return ret_port;
}
