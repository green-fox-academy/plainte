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
#include <string.h>

#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

UART_HandleTypeDef UartHandle;

int main(void)
{
    HAL_Init();

    /* enable GPIO clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* configure GPIO for UART transmit line */
    GPIOTxConfig.Pin = GPIO_PIN_9;
    GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
    GPIOTxConfig.Pull = GPIO_NOPULL;
    GPIOTxConfig.Speed = GPIO_SPEED_FAST;
    GPIOTxConfig.Alternate = GPIO_AF7_USART1;

    HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

    /* configure GPIO for UART receive line */
    GPIORxConfig.Pin = GPIO_PIN_7;
    GPIORxConfig.Mode = GPIO_MODE_AF_PP;
    GPIOTxConfig.Pull = GPIO_NOPULL;
    GPIORxConfig.Speed = GPIO_SPEED_FAST;
    GPIORxConfig.Alternate = GPIO_AF7_USART1;

    HAL_GPIO_Init(GPIOB, &GPIORxConfig);

    /* enable the clock of the used peripherial instance */
    __HAL_RCC_USART1_CLK_ENABLE();

    /* defining the UART configuration structure */
    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    HAL_UART_Init(&UartHandle);

    char *ret;
    char *token;

    while (1) {


    	char received[100] = "";

        HAL_UART_Receive(&UartHandle, (uint8_t*) received, 100, 5000);
        ret = memchr(received, '\0', strlen(received));
        if (ret == NULL) {
        	HAL_UART_Transmit(&UartHandle, (uint8_t*) received, strlen(received), 0xFFFF);
        } else {
            token = strtok(received, '\0');
            HAL_UART_Transmit(&UartHandle, (uint8_t*) token, strlen(token), 0xFFFF);
        }
    }
}
