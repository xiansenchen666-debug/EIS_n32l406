/*
 * Copyright (c) 2025, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for abs()

#include "bsp_bq7982x.h"
#include "bsp_bq7982x_app.h"
#include "math.h"
#include "main.h"
#include "MSP_SPI.h"

#if (ACTIVECHANNELS < 6) || (ACTIVECHANNELS > 26)
#error "ACTIVECHANNELS must be in the 6..26 range for BQ7982X DEV_CONF2.NUM_CELL"
#endif

#define BQ7982X_NUM_CELL_CFG ((uint8_t)(ACTIVECHANNELS - 1u))

/**
 * BQ Device Delay Task fucntion group
 */
uint8_t BQDev_TaskStatus              = BQTaskStatus_IDLE;
volatile uint8_t BQDev_TaskDelayReady = 0;

/**
 * @brief Basic function group
 *
 */

/**
 * @brief 初始化 BQ 寄存器值为默认值 (Initialize BQ Parameters)
 *          当创建一个新的 bq7982x_dev_t 变量时，
 *          需要调用此函数来初始化该结构体
 *
 * @param pBQDev BQ 寄存器结构体指针 (Pointer to BQ register structure)
 * @param pBQSta BQ 系统状态结构体指针 (Pointer to BQ system status structure)
 */
void BQParamInit(bq7982x_dev_t *pBQDev, bq7982x_syssta_t *pBQSta)
{
    //All register default value is 0x00.

    // NVM BACKED REGISTERS
    // Need to read from BQ when NVM is programmed.
    // pBQDev->DevConf1.reg     = 0x2C;
    pBQDev->AdcCtrl2.reg     = 0x00;
    pBQDev->DevConf2.reg     = 0x00;
    pBQDev->DevConf5.reg     = 0x00;
    pBQDev->BbvcPosn2.reg    = 0x00;
    pBQDev->BbvcPosn3.reg    = 0x00;
    pBQDev->AdcConf.reg      = 0x00;
    pBQDev->DiagAdcCtrl1.reg = 0x00;
    pBQDev->GpioConf1.reg    = 0x00;
    pBQDev->GpioConf2.reg    = 0x00;
    pBQDev->GpioConf3.reg    = 0x00;
    pBQDev->GpioConf4.reg    = 0x00;
    pBQDev->GpioConf5.reg    = 0x00;
    pBQDev->GpioConf6.reg    = 0x00;
    pBQDev->GpioConf7.reg    = 0x00;
    pBQDev->GpioConf8.reg    = 0x00;
    pBQDev->GpioConf9.reg    = 0x00;
    pBQDev->GpioConf10.reg    = 0x00;

    // Dua to ID can be 0, set default value to -1
    pBQSta->BrokenNodeID         = -1;
    pBQSta->FaultNode            = -1;
    pBQSta->BrokenNodeID_Reverse = -1;
    pBQSta->FaultNode_Reverse    = -1;
    pBQSta->CANIDSet             = -1;
}

/**
 * @brief 唤醒所有堆栈设备 (Wakeup All Stack Devices)
 *        发送唤醒 Ping 并通过写命令唤醒 daisy chain 中的所有设备
 *
 * @param None
 *
 * @return None
 *
 */
void WakeStackDevice(void)
{
    // Ensure pins are in GPIO mode for Wake Ping
    Wake798XX_PingInit();
    Wake798XX();                         //Wake stack1
    
    // Switch GPIO to SPI mode after Wake Ping
    MSP_SPI_Init(mySPI0_BASE);

    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms    
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms    
#if (TOTALBOARDS > 1)
     //wake stack device
    WriteReg(0, BQ7982X_CONTROL1_OFFSET, 0x20, 1, FRMWRT_ALL_W);
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
    DEVICE_DELAY_US(15000); //Delay 12ms
#endif
    // WriteRegUART(0, 0x309, 0x20, 1, FRMWRT_SGL_W);  //Wake stack1+
    // DEVICE_DELAY_US((TOTALBOARDS - 1) * 12*2*1000);
}
/**
 * @brief 睡眠唤醒所有堆栈设备 (Sleep Wakeup All Stack Devices)
 *        使用较短的唤醒信号唤醒设备
 *
 * @param None
 *
 * @return None
 *
 */
void SleepWakeStackDevice(void)
{
    // Ensure pins are in GPIO mode for Wake Ping
    Wake798XX_PingInit();
    SleepWake798XX();                         //Wake stack1
    
    // Switch GPIO to SPI mode after Wake Ping
    MSP_SPI_Init(mySPI0_BASE);

    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
     //Sleepwake stack device
     WriteReg(0, BQ7982X_CONTROL1_OFFSET, 0x10, 1, FRMWRT_ALL_W);

    // WriteRegUART(0, 0x309, 0x20, 1, FRMWRT_SGL_W);  //Wake stack1+
    // DEVICE_DELAY_US((TOTALBOARDS - 1) * 12*2*1000);
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
    DEVICE_DELAY_US(12000); //Delay 12ms
}
//**********************
//AUTO ADDRESS SEQUENCE
//**********************
/**
 * @brief 自动寻址序列 (Auto Addressing Sequence)
 *        自动为堆栈中的每个设备分配地址，并读取分配的地址以确认
 *
 * @param AddResponse 地址响应缓冲区 (Address Response Buffer)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 */
void AutoAddress(uint8_t * AddResponse, uint8_t * ReadBuf)
{
    uint32_t currentBoard = 0;

    //  //disable timeout replaced by DIStimeout API
    //  WriteReg(0, BQ7982X_DEBUG_CTRL_UNLOCK_OFFSET, 0xA506, 2, FRMWRT_SGL_W);

     //ENABLE AUTO ADDRESSING MODE
     WriteReg(0, BQ7982X_CONTROL2_OFFSET, 0x08, 1, FRMWRT_ALL_W);

     //SET ADDRESSES FOR EVERY BOARD
     for(currentBoard=0; currentBoard<TOTALBOARDS; currentBoard++)
     {
         //ADDRESS NON-TOP-OF-STACK DEVICES
         WriteReg(0, BQ7982X_COML_CTRL_OFFSET, currentBoard, 1, FRMWRT_ALL_W);

         //SET TOP OF STACK
         if(currentBoard+1 == TOTALBOARDS)
         {
             WriteReg(currentBoard, BQ7982X_CONTROL2_OFFSET, 0x08, 1, FRMWRT_SGL_W);
             WriteReg(currentBoard, BQ7982X_COML_CTRL_OFFSET, 0x80 | currentBoard, 1, FRMWRT_SGL_W);
         }
     }
    
    ReadReg(0, BQ7982X_COML_CTRL_OFFSET, ReadBuf, 1, 0, FRMWRT_ALL_R);
    for(currentBoard=0; currentBoard<TOTALBOARDS; currentBoard++)
    {
        *AddResponse++ = ReadBuf[currentBoard*7 + 4] & 0x3F;
    }
     //OPTIONAL: read back all device addresses
    //  for(currentBoard=0; currentBoard<TOTALBOARDS; currentBoard++)
    //  {
    //     ReadReg(currentBoard, BQ7982X_COML_CTRL_OFFSET, ReadBuf, 1, 0, FRMWRT_SGL_R);
    //     *AddResponse++ = ReadBuf[4] & 0x3F;
    //  }

    // return;
}

//**************************
//END AUTO ADDRESS SEQUENCE
//**************************

// /**
//  * @brief Cell balance function group
//  *
//  */


// /**
//  * @brief Set the Cell balance Time
//  *
//  * @param BQID BQ device ID
//  * @param pBQDev BQ device
//  * @param CellNum
//  *          0 ~ 14: Cell number to set
//  *          0: is set all cell with same time
//  * @param CBTime Cell balance time in second, please refer to datasheet
//  *                0 <= uCbTime <= 36000
//  * @param Writetype Register write type
//  * @return uint32_t the actual CB time set to bq device.
//  *          -1: CBTime invalid
//  *          -2: CellNum invalid
//  */
// typedef struct {
//     uint16_t CBT;
//     uint8_t CBTReg;
// } BQ_CBTime_Table_t;
// #define CellBalanceTimeTable_LEN 32
// const BQ_CBTime_Table_t CellBalanceTimeTable[CellBalanceTimeTable_LEN] = {
//     {0, 0x00}, {30, 0x01}, {60, 0x02}, {300, 0x03}, {600, 0x04}, {1200, 0x05},
//     {1800, 0x06}, {2400, 0x07}, {3000, 0x08}, {3600, 0x09}, {4200, 0x0A},
//     {4800, 0x0B}, {5400, 0x0C}, {6000, 0x0D}, {6600, 0x0E}, {7200, 0x0F},
//     {9000, 0x10}, {10800, 0x11}, {12600, 0x12}, {14400, 0x13}, {16200, 0x14},
//     {18000, 0x15}, {19800, 0x16}, {21600, 0x17}, {23400, 0x18}, {25200, 0x19},
//     {27000, 0x1A}, {28800, 0x1B}, {30600, 0x1C}, {32400, 0x1D}, {34200, 0x1E},
//     {36000, 0x1F}};
// uint32_t SetCbTime(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t CellNum,
//     uint32_t CBTime, uint8_t Writetype)
// {
//     uint8_t bID_temp        = 0;
//     uint32_t uCbTime_actual = 0;

//     uint32_t i = 0;

//     for (i = 0; i < CellBalanceTimeTable_LEN; i++) {
//         if (CBTime <= CellBalanceTimeTable[i].CBT) {
//             break;
//         }
//     }
//     if (i == CellBalanceTimeTable_LEN) {
//         return -1;
//     }
//     uCbTime_actual              = CellBalanceTimeTable[i].CBT;
//     pBQDev->CbCellxCtrl.fs.time = CellBalanceTimeTable[i].CBTReg;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     if (CellNum == 0) {
//         for (i = CB_CELL14_CTRL; i < CB_CELL1_CTRL; i++) {
//             WriteReg(bID_temp, i, pBQDev->CbCellxCtrl.reg, 1, Writetype);
//         }
//     } else if ((CellNum >= 1) && (CellNum <= 14)) {
//         WriteReg(bID_temp, 0x324 + (14 - CellNum), pBQDev->CbCellxCtrl.reg, 1,
//             Writetype);
//     } else {
//         return -2;
//     }

//     return uCbTime_actual;
// }

// /**
//  * @brief Set the BAL_CTRL1 PWM
//  *
//  * @param BQID BQ device ID
//  * @param pBQDev BQ device
//  * @param Duty from 1 to 100 integer
//  * @param Writetype Register write type
//  * @return uint8_t Register value
//  */
// uint8_t SetBalCtrlPWM(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Duty, uint8_t Writetype)
// {
//     uint8_t bID_temp  = 0;
//     uint8_t Duty_temp = 0;

//     Duty_temp = (Duty * 63) / 100;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     pBQDev->BalCtrl1.fs.pwm = Duty_temp;

//     WriteReg(bID_temp, BAL_CTRL1, pBQDev->BalCtrl1.reg, 1, Writetype);

//     return Duty_temp;
// }

// /**
//  * @brief Set cell balancing configuration.
//  *          Including balancing type, etc.
//  *          Then start balance control.
//  *
//  * @param BQID BQ device ID
//  * @param pBQDev Cell balance configuration
//  *                  BAL_CTRL2
//  *                  DEV_CONF1
//  * @param Writetype Register write type
//  * @return uint8_t
//  */
// uint8_t StartBalCtrl(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Writetype)
// {
//     uint8_t bID_temp              = 0;
//     uint8_t rtn                   = 0;
//     pBQDev->BalCtrl2.fs.auto_bal  = 0;
//     pBQDev->BalCtrl2.fs.bal_go    = 1;
//     pBQDev->DevConf1.fs.no_adj_cb = 1;
//     //initiate the cell CBTWARN
//     pBQDev->DevConf1.fs.cbtwarn_dis = 1;
//     pBQDev->DevConf1.fs.twarn_thr   = 0;
//     //enable OTCB_EN
//     pBQDev->BalCtrl2.fs.otcb_en = 0;
//     //enable unmask fault stop
//     pBQDev->BalCtrl2.fs.fltstop_en = 0;  // not used
//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     rtn = WriteReg(bID_temp, DEV_CONF1, pBQDev->DevConf1.reg, 1, Writetype);
//     rtn = WriteReg(bID_temp, BAL_CTRL2, pBQDev->BalCtrl2.reg, 1, Writetype);

//     return rtn;
// }

// /**
//  * @brief Set the OTCB threshold for the OTUT comparator.
//  *
//  * @param BQID BQ device ID
//  * @param pBQDev Cell balance configuration
//  *              Read pBQDev->BalCtrl2.fs.otcb_en
//  *              Set pBQDev->OtcbThresh depending on OTCBThrVal
//  * @param OTCBThrVal OTCB threshold value, from 5% to 24% or 56% to 63%
//  *              When pBQDev->BalCtrl2.fs.otcb_en == 0
//  *                  OTCBThrVal range from 5 to 24
//  *              When pBQDev->BalCtrl2.fs.otcb_en == 1
//  *                  OTCBThrVal range from 56 to 63
//  * @param Writetype Register write type
//  * @return uint8_t OTCBThresh value written to the BQ register
//  */
// typedef struct {
//     uint16_t OTCBThr;
//     uint8_t OTCBThrReg;
// } BQ_OTCBThr_Table_t;
// #define OTCBThreshTable0_LEN 13
// #define OTCBThreshTable1_LEN 8
// const BQ_OTCBThr_Table_t OTCBThreshTable0[OTCBThreshTable0_LEN] = {{5, 0x00},
//     {6, 0x01}, {7, 0x02}, {8, 0x03}, {9, 0x04}, {10, 0x05}, {12, 0x06},
//     {14, 0x07}, {16, 0x08}, {18, 0x09}, {20, 0x0A}, {22, 0x0B}, {24, 0x0C}};
// const BQ_OTCBThr_Table_t OTCBThreshTable1[OTCBThreshTable1_LEN] = {{56, 0x00},
//     {57, 0x01}, {58, 0x02}, {59, 0x03}, {60, 0x04}, {61, 0x05}, {62, 0x06},
//     {63, 0x07}};
// uint8_t OTCBInit(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t OTCBThrVal, uint8_t Writetype)
// {
//     uint8_t bID_temp        = 0;
//     uint16_t OTCBThrVal_rtn = 0;
//     ;

//     uint32_t i = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     if (pBQDev->BalCtrl2.fs.otcb_en == 0) {
//         for (i = 0; i < OTCBThreshTable0_LEN; i++) {
//             if (OTCBThrVal <= OTCBThreshTable0[i].OTCBThr) {
//                 break;
//             }
//         }
//         if (i == OTCBThreshTable0_LEN) {
//             return -1;
//         }
//         pBQDev->OtcbThresh.fs.otcb_thr = OTCBThreshTable0[i].OTCBThrReg;
//         OTCBThrVal_rtn                 = OTCBThreshTable0[i].OTCBThr;
//     } else {
//         for (i = 0; i < OTCBThreshTable1_LEN; i++) {
//             if (OTCBThrVal <= OTCBThreshTable1[i].OTCBThr) {
//                 break;
//             }
//         }
//         if (i == OTCBThreshTable1_LEN) {
//             return -1;
//         }
//         pBQDev->OtcbThresh.fs.otcb_thr = OTCBThreshTable1[i].OTCBThrReg;
//         OTCBThrVal_rtn                 = OTCBThreshTable1[i].OTCBThr;
//     }

//     WriteReg(bID_temp, OTCB_THRESH, pBQDev->OtcbThresh.reg, 1, Writetype);

//     return OTCBThrVal_rtn;
// }

// /**
//  * @brief Set the UVCB threshold.
//  *
//  * @param BQID BQ device ID
//  * @param pBQDev Cell balance configuration
//  *          VCBDONE_THRESH
//  *          OVUV_CTRL2
//  * @param VCBDThrVal VCBDONE_THRESH
//  *          If a cell’s voltage < this threshold, the cell balancing on that cell stops.
//  *          Please refer to Datasheet 6.5.3.2.30 VCBDONE_THRESH for details.
//  *          VCBDThrVal = 2000:25:5000, or can be any integer from 2000 to 5000
//  * @param Writetype Register write type
//  * @return uint8_t Actual voltage set to VCBDONE_THRESH
//  *          -1: VCBDThrVal invalid.
//  */
// uint16_t UVCBInit(uint8_t BQID, bq78706_dev_t *pBQDev, uint16_t VCBDThrVal,
//     uint8_t Writetype)
// {
//     pBQDev->OvuvCtrl2.fs.ovuv_go   = 0b1;
//     pBQDev->OvuvCtrl2.fs.ovuv_mode = 0b01;
//     uint8_t bID_temp               = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     if (VCBDThrVal == 0) {
//         pBQDev->VcbdoneThresh.fs.cb_thr = 0;
//     } else if ((VCBDThrVal >= 2000) && (VCBDThrVal <= 5000)) {
//         pBQDev->VcbdoneThresh.fs.cb_thr = (VCBDThrVal - 1975) / 25;
//     } else {
//         return -1;
//     }

//     WriteReg(
//         bID_temp, VCBDONE_THRESH, pBQDev->VcbdoneThresh.reg, 1, Writetype);
//     WriteReg(bID_temp, OVUV_CTRL2, pBQDev->OvuvCtrl2.reg, 1, Writetype);

//     return ((pBQDev->VcbdoneThresh.fs.cb_thr - 1) * 25) + 2000;
// }

/**
 * @brief 暂停所有电池均衡 (Pause All Cell Balancing)
 *        设置 BalCtrl2 寄存器以暂停均衡
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev 电池均衡配置结构体 (Cell balance configuration structure)
 *              使用其中的 BAL_CTRL2 成员
 * @param Writetype 寄存器写类型 (Register write type)
 * @return uint8_t 写入结果 (Result)
 */
uint8_t PauseBalCtrl(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }

    pBQDev->BalCtrl2.fs.cb_pause = 1;
    pBQDev->BalCtrl2.fs.bal_go   = 0;
    return WriteReg(bID_temp, BQ7982X_BAL_CTRL2_OFFSET, pBQDev->BalCtrl2.reg, 1, Writetype);
}

/**
 * @brief 恢复正常电池均衡操作 (Resume Normal Cell Balancing)
 *        清除 BalCtrl2 寄存器中的暂停标志
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev 电池均衡配置结构体 (Cell balance configuration structure)
 *              使用其中的 BAL_CTRL2 成员
 * @param Writetype 寄存器写类型 (Register write type)
 * @return uint8_t 写入结果 (Result)
 */
uint8_t ResumeBalCtrl(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }

    pBQDev->BalCtrl2.fs.cb_pause = 0;
    pBQDev->BalCtrl2.fs.bal_go   = 0;
    return WriteReg(bID_temp, BQ7982X_BAL_CTRL2_OFFSET, pBQDev->BalCtrl2.reg, 1, Writetype);
}

/**
 * @brief 获取 BQ 设备的电池均衡状态 (Get Cell Balance Status)
 *        读取 BAL_STAT 寄存器
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev 电池均衡配置结构体 (Cell balance configuration structure)
 *              更新其中的 BAL_STAT 成员
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 寄存器读类型 (Register read type)
 * @return uint8_t 读取帧的长度 (Length of read frame)
 */
uint8_t GetBalSts(
    uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;

    if (Readtype == FRMWRT_SGL_R) {
        bID_temp = BQID;
    }

    rtn = ReadReg(bID_temp, BQ7982X_BAL_STAT_OFFSET, ReadBuf, 1, 0, Readtype);

    // Please take care of these read back data
    // if Readtype is Stack or All devices read.
    pBQDev->BalStat.reg = ReadBuf[4] & 0x3F;

    return rtn;
}

/**
 * @brief 获取均衡剩余时间 (Get Balance Remain Time)
 *        读取 BAL_TIME 寄存器
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev 电池均衡配置结构体 (Cell balance configuration structure)
 *              使用 BAL_CTRL3, BAL_TIME 成员
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 寄存器读类型 (Register read type)
 * @return int16_t 电池均衡剩余时间(秒) (Cell balance remain time in seconds)
 *                  -1: Readtype 无效 (Invalid Readtype)
 */
