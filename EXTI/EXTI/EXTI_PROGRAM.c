/*
 * EXTI_PROGRAM.c
 *
 * Created: 4/22/2022 5:04:44 PM
 *  Author: fawzy
 */ 
#include "memory_map.h"
#include "utilities.h"
#include "STD_TYPES.h"
#include "EXTI_REGISTER.h"
#include "EXTI_INTERFACE.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_CONFIG.h"

/*global pointer to function to hold INT0 ISR address*/
void (*EXTI_PVInt0ptrfunc)(void) =NULL;

/*global pointer to function to hold INT1 ISR address*/
void (*EXTI_PVInt1ptrfunc)(void) =NULL;

/*global pointer to function to hold INT2 ISR address*/
void (*EXTI_PVInt2ptrfunc)(void) =NULL;

void EXTI_INT0_INIT(void)
{
	/* 1- check sense control*/
	#if INT0_SENSE == LOW_LEVEL
	clearbit(MCUCR,MCUCR_ISC00);
	clearbit(MCUCR,MCUCR_ISC01);
	
	#elif INT0_SENSE == ON_CHANGE
	setbit(MCUCR,MCUCR_ISC00);
	clearbit(MCUCR,MCUCR_ISC01);
		
	#elif INT0_SENSE == FAILING_EDGE
	clearbit(MCUCR,MCUCR_ISC00);
	setbit(MCUCR,MCUCR_ISC01);
		
	
	#elif INT0_SENSE == RISING_EDGE
	setbit(MCUCR,MCUCR_ISC00);
	setbit(MCUCR,MCUCR_ISC01);
	
	#else
	#warning  "wrong INT0_SENSE configuration option"
	#endif
	
	#if INT0_INITIAL_STATE == ENABLED
	setbit(GICR,GICR_INT0);
	#elif INT0_INITIAL_STATE == DISABLED
	clearbit(GICR,GICR_INT0);
	#else
	#warning "wrong INT0_INITIAL_STATE configuration option"
    #endif
	
}
void EXTI_INT1_INIT(void)
{
	/* 1- check sense control*/
	#if INT1_SENSE == LOW_LEVEL
	clearbit(MCUCR,MCUCR_ISC10);
	clearbit(MCUCR,MCUCR_ISC11);
	
	#elif INT1_SENSE == ON_CHANGE
	setbit(MCUCR,MCUCR_ISC10);
	clearbit(MCUCR,MCUCR_ISC11);
	
	#elif INT1_SENSE == FAILING_EDGE
	clearbit(MCUCR,MCUCR_ISC10);
	setbit(MCUCR,MCUCR_ISC11);
	
	
	#elif INT1_SENSE == RISING_EDGE
	setbit(MCUCR,MCUCR_ISC10);
	setbit(MCUCR,MCUCR_ISC11);
	
	#else
	#warning  "wrong INT1_SENSE configuration option"
	#endif
	
	#if INT1_INITIAL_STATE == ENABLED
	setbit(GICR,GICR_INT1);
	#elif INT1_INITIAL_STATE == DISABLED
	clearbit(GICR,GICR_INT1);
	#else
	#warning "wrong INT1_INITIAL_STATE configuration option"
	#endif
	
	
}
void EXTI_INT2_INIT(void)
{
	/* 1- check sense control*/
	
	#if INT2_SENSE == FAILING_EDGE
	clearbit(MCUCSR,MCUCSR_ISC2);
	
	#elif INT2_SENSE == RISING_EDGE
	setbit(MCUCSR,MCUCSR_ISC2);
	
	#else
	#warning  "wrong INT2_SENSE configuration option"
	#endif
	
	#if INT2_INITIAL_STATE == ENABLED
	setbit(GICR,GICR_INT2);
	#elif INT2_INITIAL_STATE == DISABLED
	clearbit(GICR,GICR_INT2);
	#else
	#warning "wrong INT2_INITIAL_STATE configuration option"
	#endif
	
}
U8 EXTI_INT0_INIT_SENSE(U8 sense_control)
{
	U8 Error_State =OK;
	switch(sense_control)
	{
		case  LOW_LEVEL : clearbit(MCUCR,MCUCR_ISC00);   clearbit(MCUCR,MCUCR_ISC01);  break;
		
		case ON_CHANGE :setbit(MCUCR,MCUCR_ISC00);   clearbit(MCUCR,MCUCR_ISC01);  break;
		
		case FAILING_EDGE : clearbit(MCUCR,MCUCR_ISC00); setbit(MCUCR,MCUCR_ISC01); break;
		
		case RISING_EDGE : setbit(MCUCR,MCUCR_ISC00);  setbit(MCUCR,MCUCR_ISC01); break;
		
		default: Error_State =NOTOK;
	}
	return Error_State;
}

