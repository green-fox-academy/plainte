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

int main(void)
{
	HAL_Init();

	// need to enable GPIOx port's clock first
	__HAL_RCC_GPIOF_CLK_ENABLE();

	LEDS.Pin = GPIO_PIN_10 | GPIO_PIN_9;	// setting up 2 pins at once w | (A1, A2)
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;		// configure as output, push pull mode
	LEDS.Pull = GPIO_NOPULL;				// we use external resistor so no
	LEDS.Speed = GPIO_SPEED_HIGH;			// high speed output

	HAL_GPIO_Init(GPIOF, &LEDS);			// initialize the pin on GPIOF port

	while (1) {
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_Delay(500);

		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_Delay(500);
	}
}

