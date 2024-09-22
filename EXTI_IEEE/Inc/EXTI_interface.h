/*
 * EXTI_interface.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Asem
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/*---------------include section------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_registers.h"
/*---------------macros section------------------*/
#define RISING_EDGE_DETECTION			1
#define FALLING_EDGE_DETECTION			0
#define EDGE_CHANGE						2
/*---------------data type section------------------*/

/*---------------functions section------------------*/
/*for Hardware enable functions and edge triggering*/
void EXTI_VoidHardwareInterruptEnable(uint8_t line_num,uint8_t edge_detection);
void EXTI_VoidHardwareEventEnable(uint8_t line_num,uint8_t edge_detection);
/*for Software enable functions and edge triggering**/
void EXTI_VoidSoftwareInterruptMask(uint8_t line_num);
void EXTI_VoidSoftwareEventMask(uint8_t line_num);
/*set callbacks fo array of pointer to functions of isrs*/
void EXTI_VoidSetCallbackFunction(uint8_t line_num,void (*ptr)(void));
#endif /* EXTI_INTERFACE_H_ */
