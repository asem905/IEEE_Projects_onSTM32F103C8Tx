/*
 * Systick_config.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Asem
 */

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*---------------macros section------------------*/
#define SYSTICK_AHB_DIVD1 					1
#define SYSTICK_AHB_DIVD8					0
#define SYSTICK_CLOCK_SOURCE				SYSTICK_AHB_DIVD1
#define SYSTEM_CLOCK						16//in MHZ

#define SYSTICK_INTERRUPT_PERIODIC			0
#define SYSTICK_INTERRUPT_NONPERIODIC		1

#define SYSTICK_INTERRUPT					SYSTICK_INTERRUPT_NONPERIODIC

#define MAX_SYSTICK_LOAD  					0xFFFFFF
#endif /* SYSTICK_CONFIG_H_ */
