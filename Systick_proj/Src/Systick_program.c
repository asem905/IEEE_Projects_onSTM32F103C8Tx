/*
 * Systick_program.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Asem
 */

#include "Systick_interface.h"

// Pointer to a callback function to be called when the SysTick interrupt occurs
void (*Systick_callback)(void) = NULL;

// Function to initialize the SysTick timer based on the clock source
void Systick_init() {
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
    // Select AHB as the clock source without division
    SYSTICK->CTRL |= (1 << 2);
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
    // Select AHB/8 as the clock source
    SYSTICK->CTRL &= ~(1 << 2);
#endif
}

// Function to delay for a specified number of milliseconds
void Systick_delay_milliseconds(uint32_t ms) {
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
    // Check if the calculated load value fits within the 24-bit SysTick LOAD register
    if ((ms * SYSTEM_CLOCK * 1000 - 1) < MAX_SYSTICK_LOAD) {
        // Set the SysTick LOAD register with the calculated value
        SYSTICK->LOAD = ms * SYSTEM_CLOCK * 1000 - 1;
        // Start the SysTick timer
        SYSTICK->CTRL |= (1 << 0);
        // Wait until the count flag is set, indicating the timer reached zero
        while (!((SYSTICK->CTRL & (1 << 16)) >> 16));
        // Stop the SysTick timer
        SYSTICK->CTRL &= ~(1 << 0);
    }
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
    // Check if the calculated load value fits within the 24-bit SysTick LOAD register
    if ((ms * SYSTEM_CLOCK / 8 * 1000 - 1) < MAX_SYSTICK_LOAD) {
        // Set the SysTick LOAD register with the calculated value
        SYSTICK->LOAD = ms * SYSTEM_CLOCK / 8 * 1000 - 1;
        // Start the SysTick timer
        SYSTICK->CTRL |= (1 << 0);
        // Wait until the count flag is set, indicating the timer reached zero
        while (!((SYSTICK->CTRL & (1 << 16)) >> 16));
        // Stop the SysTick timer
        SYSTICK->CTRL &= ~(1 << 0);
    }
#endif
}

// Function to delay for a specified number of microseconds
void Systick_delay_microseconds(uint32_t us) {
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
    // Check if the calculated load value fits within the 24-bit SysTick LOAD register
    if ((us * SYSTEM_CLOCK * 1000 - 1) < MAX_SYSTICK_LOAD) {
        // Set the SysTick LOAD register with the calculated value
        SYSTICK->LOAD = us * SYSTEM_CLOCK * 1000 - 1;
        // Start the SysTick timer
        SYSTICK->CTRL |= (1 << 0);
        // Wait until the count flag is set, indicating the timer reached zero
        while (!((SYSTICK->CTRL & (1 << 16)) >> 16));
        // Stop the SysTick timer
        SYSTICK->CTRL &= ~(1 << 0);
    }
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
    // Check if the calculated load value fits within the 24-bit SysTick LOAD register
    if ((us * SYSTEM_CLOCK / 8 * 1000 - 1) < MAX_SYSTICK_LOAD) {
        // Set the SysTick LOAD register with the calculated value
        SYSTICK->LOAD = us * SYSTEM_CLOCK / 8 * 1000 - 1;
        // Start the SysTick timer
        SYSTICK->CTRL |= (1 << 0);
        // Wait until the count flag is set, indicating the timer reached zero
        while (!((SYSTICK->CTRL & (1 << 16)) >> 16));
        // Stop the SysTick timer
        SYSTICK->CTRL &= ~(1 << 0);
    }
#endif
}

// Function to get the elapsed time since the SysTick timer started
int Systick_get_elapsed_time() {
    // Return the difference between the initial load value and the current value in the VAL register
    return ((SYSTICK->LOAD & 0xFFFFFF) - (SYSTICK->VAL & 0xFFFFFF));
}

// Function to get the remaining time before the SysTick timer reaches zero
int Systick_remaining_time() {
    // Return the current value in the VAL register, indicating the remaining time
    return (SYSTICK->VAL & 0xFFFFFF);
}

// Function to enable SysTick interrupts
void Systick_enable_inrterrupt() {
    // Set the TICKINT bit in the CTRL register to enable the SysTick interrupt
    SYSTICK->CTRL |= (1 << 1);
}

// Function to start a millisecond delay with interrupt and register a callback function
void Systick_start_count_millisecondsIT(uint32_t ms, void (*ptr)(void)) {
    if (ptr != NULL) {
        // Register the callback function to be called when the interrupt occurs
        Systick_callback = ptr;
        // Set the reload register with the desired value based on the clock source
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
        if ((ms * SYSTEM_CLOCK * 1000 - 1) < MAX_SYSTICK_LOAD) {
            SYSTICK->LOAD = ms * SYSTEM_CLOCK * 1000; // Set the LOAD register
        }
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
        if ((ms * SYSTEM_CLOCK * 1000 - 1) < MAX_SYSTICK_LOAD) {
            SYSTICK->LOAD = ms * SYSTEM_CLOCK / 8 * 1000; // Set the LOAD register
        }
#endif
        // Start the SysTick timer
        SYSTICK->CTRL |= (1 << 0);
    } else {
        // Handle the case where the callback function is NULL
    }
}

// Function to start a microsecond delay with interrupt and register a callback function
void Systick_start_count_microsecondsIT(uint32_t us, void (*ptr)(void)) {
    if (ptr != NULL) {
        // Register the callback function to be called when the interrupt occurs
        Systick_callback = ptr;
        // Set the reload register with the desired value based on the clock source
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
        if ((us * SYSTEM_CLOCK * 1000 - 1) < MAX_SYSTICK_LOAD) {
            SYSTICK->LOAD = us * SYSTEM_CLOCK * 1000 - 1; // Set the LOAD register
        }
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
        if ((us * SYSTEM_CLOCK / 8 * 1000 - 1) < MAX_SYSTICK_LOAD) {
            SYSTICK->LOAD = us * SYSTEM_CLOCK / 8 * 1000 - 1; // Set the LOAD register
        }
#endif
        // Start the SysTick timer
        SYSTICK->CTRL |= (1 << 0);
    } else {
        // Handle the case where the callback function is NULL
    }
}

// SysTick interrupt handler
void SysTick_Handler(void) {
    if (Systick_callback) {
        // Call the registered callback function
        Systick_callback();
#if SYSTICK_INTERRUPT == SYSTICK_INTERRUPT_NONPERIODIC
        // If the SysTick interrupt is non-periodic, turn off the timer
        SYSTICK->CTRL &= ~(1 << 0);
        // Disable the SysTick interrupt
        SYSTICK->CTRL &= ~(1 << 1);
#endif
    }
}
