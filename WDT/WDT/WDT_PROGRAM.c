/*
 * WDT_PROGRAM.c
 *
 * Created: 2/13/2023 1:19:02 PM
 *  Author: fawzy elbayaa
 */ 
#include "STD_TYPES.h"
#include "utilities.h"
#include "WDT_CONFIG.h"
#include "WDT_PRIVATE.h"
#include "WDT_INTERFACE.h"
#include "WDT_REGISTER.h"



void WDT_voidSleep(U8 copy_SleepTime)
{
	U8 Local_u8Error = OK;
	WDTCR &= 0b11111000;
	switch (copy_SleepTime)
	{
		
	
	case WDT_RESSET_AFTER13ms :  WDTCR |=WDT_RESSET_AFTER13ms;    break ;
	case WDT_RESSET_AFTER32ms :  WDTCR |=WDT_RESSET_AFTER32ms;    break ;
	case WDT_RESSET_AFTER65ms :  WDTCR |=WDT_RESSET_AFTER65ms;    break ;
	case WDT_RESSET_AFTER130ms :  WDTCR |=WDT_RESSET_AFTER130ms;    break ;
	case WDT_RESSET_AFTER260ms :  WDTCR |=WDT_RESSET_AFTER260ms;    break ;
	case WDT_RESSET_AFTER520ms :  WDTCR |=WDT_RESSET_AFTER520ms;    break ;
	case WDT_RESSET_AFTER1000ms :  WDTCR |=WDT_RESSET_AFTER1000ms;    break ;
	case WDT_RESSET_AFTER2100ms :  WDTCR |=WDT_RESSET_AFTER2100ms;    break ;
	default : Local_u8Error = NOTOK;
	}
	
	
}
void WDT_VoidEnable(void)
{
	setbit(WDTCR , WDTCR_WDE);
	
}
void WDT_VoidDisable(void)
{
	WDTCR |=0b00011000;
	WDTCR = 0;
	
}
