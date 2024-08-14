/*
 * GPIO_interface.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Asem
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
/*---------------include section------------------*/
#include "GPIO_registers.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*---------------macros section------------------*/
/*input mode*/
#define GPIO_MODE_INPUT_FLOATING		ob01
#define GPIO_MODE_INPUT_PUSHPULL		0b01
#define GPIO_MODE_INPUT_ANALOG			0b10
/*output mode*/
#define GPIO_MODE_OUTPUT_OPENDRAIN		0b00
#define GPIO_MODE_OUTPUT_PUSHPULL		0b01
#define GPIO_MODE_ALTFN_PUSPULL			0b10
#define GPIO_MODE_ALTFN_OPENDRAIN		0b11

/*speed mode*/
#define GPIO_SPEED_2MHZ					0b10
#define GPIO_SPEED_10MHZ				0b01
#define GPIO_SPEED_50MHZ				0b11
/*pull type*/
#define GPIO_PULLDOWN					0
#define GPIO_PULLUP						1

/*pin logic*/
#define GPIOX_PIN_LOGIC_HIGH			1
#define GPIOX_PIN_LOGIC_LOW				0
/*---------------data type section------------------*/

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE
}GPIO_port_t;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
}GPIO_pin_num_t;
typedef struct {
	GPIO_port_t port;
	GPIO_pin_num_t pin_num;
	uint8_t mode;
	uint8_t speed;
	uint8_t pull_type;
	uint8_t pin_logic;
}GPIO_config_t;


/*---------------functions section------------------*/
void GPIO_init(GPIO_config_t* config);
void GPIO_read_pin(GPIO_config_t* config);
void GPIO_write_pin(GPIO_config_t* config);


#endif /* GPIO_INTERFACE_H_ */
