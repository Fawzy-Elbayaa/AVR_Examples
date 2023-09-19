/*
 * Timer_Private.h
 *
 * Created: 9/20/2022 10:49:01 PM
 *  Author: fawzy
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
//WAVEFORM GENERATION
#define  TIMER_NORMAL      0
#define  TIMER_BWM         1
#define  TIMER_CTC         2
#define  TIMER_FAST_BWM    3

//PRESCALER
#define  TIMER_NO_CLOCK_SOUECE                    0
#define  TIMER_CLOCK                              1
#define  TIMER_CLOCK_DIVIDE_BY_8                  2
#define  TIMER_CLOCK_DIVIDE_BY_64                 3   
#define  TIMER_CLOCK_DIVIDE_BY_256                4
#define  TIMER_CLOCK_DIVIDE_BY_1024               5
#define  TIMER_EXT_FAILING_EDGE                   6
#define  TIMER_EXT_RAISING_EDGE                   7







#endif /* TIMER_PRIVATE_H_ */