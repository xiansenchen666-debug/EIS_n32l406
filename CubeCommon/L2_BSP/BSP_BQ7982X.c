/*
 *  @file bq798xx.c
 *
 *  @author Vince Toledo - Texas Instruments Inc.
 *  @date February 2020
 *  @version 1.2
 *  @note Built with CCS for Hercules Version: 8.1.0.00011
 *  @note Built for TMS570LS1224 (LAUNCH XL2)
 */

/*
* Copyright (C) 2011-2022 Texas Instruments Incorporated - www.ti.com
*
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#include "bsp_bq7982x.h"
#include "MSP_GPIO.h"
#include "MSP_SPI.h"
#include "main.h" // For DEVICE_DELAY_US
#include "ProjectConfig.h"

#include <stdbool.h>


uint8_t bReturn = 0;
int bRes = 0;
uint8_t bBuf[8]; // 小缓冲区，用于构建寄存器数据
uint8_t pFrame[64]; // 发送帧缓冲区
uint16_t wCRC = 0;

/**
 * @brief 初始化唤醒引脚 (Wake Ping Initialization)
 *        配置 nPCS, PSCLK, PSDI 引脚为输出模式，并设置初始状态
 */
void Wake798XX_PingInit(void)
{
    /* 先把 nPCS 输出寄存器置高，防止初始化毛刺 */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);
	MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 1);

    /* 初始化三个引脚 */
    MSP_GPIO_Init(MSP_WAKE_NPCS_PORT,  MSP_WAKE_NPCS_PIN,  GPIO_Mode_Out_PP);
    MSP_GPIO_Init(MSP_WAKE_PSCLK_PORT, MSP_WAKE_PSCLK_PIN, GPIO_Mode_Out_PP);
    MSP_GPIO_Init(MSP_WAKE_PSDI_PORT,  MSP_WAKE_PSDI_PIN,  GPIO_Mode_Out_PP);

    /* 默认空闲状态 */
    MSP_GPIO_Write(MSP_WAKE_NPCS_PORT,  MSP_WAKE_NPCS_PIN, 1);
    MSP_GPIO_Write(MSP_WAKE_PSCLK_PORT, MSP_WAKE_PSCLK_PIN, 0);
    MSP_GPIO_Write(MSP_WAKE_PSDI_PORT,  MSP_WAKE_PSDI_PIN,  0);
}

/**
 * @brief 唤醒 BQ798XX 设备 (Wake Ping)
 *        拉低 COM 端口一定时间以产生唤醒信号
 *        用于将设备从 Shutdown 模式唤醒到 Active 模式
 */
void Wake798XX(void) {
    /* PSCLK = 0 */
    MSP_GPIO_Write(MSP_WAKE_PSCLK_PORT, MSP_WAKE_PSCLK_PIN, 0);
    /* PSDI = 0 */
    MSP_GPIO_Write(MSP_WAKE_PSDI_PORT, MSP_WAKE_PSDI_PIN, 0);
    /* nPCS 拉低 */
    MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 0);
    /* 6ms 延时 */
    DEVICE_DELAY_US(6000);
    /* nPCS 拉高 */
    MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 1);
}

/**
 * @brief 睡眠唤醒 (Sleep Wake Ping)
 *        持续时间较短的唤醒信号
 *        用于将设备从 Sleep 模式唤醒到 Active 模式
 */
void SleepWake798XX(void) {
    /* PSCLK = 0 */
    MSP_GPIO_Write(MSP_WAKE_PSCLK_PORT, MSP_WAKE_PSCLK_PIN, 0);
    /* PSDI = 0 */
    MSP_GPIO_Write(MSP_WAKE_PSDI_PORT, MSP_WAKE_PSDI_PIN, 0);
    /* nPCS 拉低 */
    MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 0);
    DEVICE_DELAY_US(1000); // WAKE ping = 0.5ms 到 1.5ms
    /* nPCS 拉高 */
    MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 1);
}

