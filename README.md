


# STM32F103C8T6 Microcontroller Programs

This repository contains code for various peripherals and functionalities on STM32 microcontrollers. It includes programs for configuring and managing the RCC (Reset and Clock Control), GPIO (General Purpose Input/Output), SysTick timer, and NVIC (Nested Vectored Interrupt Controller) peripherals.

## RCC Program

### Overview

The RCC program provides functionality for configuring and managing the Reset and Clock Control (RCC) peripheral of STM32 microcontrollers. It includes functions to initialize the RCC, configure the system clock, and enable or disable peripherals.

### Files

- **RCC_program.c**: Implements RCC initialization and peripheral enable/disable functions.
- **RCC_registers.h**: Defines the RCC register structure and base address.

### RCC Initialization

The `RCC_init()` function configures the system clock source and AHB prescaler. The clock source can be selected from HSI (High-Speed Internal), HSE (High-Speed External), or PLL (Phase-Locked Loop).

#### Configuration

Modify the following macros to match your system configuration:

- `SYSTIM_CLOCK`: Select the clock source. Options are `RCC_HSI`, `RCC_HSE`, or `RCC_PLL`.
- `HSEBYP`: HSE bypass configuration bit.
- `PLL_CLOCK_SOURCE`: Configuration for the PLL clock source.
- `AHB_PRESCALER`: Value for the AHB prescaler.

#### Function Descriptions

**`void RCC_init(void)`**

Initializes the RCC according to the selected clock source.

**`void RCC_Peripheralenable(uint32_t peripheral)`**

Enables the specified peripheral by setting the appropriate bit in the APB1 peripheral clock enable register.

**`void RCC_Peripheraldisable(uint32_t peripheral)`**

Disables the specified peripheral by clearing the appropriate bit in the APB1 peripheral clock enable register.

### Example Usage

```c
#include "RCC_interface.h"

// Configure RCC to use HSI
SYSTIM_CLOCK = RCC_HSI;
RCC_init(); // Initialize RCC

// Enable a specific peripheral
RCC_Peripheralenable(RCC_APB1ENR_TIM2EN);

// Disable a specific peripheral
RCC_Peripheraldisable(RCC_APB1ENR_TIM2EN);
```

## GPIO Program

### Overview

The GPIO program provides functionality for configuring and manipulating GPIO (General Purpose Input/Output) pins on STM32 microcontrollers. It includes functions to initialize GPIO pins, read their states, and write values to them.

### Files

- **GPIO_program.c**: Implements GPIO initialization, reading, and writing functions.
- **GPIO_interface.h**: Defines GPIO configuration structures and constants.
- **GPIO_registers.h**: Defines GPIO registers.

### GPIO Initialization

**`void GPIO_init(GPIO_config_t* config)`**

Initializes a GPIO pin according to the specified configuration.

### GPIO Read Pin

**`void GPIO_read_pin(GPIO_config_t* config)`**

Reads the current logic level of a specified GPIO pin.

### GPIO Write Pin

**`void GPIO_write_pin(GPIO_config_t* config)`**

Writes a logic level to a specified GPIO pin.

### Example Usage

```c
GPIO_config_t gpio_config;

// Initialize GPIO pin 5 on port A as output
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
```

## SysTick Timer Program

### Overview

The SysTick timer program provides functionality for configuring and managing the SysTick timer peripheral on STM32 microcontrollers. It includes functions to initialize the timer, create delays, and handle interrupts.

### Files

- **Systick_program.c**: Implements SysTick initialization, delay functions, and interrupt handling.
- **Systick_interface.h**: Defines SysTick configuration and function prototypes.

### SysTick Initialization

**`void Systick_init(void)`**

Initializes the SysTick timer based on the selected clock source.

### Delay Functions

**`void Systick_delay_milliseconds(uint32_t ms)`**

Delays for a specified number of milliseconds.

**`void Systick_delay_microseconds(uint32_t us)`**

Delays for a specified number of microseconds.

### Timer Functions

**`int Systick_get_elapsed_time(void)`**

Gets the elapsed time since the SysTick timer started.

**`int Systick_remaining_time(void)`**

Gets the remaining time before the SysTick timer reaches zero.

### Interrupt Functions

**`void Systick_enable_inrterrupt(void)`**

Enables SysTick interrupts.

**`void Systick_start_count_millisecondsIT(uint32_t ms, void (*ptr)(void))`**

Starts a millisecond delay with interrupt and registers a callback function.

**`void Systick_start_count_microsecondsIT(uint32_t us, void (*ptr)(void))`**

Starts a microsecond delay with interrupt and registers a callback function.

**`void SysTick_Handler(void)`**

SysTick interrupt handler that calls the registered callback function.

### Example Usage

```c
#include "Systick_interface.h"

// Initialize SysTick
Systick_init();

// Delay for 100 milliseconds
Systick_delay_milliseconds(100);

// Delay for 100 microseconds
Systick_delay_microseconds(100);

// Start a millisecond delay with interrupt
void myCallback(void) {
    // Code to execute when interrupt occurs
}
Systick_start_count_millisecondsIT(1000, myCallback);
```

## NVIC Program

### Overview

The NVIC program provides functionality for configuring and managing the Nested Vectored Interrupt Controller (NVIC) on STM32 microcontrollers. It includes functions to enable/disable interrupts, set/get interrupt priorities, and manage pending interrupts.

### Files

- **NVIC_program.c**: Implements NVIC initialization and interrupt management functions.
- **NVIC_interface.h**: Defines NVIC function prototypes and constants.

### NVIC Functions

**`void NVIC_EnableIRQ(IRQn_t IRQn)`**

Enables the specified interrupt by setting the appropriate bit in the ISER register.

**`void NVIC_DisableIRQ(IRQn_t IRQn)`**

Disables the specified interrupt by setting the appropriate bit in the ICER register.

**`uint8_t NVIC_GetPendingIRQ(IRQn_t IRQn)`**

Gets the pending status of the specified interrupt.

**`void NVIC_SetPendingIRQ(IRQn_t IRQn)`**

Sets the specified interrupt as pending.

**`void NVIC_ClearPendingIRQ(IRQn_t IRQn)`**

Clears the pending status of the specified interrupt.

**`uint8_t NVIC_GetActive(IRQn_t IRQn)`**

Gets the active status of the specified interrupt.

**`void NVIC_SetPriority(IRQn_t IRQn, uint8_t priority)`**

Sets the priority of the specified interrupt.

**`uint8_t NVIC_GetPriority(IRQn_t IRQn)`**

Gets the priority of the specified interrupt.

### Example Usage

```c
#include "NVIC_interface.h"

// Enable an interrupt
NVIC_EnableIRQ(IRQn_Type_Tim2);

// Set priority for an interrupt
NVIC_SetPriority(IRQn_Type_Tim2, 1);

// Check if an interrupt is pending
if (NVIC_GetPendingIRQ(IRQn_Type_Tim2)) {
    // Handle pending interrupt
}

// Clear a pending interrupt
NVIC_ClearPendingIRQ(IRQn_Type_Tim2);
```
```
