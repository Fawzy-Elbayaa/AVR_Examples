/*
 * memory_map.h
 *
 * Created: 12/23/2021 2:18:39 PM
 *  Author: fawzy
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_
#define PORTA *((volatile unsigned char *)0x3B)
#define DDRA *((volatile unsigned char *)0x3A)
#define PINA *((volatile unsigned char *)0x39)

//PORT C
#define PORTC *((volatile unsigned char *)0x35)
#define DDRC *((volatile unsigned char *)0x34)
#define PINC *((volatile unsigned char *)0x33)
// PORT B
#define PORTB *((volatile unsigned char *)0x38)
#define DDRB *((volatile unsigned char *)0x37)
#define PINB *((volatile unsigned char *)0x36)
//PORT D
#define PORTD *((volatile unsigned char *)0x32)
#define DDRD *((volatile unsigned char *)0x31)
#define PIND *((volatile unsigned char *)0x30)








#endif /* MEMORY_MAP_H_ */