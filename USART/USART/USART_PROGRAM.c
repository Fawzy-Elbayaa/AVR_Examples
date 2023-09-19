/*
 * USART_PROGRAM.c
 *
 * Created: 2/23/2023 6:30:33 PM
 *  Author: fawzy
 */ 
#include "STD_TYPES.h"
#include "utilities.h"
#include "USART_REG.h"
#include "USART_INTERFACE.h"
#include "USART_PRIVATE.h"
#include "USART_CONFIG.h"


void USART_VoidInit(void)
{
	U8 Local_u8UCSRCValue=0;
	setbit(Local_u8UCSRCValue , 7);  // to write on reg UCSRC 
	setbit(Local_u8UCSRCValue , UCSRC_UCSZ0);  //to choose data 8 bit mode
	setbit(Local_u8UCSRCValue , UCSRC_UCSZ1);  //to choose data 8 bit mode
	
	UCSRC = Local_u8UCSRCValue;
	
	UBRRL = 51;   //to choose baudrate 9600bit/sec when the clock 8mhz
	 
	setbit(UCSRB , UCSRB_TXEN);   //transmit enable
	setbit(UCSRB , UCSRB_RXEN);   //receive enable
	
	
}
void USART_VoidSend(U8 Copy_data)
{
	while(readbit(UCSRA , UCSRA_UDRE) == 0);  //wait until the transmit data is empty
	UDR = Copy_data;     //you must write on UDR to choose transmit data
	
	
}

U8 USART_U8Receive(void)
{
	while(readbit(UCSRA , UCSRA_RXC)==0);   // wait until the receive is complete
	return UDR;             //you must read the UDR to choose receive data
}