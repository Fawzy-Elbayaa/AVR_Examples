/*
 * TIMER_PROGRAM.c
 *
 * Created: 12/17/2022 1:40:34 PM
 *  Author: fawzy
 */ 

#include "STD_TYPES.h"
#include "utilities.h"

#include "TIMER_CONFIG.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_REGISTER.h"

void (*Timer0_PvCallBackFunc)(void)=NULL;
U32 real_cov;
U8 On_time_Bwm;
U8 Off_Time_Bwm;
void (*TIMER1_GLIBALPVICUcallback)(void) = NULL;

U32 Get_Real_Cov(void)
{
	return real_cov;
}
void TIMER0_VoidInit(void)
{
	#if     Generation_Mode == TIMER0_Normal_Mode
	clearbit(TCCR0,TCCR0_WGM01);
	clearbit(TCCR0 ,TCCR0_WGM00);
	
	#elif    Generation_Mode == TIMER0_PWM_phase_correct
	clearbit(TCCR0,TCCR0_WGM01);
	setbit(TCCR0 ,TCCR0_WGM00);
		
	#elif    Generation_Mode == TIMER0_CTC
	setbit(TCCR0,TCCR0_WGM01);
	clearbit(TCCR0 ,TCCR0_WGM00);
		
	#elif    Generation_Mode == TIMER0_Fast_Pwm
	setbit(TCCR0,TCCR0_WGM01);
	setbit(TCCR0 ,TCCR0_WGM00);
	
	#else
	#warning "wrong generation configration option"
	#endif
	
	#if Timer0_Isr_Source == TIMER0_NOrmal_Interrupt
	setbit(TIMSK , TIMSK_TOIE0);
	
	#elif Timer0_Isr_Source == TIMER0_Compare_Match_Interrupt
	setbit(TIMSK , TIMSK_OCIEO);
	
	#elif Timer0_Isr_Source == TIMER0_Isr_Off
	clearbit(TIMSK , TIMSK_TOIE0);
	clearbit(TIMSK , TIMSK_OCIEO);
    
	#else
	#warning "wrong Timer0_Isr_source options "
    #endif 
	 
	TCCR0 &= Pre_Timer0;             /*magic number to clear the first three bits*/
	
	#if Timer_Clock == TIMER0_No_Clock_Source
	TCCR0 |=TIMER0_No_Clock_Source;
	
	#elif Timer_Clock == TIMER0_NO_Prescaler   
	TCCR0 |=TIMER0_NO_Prescaler;
	
	#elif Timer_Clock == TIMER0_Divide_By_8
	TCCR0 |=TIMER0_Divide_By_8;
	
	#elif Timer_Clock == TIMER0_Divide_By_64
	TCCR0 |=TIMER0_Divide_By_64;
	
	#elif Timer_Clock == TIMER0_Divide_By_256
	TCCR0 |=TIMER0_Divide_By_256;
	
	#elif Timer_Clock == TIMER0_Divide_By_1024
	TCCR0 |=  TIMER0_Divide_By_1024;
	
	#elif Timer_Clock == TIMER0_External_Clock_With_Failiing_Edge
	TCCR0 |=TIMER0_External_Clock_With_Failiing_Edge;
	
	#elif Timer_Clock == TIMER0_External_Clock_With_Raising_Edge
	TCCR0 |=TIMER0_External_Clock_With_Raising_Edge;
	
	#else
	#warning "TIMER0 wrong Clock_Source options "

    #endif     
	
	
	/*select clock divide_by 64*/
	/*clearbit(TCCR0 , TCCR0_CS02);
	setbit(TCCR0, TCCR0_CS01);
	clearbit(TCCR0 , TCCR0_CS00);*/
	//TCCR0 &= Pre_Timer0;   /*magic number to clear the first three bits*/
	//TCCR0 |=Divide_By_64;       /* to choose 64 Prescaler*/
	
}

