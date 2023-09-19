/*
 * ADC_PROGRAM.c
 *
 * Created: 8/6/2022 12:40:08 AM
 *  Author: fawzy
 */ 
#include "STD_TYPES.h"
#include "utilities.h"

#include "ADC_CONFIG.h"
#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "ADC_REGESTER.h"

 static U16 *Adc_U16Reading = NULL;
 static void (*Adc_PvCallBackNotification)(void)= NULL;

U8 ADC_BusyState = IDEAL;

void ADC_VoidInit(void)
{
	//voltage reference
	#if VOLTAGE_REFERNCE==INPUT_VOLTAGE_AREF
	clearbit(ADMUX,ADMUX_REFS0);
	clearbit(ADMUX,ADMUX_REFS1);
	
	#elif VOLTAGE_REFERNCE==INPUT_VOLTAGE_AVCC
	setbit(ADMUX,ADMUX_REFS0);
	clearbit(ADMUX,ADMUX_REFS1);
	
	#elif VOLTAGE_REFERNCE==INPUT_VOLTAGE_INTERNAL
	setbit(ADMUX,ADMUX_REFS0);
	setbit(ADMUX,ADMUX_REFS1);
	#else
	#warning "the selection is not exist configuration it"
	#endif
	
	
	//right adjust
	#if RESULT_ADC==ADC_RIGHT_ADJUST
	clearbit(ADMUX,ADMUX_ADLAR);
	#elif RESULT_ADC==ADC_LEFT_ADJUST
	setbit(ADMUX,ADMUX_ADLAR);
	
	#else
	#warning "the selection is not exist configuration it"
    #endif
	
	//prescaler
	ADCSRA &=Mask_Prescaler;
	ADCSRA |=PRESCALER_divide_by_128;
	
	
	//enable ADC
	setbit(ADCSRA,ADCSRA_ADEN);
}


U8 ADC_U16StartConversionSync(U8 COPY_U8Channel , U16* reading)
{
	U8 Current_state = IDEAL;
	U8 error_state =OK;
	U32 Local_u32Counter = 0;
	
   if (Current_state ==IDEAL)
   {
        Current_state =BUSY;
	    // the MUX bit in ADMUX register
	    ADMUX &=MASK_Mux_Channel;
	    ADMUX |= COPY_U8Channel;
	    
	    //start conversion
	    setbit(ADCSRA,ADCSRA_ADSC);
	    //polling (busy waiting) until the conversion complete flag is set
	    while((readbit(ADCSRA,ADCSRA_ADIF)==0) && (Local_u32Counter !=ADC_u32TIMEOUT))
	    {
	    	Local_u32Counter++;
	    } 
	    if (Local_u32Counter ==ADC_u32TIMEOUT)
	    {
	    	//loop is broken because the time is reach
	    	error_state = NOTOK;
	    }
	    else
	    {
	    	//loop is broken because the flag is reach
	    	setbit(ADCSRA,ADCSRA_ADIF);
	    	*reading = RESULT;
			Current_state = IDEAL;
	    }
	}
	else
	{
		Current_state= BUSYFUNC;
		error_state = NOTOK;
	}
	return error_state ;
	
}



U8 ADC_U16StartConversionASync(U8 COPY_U8Channel , U16* reading , void (*Copy_PvNotificationFunc)(void))
{
	U8 Local_ErrorState = OK;
	if (ADC_BusyState ==IDEAL)
	{
		if ((reading ==NULL)  || (Copy_PvNotificationFunc == NULL))
		{
			Local_ErrorState = NULLPOINTER;
		}
		else
		{
			ADC_BusyState  = BUSY;
			Adc_U16Reading =reading;
			Adc_PvCallBackNotification = Copy_PvNotificationFunc;
			// the MUX bit in ADMUX register
			ADMUX &=MASK_Mux_Channel;
			ADMUX |= COPY_U8Channel;
			
			//start conversion
			setbit(ADCSRA,ADCSRA_ADSC);
			
			//ADC  enable interrupt
			setbit(ADCSRA,ADCSRA_ADIE);
			
		}
	}
	
	
	
	
}
U16 mapping (U8 x1_input, U16 y1_output , U16 x2_input, U16 y2_output, U16 x_value )   // 0 1000  1023  2000 
{
	
	U32 res1;
	U16 res2;
	U16 res3;
	
	res1 = (U32)(y2_output - y1_output )* (x_value - x1_input) ;
	res2 = (x2_input - x1_input);
	res3=  (U16)(((U32)res1 / res2 ) + y1_output);
	return res3 ;
	
}
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*read adc result */
	*(Adc_U16Reading) =RESULT;
	/*invoke the call back notification func*/
	Adc_PvCallBackNotification();
	
	ADC_BusyState = IDEAL ;
	
	/*disable the interrupt of  ADC*/
	clearbit(ADCSRA , ADCSRA_ADIE);
	
}
