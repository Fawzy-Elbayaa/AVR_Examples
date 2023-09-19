/*
 * ADC_INTERFACE.h
 *
 * Created: 8/6/2022 12:38:59 AM
 *  Author: fawzy
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_VoidInit(void);


U8 ADC_U16StartConversionSync(U8 COPY_U8Channel , U16* reading);
U8 ADC_U16StartConversionASync(U8 COPY_U8Channel , U16* reading , void (*Copy_PvNotificationFunc)(void));

typedef struct
{
	U8 Channel;
	U16 Result;
	U8 Size;
	void (*NotificationFunc)(void);
	
}Chain_t;

U8 Adc_u8StartChainAsyn(Chain_t * Copy_Chain);
	
	



#endif /* ADC_INTERFACE_H_ */