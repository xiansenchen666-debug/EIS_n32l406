/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_SPI.c
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-12-04
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#include "MSP_SPI.h"

/**
 * @brief  Initializes the SPIx peripheral.
 * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
 */
void MSP_SPI_Init(SPI_Module* SPIx)
{
    GPIO_InitType GPIO_InitStructure;
    SPI_InitType SPI_InitStructure;
    GPIO_InitStruct(&GPIO_InitStructure);
    if (SPIx == SPI1)
    {
        /* Enable SPI1 and GPIOA clocks */
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_SPI1 | RCC_APB2_PERIPH_GPIOA |    RCC_APB2_PERIPH_AFIO, ENABLE);
        /* SPI1 SCK (PA5) and MOSI (PA7) configuration */
        GPIO_InitStructure.Pin            = GPIO_PIN_5 | GPIO_PIN_7;
        GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF0_SPI1;
        GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
        /* SPI1 MISO (PA6) configuration */
        GPIO_InitStructure.Pin            = GPIO_PIN_6;
        GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_Input; // MISO Input
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF0_SPI1;
        GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
    }
    else if (SPIx == SPI2)
    {
        /* Enable SPI2 and GPIOB clocks */
        RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_SPI2 | RCC_APB2_PERIPH_GPIOB | RCC_APB2_PERIPH_AFIO, ENABLE);
        /* SPI2 SCK (PB13) and MOSI (PB15) configuration */
        GPIO_InitStructure.Pin            = GPIO_PIN_13 | GPIO_PIN_15;
        GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF0_SPI2;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
        /* SPI2 MISO (PB14) configuration */
        GPIO_InitStructure.Pin            = GPIO_PIN_14;
        GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_Input; // MISO Input
        GPIO_InitStructure.GPIO_Alternate = GPIO_AF0_SPI2;
        GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);
    }
    /* SPI Config */
    SPI_InitStructure.DataDirection = SPI_DIR_DOUBLELINE_FULLDUPLEX;
    SPI_InitStructure.SpiMode       = SPI_MODE_MASTER;
    SPI_InitStructure.DataLen       = SPI_DATA_SIZE_8BITS;
    SPI_InitStructure.CLKPOL        = SPI_CLKPOL_LOW;         // CPOL=0
    SPI_InitStructure.CLKPHA        =   SPI_CLKPHA_FIRST_EDGE; // CPHA=0 (Mode 0 for TI BQ)
    SPI_InitStructure.NSS           = SPI_NSS_SOFT;           // Software CS
    /* System Clock 64MHz. Prescaler 16 -> 4MHz. Prescaler 8 -> 8MHz. */
    // Using 4MHz to be safe for BQ7982X (Max SPI freq is often 6MHz)
    SPI_InitStructure.BaudRatePres  = SPI_BR_PRESCALER_32;
    SPI_InitStructure.FirstBit      = SPI_FB_MSB;
    SPI_InitStructure.CRCPoly       = 7;
    SPI_Init(SPIx, &SPI_InitStructure);
    /* Enable SPI */
    SPI_Enable(SPIx, ENABLE);
}

/**
 * @brief  Sends a data through the SPIx/I2Sx peripheral (blocking).
 * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
 * @param  Data: Data to be transmitted.
 */
int SPI_writeDataBlockingFIFO(SPI_Module* SPIx, uint16_t Data, uint32_t timeout_loops)
{
    while (SPI_I2S_GetStatus(SPIx, SPI_I2S_TE_FLAG) == RESET)
    {
        if (timeout_loops-- == 0u)
        {
            return -1;
        }
    }

    /* Send byte through the SPIx/I2Sx peripheral */
    SPI_I2S_TransmitData(SPIx, Data);
    return 0;
}

/**
 * @brief  Returns the most recent received data by the SPIx/I2Sx peripheral (blocking).
 * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
 * @return The value of the received data.
 */
int SPI_readDataBlockingFIFO(SPI_Module* SPIx, uint16_t *Data, uint32_t timeout_loops)
{
    while (SPI_I2S_GetStatus(SPIx, SPI_I2S_RNE_FLAG) == RESET)
    {
        if (timeout_loops-- == 0u)
        {
            return -1;
        }
    }

    /* Return the data in the DR register */
    *Data = SPI_I2S_ReceiveData(SPIx);
    return 0;
}
