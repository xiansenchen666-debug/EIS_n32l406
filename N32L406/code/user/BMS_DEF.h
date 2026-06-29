/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            BMS_DEF.c
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-02-15
 * @copyright       DE.POWER
 * *****************************************************************************************************************/

#ifndef __BMS_DEF_H__
#define __BMS_DEF_H__

// <<< Use Configuration Wizard in Context Menu >>>

#define DEBUG

#define ENTRY_SLEEP_TIME (600*1000)                                  // 进入休眠时间
#define IDLE_HOLD_TIMEOUT (ENTRY_SLEEP_TIME)                        // 空闲状态保持最少时间
#define COMM_IDLE_TIMEOUT (ENTRY_SLEEP_TIME)                        // 通信空闲判断时间阈值,单位毫秒
#define KEY_IDLE_TIMEOUT (ENTRY_SLEEP_TIME)                         // 按键空闲判断时间阈值,单位毫秒
#define NORMAL_LEAST_HOLDTIME (ENTRY_SLEEP_TIME)                    // 保持在NORMAL状态的最少时间

#define ENTRY_SHUTDOWN_TIME (60*1000)                               // 进入shutdown时间
#define NORMAL_SUV_SHUTDOWN_TIMEOUT (ENTRY_SHUTDOWN_TIME)           // 在NORMAL状态时,触发SUV保护进入shutdown延时
#define NORMAL_ENTRY_SHUTDOWN_HOLDTIME (ENTRY_SHUTDOWN_TIME)        // 保持在NORMAL状态的最少时间
#define LONGWAKE_SHUTDOWN_VOLTAGE (2800)                            // 在LONGWAKE状态时,电压低于该值时进入shutdown模式,单位毫伏


// <o>BMS Modecheck current threshold<0-2000>
//  <i>BMS充放电状态判断电流阈值 Default: 200
#define BMS_MODECHECK_CURRENT_THRESHOLD (100)

// <<< end of configuration section >>>
#endif