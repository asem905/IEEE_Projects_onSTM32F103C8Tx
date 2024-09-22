/*
 * EXTI_registers.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Asem
 */

#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_
/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*---------------macros section------------------*/
#define EXTI_BASE_ADDR		  0x40010400
#define EXTI                  ((EXTI_REGDEF_T*)EXTI_BASE_ADDR)
/*---------------data type section------------------*/

/*---------------functions section------------------*/
typedef volatile struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_REGDEF_T;

#endif /* EXTI_REGISTERS_H_ */