int16_t GetBalRemainTime(
    uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp     = 0;
    uint16_t BalTime_rtn = 0;
    uint8_t Writetype    = 0;

    if (Readtype == FRMWRT_SGL_R) {
        bID_temp  = BQID;
        Writetype = FRMWRT_SGL_W;
    } else if (Readtype == FRMWRT_STK_R) {
        Writetype = FRMWRT_STK_W;
    } else if (Readtype == FRMWRT_ALL_R) {
        Writetype = FRMWRT_ALL_W;
    } else {
        return -1;
    }
    pBQDev->BalCtrl3.fs.bal_time_sel = 0;  // channel 1
    pBQDev->BalCtrl3.fs.bal_time_go  = 1;
    WriteReg(bID_temp, BQ7982X_BAL_CTRL3_OFFSET, pBQDev->BalCtrl3.reg, 1, Writetype);

    ReadReg(bID_temp, BQ7982X_BAL_TIME_OFFSET, ReadBuf, 1, 0, Readtype);

    // Please take care of these read back data
    // if Readtype is Stack or All devices read.
    pBQDev->BalTime.reg = ReadBuf[4] & 0x3F;

    if (pBQDev->BalTime.fs.time_unit == 0) {
        BalTime_rtn = pBQDev->BalTime.fs.time * 300;
    } else {
        BalTime_rtn = pBQDev->BalTime.fs.time * 5;
    }

    return BalTime_rtn;
}

// /**
//  * @brief ADC, GPIO function group
//  *
//  */

// uint8_t AdcCtrlInit(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Writetype)
// {
//     uint8_t bID_temp = 0;
//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     pBQDev->AdcCtrl2.fs.lpf_vcell    = 0b010;  // LPF=39Hz
//     pBQDev->AdcCtrl2.fs.lpf_vcell_en = 0b1;    // enable
//     pBQDev->AdcCtrl2.fs.adc_mode     = 0b10;   // continous mode
//     pBQDev->DevConf2.fs.num_cell     = 0x07;   // 13cell, if 18 cell set 0x0B;
// #ifdef NOBUSBAR
//     pBQDev->DevConf2.fs.bb_pin_en = 0b0;  // busbar not used
//     pBQDev->DevConf2.fs.ptc_en    = 0b1;  // PTC_EN used
// #else
//     pBQDev->DevConf2.fs.bb_pin_en = 0b1;
//     pBQDev->DevConf2.fs.bb_pin_loc =
//         0b10;  // 9s is busbar; customer configure by their project
//     pBQDev->BbvcPosn2.fs.cell9 = 0b1;
// #endif
//     pBQDev->AdcConf.fs.adc_dly         = 0x00;  // 0us
//     pBQDev->DiagAdcCtrl1.fs.vcell_filt = 0b0;   // 8 samples
//     pBQDev->DiagAdcCtrl1.fs.vcell_thr =
//         0b000110;  // The VC vs. CB check is considered to pass if the measured delta is < this threshold 6mV

//     WriteReg(bID_temp, ADC_CTRL2, pBQDev->AdcCtrl2.reg, 1, Writetype);
//     WriteReg(bID_temp, DEV_CONF2, pBQDev->DevConf2.reg, 1, Writetype);
//     WriteReg(bID_temp, DEV_CONF5, pBQDev->DevConf5.reg, 1, Writetype);
//     WriteReg(bID_temp, BBVC_POSN2, pBQDev->BbvcPosn2.reg, 1, Writetype);
//     WriteReg(bID_temp, BBVC_POSN3, pBQDev->BbvcPosn3.reg, 1, Writetype);
//     WriteReg(bID_temp, ADC_CONF, pBQDev->AdcConf.reg, 1, Writetype);
//     WriteReg(bID_temp, DIAG_ADC_CTRL1, pBQDev->DiagAdcCtrl1.reg, 1, Writetype);

//     return 0;
// }

// uint8_t GpioConfInit(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Writetype)
// {
//     pBQDev->GpioConf2.fs.gpio3  = ADC_RATIO;
//     pBQDev->GpioConf2.fs.gpio4  = ADC_RATIO;
//     pBQDev->GpioConf3.fs.gpio5  = ADC_RATIO;
//     pBQDev->GpioConf3.fs.gpio6  = ADC_RATIO;
//     pBQDev->GpioConf4.fs.gpio7  = ADC_RATIO;
//     pBQDev->GpioConf4.fs.gpio8  = ADC_RATIO;
//     pBQDev->GpioConf5.fs.gpio9  = OUTPUT_H;
//     pBQDev->GpioConf5.fs.gpio10 = OUTPUT_H;
//     pBQDev->GpioConf6.fs.gpio11 = OUTPUT_L;

//     uint8_t bID_temp = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     WriteReg(bID_temp, GPIO_CONF1, pBQDev->GpioConf1.reg, 1, Writetype);
//     WriteReg(bID_temp, GPIO_CONF2, pBQDev->GpioConf2.reg, 1, Writetype);
//     WriteReg(bID_temp, GPIO_CONF3, pBQDev->GpioConf3.reg, 1, Writetype);
//     WriteReg(bID_temp, GPIO_CONF4, pBQDev->GpioConf4.reg, 1, Writetype);
//     WriteReg(bID_temp, GPIO_CONF5, pBQDev->GpioConf5.reg, 1, Writetype);
//     WriteReg(bID_temp, GPIO_CONF6, pBQDev->GpioConf6.reg, 1, Writetype);
//     WriteReg(bID_temp, ADC_CTRL1, pBQDev->AdcCtrl1.reg, 1, Writetype);

//     return 0;
// }

// uint8_t AdcConversion(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Writetype)
// {
//     uint8_t bID_temp           = 0;
//     pBQDev->AdcCtrl2.fs.adc_go = 1;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     WriteReg(bID_temp, ADC_CTRL2, pBQDev->AdcCtrl2.reg, 1, Writetype);

//     return 0;
// }

// uint8_t GetADCStatus(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp = 0;

//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp = BQID;
//     }

//     ReadReg(bID_temp, ADC_DATA_RDY, ReadBuf, 1, 0, Readtype);
//     pBQDev->AdcDataRdy.reg = ReadBuf[4] & 0xFF;  // Debug ADC status
//     ReadReg(bID_temp, DEV_STAT1, ReadBuf, 1, 0, Readtype);
//     pBQDev->DevStat1.reg = ReadBuf[4] & 0xFF;  // Debug ADC status

//     return 0;
// }
// uint8_t ADCReadyCheck(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp = 0;
//     uint8_t rtn      = 0;

//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp = BQID;
//     }
//     do {
//         rtn = GetADCStatus(bID_temp, pBQDev, ReadBuf, Readtype);
//     } while ((pBQDev->AdcDataRdy.fs.drdy_vcelladc == 0) ||
//              (pBQDev->AdcDataRdy.fs.drdy_gpadc == 0) ||
//              (pBQDev->DevStat1.fs.vcelladc_run == 0) ||
//              (pBQDev->DevStat1.fs.gpadc_run == 0));
//     return rtn;
// }

// uint8_t GetADCDiagStatus(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp = 0;
//     uint8_t rtn      = 0;

//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp = BQID;
//     }

//     rtn = ReadReg(bID_temp, DIAG_STAT2, ReadBuf, 1, 0, Readtype);
//     pBQDev->DiagStat1.reg = ReadBuf[4] & 0xFF;  // Debug ADC status
//     return rtn;
// }

/**
 * @brief 获取电芯电压 (Get Cell Voltage)
 *        从 BQ 设备读取所有活动通道的电芯电压
 *        并转换为实际电压值存入结构体
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体指针 (BQ Device structure pointer)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (Read Type)
 * @return uint8_t 读取结果 (Result)
 */
uint8_t GetVCell(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;
    uint8_t i,j;

    if (Readtype == FRMWRT_SGL_R) {
        bID_temp = BQID;
    }

    // Read from BQ VCELL14_HI to VCELL1_LO, 28 bytes in total
    ReadReg(bID_temp, BQ7982X_VCELL26_HI_OFFSET + (26 - ACTIVECHANNELS) * 2, ReadBuf, ACTIVECHANNELS * 2, 0, Readtype);

    if (Readtype == FRMWRT_SGL_R) {
        for (i = 0; i < ACTIVECHANNELS; i++) {
            pBQDev[bID_temp].VcellSinglex[ACTIVECHANNELS * 2 - i * 2 - 2] =
                ReadBuf[4 + i * 2];
            pBQDev[bID_temp].VcellSinglex[ACTIVECHANNELS * 2 - i * 2 - 1] =
                ReadBuf[5 + i * 2];
            pBQDev[bID_temp].Vcellx[ACTIVECHANNELS - i - 1] =
                ((ReadBuf[4 + i * 2] << 8) + (ReadBuf[5 + i * 2])) *
                VLSB_STANDARD_F;
        }
    } else if (Readtype == FRMWRT_ALL_R) {
        for (j = 0; j < TOTALBOARDS; j++) {
            for (i = 0; i < ACTIVECHANNELS; i++) {
                pBQDev[TOTALBOARDS - 1 - j]
                    .VcellSinglex[ACTIVECHANNELS * 2 - i * 2 - 2] =
                    ReadBuf[j * (ACTIVECHANNELS * 2 + 6) + 4 + i * 2];
                pBQDev[TOTALBOARDS - 1 - j]
                    .VcellSinglex[ACTIVECHANNELS * 2 - i * 2 - 1] =
                    ReadBuf[j * (ACTIVECHANNELS * 2 + 6) + 5 + i * 2];
                pBQDev[TOTALBOARDS - 1 - j].Vcellx[ACTIVECHANNELS - i - 1] =
                    (
                        // Need to confirm whether each board will have 4 extra bytes to ignore
                        // (j+1) is each board have 4 extra bytes
                        (ReadBuf[j * (ACTIVECHANNELS * 2 + 6) + 4 + i * 2]
                            << 8) +
                        (ReadBuf[j * (ACTIVECHANNELS * 2 + 6) + 5 + i * 2])) *
                    VLSB_STANDARD_F;
            }
        }
    }

    return rtn;
}


// Hardware related
// 3 4 5 6 is single channel
// 7 8 connected mux
// 9 10 11 mux control
// 3 4 5 6 is single channel
// 7 8 connected mux
// 9 10 11 mux control
uint8_t VGpio_conf[2] = {OUTPUT_L, OUTPUT_H};

/**
 * @brief 控制 TMUX GPIO (TMUX GPIO Control)
 *        用于控制外部多路复用器，通过 GPIO 9, 10, 11 切换通道
 *        并触发 ADC 转换
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体指针 (BQ Device structure pointer)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Writetype 写入类型 (Write Type)
 * @return int8_t 结果 (Result)
 */
int8_t TMUX_GPIO(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Writetype)
{
    uint8_t bID_temp     = 0;
    static uint8_t rdSeq = 0;
    uint8_t Readtype     = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
        Readtype = FRMWRT_SGL_R;
    } else if (Writetype == FRMWRT_STK_W) {
        Readtype = FRMWRT_STK_R;
    } else if (Writetype == FRMWRT_ALL_W) {
        Readtype = FRMWRT_ALL_R;
    } else {
        return -1;
    }
    ReadReg(bID_temp, BQ7982X_GPIO_STAT1_OFFSET, ReadBuf, 1, 0, Readtype);
    pBQDev->GpioStat1.reg = ReadBuf[4];

    pBQDev->GpioConf5.fs.gpio9  = VGpio_conf[rdSeq & 0x01];
    pBQDev->GpioConf5.fs.gpio10 = VGpio_conf[(rdSeq & 0x02) >> 1];
    pBQDev->GpioConf6.fs.gpio11 = VGpio_conf[(rdSeq & 0x04) >> 2];

    // Standard steps
    // Set GPIO output H/L
    // Delay
    // Read GPIO voltage
    rdSeq++;
    if (rdSeq == 8) {
        rdSeq = 0;
    }
    WriteReg(bID_temp, BQ7982X_GPIO_CONF5_OFFSET, pBQDev->GpioConf5.reg, 1, Writetype);
    WriteReg(bID_temp, BQ7982X_GPIO_CONF6_OFFSET, pBQDev->GpioConf6.reg, 1, Writetype);
    WriteReg(bID_temp, BQ7982X_ADC_CTRL2_OFFSET, pBQDev->AdcCtrl2.reg, 1, Writetype);
    return 0;
}

int8_t BQ7982X_SetGpio20High(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    } else if (Writetype != FRMWRT_STK_W && Writetype != FRMWRT_ALL_W) {
        return -1;
    }

    pBQDev->GpioConf10.fs.gpio20 = OUTPUT_H;
    WriteReg(bID_temp, BQ7982X_GPIO_CONF10_OFFSET, pBQDev->GpioConf10.reg, 1, Writetype);
    WriteReg(bID_temp, BQ7982X_GPIO_OUT3_OFFSET, BQ7982X_GPIO_OUT3_GPIO20_MSK, 1, Writetype);

    return 0;
}

int8_t BQ7982X_SoftReset(uint8_t BQID, uint8_t Writetype)
{
    uint8_t bID_temp = 0;
    int8_t rtn = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    } else if (Writetype != FRMWRT_STK_W && Writetype != FRMWRT_ALL_W) {
        return -1;
    }

    rtn = (int8_t)WriteReg(bID_temp, BQ7982X_CONTROL1_OFFSET, BQ7982X_CONTROL1_SOFT_RESET_MSK, 1, Writetype);
    DEVICE_DELAY_US(15000);
    DEVICE_DELAY_US(15000);

    return rtn;
}
/**
 * @brief 获取 GPIO 电压 (Get GPIO Voltage)
 *        读取 GPIO 通道的 ADC 转换结果
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体指针 (BQ Device structure pointer)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (Read Type)
 * @return uint8_t 读取结果 (Result)
 */
int8_t BQ7982X_GotoSleep(uint8_t BQID, uint8_t Writetype)
{
    uint8_t bID_temp = 0;
    int8_t rtn = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    } else if (Writetype != FRMWRT_STK_W && Writetype != FRMWRT_ALL_W) {
        return -1;
    }

    rtn = (int8_t)WriteReg(bID_temp, BQ7982X_CONTROL1_OFFSET, BQ7982X_CONTROL1_GOTO_SLEEP_MSK, 1, Writetype);
    DEVICE_DELAY_US(15000);
    DEVICE_DELAY_US(15000);

    return rtn;
}

uint8_t GetVGpio(
    uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;
    float VLSB_GPIO  = 0;
    uint8_t i,j;

    if (Readtype == FRMWRT_SGL_R) {
        bID_temp = BQID;
    }

    if (pBQDev->GpioConf1.fs.gpio1 == ADC_RATIO ||
        pBQDev->GpioConf1.fs.gpio2 == ADC_RATIO ||
        pBQDev->GpioConf2.fs.gpio3 == ADC_RATIO ||
        pBQDev->GpioConf2.fs.gpio4 == ADC_RATIO ||
        pBQDev->GpioConf3.fs.gpio5 == ADC_RATIO ||
        pBQDev->GpioConf3.fs.gpio6 == ADC_RATIO ||
        pBQDev->GpioConf4.fs.gpio7 == ADC_RATIO ||
        pBQDev->GpioConf4.fs.gpio8 == ADC_RATIO ||
        pBQDev->GpioConf5.fs.gpio9 == ADC_RATIO ||
        pBQDev->GpioConf5.fs.gpio10 == ADC_RATIO ||
        pBQDev->GpioConf6.fs.gpio11 == ADC_RATIO ||
        pBQDev->GpioConf6.fs.gpio12 == ADC_RATIO ||
        pBQDev->GpioConf7.fs.gpio13 == ADC_RATIO ||
        pBQDev->GpioConf7.fs.gpio14 == ADC_RATIO ||
        pBQDev->GpioConf8.fs.gpio15 == ADC_RATIO ||
        pBQDev->GpioConf8.fs.gpio16 == ADC_RATIO ||
        pBQDev->GpioConf9.fs.gpio17 == ADC_RATIO ||
        pBQDev->GpioConf9.fs.gpio18 == ADC_RATIO ||
        pBQDev->GpioConf10.fs.gpio19 == ADC_RATIO ||
        pBQDev->GpioConf10.fs.gpio20 == ADC_RATIO ) {
        VLSB_GPIO = VLSB_GPIO_RATIO;
    } else {
        VLSB_GPIO = VLSB_STANDARD_F;
    }

    rtn = ReadReg(bID_temp, BQ7982X_GPIO1_HI_OFFSET, ReadBuf, GADC_ACTIVECHANNEL * 2, 0, Readtype);
    if (Readtype == FRMWRT_SGL_R) {
        for (i = 0; i < GADC_ACTIVECHANNEL; i++) {
            pBQDev[bID_temp].VGPIOSinglex[GADC_ACTIVECHANNEL * 2 - i * 2 - 2] =
                ReadBuf[4 + i * 2];
            pBQDev[bID_temp].VGPIOSinglex[GADC_ACTIVECHANNEL * 2 - i * 2 - 1] =
                ReadBuf[5 + i * 2];
            pBQDev[bID_temp].GPIOxVoltage[GADC_ACTIVECHANNEL - i - 1] =
                ((ReadBuf[4 + i * 2] << 8) + (ReadBuf[5 + i * 2])) * VLSB_GPIO;
        }
    } else if (Readtype == FRMWRT_ALL_R) {
        for (j = 0; j < TOTALBOARDS; j++) {
            for (i = 0; i < GADC_ACTIVECHANNEL; i++) {
                pBQDev[j].VGPIOSinglex[GADC_ACTIVECHANNEL * 2 - i * 2 - 2] =
                    ReadBuf[j * (GADC_ACTIVECHANNEL * 2 + 6) + 4 + i * 2];
                pBQDev[j].VGPIOSinglex[GADC_ACTIVECHANNEL * 2 - i * 2 - 1] =
                    ReadBuf[j * (GADC_ACTIVECHANNEL * 2 + 6) + 5 + i * 2];
                pBQDev[j].GPIOxVoltage[GADC_ACTIVECHANNEL - i - 1] =
                    (
                        // Need to confirm whether each board will have 4 extra bytes to ignore
                        // (j+1) is each board have 4 extra bytes
                        (ReadBuf[j * (GADC_ACTIVECHANNEL * 2 + 6) + 4 + i * 2]
                            << 8) +
                        (ReadBuf[j * (GADC_ACTIVECHANNEL * 2 + 6) + 5 +
                                 i * 2])) *
                    VLSB_GPIO;
            }
        }
    }

    return rtn;
}

/**
 * @brief 冻结 DLPF (Digital Low Pass Filter) (DLPF Freeze)
 *        暂停低通滤波器，并等待状态确认
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体指针 (BQ Device structure pointer)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (Read Type)
 * @return int8_t 结果 (Result)
 */
int8_t DLPF_freeze(
    uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp  = 0;
    uint8_t rtn       = 0;
    uint8_t Writetype = 0;

    if (Readtype == FRMWRT_SGL_R) {
        bID_temp  = BQID;
        Writetype = FRMWRT_SGL_W;
    } else if (Readtype == FRMWRT_STK_R) {
        Writetype = FRMWRT_STK_W;
    } else if (Readtype == FRMWRT_ALL_R) {
        Writetype = FRMWRT_ALL_W;
    } else {
        return -1;
    }

    // pBQDev->AdcCtrl3.fs.freeze_lpf_en = 1;
    WriteReg(bID_temp, BQ7982X_ADC_CTRL3_OFFSET, pBQDev->AdcCtrl3.reg, 1, Writetype);//temp for EIS
    do {
        // Read from BQ DIAG_STAT1
        rtn = ReadReg(bID_temp, BQ7982X_DIAG_STAT1_OFFSET, ReadBuf, 1, 0, Readtype);
        // Need to confirm the data structure.
        pBQDev->DiagStat1.reg = ReadBuf[4];
    } while (pBQDev->DiagStat1.fs.freeze_lpf_active == 0);

    return rtn;
}

/**
 * @brief 解冻 DLPF (DLPF Defreeze)
 *        恢复低通滤波器运行，并等待状态确认
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体指针 (BQ Device structure pointer)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (Read Type)
 * @return int8_t 结果 (Result)
 */
int8_t DLPF_Defreeze(
    uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp  = 0;
    uint8_t rtn       = 0;
    uint8_t Writetype = 0;

    if (Readtype == FRMWRT_SGL_R) {
        bID_temp  = BQID;
        Writetype = FRMWRT_SGL_W;
    } else if (Readtype == FRMWRT_STK_R) {
        Writetype = FRMWRT_STK_W;
    } else if (Readtype == FRMWRT_ALL_R) {
        Writetype = FRMWRT_ALL_W;
    } else {
        return -1;
    }

    // pBQDev->AdcCtrl3.fs.freeze_lpf_en = 0;
    WriteReg(bID_temp, BQ7982X_ADC_CTRL3_OFFSET, pBQDev->AdcCtrl3.reg, 1, Writetype); //temp for EIS

    // Read verify, waiting for BQ device exit freeze mode.
    do {
        // Read from BQ DIAG_STAT1
        rtn = ReadReg(bID_temp, BQ7982X_DIAG_STAT1_OFFSET, ReadBuf, 1, 0, Readtype);
        // Need to confirm the data structure.
        pBQDev->DiagStat1.reg = ReadBuf[4];
    } while (pBQDev->DiagStat1.fs.freeze_lpf_active == 1);

    return rtn;
}

