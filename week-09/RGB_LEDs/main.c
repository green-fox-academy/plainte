#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "initialization.h"
#include "system_clock_config.h"


int main(void)
{
    HAL_Init();
    SystemClock_Config();

    init_pwms_leds();
    init_rng();
    init_uart();

    uint32_t random_number1 = 0;
    uint32_t random_number2 = 0;
    uint32_t random_number3 = 0;
    uint32_t for_fun = 0;

    while (1) {
    	for_fun = HAL_RNG_GetRandomNumber(&rng_instance) % 3;
    	switch (for_fun) {
    	case 0:
			random_number1 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 25;
			random_number2 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 25;
			random_number3 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 25;
			break;
    	case 1:
			random_number1 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 3;
			random_number2 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 3;
			random_number3 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 3;
			break;
    	case 2:
			random_number1 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 40;
			random_number2 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 40;
			random_number3 = 100 - HAL_RNG_GetRandomNumber(&rng_instance) % 40;
			break;
    	}
		__HAL_TIM_SET_COMPARE(&TimHandle1, TIM_CHANNEL_2, random_number1);
		__HAL_TIM_SET_COMPARE(&TimHandle2, TIM_CHANNEL_1, random_number2);
		__HAL_TIM_SET_COMPARE(&TimHandle3, TIM_CHANNEL_1, random_number3);
		HAL_Delay(50);
    }
}
