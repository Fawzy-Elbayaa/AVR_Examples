/*
 * Memory_Map.h
 *
 * Created: 7/6/2022 2:06:55 AM
 *  Author: fawzy
 */ 



#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_
//PORTA
#define PORTA *((volatile unsigned char *)0x3B)
#define DDRA *((volatile unsigned char *)0x3A)
#define PINA *((volatile unsigned char *)0x39)

// PORT B
#define PORTB *((volatile unsigned char *)0x38)
#define DDRB *((volatile unsigned char *)0x37)
#define PINB *((volatile unsigned char *)0x36)

//PORT C
#define PORTC *((volatile unsigned char *)0x35)
#define DDRC *((volatile unsigned char *)0x34)
#define PINC *((volatile unsigned char *)0x33)

//PORT D
#define PORTD *((volatile unsigned char *)0x32)
#define DDRD *((volatile unsigned char *)0x31)
#define PIND *((volatile unsigned char *)0x30)







#endif /* MEMORY_MAP_H_ */