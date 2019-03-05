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
			

int main(void)
{
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);
	int delay_time = 2000;
	int speed_it = 1;
	int count = 0;
	while (1) {
		BSP_LED_On(LED1);
		HAL_Delay(delay_time);
		BSP_LED_Off(LED1);
		HAL_Delay(delay_time);
		count++;
		if (count == 3) {
			count = 0;
			if (speed_it) {
				delay_time /= 2;
			} else {
				delay_time *= 2;
			}
		}
		if (delay_time == 250) {
			speed_it = 0;
		} else if (delay_time == 2000) {
			speed_it = 1;
		}
	}
}

