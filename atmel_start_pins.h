/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMD21 has 8 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7

#define LED GPIO(GPIO_PORTA, 2)
#define DMX_RX GPIO(GPIO_PORTA, 5)
#define DMX_TX GPIO(GPIO_PORTA, 6)
#define LED_4 GPIO(GPIO_PORTA, 8)
#define BTN_4 GPIO(GPIO_PORTA, 9)
#define LED_3 GPIO(GPIO_PORTA, 10)
#define BTN_3 GPIO(GPIO_PORTA, 11)
#define LED_2 GPIO(GPIO_PORTA, 14)
#define BTN_2 GPIO(GPIO_PORTA, 15)
#define LED_1 GPIO(GPIO_PORTA, 16)
#define BTN_1 GPIO(GPIO_PORTA, 17)
#define PA22 GPIO(GPIO_PORTA, 22)
#define PA23 GPIO(GPIO_PORTA, 23)
#define PA25 GPIO(GPIO_PORTA, 25)

#endif // ATMEL_START_PINS_H_INCLUDED