// /**
//  * @brief ADC, GPIO function group
//  *
//  */

// uint8_t GetAllFaults(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp = 0;
//     uint8_t rtn      = 0;

//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp = BQID;
//     }

//     rtn = ReadReg(bID_temp, FAULT_SUMMARY, ReadBuf, 1, 0, Readtype);

//     // Single device's fault process.
//     pBQDev->FaultSummary.reg = ReadBuf[4];

// // Read back Level 2 fault register
// #if 1
//     // Example for reading the pwr fault details
//     if (pBQDev->FaultSummary.fs.fault_pwr == 1) {
//         ReadReg(bID_temp, FAULT_PWR1, ReadBuf, 2, 0, Readtype);
//         pBQDev->FaultPwr1.reg = ReadBuf[4];
//         pBQDev->FaultPwr2.reg = ReadBuf[5];
//     } else {
//         pBQDev->FaultPwr1.reg = 0;
//         pBQDev->FaultPwr2.reg = 0;
//     }

//     if (pBQDev->FaultSummary.fs.fault_comm == 1) {
//         ReadReg(bID_temp, FAULT_COMM, ReadBuf, 1, 0, Readtype);
//         pBQDev->FaultComm.reg = ReadBuf[4];
//     }

//     if (pBQDev->FaultSummary.fs.fault_otp == 1) {
//         ReadReg(bID_temp, FAULT_OTP, ReadBuf, 1, 0, Readtype);
//         pBQDev->FaultOtp.reg = ReadBuf[4];
//     } else {
//         pBQDev->FaultOtp.reg = 0;
//     }
// #endif
//     return rtn;
// }

uint8_t ResetAllFaults(
    uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Writetype)
{
    uint8_t bID_temp = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }

    WriteReg(bID_temp, BQ7982X_FAULT_RST1_OFFSET, 0xFFFFFF, 3, Writetype);

//     // Customer Task: clear other level 2 and level 3 fault.

    return 0;
}

uint8_t MaskAllFaults(
    uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Writetype)
{
    uint8_t bID_temp = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }

    return WriteReg(bID_temp, BQ7982X_FAULT_MSK1_OFFSET, 0xFFFFFF, 3, Writetype);
}

// uint8_t GpioOpnWrUpdate(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp  = 0;
//     float ABS_A_B     = 0;
//     uint8_t Writetype = 0;
//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp  = BQID;
//         Writetype = FRMWRT_SGL_W;
//     } else if (Readtype == FRMWRT_STK_R) {
//         Writetype = FRMWRT_STK_W;
//     } else if (Readtype == FRMWRT_ALL_R) {
//         Writetype = FRMWRT_ALL_W;
//     } else {
//         return -1;
//     }
//     switch (BQDev_TaskStatus) {
//         case BQTaskStatus_IDLE:
//             GetVGpio(bID_temp, pBQDev, ReadBuf, Readtype);

//             for (int i = 0; i < GADC_ACTIVECHANNEL; i++) {
//                 // Convert GPIOx's voltage depending on GPIOx_HI + GPIOx_LO
//                 pBQDev->GPIOxVoltageA[i] = (pBQDev->GPIOxVoltage[i]) / 100 * 4;

//                 if (pBQDev->GPIOxVoltageA[i] > 2) {
//                     // Set GPIO to weak pull-down
//                     switch (i) {
//                         case 2: {
//                             // Configure GPIO3 to ADC absolute power-down mode
//                             pBQDev->GpioConf2.fs.gpio3 = ADC_ABS_PD;
//                             break;
//                         }
//                         case 4: {
//                             // Configure GPIO5 to ADC absolute power-down mode
//                             pBQDev->GpioConf3.fs.gpio5 = ADC_ABS_PD;
//                             break;
//                         }
//                         case 6: {
//                             // Configure GPIO7 to ADC absolute power-down mode
//                             pBQDev->GpioConf4.fs.gpio7 = ADC_ABS_PD;
//                             break;
//                         }
//                         default: {
//                             // Handle unexpected values of 'i' (e.g., ignore or log an error)
//                             break;
//                         }
//                     }
//                 } else {
//                     // Set GPIO to weak pull-up
//                     // Todo: how to set GPIO to weak pull-down or pull-up?
//                     switch (i) {
//                         case 2: {
//                             // Configure GPIO3 to ADC absolute power-down mode
//                             pBQDev->GpioConf2.fs.gpio3 = ADC_ABS_PU;
//                             break;
//                         }
//                         case 4: {
//                             // Configure GPIO5 to ADC absolute power-down mode
//                             pBQDev->GpioConf3.fs.gpio5 = ADC_ABS_PU;
//                             break;
//                         }
//                         case 6: {
//                             // Configure GPIO7 to ADC absolute power-down mode
//                             pBQDev->GpioConf4.fs.gpio7 = ADC_ABS_PU;
//                             break;
//                         }
//                         default: {
//                             // Handle unexpected values of 'i' (e.g., ignore or log an error)
//                             break;
//                         }
//                     }
//                 }
//             }
//             WriteReg(
//                 bID_temp, GPIO_CONF1, pBQDev->GpioConf1.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF2, pBQDev->GpioConf2.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF3, pBQDev->GpioConf3.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF4, pBQDev->GpioConf4.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF5, pBQDev->GpioConf5.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF6, pBQDev->GpioConf6.reg, 1, Writetype);
//             AdcConversion(bID_temp, pBQDev, Writetype);
//             ADCReadyCheck(bID_temp, pBQDev, ReadBuf, Readtype);
//             BQDev_TaskStatus = BQTaskStatus_GpioOpn_WaitDelay;
//             // Start delay task interrrupt
//             DL_Timer_setLoadValue(TIMER_BQTASK_INST, BQTask_GpioOpn_DelayTime);
//             DL_Timer_startCounter(TIMER_BQTASK_INST);
//             break;

//         case BQTaskStatus_GpioOpn_WaitDelay:
//             GetVGpio(bID_temp, pBQDev, ReadBuf, Readtype);

//             for (int i = 0; i < GADC_ACTIVECHANNEL; i++) {
//                 // Convert GPIOx's voltage depending on GPIOx_HI + GPIOx_LO
//                 pBQDev->GPIOxVoltageB[i] = pBQDev->GPIOxVoltage[i];

//                 if (pBQDev->GPIOxVoltageB[i] > pBQDev->GPIOxVoltageA[i]) {
//                     ABS_A_B =
//                         pBQDev->GPIOxVoltageB[i] - pBQDev->GPIOxVoltageA[i];
//                 } else {
//                     ABS_A_B =
//                         pBQDev->GPIOxVoltageA[i] - pBQDev->GPIOxVoltageB[i];
//                 }

//                 if (ABS_A_B > 1) {
//                     // Open Wire Fail
//                     // Customer task
//                 } else {
//                     // Open Wire Pass
//                     // Customer task
//                 }
//             }
//             pBQDev->GpioConf2.fs.gpio3 = ADC_RATIO;
//             pBQDev->GpioConf3.fs.gpio5 = ADC_RATIO;
//             pBQDev->GpioConf4.fs.gpio7 = ADC_RATIO;
//             WriteReg(
//                 bID_temp, GPIO_CONF1, pBQDev->GpioConf1.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF2, pBQDev->GpioConf2.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF3, pBQDev->GpioConf3.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF4, pBQDev->GpioConf4.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF5, pBQDev->GpioConf5.reg, 1, Writetype);
//             WriteReg(
//                 bID_temp, GPIO_CONF6, pBQDev->GpioConf6.reg, 1, Writetype);
//             AdcConversion(bID_temp, pBQDev, Writetype);
//             ADCReadyCheck(bID_temp, pBQDev, ReadBuf, Readtype);
//             BQDev_TaskStatus = BQTaskStatus_IDLE;
//             break;

//         default:
//             // BQDev_TaskStatus is not IDLE or valid value.
//             return -1;
//             break;
//     }
//     return 0;
// }

// uint8_t CellOpnWrUpdate(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp = 0;

//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp = BQID;
//     }

//     GetVCell(bID_temp, pBQDev, ReadBuf, Readtype);

//     // Customer task

//     return 0;
// }

// uint8_t AcompDiag(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp  = 0;
//     uint8_t Writetype = 0;

//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp  = BQID;
//         Writetype = FRMWRT_SGL_W;
//     } else if (Readtype == FRMWRT_STK_R) {
//         Writetype = FRMWRT_STK_W;
//     } else if (Readtype == FRMWRT_ALL_R) {
//         Writetype = FRMWRT_ALL_W;
//     } else {
//         return -1;
//     }

//     switch (BQDev_TaskStatus) {
//         case BQTaskStatus_IDLE:
//             GetBalSts(bID_temp, pBQDev, ReadBuf, Readtype);
//             if (pBQDev->BalStat.fs.cb_run == 1) {
//                 // Pause cell balance
//                 DL_GPIO_setPins(GPIOB, LED_GREEN_PIN);
//                 PauseBalCtrl(bID_temp, pBQDev, Writetype);
//                 // Waiting for cell balance is paused.
//                 do {
//                     GetBalSts(bID_temp, pBQDev, ReadBuf, Readtype);
//                 } while (pBQDev->BalStat.fs.cb_inpause == 0);
//             }
//             // Need to set ADC CTRL1, CTRL2 by write pBQDev
//             WriteReg(bID_temp, DIAG_ADC_CTRL1, pBQDev->DiagAdcCtrl1.reg, 1,
//                 Writetype);
//             pBQDev->DiagAdcCtrl2.fs.gpio_thr = 6;
//             WriteReg(bID_temp, DIAG_ADC_CTRL2, pBQDev->DiagAdcCtrl2.reg, 1,
//                 Writetype);
//             // Start ACOMP and DCOMP
//             pBQDev->DiagAdcCtrl3.fs.diag_dig_en   = 1;
//             pBQDev->DiagAdcCtrl3.fs.diag_ana_mode = 0b11;
//             // 0b11 = Both cell voltage measurement analog path diagnostic and GPIO measurement analog path diagnostic
//             // 0b01 = Cell voltage measurement analog path diagnostic is performed.
//             // 0b10 = GPIO measurement analog path diagnostic is performed (applies to GPIO configured as “ADC and OTUT inputs” or “ADC only input”).
//             pBQDev->DiagAdcCtrl3.fs.diag_ana_go = 1;
//             WriteReg(bID_temp, DIAG_ADC_CTRL3, pBQDev->DiagAdcCtrl3.reg, 1,
//                 Writetype);
//             // Ensure diagnostic is running
//             do {
//                 ReadReg(bID_temp, DEV_STAT1, ReadBuf, 2, 0, Readtype);
//                 pBQDev->DevStat1.reg = ReadBuf[4];
//                 pBQDev->DevStat2.reg = ReadBuf[5];
//             } while ((pBQDev->DevStat1.fs.diag_ana_run == 0) ||
//                      (pBQDev->DevStat2.fs.diag_dig_run == 0));

//             BQDev_TaskStatus = BQTaskStatus_AcompDiag_WaitDelay;
//             // Start delay task interrrupt
//             if (pBQDev->DiagAdcCtrl1.fs.vcell_filt == 0) {
//                 DL_Timer_setLoadValue(
//                     TIMER_BQTASK_INST, BQTask_AcompDiag_DelayTime0);
//             } else {
//                 DL_Timer_setLoadValue(
//                     TIMER_BQTASK_INST, BQTask_AcompDiag_DelayTime1);
//             }
//             DL_Timer_startCounter(TIMER_BQTASK_INST);
//             break;

//         case BQTaskStatus_AcompDiag_WaitDelay:
//             ReadReg(bID_temp, FAULT_ADC_MISC, ReadBuf, 1, 0, Readtype);
//             pBQDev->FaultAdcMisc.reg = ReadBuf[4];
//             if (pBQDev->FaultAdcMisc.reg != 0) {
//                 // Diagnostic failed.
//                 return -2;
//             }
//             do {
//                 ReadReg(bID_temp, DIAG_STAT1, ReadBuf, 2, 0, Readtype);
//                 pBQDev->DiagStat1.reg = ReadBuf[4];
//                 pBQDev->DiagStat2.reg = ReadBuf[5];
//             } while (
//                 (pBQDev->DiagStat2.fs.drdy_ana_gpio !=
//                     1) ||  // 0 is (pBQDev->DiagStat2.fs.drdy_ana_gpio != 1)
//                 (pBQDev->DiagStat2.fs.drdy_ana_vcell != 1) ||
//                 (0));  // 0 is pBQDev->DiagStat2.fs.drdy_dig != 1

//             ReadReg(bID_temp, DIAG_STAT1, ReadBuf, 2, 0, Readtype);
//             pBQDev->DiagStat1.reg = ReadBuf[4];
//             pBQDev->DiagStat2.reg = ReadBuf[5];
//             if ((pBQDev->DiagStat2.fs.drdy_ana_gpio != 1) ||
//                 (pBQDev->DiagStat2.fs.drdy_ana_vcell != 1) ||
//                 0) {  //0 is (pBQDev->DiagStat2.fs.drdy_dig != 1)
//                 // DRDY failed.
//                 return -3;
//             }

//             // Read faults
//             ReadReg(bID_temp, FAULT_ADC_GPIO1, ReadBuf, 2, 0, Readtype);
//             pBQDev->FaultAdcGpio1.reg = ReadBuf[4];
//             pBQDev->FaultAdcGpio2.reg = ReadBuf[5];
//             ReadReg(bID_temp, FAULT_ADC_VCELL1, ReadBuf, 3, 0, Readtype);
//             pBQDev->FaultAdcVcell1.reg = ReadBuf[4];
//             pBQDev->FaultAdcVcell2.reg = ReadBuf[5];
//             pBQDev->FaultAdcVcell3.reg = ReadBuf[6];

//             //Reset ADC faults
//             WriteReg(bID_temp, FAULT_RST2, 0x08, 1, Writetype);

//             // Ensure all ADC faults are cleared.
//             ReadReg(bID_temp, FAULT_ADC_GPIO1, ReadBuf, 2, 0, Readtype);
//             if ((ReadBuf[4] != 0) || (ReadBuf[5] != 0)) {
//                 // return -4;
//             }
//             ReadReg(bID_temp, FAULT_ADC_VCELL1, ReadBuf, 3, 0, Readtype);
//             if ((ReadBuf[4] != 0) || (ReadBuf[5] != 0) || (ReadBuf[6] != 0)) {
//                 // return -4;
//             }

//             ResumeBalCtrl(bID_temp, pBQDev, Writetype);
//             DL_GPIO_clearPins(GPIOB, LED_GREEN_PIN);
//             BQDev_TaskStatus = BQTaskStatus_IDLE;
//             break;

//         default:
//             // BQDev_TaskStatus is not IDLE or valid value.
//             return -1;
//             break;
//     }

//     return 0;
// }

// uint8_t OTP(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Writetype)
// {
//     uint8_t bID_temp = 0;
//     uint8_t Readtype = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//         Readtype = FRMWRT_SGL_R;
//     } else if (Writetype == FRMWRT_STK_W) {
//         Readtype = FRMWRT_STK_R;
//     } else if (Writetype == FRMWRT_ALL_W) {
//         Readtype = FRMWRT_ALL_R;
//     } else {
//         return -1;
//     }

//     switch (BQDev_TaskStatus) {
//         case BQTaskStatus_IDLE:
//             ReadReg(bID_temp, CUST_MISC1, ReadBuf, 1, 0,
//                 Readtype);  // just to verify if CUST_MISC1 has written.
//             pBQDev->OtpProgUnlock1.reg = 0xBC;
//             pBQDev->OtpProgUnlock2.reg = 0x6F;
//             WriteReg(bID_temp, OTP_PROG_UNLOCK1, pBQDev->OtpProgUnlock1.reg, 1,
//                 Writetype);
//             WriteReg(bID_temp, OTP_PROG_UNLOCK2, pBQDev->OtpProgUnlock2.reg, 1,
//                 Writetype);

//             do {
//                 ReadReg(bID_temp, OTP_STAT, ReadBuf, 1, 0, Readtype);
//                 pBQDev->OtpStat.reg = ReadBuf[4];
//             } while (((pBQDev->OtpStat.fs.unlock != 1) ||
//                       (pBQDev->OtpStat.fs.loader != 0) ||
//                       (pBQDev->OtpStat.fs.uv_ovok != 0) ||
//                       (pBQDev->OtpStat.fs._try != 0)));

//             // Start OTP programming
//             pBQDev->Control2.fs.prog_go = 1;
//             WriteReg(bID_temp, CONTROL2, pBQDev->Control2.reg, 1, Writetype);

//             BQDev_TaskStatus = BQTaskStatus_OTP_WaitDelay;
//             // Start task delay timer
//             DL_Timer_setLoadValue(TIMER_BQTASK_INST, BQTask_OTP_DelayTime);
//             DL_Timer_startCounter(TIMER_BQTASK_INST);
//             break;

//         case BQTaskStatus_OTP_WaitDelay:
//             ReadReg(bID_temp, OTP_STAT, ReadBuf, 1, 0, Readtype);
//             pBQDev->OtpStat.reg = ReadBuf[4];
//             if (pBQDev->OtpStat.fs.done == 0) {
//                 // OTP failed
//                 return -1;
//             }

//             // Issue a software reset
//             pBQDev->Control1.fs.soft_reset = 1;
//             WriteReg(bID_temp, CONTROL1, pBQDev->Control1.reg, 1, Writetype);

//             // Check OTP_Stat register
//             if (pBQDev->OtpStat.reg != 0xE0) {
//                 // Program failed.
//                 return -2;
//             }

//             BQDev_TaskStatus = BQTaskStatus_IDLE;
//             break;

//         default:
//             // BQDev_TaskStatus is not IDLE or valid value.
//             return -1;
//             break;
//     }

//     return 0;
// }

// uint8_t HWReset(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Writetype)
// {
//     return 0;
// }

// uint8_t CbfetDiag(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Writetype)
// {
//     // 6.3.9.3 Balancing FET Diagnostic
//     uint8_t bID_temp = 0;
//     uint8_t Readtype = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//         Readtype = FRMWRT_SGL_R;
//     } else if (Writetype == FRMWRT_STK_W) {
//         Readtype = FRMWRT_STK_R;
//     } else if (Writetype == FRMWRT_ALL_W) {
//         Readtype = FRMWRT_ALL_R;
//     } else {
//         return -1;
//     }

//     switch (BQDev_TaskStatus) {
//         case BQTaskStatus_IDLE:
//             GetBalSts(bID_temp, pBQDev, ReadBuf, Readtype);
//             if (pBQDev->BalStat.fs.cb_run == 1) {
//                 // Pause cell balance
//                 DL_GPIO_setPins(GPIOB, LED_GREEN_PIN);
//                 PauseBalCtrl(bID_temp, pBQDev, Writetype);
//                 // Waiting for cell balance is paused.
//                 do {
//                     GetBalSts(bID_temp, pBQDev, ReadBuf, Readtype);
//                 } while (pBQDev->BalStat.fs.cb_inpause == 0);
//             }

//             pBQDev->DiagMiscCtrl2.fs.diag_cbfetow_go = 1;
//             WriteReg(bID_temp, DIAG_MISC_CTRL2, pBQDev->DiagMiscCtrl2.reg, 1,
//                 Writetype);

//             BQDev_TaskStatus = BQTaskStatus_CbfetDiag_WaitDelay;
//             // Start task delay timer

//             DL_Timer_setLoadValue(
//                 TIMER_BQTASK_INST, BQTask_CbfetDiag_DelayTime);
//             DL_Timer_startCounter(TIMER_BQTASK_INST);
//             break;

//         case BQTaskStatus_CbfetDiag_WaitDelay:
//             delayms(16);
//             ReadReg(bID_temp, DIAG_STAT2, ReadBuf, 1, 0, Readtype);
//             pBQDev->DiagStat2.reg = ReadBuf[4];
//             if (pBQDev->DiagStat2.fs.drdy_cbfetow == 0) {
//                 DL_Timer_setLoadValue(TIMER_BQTASK_INST, BQTask_1MS_DelayTime);
//                 DL_Timer_startCounter(TIMER_BQTASK_INST);
//                 break;
//             }

//             ReadReg(bID_temp, FAULT_CB_FETOW1, ReadBuf, 3, 0, Readtype);
//             pBQDev->FaultCbFetow1.reg = ReadBuf[4];
//             pBQDev->FaultCbFetow2.reg = ReadBuf[5];
//             pBQDev->FaultCbFetow3.reg = ReadBuf[6];