void TIMER1_VoidInit(void)
{
	#if     TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_NORMAL
	clearbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_8BIT
	setbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
		
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_9BIT
	clearbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
	
		
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_10BIT
	setbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_TOP_OCR1A
	clearbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
	
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_8BIT
	setbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_9BIT
	clearbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_10BIT
	setbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	clearbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_Phase_Frequency_Correct_TOP_ICR1
	clearbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_Phase_Frequency_Correct_TOP_OCR1A
	setbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_Phase_Correct_TOP_ICR1
	clearbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_Phase_Correct_TOP_OCR1A
	setbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	clearbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_TOP_ICR1
	clearbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_RESERVED
	setbit(TCCR1A , TCCR1A_WGM10);
	clearbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_TOP_ICR1
	clearbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	#elif    TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_TOP_OCR1A
	setbit(TCCR1A , TCCR1A_WGM10);
	setbit(TCCR1A , TCCR1A_WGM11);
	setbit(TCCR1B , TCCR1B_WGM12);
	setbit(TCCR1B , TCCR1B_WGM13);
	
	#else
	#warning "TIMER1 wrong generation configration option"
	#endif
	
	#if TIMER1_Isr_Source == TIMER1_Input_Capture_Interrupt_Enable
	setbit(TIMSK , TIMSK_TICIE1);
	
	#elif TIMER1_Isr_Source == TIMER_Output_CompareA_Match_Interrupt_Enable
	setbit(TIMSK , TIMSK_OCIE1A);
	
	#elif TIMER1_Isr_Source == TIMER_Output_CompareB_Match_Interrupt_Enable
	setbit(TIMSK  , TIMSK_OCIE1B);
	
	#elif TIMER1_Isr_Source==TIMER_Overflow_Interrupt_Enable
	setbit(TIMSK  , TIMSK_TOIE1);
	
	#elif TIMER1_Isr_Source==TIMER1_NO_SOURCE_ISR
	clearbit(TIMSK , TIMSK_TICIE1);
	clearbit(TIMSK , TIMSK_OCIE1A);
	clearbit(TIMSK  , TIMSK_OCIE1B);
	clearbit(TIMSK  , TIMSK_TOIE1);
	
	
    
	#else
	#warning "wrong Timer1_Isr_source options "
    #endif 
	 
	TCCR1B &=PRE_TIMER1;             /*magic number to clear the first three bits*/
	
	#if TIMER1_Clock_Source == TIMER1_No_Clock_Source
	TCCR1B |=TIMER1_No_Clock_Source;
	
	#elif TIMER1_Clock_Source == TIMER1_NO_Prescaler   
	TCCR1B |=TIMER1_NO_Prescaler;
	
	#elif TIMER1_Clock_Source == TIMER1_Divide_By_8
	TCCR1B |=TIMER1_Divide_By_8;
	
	#elif TIMER1_Clock_Source == TIMER1_Divide_By_64
	TCCR1B |=TIMER1_Divide_By_64;
	
	#elif TIMER1_Clock_Source == TIMER1_Divide_By_256
	TCCR1B |=TIMER1_Divide_By_256;
	
	#elif TIMER1_Clock_Source == TIMER1_Divide_By_1024
	TCCR1B |=TIMER1_Divide_By_1024;
	
	#elif TIMER1_Clock_Source == TIMER1_External_Clock_With_Failiing_Edge
	TCCR1B |=TIMER1_External_Clock_With_Failiing_Edge;
	
	#elif TIMER1_Clock_Source == TIMER1_External_Clock_With_Raising_Edge
	TCCR1B |=TIMER1_External_Clock_With_Raising_Edge;
	
	#else
	#warning "TIMER1 wrong Clock_Source options "

    #endif     
	
	
}

U16 TIMER0_U8SetCallBack(void (*Copy_PvCallBackFunc)(void) , U8 Compare_match_Value , U16 required_time_milli)  //using compare match
{
	U8 Local_error_State= OK;
	OCR0 = Compare_match_Value;
	U16 Result_Ctc = (required_time_milli / Compare_match_Value);
	Result_Ctc = Result_Ctc *1000;
	if (Copy_PvCallBackFunc !=NULL)
	{
		Timer0_PvCallBackFunc = Copy_PvCallBackFunc;
	}
	else
	{
		Local_error_State = NULLPOINTER ;
		
	}
	return Result_Ctc ;
	
}

