/*
 * TIMER_INTERFACE.h
 *
 * Created: 12/17/2022 1:38:37 PM
 *  Author: fawzy
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#define  FALLING_EDGE     0
#define  RISING_EDGE     1

#define  ENABLED        0
#define  DISABLED       1 

void TIMER0_VoidInit(void);
void TIMER1_VoidInit(void);

U16 TIMER0_U8SetCallBack(void (*Copy_PvCallBackFunc)(void) , U8 Compare_match_Value , U16 required_time_milli);

U8 TIMER0_U8SetCallBackOV(void (*Copy_PVCallBack_OV)(void) , float required_time_milli);

U8 Timer0_U8BWM(U16 Period_Time_Milli , float DutyCycle_Percentage , U8 Prescaler , void (*Copy_PVCallBackFunc)(void) ,U16 Required_Time_Millii );

void Timer0_voidFast_Bwm( U8 Duty_Cycle );
void TIMER1_voidFast_Bwm(U16 TOP , U16 COMP);
void Timer0_voidPhase_Correct(U8 Duty_Cycle);
void Timer1_voidSetTimerValue(U16 Copy_U16value);
U16 Timer1_U16ReadTimerValue(void);
U8 Timer1_voidSettrigger(U8 copy_u8Edge);
U8 TIMER1_u8ISR_ICU_Mode(U8 MODE_ICU_ISR);

U8 TIMER1_voidICUCallback(void (*copy_pvCallbackFunc)(void));



U32 Get_Real_Cov(void);


#endif /* TIMER_INTERFACE_H_ */