/*
 * NVIC_interface.h
 *
 *  Created on: Sep 3, 2024
 *      Author: Asem
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_registers.h"
/*---------------macros section------------------*/

/*---------------data type section------------------*/
typedef enum{
	WWDG_IRQn,
	PVD_IRQn,
	TAMPER_IRQn,
	RTC_IRQn,
	FLASH_IRQn,
	RCC_IRQn,
	EXTI0_IRQn,
	EXTI1_IRQn,
	EXTI2_IRQn,
	EXTI3_IRQn,
	EXTI4_IRQn,
	DMA1_Channel1_IRQn,
	DMA1_Channel2_IRQn,
	DMA1_Channel3_IRQn,
	DMA1_Channel4_IRQn,
	DMA1_Channel5_IRQn,
	DMA1_Channel6_IRQn,
	DMA1_Channel7_IRQn,
	ADC1_2_IRQn,
	CAN1_TX_IRQn,
	CAN1_RX0_IRQn,
	CAN1_RX1_IRQn,
	CAN1_SCE_IRQn,
	EXTI9_5_IRQn,
	TIM1_BRK_IRQn,
	TIM1_IRQn_UP,
	TIM1_TRG_COM_IRQn,
	TIM1_CC_IRQn,
	TIM2_IRQn,
	TIM3_IRQn,
	TIM4_IRQn,
	I2C1_EV_IRQn,
	I2C1_ER_IRQn,
	I2C2_EV_IRQn,
	I2C2_ER_IRQn,
	SPI1_IRQn,
	SPI2_IRQn,
	USART1_IRQn,
	USART2_IRQn,
	USART3_IRQn,
	EXTI15_10_IRQn,
	RTC_Alarm_IRQn,
	OTG_FS_WKUP_IRQn,

	TIM5_IRQn=50,
	SPI3_IRQn,
	USART4_IRQn,
	USART5_IRQn,
	TIM6_IRQn,
	TIM7_IRQn,
	DMA2_Channel1_IRQn,
	DMA2_Channel2_IRQn,
	DMA2_Channel3_IRQn,
	DMA2_Channel4_IRQn,
	DMA2_Channel5_IRQn,
	ETH_IRQn,
	ETH_WKUP_IRQn,
	CAN2_TX_IRQn,
	CAN2_RX0_IRQn,
	CAN2_RX1_IRQn,
	CAN2_SCE_IRQn,
	OTG_FS_IRQn
}IRQn_t;
/*---------------functions section------------------*/
void NVIC_EnableIRQ(IRQn_t IRQn);
void NVIC_DisableIRQ(IRQn_t IRQn);
uint8_t NVIC_GetPendingIRQ (IRQn_t IRQn);
void NVIC_SetPendingIRQ (IRQn_t IRQn);
void NVIC_ClearPendingIRQ (IRQn_t IRQn);
uint8_t NVIC_GetActive (IRQn_t IRQn);
void NVIC_SetPriority (IRQn_t IRQn, uint8_t priority);
uint8_t NVIC_GetPriority (IRQn_t IRQn);
#endif /* NVIC_INTERFACE_H_ */