U8 TIMER0_U8SetCallBackOV(void (*Copy_PVCallBack_OV)(void) , float required_time_milli)
{
	
	U8 Local_Error= OK;
	float OV_Time;
	float COV;
	U16 preload;
	float fraction;
	
	if (Copy_PVCallBack_OV!=NULL)
	{
		OV_Time = ((float)8*256*1000)/(float)8000000;   // milli second 0.256
		Timer0_PvCallBackFunc=Copy_PVCallBack_OV;
		
		
		if (required_time_milli > OV_Time)
		{
			COV = ((float)required_time_milli /(float)OV_Time);   //3906.25
			fraction = (COV - (int)COV);   //0.25
			real_cov = (int)COV;   //3906
			
			if( fraction !=0)
			{
				preload = (256 - (256*fraction));   //192
				TCNT0= preload;
			}
		}
		else if (required_time_milli < OV_Time)
		{
		    
			fraction = (required_time_milli /OV_Time);   //0.25
			preload = (256 - (256*fraction));
			TCNT0 = preload;
			real_cov = 0;
			
			
		}
		else
		{
			real_cov = 1;
		}
	}
	else
	{
		Local_Error = NOTOK;
	}
	return Local_Error ;
}

U8 Timer0_U8BWM(U16 Period_Time_Milli , float DutyCycle_Percentage , U8 Prescaler , void (*Copy_PVCallBackFunc)(void) , U16 Required_Time_Millii)
{
	U16 On_Time_Milli;
	U16 Off_Time_Milli;
	U8 Compare_Match;
	U8 Tick_Time;
	U8 Local_U8ErrorState= OK;
	if (Copy_PVCallBackFunc !=NULL)
	{
		Timer0_PvCallBackFunc = Copy_PVCallBackFunc;
		
		Tick_Time = (Prescaler / 8 );    /*tick of time by micro second */
		On_Time_Milli = (U16)((float)DutyCycle_Percentage * (U16)Period_Time_Milli);   /*to find on of time*/     //5000
		Off_Time_Milli = Period_Time_Milli - On_Time_Milli ;      /* to find off the time*/     //15000
		Period_Time_Milli = On_Time_Milli + Off_Time_Milli ; 
		
		Compare_Match = Required_Time_Millii / Tick_Time;  
		if (Compare_Match > 256)  /*the OCR0 will cause that overflow of register*/
		{ 
			Local_U8ErrorState = NOTOK ;  
			clearbit(TIMSK , TIMSK_OCIEO);   // disable the interrupt  in case overflow of the register 
		}
		else
		{
			OCR0 = Compare_Match ; 
			On_Time_Milli = On_Time_Milli /1000;       //to calculate on_time 
			Off_Time_Milli = Off_Time_Milli /1000;     //to calculate off_time
			On_time_Bwm = On_Time_Milli;
			Off_Time_Bwm = Off_Time_Milli;
			 
			
		}
	}
	else
	{
		Local_U8ErrorState = NULLPOINTER;
	}
	return Local_U8ErrorState ;
}

void Timer0_voidFast_Bwm(U8 Duty_Cycle)
{
	U8 copy_u8_Value ;
	#if TIMER0_Fast_Pwm_Mode == OCO_Disconnected
	clearbit(TCCR0 , TCCR0_COM00);
	clearbit(TCCR0 , TCCR0_COM01);
	
	#elif  TIMER0_Fast_Pwm_Mode == Reserved
	setbit(TCCR0 , TCCR0_COM00);
	clearbit(TCCR0 , TCCR0_COM01);
	
	#elif TIMER0_Fast_Pwm_Mode==Non_Inverting_Mode
	clearbit(TCCR0 , TCCR0_COM00);
	setbit(TCCR0 , TCCR0_COM01);
	
	copy_u8_Value =  (U8)(((U16)(Duty_Cycle)*256)/100) ;  // to find on time whereas when increase duty cycle will icrease  comapare match
	
	#elif TIMER0_Fast_Pwm_Mode == Inverting_Mode
	setbit(TCCR0 , TCCR0_COM00);
	setbit(TCCR0 , TCCR0_COM01);
	
	copy_u8_Value = (U8)(((U16)(100-Duty_Cycle)*256)/100);  // to find on time whereas when increase duty cycle will decrease comapare match
	
	#else
	#warning "wrong Fast_Pwm_Mode options "
	
    #endif
	
	OCR0 = copy_u8_Value;
	
}
U8  Timer1_voidSettrigger(U8 copy_u8Edge)
{
	U8 Local_u8ErrorState = OK;
	switch(copy_u8Edge)
	{
		case RISING_EDGE :setbit(TCCR1B , TCCR1B_ICES1);  break ;
		case FALLING_EDGE :clearbit(TCCR1B , TCCR1B_ICES1); break;
		default: Local_u8ErrorState = NOTOK;
	}
	return Local_u8ErrorState;
}
U8 TIMER1_voidICUCallback(void (*copy_pvCallbackFunc)(void))
{
	U8 Local_u8ErrorState = OK;
	if (copy_pvCallbackFunc !=NULL)
	{
		TIMER1_GLIBALPVICUcallback = copy_pvCallbackFunc;
	}
	else 
	{
		Local_u8ErrorState = NOTOK ;
	}
	return Local_u8ErrorState ;
}
U8 TIMER1_u8ISR_ICU_Mode(U8 Mode_Icu_Isr)
{
	U8 Local_u8error= OK;
	switch(Mode_Icu_Isr)
	{
		case  ENABLED  :setbit(TIMSK  , TIMSK_TICIE1);  break ;
		case  DISABLED  :clearbit(TIMSK  , TIMSK_TICIE1);  break ;
		
	}
}


