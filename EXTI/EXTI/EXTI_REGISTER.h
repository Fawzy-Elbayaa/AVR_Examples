/*
 * EXTI_REGISTER.h
 *
 * Created: 4/22/2022 5:03:26 PM
 *  Author: fawzy
 */ 


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define  MCUCR               *((volatile unsigned char *)0X55)
#define  MCUCR_ISC11         3
#define  MCUCR_ISC10         2
#define  MCUCR_ISC01         1
#define  MCUCR_ISC00         0

#define  MCUCSR              *((volatile unsigned char *)0X54)
#define  MCUCSR_ISC2         6                

#define  GICR                *((volatile unsigned char *)0X5B)
#define  GICR_INT1           7
#define  GICR_INT0           6
#define  GICR_INT2           5

#define  GIFR                *((volatile unsigned char *)0X5A)






#endif /* EXTI_REGISTER_H_ */