/*
 * GPIO_registers.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Asem
 */

#ifndef GPIO_REGISTERS_H_
#define GPIO_REGISTERS_H_
/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*---------------macros section------------------*/
#define GPIOA_BASE_ADDR        0x40010800
#define GPIOA                 ((GPIO_REGDEF_T*)GPIOA_BASE_ADDR)

#define GPIOB_BASE_ADDR        0x40010C00
#define GPIOB                 ((GPIO_REGDEF_T*)GPIOB_BASE_ADDR)

#define GPIOC_BASE_ADDR        0x40011000
#define GPIOC                 ((GPIO_REGDEF_T*)GPIOC_BASE_ADDR)

#define GPIOD_BASE_ADDR        0x40014000
#define GPIOD                 ((GPIO_REGDEF_T*)GPIOD_BASE_ADDR)

#define GPIOE_BASE_ADDR        0x40018000
#define GPIOE                 ((GPIO_REGDEF_T*)GPIOE_BASE_ADDR)
/*---------------data type section------------------*/
//volatile must be used to tell compiler that they would change
typedef struct {
    volatile uint32_t CRL;     // Clock control register
    volatile uint32_t CRH;   // Clock configuration register
    volatile uint32_t IDR;    // Clock interrupt register
    volatile uint32_t ODR; // APB2 peripheral reset register
    volatile uint32_t BSRR; // APB1 peripheral reset register
    volatile uint32_t BRR;  // AHB peripheral clock enable register
    volatile uint32_t LCKR; // APB2 peripheral clock enable register
} GPIO_REGDEF_T;


#endif /* GPIO_REGISTERS_H_ */
