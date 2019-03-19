/*
 * initializations.h
 *
 *  Created on: 2019. márc. 19.
 *      Author: molna
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

#ifndef INITIALIZATIONS_H_
#define INITIALIZATIONS_H_

/* create the configuration structs */
UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef timer_handle;
GPIO_InitTypeDef user_button_handle;


void init_uart(void)
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

	HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

void init_timer(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	HAL_TIM_Base_DeInit(&timer_handle);
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1; /* 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	timer_handle.Init.Period = 5000 - 1; /* 10000 x 0.5 ms = 6 second period */
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&timer_handle);

    HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void init_user_button()
{
	// Initialize the user push button
	__HAL_RCC_GPIOI_CLK_ENABLE();

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING;	// Generate interrupt on the rising edge of the signal

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	// Set the priority of the interrupt
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);

	// Enable the interrupt
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}



#endif /* INITIALIZATIONS_H_ */
