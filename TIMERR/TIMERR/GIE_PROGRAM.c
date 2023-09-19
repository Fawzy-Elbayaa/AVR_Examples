/*
 * GIE_PROGRAM.c
 *
 * Created: 4/22/2022 5:50:49 PM
 *  Author: fawzy
 */ 

#include "utilities.h"
#include "memory_map.h"
#include "GIE_REGISTER.h"
#include "GIE_INTERFACE.h"


void GIE_ENABLE(void)
{
	setbit(SREG,SREG_I);
}
void GIE_DISABLE(void)
{

	clearbit(SREG,SREG_I);
	
}