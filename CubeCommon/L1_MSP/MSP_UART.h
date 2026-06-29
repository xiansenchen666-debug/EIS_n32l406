/************************************** (C) Copyright 2022-2024 De.Power,China. *************************************
 *                                                DE.POWER Co., Ltd                                                 *
 *                                              Product R & D department                                            *
 *                                                Software Department                                               *
 *                                                All Rights Reserved.                                              */
/********************************************************************************************************************
 * @file            MSP_UART.h
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-12-06
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#ifndef _MSP_UART_H_
#define _MSP_UART_H_

#include <stdint.h>

void log_uart_init(uint32_t baudrate);
void log_uart_wait_tx_complete(void);

#endif
