/*
 * SPI_PROGRAM.c
 *
 * Created: 3/24/2023 12:07:29 AM
 *  Author: fawzy
 */ 

#include "STD_TYPES.h"
#include "utilities.h"
#include "SPI_CONFIG.h"
#include "SPI_INTERFACE.h"
#include "SPI_PRIVATE.h"
#include "SPI_REG.h"

void SPI_VoidInitMaster(void)
{
	/*init master*/
	setbit(SPCR, SPCR_MSTR);
	
	/*prescaler :divide by 16*/
	setbit(SPCR , SPCR_SPR0);
	clearbit(SPCR , SPCR_SPR1);
	clearbit(SPSR , SPSR_SPI2X);
	
	/*SPI ENABLE*/
	setbit(SPCR , SPCR_SPE);
	
}
void SPI_VoidInitSlave(void)
{
	/*init SLAVE*/
	clearbit(SPCR, SPCR_MSTR);
	
	/*SPI ENABLE*/
	setbit(SPCR , SPCR_SPE);
	
}
U8 SPI_U8Transceive(U8 copy_U8data)
{
	/*SEND DATA*/
	SPDR = copy_U8data ; 
	
	/*busy waiting until transfer complete */
	while(readbit(SPSR , SPSR_SPIF)==0);
	
	/*get the exchanged data */
	return SPDR ;
	
}
