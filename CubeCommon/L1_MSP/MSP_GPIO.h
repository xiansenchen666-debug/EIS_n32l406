/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_GPIO.h
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-11-23
 * @copyright       DE.POWER
 * *****************************************************************************************************************/

#ifndef _MSP_GPIO_H_
#define _MSP_GPIO_H_

#include "n32l40x.h"
#include "n32l40x_gpio.h"
#include "n32l40x_rcc.h"

// TI-style macros mapping (兼容层定义)
// 建议用户根据实际板子修改这些宏
#define GPIO_27_GPIO27      27
#define GPIO_DIR_MODE_OUT   1
#define GPIO_DIR_MODE_IN    0

// 硬件资源映射 (Hardware Mapping)
// 示例: 使用 PB12 作为 GPIO_27
#define MSP_GPIO_27_PORT    GPIOB
#define MSP_GPIO_27_PIN     GPIO_PIN_12 

// 函数原型
void GPIO_setPinConfig(uint32_t pin);
void GPIO_setDirectionMode(uint32_t pin, uint32_t mode);
void GPIO_togglePin(uint32_t pin); // 新增翻转功能

// N32 风格的底层辅助函数 (参考官方例程)
void MSP_GPIO_Init(GPIO_Module* GPIOx, uint16_t Pin, GPIO_ModeType Mode);
void MSP_GPIO_Write(GPIO_Module* GPIOx, uint16_t Pin, uint8_t Val);
void MSP_GPIO_Toggle(GPIO_Module* GPIOx, uint16_t Pin);

#endif
