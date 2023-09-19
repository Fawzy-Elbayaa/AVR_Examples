/*
 * SPI_INTERFACE.h
 *
 * Created: 3/24/2023 12:06:19 AM
 *  Author: fawzy
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_VoidInitMaster(void);
void SPI_VoidInitSlave(void);
U8 SPI_U8Transceive(U8 copy_U8data);





#endif /* SPI_INTERFACE_H_ */