/*
 * USART_REG.h
 *
 * Created: 2/23/2023 6:27:56 PM
 *  Author: fawzy
 */ 


#ifndef USART_REG_H_
#define USART_REG_H_

#define UDR                                 *((volatile U8 *)(0X2C))    //TO write or read data   

#define UCSRA                               *((volatile U8 *)(0X2B))    //Control and Status Register A
#define UCSRA_RXC                           7 // THE FLAG RECEIVE COMPLETE
#define UCSRA_TXC                           6 //The flag transmit complete
#define UCSRA_UDRE                          5 //THE Flag for data register is empty
#define UCSRA_FE                            4 // FRAME ERROR
#define UCSRA_DOR                           3 // data over run
#define UCSRA_PE                            2 //parity error
#define UCSRA_U2X                           1 //Double the USART Transmission Speed
#define UCSRA_MPCM                          0 //Multi-processor Communication Mode

#define  UCSRB                              *((volatile U8 *)(0X2A))    //Control and Status Register B
#define  UCSRB_RXCIE                        7  //: RX Complete Interrupt Enable
#define  UCSRB_TXCIE                        6  // TX Complete Interrupt Enable 
#define  UCSRB_UDRIE                        5  // USART Data Register Empty Interrupt Enable
#define  UCSRB_RXEN                         4  // Receiver Enable
#define  UCSRB_TXEN                         3  // Transmitter Enable
#define  UCSRB_UCSZ2                        2  // Character Size OF DATA (5 bit  or 6 or 7 or 8 or 9) with UCSZ1:0
#define  UCSRB_RXB8                         1  // Receive Data Bit 8 (RXB8 is the ninth data bit of the received)
#define  UCSRB_TXB8                         0  // Transmit Data Bit 8 (TXB8 is the ninth data bit in the character)

#define  UCSRC                              *((volatile U8 *)(0X40))    //Control and Status Register C
#define  UCSRC_URSEL                        7 // : Register Select
#define  UCSRC_UMSEL                        6 //USART Mode Selec
#define  UCSRC_UPM1                         5 // PARIT MODE 
#define  UCSRC_UPM0                         4  //pariy mode
#define  UCSRC_USBS                         3  // stop bit select 
#define  UCSRC_UCSZ1                        2  // data bit size
#define  UCSRC_UCSZ0                        1  //data bit size 
#define  UCSRC_UCPOL                        0  // clock polarity( it used synchronous only )

#define  UBRRH                              *((volatile U8 *)(0X40))    // Baud Rate Registers   
#define  UBRRL                              *((volatile U8 *)(0X29))    // Baud Rate Registers   




#endif /* USART_REG_H_ */