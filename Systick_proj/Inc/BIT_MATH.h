/*
 * BIT_MATH.h
 *
 *  Created on: May 6, 2024
 *      Author: Asem
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define setbit(reg,bit_postn)  (reg |= (1<<bit_postn))
#define clearbit(reg,bit_postn)  (reg &= ~(1<<bit_postn))
#define togglebit(reg,bit_postn)  (reg ^= (1<<bit_postn))
#define readbit(reg,bit_postn)  ((reg >> bit_postn)&1)
#define SET_BYTE(reg,value)  (reg = value)
#define ROT_LEFT(reg,bit_postn)  ((reg<<bit_postn)|(reg >> (no_of_bits - bit_postn)))
#define ROT_RIGHT(reg,bit_postn)  ((reg>>bit_postn)|(reg << (no_of_bits - bit_postn)))

#endif /* BIT_MATH_H_ */
