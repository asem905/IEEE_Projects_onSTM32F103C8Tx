/*
 * Systick_interface.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Asem
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_
/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Systick_register.h"
#include "Systick_config.h"
/*---------------macros section------------------*/


/*---------------data type section------------------*/


/*---------------functions declarations---------------*/
void Systick_init();
void Systick_delay_milliseconds(uint32_t ms);
void Systick_delay_microseconds(uint32_t us);
int Systick_get_elapsed_time();
int Systick_remaining_time();
void Systick_enable_inrterrupt();
void Systick_start_count_millisecondsIT(uint32_t ms,void (*ptr)(void));
void Systick_start_count_microsecondsIT(uint32_t us,void (*ptr)(void));
#endif /* SYSTICK_INTERFACE_H_ */
