/*
 * NVIC_program.c
 *
 *  Created on: Sep 3, 2024
 *      Author: Asem
 */
#include "NVIC_interface.h"

void NVIC_EnableIRQ(IRQn_t IRQn){
	if(IRQn<0){
			return ;
	}
	NVIC->ISER[IRQn/32] |= (uint32_t)(1<<(IRQn%32));
}
void NVIC_DisableIRQ(IRQn_t IRQn){
	if(IRQn<0){
		return ;
	}
	NVIC->ICER[IRQn/32] |= (uint32_t)(1<<(IRQn%32));
}
uint8_t NVIC_GetPendingIRQ(IRQn_t IRQn) {
    if (IRQn < 0) {
        return FALSE;
    }
    return (NVIC->ISPR[IRQn / 32] & (1 << (IRQn % 32))) ? TRUE : FALSE;
}

void NVIC_SetPendingIRQ (IRQn_t IRQn){
	if(IRQn<0){
		return ;
	}
	NVIC->ISPR[IRQn/32] |= (uint32_t)(1<<(IRQn%32));
}
void NVIC_ClearPendingIRQ(IRQn_t IRQn) {
    if (IRQn < 0) {
        return;
    }
    NVIC->ICPR[IRQn / 32] |= (uint32_t)(1 << (IRQn % 32));
}

uint8_t NVIC_GetActive(IRQn_t IRQn) {
    if((NVIC->IAPR[IRQn / 32] & (1 << (IRQn % 32)))){
    	return IRQn;
    }
}
void NVIC_SetPriority(IRQn_t IRQn, uint8_t priority) {
    if (IRQn < 0) {
        return;
    }
    NVIC->IPR[IRQn] = (uint8_t)(priority << 4);
}

uint8_t NVIC_GetPriority(IRQn_t IRQn) {
    return (NVIC->IPR[IRQn] >> 4) & 0x0F; // Assumes 4-bit priority
}

