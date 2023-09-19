/*
 * GPIO.h
 *
 * Created: 7/6/2022 2:07:57 AM
 *  Author: fawzy
 */ 


#include <util/delay.h>
#include "memory_map.h"
#include "utilities.h"


#ifndef GPIO_H_
#define GPIO_H_
//PORTS MACROS
#define  PORT_A                      0
#define  PORT_B                      1
#define  PORT_C                      2
#define  PORT_D                      3


//PINS MACROS
#define  pin0                        0
#define  pin1                        1
#define  pin2                        2
#define  pin3                        3
#define  pin4                        4
#define  pin5                        5
#define  pin6                        6
#define  pin7                        7


//direction macros
#define  direction_input             0
#define  direction_output            1


//public function
void gpio_set_port_direction(unsigned char portnumber ,unsigned char direction);
void gpio_set_pin_direction(unsigned char portnumber ,unsigned char pin ,unsigned char direction);
void gpio_set_pin_value(unsigned char portnumber ,unsigned char pin ,unsigned char value);
void gpio_set_port_value(unsigned char portnumber ,unsigned char value);
unsigned char get_pin_value(unsigned char portnumber ,unsigned char pin);
unsigned char get_port_value(unsigned char portnumber);









#endif /* GPIO_H_ */