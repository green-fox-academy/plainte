#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "string.h"

#include "initializations.h"
#include "systemclock_config.c"

typedef enum {
	OPEN, SECURING, SECURED, OPENING
} railway_state_t;

railway_state_t state = OPEN;

volatile char entered_open[24] = "Entered in OPEN state\n";
volatile char entered_securing[28] = "Entered in SECURING state\n";
volatile char entered_secured[27] = "Entered in SECURED state\n";
volatile char entered_opening[27] = "Entered in OPENING state\n";

volatile int flashing_slower = 0;
volatile int time_count = 0;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);

	init_uart();
	init_timer();
	init_user_button();

	/* starting the timer */
	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {
		if (state == SECURING) {
			time_count = HAL_GetTick();
			while (HAL_GetTick() - time_count < 5000) {
				HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			}
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			HAL_UART_Transmit_IT(&uart_handle, (uint8_t *)entered_secured, 26);
			state = SECURED;
		} else if (state == OPENING) {
			time_count = HAL_GetTick();
			while (HAL_GetTick()- time_count < 6000) {
				HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			}
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			state = OPEN;
			HAL_UART_Transmit_IT(&uart_handle, (uint8_t *)entered_open, 23);
		}

	}
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (state == OPEN) {
		flashing_slower++;
		if (flashing_slower % 2 == 0) {
			BSP_LED_Toggle(LED_GREEN);
		}
	} else if (state == SECURING || state == OPENING) {
		BSP_LED_Toggle(LED_GREEN);
	} else if (state == SECURED) {
		BSP_LED_Off(LED_GREEN);
	}
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (state == OPEN) {
		flashing_slower = 0;
		state = SECURING;
		HAL_UART_Transmit_IT(&uart_handle, (uint8_t *)entered_securing, 27);
	} else if (state == SECURED) {
		flashing_slower = 0;
		state = OPENING;
		HAL_UART_Transmit_IT(&uart_handle, (uint8_t *)entered_opening, 26);
	}
}

void USART1_IRQHandler() {
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
}