void TIMER1_voidFast_Bwm(U16 TOP , U16 COMP)
{
	
	#if TIMER1_Fast_Pwm_Mode == OCO_Disconnected
	clearbit(TCCR1A , TCCR1A_COM1A0);
	clearbit(TCCR1A , TCCR1A_COM1A1);
	
	#elif  TIMER1_Fast_Pwm_Mode == TIMER1_TOGGLE_COMP
	setbit(TCCR1A , TCCR1A_COM1A0);
	clearbit(TCCR1A , TCCR1A_COM1A1);
	
	#elif TIMER1_Fast_Pwm_Mode==Non_Inverting_Mode
	clearbit(TCCR1A , TCCR1A_COM1A0);
	setbit(TCCR1A , TCCR1A_COM1A1);
	
	#elif TIMER1_Fast_Pwm_Mode == Inverting_Mode
	setbit(TCCR1A , TCCR1A_COM1A0);
	setbit(TCCR1A , TCCR1A_COM1A1);
	
	#else
	#warning "TIMER1 wrong Fast_Pwm_Mode options "
	#endif
	
	ICR1L = TOP;
	OCR1AL = COMP ; 
	
}
void Timer0_voidPhase_Correct(U8 Duty_Cycle)
{
	U8 copy_u8_Value ;
	#if Phase_Correct_Mode == OCO_Disconnected
	clearbit(TCCR0 , TCCR0_COM00);
	clearbit(TCCR0 , TCCR0_COM01);
	
	#elif  Phase_Correct_Mode == Reserved
	setbit(TCCR0 , TCCR0_COM00);
	clearbit(TCCR0 , TCCR0_COM01);
	
	#elif Phase_Correct_Mode==Non_Inverting_Mode
	clearbit(TCCR0 , TCCR0_COM00);
	setbit(TCCR0 , TCCR0_COM01);
	
	copy_u8_Value =  (U8)(((U16)(Duty_Cycle)*256)/100) ;  // to find on time whereas when increase duty cycle will icrease  comapare match
	
	#elif Phase_Correct_Mode == Inverting_Mode
	setbit(TCCR0 , TCCR0_COM00);
	setbit(TCCR0 , TCCR0_COM01);
	
	copy_u8_Value = (U8)(((U16)(100-Duty_Cycle)*256)/100);  // to find on time whereas when increase duty cycle will decrease comapare match
	
	#else
	#warning "wrong Phase_Correct_Mode options "
	
	#endif
	
	OCR0 = copy_u8_Value;	
}
void Timer1_voidSetTimerValue(U16 Copy_U16value)
{
	
	TCNT1L = Copy_U16value ; 
}
U16 Timer1_U16ReadTimerValue(void)
{
	return TCNT1L ;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (Timer0_PvCallBackFunc != NULL)
	{
		Timer0_PvCallBackFunc();
	}
}




void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if (Timer0_PvCallBackFunc != NULL)
	{
		Timer0_PvCallBackFunc();
	}
}
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if (TIMER1_GLIBALPVICUcallback != NULL)
	{
		TIMER1_GLIBALPVICUcallback();
	}
	
}

