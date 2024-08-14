/*
 * RCC_program.c
 *
 *  Created on: May 6, 2024
 *  Author: Assem Samy
 */

#include "RCC_interface.h"
void RCC_init() {
#if SYSTIM_CLOCK == RCC_HSI
    // Turn on HSI clock
    RCC->CR |= (1 << 0);
    // Wait until HSI is ready
    while ((RCC->CR & (1 << 1)) == 0); // Check if HSIRDY bit is set
    // Set HSI as system clock source
    RCC->CFGR &= ~(0b11 << 0);  // Clear SW bits
    RCC->CFGR |= (0b00 << 0);   // Set HSI as system clock source

#elif SYSTIM_CLOCK == RCC_HSE
    // Configure HSE bypass if needed
    RCC->CR |= (HSEBYP << 18);
    // Turn on HSE clock
    RCC->CR |= (1 << 16);
    // Wait until HSE is ready
    while ((RCC->CR & (1 << 17)) == 0); // Check if HSERDY bit is set
    // Set HSE as system clock source
    RCC->CFGR &= ~(0b11 << 0);  // Clear SW bits
    RCC->CFGR |= (0b01 << 0);   // Set HSE as system clock source

#elif SYSTIM_CLOCK == RCC_PLL
    // Configure PLL source
    RCC->CFGR |= (PLL_CLOCK_SOURCE << 16);
    // Turn on PLL
    RCC->CR |= (1 << 24);
    // Wait until PLL is ready
    while ((RCC->CR & (1 << 25)) == 0); // Check if PLLRDY bit is set
    // Set PLL as system clock source
    RCC->CFGR &= ~(0b11 << 0);  // Clear SW bits
    RCC->CFGR |= (0b10 << 0);   // Set PLL as system clock source

#else
    #error "Invalid SYSTIM_CLOCK setting"
#endif

    // Wait until the system clock source is correctly set
    while ((RCC->CFGR & (0b11 << 2)) != (RCC->CFGR & 0b11));

    // Configure AHB prescaler
    RCC->CFGR &= ~(0b1111 << 4);    // Clear AHB prescaler bits
    RCC->CFGR |= (AHB_PRESCALER << 4); // Set AHB prescaler value
    // Configure APP1 prescaler
    RCC->CFGR &= ~(0b111 << 8);    // Clear AHB prescaler bits
    RCC->CFGR |= (APB1_PRESCALER << 8); // Set AHB prescaler value
    // Configure APP2 prescaler
    RCC->CFGR &= ~(0b111 << 11);    // Clear AHB prescaler bits
    RCC->CFGR |= (APB2_PRESCALER << 11); // Set AHB prescaler value
}

void RCC_Peripheralenable(peripheral_t per) {
	switch(per){
		case RCC_GPIOA_EN:
			RCC->APB2ENR |= (1<<2);
			break;
		case RCC_GPIOB_EN:
			RCC->APB2ENR |= (1<<3);
			break;
		case RCC_GPIOC_EN:
			RCC->APB2ENR |= (1<<4);
			break;
		case RCC_GPIOD_EN:
			RCC->APB2ENR |= (1<<5);
			break;
		case RCC_GPIOE_EN:
			RCC->APB2ENR |= (1<<6);
			break;
		case RCC_ADC1_EN:
			RCC->APB2ENR |= (1<<9);
			break;
		case RCC_ADC2_EN:
			RCC->APB2ENR |= (1<<10);
			break;
		case RCC_TIM1_EN:
			RCC->APB2ENR |= (1<<11);
			break;
		case RCC_SPI_EN:
			RCC->APB2ENR |= (1<<12);
			break;
		case RCC_USART_EN:
			RCC->APB2ENR |= (1<<14);
			break;
	}
}

void RCC_Peripheraldisable(peripheral_t per) {
	switch(per){
		case RCC_GPIOA_EN:
			RCC->APB2ENR |= ~(1<<2);
			break;
		case RCC_GPIOB_EN:
			RCC->APB2ENR |= ~(1<<3);
			break;
		case RCC_GPIOC_EN:
			RCC->APB2ENR |= ~(1<<4);
			break;
		case RCC_GPIOD_EN:
			RCC->APB2ENR |= ~(1<<5);
			break;
		case RCC_GPIOE_EN:
			RCC->APB2ENR |= ~(1<<6);
			break;
		case RCC_ADC1_EN:
			RCC->APB2ENR |= ~(1<<9);
			break;
		case RCC_ADC2_EN:
			RCC->APB2ENR |= ~(1<<10);
			break;
		case RCC_TIM1_EN:
			RCC->APB2ENR |= ~(1<<11);
			break;
		case RCC_SPI_EN:
			RCC->APB2ENR |= ~(1<<12);
			break;
		case RCC_USART_EN:
			RCC->APB2ENR |= ~(1<<14);
			break;
		}
}