//             ResumeBalCtrl(bID_temp, pBQDev, Writetype);
//             DL_GPIO_clearPins(GPIOB, LED_GREEN_PIN);
//             BQDev_TaskStatus = BQTaskStatus_IDLE;
//             break;

//         default:
//             // BQDev_TaskStatus is not IDLE or valid value.
//             return -1;
//             break;
//     }

//     return 0;
// }

// /**
//  * @brief
//  *
//  * @param BQID BQ device ID
//  * @param pBQDev Cell balance configuration
//  *                  DEV_CONF1
//  * @param Writetype Register write type
//  * @return uint8_t
//  */
// uint8_t OTUTInit(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Writetype)
// {
//     uint8_t bID_temp = 0;
//     uint8_t rtn      = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     pBQDev->Otutctrl2.fs.otut_mode = 0b01;
//     pBQDev->Otutctrl2.fs.otut_go   = 0b1;

//     rtn = WriteReg(bID_temp, OTUT_CTRL2, pBQDev->Otutctrl2.reg, 1, Writetype);

//     return rtn;
// }

/**
 * @brief 禁用通信超时 (Disable Communication Timeout)
 *        主要用于调试，防止调试时因断点导致芯片复位
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @param Writetype 写入类型 (Write Type)
 * @return uint8_t 写入结果 (Result)
 */
uint8_t DisableTimeout(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }
    pBQDev->DebugCtrlUnlock.reg = 0xA5;
    pBQDev->DebugCommCtrl1.fs.ct_dis = 1;   //enable com timeout 
    pBQDev->DebugCommCtrl1.fs.pspi_en = 1;  //keep PSPI work
    rtn = WriteReg(bID_temp, BQ7982X_DEBUG_CTRL_UNLOCK_OFFSET, pBQDev->DebugCtrlUnlock.reg , 1, Writetype);
    rtn = WriteReg(bID_temp, BQ7982X_DEBUG_COMM_CTRL1_OFFSET, pBQDev->DebugCommCtrl1.reg, 1, Writetype);

    return rtn;
}

/**
 * @brief 检查采样线是否断线 (Open Wire Detection Update)
 *        通过比较不同时刻的电压采样值来判断是否断线
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param MaxVol 最大电压阈值 (Max Voltage Threshold)
 * @param MinVol 最小电压阈值 (Min Voltage Threshold)
 * @param Readtype 读取类型 (Read Type)
 * @return int8_t 0: 成功, -1: 状态错误
 */
int8_t VcOpnWrUpdate(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf,
    float MaxVol, float MinVol, uint8_t Readtype)
{
    float ABS_A_B = 0;
    uint8_t i;

    switch (BQDev_TaskStatus) {
        case BQTaskStatus_IDLE:
            for (i = 0; i < ACTIVECHANNELS; i++) {
                // Convert GPIOx's voltage depending on GPIOx_HI + GPIOx_LO
                pBQDev->VcellxA[i] = pBQDev->Vcellx[i];
                if (pBQDev->VcellxA[i] == 0xFFFF ||
                    pBQDev->VcellxA[i] > MaxVol ||
                    pBQDev->VcellxA[i] < MinVol) {
                    // Open Wire Fail
                    // Customer task
                    // printf("Vcell %d Value_exceed:%f\n",i+1, pBQDev->VcellxA[i]);
                }
            }
            BQDev_TaskStatus = BQTaskStatus_VcOpn_WaitDelay;

            // Use Readvoltage delay to replace this timer delay.
            // Start delay task interrrupt
            // DL_Timer_setLoadValue(TIMER_BQTASK_INST, BQTask_VcOpn_DelayTime);
            // DL_Timer_startCounter(TIMER_BQTASK_INST);
            break;

        case BQTaskStatus_VcOpn_WaitDelay:
            // GetVCell(bID_temp, pBQDev, ReadBuf, Readtype);
            for (i = 0; i < ACTIVECHANNELS; i++) {
                // Convert GPIOx's voltage depending on GPIOx_HI + GPIOx_LO
                pBQDev->VcellxB[i] = pBQDev->Vcellx[i];
                if (pBQDev->VcellxB[i] == 0xFFFF ||
                    pBQDev->VcellxB[i] > MaxVol ||
                    pBQDev->VcellxB[i] < MinVol) {
                    // Open Wire Fail
                    // Customer task
                    // printf("GPIO %d ABS_A_B:%f\n",i+1, ABS_A_B);
                }
                if (pBQDev->VcellxB[i] > pBQDev->VcellxA[i]) {
                    ABS_A_B = pBQDev->VcellxB[i] - pBQDev->VcellxA[i];
                } else {
                    ABS_A_B = pBQDev->VcellxA[i] - pBQDev->VcellxB[i];
                }

                if (ABS_A_B > 0.5 || ABS_A_B == 0) {
                    // Open Wire Fail
                    // Customer task
                    // printf("Vcell_AB %d ABS_A_B:%f\n",i+1, ABS_A_B);
                } else {
                    // Open Wire Pass5
                    // Customer task
                    // printf("Vcell_AB %d ABS_A_B:%f\n",i+1, ABS_A_B);
                }
            }

            BQDev_TaskStatus = BQTaskStatus_IDLE;
            break;

        default:
            // BQDev_TaskStatus is not IDLE or valid value.
            return -1;
            // break;
    }
    return 0;
}

// uint8_t BusbarInit(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Writetype)
// {
//     uint8_t bID_temp = 0;
//     uint8_t rtn      = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     // 1. [BB_PIN_EN] = 0b1, [BB_PIN_LOC] = 0b00 (configure BB position).
//     pBQDev->DevConf2.fs.num_cell  = 0b0111;
//     pBQDev->DevConf2.fs.bb_pin_en = 0b1;
//     pBQDev->DevConf2.fs.bb_pin_loc =
//         0b00;  // 7s is busbar; customer configure by their project
//     WriteReg(bID_temp, DEV_CONF2, pBQDev->DevConf2.reg, 1, Writetype);
//     // pBQDev->BbvcPosn2.fs.cell9=0b1;
//     // 2. [ADC_MODE] = 0b10, [ADC_GO] = 0b1(set ADC in continuous run mode).
//     pBQDev->AdcCtrl2.fs.adc_mode = 0b10;
//     pBQDev->AdcCtrl2.fs.adc_go   = 0b1;
//     WriteReg(bID_temp, ADC_CTRL2, pBQDev->AdcCtrl2.reg, 1, Writetype);
//     // 3. [DIAG_ANA_SEL] = CHANNEL 7; [DIAG_MEAS_GO]=0b1(at this point, DIAG_RDNT_HI/MI/LO is still CB cell 7).
//     pBQDev->AdcCtrl3.fs.diag_ana_sel = 0b00111;
//     pBQDev->AdcCtrl4.fs.diag_meas_go = 0b1;
//     WriteReg(bID_temp, ADC_CTRL3, pBQDev->AdcCtrl3.reg, 1, Writetype);
//     WriteReg(bID_temp, ADC_CTRL4, pBQDev->AdcCtrl4.reg, 1, Writetype);
//     // rtn = WriteReg(bID_temp, BBVC_POSN2, pBQDev->BbvcPosn2.reg, 1, Writetype);

//     return rtn;
// }

// uint8_t GetVBusbar(
//     uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
// {
//     uint8_t bID_temp  = 0;
//     uint8_t Writetype = 0;

//     if (Readtype == FRMWRT_SGL_R) {
//         bID_temp  = BQID;
//         Writetype = FRMWRT_SGL_W;
//     } else if (Readtype == FRMWRT_STK_R) {
//         Writetype = FRMWRT_STK_W;
//     } else if (Readtype == FRMWRT_ALL_R) {
//         Writetype = FRMWRT_ALL_W;
//     } else {
//         return -1;
//     }

//     // 4. The user can enable the VC/CB comparison by [DIAG_ANA_MODE] and [DIAG_ANA_GO].
//     // 5. By the time the user would like to extract busbar IR drop: [BB_MEAS_MODE]=0b1, [DIAG_ANA_MODE] =0b00, [DIAG_ANA_GO]=0b1 (disable the VC/CB comparison, [BB_MEAS_MODE] takes effect).
//     pBQDev->DiagAdcCtrl3.fs.bb_meas_mode  = 0b1;
//     pBQDev->DiagAdcCtrl3.fs.diag_ana_mode = 0b00;
//     pBQDev->DiagAdcCtrl3.fs.diag_ana_go   = 0b1;
//     WriteReg(bID_temp, DIAG_ADC_CTRL3, pBQDev->DiagAdcCtrl3.reg, 1, Writetype);
//     // 6. [DIAG_ANA_SEL] = CHANNEL 7; [DIAG_MEAS_GO]=0b1.
//     pBQDev->AdcCtrl3.fs.diag_ana_sel = 0b00111;
//     pBQDev->AdcCtrl4.fs.diag_meas_go = 0b1;
//     WriteReg(bID_temp, ADC_CTRL3, pBQDev->AdcCtrl3.reg, 1, Writetype);
//     WriteReg(bID_temp, ADC_CTRL4, pBQDev->AdcCtrl4.reg, 1, Writetype);
//     // 7a. Wait until [DRDY_DIAG] =1, read out DIAG_RDNT_HI/MI/LO and DIAG_MAIN_HI/MI/LO
//     do {
//         // Read from BQ DIAG_STAT1
//         ReadReg(bID_temp, ADC_DATA_RDY, ReadBuf, 1, 0, Readtype);
//         // Need to confirm the data structure.
//         pBQDev->AdcDataRdy.reg = ReadBuf[4];
//     } while (pBQDev->AdcDataRdy.fs.drdy_diag == 0);
//     // 7b. Subtract DIAG_MAIN_HI/MI/LO from DIAG_RDNT_HI/MI/LO to get the busbar IR drop.
//     ReadReg(bID_temp, DIAG_MAIN_HI, ReadBuf, 6, 0, Readtype);
//     pBQDev->Diag_rdnt_cbbb =
//         ((ReadBuf[8] << 8) + ReadBuf[9]) * VLSB_STANDARD_F;
//     pBQDev->Diag_main_vc = ((ReadBuf[5] << 8) + ReadBuf[6]) * VLSB_STANDARD_F;
//     pBQDev->Vbusbar      = pBQDev->Diag_rdnt_cbbb - pBQDev->Diag_main_vc;
//     return 0;
// }

// uint8_t BusbarVCInit(uint8_t BQID, bq78706_dev_t *pBQDev, uint8_t Writetype)
// {
//     uint8_t bID_temp = 0;
//     uint8_t rtn      = 0;

//     if (Writetype == FRMWRT_SGL_W) {
//         bID_temp = BQID;
//     }

//     // 1. [CELL4] = 0b1, 4s is busbar; customer configure by their project
//     pBQDev->BbvcPosn3.fs.cell4 = 0b1;
//     WriteReg(bID_temp, BBVC_POSN3, pBQDev->BbvcPosn3.reg, 1, Writetype);
//     // pBQDev->BbvcPosn2.fs.cell9=0b1;
//     // 2. [CELL4] = 0b01, 4s is busbar; customer configure by their project
//     pBQDev->UvDisable2.fs.cell4 = 0b1;
//     WriteReg(bID_temp, UV_DISABLE2, pBQDev->UvDisable2.reg, 1, Writetype);

//     return rtn;
// }

// // send the ADC bit value to the calculation function
// void TMP61(bq78706_dev_t *pBQDev)
// {
//     // THRM calculations - 4th order polynomial regression
//     float THRM_A0  = -2.691712E+02;
//     float THRM_A1  = 5.062889E-02;
//     float THRM_A2  = -3.099051E-06;
//     float THRM_A3  = 1.153395E-10;
//     float THRM_A4  = -1.746912E-15;
//     float THRM_RES = 0;
//     float RBias    = 10000;
//     // float VBias = 4.00;
//     // calculate the resistance of the thermistor
//     if (pBQDev->GpioConf1.fs.gpio1 == ADC_RATIO ||
//         pBQDev->GpioConf1.fs.gpio2 == ADC_RATIO ||
//         pBQDev->GpioConf2.fs.gpio3 == ADC_RATIO ||
//         pBQDev->GpioConf2.fs.gpio4 == ADC_RATIO ||
//         pBQDev->GpioConf3.fs.gpio5 == ADC_RATIO ||
//         pBQDev->GpioConf3.fs.gpio6 == ADC_RATIO ||
//         pBQDev->GpioConf4.fs.gpio7 == ADC_RATIO ||
//         pBQDev->GpioConf4.fs.gpio8 == ADC_RATIO ||
//         pBQDev->GpioConf5.fs.gpio9 == ADC_RATIO ||
//         pBQDev->GpioConf5.fs.gpio10 == ADC_RATIO ||
//         pBQDev->GpioConf6.fs.gpio11 == ADC_RATIO) {
//         for (int i = 0; i < GADC_ACTIVECHANNEL; i++) {
//             THRM_RES = pBQDev->GPIOxVoltage[i] * 0.01 * RBias /
//                        (1 - pBQDev->GPIOxVoltage[i] * 0.01);
//             pBQDev->GPIOTemp[i] =
//                 (THRM_A4 * powf(THRM_RES, 4)) + (THRM_A3 * powf(THRM_RES, 3)) +
//                 (THRM_A2 * powf(THRM_RES, 2)) + (THRM_A1 * THRM_RES) + THRM_A0;
//         }
//     }
// }

// void TIMER_BQTASK_INST_IRQHandler(void)
// {
//     switch (DL_TimerG_getPendingInterrupt(TIMER_BQTASK_INST)) {
//         case DL_TIMER_IIDX_ZERO:
//             BQDev_TaskDelayReady = 1;
//             break;
//         default:
//             break;
//     }
// }


/**
 * @brief 读取 EIS 电压部分 (Read EIS Cell Voltage)
 *        读取 EIS 测得的电池电压的实部和虚部
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (Read Type)
 * @return int8_t 读取结果 (Result)
 */
