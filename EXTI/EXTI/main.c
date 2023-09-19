/*
 * EXTI.c
 *
 * Created: 8/1/2022 1:28:16 AM
 * Author : fawzy
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>
#include "utilities.h"
#include "memory_map.h"
#include "STD_TYPES.h"
#include "port_config.h"
#include "port_initial.h"
#include "GPOIO.h"
#include "EXTI_INTERFACE.h"
#include "GIE_INTERFACE.h"
#include "EXTI_PRIVATE.h"

void ISR_INT0(void);
void ISR_INT1(void);
void ISR_INT2(void);





int main(void)
{
	direction_and_port_init();
	//DDRD =0X00;
	//DDRA =0XFF;
	//PORTD= 0XFF;
	//PORTA=0X00;
	//DDRC =0XFF;
	//PORTC = 0X00;
	//DDRB =0X00;
	//PORTB=0XFF;
	//EXTI_INT0_INIT();
	EXTI_INT0_INIT_SENSE(FAILING_EDGE);
	EXTI_INT_ENABLE(IN0);
	EXTI_U8INT0SETCALLBACK(&ISR_INT0);
	EXTI_INT1_INIT_SENSE(FAILING_EDGE);
	EXTI_INT_ENABLE(IN1);
	EXTI_U8INT1SETCALLBACK(&ISR_INT1);
	EXTI_INT2_INIT_SENSE(FAILING_EDGE);
	EXTI_INT_ENABLE(IN2);
	EXTI_U8INT2SETCALLBACK(&ISR_INT2);
	
	//EXTI_INT1_INIT();
	//EXTI_INT2_INIT();
	GIE_ENABLE();
	/* Replace with your application code */
	while (1)
	{
	}
}

void ISR_INT0(void)
{
	gpio_set_pin_value(PORT_A ,pin0 ,1);
	
}
//void __vector_1 (void) __attribute__((signal));
//void __vector_1 (void)
//{
//	gpio_set_pin_value(PORT_A ,pin0 ,1);
//	//PORTA = 0X01;
//}

void ISR_INT1(void)
{
	gpio_set_pin_value(PORT_A ,pin1 ,1);
	
}

//void __vector_2 (void) __attribute__((signal));
//void __vector_2 (void)
//{
//	gpio_set_pin_value(PORT_A ,pin1 ,1);
//
//
//}
void ISR_INT2(void)
{
	gpio_set_pin_value(PORT_C ,pin0 ,1);
	
}

//void __vector_3 (void) __attribute__((signal));
//void __vector_3 (void)
//{
//	gpio_set_pin_value(PORT_C ,pin0 ,1);
//
//
//}

