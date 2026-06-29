/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_IWTD.h
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-12-06
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#ifndef _MSP_IWTD_H_
#define _MSP_IWTD_H_

#include <stdint.h>
/*******************************************************************************************************************
 * @brief      MSP_IWTD_Init
 * @attention  看门狗初始化,最小输入1000ms,最大26000.
 * @author     zhuyongjun
 *******************************************************************************************************************/
extern void MSP_IWTD_Init(uint16_t restTime_ms);

/*******************************************************************************************************************
 * @brief      MSP_IWTD_Feed
 * @attention  喂狗.
 * @author     zhuyongjun
 *******************************************************************************************************************/
extern void MSP_IWTD_Feed(void);
    
#endif