#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

GPIO_InitTypeDef volume_buttons;
GPIO_InitTypeDef channel_buttons;

UART_HandleTypeDef UartHandle;

static void Error_Handler(void);
static void SystemClock_Config(void);

volatile uint32_t rising_edge = 0;
const uint32_t debounce_delay = 1000;    // the debounce time in ms (increase if the output flickers)

volatile int volume = 0;
volatile double max_frequency = 108.00; // frequencies in MHz
volatile double min_frequency = 87.5;
volatile double preset_radio[5] = { 88.1, 89.5, 90.9, 92.1, 92.9 };

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	/* volume buttons A1, A2 */
	__HAL_RCC_GPIOF_CLK_ENABLE();

	volume_buttons.Pin = GPIO_PIN_10 | GPIO_PIN_9;
	volume_buttons.Mode = GPIO_MODE_IT_RISING; /* configure as output, in push-pull mode */
	volume_buttons.Pull = GPIO_NOPULL;
	volume_buttons.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(GPIOF, &volume_buttons);

	channel_buttons.Pin = GPIO_PIN_8 | GPIO_PIN_7;
	channel_buttons.Mode = GPIO_MODE_IT_RISING;
	channel_buttons.Pull = GPIO_NOPULL;
	channel_buttons.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(GPIOF, &channel_buttons);

	BSP_LED_Init(LED_GREEN);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 4, 0);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	  __HAL_RCC_USART1_CLK_ENABLE();

	/* defining the UART configuration structure */
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &UartHandle);

	char buffer[3];

	while (1) {

		HAL_Delay(1000);
		sprintf(buffer, "%d", volume);

		HAL_UART_Transmit(&UartHandle, (uint8_t*) buffer, strlen(buffer), 0xFFFF);

	}
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

void EXTI9_5_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	// volume up pin10 button
	uint32_t start = HAL_GetTick();
	if (GPIO_Pin == GPIO_PIN_10) {
		while (rising_edge == 0) {
			if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10) == 0) {
				rising_edge = HAL_GetTick();
			}
		}
		if (start - rising_edge < debounce_delay) {
			if (volume + 1 <= 100) {
				volume++;
			}
		} else {
			if (volume + 5 <= 100) {
				volume += 5;
			} else {
				volume = 100;
			}
		}
	}
	rising_edge = 0;
}
