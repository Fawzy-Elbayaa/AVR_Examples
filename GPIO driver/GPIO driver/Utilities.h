/*
 * Utilities.h
 *
 * Created: 7/6/2022 2:05:32 AM
 *  Author: fawzy
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

#define setbit(reg ,bit)     (reg=reg|(1<<bit))
#define clearbit(reg,bit)    (reg=reg &~(1<<bit))
#define readbit(reg,bit)     ((reg>>bit)&1)
#define toggelbit(reg,bit)   (reg=reg^(1<<bit))





#endif /* UTILITIES_H_ */