int8_t Read_EIS_CV(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp  = 0;
    uint8_t Writetype = 0;
    uint8_t i, j;
    uint8_t rtn;
    float32_t vc_amp_comp = 5;

    if (Readtype == FRMWRT_SGL_R) {
        bID_temp  = BQID;
        Writetype = FRMWRT_SGL_W;
    } else if (Readtype == FRMWRT_STK_R) {
        Writetype = FRMWRT_STK_W;
    } else if (Readtype == FRMWRT_ALL_R) {
        Writetype = FRMWRT_ALL_W;
    } else {
        return -1;
    }

    // ==========================================================
    // 1. 读取 实部 (Real Portion)
    // ==========================================================
    pBQDev->EisMiscCtrl.fs.eis_res_sel = 0;     // 0: 实部
    pBQDev->EisMiscCtrl.fs.eis_res_tone = 0;    // Tone1 结果
    WriteReg(bID_temp, BQ7982X_EIS_MISC_CTRL_OFFSET, pBQDev->EisMiscCtrl.reg, 1, Writetype);

    // 第一段读取：VC1-VC13 (最多13个通道，每个通道3字节)
    uint8_t read_len1 = (ACTIVECHANNELS > 13) ? 13 * 3 : ACTIVECHANNELS * 3;
    rtn = ReadReg(bID_temp, BQ7982X_EIS_VC1_HI_OFFSET, ReadBuf, read_len1, 0, Readtype);

    if (Readtype == FRMWRT_SGL_R) {
        for (i = 0; i < ((ACTIVECHANNELS > 13) ? 13 : ACTIVECHANNELS); i++) {
            pBQDev[bID_temp].VCeis_R[i * 3]     = ReadBuf[4 + i * 3];
            pBQDev[bID_temp].VCeis_R[i * 3 + 1] = ReadBuf[5 + i * 3];
            pBQDev[bID_temp].VCeis_R[i * 3 + 2] = ReadBuf[6 + i * 3];
            
            // 24位补码转32位有符号整数
            pBQDev[bID_temp].debug[i] = (((pBQDev[bID_temp].VCeis_R[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                        (uint32_t)pBQDev[bID_temp].VCeis_R[i * 3] << 16 |
                                        (uint32_t)pBQDev[bID_temp].VCeis_R[i * 3 + 1] << 8 |
                                        (uint32_t)pBQDev[bID_temp].VCeis_R[i * 3 + 2];
            
            pBQDev[bID_temp].VCeis_R_Decode[i] = (float)pBQDev[bID_temp].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
        }
    } else if (Readtype == FRMWRT_ALL_R) {
        for (j = 0; j < TOTALBOARDS; j++) {
            for (i = 0; i < ((ACTIVECHANNELS > 13) ? 13 : ACTIVECHANNELS); i++) {
                uint16_t offset = j * (read_len1 + 6) + 4 + i * 3;
                pBQDev[j].VCeis_R[i * 3]     = ReadBuf[offset];
                pBQDev[j].VCeis_R[i * 3 + 1] = ReadBuf[offset + 1];
                pBQDev[j].VCeis_R[i * 3 + 2] = ReadBuf[offset + 2];

                pBQDev[j].debug[i] = (((pBQDev[j].VCeis_R[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                     (uint32_t)pBQDev[j].VCeis_R[i * 3] << 16 |
                                     (uint32_t)pBQDev[j].VCeis_R[i * 3 + 1] << 8 |
                                     (uint32_t)pBQDev[j].VCeis_R[i * 3 + 2];

                pBQDev[j].VCeis_R_Decode[i] = (float)pBQDev[j].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
            }
        }
    }

    // 处理超过13通道的情况 (VC14及以上)
    if (ACTIVECHANNELS > 13) {
        rtn = ReadReg(bID_temp, BQ7982X_EIS_VC14_HI_OFFSET, ReadBuf, ACTIVECHANNELS * 3 - 13 * 3, 0, Readtype);
        if (Readtype == FRMWRT_SGL_R) {
            for (i = 13; i < ACTIVECHANNELS; i++) {
                pBQDev[bID_temp].VCeis_R[i * 3]     = ReadBuf[4 + (i - 13) * 3];
                pBQDev[bID_temp].VCeis_R[i * 3 + 1] = ReadBuf[5 + (i - 13) * 3];
                pBQDev[bID_temp].VCeis_R[i * 3 + 2] = ReadBuf[6 + (i - 13) * 3];
                
                pBQDev[bID_temp].debug[i] = (((pBQDev[bID_temp].VCeis_R[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                            (uint32_t)pBQDev[bID_temp].VCeis_R[i * 3] << 16 |
                                            (uint32_t)pBQDev[bID_temp].VCeis_R[i * 3 + 1] << 8 |
                                            (uint32_t)pBQDev[bID_temp].VCeis_R[i * 3 + 2];

                pBQDev[bID_temp].VCeis_R_Decode[i] = (float)pBQDev[bID_temp].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
            }
        } else if (Readtype == FRMWRT_ALL_R) {
            for (j = 0; j < TOTALBOARDS; j++) {
                for (i = 13; i < ACTIVECHANNELS; i++) {
                    uint16_t offset = j * ((ACTIVECHANNELS - 13) * 3 + 6) + 4 + (i - 13) * 3;
                    pBQDev[j].VCeis_R[i * 3]     = ReadBuf[offset];
                    pBQDev[j].VCeis_R[i * 3 + 1] = ReadBuf[offset + 1];
                    pBQDev[j].VCeis_R[i * 3 + 2] = ReadBuf[offset + 2];

                    pBQDev[j].debug[i] = (((pBQDev[j].VCeis_R[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                         (uint32_t)pBQDev[j].VCeis_R[i * 3] << 16 |
                                         (uint32_t)pBQDev[j].VCeis_R[i * 3 + 1] << 8 |
                                         (uint32_t)pBQDev[j].VCeis_R[i * 3 + 2];

                    pBQDev[j].VCeis_R_Decode[i] = (float)pBQDev[j].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
                }
            }
        }
    }

    // ==========================================================
    // 2. 读取 虚部 (Imaginary Portion)
    // ==========================================================
    pBQDev->EisMiscCtrl.fs.eis_res_sel = 1;     // 1: 虚部
    pBQDev->EisMiscCtrl.fs.eis_res_tone = 0;    // Tone1 结果
    WriteReg(bID_temp, BQ7982X_EIS_MISC_CTRL_OFFSET, pBQDev->EisMiscCtrl.reg, 1, Writetype);

    rtn = ReadReg(bID_temp, BQ7982X_EIS_VC1_HI_OFFSET, ReadBuf, read_len1, 0, Readtype);
    
    if (Readtype == FRMWRT_SGL_R) {
        for (i = 0; i < ((ACTIVECHANNELS > 13) ? 13 : ACTIVECHANNELS); i++) {
            pBQDev[bID_temp].VCeis_I[i * 3]     = ReadBuf[4 + i * 3];
            pBQDev[bID_temp].VCeis_I[i * 3 + 1] = ReadBuf[5 + i * 3];
            pBQDev[bID_temp].VCeis_I[i * 3 + 2] = ReadBuf[6 + i * 3];

            pBQDev[bID_temp].debug[i] = (((pBQDev[bID_temp].VCeis_I[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                        (uint32_t)pBQDev[bID_temp].VCeis_I[i * 3] << 16 |
                                        (uint32_t)pBQDev[bID_temp].VCeis_I[i * 3 + 1] << 8 |
                                        (uint32_t)pBQDev[bID_temp].VCeis_I[i * 3 + 2];

            pBQDev[bID_temp].VCeis_I_Decode[i] = (float)pBQDev[bID_temp].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
        }
    } else if (Readtype == FRMWRT_ALL_R) {
        for (j = 0; j < TOTALBOARDS; j++) {
            for (i = 0; i < ((ACTIVECHANNELS > 13) ? 13 : ACTIVECHANNELS); i++) {
                uint16_t offset = j * (read_len1 + 6) + 4 + i * 3;
                pBQDev[j].VCeis_I[i * 3]     = ReadBuf[offset];
                pBQDev[j].VCeis_I[i * 3 + 1] = ReadBuf[offset + 1];
                pBQDev[j].VCeis_I[i * 3 + 2] = ReadBuf[offset + 2];

                pBQDev[j].debug[i] = (((pBQDev[j].VCeis_I[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                     (uint32_t)pBQDev[j].VCeis_I[i * 3] << 16 |
                                     (uint32_t)pBQDev[j].VCeis_I[i * 3 + 1] << 8 |
                                     (uint32_t)pBQDev[j].VCeis_I[i * 3 + 2];

                pBQDev[j].VCeis_I_Decode[i] = (float)pBQDev[j].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
            }
        }
    }

    if (ACTIVECHANNELS > 13) {
        rtn = ReadReg(bID_temp, BQ7982X_EIS_VC14_HI_OFFSET, ReadBuf, ACTIVECHANNELS * 3 - 13 * 3, 0, Readtype);
        if (Readtype == FRMWRT_SGL_R) {
            for (i = 13; i < ACTIVECHANNELS; i++) {
                pBQDev[bID_temp].VCeis_I[i * 3]     = ReadBuf[4 + (i - 13) * 3];
                pBQDev[bID_temp].VCeis_I[i * 3 + 1] = ReadBuf[5 + (i - 13) * 3];
                pBQDev[bID_temp].VCeis_I[i * 3 + 2] = ReadBuf[6 + (i - 13) * 3];

                pBQDev[bID_temp].debug[i] = (((pBQDev[bID_temp].VCeis_I[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                            (uint32_t)pBQDev[bID_temp].VCeis_I[i * 3] << 16 |
                                            (uint32_t)pBQDev[bID_temp].VCeis_I[i * 3 + 1] << 8 |
                                            (uint32_t)pBQDev[bID_temp].VCeis_I[i * 3 + 2];

                pBQDev[bID_temp].VCeis_I_Decode[i] = (float)pBQDev[bID_temp].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
            }
        } else if (Readtype == FRMWRT_ALL_R) {
            for (j = 0; j < TOTALBOARDS; j++) {
                for (i = 13; i < ACTIVECHANNELS; i++) {
                    uint16_t offset = j * ((ACTIVECHANNELS - 13) * 3 + 6) + 4 + (i - 13) * 3;
                    pBQDev[j].VCeis_I[i * 3]     = ReadBuf[offset];
                    pBQDev[j].VCeis_I[i * 3 + 1] = ReadBuf[offset + 1];
                    pBQDev[j].VCeis_I[i * 3 + 2] = ReadBuf[offset + 2];

                    pBQDev[j].debug[i] = (((pBQDev[j].VCeis_I[i * 3] & (1 << 7)) == 0x80) ? 0xFF000000 : 0x00000000) |
                                         (uint32_t)pBQDev[j].VCeis_I[i * 3] << 16 |
                                         (uint32_t)pBQDev[j].VCeis_I[i * 3 + 1] << 8 |
                                         (uint32_t)pBQDev[j].VCeis_I[i * 3 + 2];

                    pBQDev[j].VCeis_I_Decode[i] = (float)pBQDev[j].debug[i] * 4096 / (8388608.0) * (1 / 0.30517) * (1 / vc_amp_comp) / (float)(pBQDev->dft_len_struct) * 2;
                }
            }
        }
    }

    return rtn;
}


/**
 * @brief 读取 EIS 电流部分 (Read EIS Cell Current)
 *        读取 EIS 测得的电流通道的实部和虚部
 *
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (Read Type)
 * @return int8_t 读取结果 (Result)
 */
int8_t Read_EIS_CC(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp  = 0;
    uint8_t Writetype = 0;
    uint8_t rtn;
    uint8_t i,j;
    float32_t cs_direction = -1;//EVM
    float32_t cs_amp_comp = 5;
    
    // 分流电阻值 (Shunt Resistor)
    if (Readtype == FRMWRT_SGL_R) {
        bID_temp  = BQID;
        Writetype = FRMWRT_SGL_W;
    } else if (Readtype == FRMWRT_STK_R) {
        Writetype = FRMWRT_STK_W;
    } else if (Readtype == FRMWRT_ALL_R) {
        Writetype = FRMWRT_ALL_W;
    } else {
        return -1;
    }
    //1.read the real portion first
    pBQDev->EisMiscCtrl.fs.eis_res_sel = 0;    //real portion
    pBQDev->EisMiscCtrl.fs.eis_res_tone = 0;    //tone1 result
    WriteReg(0, BQ7982X_EIS_MISC_CTRL_OFFSET, pBQDev->EisMiscCtrl.reg, 1, Writetype);
    rtn = ReadReg(bID_temp, BQ7982X_EIS_CS_HI_OFFSET, ReadBuf, ACTIVECHANNELS_C*3, 0, Readtype);
    if (Readtype == FRMWRT_SGL_R) {
        for (i = 0; i < ACTIVECHANNELS_C; i++) {
            pBQDev[bID_temp].CSeis_R[i * 3] = ReadBuf[4 + i * 3];
            pBQDev[bID_temp].CSeis_R[i * 3 + 1] = ReadBuf[5 + i * 3];
            pBQDev[bID_temp].CSeis_R[i * 3 + 2] = ReadBuf[6 + i * 3];
            pBQDev[bID_temp].debug[i] = 
            (((pBQDev[bID_temp].CSeis_R[i * 3] & (1 << 7)) == 0x80)? 0xFF000000:0x00000000) | 
            (uint32_t)pBQDev[bID_temp].CSeis_R[i * 3] << 16 | 
            (uint32_t)pBQDev[bID_temp].CSeis_R[i * 3 + 1] << 8 | 
            (uint32_t)pBQDev[bID_temp].CSeis_R[i * 3 + 2];
            
            pBQDev[bID_temp].CSeis_R_Decode[i] =(float)pBQDev[bID_temp].debug[i] * cs_direction * 
                5120.0 / (8388608.0) * (1 / 0.3725) * (1 / cs_amp_comp) /(pBQDev->dft_len_struct) * 2;
        }
    } else if (Readtype == FRMWRT_ALL_R) {
        for (j = 0; j < TOTALBOARDS; j++) {
            for (i = 0; i < ACTIVECHANNELS_C; i++) {
                pBQDev[j].CSeis_R[i * 3] = ReadBuf[j * (ACTIVECHANNELS_C * 3 + 6) + 4 + i * 3];
                pBQDev[j].CSeis_R[i * 3 + 1] = ReadBuf[j * (ACTIVECHANNELS_C * 3 + 6) + 5 + i * 3];
                pBQDev[j].CSeis_R[i * 3 + 2] = ReadBuf[j * (ACTIVECHANNELS_C * 3 + 6) + 6 + i * 3];
                pBQDev[j].debug[i] = 
                (((pBQDev[j].CSeis_R[i * 3] & (1 << 7)) == 0x80)? 0xFF000000:0x00000000) | 
                (uint32_t)pBQDev[j].CSeis_R[i * 3] << 16 | 
                (uint32_t)pBQDev[j].CSeis_R[i * 3 + 1] << 8 | 
                (uint32_t)pBQDev[j].CSeis_R[i * 3 + 2];
                
                pBQDev[j].CSeis_R_Decode[i] =(float)pBQDev[j].debug[i] * cs_direction * 
                 5120.0 / (8388608.0) * (1 / 0.3725) * (1 / cs_amp_comp) /(pBQDev->dft_len_struct) * 2;
            }
        }
    }
    //2.read the imag portion next
    pBQDev->EisMiscCtrl.fs.eis_res_sel = 1;    //imag portion
    pBQDev->EisMiscCtrl.fs.eis_res_tone = 0;    //tone1 result
    WriteReg(0, BQ7982X_EIS_MISC_CTRL_OFFSET, pBQDev->EisMiscCtrl.reg, 1, Writetype);
    rtn = ReadReg(bID_temp, BQ7982X_EIS_CS_HI_OFFSET, ReadBuf, ACTIVECHANNELS_C*3, 0, Readtype);
    if (Readtype == FRMWRT_SGL_R) {
        for (i = 0; i < ACTIVECHANNELS_C; i++) {
            pBQDev[bID_temp].CSeis_I[i * 3] = ReadBuf[4 + i * 3];
            pBQDev[bID_temp].CSeis_I[i * 3 + 1] = ReadBuf[5 + i * 3];
            pBQDev[bID_temp].CSeis_I[i * 3 + 2] = ReadBuf[6 + i * 3];
            pBQDev[bID_temp].debug[i] = 
            (((pBQDev[bID_temp].CSeis_I[i * 3] & (1 << 7)) == 0x80)? 0xFF000000:0x00000000) | 
            (uint32_t)pBQDev[bID_temp].CSeis_I[i * 3] << 16 | 
            (uint32_t)pBQDev[bID_temp].CSeis_I[i * 3 + 1] << 8 | 
            (uint32_t)pBQDev[bID_temp].CSeis_I[i * 3 + 2];
            
            pBQDev[bID_temp].CSeis_I_Decode[i] =(float)pBQDev[bID_temp].debug[i] * cs_direction * 
             5120.0 / (8388608.0) * (1 / 0.3725) * (1 / cs_amp_comp) /(pBQDev->dft_len_struct) * 2;
        }
    } else if (Readtype == FRMWRT_ALL_R) {
        for (j = 0; j < TOTALBOARDS; j++) {
            for (i = 0; i < ACTIVECHANNELS_C; i++) {
                pBQDev[j].CSeis_I[i * 3] = ReadBuf[j * (ACTIVECHANNELS_C * 3 + 6) + 4 + i * 3];
                pBQDev[j].CSeis_I[i * 3 + 1] = ReadBuf[j * (ACTIVECHANNELS_C * 3 + 6) + 5 + i * 3];
                pBQDev[j].CSeis_I[i * 3 + 2] = ReadBuf[j * (ACTIVECHANNELS_C * 3 + 6) + 6 + i * 3];
                pBQDev[j].debug[i] = 
                (((pBQDev[j].CSeis_I[i * 3] & (1 << 7)) == 0x80)? 0xFF000000:0x00000000) | 
                (uint32_t)pBQDev[j].CSeis_I[i * 3] << 16 | 
                (uint32_t)pBQDev[j].CSeis_I[i * 3 + 1] << 8 | 
                (uint32_t)pBQDev[j].CSeis_I[i * 3 + 2];
                
                pBQDev[j].CSeis_I_Decode[i] =(float)pBQDev[j].debug[i] * cs_direction * 
                 5120.0 / (8388608.0) * (1 / 0.3725) * (1 / cs_amp_comp) /(pBQDev->dft_len_struct) * 2;
            }
        }
    }
    rtn = ReadReg(bID_temp, BQ7982X_SMART_FREEZE_STAT1_OFFSET, ReadBuf, 3, 0, Readtype);
    return rtn;
}

/**
 * @brief EIS 阻抗计算函数 (EIS Impedance Calculation)
 * 
 * 根据测量的电压和电流的实部与虚部，计算阻抗的实部 (Zreal)、虚部 (Zimag)、
 * 幅值 (Zmag) 和相位 (Zpha)。
 * 
 * 计算公式 (基于复数除法 Z = V / I):
 * Zreal = (V_real * I_real + V_imag * I_imag) / (I_real^2 + I_imag^2)
 * Zimag = (V_imag * I_real - V_real * I_imag) / (I_real^2 + I_imag^2)
 * Zmag  = sqrt(Zreal^2 + Zimag^2)
 * Zpha  = atan2(Zimag, Zreal) * 180 / pi
 * 
 * @param pBQDev BQ 设备结构体数组，包含解码后的电压 (VCeis) 和电流 (CSeis) 数据
 * @param out_P 输出相位数组指针 (Output Phase)
 * @param out_M 输出幅值数组指针 (Output Magnitude)
 */
void EIS_Z_Cal(bq7982x_dev_t *pBQDev, float* out_P, float* out_M)
{
    uint8_t i,j,j_cs;
    float pi = 3.1415926;
    for (j = 0; j < TOTALBOARDS; j++) {
        for (i = 0; i < ACTIVECHANNELS; i++) {
            // 确定电流采样所在的板卡 (通常堆叠配置中，电流采样可能只在特定的板卡上)
            if (j == 0 || j == 1) j_cs = 0;
            else if (j == 2 || j == 3) j_cs =2;
            
            // Zreal (阻抗实部)
            pBQDev[j].Zeis_R_Decode[i] = (
            pBQDev[j].VCeis_R_Decode[i] * pBQDev[j_cs].CSeis_R_Decode[0] + 
            pBQDev[j].VCeis_I_Decode[i] * pBQDev[j_cs].CSeis_I_Decode[0]
            )/
            (
            pBQDev[j_cs].CSeis_R_Decode[0] * pBQDev[j_cs].CSeis_R_Decode[0] + 
            pBQDev[j_cs].CSeis_I_Decode[0] * pBQDev[j_cs].CSeis_I_Decode[0]
            );
            
            // Zimag (阻抗虚部)
            pBQDev[j].Zeis_I_Decode[i] = (
            pBQDev[j].VCeis_I_Decode[i] * pBQDev[j_cs].CSeis_R_Decode[0] - 
            pBQDev[j].VCeis_R_Decode[i] * pBQDev[j_cs].CSeis_I_Decode[0]
            )/
            (
            pBQDev[j_cs].CSeis_R_Decode[0] * pBQDev[j_cs].CSeis_R_Decode[0] + 
            pBQDev[j_cs].CSeis_I_Decode[0] * pBQDev[j_cs].CSeis_I_Decode[0]
            );
            
            // Zmag (阻抗幅值)
            pBQDev[j].Zeis_M_Decode[i] = (
            (float)(sqrt(pBQDev[j].Zeis_R_Decode[i] * pBQDev[j].Zeis_R_Decode[i] + pBQDev[j].Zeis_I_Decode[i] * pBQDev[j].Zeis_I_Decode[i]))               
            );
            
            // Zpha (阻抗相位，单位：度)
            pBQDev[j].Zeis_P_Decode[i] = (
            (float)(atan2(pBQDev[j].Zeis_I_Decode[i], pBQDev[j].Zeis_R_Decode[i]) * 180 / pi)              
            );    
            // 根据用户定义：result_decode_P 为阻抗 (Magnitude)，result_decode_M 为相位 (Phase)
            out_P[j * ACTIVECHANNELS + i] =  pBQDev[j].Zeis_P_Decode[i];
            out_M[j * ACTIVECHANNELS + i] =  pBQDev[j].Zeis_M_Decode[i];
            }
    }
}

/**
 * @brief 检查 EIS 测量是否完成 (Check EIS Completion)
 * 
 * 轮询 EIS 状态寄存器 (EIS_STAT)，检查 DFE (数字前端) 和 DFT (离散傅里叶变换) 
 * 是否仍在运行，以及 DFT 数据是否准备就绪。
 * 
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (单播/广播/堆栈)
 * @return int8_t 
 *      0: 未完成 (DFE/DFT 运行中 或 数据未就绪)
 *     -1: 错误 (DFE/DFT 仍在运行，理论上此时应已停止)
 *    rtn: 读取函数的返回值 (通常是 0 表示成功)
 */

int8_t EISCompleteCheck(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn = 0;

    if(Readtype == FRMWRT_SGL_R) {
        bID_temp = BQID;
    }
    
    ReadReg(bID_temp, BQ7982X_EIS_STAT_OFFSET, ReadBuf, 1, 0, Readtype);
    pBQDev->EisStat.reg = ReadBuf[4];
    
    // 检查状态位：
    // eis_dfe_run: 1 = DFE 正在运行
    // eis_dft_run: 1 = DFT 正在计算
    // eis_dft_rdy: 0 = DFT 数据未就绪


    if ((pBQDev->EisStat.fs.eis_dfe_run == 1) || 
        (pBQDev->EisStat.fs.eis_dft_run == 1) ||
        (pBQDev->EisStat.fs.eis_dft_rdy == 0))
    {
        return 0;
    }
    return 1;
}

/**
 * @brief EIS 配置函数 (PWM, DFE, DFT)
 * 
 * 配置 EIS 相关的寄存器，包括：
 * 1. 重启 DFT 和 ADC 状态。
 * 2. 配置 PWM 生成器 (EIS_PWM_CTRLx)：幅度、相位、DC 偏移、分频器。
 * 3. 配置 DFE (数字前端) 增益和滤波器 (EIS_DFE_CTRLx)：电压/电流通道增益、DCC (直流消除) 设置。
 * 4. 配置 DFT (离散傅里叶变换) 参数 (EIS_DFT_CTRLx, EIS_COM_CTRLx)：模式、长度、相位偏移。
 * 
 * @param BQID BQ 设备 ID
 * @param pBQDev BQ 设备结构体
 * @param Writetype 写入类型 (单播/广播)
 * @return int8_t 0 (成功)
 */
int8_t EIS_Config(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;
    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }
    
    // 1. 重启 DFT 和 ADC，清除 DRDY(数据就绪) 标志位，为新的测量做准备
    pBQDev->EisDftCtrl4.fs.eis_dft_go = 1;// Restart DFT so that the DFT_DRDY bit is cleared
    WriteReg(bID_temp, BQ7982X_EIS_DFT_CTRL4_OFFSET, pBQDev->EisDftCtrl4.reg, 1, Writetype);
    pBQDev->AdcCtrl3.fs.adc_go = 1;//Restart ADC so that the ADC_DRDY bit is cleared
    WriteReg(bID_temp, BQ7982X_ADC_CTRL3_OFFSET, pBQDev->AdcCtrl3.reg, 1, Writetype);
    
    // 2. 配置硬件 PWM 生成器参数 (用于生成正弦波激励信号)
    // pBQDev->EisPwmCtrl1.fs.amp1 = 0b01100011;//(1 / 256) X AMP1(99) X 100%
    // 设置正弦波 PWM 幅度 (决定激励电流大小)
    pBQDev->EisPwmCtrl1.fs.amp1 = 0x4C; 

    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL1_OFFSET, pBQDev->EisPwmCtrl1.reg, 1, Writetype);
    // 设置 PWM 相位，通常设为 0。(2pi / 256) X PHASE1(0)
    pBQDev->EisPwmCtrl6.fs.phase1 = 0;
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL6_OFFSET, pBQDev->EisPwmCtrl6.reg, 1, Writetype);
    
    // 设置 PWM 的直流(DC)偏置，控制正弦波的中心电压。(1 / 4096) X {[DC_SHIFTH, DC_SHIFTL]}
    pBQDev->EisPwmCtrl11.fs.dc_shifth = 0b1000;
    pBQDev->EisPwmCtrl12.fs.dc_shiftl = 0;
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL11_OFFSET, (pBQDev->EisPwmCtrl11.reg << 8) + pBQDev->EisPwmCtrl12.reg, 2, Writetype);
    
    // BQ79826 PWM 载波 = 32 MHz / (PWM_DIVISOR + 128)。
    // PWM_DIVISOR = 0x0380，因此载波为 32 MHz / 1024 = 31.25 kHz。
    pBQDev->EisPwmCtrl13.fs.pwm_divisorh = 0x03;
    pBQDev->EisPwmCtrl14.fs.pwm_divisorl = 0x80;
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL13_OFFSET, (pBQDev->EisPwmCtrl13.reg << 8) + pBQDev->EisPwmCtrl14.reg, 2, Writetype);    
    
    // 设置 PWM 工作模式：0b01 表示单音(Single Tone)模式，生成单一频率正弦波
    pBQDev->EisPwmCtrl15.fs.eis_pwm_mode = 0b01; 
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL15_OFFSET, pBQDev->EisPwmCtrl15.reg, 1, Writetype);    
    
    // 3. 配置 DFE (Digital Front End - 数字前端)
    // 配置电压通道(VC)前端放大器增益：设置为 5V/V (放大微弱的电压响应信号)
    pBQDev->EisDfeCtrl1.fs.vc_amph = 0b10100000;
    pBQDev->EisDfeCtrl2.fs.vc_ampl = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL1_OFFSET, (pBQDev->EisDfeCtrl1.reg << 8) + pBQDev->EisDfeCtrl2.reg, 2, Writetype);    
    
    // 配置电流通道(CS)前端放大器增益：设置为 5V/V (放大微弱的电流响应信号)
    pBQDev->EisDfeCtrl3.fs.cs_amph = 0b10100000;
    pBQDev->EisDfeCtrl4.fs.cs_ampl = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL3_OFFSET, (pBQDev->EisDfeCtrl3.reg << 8) + pBQDev->EisDfeCtrl4.reg, 2, Writetype);   
    
    // 将之前在 EIS_Para_Calculation 中计算好的高通滤波器(HPF)系数写入硬件寄存器
    // pBQDev->EisDfeCtrl5.fs.hpf_coefh = 0b1111;//cal
    // pBQDev->EisDfeCtrl6.fs.hpf_coefm = 0b11011111;
    // pBQDev->EisDfeCtrl7.fs.hpf_coefl = 0b00001110;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL5_OFFSET, ((uint32_t)pBQDev->EisDfeCtrl5.reg << 16) + (pBQDev->EisDfeCtrl6.reg << 8) + pBQDev->EisDfeCtrl7.reg, 3, Writetype);   
    
    // 配置 DCC (DC Cancellation - 直流消除) 模块，用于去除信号中的电池直流基准电压
    // 电压通道 DCC 缩放因子和滤波器配置（此处设为 0，可能在别处或默认不开启）
    pBQDev->EisDfeCtrl8.fs.vc_dcc_scaleh = 0;
    pBQDev->EisDfeCtrl9.fs.vc_dcc_scalem = 0;
    pBQDev->EisDfeCtrl10.fs.vc_dcc_scalel = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL8_OFFSET, ((uint32_t)pBQDev->EisDfeCtrl8.reg << 16) + (pBQDev->EisDfeCtrl9.reg << 8) + pBQDev->EisDfeCtrl10.reg, 3, Writetype);   
    pBQDev->EisDfeCtrl11.fs.vc_dcc_lpfh = 0;
    pBQDev->EisDfeCtrl12.fs.vc_dcc_lpfm = 0;
    pBQDev->EisDfeCtrl13.fs.vc_dcc_lpfl = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL11_OFFSET, ((uint32_t)pBQDev->EisDfeCtrl11.reg << 16) + (pBQDev->EisDfeCtrl12.reg << 8) + pBQDev->EisDfeCtrl13.reg, 3, Writetype);   
    pBQDev->EisDfeCtrl14.fs.vc_dcc_dch = 0;
    pBQDev->EisDfeCtrl15.fs.vc_dcc_dcm = 0;
    pBQDev->EisDfeCtrl16.fs.vc_dcc_dcl = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL14_OFFSET, ((uint32_t)pBQDev->EisDfeCtrl14.reg << 16) + (pBQDev->EisDfeCtrl15.reg << 8) + pBQDev->EisDfeCtrl16.reg, 3, Writetype);   
    
    // 电流通道 DCC 缩放因子和滤波器配置
    pBQDev->EisDfeCtrl17.fs.cs_dcc_scaleh = 0;
    pBQDev->EisDfeCtrl18.fs.cs_dcc_scalem = 0;
    pBQDev->EisDfeCtrl19.fs.cs_dcc_scalel = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL17_OFFSET, ((uint32_t)pBQDev->EisDfeCtrl17.reg << 16) + (pBQDev->EisDfeCtrl18.reg << 8) + pBQDev->EisDfeCtrl19.reg, 3, Writetype);   
    pBQDev->EisDfeCtrl20.fs.cs_dcc_lpfh = 0;
    pBQDev->EisDfeCtrl21.fs.cs_dcc_lpfm = 0;
    pBQDev->EisDfeCtrl22.fs.cs_dcc_lpfl = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL20_OFFSET, ((uint32_t)pBQDev->EisDfeCtrl20.reg << 16) + (pBQDev->EisDfeCtrl21.reg << 8) + pBQDev->EisDfeCtrl22.reg, 3, Writetype);   
    pBQDev->EisDfeCtrl23.fs.cs_dcc_dch = 0;
    pBQDev->EisDfeCtrl24.fs.cs_dcc_dcm = 0;
    pBQDev->EisDfeCtrl25.fs.cs_dcc_dcl = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL23_OFFSET, ((uint32_t)pBQDev->EisDfeCtrl23.reg << 16) + (pBQDev->EisDfeCtrl24.reg << 8) + pBQDev->EisDfeCtrl25.reg, 3, Writetype);   
    
    // 设置 DFE 模式为 0b01 (可能代表启用某些滤波器特性)
    // 多次写入可能是为了满足芯片手册要求的特定时序或配置安全机制
    //DFE mode 3 times?
    pBQDev->EisDfeCtrl26.fs.eis_dfe_mode = 0b01;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL26_OFFSET, pBQDev->EisDfeCtrl26.reg, 1, Writetype);   
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL26_OFFSET, pBQDev->EisDfeCtrl26.reg, 1, Writetype);   
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL26_OFFSET, pBQDev->EisDfeCtrl26.reg, 1, Writetype);   
    
    // 4. 配置 DFT (Discrete Fourier Transform - 离散傅里叶变换) 引擎
    // 设置 DFT 模式，多次写入以确保生效
    //DFT mode 2 times?
    pBQDev->EisDftCtrl4.fs.eis_dft_mode = 0b10;
    pBQDev->EisDftCtrl4.fs.eis_dft_go = 0b0; // 先不启动 DFT
    WriteReg(bID_temp, BQ7982X_EIS_DFT_CTRL4_OFFSET, pBQDev->EisDftCtrl4.reg, 1, Writetype);   
    WriteReg(bID_temp, BQ7982X_EIS_DFT_CTRL4_OFFSET, pBQDev->EisDftCtrl4.reg, 1, Writetype);   
    
    // 写入在 EIS_Para_Calculation 中计算好的 DFT 长度
    // pBQDev->EisComCtrl2.fs.dft_lenh = 0; //cal
    // pBQDev->EisComCtrl3.fs.dft_lenm = 0b11110001;
    // pBQDev->EisComCtrl4.fs.dft_lenl = 0b00011000;
    WriteReg(bID_temp, BQ7982X_EIS_COM_CTRL2_OFFSET, ((uint32_t)pBQDev->EisComCtrl2.reg << 16) + (pBQDev->EisComCtrl3.reg << 8) + pBQDev->EisComCtrl4.reg, 3, Writetype);   
    
    // 再次确认 DFT 模式设置
    pBQDev->EisDftCtrl4.fs.eis_dft_mode = 0b10;
    WriteReg(bID_temp, BQ7982X_EIS_DFT_CTRL4_OFFSET, pBQDev->EisDftCtrl4.reg, 1, Writetype);       
    
    // 配置 EIS 公共控制寄存器
    ////Com ctrl 2 times?
    pBQDev->EisComCtrl1.fs.cs_mode = 0;//0 = EIS processing is enabled. (启用 EIS 处理)
    pBQDev->EisComCtrl1.fs.num_tones = 0;//0b000 = 1 tone. (单频模式)
    WriteReg(bID_temp, BQ7982X_EIS_COM_CTRL1_OFFSET, pBQDev->EisComCtrl1.reg, 1, Writetype);       
    WriteReg(bID_temp, BQ7982X_EIS_COM_CTRL1_OFFSET, pBQDev->EisComCtrl1.reg, 1, Writetype);   
    
    // 配置 DFT 相位偏移 (默认为 0)
    pBQDev->EisDftCtrl1.fs.phaseh = 0;
    pBQDev->EisDftCtrl2.fs.phasem = 0;
    pBQDev->EisDftCtrl3.fs.phasel = 0;
    WriteReg(bID_temp, BQ7982X_EIS_DFT_CTRL1_OFFSET, ((uint32_t)pBQDev->EisDftCtrl1.reg << 16) + (pBQDev->EisDftCtrl2.reg << 8) + pBQDev->EisDftCtrl3.reg, 3, Writetype);   
    
    // 写入在 EIS_Para_Calculation 中计算好的目标频率索引
    // pBQDev->EisComCtrl5.fs.freq_idx1h = 0;//cal
    // pBQDev->EisComCtrl6.fs.freq_idx1m = 0b01000001;
    // pBQDev->EisComCtrl7.fs.freq_idx1l = 0b00111010;
    WriteReg(bID_temp, BQ7982X_EIS_COM_CTRL5_OFFSET, ((uint32_t)pBQDev->EisComCtrl5.reg << 16) + (pBQDev->EisComCtrl6.reg << 8) + pBQDev->EisComCtrl7.reg, 3, Writetype);   
// End of DFE| DFT| and PWM configuration
    return rtn;
}

// Start Start PWM| ADC| and DFE
/**
 * @brief 启动 EIS PWM 输出、ADC 和 DFE
 * 
 * 配置并启动 EIS 测量所需的各个模块：
 * 1. PWM 模块 (EIS_PWM_CTRL15): 设置模式并启动。
 * 2. ADC 模块 (ADC_CTRL3/4): 设置 ADC 模式 (CSADC) 并启动。
 * 3. DFE 模块 (EIS_DFE_CTRL26): 启动数字前端处理。
 * 
 * @param BQID BQ 设备 ID
 * @param pBQDev BQ 设备结构体
 * @param Writetype 写入类型
 * @return int8_t 0
 */
int8_t EIS_PWM(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;

    // 1. 确定写入的设备ID (如果是单播则指定ID，如果是广播则ID为0)
    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }

    // 2. 配置并启动 PWM
    // eis_pwm_mode = 0b10: 配置 PWM 的输出模式，0b10 可能是内部正弦波/方波生成模式
    pBQDev->EisPwmCtrl15.fs.eis_pwm_mode = 0b10;//0b01
    // eis_pwm_go = 1: 触发 PWM 开始输出激励信号
    pBQDev->EisPwmCtrl15.fs.eis_pwm_go = 0b1;
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL15_OFFSET, pBQDev->EisPwmCtrl15.reg, 1, FRMWRT_SGL_W);   

    // 3. 配置 ADC 通道
    // csadc_mode = 1: 启用电流采样 (CS) ADC 模式，使其开始采样反馈的交流电流信号
    pBQDev->AdcCtrl4.fs.csadc_mode = 0b1;
    WriteReg(bID_temp, BQ7982X_ADC_CTRL4_OFFSET, pBQDev->AdcCtrl4.reg, 1, Writetype);   
    
    // adc_mode = 0b10: 配置电压采样 (VC) ADC 为特定的连续采样或 EIS 模式
    pBQDev->AdcCtrl3.fs.adc_mode = 0b10;
    // adc_go = 1: 启动 ADC 采样过程
    pBQDev->AdcCtrl3.fs.adc_go = 0b1;    
    WriteReg(bID_temp, BQ7982X_ADC_CTRL3_OFFSET, pBQDev->AdcCtrl3.reg, 1, Writetype);   

    // 4. 配置并启动 DFE (数字前端滤波器)
    // eis_dfe_go = 1: 准备启动 DFE
    pBQDev->EisDfeCtrl26.fs.eis_dfe_go = 0b1;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL26_OFFSET, pBQDev->EisDfeCtrl26.reg, 1, Writetype); 
    
    // eis_dfe_mode = 0b01: 设置 DFE 运行模式 (通常包括高通滤波、降采样等信号预处理)
    pBQDev->EisDfeCtrl26.fs.eis_dfe_mode = 0b01;
    // 再次确认启动 DFE (将模式与启动命令一起下发)
    pBQDev->EisDfeCtrl26.fs.eis_dfe_go = 0b1;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL26_OFFSET, pBQDev->EisDfeCtrl26.reg, 1, Writetype); 
    
    return rtn;
}

/**
 * @brief 停止 EIS PWM 激励、DFE 和 ADC
 *
 * GO 位是动作位：必须在 mode=0 后写 GO=1，BQ 才会采样停止配置。
 */
int8_t EIS_Stop(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }

    pBQDev->EisDfeCtrl26.fs.eis_dfe_mode = 0b00;
    pBQDev->EisDfeCtrl26.fs.eis_dfe_go = 0b1;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL26_OFFSET,
             pBQDev->EisDfeCtrl26.reg, 1, Writetype);

    pBQDev->AdcCtrl4.fs.csadc_mode = 0b0;
    WriteReg(bID_temp, BQ7982X_ADC_CTRL4_OFFSET,
             pBQDev->AdcCtrl4.reg, 1, Writetype);

    pBQDev->AdcCtrl3.fs.adc_mode = 0b00;
    pBQDev->AdcCtrl3.fs.adc_go = 0b1;
    WriteReg(bID_temp, BQ7982X_ADC_CTRL3_OFFSET,
             pBQDev->AdcCtrl3.reg, 1, Writetype);

    pBQDev->EisPwmCtrl15.fs.eis_pwm_mode = 0b00;
    pBQDev->EisPwmCtrl15.fs.eis_pwm_go = 0b1;
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL15_OFFSET,
             pBQDev->EisPwmCtrl15.reg, 1, Writetype);

    return 0;
}

// Start of Smart Freeze/DFT. Ensure there is enough delay between DFE and Smart Freeze (5/(Frequncy))
/**
 * @brief EIS 智能冻结 (Smart Freeze) 与 DFT 触发
 * 
 * "智能冻结" 机制用于在特定时刻触发 DFT，以确保多个设备之间的同步或与 PWM 相位的对齐。
 * 1. 读取 Smart Freeze 状态 (SMART_FREEZE_STAT1)，获取当前的 Slot 计数。
 * 2. 根据当前计数设置触发 Slot (SMART_FREEZE_CTRL1)。
 * 3. 启动 Smart Freeze (SMART_FREEZE_CTRL2)，这将自动触发 DFT。
 * 
 * @param BQID BQ 设备 ID
 * @param pBQDev BQ 设备结构体
 * @param ReadBuf 读取缓冲区
 * @param Readtype 读取类型
 * @return int8_t 0
 */
int8_t EIS_SMART_FREEZE(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)
{
    
    uint8_t bID_temp  = 0;
    uint8_t rtn      = 0;
    uint8_t Writetype = 0;
    if (Readtype == FRMWRT_SGL_R) {
        bID_temp  = BQID;
        Writetype = FRMWRT_SGL_W;
    } else if (Readtype == FRMWRT_STK_R) {
        Writetype = FRMWRT_STK_W;
    } else if (Readtype == FRMWRT_ALL_R) {
        Writetype = FRMWRT_ALL_W;
    } else {
        return -1;
    }
    rtn = ReadReg(bID_temp, BQ7982X_SMART_FREEZE_STAT1_OFFSET, ReadBuf, 3, 0, Readtype);
    // Get Smart Freeze Status and adjust the Smart freeze Counter trigger accordingly
    pBQDev->SmartFreezeStat3.fs.slot_count = ReadBuf[6];
    pBQDev->SmartFreezeCtrl1.fs.slot_sel = (pBQDev->SmartFreezeStat3.fs.slot_count) - 1;
    // pBQDev->SmartFreezeCtrl1.fs.slot_sel = 0b01011011;//yan
    WriteReg(bID_temp, BQ7982X_SMART_FREEZE_CTRL1_OFFSET, pBQDev->SmartFreezeCtrl1.reg, 1, Writetype);   
    pBQDev->SmartFreezeCtrl2.fs.sf_mode = 0b00;   
    pBQDev->SmartFreezeCtrl2.fs.sf_go = 0b1;
    WriteReg(bID_temp, BQ7982X_SMART_FREEZE_CTRL2_OFFSET, pBQDev->SmartFreezeCtrl2.reg, 1, Writetype);   
    pBQDev->SmartFreezeCtrl2.fs.sf_go = 0b1;
    pBQDev->SmartFreezeCtrl2.fs.sf_mode = 0b10;    
    WriteReg(bID_temp, BQ7982X_SMART_FREEZE_CTRL2_OFFSET, pBQDev->SmartFreezeCtrl2.reg, 1, Writetype);   
    // pBQDev->EisDftCtrl4.fs.eis_dft_go = 0b1;// if smart freeze sf_mode has been 01 then no need eft go
    // WriteReg(bID_temp, BQ7982X_EIS_DFT_CTRL4_OFFSET, pBQDev->EisDftCtrl4.reg, 1, Writetype);  
       
    return rtn;
}
// PLL Synchronization - Set transmitter and reciever modes accordingly
/**
 * @brief PLL (锁相环) 同步
 * 
 * 同步所有堆叠设备的 PLL，以确保时钟一致性。
 * 配置主设备为发射器，从设备为接收器。
 * 
 * @param BQID BQ 设备 ID
 * @param pBQDev BQ 设备结构体
 * @param Writetype 写入类型
 * @return int8_t 0
 */
int8_t PLL_Sync(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    // uint8_t bID_temp = 0;
    uint8_t rtn      = 0;

    // if (Writetype == FRMWRT_SGL_W) {
    //     bID_temp = BQID;
    // }
    pBQDev->PllSyncCtrl1.fs.pll_sync_dir = 0b1;
    pBQDev->PllSyncCtrl1.fs.pll_dev_mode = 0b001;
    WriteReg(0, BQ7982X_PLL_SYNC_CTRL1_OFFSET, pBQDev->PllSyncCtrl1.reg, 1, FRMWRT_ALL_W);
    pBQDev->PllSyncCtrl1.fs.pll_sync_dir = 0b0;
    pBQDev->PllSyncCtrl1.fs.pll_dev_mode = 0b010;
    WriteReg(0, BQ7982X_PLL_SYNC_CTRL1_OFFSET, pBQDev->PllSyncCtrl1.reg, 1, FRMWRT_SGL_W);      
    pBQDev->PllSyncCtrl2.fs.pll_sync_go = 0b1;
    WriteReg(0, BQ7982X_PLL_SYNC_CTRL2_OFFSET, pBQDev->PllSyncCtrl2.reg, 1, FRMWRT_ALL_W);    
    DEVICE_DELAY_US(3000);
    return rtn;
}
// Start of Starting Digital Synchronization Counter
/**
 * @brief 数字同步计数器启动
 * 
 * 启动数字同步计数器，用于精确的时间对齐。
 * 
 * @param BQID BQ 设备 ID
 * @param pBQDev BQ 设备结构体
 * @param Writetype 写入类型
 * @return int8_t 0
 */
int8_t Digital_Sync_counter(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t Writetype)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;

    if (Writetype == FRMWRT_SGL_W) {
        bID_temp = BQID;
    }
    // WriteReg(bID_temp, 0x101a, ？, 1, FRMWRT_ALL_W);
    pBQDev->DigSyncCtrl6.fs.dig_sync_go = 0b1;
    pBQDev->DigSyncCtrl6.fs.dig_sync_mode = 0b10;
    pBQDev->DigSyncCtrl6.fs.dig_sync_wait = 0b1;
    pBQDev->DigSyncCtrl6.fs.dig_sync_start = 0b1;
    pBQDev->DigSyncCtrl6.fs.sync_adc_reset = 0b1;
    WriteReg(bID_temp, 0x101A, 0x0F, 1, Writetype);      
    WriteReg(bID_temp, BQ7982X_DIG_SYNC_CTRL6_OFFSET, pBQDev->DigSyncCtrl6.reg, 1, Writetype);      
    return rtn;
    // End of Digital Synchronization Counter
}
// Start of Manual Synchronization - Synchronization is done every 10ms - look over pseudocode for HFO_FREQ_CTRL value adjustment
uint8_t sync_delta_count = 0;
int16_t delta_raw[] ={-16069,	-19,	-22,	-71,	15694,	15691,	15582,	14707,	12760,	10689,	8612,	6535,	4459,	2387,	312,	-1302,	-2442,	-3101,	-3277,	-2972,	-2178,	-899,	256,	941,	1139,	855,	329,	-149,	-408,	-431,	-287,	-96,	52,	119,	104,	43,	-23,	-66,	-81,	-70,	-48,	-33,	-19,	-5,	-4,	-9,	-17,	-30,	-41,	-44,	-40,	-39,	-34,	-30,	-28,	-32,	-36,	-37,	-38,	-36,	-32,	-33,	-33,	-38,	-39,	-32,	-32,	-31,	-29,	-31,	-32,	-36,	-33,	-31,	-28,	-29,	-28,	-35,	-34,	-34,	-35,	-37,	-36,	-35,	-34,	-32,	-29,	-30,	-33,	-33,	-34,	-36,	-37,	-40,	-39,	-37,	-37,	-33,	-30,	-32,	-33,	-34,	-35,	-34,	-35,	-37,	-37,	-36,	-36,	-34,	-32,	-30,	-30,	-32,	-33,	-35,	-40,	-39,	-38,	-38,	-35,	-31,	-34,	-35,	-35,	-39,	-39,	-32,	-30,	-29,	-33,	-38,	-39,	-37,	-37,	-34,	-35,	-33,	-28,	-29,	-32,	-31,	-29,	-33,	-36,	-34,	-37,	-35,	-31,	-30,	-30,	-34,	-37,	-35,	-30,	-31,	-31,	-32,	-33,	-31,	-31,	-34,	-33,	-30,	-35,	-36,	-36,	-36,	-38,	-34,	-33,	-30,	-30,	-32,	-35,	-40,	-41,	-39,	-33,	-33,	-33,	-30,	-33,	-37,	-37,	-37,	-38,	-31,	-32,	-32,	-33,	-33,	-34,	-33,	-32,	-29,	-32,	-36,	-37,	-38,	-34,	-29,	-28,	-28,	-33,	-36,	-35,	-37,	-35,	-33,	-32,	-31,	-31,	-31,	-26,	-27,	-34,	-35,	-38,	-33,	-34,	-35,	-36,	-39,	-40,	-35,	-28,	-27,	-31,	-35,	-36,	-36,	-34,	-32,	-29,	-34,	-31,	-31,	-36,	-37,	-35,	-37,	-34,	-29,	-28,	-32,	-37,	-37,	-33,	-33,	-31,	-29,	-32,	-35,	-40,	-40,	-34,	-33,	-32,	-31,	-31,	-30,	-30,	-27,	-30,	-35,	-33,	-32,	-32,	-32,	-33,	-33,	-30,	-35,	-38,	-35,	-33,	-29,	-29,	-25,	-28,	-30,	-34,	-37,	-37,	-37,	-35,	-35,	-33,	-32,	-29,	-30,	-34,	-39,	-39,	-34,	-26,	-25,	-29,	-31,	-32,	-29,	-35,	-38,	-37,	-37,	-35,	-32,	-30,	-30,	-32,	-34,	-39,	-39,	-33,	-34,	-32,	-31,	-29,	-32,	-33,	-36,	-35,	-31,	-32,	-32,	-33,	-39,	-35,	-34,	-31,	-30,	-30,	-30,	-30,	-27,	-31,	-37,	-35,	-37,	-35,	-32,	-28,	-28,	-32,	-36,	-38,	-33,	-33,	-35,	-35,	-36,	-40,	-38,	-37,	-37,	-36,	-36,	-35,	-31,	-30,	-33,	-33,	-35,	-34,	-33,	-35,	-35,	-37,	-33,	-29,	-31,	-30,	-30,	-32,	-30,	-34,	-39,	-39,	-38,	-38,	-38,	-37,	-38,	-34,	-32,	-26,	-22,	-23,	-30,	-36,	-37,	-37,	-37,	-35,	-36,	-38,	-36,	-33,	-31,	-29,	-28,	-32,	-39,	-39,	-37,	-34,	-31,	-30,	-30,	-31,	-31,	-30,	-28,	-30,	-35,	-37,	-35,	-32,	-28,	-27,	-30,	-32,	-36,	-38,	-34,	-31,	-32,	-33,	-32,	-33,	-36,	-32,	-31,	-29,	-34,	-33,	-35,	-36,	-39,	-39,	-36,	-30,	-28,	-27,	-31,	-35,	-37,	-34,	-30,	-31,	-32,	-32,	-35,	-36,	-37,	-37,	-37,	-37,	-34,	-33,	-33,	-35,	-35,	-36,	-35,	-35,	-32,	-32,	-28,	-33,	-37,	-37,	-37,	-38,	-35,	-32,	-28,	-27,	-30,	-32,	-37,	-36,	-34,	-35,	-37,	-31,	-28,	-31,	-33,	-36,	-34,	-33,	-31,	-31,	-31,	-28,	-30,	-33,	-35,	-34,	-36,	-36,	-39,	-39,	-33,	-30,	-29,	-36,	-40,	-39,	-39,	-36,	-33,	-27,	-24,	-27,	-32,	-34,	-43,	-40,	-34,	-32,	-34,	-36,	-38,	-36,	-32,	-32,	-31,	-31,	-28,	-28,	-35,	-40,	-41,	-37,	-33,	-27,	-24,	-28,	-32,	-35,	-42,	-36,	-29,	-24,	-27,	-27,	-33,	-36,	-37,	-37,	-37,	-36,	-38,	-35,	-31,	-32,	-33,	-36,	-36,	-33,	-30,	-32,	-34,	-34,	-37,	-34,	-31,	-32,	-34,	-35,	-36,	-39,	-37,	-32,	-33,	-33,	-33,	-34,	-35,	-34,	-37,	-33,	-30,	-32,	-34,	-33,	-32,	-31,	-33,	-36,	-34,	-33,	-32,	-29,	-32,	-34,	-32,	-30,	-33,	-36,	-34,	-33,	-33,	-32,	-30,	-33,	-38,	-36,	-33,	-32,	-31,	-30,	-30,	-30,	-28,	-30,	-34,	-38,	-38,	-38,	-35,	-37,	-36,	-32,	-31,	-30,	-33,	-36,	-34,	-31,	-29,	-35,	-40,	-34,	-34,	-34,	-36,	-36,	-38,	-34,	-29,	-28,	-33,	-38,	-39,	-33,	-35,	-37,	-37,	-37,	-39,	-32,	-31,	-30,	-29,	-35,	-34,	-34,	-31,	-31,	-32,	-37,	-33,	-31,	-30,	-28,	-28,	-30,	-34,	-39,	-39,	-39,	-34,	-29,	-28,	-30,	-35,	-32,	-32,	-27,	-30,	-32,	-35,	-38,	-37,	-39,	-37,	-32,	-29,	-32,	-34,	-37,	-35,	-33,	-31,	-28,	-31,	-34,	-38,	-35,	-34,	-32,	-27,	-29,	-29,	-31,	-33,	-33,	-32,	-33,	-34,	-33,	-37,	-34,	-35,	-33,	-30,	-32,	-33,	-32,
}; 
/**
 * @brief 周期性数字同步 (Digital Sync Every 10ms)
 *        
 * 读取数字同步状态寄存器 (DIG_SYNC_STAT1)，获取当前的计数值，
 * 并调用 BQ7982x_Manual_Sync_Proc 进行时钟频率调整。
 * 建议每 10ms 调用一次。
 * 
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @param ReadBuf 读取缓冲区 (Read Buffer)
 * @param Readtype 读取类型 (Read Type)
 * @return int8_t 读取结果 (Result)
 */
int8_t DigitalSyncEvery10ms(uint8_t BQID, bq7982x_dev_t *pBQDev, uint8_t *ReadBuf, uint8_t Readtype)//broadcast mode
{
    uint8_t bID_temp  = 0;
    uint8_t rtn      = 0;
    uint8_t j;
    if (Readtype == FRMWRT_SGL_R) {
        bID_temp  = BQID;
    } 
    rtn = ReadReg(bID_temp, BQ7982X_DIG_SYNC_STAT1_OFFSET, ReadBuf, 2, 0, Readtype);
    for (j = 0; j < TOTALBOARDS; j++) {
        pBQDev[j].sync_count = (ReadBuf[j * (2 + 6) + 4 ] << 8) | ReadBuf[j * (2 + 6) + 5 ];
    }
    // delta test
        // pBQDev[0].sync_count = 0;
        // pBQDev[1].sync_count =  (uint16_t)(delta_raw[sync_delta_count]);
        // sync_delta_count++;
    BQ7982x_Manual_Sync_Proc(bID_temp, pBQDev);
    rtn = ReadReg(0, BQ7982X_DEV_STAT2_OFFSET, ReadBuf, 1, 0, FRMWRT_SGL_R);
    return rtn;
    // ReadReg(0, BQ7982X_FAULT_SYS1_OFFSET, ReadBuf, 1, 0, FRMWRT_SGL_R);
}

// Comment - This is done every time DIG_SYNC_STAT is read. GET_DATA_PTR will get the data from reading DIG_SYNC_STAT register (SYNC_COUNTH + SYNC_COUNTL)
#define DIAG_STEP_STATE1
static uint16_t base_counter;
uint16_t data;
uint8_t freq_adj[TOTALBOARDS];

/**
 * @brief 手动同步处理 (Manual Synchronization Process)
 *        软件锁相环 (Software PLL) 实现。
 *        计算各从设备与主设备的计数器差值 (Delta)，使用 PID 算法计算
 *        频率调整值 (freq_adj)，并写入 HFO_FREQ_CTRL 寄存器以调整时钟。
 * 
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @return int8_t 频率调整值 (Frequency Adjustment Value)
 */
int8_t BQ7982x_Manual_Sync_Proc(uint8_t BQID, bq7982x_dev_t *pBQDev)
{   
    // uint8_t TIBMS_MAX_BMICS_IN_IFACE_0  = TOTALBOARDS;
    // uint8_t TIBMS_MAX_PMICS_IN_IFACE_0 = 0;

    static uint16_t stack_counter[TOTALBOARDS];

    static int current_delta_zero[TOTALBOARDS];
    static uint8_t init = 0;
    static int current_delta[TOTALBOARDS];
    static int prev_delta[TOTALBOARDS];
    int8_t uRet;
    // Sign//
    // static int freq_adj_sign_prev[TOTALBOARDS];
    // static int freq_adj_sign_next[TOTALBOARDS];
    // Change Bit//
    // static uint8_t freq_adj_bit[TOTALBOARDS];

    //////////////
    // PID//
    static int freq_adj_gain_p = 100;//->100
    static int freq_adj_gain_i = 0;   // 100
    static int freq_adj_gain_d = 100; // 400->100
    static int e_p[TOTALBOARDS];
    static int e_d[TOTALBOARDS];
    static int e_i[TOTALBOARDS];
    // static uint8_t cycle_per_device[TOTALBOARDS];
    static uint8_t sync_state = 1;
    static int dig_sync_counter = 0;//yan test 2
    uint8_t i,j;
    switch (sync_state)
    {
    case 1:
    {
        ////////////////////////////////////////Counter Delta//////////////////////////////////////////////
        // prev_prev_prev_delta = prev_prev_delta;
        // prev_prev_delta = prev_delta;
        data = pBQDev[0].sync_count;
        base_counter = data;
        for (i = 1; i <= (TOTALBOARDS-1); i++)
        {
            prev_delta[i] = current_delta[i];
            data = pBQDev[i].sync_count;
            stack_counter[i] = data;
            current_delta[i] = (int)(stack_counter[i] - base_counter);

            if ((current_delta[i]) >= (32768))
            {
                current_delta[i] = current_delta[i] - 65536;
            }
            else if (current_delta[i] <= (-32768))
            {
                current_delta[i] = current_delta[i] + 65536;
            }
            else
            {
                current_delta[i] = current_delta[i];
            }           
        }
        // second_order_diff = current_delta - 2*prev_delta + prev_prev_delta;
        // Initialzation of delta zero
        /////////////////////////////////////////////////////////////////////////////////////////////////////
        if ((dig_sync_counter + 1) < 0) {
            dig_sync_counter = 100;         
        }
        if (dig_sync_counter >= 2)
        {
            for (i = 1; i <= (TOTALBOARDS-1); i++)
            {
                if (init == 0)
                {
                    init++;
                    for (j = 1; j <= (TOTALBOARDS-1); j++)
                    {
                        current_delta_zero[j] = current_delta[j];
                    }
                    // second_order_diff_zero = second_order_diff;
                }
                if (current_delta[i] - current_delta_zero[i] != 0)
                {
                    e_p[i] = current_delta[i] - current_delta_zero[i];
                    e_d[i] = current_delta[i] - prev_delta[i];
                    e_i[i] = e_i[i] + current_delta[i];
                    if((~((int)round((freq_adj_gain_p * e_p[i] + freq_adj_gain_i * e_i[i] + freq_adj_gain_d * e_d[i]) / 1000))) > 127){
                        freq_adj[i] = 127;
                    } else if ((~((int)round((freq_adj_gain_p * e_p[i] + freq_adj_gain_i * e_i[i] + freq_adj_gain_d * e_d[i]) / 1000))) < -127){
                        freq_adj[i] = (uint8_t)(-127);
                    } else {
                        // freq_adj[i] = (uint8_t)(~((int)round((freq_adj_gain_p * e_p[i] + freq_adj_gain_i * e_i[i] + freq_adj_gain_d * e_d[i]) / 1000)));
                        freq_adj[i] = (uint8_t)(~((int)round((freq_adj_gain_p * e_p[i] + freq_adj_gain_i * e_i[i] + freq_adj_gain_d * e_d[i]) / 1000)));

                    }
                    // freq_adj[i] = (-1)*freq_adj[i];//yan
                    if(dig_sync_counter >=300){
                            if(((int8_t)freq_adj[i]) > 80 || ((int8_t)freq_adj[i]) < -80 ){
                           //reset
                           dig_sync_counter = 0;
                           init = 0;
                           memset(&e_i, 0, sizeof(TOTALBOARDS));
                            pBQDev->PllSyncCtrl2.fs.pll_sync_go = 0b1;
                            WriteReg(0, BQ7982X_PLL_SYNC_CTRL2_OFFSET, pBQDev->PllSyncCtrl2.reg, 1, FRMWRT_ALL_W);    
                            DEVICE_DELAY_US(3000);
				//Pseudocode restart pll
                        //    Bmi_PLLSYNCLOOP(0); no API now
                           break;
                        }
                    }
                    // freq_adj[i] = (-1)*freq_adj[i];
                    pBQDev[i].freq_adj = freq_adj[i];
                    //     uRet |= Comif_SingleWrite(pBmicMgr->pComifCtx, i,
                    //                           COMIF_PRIO_CELL(0x0226),
                    //                           &freq_adj[i], WRITE_1BYTE);

                    // freq_adj[i] = 0x01;
                    // uRet |= Comif_SingleWrite(pBmicMgr->pComifCtx, i,
                    //                           COMIF_PRIO_CELL(0x0227),
                    //                           &freq_adj[i], WRITE_1BYTE);
                    pBQDev[i].HfoFreqCtrl1.fs.freq_adj = pBQDev[i].freq_adj;
                    pBQDev[i].HfoFreqCtrl2.fs.freq_go = 0b1;
                    WriteReg(i, BQ7982X_HFO_FREQ_CTRL1_OFFSET, (pBQDev[i].HfoFreqCtrl1.reg << 8) + pBQDev[i].HfoFreqCtrl2.reg, 2, FRMWRT_SGL_W); 
                }
                else
                {
                    freq_adj[i] = 0;
                }
            }           
        }
        dig_sync_counter++;
        break;
    }
    default:
    {
        break;
    }
    }
    // pause = 0; //no API
    // Variable stop
    uRet = (int8_t)freq_adj[i];
    return uRet;
}

/**
 * @brief NVM 寄存器配置 (NVM Register Configuration)
 *        模拟 NVM 加载过程，批量写入配置寄存器。
 *        配置通信、GPIO、ADC、阈值、EIS 参数等。
 * 
 * @param BQID BQ 设备 ID (BQ Device ID)
 * @param pBQDev BQ 设备结构体 (BQ Device structure)
 * @return int8_t 0 (成功)
 */
int8_t NVM_Register_Configuration(uint8_t BQID, bq7982x_dev_t *pBQDev)
{
    uint8_t bID_temp = 0;
    uint8_t rtn      = 0;
    uint8_t j      = 0;
    // if (Writetype == FRMWRT_SGL_W) {
    //     bID_temp = BQID;
    // }
    WriteReg(bID_temp, BQ7982X_FAULT_RST1_OFFSET, 0x000000, 3, FRMWRT_ALL_W); 
    for (j = 0; j < TOTALBOARDS; j++) {
        bID_temp = j;
        WriteReg(bID_temp, BQ7982X_COMM_CONF2_OFFSET, 0x0000, 2, FRMWRT_SGL_W); 
    }

    for (j = 0; j < TOTALBOARDS; j++) {
        bID_temp = j;
        pBQDev[j].CommConf1.fs.group = 0b01;
        WriteReg(bID_temp, BQ7982X_COMM_CONF1_OFFSET, pBQDev[j].CommConf1.reg, 1, FRMWRT_SGL_W); 
    }
    for (j = 0; j < TOTALBOARDS; j++) {
        bID_temp = j;
        pBQDev[j].DevConf1.fs.nfault_en = 0b1;
        pBQDev[j].DevConf2.fs.num_cell = BQ7982X_NUM_CELL_CFG;
        pBQDev[j].DevConf3.reg = 0x00;
        if(j == 0)pBQDev[j].DevConf3.fs.crystal_en = 0b1;
        else pBQDev[j].DevConf3.fs.crystal_en = 0b0;
        WriteReg(bID_temp, BQ7982X_DEV_CONF1_OFFSET, ((uint32_t)pBQDev[j].DevConf1.reg << 16) + (pBQDev[j].DevConf2.reg << 8) + pBQDev[j].DevConf3.reg, 3, FRMWRT_SGL_W); 
    }
    for (j = 0; j < TOTALBOARDS; j++) {
        bID_temp = j;
        pBQDev[j].GpioConf1.reg = 0x00;
        pBQDev[j].GpioConf2.reg = 0x00;
        pBQDev[j].GpioConf3.reg = 0x00;
        pBQDev[j].GpioConf4.fs.eis_pwm_en = 0b1;
        // pBQDev[j].GpioConf5.fs.spare = 0b1;
        WriteReg(bID_temp, BQ7982X_GPIO_CONF1_OFFSET, ((uint64_t)pBQDev[j].GpioConf1.reg << 32) + ((uint64_t)pBQDev[j].GpioConf2.reg << 24) + ((uint64_t)pBQDev[j].GpioConf3.reg << 16)
                 + (uint64_t)(pBQDev[j].GpioConf4.reg << 8) + pBQDev[j].GpioConf5.reg, 5, FRMWRT_SGL_W); 
        pBQDev[j].GpioConf6.fs.gpio12 = 0b101;//0b101 = ADC input (absolute) and weak pull-up.
        pBQDev[j].GpioConf7.reg = 0x00;
        pBQDev[j].GpioConf8.reg = 0x00;
        pBQDev[j].GpioConf9.fs.gpio18 = 0b001;//0b001 = ADC and OTUT inputs (ratiometric).
        pBQDev[j].GpioConf10.reg = 0x00;
        WriteReg(bID_temp, BQ7982X_GPIO_CONF6_OFFSET, ((uint64_t)pBQDev[j].GpioConf6.reg << 32) + ((uint64_t)pBQDev[j].GpioConf7.reg << 24) + ((uint64_t)pBQDev[j].GpioConf8.reg << 16)
                 + ((uint64_t)pBQDev[j].GpioConf9.reg << 8) + pBQDev[j].GpioConf10.reg, 5, FRMWRT_SGL_W); 
    }
    pBQDev->SmartFreezeConf.fs.slot_len = 0b11;//256 ADC measurement slots
    pBQDev->SmartFreezeConf.fs.samp_len = 0b001;//128us
    WriteReg(bID_temp, BQ7982X_SMART_FREEZE_CONF_OFFSET, pBQDev->SmartFreezeConf.reg, 1, FRMWRT_ALL_W); 
    //881 write ADC_CTRL6
    pBQDev->AdcCtrl5.reg = 0x00;
    pBQDev->AdcCtrl4.fs.csadc_mode = 0b01;
    pBQDev->AdcCtrl3.fs.adc_mode = 0b10;
    pBQDev->AdcCtrl3.fs.adc_go = 0b1;
    pBQDev->AdcCtrl2.fs.diag1_ana_sel = 0b00001;
    pBQDev->AdcCtrl1.fs.diag_meas_go = 0b1;
    WriteReg(bID_temp, BQ7982X_ADC_CTRL5_OFFSET, ((uint64_t)pBQDev->AdcCtrl5.reg << 32) + ((uint64_t)pBQDev->AdcCtrl4.reg << 24) + ((uint64_t)pBQDev->AdcCtrl3.reg << 16)
                + ((uint64_t)pBQDev->AdcCtrl2.reg << 8) + pBQDev->AdcCtrl1.reg, 5, FRMWRT_ALL_W); 
    pBQDev->Control2.fs.tsref_en = 0b1;
    WriteReg(bID_temp, BQ7982X_CONTROL2_OFFSET, pBQDev->Control2.reg, 1, FRMWRT_ALL_W); 
    pBQDev->OvThresh1.fs.ov_thr = 0b00000000; //2700mV
    pBQDev->UvThresh1.fs.uv_thr = 0b000000; //1200mV
    pBQDev->OvThresh2.fs.ov_thr = 0b00000000; //2700mV
    pBQDev->UvThresh2.fs.uv_thr = 0b000000; //1200mV
    WriteReg(bID_temp, BQ7982X_OV_THRESH1_OFFSET, ((uint32_t)pBQDev->OvThresh1.reg << 24) + ((uint32_t)pBQDev->UvThresh1.reg << 16)
                 + ((uint32_t)pBQDev->OvThresh2.reg << 8) + pBQDev->UvThresh2.reg, 4, FRMWRT_ALL_W); 
    pBQDev->OtutThresh1.reg = 0x00;
    pBQDev->OtutThresh2.reg = 0x00;
    WriteReg(bID_temp, BQ7982X_OTUT_THRESH1_OFFSET, (pBQDev->OtutThresh1.reg << 8) + pBQDev->OtutThresh2.reg, 2, FRMWRT_ALL_W); 
    WriteReg(bID_temp, BQ7982X_EIS_DISABLE1_OFFSET, 0x00000000, 4, FRMWRT_ALL_W); //enable all channel EIS process
    pBQDev->EisComCtrl1.fs.cs_mode = 0b1;//disable CS EIS?
    pBQDev->EisComCtrl2.reg = 0x00;
    pBQDev->EisComCtrl3.reg = 0x00;
    pBQDev->EisComCtrl4.reg = 0x00;
    pBQDev->EisComCtrl5.reg = 0x00;
    pBQDev->EisComCtrl6.reg = 0x00;
    pBQDev->EisComCtrl7.reg = 0x00;
    // pBQDev->EisComCtrl8.reg = 0x00;
    WriteReg(bID_temp, BQ7982X_EIS_COM_CTRL1_OFFSET, 0x00000000000000 + ((uint64_t)pBQDev->EisComCtrl1.reg << 56), 8, FRMWRT_ALL_W); 
    // pBQDev->EisComCtrl9.reg = 0b00;
    // pBQDev->EisComCtrl10.reg = 0x00;
    // pBQDev->EisComCtrl11.reg = 0x00;
    // pBQDev->EisComCtrl12.reg = 0x00;
    // pBQDev->EisComCtrl13.reg = 0x00;
    // pBQDev->EisComCtrl14.reg = 0x00;
    // pBQDev->EisComCtrl15.reg = 0x00;
    // pBQDev->EisComCtrl16.reg = 0x00;
    // WriteReg(bID_temp, BQ7982X_EIS_COM_CTRL9_OFFSET, 0x0000000000000000, 8, FRMWRT_ALL_W); 
    // pBQDev->EisComCtrl17.reg = 0x00;
    // pBQDev->EisComCtrl18.reg = 0x00;
    // pBQDev->EisComCtrl19.reg = 0x00;
    // WriteReg(bID_temp, BQ7982X_EIS_COM_CTRL17_OFFSET, 0x000000, 3, FRMWRT_ALL_W); 
    pBQDev->EisDfeCtrl1.fs.vc_amph = 0b10100000;
    pBQDev->EisDfeCtrl3.fs.cs_amph = 0b10100000;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL1_OFFSET, ((uint64_t)pBQDev->EisDfeCtrl1.reg << 56) + ((uint64_t)pBQDev->EisDfeCtrl3.reg << 40) + 0x0000000000000000, 8, FRMWRT_ALL_W);    
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL9_OFFSET, 0x0000000000000000, 8, FRMWRT_ALL_W);    
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL17_OFFSET, 0x0000000000000000, 8, FRMWRT_ALL_W);    
    pBQDev->EisDfeCtrl25.fs.cs_dcc_dcl = 0;
    pBQDev->EisDfeCtrl26.fs.eis_dfe_mode = 0b01;
    WriteReg(bID_temp, BQ7982X_EIS_DFE_CTRL25_OFFSET, pBQDev->EisDfeCtrl26.reg + 0x0000, 2, FRMWRT_ALL_W);    
    pBQDev->EisDftCtrl1.fs.phaseh = 0;
    pBQDev->EisDftCtrl2.fs.phasem = 0;
    pBQDev->EisDftCtrl3.fs.phasel = 0;
    pBQDev->EisDftCtrl4.fs.eis_dft_mode = 0b10;
    WriteReg(bID_temp, BQ7982X_EIS_DFT_CTRL1_OFFSET, ((uint32_t)pBQDev->EisDftCtrl1.reg << 24) + ((uint32_t)pBQDev->EisDftCtrl2.reg << 16) + ((uint32_t)pBQDev->EisDftCtrl3.reg << 8) + pBQDev->EisDftCtrl4.reg, 4, FRMWRT_ALL_W);   
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL1_OFFSET, 0x0000000000000000, 8, FRMWRT_ALL_W);  
    pBQDev->EisPwmCtrl15.fs.eis_pwm_mode = 0b10;
    WriteReg(bID_temp, BQ7982X_EIS_PWM_CTRL9_OFFSET, 0x00000000000000 + pBQDev->EisPwmCtrl15.reg, 7, FRMWRT_ALL_W);    
    pBQDev->EisMiscCtrl.fs.eis_res_sel = 0;    //real portion
    pBQDev->EisMiscCtrl.fs.eis_res_tone = 0;    //tone1 result
    WriteReg(bID_temp, BQ7982X_EIS_MISC_CTRL_OFFSET, pBQDev->EisMiscCtrl.reg, 1, FRMWRT_ALL_W);
    pBQDev->SmonhThresh.fs.smonh_thr = 0b01110101;
    pBQDev->SmonlThresh.fs.smonl_thr = 0b00000001;
    WriteReg(bID_temp, BQ7982X_SMONH_THRESH_OFFSET, (pBQDev->SmonhThresh.reg << 8) + pBQDev->SmonlThresh.reg, 2, FRMWRT_ALL_W);
    pBQDev->MonCtrl.fs.smon_peak_mode = 0b1;
    pBQDev->MonCtrl.fs.otcb_mode = 0b1;
    pBQDev->MonCtrl.fs.vcbdone_mode = 0b1;
    pBQDev->MonCtrl.fs.smon_mode = 0b1;
    pBQDev->MonCtrl.fs.mon_go = 0b1;
    WriteReg(bID_temp, BQ7982X_MON_CTRL_OFFSET, pBQDev->MonCtrl.reg, 1, FRMWRT_ALL_W);
    pBQDev[0].PllSyncCtrl1.fs.pll_dev_mode = 0b010;
    WriteReg(0, BQ7982X_PLL_SYNC_CTRL1_OFFSET, pBQDev->PllSyncCtrl1.reg, 1, FRMWRT_SGL_W);      
    for (j = 1; j < TOTALBOARDS; j++) {
        bID_temp = j;
        pBQDev[j].PllSyncCtrl1.fs.pll_dev_mode = 0b001;
        pBQDev[j].PllSyncCtrl1.fs.pll_sync_dir = 0b1;
        WriteReg(bID_temp, BQ7982X_PLL_SYNC_CTRL1_OFFSET, pBQDev[j].PllSyncCtrl1.reg, 1, FRMWRT_SGL_W);      
    }
    pBQDev->DigSyncConf1.fs.addrh = 0b00000010;
    pBQDev->DigSyncConf2.fs.addrl = 0b00110001;
    WriteReg(bID_temp, BQ7982X_DIG_SYNC_CONF1_OFFSET, (pBQDev->DigSyncConf1.reg << 8) + pBQDev->DigSyncConf2.reg, 2, FRMWRT_ALL_W);   
    pBQDev->DigSyncCtrl3.fs.sync_dev_mode = 0b10;
    pBQDev->DigSyncCtrl3.fs.sync_dev_go = 0b1;
    WriteReg(0, BQ7982X_DIG_SYNC_CTRL3_OFFSET, ((uint32_t)pBQDev->DigSyncCtrl3.reg<<24) + 0x00000000, 4, FRMWRT_SGL_W);              
    for (j = 1; j < TOTALBOARDS; j++) {
        bID_temp = j;
        pBQDev[j].DigSyncCtrl3.fs.sync_dev_frame = 0b1;
        pBQDev[j].DigSyncCtrl3.fs.sync_dev_dir = 0b1;
        pBQDev[j].DigSyncCtrl3.fs.sync_dev_mode = 0b01;
        pBQDev[j].DigSyncCtrl3.fs.sync_dev_go = 0b1;
        WriteReg(bID_temp, BQ7982X_DIG_SYNC_CTRL3_OFFSET, ((uint32_t)pBQDev[j].DigSyncCtrl3.reg<<24) + 0x00000000, 4, FRMWRT_SGL_W);      
    }    
    pBQDev->SmartFreezeConf.fs.slot_len = 0b10;//128 ADC measurement slots
    pBQDev->SmartFreezeConf.fs.samp_len = 0b111;//8192 us
    WriteReg(bID_temp, BQ7982X_SMART_FREEZE_CONF_OFFSET, pBQDev->SmartFreezeConf.reg, 1, FRMWRT_ALL_W); 
    return rtn;
}

