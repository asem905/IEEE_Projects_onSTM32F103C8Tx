/*
 * RCC_config.h
 *
 *  Created on: May 6, 2024
 *      Author: Asem
 */

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

/*---------------macros section------------------*/
#define RCC_HSI					0
#define RCC_HSE					1
#define RCC_PLL					2

#define SYSTIM_CLOCK			RCC_HSE
#define HSEBYP					0
#define PLL_CLOCK_SOURCE 		RCC_HSI
#define PLL_MULTIPLIER 			2
/*buses prescalers*/
#define AHB_PRESCALER_1				0b0000
#define AHB_PRESCALER_2				0b1000
#define AHB_PRESCALER_4				0b1001
#define AHB_PRESCALER_8				0b1010
#define AHB_PRESCALER_16			0b1011
#define AHB_PRESCALER_64			0b1100
#define AHB_PRESCALER_128			0b1101
#define AHB_PRESCALER_256			0b1110
#define AHB_PRESCALER_512			0b1111
#define AHB_PRESCALER 				AHB_PRESCALER_2

/*prescaler (APB)*/
#define APB_PRESCALER_1				0b000
#define APB_PRESCALER_2				0b100
#define APB_PRESCALER_4				0b101
#define APB_PRESCALER_8				0b110
#define APB_PRESCALER_16			0b111
#define APB1_PRESCALER 				APB_PRESCALER_2
#define APB2_PRESCALER 				APB_PRESCALER_2
/*prescaler (ADC)*/
#define ADC_PRESCALER_2				0b00
#define ADC_PRESCALER_4				0b01
#define ADC_PRESCALER_8				0b10
#define ADC_PRESCALER_16			0b11
#define ADC_PRESCALER 				ADC_PRESCALER_2
#endif /* RCC_RCC_CONFIG_H_ */
