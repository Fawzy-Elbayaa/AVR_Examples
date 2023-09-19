/*
 * TIMER_REGISTER.h
 *
 * Created: 12/17/2022 1:40:05 PM
 *  Author: fawzy
 */ 


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define  TCCR0             *((volatile U8 *)(0X53))
#define  TCCR0_CS00         0
#define  TCCR0_CS01         1
#define  TCCR0_CS02         2
#define  TCCR0_WGM01        3
#define  TCCR0_COM00        4
#define  TCCR0_COM01        5
#define  TCCR0_WGM00        6
#define  TCCR0_FOFO         7

#define  TCNT0             *((volatile U8 *)(0X52))

#define  OCR0             *((volatile U8 *)(0X5C))

#define  TIMSK             *((volatile U8 *)(0X59))
#define  TIMSK_TOIE0          0
#define  TIMSK_OCIEO          1
#define  TIMSK_TOIE1          2
#define  TIMSK_OCIE1B         3
#define  TIMSK_OCIE1A         4
#define  TIMSK_TICIE1         5
#define  TIMSK_TOIE2          6
#define  TIMSK_OCIE2          7



// intialize of register timer1
#define  TCCR1A             *((volatile U8 *)(0X4f))  //compare ouput mode for compare unit A
#define  TCCR1A_WGM10          0       //Waveform Generation Mode
#define  TCCR1A_WGM11          1	   //Waveform Generation Mode
#define  TCCR1A_FOC1B          2	   //Force Output Compare for Compare unit B
#define  TCCR1A_FOC1A          3	   //Force Output Compare for Compare unit A
#define  TCCR1A_COM1B0         4	   //Compare Output Mode for Compare unit B
#define  TCCR1A_COM1B1         5	   //Compare Output Mode for Compare unit B
#define  TCCR1A_COM1A0         6	   //Compare Output Mode for Compare unit A
#define  TCCR1A_COM1A1         7	   //Compare Output Mode for Compare unit A


#define  TCCR1B             *((volatile U8 *)(0X4e))  //compare ouput mode for compare unit B
#define  TCCR1B_CS10          0       //Clock Select
#define  TCCR1B_CS11          1		  //Clock Select
#define  TCCR1B_CS12          2		  //Clock Select
#define  TCCR1B_WGM12         3		  //Waveform Generation Mode
#define  TCCR1B_WGM13         4		  //Waveform Generation Mode
#define  TCCR1B_RESERVED      5 	  //Reserved Bit
#define  TCCR1B_ICES1         6		  //Input Capture Edge Select
#define  TCCR1B_ICNC1         7    	  //Input Capture Noise Canceler

#define   TCNT1L            *((volatile U16 *)(0X4c))    //Timer/Counter1 – Counter Register Low Byte + high byte
#define   OCR1AL            *((volatile U16 *)(0X4A))    //Timer/Counter1 – Output Compare Register A Low Byte + high byte
#define   OCR1BL            *((volatile U16 *)(0X48))    //Timer/Counter1 – Output Compare Register B Low Byte + high byte
#define   ICR1L             *((volatile U16 *)(0X46))    //Timer/Counter1 – Input Capture Register Low Byte + high byte

#endif /* TIMER_REGISTER_H_ */