/**
 * @brief 硬件复位 (Hardware Reset Ping)
 *        持续时间很长的低电平信号
 *        用于强制复位设备
 */
void HWRST_798XX(void) {
    /* PSCLK = 0 */
    MSP_GPIO_Write(MSP_WAKE_PSCLK_PORT, MSP_WAKE_PSCLK_PIN, 0);
    /* PSDI = 0 */
    MSP_GPIO_Write(MSP_WAKE_PSDI_PORT, MSP_WAKE_PSDI_PIN, 0);
    /* nPCS 拉低 */
    MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 0);
    DEVICE_DELAY_US(26000); // HWST ping = 24~28ms
    /* nPCS 拉高 */
    MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 1);
}

//************************
// 读写函数 (WRITE AND READ FUNCTIONS)
//************************

/**
 * @brief 格式化写数据并发送 (Write Register)
 *        将 64位数据根据长度拆分，调用 WriteFrame 发送
 *        支持单字节到 8字节的写入
 *
 * @param bID 设备 ID (Device ID)
 * @param wAddr 寄存器地址 (Register Address)
 * @param dwData 要写入的数据 (Data to write, up to 8 bytes)
 * @param bLen 数据长度 (1-8 字节)
 * @param bWriteType 写类型 (单播/广播/堆栈) (Write Type: Single/Broadcast/Stack)
 * @return int 写入结果 (Result)
 */
int WriteReg(uint8_t bID, uint16_t wAddr, uint64_t dwData, uint8_t bLen, uint8_t bWriteType) 
{
    // 设备地址, 寄存器起始地址, 数据字节, 数据长度, 写类型 (单播, 广播, 堆栈)
    bRes = 0;
    memset(bBuf,0,sizeof(bBuf));
    switch (bLen) {
    case 1:
        bBuf[0] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 1, bWriteType);
        break;
    case 2:
        bBuf[0] = (dwData & 0x000000000000FF00) >> 8;
        bBuf[1] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 2, bWriteType);
        break;
    case 3:
        bBuf[0] = (dwData & 0x0000000000FF0000) >> 16;
        bBuf[1] = (dwData & 0x000000000000FF00) >> 8;
        bBuf[2] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 3, bWriteType);
        break;
    case 4:
        bBuf[0] = (dwData & 0x00000000FF000000) >> 24;
        bBuf[1] = (dwData & 0x0000000000FF0000) >> 16;
        bBuf[2] = (dwData & 0x000000000000FF00) >> 8;
        bBuf[3] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 4, bWriteType);
        break;
    case 5:
        bBuf[0] = (dwData & 0x000000FF00000000) >> 32;
        bBuf[1] = (dwData & 0x00000000FF000000) >> 24;
        bBuf[2] = (dwData & 0x0000000000FF0000) >> 16;
        bBuf[3] = (dwData & 0x000000000000FF00) >> 8;
        bBuf[4] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 5, bWriteType);
        break;
    case 6:
        bBuf[0] = (dwData & 0x0000FF0000000000) >> 40;
        bBuf[1] = (dwData & 0x000000FF00000000) >> 32;
        bBuf[2] = (dwData & 0x00000000FF000000) >> 24;
        bBuf[3] = (dwData & 0x0000000000FF0000) >> 16;
        bBuf[4] = (dwData & 0x000000000000FF00) >> 8;
        bBuf[5] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 6, bWriteType);
        break;
    case 7:
        bBuf[0] = (dwData & 0x00FF000000000000) >> 48;
        bBuf[1] = (dwData & 0x0000FF0000000000) >> 40;
        bBuf[2] = (dwData & 0x000000FF00000000) >> 32;
        bBuf[3] = (dwData & 0x00000000FF000000) >> 24;
        bBuf[4] = (dwData & 0x0000000000FF0000) >> 16;
        bBuf[5] = (dwData & 0x000000000000FF00) >> 8;
        bBuf[6] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 7, bWriteType);
        break;
    case 8:
        bBuf[0] = (dwData & 0xFF00000000000000) >> 56;
        bBuf[1] = (dwData & 0x00FF000000000000) >> 48;
        bBuf[2] = (dwData & 0x0000FF0000000000) >> 40;
        bBuf[3] = (dwData & 0x000000FF00000000) >> 32;
        bBuf[4] = (dwData & 0x00000000FF000000) >> 24;
        bBuf[5] = (dwData & 0x0000000000FF0000) >> 16;
        bBuf[6] = (dwData & 0x000000000000FF00) >> 8;
        bBuf[7] = dwData & 0x00000000000000FF;
        bRes = WriteFrame(bID, wAddr, bBuf, 8, bWriteType);
        break;
    default:
        break;
    }

    return bRes;
}

