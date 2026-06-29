/*
 *  @file bq797xx.h
 *
 *  @author Vince Toledo - Texas Instruments Inc.
 *  @date February 2020
 *  @version 1.2
 *  @note Built with CCS for Hercules Version: 8.1.0.00011
 *  @note Built for TMS570LS1224 (LAUNCH XL2)
 */

/*****************************************************************************
**
**  Copyright (c) 2011-2019 Texas Instruments
**
******************************************************************************/


#ifndef BQ797xx_H_
#define BQ797xx_H_


#include "string.h"
#include "bsp_bq7982x_regs.h"
#include "bsp_bq7982x_regs_types.h"
#include "bsp_bq7982x_data_types.h"


/* ============================================================================ */
/* WAKE Ping 引脚定义 */
/* ============================================================================ */

#define MSP_WAKE_NPCS_PORT      GPIOB
#define MSP_WAKE_NPCS_PIN       GPIO_PIN_12

#define MSP_WAKE_PSCLK_PORT     GPIOB
#define MSP_WAKE_PSCLK_PIN      GPIO_PIN_13

#define MSP_WAKE_PSDI_PORT      GPIOB
#define MSP_WAKE_PSDI_PIN       GPIO_PIN_15

#define MAXBYTES (26*3)     //maximum number of bytes to be read from the devices (for array creation)


#define TOTALBOARDS 1       //boards in stack

#define ACTIVECHANNELS 13
#define GADC_ACTIVECHANNEL 20
#define ACTIVECHANNELS_C 1

#define BRIDGEDEVICE 1

void DEVICE_DELAY_US(uint32_t us);

#define FRMWRT_SGL_R	0x10    //single device READ
#define FRMWRT_SGL_W	0x18    //single device WRITE
#define FRMWRT_ALL_R	0x00    //broadcast READ
#define FRMWRT_ALL_W	0x08    //broadcast WRITE
#define FRMWRT_STK_R    0xFF    //stack READ
#define FRMWRT_STK_W    0xFF    //stack WRITE

/**
 * Parameter
 * Resolution for VC/CB/GPIO/D1/D2/REF4V/TSREF
 */
#define VLSB_STANDARD 100       // uV/LSB
#define VLSB_STANDARD_F 0.0001  // V/LSB
#define VLSB_GPIO_RATIO 0.005   //%/LSB
#define CLSB_CS_AC 2.4       // uV/LSB
#define VLSB_Vcell_AC 2.4       // uV/LSB


// Function Prototypes
void Wake798XX_PingInit(void);
void Wake798XX();
void SleepWake798XX(void);
void HWRST_798XX(void); 
uint16_t CRC16(uint8_t *pBuf, int nLen);

int WriteFrame(uint8_t bID, uint16_t wAddr, uint8_t * pData, uint8_t bLen, uint8_t bWriteType);
int ReadFrameReq(uint8_t bID, uint16_t wAddr, uint8_t bByteToReturn, uint8_t bWriteType);
int WriteReg(uint8_t bID, uint16_t wAddr, uint64_t dwData, uint8_t bLen, uint8_t bWriteType);
int ReadReg(uint8_t bID, uint16_t wAddr, uint8_t * pData, uint8_t bLen, uint32_t dwTimeOut, uint8_t bWriteType);


#endif /* BQ79606_H_ */
//EOF
