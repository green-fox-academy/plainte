#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "string.h"

TIM_HandleTypeDef TimHandle;
UART_HandleTypeDef uart_handle;

char buffer[6];
volatile uint16_t tim_val = 0;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_uart()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	/* defining the UART configuration structure */
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	HAL_NVIC_SetPriority(USART1_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    BSP_LED_Init(LED_GREEN);
    __HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_TIM_SET_COUNTER(&TimHandle, 0);
    init_uart();

    TimHandle.Instance = TIM2;
    TimHandle.Init.Prescaler		= 10800 - 1;	/* 108000000/10800=1000000 -> speed of 1 count-up: 1/10000 s = 0.1 ms */
    TimHandle.Init.Period		= 10000 - 1;	/* 10000 x 0.1 ms  = 1 s period */
    TimHandle.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    TimHandle.Init.CounterMode		= TIM_COUNTERMODE_UP;

    /* configure the timer */
    HAL_TIM_Base_Init(&TimHandle);

    /* starting the timer */
    HAL_TIM_Base_Start_IT(&TimHandle);

    HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    memset(buffer, '\0', 6);
	HAL_UART_Receive_IT(&uart_handle,(uint8_t *) &buffer, 6);

    while (1) {
    }
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		tim_val = __HAL_TIM_GET_COUNTER(htim);
		if(tim_val == 0){
			BSP_LED_Toggle(LED_GREEN);
		}

	}
}

static void Error_Handler(void)
{}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	if (huart->Instance == USART1) {
		if(strcmp(buffer, "flash")){
			BSP_LED_Toggle(LED_GREEN);
		} else if (strcmp(buffer, "on")){
			BSP_LED_On(LED_GREEN);
		} else if (strcmp(buffer, "off")){
			BSP_LED_Off(LED_GREEN);
		}
		memset(buffer, '\0', 6);
		HAL_UART_Receive_IT(&uart_handle,(uint8_t * ) &buffer, 6);
	}
}