float eis_frequency_cal; 
uint32_t freq_indxn;
float bin_size;
/**
 * @brief EIS 参数计算与配置
 * 
 * 根据目标 EIS 频率计算并配置相关的寄存器参数，包括 DFT 长度、
 * 频率索引、HPF 系数等。
 * 
 * @param BQID BQ 设备 ID
 * @param pBQDev BQ 设备结构体
 * @param eis_frequency 目标 EIS 频率 (Hz)
 */
void EIS_Para_Calculation(uint8_t BQID, bq7982x_dev_t *pBQDev, float eis_frequency)
{
    float hpf_corner;                                  // 高通滤波器(HPF)截止频率
    float f_sample_max = 7.8125;//khz                  // ADC 最大采样率 7.8125 kHz
    float pi = 3.141592654;                            // 圆周率常数
    uint16_t dft_len_max = 32500;                      // 芯片支持的 DFT 最大点数
    uint16_t dft_len_min = 31250;                      // 芯片支持的 DFT 最小点数
    uint8_t bin_min = 5;                               // 目标频率在频谱上至少占据的 bin(格子)数量，保证精度
    // uint8_t dsr_start = 1;
    float hpf_coefficent_b = 0.0000009536743;          // HPF 系数寄存器的 LSB(最小分辨率) 1/(2^20)


    // 1. 设置高通滤波器的截止频率
    // 如果测试频率 > 10Hz，截止频率固定在 10Hz；如果 <= 10Hz，截止频率就等于测试频率
    if(eis_frequency > 10)
        hpf_corner =  10;
    else hpf_corner = eis_frequency; 
    
    // 2. 计算降采样率 (DSR: Down Sample Rate)
    // 根据目标频率计算出在最大采样率下，所需的理论最大采样点数
    float max_bin_size = f_sample_max * 1000/eis_frequency*bin_min;
    // 如果理论点数超过了 DFT 长度上限，就需要降采样
    uint8_t eis_dsr = ceilf(max_bin_size/dft_len_max);
    // 限制降采样率的最小值为 10
    eis_dsr = (eis_dsr < 10)? eis_dsr:10;
    // float f_sample = f_sample_max/eis_dsr;          // 实际采样率
    
    // 3. 计算数字高通滤波器 (HPF) 的系数
    // 公式: 1 - 2*pi * 截止频率 / 实际采样频率
    float hpf_coefficient = 1 -2 * pi * hpf_corner /(f_sample_max * 1000 / eis_dsr);
    
    // 4. 计算 DFT 的实际长度
    // 根据是否超出最大点数，选择降采样后的长度，或者不降采样时的标准长度
    uint32_t dft_len = (max_bin_size > dft_len_max)? 
        roundf((f_sample_max * 1000/ eis_dsr) / eis_frequency * bin_min)
        :roundf(ceilf(dft_len_min / (f_sample_max * 1000)) * f_sample_max * 1000);
        
    // 5. 计算频谱的频率分辨率 (Bin Size)
    // Bin Size = 实际采样率 / DFT长度
    bin_size = f_sample_max * 1000 / eis_dsr / dft_len;
    
    // 6. 计算滤波器和 DFT 的等待时间
    // 数字前端滤波器稳定时间：5 个时间常数，且最少 2 秒 (保持单位为秒)
    float dfe_wait_time = roundf(1 / hpf_corner * 5);
    dfe_wait_time = (dfe_wait_time > 2)? dfe_wait_time:2;
    
    // DFT 收集足够数据所需的时间 (保持单位为秒)
    float dft_wait_time = ceilf((1 / (f_sample_max * 1000)) * dft_len * eis_dsr);
    // roundf((f_sample * 1000/ eis_dsr) / eis_frequency * bin_min);
    // roundf(ceilf(dft_len_min / (f_sample * 1000)) * f_sample * 1000);
    
    // 7. 计算目标频率在频谱中的索引 (Frequency Index)
    // 告诉硬件正弦波生成器要生成的频率位置
    freq_indxn = roundf(eis_frequency / bin_size);
    // 反算实际生成的物理频率
    eis_frequency_cal = f_sample_max *1000 / eis_dsr / dft_len * freq_indxn; 
    
    // 8. 将计算结果保存到 BQ 结构体中
    pBQDev->freq_indxn = freq_indxn;
    pBQDev->dfe_wait_time = dfe_wait_time;
    pBQDev->dft_wait_time = dft_wait_time;
    pBQDev->dft_len_struct = dft_len;
    
    // 将浮点数 HPF 系数转换为写入寄存器的整数值
    uint32_t hpf_coefficent_reg = roundf(hpf_coefficient / hpf_coefficent_b);
    pBQDev->hpf_coefficient = hpf_coefficient;
    pBQDev->dsr = eis_dsr;
    pBQDev->hpf_coefficent_reg = hpf_coefficent_reg;
    
    // 9. 扣除硬件内部流水线的 780 个固定时钟延迟
    dft_len = dft_len - 780;
    
    // 10. 将计算好的参数填入 BQ 寄存器镜像结构体
    // 配置 DFT 长度 (分高、中、低 3 个字节写入)
    pBQDev->EisComCtrl2.fs.dft_lenh = (dft_len >> 16) & 0x0F;
    pBQDev->EisComCtrl3.fs.dft_lenm = (dft_len >> 8) & 0xFF;
    pBQDev->EisComCtrl4.fs.dft_lenl = (dft_len) & 0xFF;
    
    // 配置频率索引 (分高、中、低 3 个字节写入)
    pBQDev->EisComCtrl5.fs.freq_idx1h = (freq_indxn >> 16) & 0x07;
    pBQDev->EisComCtrl6.fs.freq_idx1m = (freq_indxn >> 8) & 0xFF;
    pBQDev->EisComCtrl7.fs.freq_idx1l = (freq_indxn) & 0xFF;
    
    // 配置降采样率 (写入值需要减 1)
    pBQDev->EisDfeCtrl26.fs.eis_dsr = eis_dsr-1;
    
    // 配置 HPF 系数 (分高、中、低 3 个字节写入)
    pBQDev->EisDfeCtrl5.fs.hpf_coefh = (hpf_coefficent_reg >> 16) & 0x0F;
    pBQDev->EisDfeCtrl6.fs.hpf_coefm = (hpf_coefficent_reg >> 8) & 0xFF;
    pBQDev->EisDfeCtrl7.fs.hpf_coefl = (hpf_coefficent_reg) & 0xFF;
}
// **********************
// AUTO ADDRESS SEQUENCE
// **********************
/**
 * @brief PWM 晶振唤醒与初始化
 * 
 * 启用主设备的晶振 (Crystal)，并通过 PWM 信号唤醒堆叠设备。
 * 包含发送唤醒指令、延时等待以及调用 SleepWakeStackDevice。
 * 
 * @param pBQDev BQ 设备结构体
 * @param ReadBuf 读取缓冲区
 */
