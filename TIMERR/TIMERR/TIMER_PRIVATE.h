/*
 * TIMER_PRIVATE.h
 *
 * Created: 12/17/2022 1:38:15 PM
 *  Author: fawzy
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


/*Compare Output Mode, non-PWM Mode */
#define  TIMER0_OCO_Disconnect                          0
#define  TIMER0_Toggle_OC0                              1
#define  TIMER0_clear_OCR1                              2
#define  TIMER0_set_OCR2                                3

/* TIMER0 Waveform Generation*/
#define  TIMER0_Normal_Mode                             0
#define  TIMER0_PWM_phase_correct                       1
#define  TIMER0_CTC                                     2 
#define  TIMER0_Fast_Pwm                                3

/*Timer0 Source Interrupt*/
#define  TIMER0_NOrmal_Interrupt                        0
#define  TIMER0_Compare_Match_Interrupt                 1
#define  TIMER0_Isr_Off                                 2
 
/*SELECT CLOCK*/
#define  TIMER0_No_Clock_Source                         0b00000000
#define  TIMER0_NO_Prescaler                            0b00000001
#define  TIMER0_Divide_By_8                             0b00000010
#define  TIMER0_Divide_By_64                            0b00000011
#define  TIMER0_Divide_By_256                           0b00000100
#define  TIMER0_Divide_By_1024                          0b00000101
#define  TIMER0_External_Clock_With_Failiing_Edge       0b00000110
#define  TIMER0_External_Clock_With_Raising_Edge        0b00000111

#define  Pre_Timer0                              0b11111000

/*Select Fast PWM Mode */
#define  OCO_Disconnected                           0
#define  Reserved                                   1
#define  Non_Inverting_Mode	                        2
#define  Inverting_Mode                             3

// -------------------------------- INIT  TIMER/COUNTER 1
/*Compare Output Mode, non-PWM Mode */
#define		TIMER1_OCO_Disconnect                          0
#define		TIMER1_Toggle_OC0                              1
#define		TIMER1_clear_OCR1                              2
#define		TIMER1_set_OCR2                                3

/*WAVEFORM GENERATION MODE  */
#define  TIMER1_NORMAL                                              0
#define  TIMER1_PWM_8BIT                                            1
#define  TIMER1_PWM_9BIT                                            2
#define  TIMER1_PWM_10BIT                                           3
#define  TIMER1_CTC_TOP_OCR1A                                       4
#define  TIMER1_FAST_PWM_8BIT					                    5
#define  TIMER1_FAST_PWM_9BIT					                    6
#define  TIMER1_FAST_PWM_10BIT					                    7
#define  TIMER1_Phase_Frequency_Correct_TOP_ICR1  		            8
#define  TIMER1_Phase_Frequency_Correct_TOP_OCR1A  		            9
#define  TIMER1_PWM_Phase_Correct_TOP_ICR1   				        10
#define  TIMER1_PWM_Phase_Correct_TOP_OCR1A   				        11
#define  TIMER1_CTC_TOP_ICR1   							            12
#define  TIMER1_RESERVED   						                    13
#define  TIMER1_FAST_PWM_TOP_ICR1     					            14
#define  TIMER1_FAST_PWM_TOP_OCR1A     					            15

/*Clock Source For Timer1*/
#define  TIMER1_No_Clock_Source                             0b00000000
#define  TIMER1_NO_Prescaler                                0b00000001
#define  TIMER1_Divide_By_8                                 0b00000010
#define  TIMER1_Divide_By_64                                0b00000011
#define  TIMER1_Divide_By_256                               0b00000100
#define  TIMER1_Divide_By_1024                              0b00000101
#define  TIMER1_External_Clock_With_Failiing_Edge           0b00000110
#define  TIMER1_External_Clock_With_Raising_Edge            0b00000111

/*TIMER1 ISR SOURCE   */
#define  TIMER1_Input_Capture_Interrupt_Enable                  0 
#define  TIMER_Output_CompareA_Match_Interrupt_Enable           1
#define  TIMER_Output_CompareB_Match_Interrupt_Enable	        2                               
#define  TIMER_Overflow_Interrupt_Enable                        3
#define  TIMER1_NO_SOURCE_ISR                                   4

#define  PRE_TIMER1         0b11111000         //magic number to clear first three bits for timer1

//TIMER1 FAST PWM
#define   OCO_Disconnected                0
#define   TIMER1_TOGGLE_COMP              1
#define   TIMER1_Non_Inverting_Mode       2
#define   TIMER1_Inverting_Mode           3






#endif /* TIMER_PRIVATE_H_ */