U8 EXTI_INT1_INIT_SENSE(U8 sense_control)
{
	U8 Error_State =OK;
	switch(sense_control)
	{
		case  LOW_LEVEL :    clearbit(MCUCR,MCUCR_ISC10);	clearbit(MCUCR,MCUCR_ISC11);  break;
		
		case ON_CHANGE :     setbit(MCUCR,MCUCR_ISC10);	    clearbit(MCUCR,MCUCR_ISC11);  break;
		
		case FAILING_EDGE :  clearbit(MCUCR,MCUCR_ISC10);	setbit(MCUCR,MCUCR_ISC11); break;
		
		case RISING_EDGE :   setbit(MCUCR,MCUCR_ISC10);	    setbit(MCUCR,MCUCR_ISC11); break;
		
		default: Error_State =NOTOK;
	}
	return Error_State;
}

U8 EXTI_INT2_INIT_SENSE(U8 sense_control)
{
	U8 Error_State =OK;
	switch(sense_control)
	{
		
		
		case FAILING_EDGE : clearbit(MCUCSR,MCUCSR_ISC2); break;
		
		case RISING_EDGE : setbit(MCUCSR,MCUCSR_ISC2);    break;
		
		default: Error_State =NOTOK;
	}
	return Error_State;
}
U8 EXTI_INT_ENABLE(U8 INT_PIN_STATE)
{
	U8 current_state = OK;
	switch(INT_PIN_STATE)
	{
		case IN0 :  setbit(GICR,GICR_INT0);   break;
		
		
		case IN1 :  setbit(GICR,GICR_INT1);   break;
		
		
		case IN2 :  setbit(GICR,GICR_INT2);   break;
		 
		
		default: current_state = NOTOK;
	}
	return current_state;
	
}
U8 EXTI_INT_DISABLE(U8 INT_PIN_STATE)
{
	U8 current_state = OK;
	switch(INT_PIN_STATE)
	{
		case IN0 :  clearbit(GICR,GICR_INT0);   break;
		
		
		case IN1 :  clearbit(GICR,GICR_INT1);   break;
		
		
		case IN2 :  clearbit(GICR,GICR_INT2);   break;
		
		
		default: current_state = NOTOK;
	}
	return current_state;
	
	
}

U8 EXTI_U8INT0SETCALLBACK(void (*copy_pvInt0func)(void))
{
	U8 Local_u8ErrorStatus= OK;
	if (copy_pvInt0func !=NULL)
	{
		EXTI_PVInt0ptrfunc = copy_pvInt0func;
	}
	else 
	{
		Local_u8ErrorStatus = NOTOK ;
	}
	return Local_u8ErrorStatus;
	
}

U8 EXTI_U8INT1SETCALLBACK(void (*copy_pvInt0func)(void))
{
	U8 Local_u8ErrorStatus= OK;
	if (copy_pvInt0func !=NULL)
	{
		EXTI_PVInt1ptrfunc = copy_pvInt0func;
	}
	else
	{
		Local_u8ErrorStatus = NOTOK ;
	}
	return Local_u8ErrorStatus;
	
}
U8 EXTI_U8INT2SETCALLBACK(void (*copy_pvInt0func)(void))
{
	U8 Local_u8ErrorStatus= OK;
	if (copy_pvInt0func !=NULL)
	{
		EXTI_PVInt2ptrfunc = copy_pvInt0func;
	}
	else
	{
		Local_u8ErrorStatus = NOTOK ;
	}
	return Local_u8ErrorStatus;
	
}


/*global pointer to function to hold INT1 ISR address*/

/* ISR FOR INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_PVInt0ptrfunc !=NULL)
	{
		EXTI_PVInt0ptrfunc();
	}
	
}

/* ISR FOR INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_PVInt0ptrfunc !=NULL)
	{
		EXTI_PVInt1ptrfunc();
	}
	
}

/* ISR FOR INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_PVInt0ptrfunc !=NULL)
	{
		EXTI_PVInt2ptrfunc();
	}
	
}