void PWM_CRYSTAL(bq7982x_dev_t *pBQDev, uint8_t *ReadBuf)
{
    uint32_t i;
    pBQDev[0].DevConf3.fs.crystal_en = 0b1;
    for(i = 1; i < TOTALBOARDS; i++)
    pBQDev[i].DevConf3.fs.crystal_en = 0b0;
    WriteReg(0, BQ7982X_DEV_CONF3_OFFSET, pBQDev->DevConf3.reg, 1, FRMWRT_SGL_W);
    for(i = 0; i < TOTALBOARDS; i++){
        WriteReg(TOTALBOARDS - 1 -i, BQ7982X_CONTROL1_OFFSET, 0x04, 1, FRMWRT_SGL_W);
        DEVICE_DELAY_US(1000);
    }
    for(i = 0; i<30; i++)
    {
        DEVICE_DELAY_US(10000); 
    }
    SleepWakeStackDevice();
    ReadReg(0, BQ7982X_DEV_STAT2_OFFSET, ReadBuf, 1, 0, FRMWRT_SGL_R);
    ReadReg(0, BQ7982X_FAULT_SYS1_OFFSET, ReadBuf, 1, 0, FRMWRT_SGL_R);
}

/**
 * @brief 关闭所有 BQ 设备
 * 
 * 向所有堆叠设备发送关闭指令 (CONTROL1 = 0x08)，并复位 MCU 的硬件接口。
 */
