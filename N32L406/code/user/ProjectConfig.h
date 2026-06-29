/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            ProjectConfig.h
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-02-15
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#ifndef _PROJECTCONFIG_H_
#define _PROJECTCONFIG_H_

#include "n32l40x.h"
#include "BMS_DEF.h"



/**********************************************************************************************/
//============================================================================
//                            宏函数定义
//============================================================================
//位操作
#define SETBIT(x, y)            ((x) |= (1 << (y)))
#define CLRBIT(x, y)            ((x) &= ~(1 << (y)))
#define GETBIT(x, y)            (((x) >> (y)) & 0x01)
#define WRTBIT(x, y, z)						((x) = (y << (z)))

#define SETBIT16(x, y)          ((x) |= ((u16)1 << (y)))
#define CLRBIT16(x, y)          ((x) &= ~((u16)1 << (y)))
#define GETBIT16(x, y)          (((x) >> (y)) & 0x0001)

#define SETBIT32(x, y)          ((x) |= ((u32)1 << (y)))
#define CLRBIT32(x, y)          ((x) &= ~((u32)1 << (y)))
#define GETBIT32(x, y)          (((x) >> (y)) & 0x00000001)
#define IsEqual(x, y)           ((x) == (y))
#define IsNotEqual(a,b)         ((a)!=(b))  //a不等于b返回1 否则返回0

#define IsInside(x1, x, x2)     (((x1) <= (x)) && ((x) <= (x2)))
/**********************************************************************************************/


#define FLASH_BOOT_ADDR_START 0x8000000
#define VECT_TAB_OFFSET (((uint32_t)&Load$$LR$$LR_IROM1$$Base) - FLASH_BOOT_ADDR_START)



extern void systick_init(void);
extern void DEVICE_DELAY_US(uint32_t us);
extern void DEVICE_DELAY_MS(uint32_t ms);

extern long reboot(void);


#endif