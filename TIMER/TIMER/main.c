/*
 * TIMER.c
 *
 * Created: 9/20/2022 10:48:05 PM
 * Author : fawzy
 */ 
#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "utilities.h"
#include "port_initial.h"

#include "GIE_INTERFACE.h"
#include "Timer_Interface.h"
#include "GPIO.h"


void led_toggle(void);

int main(void)
{
	GIE_ENABLE();
	direction_and_port_init();
	TIMER0_CTC_INIT(250 , 1000);
	TIMER0_U8SetCallBack(&led_toggle);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}
void led_toggle(void)
{
	
	
		toggelbit(PORTA ,0);
	
}