void ShutdownALLBQ(void)
{
    uint32_t i;
    for(i = 0; i < TOTALBOARDS - 1; i++)
    {
    WriteReg(TOTALBOARDS- 1 -i, BQ7982X_CONTROL1_OFFSET, 0x08, 1, FRMWRT_SGL_W);
    DEVICE_DELAY_US(1000);
    }
    HWRST_798XX();
    for(i = 0; i< 300; i++)
    DEVICE_DELAY_US(1000);
}
/**
 * @brief 检查同步状态
 * 
 * 检查所有从设备的频率调整值 (freq_adj)，判断系统是否已同步。
 * 如果所有设备的调整值都在阈值范围内 (<= 6)，则认为已同步。
 * 
 * @param pBQDev BQ 设备结构体
 * @return uint8_t 1: 已同步, 0: 未同步
 */
uint8_t CheckSyncStatus(bq7982x_dev_t *pBQDev)
{
    uint8_t i, max = 0;
    static uint32_t checkcount = 1;
    for(i = 1; i < TOTALBOARDS; i++)
    {
        if(abs((int8_t)pBQDev[i].freq_adj) > max) 
        max = abs((int8_t)pBQDev[i].freq_adj);
    }
    checkcount++;
    if (checkcount >10000) checkcount = 100;
    if(max > 6 || checkcount < 100)    
        return 0;
    return 1;
}

// Function: Convert 24-bit signed data (3 unsigned bytes) to int32_t (decimal stored in int32_t to prevent overflow)
// Parameters: byte_arr - Array of 3 unsigned bytes; is_little_endian - Whether the byte order is little-endian (1 = yes, 0 = big-endian)
// Return value: Converted decimal value (int32_t type, can be directly printed as decimal)
// int32_t convert_24bit_signed_to_decimal(const uint8_t byte_arr[3]) 
// {
//     uint32_t combined = 0;  // Use 32-bit unsigned integer for concatenation to avoid intermediate overflow
    
//     // 1. Concatenate 3 bytes according to byte order to get complete 24-bit data (stored in the lower 24 bits of uint32_t)
//         // Big-endian: byte[0] (upper 8 bits, contains sign bit) → byte[1] (middle 8 bits) → byte[2] (lower 8 bits)
//     combined = (uint32_t)byte_arr[0] << 16 | 
//                 ((uint32_t)byte_arr[1] << 8) | 
//                 (uint32_t)byte_arr[2];
//     // 2. Handle two's complement sign: sign-extend 24-bit signed number to 32 bits (critical! Avoids truncation)
//     int32_t result;
//     if (combined & (1U << 23)) {  // Check the highest bit of 24-bit data (bit 23, sign bit: 1 = negative, 0 = positive)
//         // Negative number: Convert 24-bit two's complement to 32-bit two's complement (fill upper 8 bits with 1s)
//         result = (int32_t)(combined | 0xFF000000U);
//     } else {
//         // Positive number: Convert 24-bit original code to 32-bit original code (fill upper 8 bits with 0s)
//         result = (int32_t)combined;
//     }
    
//     return result;  // The returned int32_t can be directly printed as decimal using printf("%d", result)
// }
