/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_IT.c
 * @brief           None.
 * @details         MSP中断函数集中处理,此处放置无法lib封装的MCU中断函数入口.
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-11-23
 * @copyright       DE.POWER
 * *****************************************************************************************************************/

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "ProjectConfig.h"


/* SysTick中断服务函数 */
void SysTick_Handler(void)
{
    // 配置为 10ms 中断一次，每次计数器加 10
    gSysTickCnt += 10;
    gEisSysTickCnt += 10;
    // 计数器回绕处理
    if (gSysTickCnt == (5000))
    {
        gSysTickCnt = 0;
    }
    if (gEisSysTickCnt == (127000))
    {
        gEisSysTickCnt = 0;
    }
    // 10ms 周期任务调度
    if (gSysTickCnt % 10 == 0)   //10ms
    {
        gTaskDigitalSync = true;
    }
    // 100ms 周期任务调度
    if (gSysTickCnt % 100 == 0)   //100ms
    {
        // gTaskReadVoltage = true;
    }
    // [核心] EIS 流程控制：DFE 等待时间结束
    // dfe_wait_time 的单位是秒，gEisSysTickCnt 的单位是毫秒，所以比较时需要将 dfe_wait_time 乘以 1000 转换为毫秒
    if (gEisSysTickCnt >= (gBQDev[0].dfe_wait_time * 1000)  && eis_run_flag == 1)
    {
        gTaskEisDFT = true;
        gEisSysTickCnt = 0;
    }
    // [核心] EIS 流程控制：DFT 等待时间结束
    if (gEisSysTickCnt >= (gBQDev[0].dft_wait_time * 1000)  && eis_run_flag == 2)
    {
        gTaskEisRead = true;
        gEisSysTickCnt = 0;
    }
    // EIS 连续读取模式（测试用）
    if (gEisSysTickCnt >= 500  && eis_run_flag == 3)
    {
        gTaskEisRead = true;
        gEisSysTickCnt = 0;
    }
}

/* SysTick初始化：10ms节拍 */
void systick_init(void)
{
    SysTick_Config(SystemCoreClock / 100);
}

/* USART1 中断服务函数 */
void USART2_IRQHandler(void)
{
    static char rx_buf[64];
    static uint8_t rx_idx = 0;

    if (USART_GetIntStatus(USART2, USART_INT_RXDNE) != RESET)
    {
        char c = (char)USART_ReceiveData(USART2);
        
        if (c == '\n' || c == '\r')
        {
            rx_buf[rx_idx] = '\0'; // 字符串结束
            if (rx_idx > 0)
            {
                // 解析指令
                if (rx_idx > 0 && strncmp(rx_buf, "START_EIS", 9) == 0)
                {
                    gTaskStartEisQuery = true;
                }
                else if (strncmp(rx_buf, "WAKE_STACK", 10) == 0 || strncmp(rx_buf, "WAKE", 4) == 0)
                {
                    gTaskWakeStackQuery = true;
                }
                else if (strncmp(rx_buf, "BQ_RESET", 8) == 0 || strncmp(rx_buf, "RESET_BQ", 8) == 0)
                {
                    gTaskBqResetQuery = true;
                }
                else if (strncmp(rx_buf, "BQ_SLEEP", 8) == 0 || strncmp(rx_buf, "SLEEP_BQ", 8) == 0 || strncmp(rx_buf, "SLEEP", 5) == 0)
                {
                    gTaskBqSleepQuery = true;
                }
                else if (strncmp(rx_buf, "START_SINGLE", 12) == 0)
                {
                    gTaskStartSingleEisQuery = true;
                }
                else if (strncmp(rx_buf, "STOP_EIS", 8) == 0)
                {
                    gTaskStopEisQuery = true;
                }
                else if (strncmp(rx_buf, "SET_EIS_CONFIG:", 15) == 0)
                {
                    char *cursor = &rx_buf[15];
                    char *end = cursor;
                    float32_t freq = (float32_t)strtof(cursor, &end);
                    uint32_t dft_len = 0u;
                    float32_t hpf_hz = 0.0f;
                    uint32_t dsr = 0u;

                    if (*end == ',')
                    {
                        cursor = end + 1;
                        dft_len = (uint32_t)strtoul(cursor, &end, 10);
                    }
                    if (*end == ',')
                    {
                        cursor = end + 1;
                        hpf_hz = (float32_t)strtof(cursor, &end);
                    }
                    if (*end == ',')
                    {
                        cursor = end + 1;
                        dsr = (uint32_t)strtoul(cursor, &end, 10);
                    }

                    if (freq > 0.0f && dft_len > 0u && hpf_hz > 0.0f && dsr > 0u && dsr <= 10u)
                    {
                        gEisRequestedFreq = freq;
                        gEisRequestedDftLength = dft_len;
                        gEisRequestedHpfHz = hpf_hz;
                        gEisRequestedDsr = (uint8_t)dsr;
                        gEisConfigOverride = 1u;
                        gTaskSetEisFreq = true;
                    }
                }
                else if (strncmp(rx_buf, "SET_FREQ:", 9) == 0)
                {
                    gEisRequestedFreq = (float32_t)atof(&rx_buf[9]);
                    gEisConfigOverride = 0u;
                    gTaskSetEisFreq = true;
                }
                else if (strncmp(rx_buf, "FREQ:", 5) == 0)
                {
                    gEisRequestedFreq = (float32_t)atof(&rx_buf[5]);
                    gEisConfigOverride = 0u;
                    gTaskSetEisFreq = true;
                }
            }
            rx_idx = 0;
        }
        else
        {
            if (rx_idx < sizeof(rx_buf) - 1)
            {
                rx_buf[rx_idx++] = c;
            }
            else
            {
                rx_idx = 0; // 溢出保护
            }
        }
        USART_ClrIntPendingBit(USART2, USART_INT_RXDNE);
    }
}
