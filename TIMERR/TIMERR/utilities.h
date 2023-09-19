/*
 * utilities.h
 *
 * Created: 12/23/2021 10:10:26 PM
 *  Author: fawzy
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_
#define setbit(reg ,bit)    (reg=reg|(1<<bit))
#define clearbit(reg,bit)   (reg=reg &~(1<<bit))
#define readbit(reg,bit)    ((reg>>bit)&1)
#define toggelbit(reg,bit)  (reg=reg^(1<<bit))






#endif /* UTILITIES_H_ */