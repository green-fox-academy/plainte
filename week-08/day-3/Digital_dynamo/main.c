#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
			
/* the timer's config structure */
TIM_HandleTypeDef TimHandle;

/* the output compare channel's config structure */
TIM_OC_InitTypeDef sConfig;

GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef button;

static void Error_Handler(void);
static void SystemClock_Config(void);

void timer_init();
void led_init();
void button_init();
volatile int speed = 0;

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	timer_init();
	led_init();
	button_init();

	HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI4_IRQn);

	while (1) {
		while (speed >= 0) {
			__HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, speed);
			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == GPIO_PIN_RESET) {
				for (int i = 0; i < 48826290; i+=5); /* 48826291 execution of this loop takes exactly 3000 ms */
				if (speed - 5 >= 0) {
					speed -= 3;
				} else {
					speed = 0;
				}
			}
		}
	}
}

void timer_init()
{
    /* we need to enable the TIM2 */
    __HAL_RCC_TIM2_CLK_ENABLE();

    TimHandle.Instance = TIM2;
	TimHandle.Init.Prescaler = 108 - 1; /* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
	TimHandle.Init.Period = 100 - 1; /* 10000 x 0.1 ms = 1 second period */
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&TimHandle) */
	HAL_TIM_PWM_Init(&TimHandle);

	/* output compare config ***********************************************************************************************/
	sConfig.Pulse = 0;
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);

	/* starting PWM */
	HAL_TIM_PWM_Start_IT(&TimHandle, TIM_CHANNEL_1);
}

void led_init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in push-pull mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config.Alternate = GPIO_AF1_TIM2; /* this alternate function we need to use TIM2 in output compare mode */
	HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void button_init()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	button.Pin = GPIO_PIN_4;
	button.Mode = GPIO_MODE_IT_RISING;
	button.Pull = GPIO_NOPULL;
	button.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOB, &button);
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

void EXTI4_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_4) {
		if (speed < 100) {
			if (speed + 2 <= 100) {
				speed += 5;
			} else {
				speed = 100;
			}
		}
	}
}
