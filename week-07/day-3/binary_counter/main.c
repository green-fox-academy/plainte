/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
			
// create a config structure
GPIO_InitTypeDef LEDS;
GPIO_InitTypeDef LED;

int main(void)
{
	HAL_Init();

	// need to enable GPIOx port's clock first
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	LEDS.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;	// setting up 3pins at once w | (A1, A2, A3)
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;					// configure as output, push pull mode
	LEDS.Pull = GPIO_NOPULL;							// we use external resistor so no
	LEDS.Speed = GPIO_SPEED_HIGH;						// high speed output

	LED.Pin = GPIO_PIN_0;								// setting up A0
	LED.Mode = GPIO_MODE_OUTPUT_PP;						// configure as output, push pull mode
	LED.Pull = GPIO_NOPULL;
	LED.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &LEDS);			// initialize the pin on GPIOF port
	HAL_GPIO_Init(GPIOA, &LED);			// initialize the pin on GPIOA port


	while (1) {
		for (int i = 0; i < 16; i++) {
			if (i % 2 == 0) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
			}
			if ((i >> 1) % 2 != 0) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
			}
			if ((i >> 2) % 2 != 0) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			}
			if ((i >> 3) % 2 != 0) {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			}
			HAL_Delay(1000);
		}
	}
}