/**
 * @brief SPI 接收超时函数 (Receive Timeout)
 *        通过 SPI 发送 dummy 数据 (0xFF00) 来提供时钟，从而接收数据
 *        主要用于读取 BQ 设备的响应
 *
 * @param base SPI 基地址 (SPI Base Address)
 * @param length 要接收的字节数 (Bytes to receive)
 * @param data 接收数据缓冲区 (Data Buffer)
 * @param timeout 超时值 (目前未完全实现超时逻辑) (Timeout value)
 * @return uint32_t 接收长度 (Received length)
 */
uint32_t Receive_TO(
    SPI_Module* base, uint32_t length, uint8_t *data, uint32_t timeout)
{
    uint16_t received;

    // 在第一个时钟前 6us 拉低 nCS
		MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 0);
		DEVICE_DELAY_US(10);

    uint8_t i;
    for(i = 0; i < length; i++)
    {
       // 发送 Dummy 数据以产生时钟
       if (SPI_writeDataBlockingFIFO(base, 0x00FF, timeout) != 0)
       {
           break;
       }
       // 读取接收到的数据
       if (SPI_readDataBlockingFIFO(base, &received, timeout) != 0)
       {
           break;
       }
       *data++ = (uint8_t)received;
    }

    // 在最后一个时钟后 6us 拉高 nCS
    DEVICE_DELAY_US(10);
		MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 1);
    // 确保每个命令之间有 6us 间隔 
    DEVICE_DELAY_US(10);
    
    return i == length ? length : 0u;
}

/**
 * @brief 读取寄存器 (Read Register)
 *        发送读取请求帧，然后等待响应数据
 *        支持单播、堆栈读取和广播读取
 *
 * @param bID 设备 ID (Device ID)
 * @param wAddr 寄存器地址 (Register Address)
 * @param pData 数据缓冲区 (Data Buffer)
 * @param bLen 读取长度 (Length to read)
 * @param dwTimeOut 超时时间 (Timeout)
 * @param bWriteType 读取类型 (单播/广播/堆栈) (Read Type: Single/Broadcast/Stack)
 * @return int 结果 (Result)
 */
