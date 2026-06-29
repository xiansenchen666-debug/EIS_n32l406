/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_IWTD.c
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-12-06
 * @copyright       DE.POWER
 * *****************************************************************************************************************/


#include <stdint.h>

/*******************************************************************************************************************
 * @brief      MSP_IWTD_Init
 * @attention  看门狗初始化,最小输入1000ms,最大26000.
 * @author     zhuyongjun
 *******************************************************************************************************************/
void MSP_IWTD_Init(uint16_t restTime_ms)
{
    //---------------使能IWDG寄存器---------------------
//    IWDG_WriteConfig(IWDG_WRITE_ENABLE);

//    //---------------设置延时时间ms---------------------
//    IWDG_SetPrescalerDiv(IWDG_PRESCALER_DIV256);
//    if(restTime_ms < 1000)
//    {
//        IWDG_CntReload(1 * 157);
//    }
//    else if(restTime_ms > 26000)
//    {
//        IWDG_CntReload(26 * 157);
//    }
//    else
//    {
//        IWDG_CntReload(restTime_ms / 1000 * 157);
//    }
//    /* Reload IWDG counter */
//    IWDG_ReloadKey();

//    //------------------使能内部看门狗---------------------
//    /* Enable IWDG (the LSI oscillator will be enabled by hardware) */
//    IWDG_Enable();
}


/*******************************************************************************************************************
 * @brief      MSP_IWTD_Feed
 * @attention  喂狗.
 * @author     zhuyongjun
 *******************************************************************************************************************/
void MSP_IWTD_Feed(void)
{
    /* Reload IWDG counter */
//    IWDG_ReloadKey();
}