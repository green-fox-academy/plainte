/*
 * initialization.c
 *
 *  Created on: 2019. márc. 21.
 *      Author: molna
 */
#include "initialization.h"

void init_pwms_leds()
{
	/* GPIOx config's */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	PB15_RGB_config.Pin = GPIO_PIN_15;
	PB15_RGB_config.Mode = GPIO_MODE_AF_OD; /* open-drain */
	PB15_RGB_config.Pull = GPIO_NOPULL;
	PB15_RGB_config.Speed = GPIO_SPEED_HIGH;
	PB15_RGB_config.Alternate = GPIO_AF9_TIM12;
	HAL_GPIO_Init(GPIOB, &PB15_RGB_config);

	__HAL_RCC_GPIOA_CLK_ENABLE();
	PA8_RGB_config.Pin = GPIO_PIN_8;
	PA8_RGB_config.Mode = GPIO_MODE_AF_OD;
	PA8_RGB_config.Pull = GPIO_NOPULL;
	PA8_RGB_config.Speed = GPIO_SPEED_HIGH;
	PA8_RGB_config.Alternate = GPIO_AF1_TIM1;
	HAL_GPIO_Init(GPIOA, &PA8_RGB_config);

	PA15_RGB_config.Pin = GPIO_PIN_15;
	PA15_RGB_config.Mode = GPIO_MODE_AF_OD;
	PA15_RGB_config.Pull = GPIO_NOPULL;
	PA15_RGB_config.Speed = GPIO_SPEED_HIGH;
	PA15_RGB_config.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(GPIOA, &PA15_RGB_config);

	/* Base timer config's */
	__HAL_RCC_TIM12_CLK_ENABLE();
	TimHandle1.Instance = TIM12;
	TimHandle1.Init.Prescaler = 108 - 1; /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
	TimHandle1.Init.Period = 100 - 1; /* 100 x 0.001 ms = 10 ms = 0.01 s period */
	TimHandle1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle1.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&TimHandle1);

	__HAL_RCC_TIM1_CLK_ENABLE();
	TimHandle2.Instance = TIM1;
	TimHandle2.Init.Prescaler = 108 - 1;
	TimHandle2.Init.Period = 100 - 1;
	TimHandle2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle2.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&TimHandle2);

	__HAL_RCC_TIM2_CLK_ENABLE();
	TimHandle3.Instance = TIM2;
	TimHandle3.Init.Prescaler = 108 - 1;
	TimHandle3.Init.Period = 100 - 1;
	TimHandle3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle3.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&TimHandle3);

	/* PWM config */
	sConfig.Pulse = 50;
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&TimHandle1, &sConfig, TIM_CHANNEL_2);
	HAL_TIM_PWM_ConfigChannel(&TimHandle2, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_ConfigChannel(&TimHandle3, &sConfig, TIM_CHANNEL_1);

	/* starting PWM */
	HAL_TIM_PWM_Start(&TimHandle1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&TimHandle2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&TimHandle3, TIM_CHANNEL_1);
}

void init_rng()
{
	__HAL_RCC_RNG_CLK_ENABLE();

	/* initializing RNG */
	rng_instance.Instance = RNG;
	HAL_RNG_Init(&rng_instance);
}

void init_uart()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart_handle);
}