int ReadReg(uint8_t bID, uint16_t wAddr, uint8_t * pData, uint8_t bLen, uint32_t dwTimeOut,
        uint8_t bWriteType) {
        
    uint32_t Timeout_count = dwTimeOut;
    // 设备地址, 寄存器起始地址, 数据指针, 数据长度, 读取类型
    bRes = 0;
    Timeout_count = 5000;  // 5000 Timeout_count 

    // 根据读取类型计算需要接收的总字节数
    // 每个响应帧包含: 帧头(1) + 长度(1) + 地址(2) + 数据(N) + CRC(2) = N + 6 字节
    if (bWriteType == FRMWRT_SGL_R) {
        ReadFrameReq(bID, wAddr, bLen, bWriteType); // 发送请求
        memset(pData, 0, (bLen + 6));
        bRes = Receive_TO(mySPI0_BASE, (bLen + 6) , pData, Timeout_count); // 接收响应

    } else if (bWriteType == FRMWRT_STK_R) {
        bRes = ReadFrameReq(bID, wAddr, bLen, bWriteType);
        memset(pData, 0, (bLen + 6) * (TOTALBOARDS - 1));
        // 堆栈读取：接收 (TOTALBOARDS - 1) 个设备的响应
        bRes = Receive_TO(mySPI0_BASE,  (bLen + 6) * (TOTALBOARDS - 1) , pData, Timeout_count);

    } else if (bWriteType == FRMWRT_ALL_R) {
        bRes = ReadFrameReq(bID, wAddr, bLen, bWriteType);
        memset(pData, 0, (bLen + 6) * TOTALBOARDS);
        // 广播读取：接收 TOTALBOARDS 个设备的响应
        bRes = Receive_TO(mySPI0_BASE, (bLen + 6) * TOTALBOARDS , pData, Timeout_count);
        
    } else {
        bRes = 0;
    }

    return bRes;
}

/**
 * @brief 构建并发送写命令帧 (Write Frame)
 *        构建 SPI 帧格式并发送
 *        帧格式: 控制字节 + (设备ID) + 寄存器地址(2) + 数据(N) + CRC(2)
 *
 * @param bID 设备 ID (Device ID)
 * @param wAddr 寄存器地址 (Register Address)
 * @param pData 数据指针 (Data Pointer)
 * @param bLen 数据长度 (Data Length)
 * @param bWriteType 写类型 (Write Type)
 * @return int 发送的数据包长度 (Packet Length)
 */
int WriteFrame(uint8_t bID, uint16_t wAddr, uint8_t * pData, uint8_t bLen, uint8_t bWriteType) {
    int bPktLen = 0;
    uint8_t * pBuf = pFrame;
    memset(pFrame, 0x7F, sizeof(pFrame)); // 填充默认值
    
    // 构建控制字节: Bit7=1(Write), Bit6-4=Type, Bit3-0=Length-1 (如果是写操作)
    // AI Fix: Only set Bit 7 (0x80) if it is a Write operation (checked via bWriteType & 0x08)
    // Previously: *pBuf++ = 0x80 | (bWriteType) | ((bWriteType & 0x08) ? bLen - 0x01 : 0x00);
    *pBuf++ = 0x80 | (bWriteType) | ((bWriteType & 0x08) ? bLen - 0x01 : 0x00); //Only include blen if it is a write; Writes are 0x90, 0xB0, 0xD0
    
    // 单播操作需要包含设备 ID
    if (bWriteType == FRMWRT_SGL_R || bWriteType == FRMWRT_SGL_W)
    {
        *pBuf++ = (bID & 0x00FF);
    }
    
    // 寄存器地址 (大端序)
    *pBuf++ = (wAddr & 0xFF00) >> 8;
    *pBuf++ = wAddr & 0x00FF;

    // 填充数据
    while (bLen--)
        *pBuf++ = *pData++;

    bPktLen = pBuf - pFrame;

    // 计算并追加 CRC
    wCRC = CRC16(pFrame, bPktLen);
    *pBuf++ = wCRC & 0x00FF;
    *pBuf++ = (wCRC & 0xFF00) >> 8;
    bPktLen += 2;

    // 发送 SPI 数据
    // 在第一个时钟前 6us 拉低 nCS
		MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 0);
    DEVICE_DELAY_US(10);

    uint8_t i;
    uint16_t received;
    for(i = 0; i < bPktLen; i++)
    {
       if (SPI_writeDataBlockingFIFO(mySPI0_BASE, pFrame[i], MSP_SPI_FIFO_TIMEOUT_LOOPS) != 0 ||
           SPI_readDataBlockingFIFO(mySPI0_BASE, &received, MSP_SPI_FIFO_TIMEOUT_LOOPS) != 0)
       {
           MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 1);
           return -1;
       }
    }

    // 在最后一个时钟后 6us 拉高 nCS
    DEVICE_DELAY_US(10);      
		MSP_GPIO_Write(MSP_WAKE_NPCS_PORT, MSP_WAKE_NPCS_PIN, 1);
    // 确保命令间隔
    DEVICE_DELAY_US(10);
    return bPktLen;
}

