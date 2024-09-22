/*
 * EXTI_program.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Asem
 */

#include "EXTI_interface.h"
/*for Hardware enable functions and edge triggering*/
void (*EXTI_line_callbacks[19])(void);


void EXTI_VoidHardwareInterruptEnable(uint8_t line_num,uint8_t edge_detection){
	if((line_num<=19) && (line_num>=0)){
		EXTI->IMR |= 1<<line_num;
		if(edge_detection == RISING_EDGE_DETECTION){
			EXTI->RTSR |= 1<<line_num;
		}else if(edge_detection == FALLING_EDGE_DETECTION){
			EXTI->FTSR |= 1<<line_num;
		}else if (edge_detection==EDGE_CHANGE){
			EXTI->RTSR |= 1<<line_num;
			EXTI->FTSR |= 1<<line_num;
		}else{
			return ;
		}
	}else{
		return;
	}
}
void EXTI_VoidHardwareEventEnable(uint8_t line_num,uint8_t edge_detection){
	if((line_num<=19) && (line_num>=0)){
		EXTI->EMR |= 1<<line_num;
		if(edge_detection == RISING_EDGE_DETECTION){
			EXTI->RTSR |= 1<<line_num;
		}else if(edge_detection == FALLING_EDGE_DETECTION){
			EXTI->FTSR |= 1<<line_num;
		}else if (edge_detection==EDGE_CHANGE){
			EXTI->RTSR |= 1<<line_num;
			EXTI->FTSR |= 1<<line_num;
		}else{
			return;
		}
	}else{
		return;
	}
}
/*for Software enable functions and edge triggering**/
void EXTI_VoidSoftwareInterruptMask(uint8_t line_num){
	if((line_num<=19) && (line_num>=0)){
			EXTI->IMR |= 1<<line_num;
			EXTI->SWIER |=1<<line_num;
	}else{
		return;
	}
}
void EXTI_VoidSoftwareEventMask(uint8_t line_num){
	if((line_num<=19) && (line_num>=0)){
				EXTI->EMR |= 1<<line_num;
				EXTI->SWIER |=1<<line_num;
	}else{
		return;
	}
}
/*set callback*/
void EXTI_VoidSetCallbackFunction(uint8_t line_num,void (*ptr)(void)){
	EXTI_line_callbacks[line_num]=ptr;
}
void EXTI0_IRQHandler(){
	if(EXTI_line_callbacks[0]){
		EXTI_line_callbacks[0]();
		EXTI->PR |= (1<<0);
	}
}
void EXTI1_IRQHandler(){
	if(EXTI_line_callbacks[1]){
		EXTI_line_callbacks[1]();
		EXTI->PR |= (1<<1);
	}
}
void EXTI2_IRQHandler(){
	if(EXTI_line_callbacks[2]){
		EXTI_line_callbacks[2]();
		EXTI->PR |= (1<<2);
	}
}
void EXTI3_IRQHandler(){
	if(EXTI_line_callbacks[3]){
		EXTI_line_callbacks[3]();
		EXTI->PR |= (1<<3);
	}
}
void EXTI4_IRQHandler(){
	if(EXTI_line_callbacks[4]){
		EXTI_line_callbacks[4]();
		EXTI->PR |= (1<<4);
	}
}

void EXTI9_5_IRQHandler(){
	for(int i=5;i<11;i++){
		if( (EXTI->PR) & (1<<i) ){
			if(EXTI_line_callbacks[i]){
				EXTI_line_callbacks[i]();
				EXTI->PR |= (1<<(i));
			}
		}
	}
}
void EXTI15_10_IRQHandler(){
	for(int i=10;i<16;i++){
		if( (EXTI->PR) & (1<<i) ){
			if(EXTI_line_callbacks[i]){
				EXTI_line_callbacks[i]();
				EXTI->PR |= (1<<(i));
			}
		}
	}
}
