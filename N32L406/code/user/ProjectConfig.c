/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              *
 ********************************************************************************************************************
 * @file            ProjectConfig.c
 * @brief           None.
 * @details         产品相关功能函数
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-02-15
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#include "n32l40x.h"
#include "ProjectConfig.h"

#include "MSP_UART.h"
#include "MSP_GPIO.h"

#include <stdint.h>
#include <stddef.h>

/* 微秒延时：基于SysTick->VAL */
void DEVICE_DELAY_US(uint32_t us)
{
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload = SysTick->LOAD + 1;

    ticks = us * (SystemCoreClock / 1000000);
    told = SysTick->VAL;

    while (tcnt < ticks)
    {
        tnow = SysTick->VAL;
        if (tnow != told)
        {
            if (tnow < told)
            {
                tcnt += told - tnow;
            }
            else
            {
                tcnt += told + (reload - tnow);
            }
            told = tnow;
        }
    }
}

/* 毫秒延时 */
void DEVICE_DELAY_MS(uint32_t ms)
{
    while (ms--)
    {
        DEVICE_DELAY_US(1000);
    }
}

long reboot(void)
{
    NVIC_SystemReset();
    return 0;
}