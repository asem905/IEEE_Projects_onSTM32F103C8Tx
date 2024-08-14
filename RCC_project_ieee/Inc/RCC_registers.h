/*
 * RCC_registers.h
 *
 *  Created on: May 6, 2024
 *      Author: Asem
 */

#ifndef RCC_RCC_REGISTERS_H_
#define RCC_RCC_REGISTERS_H_

/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*---------------macros section------------------*/
#define RCC_BASE_ADDR        0x40021000
#define RCC                  ((RCC_REGDEF_T*)RCC_BASE_ADDR)

/*---------------data type section------------------*/
//volatile must be used to tell compiler that they would change
typedef struct {
    volatile uint32_t CR;     // Clock control register
    volatile uint32_t CFGR;   // Clock configuration register
    volatile uint32_t CIR;    // Clock interrupt register
    volatile uint32_t APB2RSTR; // APB2 peripheral reset register
    volatile uint32_t APB1RSTR; // APB1 peripheral reset register
    volatile uint32_t AHBENR;  // AHB peripheral clock enable register
    volatile uint32_t APB2ENR; // APB2 peripheral clock enable register
    volatile uint32_t APB1ENR; // APB1 peripheral clock enable register
    volatile uint32_t BDCR;    // Backup domain control register
    volatile uint32_t CSR;     // Control/status register
} RCC_REGDEF_T;

#endif /* RCC_RCC_REGISTERS_H_ */
