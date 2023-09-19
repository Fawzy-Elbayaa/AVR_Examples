/*
 * EXTI_INTERFACE.h
 *
 * Created: 4/22/2022 5:04:18 PM
 *  Author: fawzy
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_INT0_INIT(void); /* a function to set the required sense control INT0 using pre build configuration */
void EXTI_INT1_INIT(void); /* a function to set the required sense control INT0 using pre build configuration */
void EXTI_INT2_INIT(void); /* a function to set the required sense control INT0 using pre build configuration */

/*Description : a function to set the required sense control INT0 using post build configuration
     input    : sense_control
 options input: 1- LOW_LEVEL
                2- ON_CHANGE
				3- FAILING_EDGE                  
				4- RISING_EDGE
   output     : Error state with type u8 				
                                             */
U8 EXTI_INT0_INIT_SENSE(U8 sense_control); 
U8 EXTI_INT0_INIT_SENSE(U8 sense_control);
U8 EXTI_INT0_INIT_SENSE(U8 sense_control);
/* Description   :  a function to set the required state INT0 using post build configuration
       input     : INT_PIN_STATE
	   OPTIONS   : 1- IN0
	               2- IN1
				   3- IN2
		OUTPUT   : CURRENT STATE		      
                                       */
U8 EXTI_INT_ENABLE(U8 INT_PIN_STATE);

/* Description   :  a function to set the required state INT0 using post build configuration
       input     : INT_PIN_STATE
	   OPTIONS   : 1- IN0
	               2- IN1
				   3- IN2
		OUTPUT   : CURRENT STATE		      
                                       */
U8 EXTI_INT_DISABLE(U8 INT_PIN_STATE);

U8 EXTI_U8INT0SETCALLBACK(void (*copy_pvInt0func)(void));

U8 EXTI_U8INT1SETCALLBACK(void (*copy_pvInt0func)(void));










#endif /* EXTI_INTERFACE_H_ */