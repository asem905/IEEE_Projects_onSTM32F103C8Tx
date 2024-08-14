/*
 * GPIO_program.c
 *
 *  Created on: Aug 8, 2024
 *      Author: Asem
 */
#include "GPIO_interface.h"


void GPIO_init(GPIO_config_t* config){
	GPIO_REGDEF_T *gpiox;
	switch(config->port){
	case PORTA:
		gpiox=GPIOA;
		break;
	case PORTB:
		gpiox=GPIOB;
		break;
	case PORTC:
		gpiox=GPIOC;
		break;
	case PORTD:
		gpiox=GPIOD;
		break;
	case PORTE:
		gpiox=GPIOE;
		break;

	}
	if(config->pin_num <PIN8){
		if(config->mode <3){//for input mode
			gpiox->CRL &= ~(0b11 << 4* config->pin_num);//4 as in reference manual pin num mode of pin 1 is at position bit4and so on
			if(config->pull_type == GPIO_PULLDOWN){
				gpiox->ODR &= ~(1<<config->pin_num);
			}else if(config->pull_type == GPIO_PULLUP){
				gpiox->ODR |= (1<<config->pin_num);
			}
		}else{//for output mode
			gpiox->CRL &= ~(0b11 << 4* config->pin_num);
			gpiox->CRL |= (config->speed << 4* config->pin_num);
		}
		gpiox->CRL &= ~(0b11 << (4* config->pin_num +2));//yo clear bits of configuration
		gpiox->CRL |= (config->mode << (4* config->pin_num +2));

	}else{
		if(config->mode <3){//for input mode
			gpiox->CRL &= ~(0b11 << 4* (config->pin_num -8));//4 as in reference manual pin num mode of pin 1 is at position bit4and so on
			if(config->pull_type == GPIO_PULLDOWN){
				gpiox->ODR &= ~(1<<config->pin_num);
			}else if(config->pull_type == GPIO_PULLUP){
				gpiox->ODR |= (1<<config->pin_num);
			}
		}else{//for output mode
			gpiox->CRL &= ~(0b11 << 4* (config->pin_num -8));
			gpiox->CRL |= (config->speed << 4* (config->pin_num -8));
		}
		gpiox->CRL &= ~(0b11 << (4* (config->pin_num -8) +2));//yo clear bits of configuration
		gpiox->CRL |= (config->mode << (4* (config->pin_num -8) +2));
	}
}
void GPIO_read_pin(GPIO_config_t* config){
	GPIO_REGDEF_T *gpiox;
	switch(config->port){
		case PORTA:
			gpiox=GPIOA;
			break;
		case PORTB:
			gpiox=GPIOB;
			break;
		case PORTC:
			gpiox=GPIOC;
			break;
		case PORTD:
			gpiox=GPIOD;
			break;
		case PORTE:
			gpiox=GPIOE;
			break;
	}
	config->pin_logic = ((gpiox->IDR & (1 << config->pin_num))?GPIOX_PIN_LOGIC_HIGH:GPIOX_PIN_LOGIC_LOW);
}
void GPIO_write_pin(GPIO_config_t* config){
	GPIO_REGDEF_T *gpiox;
	switch(config->port){
		case PORTA:
			gpiox=GPIOA;
			break;
		case PORTB:
			gpiox=GPIOB;
			break;
		case PORTC:
			gpiox=GPIOC;
			break;
		case PORTD:
			gpiox=GPIOD;
			break;
		case PORTE:
			gpiox=GPIOE;
			break;
	}
	if(config->pin_logic == GPIOX_PIN_LOGIC_HIGH){
			gpiox->BSRR = (1<<config->pin_num);//unselected bit will not be modified as it is atomic register so it modifies selected bit in one cycle only with no effect on other bits
	}else if(config->pin_logic == GPIOX_PIN_LOGIC_LOW){
			gpiox->BSRR = (1<<(config->pin_num+16));
	}else{

	}


}
