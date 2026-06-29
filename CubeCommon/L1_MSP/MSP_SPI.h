/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_SPI.h
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-12-04
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#ifndef _MSP_SPI_H_
#define _MSP_SPI_H_

#include "n32l40x.h"
#include "n32l40x_spi.h"

// Define mySPI0_BASE mapping 
// Based on BSP_BQ7982X.h (PB12/PB13/PB15), this should be SPI2
#define mySPI0_BASE     SPI2

void MSP_SPI_Init(SPI_Module* SPIx);
#define MSP_SPI_FIFO_TIMEOUT_LOOPS (100000u)

int SPI_writeDataBlockingFIFO(SPI_Module* SPIx, uint16_t Data, uint32_t timeout_loops);
int SPI_readDataBlockingFIFO(SPI_Module* SPIx, uint16_t *Data, uint32_t timeout_loops);

#endif
