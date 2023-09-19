/*
 * TIMERR.c
 *
 * Created: 12/17/2022 1:37:25 PM
 * Author : fawzy
 */ 
#define  F_CPU 8000000

#include "STD_TYPES.h"
#include "utilities.h"
#include "port_config.h"
#include "port_initial.h"
#include "GPIO.h"
#include "TIMER_INTERFACE.h"
#include "memory_map.h"
#include "GIE_INTERFACE.h"
#include "GPIO.h"
#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "lcd.h"

extern U8 On_time_Bwm;
extern U8 Off_Time_Bwm;
static volatile U16 Period_ticks = 0;
static volatile  U16 On_ticks = 0;

void led(void);
void led_OV(void);

void led_Bwm(void);
U16 Res_Compare_Match=0;
U16 counter ;
U16 ADC_RES;
U16 ret_pot;

void ICU_SW(void);
void ICU_HW(void);

int main(void)
{
	
    /* Replace with your application code */
	direction_and_port_init();
	
	TIMER1_voidICUCallback(&ICU_HW);
	//GIE_ENABLE();
	//ADC_VoidInit();
	TIMER1_VoidInit();
	Timer1_voidSettrigger(RISING_EDGE);
	TIMER1_u8ISR_ICU_Mode(ENABLED);
	TIMER0_VoidInit();
	init_lcd();
	GIE_ENABLE();
	
	
	
	//Res_Compare_Match = TIMER0_U8SetCallBack(&led , 250 , 1000);
	//TIMER0_U8SetCallBackOV(&led_OV , 0.256);
	//Timer0_U8BWM(20000 , 0.25 , 64 ,&led_Bwm, 1000);
	Timer0_voidFast_Bwm(25);
	//Timer0_voidPhase_Correct(25);
	//TIMER1_voidFast_Bwm(20000 , 2000);
	
    while (1) 
    {
		
		//while((Period_ticks == 0) && (On_ticks == 0));  /*wait until period ticks and on ticks are measured*/
		position_xy(0,0);
		write_string("periodticks=" , 0 , 0);
		send_number_lcd(Period_ticks , 3);
		position_xy(1,0);
		write_string("onticks=", 1, 0);
		
		
		send_number_lcd(On_ticks, 3);
		
		/*ADC_U16StartConversionSync(SINGLE_ENDED_INPUT_ADC7 , &ADC_RES);
		ret_pot = mapping(0, 1000 , 1023 , 2000 , ADC_RES);
		TIMER1_voidFast_Bwm(20000 , ret_pot);
		for (counter = 1000 ; counter <=2000 ; counter++)
		{
			TIMER1_voidFast_Bwm(20000 , counter);
			_delay_ms(10);
		}*/
		
    }
}
void ICU_HW(void)
{
	static U16  R1 , R2 , R3;
	static U8 Local_u8counter = 0;
	Local_u8counter++;
	if (Local_u8counter == 1)
	{
		R1 = Timer1_U16ReadTimerValue();
	}
	else if (Local_u8counter == 2)
	{
		R2 = Timer1_U16ReadTimerValue();
		Period_ticks = R2 - R1 ;
		Timer1_voidSettrigger(FALLING_EDGE);
	}
	else if (Local_u8counter ==3)
	{
		R3 = Timer1_U16ReadTimerValue();
		On_ticks = R3 - R2;
		TIMER1_u8ISR_ICU_Mode(DISABLED);
	}
	
}

/*void ICU_SW(void)
{
	static U8 Local_u8counter = 0;
	Local_u8counter++;
	if (Local_u8counter == 1)
	{
		Timer1_voidSetTimerValue(0);
		
	}
	else if (Local_u8counter == 2)
	{
		Period_ticks = Timer1_U16ReadTimerValue();
		EXTI_INT0_INIT_SENSE(FAILING_EDGE);
	}
	else if (Local_u8counter ==3)
	{
		On_ticks = Timer1_U16ReadTimerValue();
		On_ticks -= Period_ticks;
		EXTI_INT_DISABLE(IN0);
	}
	
}*/
void led(void)
{
	static U16 counter = 0;
	counter ++;
	if (counter == Res_Compare_Match)
	{
		toggelbit(PORTA, 0);
		counter =0;
		
	}
	
}



void led_OV(void)
{
	static U32 counter = 0;
	U32 Local_value = Get_Real_Cov();
	counter ++;
	
	if (Local_value >1)
	{
		if (counter == (Local_value+1))
		{
			toggelbit(PORTA, 0);
			
			counter =0;
		}
	}
	else
	{
		toggelbit(PORTA, 0);
		counter =0;
	}
	
}

void led_Bwm(void)
{
	static U8 counter=0;
	counter++;
	if(counter==On_time_Bwm)
	{
		gpio_set_pin_value(PORT_A , 0 , 0);
	}
	else if (counter==(On_time_Bwm+ Off_Time_Bwm))
	{
		gpio_set_pin_value(PORT_A , 0 , 1);
		counter =0;
		
	}
	
}

