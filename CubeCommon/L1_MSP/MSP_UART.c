#include "MSP_UART.h"
#include "n32l40x.h"
#include "n32l40x_usart.h"
#include "n32l40x_gpio.h"
#include "n32l40x_rcc.h"
#include <stdio.h>

void log_uart_init(uint32_t baudrate)
{
    GPIO_InitType GPIO_InitStructure;
    USART_InitType USART_InitStructure;
    NVIC_InitType NVIC_InitStructure;

    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB | RCC_APB2_PERIPH_AFIO, ENABLE);
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_USART2, ENABLE);

    GPIO_InitStruct(&GPIO_InitStructure);
    GPIO_InitStructure.Pin            = GPIO_PIN_4;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF4_USART2;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.Pin            = GPIO_PIN_5;
    GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_Input;
    GPIO_InitStructure.GPIO_Pull      = GPIO_Pull_Up;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF6_USART2;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.BaudRate            = baudrate;
    USART_InitStructure.WordLength          = USART_WL_8B;
    USART_InitStructure.StopBits            = USART_STPB_1;
    USART_InitStructure.Parity              = USART_PE_NO;
    USART_InitStructure.HardwareFlowControl = USART_HFCTRL_NONE;
    USART_InitStructure.Mode                = USART_MODE_TX | USART_MODE_RX;

    USART_Init(USART2, &USART_InitStructure);
    USART_ConfigInt(USART2, USART_INT_RXDNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_Enable(USART2, ENABLE);
}

void log_uart_wait_tx_complete(void)
{
    uint32_t timeout = 0x1FFFF;

    while (USART_GetFlagStatus(USART2, USART_FLAG_TXC) == RESET)
    {
        if (timeout-- == 0)
        {
            return;
        }
    }
}

#if defined(__CC_ARM) || defined(__CLANG_ARM) || defined(__ARMCC_VERSION)
int fputc(int ch, FILE *f)
{
    uint32_t timeout = 0x1FFFF;

    while (USART_GetFlagStatus(USART2, USART_FLAG_TXDE) == RESET)
    {
        if (timeout-- == 0)
        {
            return ch;
        }
    }

    USART_SendData(USART2, (uint8_t)ch);
    return ch;
}
#endif
