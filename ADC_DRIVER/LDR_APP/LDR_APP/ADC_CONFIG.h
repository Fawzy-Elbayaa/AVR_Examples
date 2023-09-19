/*
 * ADC_CONFIG.h
 *
 * Created: 8/6/2022 12:39:46 AM
 *  Author: fawzy
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*
   OPTIONS 1-INPUT_VOLTAGE_AREF    
		   2- INPUT_VOLTAGE_AVCC    
		   3- INPUT_VOLTAGE_INTERNAL
			                  */
#define   VOLTAGE_REFERNCE     INPUT_VOLTAGE_AVCC


   /*
   OPTIONS 1- ADC_RIGHT_ADJUST
           2- ADC_LEFT_ADJUST 
   */
#define   RESULT_ADC    ADC_LEFT_ADJUST 


/*   OPTIONS 1- Reading_10bit
              2- Reading_8bit

*/
#define   Reading_ADC    Reading_8bit

#define    PRESCALER_divide_by_2             0
#define    PRESCALER_divide_by_4             2
#define    PRESCALER_divide_by_8             3
#define    PRESCALER_divide_by_16            4
#define    PRESCALER_divide_by_32            5
#define    PRESCALER_divide_by_64            6
#define    PRESCALER_divide_by_128           7




#endif /* ADC_CONFIG_H_ */