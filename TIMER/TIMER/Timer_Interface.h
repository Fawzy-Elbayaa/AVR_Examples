/*
 * Timer_Interface.h
 *
 * Created: 9/20/2022 10:50:32 PM
 *  Author: fawzy
 */ 



#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_VoidInit(void);
U8 TIMER0_OV_INIT(U16 Copy_Milli_Second );
U8 TIMER0_CTC_INIT(U8 Max_CTC , U16 Copy_milli_second);


U8 TIMER0_U8SetCallBack(void (*Copy_PvCallBackFun)(void));




#endif /* TIMER_INTERFACE_H_ */