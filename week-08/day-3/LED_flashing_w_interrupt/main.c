#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
			
/* the timer's config structure */
TIM_HandleTypeDef TimHandle;

volatile uint16_t tim_val = 0;

static void Error_Handler(void);
static void SystemClock_Config(void);

void timer_init();
void led_init();

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	timer_init();
	led_init();

	/* starting the timer */
	HAL_TIM_Base_Start_IT(&TimHandle);

	while (1) {

	}
}

void timer_init()
{
    /* we need to enable the TIM2 */
    __HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_TIM_SET_COUNTER(&TimHandle, 0);
    TimHandle.Instance = TIM2;
	TimHandle.Init.Prescaler = 10800 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	TimHandle.Init.Period = 10000 - 1; /* 10000 x 0.1 ms = 1 second period */
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;

    /* configure the timer */
    HAL_TIM_Base_Init(&TimHandle);

    HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void led_init()
{
	BSP_LED_Init(LED_GREEN);
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

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		tim_val = __HAL_TIM_GET_COUNTER(htim);
		if (tim_val == 0) {
			BSP_LED_Toggle(LED_GREEN);
		}
	}
}
