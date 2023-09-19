/*
 * WDT_REGISTER.h
 *
 * Created: 2/13/2023 1:18:01 PM
 *  Author: fawzy
 */ 


#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_

#define      WDTCR                         *((volatile U8 *) (0x41))
#define      WDTCR_WDTOE                   4  //watch dog turn off enable
#define      WDTCR_WDE                     3  //Watch dog enable
#define      WDTCR_WDP2                   2  //watchdog timer prescaler2
#define      WDTCR_WDP1                   1  //watchdog timer prescaler1
#define      WDTCR_WDP0                   0  //watchdog timer prescaler0




#endif /* WDT_REGISTER_H_ */