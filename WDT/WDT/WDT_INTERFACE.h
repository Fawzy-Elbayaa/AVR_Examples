/*
 * WDT_INTERFACE.h
 *
 * Created: 2/13/2023 1:16:31 PM
 *  Author: fawzy
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

/*to choose the time that to reset micro*/
#define     WDT_RESSET_AFTER13ms                0
#define     WDT_RESSET_AFTER32ms                1
#define 	WDT_RESSET_AFTER65ms				2
#define 	WDT_RESSET_AFTER130ms				3
#define 	WDT_RESSET_AFTER260ms				4
#define 	WDT_RESSET_AFTER520ms				5
#define 	WDT_RESSET_AFTER1000ms				6
#define	    WDT_RESSET_AFTER2100ms 				7

 

void WDT_voidSleep(U8 copy_SleepTime);
void WDT_VoidEnable(void);
void WDT_VoidDisable(void);




#endif /* WDT_INTERFACE_H_ */