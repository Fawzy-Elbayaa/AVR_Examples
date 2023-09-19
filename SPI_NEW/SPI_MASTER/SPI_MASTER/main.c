/*/
 * SPI_MASTER.c
 *
 * Created: 3/24/2023 4:19:26 AM
 * Author : fawzy
 */ 

#define  F_CPU   8000000

#include "STD_TYPES.h"
#include <util/delay.h>
#include "utilities.h"
#include "memory_map.h"
#include "port_config.h"
#include "GPIO.h"
#include "SPI_INTERFACE.h"



int main(void)
{
	direction_and_port_init();
	SPI_VoidInitMaster();
	
	/* Replace with your application code */
	while (1)
	{
		SPI_U8Transceive(1);
		_delay_ms(10);
	}
}

