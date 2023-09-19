/*
 * ADC_REGESTER.h
 *
 * Created: 8/6/2022 12:38:11 AM
 *  Author: fawzy
 */ 
#include "STD_TYPES.h"
#include "utilities.h"

#ifndef ADC_REGESTER_H_
#define ADC_REGESTER_H_

#define   ADMUX             *((volatile U8*)0x27)
#define   ADMUX_REFS1        7       
#define   ADMUX_REFS0        6 
#define   ADMUX_ADLAR        5

#define   ADCSRA             *((volatile U8*)0x26)
#define   ADCSRA_ADEN        7 
#define   ADCSRA_ADSC        6
#define   ADCSRA_ADATE       5
#define   ADCSRA_ADIF        4
#define   ADCSRA_ADIE        3
#define   ADCSRA_ADPS2       2
#define   ADCSRA_ADPS1       1
#define   ADCSRA_ADPS0       0

#define   ADCH               *((volatile U8*)0x25)
#define   ADCL               *((volatile U8*)0x24)

#define   SFIOR             *((volatile U8*)0x50)
#define   SFIOR_ADTS2       7
#define   SFIOR_ADTS1       6
#define   SFIOR_ADTS0       5 

#define   RESULT               *((volatile U16*)0x24)  //ADCL+ADCH









#endif /* ADC_REGESTER_H_ */