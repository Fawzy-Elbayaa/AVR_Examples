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
	U8 error_state =OK;
	U32 Local_u32Counter = 0;
	U8 Current_state = IDEAL; 

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
			if (Reading_ADC ==Reading_10bit)
			{
				*reading = RESULT;
			}
	    	else if (Reading_ADC==Reading_8bit)
	    	{
				*reading = ADCH;
	    	}
			Current_state = IDEAL;
	    }
	}
	else
	{
		Current_state= BUSY;
		error_state = NOTOK;
	}
	return error_state ;
	
}