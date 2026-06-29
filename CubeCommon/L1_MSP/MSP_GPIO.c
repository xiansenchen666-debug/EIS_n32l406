/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_GPIO.c
 * @brief           GPIO底层驱动 + WAKE Ping控制接口
 * @details         版本1,读接口增加output状态读.
 * @attention       新增 WAKE Ping 引脚初始化与发送函数.
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-11-23
 * @copyright       DE.POWER
 ********************************************************************************************************************/

#include "MSP_GPIO.h"
#include "n32l40x_rcc.h"

/* 外部延时函数 */
#include "ProjectConfig.h"



/* ============================================================================ */
/* GPIO API */
/* ============================================================================ */

/**
 * @brief  Initialize a GPIO pin with specified mode
 */
void MSP_GPIO_Init(GPIO_Module* GPIOx, uint16_t Pin, GPIO_ModeType Mode)
{
    GPIO_InitType GPIO_InitStructure;

    /* 自动开 GPIO 时钟 */
    if (GPIOx == GPIOA)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOC, ENABLE);
    }
    else if (GPIOx == GPIOD)
    {
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOD, ENABLE);
    }

    GPIO_InitStruct(&GPIO_InitStructure);

    GPIO_InitStructure.Pin            = Pin;
    GPIO_InitStructure.GPIO_Mode      = Mode;
    GPIO_InitStructure.GPIO_Current   = GPIO_DC_4mA;
    GPIO_InitStructure.GPIO_Pull      = GPIO_No_Pull;
    GPIO_InitStructure.GPIO_Slew_Rate = GPIO_Slew_Rate_High;

    GPIO_InitPeripheral(GPIOx, &GPIO_InitStructure);
}

/**
 * @brief  Write GPIO
 */
void MSP_GPIO_Write(GPIO_Module* GPIOx, uint16_t Pin, uint8_t Val)
{
    if (Val)
    {
        GPIOx->PBSC = Pin;
    }
    else
    {
        GPIOx->PBC = Pin;
    }
}

/**
 * @brief  Toggle GPIO
 */
void MSP_GPIO_Toggle(GPIO_Module* GPIOx, uint16_t Pin)
{
    GPIOx->POD ^= Pin;
}

