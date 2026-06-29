/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            main.h
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-07-03
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#ifndef __MAIN_H__
#define __MAIN_H__

#include "n32l40x.h"
#include "BSP_BQ7982X_DATA_TYPES.h"
#include "BSP_BQ7982X.h"
#include "math.h"               // 标准数学库

#ifndef _FLOAT32_T_DEFINED
#define _FLOAT32_T_DEFINED
typedef float float32_t;
typedef double float64_t;
#endif


// DDS 正弦波生成器 (用于软件生成 MCU 参考波形)
typedef struct {
    volatile uint32_t phase_accumulator;  
    uint32_t phase_increment;             
    float amplitude;                      
    float frequency;                      
    float update_rate;                    
    float *sin_table;                     
    uint16_t table_size;                  
} dds_sine_gen_t;


/* 系统任务调度 */
extern volatile uint32_t gSysTickCnt;
extern volatile uint32_t gEisSysTickCnt;
//
///* 任务标志位 */
extern volatile bool gTaskReadVoltage;
extern volatile bool gTaskDigitalSync;
extern volatile bool gTaskEisDFE;
extern volatile bool gTaskEisDFT;
extern volatile bool gTaskEisRead;
extern volatile bool gTaskStartEisQuery; // <-- Added for PC query
extern volatile bool gTaskStartSingleEisQuery;
extern volatile bool gTaskStopEisQuery;
extern volatile bool gTaskSetEisFreq;
extern volatile bool gTaskWakeStackQuery;
extern volatile bool gTaskBqResetQuery;
extern volatile bool gTaskBqSleepQuery;
extern volatile float32_t gEisRequestedFreq;
extern volatile uint8_t gEisConfigOverride;
extern volatile uint32_t gEisRequestedDftLength;
extern volatile float32_t gEisRequestedHpfHz;
extern volatile uint8_t gEisRequestedDsr;
//
///* 状态标志 */
extern volatile uint8_t eis_run_flag;
//
///* BQ7982x 设备实例 */
extern bq7982x_dev_t gBQDev[TOTALBOARDS];

/* 任务函数声明 */
uint8_t SysTask_Dignostic(void);
void SysTask_ReadEis(void);
void SysTask_DigitalSync(void);
void SysTask_SetEisDFE(void);
void SysTask_StartEisDFT(void);

/* 延时函数 */
void DEVICE_DELAY_US(uint32_t us);

#endif
