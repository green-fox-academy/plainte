
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef button_config;

static void Error_Handler(void);
static void SystemClock_Config(void);

volatile int counter = 0;

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    /* GPIO config *********************************************************************************************************/
   /* __HAL_RCC_GPIOA_CLK_ENABLE();
    PA15_LED_config.Pin = GPIO_PIN_15;
    PA15_LED_config.Mode = GPIO_MODE_AF_PP;	/* configure as output, in push-pull mode
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;

    HAL_GPIO_Init(GPIOA, &PA15_LED_config);  */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    button_config.Pin = GPIO_PIN_4;
    button_config.Mode = GPIO_MODE_IT_RISING;
    button_config.Pull = GPIO_NOPULL;
    button_config.Speed = GPIO_SPEED_LOW;

    HAL_GPIO_Init(GPIOB, &button_config);
    BSP_LED_Init(LED_GREEN);

    HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 0);

    HAL_NVIC_EnableIRQ(EXTI4_IRQn);

    while (1) {
    	if (counter % 5 == 0 && (counter / 5) % 2 == 1) {
    			BSP_LED_On(LED_GREEN);
    		} else if (counter % 5 == 0 && (counter / 5) % 2 == 0) {
    			BSP_LED_Off(LED_GREEN);
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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK| RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
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
		counter++;
	}
}
