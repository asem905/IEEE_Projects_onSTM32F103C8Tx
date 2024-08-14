# RCC Program

## Overview

This repository contains code for configuring and managing the Reset and Clock Control (RCC) peripheral of STM32 microcontrollers. The `RCC_program.c` file provides functions to initialize the RCC, configure the system clock, and enable or disable peripherals.

## Files

- **RCC_program.c**: Contains the implementation of RCC initialization, peripheral enable/disable functions.
- **RCC_registers.h**: Defines the RCC register structure and base address.

## RCC Initialization

The `RCC_init()` function configures the system clock source and AHB prescaler. The clock source can be selected from HSI (High-Speed Internal), HSE (High-Speed External), or PLL (Phase-Locked Loop).

### Configuration

Modify the following macros to match your system configuration:

- `SYSTIM_CLOCK`: Select the clock source. Options are `RCC_HSI`, `RCC_HSE`, or `RCC_PLL`.
- `HSEBYP`: HSE bypass configuration bit.
- `PLL_CLOCK_SOURCE`: Configuration for the PLL clock source.
- `AHB_PRESCALER`: Value for the AHB prescaler.

### Function Descriptions

#### `void RCC_init(void)`

Initializes the RCC according to the selected clock source:

- **HSI**: Turns on HSI, waits for it to be ready, and sets it as the system clock source.
- **HSE**: Configures HSE bypass, turns on HSE, waits for it to be ready, and sets it as the system clock source.
- **PLL**: Configures PLL source, turns on PLL, waits for it to be ready, and sets it as the system clock source.

Sets the AHB prescaler according to the defined value.

#### `void RCC_Peripheralenable(uint32_t peripheral)`

Enables the specified peripheral by setting the appropriate bit in the APB1 peripheral clock enable register.

**Parameters:**

- `peripheral`: Peripheral identifier (e.g., `RCC_APB1ENR_TIM2EN`).

#### `void RCC_Peripheraldisable(uint32_t peripheral)`

Disables the specified peripheral by clearing the appropriate bit in the APB1 peripheral clock enable register.

**Parameters:**

- `peripheral`: Peripheral identifier (e.g., `RCC_APB1ENR_TIM2EN`).

## Example Usage

```c
#include "RCC_interface.h"

// Configure RCC to use HSI
SYSTIM_CLOCK = RCC_HSI;
RCC_init(); // Initialize RCC

// Enable a specific peripheral
RCC_Peripheralenable(RCC_APB1ENR_TIM2EN);

// Disable a specific peripheral
RCC_Peripheraldisable(RCC_APB1ENR_TIM2EN);