/**
 * @brief 发送读取请求帧 (Read Frame Request)
 *        发送一个写命令，告诉设备我们要读取哪些寄存器
 *        这只是发送请求，实际数据通过 Receive_TO 接收
 *
 * @param bID 设备 ID (Device ID)
 * @param wAddr 寄存器地址 (Register Address)
 * @param bByteToReturn 请求返回的字节数 (Bytes to return)
 * @param bWriteType 读取类型 (Read Type)
 * @return int
 */
int ReadFrameReq(uint8_t bID, uint16_t wAddr, uint8_t bByteToReturn, uint8_t bWriteType) {
    bReturn = bByteToReturn - 1;

    if (bReturn > 127)
        return 0;

    // 读取请求实际上是一个写操作，写入要读取的长度
    // 但 WriteFrame 会根据 bWriteType 处理帧结构
    return WriteFrame(bID, wAddr, &bReturn, 1, bWriteType);
}

// CRC16 表
// 多项式: x^16 + x^15 + x^2 + 1 (0x8005) -> 反转后 0xA001?
// ITU_T polynomial
const uint16_t crc16_table[256] = { 0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301,
        0x03C0, 0x0280, 0xC241, 0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1,
        0xC481, 0x0440, 0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81,
        0x0E40, 0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
        0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40, 0x1E00,
        0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41, 0x1400, 0xD4C1,
        0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641, 0xD201, 0x12C0, 0x1380,
        0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040, 0xF001, 0x30C0, 0x3180, 0xF141,
        0x3300, 0xF3C1, 0xF281, 0x3240, 0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501,
        0x35C0, 0x3480, 0xF441, 0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0,
        0x3E80, 0xFE41, 0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881,
        0x3840, 0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
        0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40, 0xE401,
        0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640, 0x2200, 0xE2C1,
        0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041, 0xA001, 0x60C0, 0x6180,
        0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240, 0x6600, 0xA6C1, 0xA781, 0x6740,
        0xA501, 0x65C0, 0x6480, 0xA441, 0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01,
        0x6FC0, 0x6E80, 0xAE41, 0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1,
        0xA881, 0x6840, 0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80,
        0xBA41, 0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
        0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640, 0x7200,
        0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041, 0x5000, 0x90C1,
        0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241, 0x9601, 0x56C0, 0x5780,
        0x9741, 0x5500, 0x95C1, 0x9481, 0x5440, 0x9C01, 0x5CC0, 0x5D80, 0x9D41,
        0x5F00, 0x9FC1, 0x9E81, 0x5E40, 0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901,
        0x59C0, 0x5880, 0x9841, 0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1,
        0x8A81, 0x4A40, 0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80,
        0x8C41, 0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
        0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040 };

/**
 * @brief 计算 CRC16 (Calculate CRC16)
 *        用于 SPI 通信帧的校验
 * @param pBuf 数据缓冲区 (Data Buffer)
 * @param nLen 数据长度 (Data Length)
 * @return uint16_t CRC 值 (CRC Value)
 */
uint16_t CRC16(uint8_t *pBuf, int nLen) {
    uint16_t wCRC = 0xFFFF;
    int i;

    for (i = 0; i < nLen; i++) {
        wCRC ^= (*pBuf++) & 0x00FF;
        wCRC = crc16_table[wCRC & 0x00FF] ^ (wCRC >> 8);
    }

    return wCRC;
}
//****************************
// 结束读写函数
//****************************

//EOF
