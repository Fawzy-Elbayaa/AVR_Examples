/*
 * TIMER_CONFIG.h
 *
 * Created: 12/17/2022 1:39:06 PM
 *  Author: fawzy elbayaa
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*Compare Output Mode, non-PWM Mode
        options  1- normal port operation (OC0 Disconnect)
		         2- Toggle OC0 on compare match
				 3- Clear OC0 on compare match
				 4- Set OC0 on compare match*/
				 
#define  Compare_output_mode     TIMER0_OCO_Disconnect	
/*waveform generation mode 
                    options 1-TIMER0_Normal_Mode
					        2-TIMER0_PWM_phase_correct
							3-TIMER0_CTC
							4-TIMER0_Fast_Pwm
							*/
#define  Generation_Mode          TIMER0_Fast_Pwm

/*Interrupt Timer0 Source
                Options  1-TIMER0_NOrmal_Interrupt
				         2-TIMER0_Compare_Match_Interrupt
						 3-TIMER0_Isr_Off
						 */
#define  Timer0_Isr_Source   TIMER0_Isr_Off
   

/*SELECT CLOCK
       options 1- TIMER0_No_Clock_Source
	           2- TIMER0_NO_Prescaler
			   3- TIMER0_Divide_By_8
	   		   4- TIMER0_Divide_By_64
			   5- TIMER0_Divide_By_256
			   6- TIMER0_Divide_By_1024
			   7- TIMER0_External_Clock_With_Failiing_Edge
			   8- TIMER0_External_Clock_With_Raising_Edge  
			   */
#define  Timer_Clock     TIMER0_Divide_By_8    

/*select Fast PWM Mode  
                 options  1- OCO_Disconnected
				          2-Reserved
						  3-Clear on CTC , Set on top (Non_Inverting_Mode)
						  4-Set on CTC  ,Clear on top (Inverting_Mode)     
						  */ 
#define TIMER0_Fast_Pwm_Mode    Non_Inverting_Mode

#define  Phase_Correct_Mode  Non_Inverting_Mode

//------------------------------------ INIT TIMER/COUNTER 1
/*Compare Output Mode, non-PWM Mode
        options  1- TIMER_normal port operation (OC0 Disconnect)
		         2- TIMER_Toggle OC0 on compare match
				 3- TIMER_Clear OC0 on compare match
				 4- TIMER_Set OC0 on compare match
				 */
#define  Compare_output_mode     TIMER1_OCO_Disconnect

/*WAVEFORM GENERATION MODE
      OPTIONS 1- TIMER1_NORMAL
	          2- TIMER1_PWM_8BIT
			  3- TIMER1_PWM_9BIT
			  4- TIMER1_PWM_10BIT
			  5- TIMER1_CTC_TOP_OCR1A
			  6- TIMER1_FAST_PWM_8BIT
			  7- TIMER1_FAST_PWM_9BIT
			  8- TIMER1_FAST_PWM_10BIT
			  9- TIMER1_ Phase_Frequency_Correct_TOP_ ICR1
			  10-TIMER1_Phase_Frequency_Correct_TOP_OCR1A
			  11-TIMER1_PWM_Phase_Correct_TOP_ICR1
			  12-TIMER1_PWM_Phase_Correct_TOP_OCR1A
			  13-TIMER1_CTC_TOP_ICR1
			  14-TIMER1_RESERVED   
			  15-TIMER1_FAST_PWM_TOP_ICR1
			  16-TIMER1_FAST_PWM_TOP_OCR1A
			  */
#define  TIMER1_WAVEFORM_GENERATION_MODE      TIMER1_NORMAL

/*SELECT CLOCK
       options 1- TIMER1_No_Clock_Source
	           2- TIMER1_NO_Prescaler
			   3- TIMER1_Divide_By_8
	   		   4- TIMER1_Divide_By_64
			   5- TIMER1_Divide_By_256
			   6- TIMER1_Divide_By_1024
			   7- TIMER1_External_Clock_With_Failiing_Edge
			   8- TIMER1_External_Clock_With_Raising_Edge  
			   */
#define  TIMER1_Clock_Source               TIMER1_Divide_By_8  

/*TIMER1_Isr_Source
                options 1-TIMER1_Input_Capture_Interrupt_Enable 
				        2-TIMER_Output_CompareA_Match_Interrupt_Enable
						3-TIMER_Output_CompareB_Match_Interrupt_Enable
						4-TIMER_Overflow_Interrupt_Enable
						5-TIMER1_NO_SOURCE_ISR
						*/ 

#define TIMER1_Isr_Source     TIMER1_NO_SOURCE_ISR  

/*timer1 fast pwm 
    options      1 - TIMER1_OC1_Disconnected
	             2 - TIMER1_TOGGLE_COMP
				 3 - TIMER1_Non_Inverting_Mode
				 4 - TIMER1_Inverting_Mode 
				 */

#define TIMER1_Fast_Pwm_Mode       TIMER1_Non_Inverting_Mode                      



	


#endif /* TIMER_CONFIG_H_ */