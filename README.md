RCC and GPIO Programs
RCC Program
Overview
This section covers the code for configuring and managing the Reset and Clock Control (RCC) peripheral of STM32 microcontrollers. The RCC_program.c file provides functions to initialize the RCC, configure the system clock, and enable or disable peripherals.

Files
RCC_program.c: Contains the implementation of RCC initialization, peripheral enable/disable functions.
RCC_registers.h: Defines the RCC register structure and base address.
RCC Initialization
The RCC_init() function configures the system clock source and AHB prescaler. The clock source can be selected from HSI (High-Speed Internal), HSE (High-Speed External), or PLL (Phase-Locked Loop).

Configuration
Modify the following macros in RCC_interface.h to match your system configuration:

SYSTIM_CLOCK: Select the clock source (RCC_HSI, RCC_HSE, or RCC_PLL).
HSEBYP: HSE bypass configuration bit.
PLL_CLOCK_SOURCE: Configuration for the PLL clock source.
AHB_PRESCALER: Value for the AHB prescaler.
Function Descriptions
void RCC_init(void)
Initializes the RCC according to the selected clock source:

HSI: Enables HSI, waits for it to be ready, and sets it as the system clock source.
HSE: Configures HSE bypass, enables HSE, waits for it to be ready, and sets it as the system clock source.
PLL: Configures PLL source, enables PLL, waits for it to be ready, and sets it as the system clock source.
Sets the AHB prescaler according to the defined value.

void RCC_Peripheralenable(uint32_t peripheral)
Enables the specified peripheral by setting the appropriate bit in the APB1 peripheral clock enable register.

Parameters:

peripheral: Peripheral identifier (e.g., RCC_APB1ENR_TIM2EN).
void RCC_Peripheraldisable(uint32_t peripheral)
Disables the specified peripheral by clearing the appropriate bit in the APB1 peripheral clock enable register.

Parameters:

peripheral: Peripheral identifier (e.g., RCC_APB1ENR_TIM2EN).
Example Usage
c
Copy code
#include "RCC_interface.h"

// Configure RCC to use HSI
SYSTIM_CLOCK = RCC_HSI;
RCC_init(); // Initialize RCC

// Enable a specific peripheral
RCC_Peripheralenable(RCC_APB1ENR_TIM2EN);

// Disable a specific peripheral
RCC_Peripheraldisable(RCC_APB1ENR_TIM2EN);
GPIO Program
Overview
This section covers the code for configuring and manipulating GPIO (General Purpose Input/Output) pins on STM32 microcontrollers. The GPIO_program.c file provides functions to initialize GPIO pins, read their states, and write values to them.

Files
GPIO_program.c: Contains the implementation of GPIO initialization, reading, and writing functions.
GPIO_interface.h: Defines the necessary GPIO configuration structures and constants.
GPIO_registers.h: Defines the GPIO registers.
Function Descriptions
void GPIO_init(GPIO_config_t* config)
Initializes a GPIO pin according to the specified configuration.

Parameters:

config: A pointer to a GPIO_config_t structure with the following fields:
port: GPIO port (e.g., PORTA, PORTB, etc.).
pin_num: The pin number to be configured (0-15).
mode: Operating mode of the pin (input or output).
speed: Speed of the pin if in output mode.
pull_type: Pull-up or pull-down resistor configuration.
Details:

Configures the pin as an input or output.
Sets pull-up or pull-down resistors if configured as input.
Configures pin speed if configured as output.
void GPIO_read_pin(GPIO_config_t* config)
Reads the current logic level of a specified GPIO pin.

Parameters:

config: A pointer to a GPIO_config_t structure with:
port: GPIO port (e.g., PORTA, PORTB, etc.).
pin_num: The pin number to be read.
pin_logic: Output parameter to store the read logic level (high or low).
Details:

Reads the pin state from the input data register (IDR) and updates the pin_logic field in the config structure.
void GPIO_write_pin(GPIO_config_t* config)
Writes a logic level to a specified GPIO pin.

Parameters:

config: A pointer to a GPIO_config_t structure with:
port: GPIO port (e.g., PORTA, PORTB, etc.).
pin_num: The pin number to be written to.
pin_logic: Logic level to write (high or low).
Details:

Uses the BSRR (Bit Set/Reset Register) to set or reset the pin.
The BSRR register is atomic, meaning that setting or resetting a bit does not affect other bits in the register.
Example Usage
c
Copy code
#include "GPIO_interface.h"

// Initialize GPIO pin 5 on port A as output
GPIO_config_t gpio_config;
gpio_config.port = PORTA;
gpio_config.pin_num = 5;
gpio_config.mode = GPIO_MODE_OUTPUT;
gpio_config.speed = GPIO_SPEED_MEDIUM;
gpio_config.pull_type = GPIO_NOPULL;

GPIO_init(&gpio_config);

// Set GPIO pin 5 high
gpio_config.pin_logic = GPIOX_PIN_LOGIC_HIGH;
GPIO_write_pin(&gpio_config);

// Read GPIO pin 5 state
GPIO_read_pin(&gpio_config);
if (gpio_config.pin_logic == GPIOX_PIN_LOGIC_HIGH) {
    // Pin is high
} else {
    // Pin is low
}
