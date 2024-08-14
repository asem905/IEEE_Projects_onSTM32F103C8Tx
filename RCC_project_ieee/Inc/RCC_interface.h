/*
 * RCC_interface.h:interface file with user
 *
 *  Created on: May 6, 2024
 *      Author: Asem
 */

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_
/*---------------include section------------------*/
#include "RCC_registers.h"
#include "RCC_config.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*---------------macros section------------------*/

/*---------------data type section------------------*/
typedef enum {
	RCC_GPIOA_EN,
	RCC_GPIOB_EN,
	RCC_GPIOC_EN,
	RCC_GPIOD_EN,
	RCC_GPIOE_EN,
	RCC_ADC1_EN,
	RCC_ADC2_EN,
	RCC_TIM1_EN,
	RCC_SPI_EN,
	RCC_USART_EN
}peripheral_t;
/*---------------functions section------------------*/
void RCC_init();
void RCC_Peripheralenable(peripheral_t per);
void RCC_Peripheraldisable(peripheral_t per);
#endif /* RCC_RCC_INTERFACE_H_ */
