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

U16 mapping (U8 x1_input, U8 y1_output , U16 x2_input, U8 y2_output, U16 x_value);





#endif /* ADC_INTERFACE_H_ */