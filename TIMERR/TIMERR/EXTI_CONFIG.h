/*
 * EXTI_CONFIG.h
 *
 * Created: 4/26/2022 5:45:14 PM
 *  Author: fawzy
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/*OPTIONS : 1-LOW_LEVEL
            2-ON_CHANGE
			3-FAILING_EDGE
			4-RISING_EDGE
                              */
#define  INT0_SENSE       RISING_EDGE

/*OPTIONS : 1-LOW_LEVEL
            2-ON_CHANGE
			3-FAILING_EDGE
			4-RISING_EDGE
			                      */
#define  INT1_SENSE    FAILING_EDGE 
/*OPTIONS : 
			1-FAILING_EDGE
			2-RISING_EDGE
			                      */

#define   INT2_SENSE    FAILING_EDGE
/*OPTIONS : 1-ENABLED 
            2-DISABLED
                        */ 
#define  INT0_INITIAL_STATE     ENABLED

/*OPTIONS : 1-ENABLED 
            2-DISABLED
                        */ 
#define  INT1_INITIAL_STATE     ENABLED

/*OPTIONS : 1-ENABLED 
            2-DISABLED
                        */ 
#define  INT2_INITIAL_STATE     ENABLED  

#endif /* EXTI_CONFIG_H_ */