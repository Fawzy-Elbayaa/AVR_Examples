/*
 * Timer_Register.h
 *
 * Created: 9/20/2022 10:50:01 PM
 *  Author: fawzy
 */ 


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


#define  TCCRO            *((volatile U8*)0x53)
#define  TCCRO_FOCO        7
#define  TCCRO_WGM00       6
#define  TCCRO_COM01       5
#define  TCCRO_COM00       4
#define  TCCRO_WGM01       3
#define  TCCRO_CSO2        2
#define  TCCRO_CS01        1
#define  TCCRO_CS00        0

/*-------------------------------------*/
#define  TCNT0              *((volatile U8*)0x52)         /* while counter mode*/



#define  OCR0               *((volatile U8*)0x5C)              /*The Output Compare*/



#define TIMSK               *((volatile U8*)0x59)   /*OCIE0 TOIE0*/
#define TIMSK_OCIE0          1     /*COMPARE MATCH INTERRUPT*/
#define TIMSK_TOIE0          0     /*OVERFLOW INTERRUPT */


 
 


#endif /* TIMER_REGISTER_H_ */