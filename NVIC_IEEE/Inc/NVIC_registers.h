/*
 * NVIC_registers.h
 *
 *  Created on: Sep 3, 2024
 *      Author: Asem
 */

#ifndef NVIC_REGISTERS_H_
#define NVIC_REGISTERS_H_
/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*---------------macros section------------------*/
#define NVIC_BASE_ADDR		  0xE000E100
#define NVIC                  ((NVIC_REGDEF_T*)NVIC_BASE_ADDR)
/*---------------data type section------------------*/
typedef volatile struct {
	volatile uint32_t ISER[3];
	volatile uint32_t reserved1[29];
	volatile uint32_t ICER[3];
	volatile uint32_t reserved2[29];
	volatile uint32_t ISPR[3];
	volatile uint32_t reserved3[29];
	volatile uint32_t ICPR[3];
	volatile uint32_t reserved4[29];
	volatile uint32_t IAPR[3];
	volatile uint32_t reserved5[61];
	volatile uint8_t IPR[84];
	volatile uint32_t reserved6[696];
	volatile uint32_t STIR;
}NVIC_REGDEF_T;

/*---------------functions section------------------*/


#endif /* NVIC_REGISTERS_H_ */
