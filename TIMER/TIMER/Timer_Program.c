/*
 * Timer_Program.c
 *
 * Created: 9/20/2022 10:51:03 PM
 *  Author: fawzy
 */ 

#include "STD_TYPES.h"
#include "utilities.h"

#include "Timer_Interface.h"
#include "Timer_Register.h"
#include "Timer_Config.h"
#include "Timer_Private.h"

static void (*TIMER0_PVCallBackFunc)(void)= NULL;

U16 real_vlue;
U16 fraction;
U16 CTC_ov;



/*void TIMER0_VoidInit(void)
{
	
	//compare match
	select CTC*/
	//clearbit(TCCRO,TCCRO_WGM00);
	//setbit(TCCRO,TCCRO_WGM01);
	
	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	//setbit(TIMSK,TIMSK_OCIE0);
	
	/*SET COMPARE MATCH VALUE */
	//OCR0 = 250;
	
	/*SELECT PRESCALER*/
	//clearbit(TCCRO,TCCRO_CS00);
	//setbit(TCCRO , TCCRO_CS01);
	//clearbit(TCCRO,TCCRO_CSO2);
	
	/*********************************/
	/*clearbit(TCCRO,TCCRO_WGM00);
	clearbit(TCCRO,TCCRO_WGM01);
	
	setbit(TIMSK,TIMSK_TOIE0);
	
	TCNT0=5;
	
	clearbit(TCCRO,TCCRO_CS00);
	setbit(TCCRO , TCCRO_CS01);
	clearbit(TCCRO,TCCRO_CSO2);
	
	
	
	
}*/
U8 TIMER0_OV_INIT(U16 Copy_Milli_Second )
{
	//waveform generation normal
	clearbit(TCCRO,TCCRO_WGM00);
	clearbit(TCCRO,TCCRO_WGM01);
	
	//timer prescaler
	clearbit(TCCRO,TCCRO_CS00);
	setbit(TCCRO , TCCRO_CS01);
	clearbit(TCCRO,TCCRO_CSO2);
	
	//set ov interrupt
	setbit(TIMSK,TIMSK_TOIE0);
	//to find real value 
	real_vlue = (U16)(((U32)Copy_Milli_Second *1000)/256);
	//to find fraction part
	fraction = (U16)(((U32)Copy_Milli_Second *1000)%256);
	
	return 0;
	
	
	
	
}	
U8 TIMER0_CTC_INIT(U8 Max_CTC , U16 Copy_milli_second)
{
	//compare match
	//select CTC
	
	clearbit(TCCRO,TCCRO_WGM00);
	setbit(TCCRO,TCCRO_WGM01);
	
	//timer prescaler
	clearbit(TCCRO,TCCRO_CS00);
	setbit(TCCRO , TCCRO_CS01);
	clearbit(TCCRO,TCCRO_CSO2);
	
	//set compare match interrupt
	setbit(TIMSK,TIMSK_OCIE0);
	
	OCR0 = Max_CTC;
	CTC_ov = (U16)(((U32)Copy_milli_second *1000)/Max_CTC);
	return OK;
	
	
	
}


U8 TIMER0_U8SetCallBack(void (*Copy_PvCallBackFun)(void))
{
	U8 Local_U8ErrorStatus=OK;
	if (Copy_PvCallBackFun !=NULL)
	{
		TIMER0_PVCallBackFunc = Copy_PvCallBackFun;
		
	}
	else
	{
		Local_U8ErrorStatus = NULLPOINTER;
	}
	
	
	return Local_U8ErrorStatus;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static U16 count =0;
	count++;
	if(count>=CTC_ov)
	{
		if (TIMER0_PVCallBackFunc!=NULL)
		{
			count=0;
			TIMER0_PVCallBackFunc();
			
		}
		
	}
	
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static U16 counter=0;
	static U8 flag=0;
	counter++;
	//real = 3906
	//frac= 64
	
	if (fraction ==0)
	{
		if (counter ==real_vlue)  //3906
		{
			if (TIMER0_PVCallBackFunc!=NULL)
			{
				
				TIMER0_PVCallBackFunc();
				
			}
			counter = 0;
			
		}
		
	}
	else
	{
		if (counter>=real_vlue && flag==0)
		{
			flag=1;
			TCNT0 = (256 - fraction);   //preload
			
			
			
		}
		else if (flag==1)
		{
			
			counter =0;
			flag =0;
			if (TIMER0_PVCallBackFunc!=NULL)
			{
				
				TIMER0_PVCallBackFunc();
				
				
				
			}
		}
		
	}
	
	
	
	
}



