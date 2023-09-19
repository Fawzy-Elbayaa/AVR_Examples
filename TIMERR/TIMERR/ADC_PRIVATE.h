/*
 * ADC_PRIVATE.h
 *
 * Created: 8/6/2022 12:38:35 AM
 *  Author: fawzy
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define  INPUT_VOLTAGE_AREF             0    
#define  INPUT_VOLTAGE_AVCC             1    
#define  INPUT_VOLTAGE_INTERNAL         3 // 2.56 VOLTE INTERNAL    

#define  ADC_RIGHT_ADJUST               0
#define  ADC_LEFT_ADJUST                1

#define  Mask_Prescaler                0b11111000

#define  Reading_10bit                  0
#define  Reading_8bit                   1


/*Analog Channel and Gain Selection Bits*/
#define  SINGLE_ENDED_INPUT_ADC0                                                    0b00000
#define  SINGLE_ENDED_INPUT_ADC1                                                    0b00001
#define  SINGLE_ENDED_INPUT_ADC2                                                    0b00010
#define  SINGLE_ENDED_INPUT_ADC3                                                    0b00011
#define  SINGLE_ENDED_INPUT_ADC4                                                    0b00100
#define  SINGLE_ENDED_INPUT_ADC5                                                    0b00101
#define  SINGLE_ENDED_INPUT_ADC6                                                    0b00110
#define  SINGLE_ENDED_INPUT_ADC7                                                    0b00111
#define  DIFFERENTIAL_INPUT_ADC0_POSITIVE_ADC0_NEGATIVE_GAIN_10X                    0b01000
#define  DIFFERENTIAL_INPUT_ADC1_POSITIVE_ADC0_NEGATIVE_GAIN_10X                    0b01001
#define  DIFFERENTIAL_INPUT_ADC0_POSITIVE_ADC0_NEGATIVE_GAIN_200X                   0b01010
#define  DIFFERENTIAL_INPUT_ADC1_POSITIVE_ADC0_NEGATIVE_GAIN_200X                   0b01011
#define  DIFFERENTIAL_INPUT_ADC2_POSITIVE_ADC2_NEGATIVE_GAIN_10X                    0b01100
#define  DIFFERENTIAL_INPUT_ADC3_POSITIVE_ADC2_NEGATIVE_GAIN_10X                    0b01101
#define  DIFFERENTIAL_INPUT_ADC2_POSITIVE_ADC2_NEGATIVE_GAIN_200X                   0b01110
#define  DIFFERENTIAL_INPUT_ADC3_POSITIVE_ADC2_NEGATIVE_GAIN_200X                   0b01111
#define  DIFFERENTIAL_INPUT_ADC0_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10000
#define  DIFFERENTIAL_INPUT_ADC1_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10001
#define  DIFFERENTIAL_INPUT_ADC2_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10010
#define  DIFFERENTIAL_INPUT_ADC3_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10011
#define  DIFFERENTIAL_INPUT_ADC4_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10100
#define  DIFFERENTIAL_INPUT_ADC5_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10101
#define  DIFFERENTIAL_INPUT_ADC6_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10110
#define  DIFFERENTIAL_INPUT_ADC7_POSITIVE_ADC1_NEGATIVE_GAIN_1X                    0b10111
#define  DIFFERENTIAL_INPUT_ADC0_POSITIVE_ADC2_NEGATIVE_GAIN_1X                    0b11000
#define  DIFFERENTIAL_INPUT_ADC1_POSITIVE_ADC2_NEGATIVE_GAIN_1X                    0b11001
#define  DIFFERENTIAL_INPUT_ADC2_POSITIVE_ADC2_NEGATIVE_GAIN_1X                    0b11010
#define  DIFFERENTIAL_INPUT_ADC3_POSITIVE_ADC2_NEGATIVE_GAIN_1X                    0b11011
#define  DIFFERENTIAL_INPUT_ADC4_POSITIVE_ADC2_NEGATIVE_GAIN_1X                    0b11100
#define  DIFFERENTIAL_INPUT_ADC5_POSITIVE_ADC2_NEGATIVE_GAIN_1X                    0b11101

#define  SINGLE_ENDED_INPUT_VBG                                                    0b11110
#define  SINGLE_ENDED_INPUT_GND                                                    0b11111


#define  MASK_Mux_Channel          0b11100000

#define  ADC_u32TIMEOUT                  50000

#define  IDEAL                       1
#define  BUSY                        0
#define  BUSYFUNC                    0
        


#endif /* ADC_PRIVATE_H_ */