/*
 * initialization.h
 *
 *  Created on: 2019. márc. 21.
 *      Author: molna
 */

#ifndef INITIALIZATION_C_
#define INITIALIZATION_C_

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* UART structure */
UART_HandleTypeDef uart_handle;

/* the timer's config structure */
TIM_HandleTypeDef TimHandle1;
TIM_HandleTypeDef TimHandle2;
TIM_HandleTypeDef TimHandle3;

/* the output compare channel's config structure */
TIM_OC_InitTypeDef sConfig;

/* pin config: we cannot use the green user LED, because it's not connected to an output compare channel so we use PA15*/
GPIO_InitTypeDef PB15_RGB_config;
GPIO_InitTypeDef PA8_RGB_config;
GPIO_InitTypeDef PA15_RGB_config;

/* RNG typedef config */
RNG_HandleTypeDef rng_instance;

void init_pwms_leds();
void init_rng();
void init_uart();


#endif /* INITIALIZATION_C_ */
