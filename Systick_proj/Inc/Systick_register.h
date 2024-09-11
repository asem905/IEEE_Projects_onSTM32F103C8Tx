/*
 * Systick_register.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Asem
 */

#ifndef SYSTICK_REGISTER_H_
#define SYSTICK_REGISTER_H_

/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*---------------macros section------------------*/
#define SYSTICK_BASE_ADDR        0xE000E010
#define SYSTICK                 ((SYSTICK_REGDEF_T*)SYSTICK_BASE_ADDR)

/*---------------data type section------------------*/
//volatile must be used to tell compiler that they would change
typedef struct {
    volatile uint32_t CTRL;     // Clock control register
    volatile uint32_t LOAD;   // Clock configuration register
    volatile uint32_t VAL;    // Clock interrupt register
    volatile uint32_t CALIB; // APB2 peripheral reset register
} SYSTICK_REGDEF_T;

#endif /* SYSTICK_REGISTER_H_ */
