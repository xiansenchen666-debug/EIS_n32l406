/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited.  This product  is  protected  under  copyright  law
 *                 and  trade  secret law as an  unpublished work.
 *                 (C) Copyright 2021 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       bq7982x_regs.h
 *  Project:    TIBMS
 *  Module:     COMIF
 *  Generator:  Code generation tool (if any)
 *
 *  Description:  Register definitions for BQ79600 device
 *
 *--------------------------------------------------------------------------------------------------------------------
 * Author:  SEM
 *--------------------------------------------------------------------------------------------------------------------
 * Revision History (top to bottom: first revision to last revision)
 *--------------------------------------------------------------------------------------------------------------------
 * Version        Date         Author               Change ID        Description
 *--------------------------------------------------------------------------------------------------------------------
 * 10.00.00       25MAR2024    SEM                0000000000000    Initial version
 * 10.00.01       08May2024    SEM                0000000000000    Updated as per the latest datasheet
 *
 *********************************************************************************************************************/

#ifndef BQ7982X_REGS_H
#define BQ7982X_REGS_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************************************************************
 * Standard Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Other Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version (Check if required)
 *********************************************************************************************************************/

#define BQ7982X_REGS_MAJOR_VERSION                      (0x01u)
#define BQ7982X_REGS_MINOR_VERSION                      (0x00u)
#define BQ7982X_REGS_PATCH_VERSION                      (0x00u)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

#define BQ7982X_GPIO_CONF_REG_NUM                       (0x0Au)
#define BQ7982X_ADC_CTRL_REG_NUM                        (0x05u)
#define BQ7982X_BAL_CTRL_REG_NUM                        (0x03u)
#define BQ7982X_DIAG_ADC_DEV_STAT_NUM                   (0x03u)
#define BQ7982X_FAULT_ADC_GPIO_NUM                      (0x03u)
#define BQ7982X_FAULT_ADC_VCELL_NUM                     (0x04u)
#define BQ7982X_FAULT_OVUV_NUM                          (0x01u)
#define BQ7982X_FAULT_OTUT_NUM                          (0x01u)
#define BQ7982X_FAULT_ADC_DIG_NUM                       (0x05u)
#define BQ7982X_DEV_CONF_REG_NUM                        (0x03u)


/* --------------------------------------------------------------------------
 * CUST_CRCHI          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_CRCHI_OFFSET                       (0x0000u)
#define BQ7982X_CUST_CRCHI_POR_VAL                      (0x47u)

#define BQ7982X_CUST_CRCHI_CRC_POS                      (0x00u)
#define BQ7982X_CUST_CRCHI_CRC_MSK                      (0xFFu)

/* --------------------------------------------------------------------------
 * CUST_CRCLO          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_CRCLO_OFFSET                       (0x0001u)
#define BQ7982X_CUST_CRCLO_POR_VAL                      (0xF1u)

#define BQ7982X_CUST_CRCLO_CRC_POS                      (0x00u)
#define BQ7982X_CUST_CRCLO_CRC_MSK                      (0xFFu)

/* --------------------------------------------------------------------------
 * DEV_CONF1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEV_CONF1_OFFSET                        (0x0002u)
#define BQ7982X_DEV_CONF1_POR_VAL                       (0x01u)

#define BQ7982X_DEV_CONF1_SPARE_POS                     (0x05u)
#define BQ7982X_POS_DEV_CONF1_VIO_UV_DS_DIS             (0x04u)
#define BQ7982X_POS_DEV_CONF1_DEEPSLEEP_DIS             (0x03u)
#define BQ7982X_DEV_CONF1_TSREF_DLY_POS                 (0x01u)
#define BQ7982X_DEV_CONF1_NFAULT_EN_POS                 (0x00u)

#define BQ7982X_DEV_CONF1_SPARE_MSK                     (0xE0u)
#define BQ7982X_MSK_DEV_CONF1_VIO_UV_DS_DIS             (0x10u)
#define BQ7982X_MSK_DEV_CONF1_DEEPSLEEP_DIS             (0x08u)
#define BQ7982X_DEV_CONF1_TSREF_DLY_MSK                 (0x06u)
#define BQ7982X_DEV_CONF1_NFAULT_EN_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * DEV_CONF2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEV_CONF2_OFFSET                        (0x0003u)
#define BQ7982X_DEV_CONF2_POR_VAL                       (0x00u)

#define BQ7982X_DEV_CONF2_MON_CYCLE_POS                 (0x05u)
#define BQ7982X_DEV_CONF2_NUM_CELL_POS                  (0x00u)

#define BQ7982X_DEV_CONF2_MON_CYCLE_MSK                 (0xE0u)
#define BQ7982X_DEV_CONF2_NUM_CELL_MSK                  (0x1Fu)

/* --------------------------------------------------------------------------
 * DEV_CONF3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEV_CONF3_OFFSET                        (0x0004u)
#define BQ7982X_DEV_CONF3_POR_VAL                       (0x05u)

#define BQ7982X_POS_DEV_CONF3_CRYSTAL_EN                (0x07u)
#define BQ7982X_DEV_CONF3_PTC_EN_POS                    (0x06u)
#define BQ7982X_DEV_CONF3_I_CB_LKG_POS                  (0x05u)
#define BQ7982X_POS_DEV_CONF3_CBADC_OFFSET              (0x03u)
#define BQ7982X_DEV_CONF3_TWARN_THR_POS                  (0x02u)
#define BQ7982X_POS_DEV_CONF3_CBTWARN_DIS               (0x01u)
#define BQ7982X_DEV_CONF3_NO_ADJ_CB_POS                 (0x00u)

#define BQ7982X_MSK_DEV_CONF3_CRYSTAL_EN                (0x80u)
#define BQ7982X_DEV_CONF3_PTC_EN_MSK                    (0x40u)
#define BQ7982X_DEV_CONF3_I_CB_LKG_MSK                  (0x20u)
#define BQ7982X_MSK_DEV_CONF3_CBADC_OFFSET              (0x18u)
#define BQ7982X_DEV_CONF3_TWARN_THR_MSK                 (0x04u)
#define BQ7982X_MSK_DEV_CONF3_CBTWARN_DIS               (0x02u)
#define BQ7982X_DEV_CONF3_NO_ADJ_CB_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * COMM_CONF1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_COMM_CONF1_OFFSET                       (0x0007u)
#define BQ7982X_COMM_CONF1_POR_VAL                      (0x00u)

#define BQ7982X_POS_COMM_CONF1_MD_HB_TO_TIMER           (0x07u)
#define BQ7982X_POS_COMM_CONF1_HB_TO_TIMER              (0x06u)
#define BQ7982X_COMM_CONF1_HB_TIMER_POS                 (0x05u)
#define BQ7982X_POS_COMM_CONF1_FRAME_LINK               (0x04u)
#define BQ7982X_COMM_CONF1_GROUP_POS                    (0x02u)
#define BQ7982X_COMM_CONF1_FRAME_EN_POS                 (0x01u)
#define BQ7982X_POS_COMM_CONF1_CRC_LENGTH               (0x00u)

#define BQ7982X_MSK_COMM_CONF1_MD_HB_TO_TIMER          (0x80u)
#define BQ7982X_MSK_COMM_CONF1_HB_TO_TIMER             (0x40u)
#define BQ7982X_COMM_CONF1_HB_TIMER_MSK                (0x20u)
#define BQ7982X_MSK_COMM_CONF1_FRAME_LINK              (0x10u)
#define BQ7982X_COMM_CONF1_GROUP_MSK                   (0x0Cu)
#define BQ7982X_COMM_CONF1_FRAME_EN_MSK                (0x02u)
#define BQ7982X_MSK_COMM_CONF1_CRC_LENGTH              (0x01u)

/* --------------------------------------------------------------------------
 * COMM_CONF2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_COMM_CONF2_OFFSET                       (0x0008u)
#define BQ7982X_COMM_CONF2_POR_VAL                      (0x00u)

#define BQ7982X_POS_COMM_CONF2_MD_RING_MODE             (0x07u)
#define BQ7982X_POS_COMM_CONF2_MD_HB_CONF1              (0x06u)
#define BQ7982X_POS_COMM_CONF2_MD_HB_CONF0              (0x05u)
#define BQ7982X_COMM_CONF2_MD_HB_EN_POS                 (0x04u)
#define BQ7982X_POS_COMM_CONF2_RING_MODE                (0x03u)
#define BQ7982X_COMM_CONF2_HB_CONF1_POS                 (0x02u)
#define BQ7982X_COMM_CONF2_HB_CONF0_POS                 (0x01u)
#define BQ7982X_COMM_CONF2_HB_EN_POS                   (0x00u)

#define BQ7982X_MSK_COMM_CONF2_MD_RING_MODE            (0x80u)
#define BQ7982X_MSK_COMM_CONF2_MD_HB_CONF1            (0x40u)
#define BQ7982X_MSK_COMM_CONF2_MD_HB_CONF0            (0x20u)
#define BQ7982X_COMM_CONF2_MD_HB_EN_MSK               (0x10u)
#define BQ7982X_MSK_COMM_CONF2_RING_MODE              (0x08u)
#define BQ7982X_COMM_CONF2_HB_CONF1_MSK               (0x04u)
#define BQ7982X_COMM_CONF2_HB_CONF0_MSK               (0x02u)
#define BQ7982X_COMM_CONF2_HB_EN_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * COMM_CONF3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_COMM_CONF3_OFFSET                       (0x0009u)
#define BQ7982X_COMM_CONF3_POR_VAL                      (0x00u)

#define BQ7982X_COMM_CONF3_SPARE6_POS                   (0x07u)
#define BQ7982X_COMM_CONF3_SPARE5_POS                   (0x06u)
#define BQ7982X_COMM_CONF3_SPARE4_POS                   (0x05u)
#define BQ7982X_COMM_CONF3_SPARE3_POS                   (0x04u)
#define BQ7982X_COMM_CONF3_SPARE2_POS                   (0x03u)
#define BQ7982X_COMM_CONF3_SPARE1_POS                   (0x02u)
#define BQ7982X_COMM_CONF3_SPARE0_POS                   (0x01u)
#define BQ7982X_POS_COMM_CONF3_IDDQ_COMM_EN             (0x00u)

#define BQ7982X_COMM_CONF3_SPARE6_MSK                   (0x80u)
#define BQ7982X_COMM_CONF3_SPARE5_MSK                   (0x40u)
#define BQ7982X_COMM_CONF3_SPARE4_MSK                   (0x20u)
#define BQ7982X_COMM_CONF3_SPARE3_MSK                   (0x10u)
#define BQ7982X_COMM_CONF3_SPARE2_MSK                   (0x08u)
#define BQ7982X_COMM_CONF3_SPARE1_MSK                   (0x04u)
#define BQ7982X_COMM_CONF3_SPARE0_MSK                   (0x02u)
#define BQ7982X_MSK_COMM_CONF3_IDDQ_COMM_EN             (0x01u)


/* --------------------------------------------------------------------------
 * BBVC_POSN1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BBVC_POSN1_OFFSET                       (0x000Cu)
#define BQ7982X_BBVC_POSN1_POR_VAL                      (0x00u)

#define BQ7982X_BBVC_POSN1_CELL8_POS                    (0x07u)
#define BQ7982X_BBVC_POSN1_CELL7_POS                    (0x06u)
#define BQ7982X_BBVC_POSN1_CELL6_POS                    (0x05u)
#define BQ7982X_BBVC_POSN1_CELL5_POS                    (0x04u)
#define BQ7982X_BBVC_POSN1_CELL4_POS                    (0x03u)
#define BQ7982X_BBVC_POSN1_CELL3_POS                    (0x02u)
#define BQ7982X_BBVC_POSN1_CELL2_POS                    (0x01u)
#define BQ7982X_BBVC_POSN1_CELL1_POS                    (0x00u)

#define BQ7982X_BBVC_POSN1_CELL8_MSK                    (0x80u)
#define BQ7982X_BBVC_POSN1_CELL7_MSK                    (0x40u)
#define BQ7982X_BBVC_POSN1_CELL6_MSK                    (0x20u)
#define BQ7982X_BBVC_POSN1_CELL5_MSK                    (0x10u)
#define BQ7982X_BBVC_POSN1_CELL4_MSK                    (0x08u)
#define BQ7982X_BBVC_POSN1_CELL3_MSK                    (0x04u)
#define BQ7982X_BBVC_POSN1_CELL2_MSK                    (0x02u)
#define BQ7982X_BBVC_POSN1_CELL1_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * BBVC_POSN2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BBVC_POSN2_OFFSET                       (0x000Du)
#define BQ7982X_BBVC_POSN2_POR_VAL                      (0x00u)

#define BQ7982X_BBVC_POSN2_CELL16_POS                   (0x07u)
#define BQ7982X_BBVC_POSN2_CELL15_POS                   (0x06u)
#define BQ7982X_BBVC_POSN2_CELL14_POS                   (0x05u)
#define BQ7982X_BBVC_POSN2_CELL13_POS                   (0x04u)
#define BQ7982X_BBVC_POSN2_CELL12_POS                   (0x03u)
#define BQ7982X_BBVC_POSN2_CELL11_POS                   (0x02u)
#define BQ7982X_BBVC_POSN2_CELL10_POS                   (0x01u)
#define BQ7982X_BBVC_POSN2_CELL9_POS                    (0x00u)

#define BQ7982X_BBVC_POSN2_CELL16_MSK                   (0x80u)
#define BQ7982X_BBVC_POSN2_CELL15_MSK                   (0x40u)
#define BQ7982X_BBVC_POSN2_CELL14_MSK                   (0x20u)
#define BQ7982X_BBVC_POSN2_CELL13_MSK                   (0x10u)
#define BQ7982X_BBVC_POSN2_CELL12_MSK                   (0x08u)
#define BQ7982X_BBVC_POSN2_CELL11_MSK                   (0x04u)
#define BQ7982X_BBVC_POSN2_CELL10_MSK                   (0x02u)
#define BQ7982X_BBVC_POSN2_CELL9_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * BBVC_POSN3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BBVC_POSN3_OFFSET                       (0x000Eu)
#define BQ7982X_BBVC_POSN3_POR_VAL                      (0x00u)

#define BQ7982X_BBVC_POSN3_CELL24_POS                   (0x07u)
#define BQ7982X_BBVC_POSN3_CELL23_POS                   (0x06u)
#define BQ7982X_BBVC_POSN3_CELL22_POS                   (0x05u)
#define BQ7982X_BBVC_POSN3_CELL21_POS                   (0x04u)
#define BQ7982X_BBVC_POSN3_CELL20_POS                   (0x03u)
#define BQ7982X_BBVC_POSN3_CELL19_POS                   (0x02u)
#define BQ7982X_BBVC_POSN3_CELL18_POS                   (0x01u)
#define BQ7982X_BBVC_POSN3_CELL17_POS                   (0x00u)

#define BQ7982X_BBVC_POSN3_CELL24_MSK                   (0x80u)
#define BQ7982X_BBVC_POSN3_CELL23_MSK                   (0x40u)
#define BQ7982X_BBVC_POSN3_CELL22_MSK                   (0x20u)
#define BQ7982X_BBVC_POSN3_CELL21_MSK                   (0x10u)
#define BQ7982X_BBVC_POSN3_CELL20_MSK                   (0x08u)
#define BQ7982X_BBVC_POSN3_CELL19_MSK                   (0x04u)
#define BQ7982X_BBVC_POSN3_CELL18_MSK                   (0x02u)
#define BQ7982X_BBVC_POSN3_CELL17_MSK                   (0x01u)
/* --------------------------------------------------------------------------
 * BBVC_POSN4          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BBVC_POSN4_OFFSET                       (0x000Fu)
#define BQ7982X_BBVC_POSN4_POR_VAL                      (0x00u)

#define BQ7982X_BBVC_POSN4_SPARE5_POS                   (0x07u)
#define BQ7982X_BBVC_POSN4_SPARE4_POS                   (0x06u)
#define BQ7982X_BBVC_POSN4_SPARE3_POS                   (0x05u)
#define BQ7982X_BBVC_POSN4_SPARE2_POS                   (0x04u)
#define BQ7982X_BBVC_POSN4_SPARE1_POS                   (0x03u)
#define BQ7982X_BBVC_POSN4_SPARE0_POS                   (0x02u)
#define BQ7982X_BBVC_POSN4_CELL26_POS                   (0x01u)
#define BQ7982X_BBVC_POSN4_CELL25_POS                   (0x00u)

#define BQ7982X_BBVC_POSN4_SPARE5_MSK                   (0x80u)
#define BQ7982X_BBVC_POSN4_SPARE4_MSK                   (0x40u)
#define BQ7982X_BBVC_POSN4_SPARE3_MSK                   (0x20u)
#define BQ7982X_BBVC_POSN4_SPARE2_MSK                   (0x10u)
#define BQ7982X_BBVC_POSN4_SPARE1_MSK                   (0x08u)
#define BQ7982X_BBVC_POSN4_SPARE0_MSK                   (0x04u)
#define BQ7982X_BBVC_POSN4_CELL26_MSK                   (0x02u)
#define BQ7982X_BBVC_POSN4_CELL25_MSK                   (0x01u)

/* --------------------------------------------------------------------------
 * OV_THRESH1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OV_THRESH1_OFFSET                       (0x0010u)
#define BQ7982X_OV_THRESH1_POR_VAL                      (0x00u)

#define BQ7982X_OV_THRESH1_OV_THR7_POS                  (0x07u)
#define BQ7982X_OV_THRESH1_OV_THR6_POS                  (0x06u)
#define BQ7982X_OV_THRESH1_OV_THR5_POS                  (0x05u)
#define BQ7982X_OV_THRESH1_OV_THR4_POS                  (0x04u)
#define BQ7982X_OV_THRESH1_OV_THR3_POS                  (0x03u)
#define BQ7982X_OV_THRESH1_OV_THR2_POS                  (0x02u)
#define BQ7982X_OV_THRESH1_OV_THR1_POS                  (0x01u)
#define BQ7982X_OV_THRESH1_OV_THR0_POS                  (0x00u)

#define BQ7982X_OV_THRESH1_OV_THR7_MSK                  (0x80u)
#define BQ7982X_OV_THRESH1_OV_THR6_MSK                  (0x40u)
#define BQ7982X_OV_THRESH1_OV_THR5_MSK                  (0x20u)
#define BQ7982X_OV_THRESH1_OV_THR4_MSK                  (0x10u)
#define BQ7982X_OV_THRESH1_OV_THR3_MSK                  (0x08u)
#define BQ7982X_OV_THRESH1_OV_THR2_MSK                  (0x04u)
#define BQ7982X_OV_THRESH1_OV_THR1_MSK                  (0x02u)
#define BQ7982X_OV_THRESH1_OV_THR0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * UV_THRESH1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_UV_THRESH1_OFFSET                       (0x0011u)
#define BQ7982X_UV_THRESH1_POR_VAL                      (0x00u)

#define BQ7982X_UV_THRESH1_SPARE1_POS                   (0x07u)
#define BQ7982X_UV_THRESH1_SPARE0_POS                   (0x06u)
#define BQ7982X_UV_THRESH1_UV_THR5_POS                  (0x05u)
#define BQ7982X_UV_THRESH1_UV_THR4_POS                  (0x04u)
#define BQ7982X_UV_THRESH1_UV_THR3_POS                  (0x03u)
#define BQ7982X_UV_THRESH1_UV_THR2_POS                  (0x02u)
#define BQ7982X_UV_THRESH1_UV_THR1_POS                  (0x01u)
#define BQ7982X_UV_THRESH1_UV_THR0_POS                  (0x00u)

#define BQ7982X_UV_THRESH1_SPARE1_MSK                   (0x80u)
#define BQ7982X_UV_THRESH1_SPARE0_MSK                   (0x40u)
#define BQ7982X_UV_THRESH1_UV_THR5_MSK                  (0x20u)
#define BQ7982X_UV_THRESH1_UV_THR4_MSK                  (0x10u)
#define BQ7982X_UV_THRESH1_UV_THR3_MSK                  (0x08u)
#define BQ7982X_UV_THRESH1_UV_THR2_MSK                  (0x04u)
#define BQ7982X_UV_THRESH1_UV_THR1_MSK                  (0x02u)
#define BQ7982X_UV_THRESH1_UV_THR0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * OV_THRESH2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OV_THRESH2_OFFSET                       (0x0012u)
#define BQ7982X_OV_THRESH2_POR_VAL                      (0x00u)

#define BQ7982X_OV_THRESH2_OV_THR7_POS                  (0x07u)
#define BQ7982X_OV_THRESH2_OV_THR6_POS                  (0x06u)
#define BQ7982X_OV_THRESH2_OV_THR5_POS                  (0x05u)
#define BQ7982X_OV_THRESH2_OV_THR4_POS                  (0x04u)
#define BQ7982X_OV_THRESH2_OV_THR3_POS                  (0x03u)
#define BQ7982X_OV_THRESH2_OV_THR2_POS                  (0x02u)
#define BQ7982X_OV_THRESH2_OV_THR1_POS                  (0x01u)
#define BQ7982X_OV_THRESH2_OV_THR0_POS                  (0x00u)

#define BQ7982X_OV_THRESH2_OV_THR7_MSK                  (0x80u)
#define BQ7982X_OV_THRESH2_OV_THR6_MSK                  (0x40u)
#define BQ7982X_OV_THRESH2_OV_THR5_MSK                  (0x20u)
#define BQ7982X_OV_THRESH2_OV_THR4_MSK                  (0x10u)
#define BQ7982X_OV_THRESH2_OV_THR3_MSK                  (0x08u)
#define BQ7982X_OV_THRESH2_OV_THR2_MSK                  (0x04u)
#define BQ7982X_OV_THRESH2_OV_THR1_MSK                  (0x02u)
#define BQ7982X_OV_THRESH2_OV_THR0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * UV_THRESH2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_UV_THRESH2_OFFSET                       (0x0013u)
#define BQ7982X_UV_THRESH2_POR_VAL                      (0x00u)
#define BQ7982X_UV_THRESH2_SPARE1_POS                   (0x07u)
#define BQ7982X_UV_THRESH2_SPARE0_POS                   (0x06u)
#define BQ7982X_UV_THRESH2_UV_THR_POS                   (0x00u)
#define BQ7982X_UV_THRESH2_SPARE1_MSK                   (0x80u)
#define BQ7982X_UV_THRESH2_SPARE0_MSK                   (0x40u)
#define BQ7982X_UV_THRESH2_UV_THR_MSK                   (0x3Fu)

/* --------------------------------------------------------------------------
 * OTUT_THRESH1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTUT_THRESH1_OFFSET                       (0x0014u)
#define BQ7982X_OTUT_THRESH1_POR_VAL                      (0x00u)

#define BQ7982X_OTUT_THRESH1_UT_THR_POS                   (0x05u)
#define BQ7982X_OTUT_THRESH1_OT_THR_POS                   (0x00u)

#define BQ7982X_OTUT_THRESH1_UT_THR_MSK                   (0xE0u)
#define BQ7982X_OTUT_THRESH1_OT_THR_MSK                  (0x1Fu)

/* --------------------------------------------------------------------------
 * OTUT_THRESH2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTUT_THRESH2_OFFSET                       (0x0015u)
#define BQ7982X_OTUT_THRESH2_POR_VAL                      (0x00u)

#define BQ7982X_OTUT_THRESH2_UT_THR2_POS                  (0x07u)
#define BQ7982X_OTUT_THRESH2_UT_THR1_POS                  (0x06u)
#define BQ7982X_OTUT_THRESH2_UT_THR0_POS                  (0x05u)
#define BQ7982X_OTUT_THRESH2_OT_THR4_POS                  (0x04u)
#define BQ7982X_OTUT_THRESH2_OT_THR3_POS                  (0x03u)
#define BQ7982X_OTUT_THRESH2_OT_THR2_POS                  (0x02u)
#define BQ7982X_OTUT_THRESH2_OT_THR1_POS                  (0x01u)
#define BQ7982X_OTUT_THRESH2_OT_THR0_POS                  (0x00u)

#define BQ7982X_OTUT_THRESH2_UT_THR2_MSK                  (0x80u)
#define BQ7982X_OTUT_THRESH2_UT_THR1_MSK                  (0x40u)
#define BQ7982X_OTUT_THRESH2_UT_THR0_MSK                  (0x20u)
#define BQ7982X_OTUT_THRESH2_OT_THR4_MSK                  (0x10u)
#define BQ7982X_OTUT_THRESH2_OT_THR3_MSK                  (0x08u)
#define BQ7982X_OTUT_THRESH2_OT_THR2_MSK                  (0x04u)
#define BQ7982X_OTUT_THRESH2_OT_THR1_MSK                  (0x02u)
#define BQ7982X_OTUT_THRESH2_OT_THR0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * SMONH_THRESH          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMONH_THRESH_OFFSET                       (0x0016u)
#define BQ7982X_SMONH_THRESH_POR_VAL                      (0x00u)
#define BQ7982X_POS_SMONH_THRESH_SMONH_THR               (0x00u)
#define BQ7982X_MSK_SMONH_THRESH_SMONH_THR             (0xFFu)

/* --------------------------------------------------------------------------
 * SMONL_THRESH          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMONL_THRESH_OFFSET                       (0x0017u)
#define BQ7982X_SMONL_THRESH_POR_VAL                      (0x00u)
#define BQ7982X_POS_SMONL_THRESH_SMONL_THR               (0x00u)
#define BQ7982X_MSK_SMONL_THRESH_SMONL_THR             (0xFFu)


/* --------------------------------------------------------------------------
 * FAULT_MSK1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_MSK1_OFFSET                       (0x0018u)
#define BQ7982X_FAULT_MSK1_POR_VAL                      (0x00u)

#define BQ7982X_POS_FAULT_MSK1_MSK_SYS_SYNC             (0x07u)
#define BQ7982X_POS_FAULT_MSK1_MSK_SYS_INT              (0x06u)
#define BQ7982X_POS_FAULT_MSK1_MSK_SYS_MON              (0x05u)
#define BQ7982X_POS_FAULT_MSK1_MSK_SYS_SMON             (0x04u)
#define BQ7982X_FAULT_MSK1_MSK_UT_POS                   (0x03u)
#define BQ7982X_FAULT_MSK1_MSK_OT_POS                   (0x02u)
#define BQ7982X_FAULT_MSK1_MSK_UV_POS                   (0x01u)
#define BQ7982X_FAULT_MSK1_MSK_OV_POS                   (0x00u)

#define BQ7982X_MSK_FAULT_MSK1_MSK_SYS_SYNC             (0x80u)
#define BQ7982X_MSK_FAULT_MSK1_MSK_SYS_INT              (0x40u)
#define BQ7982X_MSK_FAULT_MSK1_MSK_SYS_MON              (0x20u)
#define BQ7982X_MSK_FAULT_MSK1_MSK_SYS_SMON             (0x10u)
#define BQ7982X_FAULT_MSK1_MSK_UT_MSK                   (0x08u)
#define BQ7982X_FAULT_MSK1_MSK_OT_MSK                   (0x04u)
#define BQ7982X_FAULT_MSK1_MSK_UV_MSK                   (0x02u)
#define BQ7982X_FAULT_MSK1_MSK_OV_MSK                   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_MSK2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_MSK2_OFFSET                       (0x0019u)
#define BQ7982X_FAULT_MSK2_POR_VAL                      (0x00u)

#define BQ7982X_FAULT_MSK2_MSK_PWR_POS                  (0x07u)
#define BQ7982X_POS_FAULT_MSK2_MSK_COMM_FRAME          (0x06u)
#define BQ7982X_POS_FAULT_MSK2_MSK_COMM_FT             (0x05u)
#define BQ7982X_POS_FAULT_MSK2_MSK_COMM_HB             (0x04u)
#define BQ7982X_POS_FAULT_MSK2_MSK_COMM_DSY            (0x03u)
#define BQ7982X_POS_FAULT_MSK2_MSK_COMM_PSPI           (0x02u)
#define BQ7982X_POS_FAULT_MSK2_MSK_COMM_BUSY           (0x01u)
#define BQ7982X_POS_FAULT_MSK2_MSK_SYS_MISC            (0x00u)

#define BQ7982X_FAULT_MSK2_MSK_PWR_MSK                  (0x80u)
#define BQ7982X_MSK_FAULT_MSK2_MSK_COMM_FRAME          (0x40u)
#define BQ7982X_MSK_FAULT_MSK2_MSK_COMM_FT             (0x20u)
#define BQ7982X_MSK_FAULT_MSK2_MSK_COMM_HB             (0x10u)
#define BQ7982X_MSK_FAULT_MSK2_MSK_COMM_DSY            (0x08u)
#define BQ7982X_MSK_FAULT_MSK2_MSK_COMM_PSPI           (0x04u)
#define BQ7982X_MSK_FAULT_MSK2_MSK_COMM_BUSY           (0x02u)
#define BQ7982X_MSK_FAULT_MSK2_MSK_SYS_MISC            (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_MSK3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_MSK3_OFFSET                       (0x001Au)
#define BQ7982X_FAULT_MSK3_POR_VAL                      (0x00u)

#define BQ7982X_FAULT_MSK3_SPARE2_POS                   (0x07u)
#define BQ7982X_FAULT_MSK3_SPARE1_POS                   (0x06u)
#define BQ7982X_FAULT_MSK3_SPARE0_POS                   (0x05u)
#define BQ7982X_POS_FAULT_MSK3_MSK_SYS_EIS              (0x04u)
#define BQ7982X_FAULT_MSK3_MSK_CB_POS                   (0x03u)
#define BQ7982X_FAULT_MSK3_MSK_ADC_POS                  (0x02u)
#define BQ7982X_POS_FAULT_MSK3_MSK_MEM_CRC              (0x01u)
#define BQ7982X_POS_FAULT_MSK3_MSK_MEM_DATA             (0x00u)

#define BQ7982X_FAULT_MSK3_SPARE2_MSK                   (0x80u)
#define BQ7982X_FAULT_MSK3_SPARE1_MSK                   (0x40u)
#define BQ7982X_FAULT_MSK3_SPARE0_MSK                   (0x20u)
#define BQ7982X_MSK_FAULT_MSK3_MSK_SYS_EIS              (0x10u)
#define BQ7982X_FAULT_MSK3_MSK_CB_MSK                   (0x08u)
#define BQ7982X_FAULT_MSK3_MSK_ADC_MSK                  (0x04u)
#define BQ7982X_MSK_FAULT_MSK3_MSK_MEM_CRC              (0x02u)
#define BQ7982X_MSK_FAULT_MSK3_MSK_MEM_DATA             (0x01u)

/* --------------------------------------------------------------------------
 * IDDQ_CONF          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_IDDQ_CONF_OFFSET                        (0x001Cu)
#define BQ7982X_IDDQ_CONF_POR_VAL                       (0x00u)

#define BQ7982X_IDDQ_CONF_SPARE1_POS                    (0x07u)
#define BQ7982X_IDDQ_CONF_SPARE0_POS                    (0x06u)
#define BQ7982X_IDDQ_CONF_STATIC5_POS                   (0x05u)
#define BQ7982X_IDDQ_CONF_STATIC4_POS                   (0x04u)
#define BQ7982X_IDDQ_CONF_STATIC3_POS                   (0x03u)
#define BQ7982X_IDDQ_CONF_STATIC2_POS                   (0x02u)
#define BQ7982X_IDDQ_CONF_STATIC1_POS                   (0x01u)
#define BQ7982X_IDDQ_CONF_STATIC0_POS                   (0x00u)

#define BQ7982X_IDDQ_CONF_SPARE1_MSK                    (0x80u)
#define BQ7982X_IDDQ_CONF_SPARE0_MSK                    (0x40u)
#define BQ7982X_IDDQ_CONF_STATIC5_MSK                   (0x20u)
#define BQ7982X_IDDQ_CONF_STATIC4_MSK                   (0x10u)
#define BQ7982X_IDDQ_CONF_STATIC3_MSK                   (0x08u)
#define BQ7982X_IDDQ_CONF_STATIC2_MSK                   (0x04u)
#define BQ7982X_IDDQ_CONF_STATIC1_MSK                   (0x02u)
#define BQ7982X_IDDQ_CONF_STATIC0_MSK                   (0x01u)

/* --------------------------------------------------------------------------
 * CSPI_CONF          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_CONF_OFFSET                        (0x001Du)
#define BQ7982X_CSPI_CONF_POR_VAL                       (0x00u)

#define BQ7982X_CSPI_CONF_CCS8_POS                      (0x07u)
#define BQ7982X_CSPI_CONF_CCS7_POS                      (0x06u)
#define BQ7982X_CSPI_CONF_CCS6_POS                      (0x05u)
#define BQ7982X_CSPI_CONF_CCS5_POS                      (0x04u)
#define BQ7982X_CSPI_CONF_CCS4_POS                      (0x03u)
#define BQ7982X_CSPI_CONF_CCS3_POS                      (0x02u)
#define BQ7982X_CSPI_CONF_CCS2_POS                      (0x01u)
#define BQ7982X_CSPI_CONF_CCS1_POS                      (0x00u)

#define BQ7982X_CSPI_CONF_CCS8_MSK                      (0x80u)
#define BQ7982X_CSPI_CONF_CCS7_MSK                      (0x40u)
#define BQ7982X_CSPI_CONF_CCS6_MSK                      (0x20u)
#define BQ7982X_CSPI_CONF_CCS5_MSK                      (0x10u)
#define BQ7982X_CSPI_CONF_CCS4_MSK                      (0x08u)
#define BQ7982X_CSPI_CONF_CCS3_MSK                      (0x04u)
#define BQ7982X_CSPI_CONF_CCS2_MSK                      (0x02u)
#define BQ7982X_CSPI_CONF_CCS1_MSK                      (0x01u)

/* --------------------------------------------------------------------------
 * INT_CONF          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_INT_CONF_OFFSET                         (0x001Eu)
#define BQ7982X_INT_CONF_POR_VAL                        (0x00u)

#define BQ7982X_INT_CONF_SPARE2_POS                     (0x07u)
#define BQ7982X_INT_CONF_SPARE1_POS                     (0x06u)
#define BQ7982X_INT_CONF_SPARE0_POS                     (0x05u)
#define BQ7982X_INT_CONF_INT5_POS                       (0x04u)
#define BQ7982X_INT_CONF_INT4_POS                       (0x03u)
#define BQ7982X_INT_CONF_INT3_POS                       (0x02u)
#define BQ7982X_INT_CONF_INT2_POS                       (0x01u)
#define BQ7982X_INT_CONF_INT1_POS                       (0x00u)

#define BQ7982X_INT_CONF_SPARE2_MSK                     (0x80u)
#define BQ7982X_INT_CONF_SPARE1_MSK                     (0x40u)
#define BQ7982X_INT_CONF_SPARE0_MSK                     (0x20u)
#define BQ7982X_INT_CONF_INT5_MSK                       (0x10u)
#define BQ7982X_INT_CONF_INT4_MSK                       (0x08u)
#define BQ7982X_INT_CONF_INT3_MSK                       (0x04u)
#define BQ7982X_INT_CONF_INT2_MSK                       (0x02u)
#define BQ7982X_INT_CONF_INT1_MSK                       (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF1_OFFSET                       (0x001Fu)
#define BQ7982X_GPIO_CONF1_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF1_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF1_SPARE0_POS                   (0x06u)
#define BQ7982X_GPIO_CONF1_GPIO2_2_POS                  (0x05u)
#define BQ7982X_GPIO_CONF1_GPIO2_1_POS                  (0x04u)
#define BQ7982X_GPIO_CONF1_GPIO2_0_POS                  (0x03u)
#define BQ7982X_GPIO_CONF1_GPIO1_2_POS                  (0x02u)
#define BQ7982X_GPIO_CONF1_GPIO1_1_POS                  (0x01u)
#define BQ7982X_GPIO_CONF1_GPIO1_0_POS                  (0x00u)

#define BQ7982X_GPIO_CONF1_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF1_SPARE0_MSK                   (0x40u)
#define BQ7982X_GPIO_CONF1_GPIO2_2_MSK                  (0x20u)
#define BQ7982X_GPIO_CONF1_GPIO2_1_MSK                  (0x10u)
#define BQ7982X_GPIO_CONF1_GPIO2_0_MSK                  (0x08u)
#define BQ7982X_GPIO_CONF1_GPIO1_2_MSK                  (0x04u)
#define BQ7982X_GPIO_CONF1_GPIO1_1_MSK                  (0x02u)
#define BQ7982X_GPIO_CONF1_GPIO1_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF2_OFFSET                       (0x0020u)
#define BQ7982X_GPIO_CONF2_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF2_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF2_SPARE0_POS                   (0x06u)
#define BQ7982X_GPIO_CONF2_GPIO4_2_POS                  (0x05u)
#define BQ7982X_GPIO_CONF2_GPIO4_1_POS                  (0x04u)
#define BQ7982X_GPIO_CONF2_GPIO4_0_POS                  (0x03u)
#define BQ7982X_GPIO_CONF2_GPIO3_2_POS                  (0x02u)
#define BQ7982X_GPIO_CONF2_GPIO3_1_POS                  (0x01u)
#define BQ7982X_GPIO_CONF2_GPIO3_0_POS                  (0x00u)

#define BQ7982X_GPIO_CONF2_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF2_SPARE0_MSK                   (0x40u)
#define BQ7982X_GPIO_CONF2_GPIO4_2_MSK                  (0x20u)
#define BQ7982X_GPIO_CONF2_GPIO4_1_MSK                  (0x10u)
#define BQ7982X_GPIO_CONF2_GPIO4_0_MSK                  (0x08u)
#define BQ7982X_GPIO_CONF2_GPIO3_2_MSK                  (0x04u)
#define BQ7982X_GPIO_CONF2_GPIO3_1_MSK                  (0x02u)
#define BQ7982X_GPIO_CONF2_GPIO3_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF3_OFFSET                       (0x0021u)
#define BQ7982X_GPIO_CONF3_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF3_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF3_SPARE0_POS                   (0x06u)
#define BQ7982X_GPIO_CONF3_GPIO6_2_POS                  (0x05u)
#define BQ7982X_GPIO_CONF3_GPIO6_1_POS                  (0x04u)
#define BQ7982X_GPIO_CONF3_GPIO6_0_POS                  (0x03u)
#define BQ7982X_GPIO_CONF3_GPIO5_2_POS                  (0x02u)
#define BQ7982X_GPIO_CONF3_GPIO5_1_POS                  (0x01u)
#define BQ7982X_GPIO_CONF3_GPIO5_0_POS                  (0x00u)

#define BQ7982X_GPIO_CONF3_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF3_SPARE0_MSK                   (0x40u)
#define BQ7982X_GPIO_CONF3_GPIO6_2_MSK                  (0x20u)
#define BQ7982X_GPIO_CONF3_GPIO6_1_MSK                  (0x10u)
#define BQ7982X_GPIO_CONF3_GPIO6_0_MSK                  (0x08u)
#define BQ7982X_GPIO_CONF3_GPIO5_2_MSK                  (0x04u)
#define BQ7982X_GPIO_CONF3_GPIO5_1_MSK                  (0x02u)
#define BQ7982X_GPIO_CONF3_GPIO5_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF4          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF4_OFFSET                       (0x0022u)
#define BQ7982X_GPIO_CONF4_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF4_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF4_EIS_PWM_EN_POS               (0x06u)
#define BQ7982X_GPIO_CONF4_GPIO8_2_POS                  (0x05u)
#define BQ7982X_GPIO_CONF4_GPIO8_1_POS                  (0x04u)
#define BQ7982X_GPIO_CONF4_GPIO8_0_POS                  (0x03u)
#define BQ7982X_GPIO_CONF4_GPIO7_2_POS                  (0x02u)
#define BQ7982X_GPIO_CONF4_GPIO7_1_POS                  (0x01u)
#define BQ7982X_GPIO_CONF4_GPIO7_0_POS                  (0x00u)

#define BQ7982X_GPIO_CONF4_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF4_EIS_PWM_EN_MSK               (0x40u)
#define BQ7982X_GPIO_CONF4_GPIO8_2_MSK                  (0x20u)
#define BQ7982X_GPIO_CONF4_GPIO8_1_MSK                  (0x10u)
#define BQ7982X_GPIO_CONF4_GPIO8_0_MSK                  (0x08u)
#define BQ7982X_GPIO_CONF4_GPIO7_2_MSK                  (0x04u)
#define BQ7982X_GPIO_CONF4_GPIO7_1_MSK                  (0x02u)
#define BQ7982X_GPIO_CONF4_GPIO7_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF5          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF5_OFFSET                       (0x0023u)
#define BQ7982X_GPIO_CONF5_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF5_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF5_I2C_EN_POS                   (0x06u)
#define BQ7982X_GPIO_CONF5_GPIO10_2_POS                 (0x05u)
#define BQ7982X_GPIO_CONF5_GPIO10_1_POS                 (0x04u)
#define BQ7982X_GPIO_CONF5_GPIO10_0_POS                 (0x03u)
#define BQ7982X_GPIO_CONF5_GPIO9_2_POS                  (0x02u)
#define BQ7982X_GPIO_CONF5_GPIO9_1_POS                  (0x01u)
#define BQ7982X_GPIO_CONF5_GPIO9_0_POS                  (0x00u)

#define BQ7982X_GPIO_CONF5_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF5_I2C_EN_MSK                   (0x40u)
#define BQ7982X_GPIO_CONF5_GPIO10_2_MSK                 (0x20u)
#define BQ7982X_GPIO_CONF5_GPIO10_1_MSK                 (0x10u)
#define BQ7982X_GPIO_CONF5_GPIO10_0_MSK                 (0x08u)
#define BQ7982X_GPIO_CONF5_GPIO9_2_MSK                  (0x04u)
#define BQ7982X_GPIO_CONF5_GPIO9_1_MSK                  (0x02u)
#define BQ7982X_GPIO_CONF5_GPIO9_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF6          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF6_OFFSET                       (0x0024u)
#define BQ7982X_GPIO_CONF6_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF6_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF6_SPARE0_POS                   (0x06u)
#define BQ7982X_GPIO_CONF6_GPIO12_2_POS                 (0x05u)
#define BQ7982X_GPIO_CONF6_GPIO12_1_POS                 (0x04u)
#define BQ7982X_GPIO_CONF6_GPIO12_0_POS                 (0x03u)
#define BQ7982X_GPIO_CONF6_GPIO11_2_POS                 (0x02u)
#define BQ7982X_GPIO_CONF6_GPIO11_1_POS                 (0x01u)
#define BQ7982X_GPIO_CONF6_GPIO11_0_POS                 (0x00u)

#define BQ7982X_GPIO_CONF6_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF6_SPARE0_MSK                   (0x40u)
#define BQ7982X_GPIO_CONF6_GPIO12_2_MSK                 (0x20u)
#define BQ7982X_GPIO_CONF6_GPIO12_1_MSK                 (0x10u)
#define BQ7982X_GPIO_CONF6_GPIO12_0_MSK                 (0x08u)
#define BQ7982X_GPIO_CONF6_GPIO11_2_MSK                 (0x04u)
#define BQ7982X_GPIO_CONF6_GPIO11_1_MSK                 (0x02u)
#define BQ7982X_GPIO_CONF6_GPIO11_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF7          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF7_OFFSET                       (0x0025u)
#define BQ7982X_GPIO_CONF7_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF7_SPARE0_POS                   (0x07u)
#define BQ7982X_GPIO_CONF7_CSPI_EN_POS                  (0x06u)
#define BQ7982X_GPIO_CONF7_GPIO14_2_POS                 (0x05u)
#define BQ7982X_GPIO_CONF7_GPIO14_1_POS                 (0x04u)
#define BQ7982X_GPIO_CONF7_GPIO14_0_POS                 (0x03u)
#define BQ7982X_GPIO_CONF7_GPIO13_2_POS                 (0x02u)
#define BQ7982X_GPIO_CONF7_GPIO13_1_POS                 (0x01u)
#define BQ7982X_GPIO_CONF7_GPIO13_0_POS                 (0x00u)

#define BQ7982X_GPIO_CONF7_SPARE0_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF7_CSPI_EN_MSK                  (0x40u)
#define BQ7982X_GPIO_CONF7_GPIO14_2_MSK                 (0x20u)
#define BQ7982X_GPIO_CONF7_GPIO14_1_MSK                 (0x10u)
#define BQ7982X_GPIO_CONF7_GPIO14_0_MSK                 (0x08u)
#define BQ7982X_GPIO_CONF7_GPIO13_2_MSK                 (0x04u)
#define BQ7982X_GPIO_CONF7_GPIO13_1_MSK                 (0x02u)
#define BQ7982X_GPIO_CONF7_GPIO13_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF8          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF8_OFFSET                       (0x0026u)
#define BQ7982X_GPIO_CONF8_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF8_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF8_SPARE0_POS                   (0x06u)
#define BQ7982X_GPIO_CONF8_GPIO16_2_POS                 (0x05u)
#define BQ7982X_GPIO_CONF8_GPIO16_1_POS                 (0x04u)
#define BQ7982X_GPIO_CONF8_GPIO16_0_POS                 (0x03u)
#define BQ7982X_GPIO_CONF8_GPIO15_2_POS                 (0x02u)
#define BQ7982X_GPIO_CONF8_GPIO15_1_POS                 (0x01u)
#define BQ7982X_GPIO_CONF8_GPIO15_0_POS                 (0x00u)

#define BQ7982X_GPIO_CONF8_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF8_SPARE0_MSK                   (0x40u)
#define BQ7982X_GPIO_CONF8_GPIO16_2_MSK                 (0x20u)
#define BQ7982X_GPIO_CONF8_GPIO16_1_MSK                 (0x10u)
#define BQ7982X_GPIO_CONF8_GPIO16_0_MSK                 (0x08u)
#define BQ7982X_GPIO_CONF8_GPIO15_2_MSK                 (0x04u)
#define BQ7982X_GPIO_CONF8_GPIO15_1_MSK                 (0x02u)
#define BQ7982X_GPIO_CONF8_GPIO15_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF9          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF9_OFFSET                       (0x0027u)
#define BQ7982X_GPIO_CONF9_POR_VAL                      (0x00u)

#define BQ7982X_GPIO_CONF9_SPARE1_POS                   (0x07u)
#define BQ7982X_GPIO_CONF9_SPARE0_POS                   (0x06u)
#define BQ7982X_GPIO_CONF9_GPIO18_2_POS                 (0x05u)
#define BQ7982X_GPIO_CONF9_GPIO18_1_POS                 (0x04u)
#define BQ7982X_GPIO_CONF9_GPIO18_0_POS                 (0x03u)
#define BQ7982X_GPIO_CONF9_GPIO17_2_POS                 (0x02u)
#define BQ7982X_GPIO_CONF9_GPIO17_1_POS                 (0x01u)
#define BQ7982X_GPIO_CONF9_GPIO17_0_POS                 (0x00u)

#define BQ7982X_GPIO_CONF9_SPARE1_MSK                   (0x80u)
#define BQ7982X_GPIO_CONF9_SPARE0_MSK                   (0x40u)
#define BQ7982X_GPIO_CONF9_GPIO18_2_MSK                 (0x20u)
#define BQ7982X_GPIO_CONF9_GPIO18_1_MSK                 (0x10u)
#define BQ7982X_GPIO_CONF9_GPIO18_0_MSK                 (0x08u)
#define BQ7982X_GPIO_CONF9_GPIO17_2_MSK                 (0x04u)
#define BQ7982X_GPIO_CONF9_GPIO17_1_MSK                 (0x02u)
#define BQ7982X_GPIO_CONF9_GPIO17_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_CONF10          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_CONF10_OFFSET                      (0x0028u)
#define BQ7982X_GPIO_CONF10_POR_VAL                     (0x00u)

#define BQ7982X_GPIO_CONF10_SPARE1_POS                  (0x07u)
#define BQ7982X_GPIO_CONF10_SPARE0_POS                  (0x06u)
#define BQ7982X_GPIO_CONF10_GPIO20_2_POS                (0x05u)
#define BQ7982X_GPIO_CONF10_GPIO20_1_POS                (0x04u)
#define BQ7982X_GPIO_CONF10_GPIO20_0_POS                (0x03u)
#define BQ7982X_GPIO_CONF10_GPIO19_2_POS                (0x02u)
#define BQ7982X_GPIO_CONF10_GPIO19_1_POS                (0x01u)
#define BQ7982X_GPIO_CONF10_GPIO19_0_POS                (0x00u)

#define BQ7982X_GPIO_CONF10_SPARE1_MSK                  (0x80u)
#define BQ7982X_GPIO_CONF10_SPARE0_MSK                  (0x40u)
#define BQ7982X_GPIO_CONF10_GPIO20_2_MSK                (0x20u)
#define BQ7982X_GPIO_CONF10_GPIO20_1_MSK                (0x10u)
#define BQ7982X_GPIO_CONF10_GPIO20_0_MSK                (0x08u)
#define BQ7982X_GPIO_CONF10_GPIO19_2_MSK                (0x04u)
#define BQ7982X_GPIO_CONF10_GPIO19_1_MSK                (0x02u)
#define BQ7982X_GPIO_CONF10_GPIO19_0_MSK                (0x01u)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET1_OFFSET                    (0x002Bu)
#define BQ7982X_VCELL_OFFSET1_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET1_OFFSET2             (0x04u)
#define BQ7982X_POS_VCELL_OFFSET1_OFFSET1             (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET1_OFFSET2             (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET1_OFFSET1             (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET2_OFFSET                    (0x002Cu)
#define BQ7982X_VCELL_OFFSET2_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET2_OFFSET4             (0x04u)
#define BQ7982X_POS_VCELL_OFFSET2_OFFSET3             (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET2_OFFSET4             (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET2_OFFSET3             (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET3_OFFSET                    (0x002Du)
#define BQ7982X_VCELL_OFFSET3_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET3_OFFSET6             (0x04u)
#define BQ7982X_POS_VCELL_OFFSET3_OFFSET5             (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET3_OFFSET6             (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET3_OFFSET5             (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET4          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET4_OFFSET                    (0x002Eu)
#define BQ7982X_VCELL_OFFSET4_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET4_OFFSET8             (0x04u)
#define BQ7982X_POS_VCELL_OFFSET4_OFFSET7             (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET4_OFFSET8             (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET4_OFFSET7             (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET5          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET5_OFFSET                    (0x002Fu)
#define BQ7982X_VCELL_OFFSET5_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET5_OFFSET10            (0x04u)
#define BQ7982X_POS_VCELL_OFFSET5_OFFSET9             (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET5_OFFSET10            (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET5_OFFSET9             (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET6          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET6_OFFSET                    (0x0030u)
#define BQ7982X_VCELL_OFFSET6_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET6_OFFSET12            (0x04u)
#define BQ7982X_POS_VCELL_OFFSET6_OFFSET11            (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET6_OFFSET12            (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET6_OFFSET11            (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET7          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET7_OFFSET                    (0x0031u)
#define BQ7982X_VCELL_OFFSET7_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET7_OFFSET14            (0x04u)
#define BQ7982X_POS_VCELL_OFFSET7_OFFSET13            (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET7_OFFSET14            (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET7_OFFSET13            (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET8          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET8_OFFSET                    (0x0032u)
#define BQ7982X_VCELL_OFFSET8_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET8_OFFSET16            (0x04u)
#define BQ7982X_POS_VCELL_OFFSET8_OFFSET15            (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET8_OFFSET16            (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET8_OFFSET15            (0x0Fu)

/* --------------------------------------------------------------------------
 * VCELL_OFFSET9          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_OFFSET9_OFFSET                    (0x0033u)
#define BQ7982X_VCELL_OFFSET9_POR_VAL                   (0x00u)

#define BQ7982X_POS_VCELL_OFFSET9_OFFSET18            (0x04u)
#define BQ7982X_POS_VCELL_OFFSET9_OFFSET17            (0x00u)

#define BQ7982X_MSK_VCELL_OFFSET9_OFFSET18            (0xF0u)
#define BQ7982X_MSK_VCELL_OFFSET9_OFFSET17            (0x0Fu)

/* --------------------------------------------------------------------------
 * CUST_MISC1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC1_OFFSET                       (0x0034u)
#define BQ7982X_CUST_MISC1_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC1_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC1_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC1_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC1_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC1_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC1_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC1_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC1_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC1_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC1_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC1_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC1_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC1_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC1_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC1_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC1_DATA_0_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * CUST_MISC2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC2_OFFSET                       (0x0035u)
#define BQ7982X_CUST_MISC2_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC2_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC2_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC2_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC2_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC2_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC2_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC2_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC2_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC2_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC2_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC2_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC2_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC2_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC2_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC2_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC2_DATA_0_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * CUST_MISC3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC3_OFFSET                       (0x0036u)
#define BQ7982X_CUST_MISC3_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC3_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC3_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC3_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC3_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC3_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC3_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC3_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC3_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC3_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC3_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC3_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC3_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC3_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC3_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC3_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC3_DATA_0_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * CUST_MISC4          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC4_OFFSET                       (0x0037u)
#define BQ7982X_CUST_MISC4_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC4_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC4_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC4_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC4_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC4_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC4_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC4_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC4_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC4_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC4_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC4_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC4_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC4_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC4_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC4_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC4_DATA_0_MSK                    (0x01u)
/* --------------------------------------------------------------------------
 * CUST_MISC5          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC5_OFFSET                       (0x0038u)
#define BQ7982X_CUST_MISC5_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC5_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC5_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC5_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC5_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC5_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC5_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC5_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC5_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC5_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC5_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC5_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC5_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC5_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC5_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC5_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC5_DATA_0_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * CUST_MISC6          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC6_OFFSET                       (0x0039u)
#define BQ7982X_CUST_MISC6_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC6_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC6_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC6_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC6_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC6_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC6_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC6_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC6_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC6_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC6_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC6_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC6_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC6_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC6_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC6_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC6_DATA_0_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * CUST_MISC7          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC7_OFFSET                       (0x003Au)
#define BQ7982X_CUST_MISC7_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC7_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC7_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC7_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC7_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC7_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC7_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC7_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC7_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC7_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC7_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC7_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC7_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC7_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC7_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC7_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC7_DATA_0_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * CUST_MISC8          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_MISC8_OFFSET                       (0x003Bu)
#define BQ7982X_CUST_MISC8_POR_VAL                      (0x00u)

#define BQ7982X_CUST_MISC8_DATA_7_POS                   (0x07u)
#define BQ7982X_CUST_MISC8_DATA_6_POS                   (0x06u)
#define BQ7982X_CUST_MISC8_DATA_5_POS                   (0x05u)
#define BQ7982X_CUST_MISC8_DATA_4_POS                   (0x04u)
#define BQ7982X_CUST_MISC8_DATA_3_POS                   (0x03u)
#define BQ7982X_CUST_MISC8_DATA_2_POS                   (0x02u)
#define BQ7982X_CUST_MISC8_DATA_1_POS                   (0x01u)
#define BQ7982X_CUST_MISC8_DATA_0_POS                   (0x00u)

#define BQ7982X_CUST_MISC8_DATA_7_MSK                    (0x80u)
#define BQ7982X_CUST_MISC8_DATA_6_MSK                    (0x40u)
#define BQ7982X_CUST_MISC8_DATA_5_MSK                    (0x20u)
#define BQ7982X_CUST_MISC8_DATA_4_MSK                    (0x10u)
#define BQ7982X_CUST_MISC8_DATA_3_MSK                    (0x08u)
#define BQ7982X_CUST_MISC8_DATA_2_MSK                    (0x04u)
#define BQ7982X_CUST_MISC8_DATA_1_MSK                    (0x02u)
#define BQ7982X_CUST_MISC8_DATA_0_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CONF1      (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CONF1_OFFSET                   (0x003Cu)
#define BQ7982X_DIG_SYNC_CONF1_POR_VAL                  (0x00u)

#define BQ7982X_POS_DIG_SYNC_CONF1_ADDRH              (0x00u)

#define BQ7982X_MSK_DIG_SYNC_CONF1_ADDRH              (0xFFu)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CONF2      (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CONF2_OFFSET                   (0x003Du)
#define BQ7982X_DIG_SYNC_CONF2_POR_VAL                  (0x00u)

#define BQ7982X_DIG_SYNC_CONF2_ADDRL_7_POS              (0x07u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRL_6_POS              (0x06u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRL_5_POS              (0x05u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRL_4_POS              (0x04u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRL_3_POS              (0x03u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRL_2_POS              (0x02u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRL_1_POS              (0x01u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRL_0_POS              (0x00u)

#define BQ7982X_DIG_SYNC_CONF2_ADDRH_7_MSK              (0x80u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRH_6_MSK              (0x40u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRH_5_MSK              (0x20u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRH_4_MSK              (0x10u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRH_3_MSK              (0x08u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRH_2_MSK              (0x04u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRH_1_MSK              (0x02u)
#define BQ7982X_DIG_SYNC_CONF2_ADDRH_0_MSK              (0x01u)

/* --------------------------------------------------------------------------
 * SMART_FREEZE_CONF   (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMART_FREEZE_CONF_OFFSET                (0x003Eu)
#define BQ7982X_SMART_FREEZE_CONF_POR_VAL               (0x00u)


#define BQ7982X_POS_SMART_FREEZE_CONF_SPARE           (0x05u)
#define BQ7982X_POS_SMART_FREEZE_CONF_SLOT_LEN        (0x03u)
#define BQ7982X_POS_SMART_FREEZE_CONF_SAMP_LEN        (0x00u)

#define BQ7982X_MSK_SMART_FREEZE_CONF_SPARE            (0xE0u)
#define BQ7982X_MSK_SMART_FREEZE_CONF_SLOT_LEN         (0x18u)
#define BQ7982X_MSK_SMART_FREEZE_CONF_SAMP_LEN         (0x07u)

/* --------------------------------------------------------------------------
 * ADC_CONF            (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_ADC_CONF_OFFSET                         (0x003Fu)
#define BQ7982X_ADC_CONF_POR_VAL                        (0x00u)

#define BQ7982X_ADC_CONF_ADC_DLY_7_POS                  (0x07u)
#define BQ7982X_ADC_CONF_ADC_DLY_6_POS                  (0x06u)
#define BQ7982X_ADC_CONF_ADC_DLY_5_POS                  (0x05u)
#define BQ7982X_ADC_CONF_ADC_DLY_4_POS                  (0x04u)
#define BQ7982X_ADC_CONF_ADC_DLY_3_POS                  (0x03u)
#define BQ7982X_ADC_CONF_ADC_DLY_2_POS                  (0x02u)
#define BQ7982X_ADC_CONF_ADC_DLY_1_POS                  (0x01u)
#define BQ7982X_ADC_CONF_ADC_DLY_0_POS                  (0x00u)

#define BQ7982X_ADC_CONF_ADC_DLY_7_MSK                   (0x80u)
#define BQ7982X_ADC_CONF_ADC_DLY_6_MSK                   (0x40u)
#define BQ7982X_ADC_CONF_ADC_DLY_5_MSK                   (0x20u)
#define BQ7982X_ADC_CONF_ADC_DLY_4_MSK                   (0x10u)
#define BQ7982X_ADC_CONF_ADC_DLY_3_MSK                   (0x08u)
#define BQ7982X_ADC_CONF_ADC_DLY_2_MSK                   (0x04u)
#define BQ7982X_ADC_CONF_ADC_DLY_1_MSK                   (0x02u)
#define BQ7982X_ADC_CONF_ADC_DLY_0_MSK                   (0x01u)

/* --------------------------------------------------------------------------
 * OTP_SPARE6          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_SPARE6_OFFSET                       (0x0040u)
#define BQ7982X_OTP_SPARE6_POR_VAL                      (0x00u)

#define BQ7982X_OTP_SPARE6_SPARE_7_POS                  (0x07u)
#define BQ7982X_OTP_SPARE6_SPARE_6_POS                  (0x06u)
#define BQ7982X_OTP_SPARE6_SPARE_5_POS                  (0x05u)
#define BQ7982X_OTP_SPARE6_SPARE_4_POS                  (0x04u)
#define BQ7982X_OTP_SPARE6_SPARE_3_POS                  (0x03u)
#define BQ7982X_OTP_SPARE6_SPARE_2_POS                  (0x02u)
#define BQ7982X_OTP_SPARE6_SPARE_1_POS                  (0x01u)
#define BQ7982X_OTP_SPARE6_SPARE_0_POS                  (0x00u)

#define BQ7982X_OTP_SPARE6_SPARE_7_MSK                  (0x80u)
#define BQ7982X_OTP_SPARE6_SPARE_6_MSK                  (0x40u)
#define BQ7982X_OTP_SPARE6_SPARE_5_MSK                  (0x20u)
#define BQ7982X_OTP_SPARE6_SPARE_4_MSK                  (0x10u)
#define BQ7982X_OTP_SPARE6_SPARE_3_MSK                  (0x08u)
#define BQ7982X_OTP_SPARE6_SPARE_2_MSK                  (0x04u)
#define BQ7982X_OTP_SPARE6_SPARE_1_MSK                  (0x02u)
#define BQ7982X_OTP_SPARE6_SPARE_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * OTP_SPARE5          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_SPARE5_OFFSET                       (0x0041u)
#define BQ7982X_OTP_SPARE5_POR_VAL                      (0x00u)

#define BQ7982X_OTP_SPARE5_SPARE_7_POS                  (0x07u)
#define BQ7982X_OTP_SPARE5_SPARE_6_POS                  (0x06u)
#define BQ7982X_OTP_SPARE5_SPARE_5_POS                  (0x05u)
#define BQ7982X_OTP_SPARE5_SPARE_4_POS                  (0x04u)
#define BQ7982X_OTP_SPARE5_SPARE_3_POS                  (0x03u)
#define BQ7982X_OTP_SPARE5_SPARE_2_POS                  (0x02u)
#define BQ7982X_OTP_SPARE5_SPARE_1_POS                  (0x01u)
#define BQ7982X_OTP_SPARE5_SPARE_0_POS                  (0x00u)

#define BQ7982X_OTP_SPARE5_SPARE_7_MSK                  (0x80u)
#define BQ7982X_OTP_SPARE5_SPARE_6_MSK                  (0x40u)
#define BQ7982X_OTP_SPARE5_SPARE_5_MSK                  (0x20u)
#define BQ7982X_OTP_SPARE5_SPARE_4_MSK                  (0x10u)
#define BQ7982X_OTP_SPARE5_SPARE_3_MSK                  (0x08u)
#define BQ7982X_OTP_SPARE5_SPARE_2_MSK                  (0x04u)
#define BQ7982X_OTP_SPARE5_SPARE_1_MSK                  (0x02u)
#define BQ7982X_OTP_SPARE5_SPARE_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * OTP_SPARE4          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_SPARE4_OFFSET                       (0x0042u)
#define BQ7982X_OTP_SPARE4_POR_VAL                      (0x00u)

#define BQ7982X_OTP_SPARE4_SPARE_7_POS                  (0x07u)
#define BQ7982X_OTP_SPARE4_SPARE_6_POS                  (0x06u)
#define BQ7982X_OTP_SPARE4_SPARE_5_POS                  (0x05u)
#define BQ7982X_OTP_SPARE4_SPARE_4_POS                  (0x04u)
#define BQ7982X_OTP_SPARE4_SPARE_3_POS                  (0x03u)
#define BQ7982X_OTP_SPARE4_SPARE_2_POS                  (0x02u)
#define BQ7982X_OTP_SPARE4_SPARE_1_POS                  (0x01u)
#define BQ7982X_OTP_SPARE4_SPARE_0_POS                  (0x00u)

#define BQ7982X_OTP_SPARE4_SPARE_7_MSK                  (0x80u)
#define BQ7982X_OTP_SPARE4_SPARE_6_MSK                  (0x40u)
#define BQ7982X_OTP_SPARE4_SPARE_5_MSK                  (0x20u)
#define BQ7982X_OTP_SPARE4_SPARE_4_MSK                  (0x10u)
#define BQ7982X_OTP_SPARE4_SPARE_3_MSK                  (0x08u)
#define BQ7982X_OTP_SPARE4_SPARE_2_MSK                  (0x04u)
#define BQ7982X_OTP_SPARE4_SPARE_1_MSK                  (0x02u)
#define BQ7982X_OTP_SPARE4_SPARE_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * OTP_SPARE3          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_SPARE3_OFFSET                       (0x0043u)
#define BQ7982X_OTP_SPARE3_POR_VAL                      (0x00u)

#define BQ7982X_OTP_SPARE3_SPARE_7_POS                  (0x07u)
#define BQ7982X_OTP_SPARE3_SPARE_6_POS                  (0x06u)
#define BQ7982X_OTP_SPARE3_SPARE_5_POS                  (0x05u)
#define BQ7982X_OTP_SPARE3_SPARE_4_POS                  (0x04u)
#define BQ7982X_OTP_SPARE3_SPARE_3_POS                  (0x03u)
#define BQ7982X_OTP_SPARE3_SPARE_2_POS                  (0x02u)
#define BQ7982X_OTP_SPARE3_SPARE_1_POS                  (0x01u)
#define BQ7982X_OTP_SPARE3_SPARE_0_POS                  (0x00u)

#define BQ7982X_OTP_SPARE3_SPARE_7_MSK                  (0x80u)
#define BQ7982X_OTP_SPARE3_SPARE_6_MSK                  (0x40u)
#define BQ7982X_OTP_SPARE3_SPARE_5_MSK                  (0x20u)
#define BQ7982X_OTP_SPARE3_SPARE_4_MSK                  (0x10u)
#define BQ7982X_OTP_SPARE3_SPARE_3_MSK                  (0x08u)
#define BQ7982X_OTP_SPARE3_SPARE_2_MSK                  (0x04u)
#define BQ7982X_OTP_SPARE3_SPARE_1_MSK                  (0x02u)
#define BQ7982X_OTP_SPARE3_SPARE_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * OTP_SPARE2          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_SPARE2_OFFSET                       (0x0044u)
#define BQ7982X_OTP_SPARE2_POR_VAL                      (0x00u)

#define BQ7982X_OTP_SPARE2_SPARE_7_POS                  (0x07u)
#define BQ7982X_OTP_SPARE2_SPARE_6_POS                  (0x06u)
#define BQ7982X_OTP_SPARE2_SPARE_5_POS                  (0x05u)
#define BQ7982X_OTP_SPARE2_SPARE_4_POS                  (0x04u)
#define BQ7982X_OTP_SPARE2_SPARE_3_POS                  (0x03u)
#define BQ7982X_OTP_SPARE2_SPARE_2_POS                  (0x02u)
#define BQ7982X_OTP_SPARE2_SPARE_1_POS                  (0x01u)
#define BQ7982X_OTP_SPARE2_SPARE_0_POS                  (0x00u)

#define BQ7982X_OTP_SPARE2_SPARE_7_MSK                  (0x80u)
#define BQ7982X_OTP_SPARE2_SPARE_6_MSK                  (0x40u)
#define BQ7982X_OTP_SPARE2_SPARE_5_MSK                  (0x20u)
#define BQ7982X_OTP_SPARE2_SPARE_4_MSK                  (0x10u)
#define BQ7982X_OTP_SPARE2_SPARE_3_MSK                  (0x08u)
#define BQ7982X_OTP_SPARE2_SPARE_2_MSK                  (0x04u)
#define BQ7982X_OTP_SPARE2_SPARE_1_MSK                  (0x02u)
#define BQ7982X_OTP_SPARE2_SPARE_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * OTP_SPARE1          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_SPARE1_OFFSET                       (0x0045u)
#define BQ7982X_OTP_SPARE1_POR_VAL                      (0x00u)

#define BQ7982X_OTP_SPARE1_SPARE_7_POS                  (0x07u)
#define BQ7982X_OTP_SPARE1_SPARE_6_POS                  (0x06u)
#define BQ7982X_OTP_SPARE1_SPARE_5_POS                  (0x05u)
#define BQ7982X_OTP_SPARE1_SPARE_4_POS                  (0x04u)
#define BQ7982X_OTP_SPARE1_SPARE_3_POS                  (0x03u)
#define BQ7982X_OTP_SPARE1_SPARE_2_POS                  (0x02u)
#define BQ7982X_OTP_SPARE1_SPARE_1_POS                  (0x01u)
#define BQ7982X_OTP_SPARE1_SPARE_0_POS                  (0x00u)

#define BQ7982X_OTP_SPARE1_SPARE_7_MSK                  (0x80u)
#define BQ7982X_OTP_SPARE1_SPARE_6_MSK                  (0x40u)
#define BQ7982X_OTP_SPARE1_SPARE_5_MSK                  (0x20u)
#define BQ7982X_OTP_SPARE1_SPARE_4_MSK                  (0x10u)
#define BQ7982X_OTP_SPARE1_SPARE_3_MSK                  (0x08u)
#define BQ7982X_OTP_SPARE1_SPARE_2_MSK                  (0x04u)
#define BQ7982X_OTP_SPARE1_SPARE_1_MSK                  (0x02u)
#define BQ7982X_OTP_SPARE1_SPARE_0_MSK                  (0x01u)

/* --------------------------------------------------------------------------
 * CS_ADC1_CAL1        (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CS_ADC1_CAL1_OFFSET                     (0x0046u)
#define BQ7982X_CS_ADC1_CAL1_POR_VAL                    (0x00u)

#define BQ7982X_CS_ADC1_CAL1_OFFSET_4_POS               (0x04u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_3_POS               (0x03u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_2_POS               (0x02u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_1_POS               (0x01u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_0_POS               (0x00u)
#define BQ7982X_CS_ADC1_CAL1_GAINH_2_POS                (0x05u)
#define BQ7982X_CS_ADC1_CAL1_GAINH_1_POS                (0x04u)
#define BQ7982X_CS_ADC1_CAL1_GAINH_0_POS                (0x03u)

#define BQ7982X_CS_ADC1_CAL1_OFFSET_4_MSK               (0x80u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_3_MSK               (0x40u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_2_MSK               (0x20u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_1_MSK               (0x10u)
#define BQ7982X_CS_ADC1_CAL1_OFFSET_0_MSK               (0x08u)
#define BQ7982X_CS_ADC1_CAL1_GAINH_2_MSK                (0x04u)
#define BQ7982X_CS_ADC1_CAL1_GAINH_1_MSK                (0x02u)
#define BQ7982X_CS_ADC1_CAL1_GAINH_0_MSK                (0x01u)

/* --------------------------------------------------------------------------
 * CS_ADC1_CAL2        (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CS_ADC1_CAL2_OFFSET                     (0x0047u)
#define BQ7982X_CS_ADC1_CAL2_POR_VAL                    (0x00u)

#define BQ7982X_CS_ADC1_CAL2_GAINL_7_POS                (0x07u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_6_POS                (0x06u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_5_POS                (0x05u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_4_POS                (0x04u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_3_POS                (0x03u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_2_POS                (0x02u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_1_POS                (0x01u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_0_POS                (0x00u)

#define BQ7982X_CS_ADC1_CAL2_GAINL_7_MSK                (0x80u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_6_MSK                (0x40u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_5_MSK                (0x20u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_4_MSK                (0x10u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_3_MSK                (0x08u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_2_MSK                (0x04u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_1_MSK                (0x02u)
#define BQ7982X_CS_ADC1_CAL2_GAINL_0_MSK                (0x01u)

/* --------------------------------------------------------------------------
 * OTP_PROG_UNLOCK1   (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_PROG_UNLOCK1_OFFSET                (0x0200u)
#define BQ7982X_OTP_PROG_UNLOCK1_POR_VAL               (0x00u)


#define BQ7982X_POS_OTP_PROG_UNLOCK1_CODE            (0x00u)

#define BQ7982X_MSK_OTP_PROG_UNLOCK1_CODE            (0xFFu)

/* --------------------------------------------------------------------------
 * CONTROL1           (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CONTROL1_OFFSET                        (0x0204u)
#define BQ7982X_CONTROL1_POR_VAL                       (0x00u)

#define BQ7982X_CONTROL1_DIR_SEL_POS                    (0x07u)
#define BQ7982X_POS_CONTROL1_SEND_SD_HW_RST             (0x06u)
#define BQ7982X_CONTROL1_SEND_WAKE_POS                  (0x05u)
#define BQ7982X_POS_CONTROL1_SEND_SLPTOACT              (0x04u)
#define BQ7982X_POS_CONTROL1_GOTO_SHUTDOWN              (0x03u)
#define BQ7982X_CONTROL1_GOTO_SLEEP_POS                 (0x02u)
#define BQ7982X_CONTROL1_SOFT_RESET_POS                 (0x01u)
#define BQ7982X_CONTROL1_MD_TONE_SEL_POS                (0x00u)

#define BQ7982X_CONTROL1_DIR_SEL_MSK                    (0x80u)
#define BQ7982X_MSK_CONTROL1_SEND_SD_HW_RST             (0x40u)
#define BQ7982X_CONTROL1_SEND_WAKE_MSK                  (0x20u)
#define BQ7982X_MSK_CONTROL1_SEND_SLPTOACT              (0x10u)
#define BQ7982X_MSK_CONTROL1_GOTO_SHUTDOWN              (0x08u)
#define BQ7982X_CONTROL1_GOTO_SLEEP_MSK                 (0x04u)
#define BQ7982X_CONTROL1_SOFT_RESET_MSK                 (0x02u)
#define BQ7982X_CONTROL1_MD_TONE_SEL_MSK                (0x01u)

/* --------------------------------------------------------------------------
 * CONTROL2           (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CONTROL2_OFFSET                        (0x0205u)
#define BQ7982X_CONTROL2_POR_VAL                       (0x01u)

#define BQ7982X_CONTROL2_ADDR_WR_POS                    (0x03u)
#define BQ7982X_POS_CONTROL2_SEND_HW_RST_BLAST          (0x02u)
#define BQ7982X_CONTROL2_PROG_GO_POS                    (0x01u)
#define BQ7982X_CONTROL2_TSREF_EN_POS                   (0x00u)

#define BQ7982X_CONTROL2_ADDR_WR_MSK                    (0x08u)
#define BQ7982X_MSK_CONTROL2_SEND_HW_RST_BLAST          (0x04u)
#define BQ7982X_CONTROL2_PROG_GO_MSK                    (0x02u)
#define BQ7982X_CONTROL2_TSREF_EN_MSK                   (0x01u)

/* --------------------------------------------------------------------------
 * COML_CTRL           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_COML_CTRL_OFFSET                         (0x0208u)
#define BQ7982X_COML_CTRL_POR_VAL                        (0x00u)

#define BQ7982X_COML_CTRL_TOP_STACK_POS                  (0x07u)
#define BQ7982X_COML_CTRL_ADDRESS_POS                    (0x00u)

#define BQ7982X_COML_CTRL_TOP_STACK_MSK                  (0x80u)
#define BQ7982X_COML_CTRL_ADDRESS_MSK                    (0x7Fu)

/* --------------------------------------------------------------------------
 * COMH_CTRL           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_COMH_CTRL_OFFSET                         (0x0209u)
#define BQ7982X_COMH_CTRL_POR_VAL                        (0x00u)

#define BQ7982X_COMH_CTRL_TOP_STACK_POS                  (0x07u)
#define BQ7982X_COMH_CTRL_ADDRESS_POS                    (0x00u)

#define BQ7982X_COMH_CTRL_TOP_STACK_MSK                  (0x80u)
#define BQ7982X_COMH_CTRL_ADDRESS_MSK                    (0x7Fu)

/* --------------------------------------------------------------------------
 * PROP_DLY_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_PROP_DLY_CTRL1_OFFSET                    (0x0222u)
#define BQ7982X_PROP_DLY_CTRL1_POR_VAL                   (0x00u)

#define BQ7982X_POS_PROP_DLY_CTRL1_PROP_DLY_TO           (0x04u)
#define BQ7982X_POS_PROP_DLY_CTRL1_PROP_DLY_DIR          (0x03u)
#define BQ7982X_POS_PROP_DLY_CTRL1_PROP_DLY_MODE         (0x00u)

#define BQ7982X_MSK_PROP_DLY_CTRL1_PROP_DLY_TO           (0x10u)
#define BQ7982X_MSK_PROP_DLY_CTRL1_PROP_DLY_DIR          (0x08u)
#define BQ7982X_MSK_PROP_DLY_CTRL1_PROP_DLY_MODE         (0x07u)

/* --------------------------------------------------------------------------
 * PROP_DLY_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_PROP_DLY_CTRL2_OFFSET                    (0x0223u)
#define BQ7982X_PROP_DLY_CTRL2_POR_VAL                   (0x00u)

#define BQ7982X_POS_PROP_DLY_CTRL2_PROP_DLY_GO           (0x00u)

#define BQ7982X_MSK_PROP_DLY_CTRL2_PROP_DLY_GO           (0x01u)

/* --------------------------------------------------------------------------
 * HFO_FREQ_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_HFO_FREQ_CTRL1_OFFSET                    (0x0226u)
#define BQ7982X_HFO_FREQ_CTRL1_POR_VAL                   (0x00u)

#define BQ7982X_POS_HFO_FREQ_CTRL1_FREQ_ADJ              (0x00u)

#define BQ7982X_MSK_HFO_FREQ_CTRL1_FREQ_ADJ              (0xFFu)

/* --------------------------------------------------------------------------
 * HFO_FREQ_CTRL2           (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_HFO_FREQ_CTRL2_OFFSET                    (0x0227u)
#define BQ7982X_HFO_FREQ_CTRL2_POR_VAL                   (0x00u)

#define BQ7982X_POS_HFO_FREQ_CTRL2_FREQ_GO               (0x00u)

#define BQ7982X_MSK_HFO_FREQ_CTRL2_FREQ_GO               (0x01u)

/* --------------------------------------------------------------------------
 * PLL_SYNC_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_PLL_SYNC_CTRL1_OFFSET                    (0x022Au)
#define BQ7982X_PLL_SYNC_CTRL1_POR_VAL                   (0x00u)

#define BQ7982X_POS_PLL_SYNC_CTRL1_PLL_SYNC_WAIT         (0x04u)
#define BQ7982X_POS_PLL_SYNC_CTRL1_PLL_SYNC_DIR          (0x03u)
#define BQ7982X_POS_PLL_SYNC_CTRL1_PLL_DEV_MODE          (0x00u)

#define BQ7982X_MSK_PLL_SYNC_CTRL1_PLL_SYNC_WAIT         (0x10u)
#define BQ7982X_MSK_PLL_SYNC_CTRL1_PLL_SYNC_DIR          (0x08u)
#define BQ7982X_MSK_PLL_SYNC_CTRL1_PLL_DEV_MODE          (0x07u)

/* --------------------------------------------------------------------------
 * PLL_SYNC_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_PLL_SYNC_CTRL2_OFFSET                    (0x022Bu)
#define BQ7982X_PLL_SYNC_CTRL2_POR_VAL                   (0x00u)

#define BQ7982X_POS_PLL_SYNC_CTRL2_PLL_SYNC_GO           (0x00u)

#define BQ7982X_MSK_PLL_SYNC_CTRL2_PLL_SYNC_GO           (0x01u)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL1_OFFSET                    (0x022Eu)
#define BQ7982X_DIG_SYNC_CTRL1_POR_VAL                   (0x00u)

#define BQ7982X_DIG_SYNC_CTRL1_GAINH_POS                 (0x00u)

#define BQ7982X_DIG_SYNC_CTRL1_GAINH_MSK                 (0xFFu)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL2_OFFSET                    (0x022Fu)
#define BQ7982X_DIG_SYNC_CTRL2_POR_VAL                   (0x00u)

#define BQ7982X_DIG_SYNC_CTRL2_GAINL_POS                 (0x00u)

#define BQ7982X_DIG_SYNC_CTRL2_GAINL_MSK                 (0xFFu)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL3           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL3_OFFSET                    (0x0230u)
#define BQ7982X_DIG_SYNC_CTRL3_POR_VAL                   (0x00u)

#define BQ7982X_POS_DIG_SYNC_CTRL3_SYNC_DEV_FRAME        (0x04u)
#define BQ7982X_POS_DIG_SYNC_CTRL3_SYNC_DEV_DIR          (0x03u)
#define BQ7982X_POS_DIG_SYNC_CTRL3_SYNC_DEV_MODE1        (0x02u)
#define BQ7982X_POS_DIG_SYNC_CTRL3_SYNC_DEV_MODE0        (0x01u)
#define BQ7982X_POS_DIG_SYNC_CTRL3_SYNC_DEV_GO           (0x00u)

#define BQ7982X_MSK_DIG_SYNC_CTRL3_SYNC_DEV_FRAME        (0x10u)
#define BQ7982X_MSK_DIG_SYNC_CTRL3_SYNC_DEV_DIR          (0x08u)
#define BQ7982X_MSK_DIG_SYNC_CTRL3_SYNC_DEV_MODE1        (0x04u)
#define BQ7982X_MSK_DIG_SYNC_CTRL3_SYNC_DEV_MODE0        (0x02u)
#define BQ7982X_MSK_DIG_SYNC_CTRL3_SYNC_DEV_GO           (0x01u)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL4           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL4_OFFSET                    (0x0231u)
#define BQ7982X_DIG_SYNC_CTRL4_POR_VAL                   (0x00u)

#define BQ7982X_POS_DIG_SYNC_CTRL4_REF_COUNTH            (0x00u)

#define BQ7982X_MSK_DIG_SYNC_CTRL4_REF_COUNTH            (0xFFu)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL5           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL5_OFFSET                    (0x0232u)
#define BQ7982X_DIG_SYNC_CTRL5_POR_VAL                   (0x00u)

#define BQ7982X_POS_DIG_SYNC_CTRL5_REF_COUNTL            (0x00u)

#define BQ7982X_MSK_DIG_SYNC_CTRL5_REF_COUNTL            (0xFFu)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL6           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL6_OFFSET                    (0x0233u)
#define BQ7982X_DIG_SYNC_CTRL6_POR_VAL                   (0x00u)

#define BQ7982X_POS_DIG_SYNC_CTRL6_DIG_SYNC_START        (0x05u)
#define BQ7982X_POS_DIG_SYNC_CTRL6_DIG_SYNC_WAIT         (0x04u)
#define BQ7982X_POS_DIG_SYNC_CTRL6_SYNC_ADC_RESET        (0x03u)
#define BQ7982X_POS_DIG_SYNC_CTRL6_DIG_SYNC_MODE         (0x01u)
#define BQ7982X_POS_DIG_SYNC_CTRL6_DIG_SYNC_GO           (0x00u)

#define BQ7982X_MSK_DIG_SYNC_CTRL6_DIG_SYNC_START        (0x20u)
#define BQ7982X_MSK_DIG_SYNC_CTRL6_DIG_SYNC_WAIT         (0x10u)
#define BQ7982X_MSK_DIG_SYNC_CTRL6_SYNC_ADC_RESET        (0x08u)
#define BQ7982X_MSK_DIG_SYNC_CTRL6_DIG_SYNC_MODE         (0x06u)
#define BQ7982X_MSK_DIG_SYNC_CTRL6_DIG_SYNC_GO           (0x01u)

/* DIG_SYNC_CTRL7/8: GAIN3 high/low bytes. */
#define BQ7982X_DIG_SYNC_CTRL7_OFFSET                    (0x0234u)
#define BQ7982X_DIG_SYNC_CTRL8_OFFSET                    (0x0235u)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL9           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL9_OFFSET                    (0x0236u)
#define BQ7982X_DIG_SYNC_CTRL9_POR_VAL                   (0x00u)

/* DIG_SYNC_CTRL10/11: reference count high/low bytes. */
#define BQ7982X_DIG_SYNC_CTRL10_OFFSET                   (0x0237u)
#define BQ7982X_DIG_SYNC_CTRL11_OFFSET                   (0x0238u)

/* --------------------------------------------------------------------------
 * DIG_SYNC_CTRL12          (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_CTRL12_OFFSET                   (0x0239u)
#define BQ7982X_DIG_SYNC_CTRL12_POR_VAL                  (0x00u)

/* DIG_SYNC_CTRL13: GPIO synchronization and DFT freeze control. */
#define BQ7982X_DIG_SYNC_CTRL13_OFFSET                   (0x023Au)

/* Pre-C0 register aliases retained for automatic silicon compatibility. */
#define BQ7982X_LEGACY_DIG_SYNC_CTRL3_OFFSET             (0x0230u)
#define BQ7982X_LEGACY_DIG_SYNC_CTRL6_OFFSET             (0x0233u)
#define BQ7982X_LEGACY_SMART_FREEZE_CTRL1_OFFSET         (0x0236u)
#define BQ7982X_LEGACY_SMART_FREEZE_CTRL2_OFFSET         (0x0237u)
#define BQ7982X_LEGACY_SMART_FREEZE_STAT1_OFFSET         (0x0786u)

/* --------------------------------------------------------------------------
 * SMART_FREEZE_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMART_FREEZE_CTRL1_OFFSET                    (0x023Cu)
#define BQ7982X_SMART_FREEZE_CTRL1_POR_VAL                   (0x00u)

#define BQ7982X_POS_SMART_FREEZE_CTRL1_SLOT_SEL              (0x00u)

#define BQ7982X_MSK_SMART_FREEZE_CTRL1_SLOT_SEL              (0xFFu)

/* --------------------------------------------------------------------------
 * SMART_FREEZE_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMART_FREEZE_CTRL2_OFFSET                    (0x023Du)
#define BQ7982X_SMART_FREEZE_CTRL2_POR_VAL                   (0x00u)

#define BQ7982X_POS_SMART_FREEZE_CTRL2_SF_MODE               (0x01u)
#define BQ7982X_POS_SMART_FREEZE_CTRL2_SF_GO                 (0x00u)

#define BQ7982X_MSK_SMART_FREEZE_CTRL2_SF_MODE               (0x06u)
#define BQ7982X_MSK_SMART_FREEZE_CTRL2_SF_GO                 (0x01u)

/* --------------------------------------------------------------------------
 * ADC_CTRL5                    (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_ADC_CTRL5_OFFSET                            (0x0243u)
#define BQ7982X_ADC_CTRL5_POR_VAL                           (0x00u)

#define BQ7982X_ADC_CTRL5_LPF2_CS_POS                       (0x05u)
#define BQ7982X_ADC_CTRL5_LPF2_CS_EN_POS                    (0x04u)
#define BQ7982X_ADC_CTRL5_LPF_CS_POS                        (0x01u)
#define BQ7982X_ADC_CTRL5_LPF_CS_EN_POS                     (0x00u)

#define BQ7982X_ADC_CTRL5_LPF2_CS_MSK                       (0xE0u)
#define BQ7982X_ADC_CTRL5_LPF2_CS_EN_MSK                    (0x10u)
#define BQ7982X_ADC_CTRL5_LPF_CS_MSK                        (0x0Eu)
#define BQ7982X_ADC_CTRL5_LPF_CS_EN_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * ADC_CTRL4                    (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_ADC_CTRL4_OFFSET                            (0x0244u)
#define BQ7982X_ADC_CTRL4_POR_VAL                           (0x00u)

#define BQ7982X_POS_ADC_CTRL4_FREEZE_LPF_EN                 (0x03u)
#define BQ7982X_POS_ADC_CTRL4_ADC_DLY_MODE                  (0x02u)
#define BQ7982X_ADC_CTRL4_CSADC_MODE_POS                    (0x01u)
#define BQ7982X_ADC_CTRL4_GP_DR_POS                         (0x00u)

#define BQ7982X_MSK_ADC_CTRL4_FREEZE_LPF_EN                 (0x08u)
#define BQ7982X_MSK_ADC_CTRL4_ADC_DLY_MODE                  (0x04u)
#define BQ7982X_ADC_CTRL4_CSADC_MODE_MSK                    (0x02u)
#define BQ7982X_ADC_CTRL4_GP_DR_MSK                         (0x01u)

/* --------------------------------------------------------------------------
 * ADC_CTRL3                    (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_ADC_CTRL3_OFFSET                            (0x0245u)
#define BQ7982X_ADC_CTRL3_POR_VAL                           (0x00u)

#define BQ7982X_ADC_CTRL3_FREEZE_EN_POS                     (0x07u)
#define BQ7982X_ADC_CTRL3_LPF_VCELL_POS                     (0x04u)
#define BQ7982X_ADC_CTRL3_LPF_VCELL_EN_POS                  (0x03u)
#define BQ7982X_ADC_CTRL3_ADC_MODE_POS                      (0x01u)
#define BQ7982X_ADC_CTRL3_ADC_GO_POS                        (0x00u)

#define BQ7982X_ADC_CTRL3_FREEZE_EN_MSK                     (0x80u)
#define BQ7982X_ADC_CTRL3_LPF_VCELL_MSK                     (0x70u)
#define BQ7982X_ADC_CTRL3_LPF_VCELL_EN_MSK                  (0x08u)
#define BQ7982X_ADC_CTRL3_ADC_MODE_MSK                      (0x06u)
#define BQ7982X_ADC_CTRL3_ADC_GO_MSK                        (0x01u)

/* --------------------------------------------------------------------------
 * ADC_CTRL2                    (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_ADC_CTRL2_OFFSET                            (0x0246u)
#define BQ7982X_ADC_CTRL2_POR_VAL                           (0x00u)

#define BQ7982X_POS_ADC_CTRL2_FLIP_READ_EN                  (0x07u)
#define BQ7982X_ADC_CTRL2_FLIP_RESET_POS                    (0x06u)
#define BQ7982X_POS_ADC_CTRL2_DIAG_VCELL_GPIO               (0x05u)
#define BQ7982X_POS_ADC_CTRL2_DIAG_ANA_SEL                  (0x00u)

#define BQ7982X_MSK_ADC_CTRL2_FLIP_READ_EN                  (0x80u)
#define BQ7982X_ADC_CTRL2_FLIP_RESET_MSK                    (0x40u)
#define BQ7982X_MSK_ADC_CTRL2_DIAG_VCELL_GPIO               (0x20u)
#define BQ7982X_MSK_ADC_CTRL2_DIAG_ANA_SEL                  (0x1Fu)

/* --------------------------------------------------------------------------
 * ADC_CTRL1                    (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_ADC_CTRL1_OFFSET                            (0x0247u)
#define BQ7982X_ADC_CTRL1_POR_VAL                           (0x00u)

#define BQ7982X_POS_ADC_CTRL1_DIAG_D1D2_SEL                 (0x01u)
#define BQ7982X_POS_ADC_CTRL1_DIAG_MEAS_GO                  (0x00u)

#define BQ7982X_MSK_ADC_CTRL1_DIAG_D1D2_SEL                 (0x0Eu)
#define BQ7982X_MSK_ADC_CTRL1_DIAG_MEAS_GO                  (0x01u)

/* --------------------------------------------------------------------------
 * DIAG_ADC_CTRL1               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_ADC_CTRL1_OFFSET                       (0x0248u)
#define BQ7982X_DIAG_ADC_CTRL1_POR_VAL                      (0x00u)

#define BQ7982X_POS_DIAG_ADC_CTRL1_VCELL_FILT               (0x06u)
#define BQ7982X_POS_DIAG_ADC_CTRL1_VCELL_THR                (0x00u)

#define BQ7982X_MSK_DIAG_ADC_CTRL1_VCELL_FILT               (0x40u)
#define BQ7982X_MSK_DIAG_ADC_CTRL1_VCELL_THR                (0x3Fu)

/* --------------------------------------------------------------------------
 * DIAG_ADC_CTRL2               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_ADC_CTRL2_OFFSET                       (0x0249u)
#define BQ7982X_DIAG_ADC_CTRL2_POR_VAL                      (0x00u)

#define BQ7982X_POS_DIAG_ADC_CTRL2_BAL_CYCLES               (0x05u)
#define BQ7982X_DIAG_ADC_CTRL2_BB_THR_POS                   (0x03u)
#define BQ7982X_POS_DIAG_ADC_CTRL2_GPIO_THR                 (0x00u)

#define BQ7982X_MSK_DIAG_ADC_CTRL2_BAL_CYCLES               (0x20u)
#define BQ7982X_DIAG_ADC_CTRL2_BB_THR_MSK                   (0x18u)
#define BQ7982X_MSK_DIAG_ADC_CTRL2_GPIO_THR                 (0x07u)

/* --------------------------------------------------------------------------
 * DIAG_ADC_CTRL3               (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_ADC_CTRL3_OFFSET                       (0x024Au)
#define BQ7982X_DIAG_ADC_CTRL3_POR_VAL                      (0x00u)

#define BQ7982X_POS_DIAG_ADC_CTRL3_DIAG_BAL_FREEZE          (0x07u)
#define BQ7982X_POS_DIAG_ADC_CTRL3_BB_ACOMP_EN              (0x06u)
#define BQ7982X_POS_DIAG_ADC_CTRL3_ACOMP_MPFLT_INJ          (0x05u)
#define BQ7982X_POS_DIAG_ADC_CTRL3_DCOMP_MPFLT_INJ          (0x04u)
#define BQ7982X_POS_DIAG_ADC_CTRL3_DIAG_DIG_EN              (0x03u)
#define BQ7982X_POS_DIAG_ADC_CTRL3_DIAG_ANA_MODE            (0x01u)
#define BQ7982X_POS_DIAG_ADC_CTRL3_DIAG_ANA_GO              (0x00u)

#define BQ7982X_MSK_DIAG_ADC_CTRL3_DIAG_BAL_FREEZE          (0x80u)
#define BQ7982X_MSK_DIAG_ADC_CTRL3_BB_ACOMP_EN              (0x40u)
#define BQ7982X_MSK_DIAG_ADC_CTRL3_ACOMP_MPFLT_INJ          (0x20u)
#define BQ7982X_MSK_DIAG_ADC_CTRL3_DCOMP_MPFLT_INJ          (0x10u)
#define BQ7982X_MSK_DIAG_ADC_CTRL3_DIAG_DIG_EN              (0x08u)
#define BQ7982X_MSK_DIAG_ADC_CTRL3_DIAG_ANA_MODE            (0x06u)
#define BQ7982X_MSK_DIAG_ADC_CTRL3_DIAG_ANA_GO              (0x01u)

/* --------------------------------------------------------------------------
 * DIAG_MISC_CTRL1              (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_MISC_CTRL1_OFFSET                      (0x024Bu)
#define BQ7982X_DIAG_MISC_CTRL1_POR_VAL                     (0x00u)

#define BQ7982X_POS_DIAG_MISC_CTRL1_CSPI_LOOPBACK           (0x06u)
#define BQ7982X_POS_DIAG_MISC_CTRL1_FLIP_TR_CRC             (0x05u)
#define BQ7982X_POS_DIAG_MISC_CTRL1_FLIP_FACT_CRC           (0x04u)
#define BQ7982X_POS_DIAG_MISC_CTRL1_MARGIN_MODE             (0x01u)
#define BQ7982X_POS_DIAG_MISC_CTRL1_MARGIN_GO               (0x00u)

#define BQ7982X_MSK_DIAG_MISC_CTRL1_CSPI_LOOPBACK           (0x40u)
#define BQ7982X_MSK_DIAG_MISC_CTRL1_FLIP_TR_CRC             (0x20u)
#define BQ7982X_MSK_DIAG_MISC_CTRL1_FLIP_FACT_CRC           (0x10u)
#define BQ7982X_MSK_DIAG_MISC_CTRL1_MARGIN_MODE             (0xE0u)
#define BQ7982X_MSK_DIAG_MISC_CTRL1_MARGIN_GO               (0x01u)

/* --------------------------------------------------------------------------
 * DIAG_MISC_CTRL2              (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_MISC_CTRL2_OFFSET                      (0x024Cu)
#define BQ7982X_DIAG_MISC_CTRL2_POR_VAL                     (0x00u)

#define BQ7982X_POS_DIAG_MISC_CTRL2_DIAG_VCOW_DIS           (0x06u)
#define BQ7982X_POS_DIAG_MISC_CTRL2_DIAG_CBOW_DIS           (0x05u)
#define BQ7982X_POS_DIAG_MISC_CTRL2_NUM_CELL_OV_MPFLT_INJ   (0x04u)
#define BQ7982X_POS_DIAG_MISC_CTRL2_CBFETOW_MPFLT_INJ       (0x03u)
#define BQ7982X_POS_DIAG_MISC_CTRL2_DIAG_CBFETOW_GO         (0x02u)
#define BQ7982X_POS_DIAG_MISC_CTRL2_PWRBIST_NO_RST          (0x01u)
#define BQ7982X_POS_DIAG_MISC_CTRL2_PWRBIST_GO              (0x00u)

#define BQ7982X_MSK_DIAG_MISC_CTRL2_DIAG_VCOW_DIS           (0x40u)
#define BQ7982X_MSK_DIAG_MISC_CTRL2_DIAG_CBOW_DIS           (0x20u)
#define BQ7982X_MSK_DIAG_MISC_CTRL2_NUM_CELL_OV_MPFLT_INJ   (0x10u)
#define BQ7982X_MSK_DIAG_MISC_CTRL2_CBFETOW_MPFLT_INJ       (0x08u)
#define BQ7982X_MSK_DIAG_MISC_CTRL2_DIAG_CBFETOW_GO         (0x04u)
#define BQ7982X_MSK_DIAG_MISC_CTRL2_PWRBIST_NO_RST          (0x02u)
#define BQ7982X_MSK_DIAG_MISC_CTRL2_PWRBIST_GO              (0x01u)

/* --------------------------------------------------------------------------
 * CB_CELL26_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL26_CTRL_OFFSET                       (0x0256u)
#define BQ7982X_CB_CELL26_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL26_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL26_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL25_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL25_CTRL_OFFSET                       (0x0257u)
#define BQ7982X_CB_CELL25_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL25_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL25_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL24_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL24_CTRL_OFFSET                       (0x0258u)
#define BQ7982X_CB_CELL24_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL24_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL24_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL23_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL23_CTRL_OFFSET                       (0x0259u)
#define BQ7982X_CB_CELL23_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL23_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL23_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL22_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL22_CTRL_OFFSET                       (0x025Au)
#define BQ7982X_CB_CELL22_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL22_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL22_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL21_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL21_CTRL_OFFSET                       (0x025Bu)
#define BQ7982X_CB_CELL21_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL21_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL21_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL20_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL20_CTRL_OFFSET                       (0x025Cu)
#define BQ7982X_CB_CELL20_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL20_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL20_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL19_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL19_CTRL_OFFSET                       (0x025Du)
#define BQ7982X_CB_CELL19_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL19_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL19_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL18_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL18_CTRL_OFFSET                       (0x025Eu)
#define BQ7982X_CB_CELL18_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL18_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL18_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL17_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL17_CTRL_OFFSET                       (0x025Fu)
#define BQ7982X_CB_CELL17_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL17_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL17_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL16_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL16_CTRL_OFFSET                       (0x0260u)
#define BQ7982X_CB_CELL16_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL16_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL16_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL15_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL15_CTRL_OFFSET                       (0x0261u)
#define BQ7982X_CB_CELL15_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL15_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL15_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL14_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL14_CTRL_OFFSET                       (0x0262u)
#define BQ7982X_CB_CELL14_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL14_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL14_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL13_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL13_CTRL_OFFSET                       (0x0263u)
#define BQ7982X_CB_CELL13_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL13_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL13_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL12_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL12_CTRL_OFFSET                       (0x0264u)
#define BQ7982X_CB_CELL12_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL12_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL12_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL11_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL11_CTRL_OFFSET                       (0x0265u)
#define BQ7982X_CB_CELL11_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL11_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL11_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL10_CTRL               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL10_CTRL_OFFSET                       (0x0266u)
#define BQ7982X_CB_CELL10_CTRL_POR_VAL                      (0x00u)

#define BQ7982X_CB_CELL10_CTRL_TIME_POS                     (0x00u)
#define BQ7982X_CB_CELL10_CTRL_TIME_MSK                     (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL9_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL9_CTRL_OFFSET                        (0x0267u)
#define BQ7982X_CB_CELL9_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL9_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL9_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL8_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL8_CTRL_OFFSET                        (0x0268u)
#define BQ7982X_CB_CELL8_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL8_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL8_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL7_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL7_CTRL_OFFSET                        (0x0269u)
#define BQ7982X_CB_CELL7_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL7_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL7_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL6_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL6_CTRL_OFFSET                        (0x026Au)
#define BQ7982X_CB_CELL6_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL6_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL6_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL5_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL5_CTRL_OFFSET                        (0x026Bu)
#define BQ7982X_CB_CELL5_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL5_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL5_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL4_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL4_CTRL_OFFSET                        (0x026Cu)
#define BQ7982X_CB_CELL4_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL4_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL4_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL3_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL3_CTRL_OFFSET                        (0x026Du)
#define BQ7982X_CB_CELL3_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL3_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL3_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL2_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL2_CTRL_OFFSET                        (0x026Eu)
#define BQ7982X_CB_CELL2_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL2_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL2_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_CELL1_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_CELL1_CTRL_OFFSET                        (0x026Fu)
#define BQ7982X_CB_CELL1_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_CELL1_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_CELL1_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * CB_GLOBAL_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CB_GLOBAL_CTRL_OFFSET                        (0x0270u)
#define BQ7982X_CB_GLOBAL_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CB_GLOBAL_CTRL_TIME_POS                      (0x00u)
#define BQ7982X_CB_GLOBAL_CTRL_TIME_MSK                      (0x1Fu)

/* --------------------------------------------------------------------------
 * VCBDONE_THRESH               (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCBDONE_THRESH_OFFSET                        (0x0271u)
#define BQ7982X_VCBDONE_THRESH_POR_VAL                       (0x00u)

#define BQ7982X_VCBDONE_THRESH_CB_THR_POS                    (0x00u)
#define BQ7982X_VCBDONE_THRESH_CB_THR_MSK                    (0x7Fu)

/* --------------------------------------------------------------------------
 * OTCB_THRESH                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTCB_THRESH_OFFSET                        (0x0272u)
#define BQ7982X_OTCB_THRESH_POR_VAL                       (0x00u)

#define BQ7982X_OTCB_THRESH_OTCB_THR_POS                    (0x00u)
#define BQ7982X_OTCB_THRESH_OTCB_THR_MSK                    (0x0Fu)

/* --------------------------------------------------------------------------
 * OVUV_THR_SEL1                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OVUV_THR_SEL1_OFFSET                        (0x0273u)
#define BQ7982X_OVUV_THR_SEL1_POR_VAL                       (0x00u)

#define BQ7982X_OVUV_THR_SEL1_CELL8_POS                    (0x07u)
#define BQ7982X_OVUV_THR_SEL1_CELL8_MSK                    (0x80u)

#define BQ7982X_OVUV_THR_SEL1_CELL7_POS                    (0x06u)
#define BQ7982X_OVUV_THR_SEL1_CELL7_MSK                    (0x40u)

#define BQ7982X_OVUV_THR_SEL1_CELL6_POS                    (0x05u)
#define BQ7982X_OVUV_THR_SEL1_CELL6_MSK                    (0x20u)

#define BQ7982X_OVUV_THR_SEL1_CELL5_POS                    (0x04u)
#define BQ7982X_OVUV_THR_SEL1_CELL5_MSK                    (0x10u)

#define BQ7982X_OVUV_THR_SEL1_CELL4_POS                    (0x03u)
#define BQ7982X_OVUV_THR_SEL1_CELL4_MSK                    (0x08u)

#define BQ7982X_OVUV_THR_SEL1_CELL3_POS                    (0x02u)
#define BQ7982X_OVUV_THR_SEL1_CELL3_MSK                    (0x04u)

#define BQ7982X_OVUV_THR_SEL1_CELL2_POS                    (0x01u)
#define BQ7982X_OVUV_THR_SEL1_CELL2_MSK                    (0x02u)

#define BQ7982X_OVUV_THR_SEL1_CELL1_POS                    (0x00u)
#define BQ7982X_OVUV_THR_SEL1_CELL1_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * OVUV_THR_SEL2                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OVUV_THR_SEL2_OFFSET                        (0x0274u)
#define BQ7982X_OVUV_THR_SEL2_POR_VAL                       (0x00u)

#define BQ7982X_OVUV_THR_SEL2_CELL16_POS                    (0x07u)
#define BQ7982X_OVUV_THR_SEL2_CELL16_MSK                    (0x80u)

#define BQ7982X_OVUV_THR_SEL2_CELL15_POS                    (0x06u)
#define BQ7982X_OVUV_THR_SEL2_CELL15_MSK                    (0x40u)

#define BQ7982X_OVUV_THR_SEL2_CELL14_POS                    (0x05u)
#define BQ7982X_OVUV_THR_SEL2_CELL14_MSK                    (0x20u)

#define BQ7982X_OVUV_THR_SEL2_CELL13_POS                    (0x04u)
#define BQ7982X_OVUV_THR_SEL2_CELL13_MSK                    (0x10u)

#define BQ7982X_OVUV_THR_SEL2_CELL12_POS                    (0x03u)
#define BQ7982X_OVUV_THR_SEL2_CELL12_MSK                    (0x08u)

#define BQ7982X_OVUV_THR_SEL2_CELL11_POS                    (0x02u)
#define BQ7982X_OVUV_THR_SEL2_CELL11_MSK                    (0x04u)

#define BQ7982X_OVUV_THR_SEL2_CELL10_POS                    (0x01u)
#define BQ7982X_OVUV_THR_SEL2_CELL10_MSK                    (0x02u)

#define BQ7982X_OVUV_THR_SEL2_CELL9_POS                    (0x00u)
#define BQ7982X_OVUV_THR_SEL2_CELL9_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * OVUV_THR_SEL3                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OVUV_THR_SEL3_OFFSET                        (0x0275u)
#define BQ7982X_OVUV_THR_SEL3_POR_VAL                       (0x00u)

#define BQ7982X_OVUV_THR_SEL3_CELL24_POS                    (0x07u)
#define BQ7982X_OVUV_THR_SEL3_CELL24_MSK                    (0x80u)

#define BQ7982X_OVUV_THR_SEL3_CELL23_POS                    (0x06u)
#define BQ7982X_OVUV_THR_SEL3_CELL23_MSK                    (0x40u)

#define BQ7982X_OVUV_THR_SEL3_CELL22_POS                    (0x05u)
#define BQ7982X_OVUV_THR_SEL3_CELL22_MSK                    (0x20u)

#define BQ7982X_OVUV_THR_SEL3_CELL21_POS                    (0x04u)
#define BQ7982X_OVUV_THR_SEL3_CELL21_MSK                    (0x10u)

#define BQ7982X_OVUV_THR_SEL3_CELL20_POS                    (0x03u)
#define BQ7982X_OVUV_THR_SEL3_CELL20_MSK                    (0x08u)

#define BQ7982X_OVUV_THR_SEL3_CELL19_POS                    (0x02u)
#define BQ7982X_OVUV_THR_SEL3_CELL19_MSK                    (0x04u)

#define BQ7982X_OVUV_THR_SEL3_CELL18_POS                    (0x01u)
#define BQ7982X_OVUV_THR_SEL3_CELL18_MSK                    (0x02u)

#define BQ7982X_OVUV_THR_SEL3_CELL17_POS                    (0x00u)
#define BQ7982X_OVUV_THR_SEL3_CELL17_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * OVUV_THR_SEL4                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OVUV_THR_SEL4_OFFSET                        (0x0276u)
#define BQ7982X_OVUV_THR_SEL4_POR_VAL                       (0x00u)

#define BQ7982X_OVUV_THR_SEL4_CELL26_POS                    (0x01u)
#define BQ7982X_OVUV_THR_SEL4_CELL26_MSK                    (0x02u)

#define BQ7982X_OVUV_THR_SEL4_CELL25_POS                    (0x00u)
#define BQ7982X_OVUV_THR_SEL4_CELL25_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * OTUT_THR_SEL1                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTUT_THR_SEL1_OFFSET                        (0x0277u)
#define BQ7982X_OTUT_THR_SEL1_POR_VAL                       (0x00u)

#define BQ7982X_OTUT_THR_SEL1_GPIO8_POS                     (0x07u)
#define BQ7982X_OTUT_THR_SEL1_GPIO8_MSK                     (0x80u)

#define BQ7982X_OTUT_THR_SEL1_GPIO7_POS                     (0x06u)
#define BQ7982X_OTUT_THR_SEL1_GPIO7_MSK                     (0x40u)

#define BQ7982X_OTUT_THR_SEL1_GPIO6_POS                     (0x05u)
#define BQ7982X_OTUT_THR_SEL1_GPIO6_MSK                     (0x20u)

#define BQ7982X_OTUT_THR_SEL1_GPIO5_POS                     (0x04u)
#define BQ7982X_OTUT_THR_SEL1_GPIO5_MSK                     (0x10u)

#define BQ7982X_OTUT_THR_SEL1_GPIO4_POS                     (0x03u)
#define BQ7982X_OTUT_THR_SEL1_GPIO4_MSK                     (0x08u)

#define BQ7982X_OTUT_THR_SEL1_GPIO3_POS                     (0x02u)
#define BQ7982X_OTUT_THR_SEL1_GPIO3_MSK                     (0x04u)

#define BQ7982X_OTUT_THR_SEL1_GPIO2_POS                     (0x01u)
#define BQ7982X_OTUT_THR_SEL1_GPIO2_MSK                     (0x02u)

#define BQ7982X_OTUT_THR_SEL1_GPIO1_POS                     (0x00u)
#define BQ7982X_OTUT_THR_SEL1_GPIO1_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * OTUT_THR_SEL2                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTUT_THR_SEL2_OFFSET                        (0x0278u)
#define BQ7982X_OTUT_THR_SEL2_POR_VAL                       (0x00u)

#define BQ7982X_OTUT_THR_SEL2_GPIO16_POS                    (0x07u)
#define BQ7982X_OTUT_THR_SEL2_GPIO16_MSK                    (0x80u)

#define BQ7982X_OTUT_THR_SEL2_GPIO15_POS                    (0x06u)
#define BQ7982X_OTUT_THR_SEL2_GPIO15_MSK                    (0x40u)

#define BQ7982X_OTUT_THR_SEL2_GPIO14_POS                    (0x05u)
#define BQ7982X_OTUT_THR_SEL2_GPIO14_MSK                    (0x20u)

#define BQ7982X_OTUT_THR_SEL2_GPIO13_POS                    (0x04u)
#define BQ7982X_OTUT_THR_SEL2_GPIO13_MSK                    (0x10u)

#define BQ7982X_OTUT_THR_SEL2_GPIO12_POS                    (0x03u)
#define BQ7982X_OTUT_THR_SEL2_GPIO12_MSK                    (0x08u)

#define BQ7982X_OTUT_THR_SEL2_GPIO11_POS                    (0x02u)
#define BQ7982X_OTUT_THR_SEL2_GPIO11_MSK                    (0x04u)

#define BQ7982X_OTUT_THR_SEL2_GPIO10_POS                    (0x01u)
#define BQ7982X_OTUT_THR_SEL2_GPIO10_MSK                    (0x02u)

#define BQ7982X_OTUT_THR_SEL2_GPIO9_POS                     (0x00u)
#define BQ7982X_OTUT_THR_SEL2_GPIO9_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * OTUT_THR_SEL3                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTUT_THR_SEL3_OFFSET                        (0x0279u)
#define BQ7982X_OTUT_THR_SEL3_POR_VAL                       (0x00u)

#define BQ7982X_OTUT_THR_SEL3_GPIO20_POS                    (0x03u)
#define BQ7982X_OTUT_THR_SEL3_GPIO20_MSK                    (0x08u)

#define BQ7982X_OTUT_THR_SEL3_GPIO19_POS                    (0x02u)
#define BQ7982X_OTUT_THR_SEL3_GPIO19_MSK                    (0x04u)

#define BQ7982X_OTUT_THR_SEL3_GPIO18_POS                    (0x01u)
#define BQ7982X_OTUT_THR_SEL3_GPIO18_MSK                    (0x02u)

#define BQ7982X_OTUT_THR_SEL3_GPIO17_POS                    (0x00u)
#define BQ7982X_OTUT_THR_SEL3_GPIO17_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * MON_CTRL                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_MON_CTRL_OFFSET                        (0x027Au)
#define BQ7982X_MON_CTRL_POR_VAL                       (0x31u)

#define BQ7982X_POS_MON_CTRL_SMON_PEAK_RST            (0x07u)
#define BQ7982X_MSK_MON_CTRL_SMON_PEAK_RST            (0x80u)

#define BQ7982X_POS_MON_CTRL_SMON_PEAK_MODE           (0x06u)
#define BQ7982X_MSK_MON_CTRL_SMON_PEAK_MODE           (0x40u)

#define BQ7982X_MON_CTRL_OTCB_MODE_POS                (0x05u)
#define BQ7982X_MON_CTRL_OTCB_MODE_MSK                (0x20u)

#define BQ7982X_MON_CTRL_VCBDONE_MODE_POS            (0x04u)
#define BQ7982X_MON_CTRL_VCBDONE_MODE_MSK            (0x10u)

#define BQ7982X_MON_CTRL_SMON_MODE_POS                (0x03u)
#define BQ7982X_MON_CTRL_SMON_MODE_MSK                (0x08u)

#define BQ7982X_MON_CTRL_OTUT_MODE_POS                (0x02u)
#define BQ7982X_MON_CTRL_OTUT_MODE_MSK                (0x04u)

#define BQ7982X_MON_CTRL_OVUV_MODE_POS                (0x01u)
#define BQ7982X_MON_CTRL_OVUV_MODE_MSK                (0x02u)

#define BQ7982X_MON_CTRL_MON_GO_POS                   (0x00u)
#define BQ7982X_MON_CTRL_MON_GO_MSK                   (0x01u)

/* --------------------------------------------------------------------------
 * DIAG_MON_CTRL                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_MON_CTRL_OFFSET                        (0x027Bu)
#define BQ7982X_DIAG_MON_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_POS_DIAG_MON_CTRL_SMON_MPFLT_INJ           (0x02u)
#define BQ7982X_MSK_DIAG_MON_CTRL_SMON_MPFLT_INJ           (0x04u)

#define BQ7982X_POS_DIAG_MON_CTRL_TMON_MPFLT_INJ           (0x01u)
#define BQ7982X_MSK_DIAG_MON_CTRL_TMON_MPFLT_INJ           (0x02u)

#define BQ7982X_POS_DIAG_MON_CTRL_OVUV_MPFLT_INJ           (0x00u)
#define BQ7982X_MSK_DIAG_MON_CTRL_OVUV_MPFLT_INJ           (0x01u)

/* --------------------------------------------------------------------------
 * BAL_CTRL1                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_CTRL1_OFFSET                        (0x027Cu)
#define BQ7982X_BAL_CTRL1_POR_VAL                       (0x00u)

#define BQ7982X_BAL_CTRL1_PWM5_POS                      (0x05u)
#define BQ7982X_BAL_CTRL1_PWM5_MSK                      (0x20u)

#define BQ7982X_BAL_CTRL1_PWM4_POS                      (0x04u)
#define BQ7982X_BAL_CTRL1_PWM4_MSK                      (0x10u)

#define BQ7982X_BAL_CTRL1_PWM3_POS                      (0x03u)
#define BQ7982X_BAL_CTRL1_PWM3_MSK                      (0x08u)

#define BQ7982X_BAL_CTRL1_PWM2_POS                      (0x02u)
#define BQ7982X_BAL_CTRL1_PWM2_MSK                      (0x04u)

#define BQ7982X_BAL_CTRL1_PWM1_POS                      (0x01u)
#define BQ7982X_BAL_CTRL1_PWM1_MSK                      (0x02u)

#define BQ7982X_BAL_CTRL1_PWM0_POS                      (0x00u)
#define BQ7982X_BAL_CTRL1_PWM0_MSK                      (0x01u)

#define BQ7982X_BAL_CTRL1_PWM_MSK                       (0x3Fu)
/* --------------------------------------------------------------------------
 * BAL_CTRL2                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_CTRL2_OFFSET                        (0x027Du)
#define BQ7982X_BAL_CTRL2_POR_VAL                       (0x00u)

#define BQ7982X_BAL_CTRL2_CB_PAUSE_POS                  (0x04u)
#define BQ7982X_BAL_CTRL2_CB_PAUSE_MSK                  (0x10u)

#define BQ7982X_BAL_CTRL2_FLTSTOP_EN_POS                (0x03u)
#define BQ7982X_BAL_CTRL2_FLTSTOP_EN_MSK                (0x08u)

#define BQ7982X_BAL_CTRL2_BAL_ACT_POS                   (0x02u)
#define BQ7982X_BAL_CTRL2_BAL_ACT_MSK                   (0x04u)

#define BQ7982X_BAL_CTRL2_AUTO_BAL_POS                  (0x01u)
#define BQ7982X_BAL_CTRL2_AUTO_BAL_MSK                  (0x02u)

#define BQ7982X_BAL_CTRL2_BAL_GO_POS                    (0x00u)
#define BQ7982X_BAL_CTRL2_BAL_GO_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * BAL_CTRL3                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_CTRL3_OFFSET                        (0x027Eu)
#define BQ7982X_BAL_CTRL3_POR_VAL                       (0x00u)

#define BQ7982X_POS_BAL_CTRL3_GLOBAL_TIME_SEL           (0x06u)
#define BQ7982X_MSK_BAL_CTRL3_GLOBAL_TIME_SEL           (0x40u)

#define BQ7982X_POS_BAL_CTRL3_BAL_TIME_SEL             (0x01u)
#define BQ7982X_MSK_BAL_CTRL3_BAL_TIME_SEL             (0x3Eu)

#define BQ7982X_BAL_CTRL3_BAL_TIME_GO_POS               (0x00u)
#define BQ7982X_BAL_CTRL3_BAL_TIME_GO_MSK               (0x01u)

/* --------------------------------------------------------------------------
 * DIAG_BAL_CTRL                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_BAL_CTRL_OFFSET                        (0x027Fu)
#define BQ7982X_DIAG_BAL_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_POS_DIAG_BAL_CTRL_DIAG_BAL_UNFREEZE_GO      (0x01u)
#define BQ7982X_MSK_DIAG_BAL_CTRL_DIAG_BAL_UNFREEZE_GO      (0x02u)

#define BQ7982X_POS_DIAG_BAL_CTRL_DIAG_BAL_GO               (0x00u)
#define BQ7982X_MSK_DIAG_BAL_CTRL_DIAG_BAL_GO               (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_RST1                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_RST1_OFFSET                        (0x0290u)
#define BQ7982X_FAULT_RST1_POR_VAL                       (0x00u)

#define BQ7982X_POS_FAULT_RST1_RST_SYS_SYNC              (0x07u)
#define BQ7982X_MSK_FAULT_RST1_RST_SYS_SYNC              (0x80u)

#define BQ7982X_POS_FAULT_RST1_RST_SYS_INT               (0x06u)
#define BQ7982X_MSK_FAULT_RST1_RST_SYS_INT               (0x40u)

#define BQ7982X_POS_FAULT_RST1_RST_SYS_MON               (0x05u)
#define BQ7982X_MSK_FAULT_RST1_RST_SYS_MON               (0x20u)

#define BQ7982X_POS_FAULT_RST1_RST_SYS_SMON              (0x04u)
#define BQ7982X_MSK_FAULT_RST1_RST_SYS_SMON              (0x10u)

#define BQ7982X_FAULT_RST1_RST_UT_POS                    (0x03u)
#define BQ7982X_FAULT_RST1_RST_UT_MSK                    (0x08u)

#define BQ7982X_FAULT_RST1_RST_OT_POS                    (0x02u)
#define BQ7982X_FAULT_RST1_RST_OT_MSK                    (0x04u)

#define BQ7982X_FAULT_RST1_RST_UV_POS                    (0x01u)
#define BQ7982X_FAULT_RST1_RST_UV_MSK                    (0x02u)

#define BQ7982X_FAULT_RST1_RST_OV_POS                    (0x00u)
#define BQ7982X_FAULT_RST1_RST_OV_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_RST2                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_RST2_OFFSET                        (0x0291u)
#define BQ7982X_FAULT_RST2_POR_VAL                       (0x00u)

#define BQ7982X_FAULT_RST2_RST_PWR_POS                   (0x07u)
#define BQ7982X_FAULT_RST2_RST_PWR_MSK                   (0x80u)

#define BQ7982X_POS_FAULT_RST2_RST_COMM_FRAME           (0x06u)
#define BQ7982X_MSK_FAULT_RST2_RST_COMM_FRAME           (0x40u)

#define BQ7982X_POS_FAULT_RST2_RST_COMM_FT              (0x05u)
#define BQ7982X_MSK_FAULT_RST2_RST_COMM_FT              (0x20u)

#define BQ7982X_POS_FAULT_RST2_RST_COMM_HB              (0x04u)
#define BQ7982X_MSK_FAULT_RST2_RST_COMM_HB              (0x10u)

#define BQ7982X_POS_FAULT_RST2_RST_COMM_DSY             (0x03u)
#define BQ7982X_MSK_FAULT_RST2_RST_COMM_DSY             (0x08u)

#define BQ7982X_POS_FAULT_RST2_RST_COMM_PSPI            (0x02u)
#define BQ7982X_MSK_FAULT_RST2_RST_COMM_PSPI            (0x04u)

#define BQ7982X_POS_FAULT_RST2_RST_COMM_BUSY            (0x01u)
#define BQ7982X_MSK_FAULT_RST2_RST_COMM_BUSY            (0x02u)

#define BQ7982X_POS_FAULT_RST2_RST_SYS_MISC             (0x00u)
#define BQ7982X_MSK_FAULT_RST2_RST_SYS_MISC             (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_RST3                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_RST3_OFFSET                        (0x0292u)
#define BQ7982X_FAULT_RST3_POR_VAL                       (0x00u)

#define BQ7982X_POS_FAULT_RST3_RST_SYS_EIS              (0x04u)
#define BQ7982X_MSK_FAULT_RST3_RST_SYS_EIS              (0x10u)

#define BQ7982X_FAULT_RST3_RST_CB_POS                   (0x03u)
#define BQ7982X_FAULT_RST3_RST_CB_MSK                   (0x08u)

#define BQ7982X_FAULT_RST3_RST_ADC_POS                  (0x02u)
#define BQ7982X_FAULT_RST3_RST_ADC_MSK                  (0x04u)

#define BQ7982X_POS_FAULT_RST3_RST_MEM_CRC              (0x01u)
#define BQ7982X_MSK_FAULT_RST3_RST_MEM_CRC              (0x02u)

#define BQ7982X_POS_FAULT_RST3_RST_MEM_DATA             (0x00u)
#define BQ7982X_MSK_FAULT_RST3_RST_MEM_DATA             (0x01u)

/* --------------------------------------------------------------------------
 * OTP_ECC_TEST                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_ECC_TEST_OFFSET                        (0x0298u)
#define BQ7982X_OTP_ECC_TEST_POR_VAL                       (0x00u)


#define BQ7982X_OTP_ECC_TEST_DED_SEC_POS                   (0x02u)
#define BQ7982X_OTP_ECC_TEST_DED_SEC_MSK                   (0x04u)

#define BQ7982X_OTP_ECC_TEST_ENC_DEC_POS                   (0x01u)
#define BQ7982X_OTP_ECC_TEST_ENC_DEC_MSK                   (0x02u)

#define BQ7982X_OTP_ECC_TEST_ENABLE_POS                    (0x00u)
#define BQ7982X_OTP_ECC_TEST_ENABLE_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * I2C_WR_DATA                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_I2C_WR_DATA_OFFSET                        (0x02A0u)
#define BQ7982X_I2C_WR_DATA_POR_VAL                       (0x00u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_7                (0x07u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_7                (0x80u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_6                (0x06u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_6                (0x40u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_5                (0x05u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_5                (0x20u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_4                (0x04u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_4                (0x10u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_3                (0x03u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_3                (0x08u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_2                (0x02u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_2                (0x04u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_1                (0x01u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_1                (0x02u)

#define BQ7982X_POS_I2C_WR_DATA_DATA_BIT_0                (0x00u)
#define BQ7982X_MSK_I2C_WR_DATA_DATA_BIT_0                (0x01u)

/* --------------------------------------------------------------------------
 * I2C_CTRL                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_I2C_CTRL_OFFSET                        (0x02A1u)
#define BQ7982X_I2C_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_I2C_CTRL_RSVD_BIT_7_POS                (0x07u)
#define BQ7982X_I2C_CTRL_RSVD_BIT_7_MSK                (0x80u)

#define BQ7982X_I2C_CTRL_RSVD_BIT_6_POS                (0x06u)
#define BQ7982X_I2C_CTRL_RSVD_BIT_6_MSK                (0x40u)

#define BQ7982X_I2C_CTRL_SEND_POS                      (0x05u)
#define BQ7982X_I2C_CTRL_SEND_MSK                      (0x20u)

#define BQ7982X_I2C_CTRL_RECEIVE_POS                   (0x04u)
#define BQ7982X_I2C_CTRL_RECEIVE_MSK                   (0x10u)

#define BQ7982X_I2C_CTRL_START_POS                     (0x03u)
#define BQ7982X_I2C_CTRL_START_MSK                     (0x08u)

#define BQ7982X_I2C_CTRL_STOP_POS                      (0x02u)
#define BQ7982X_I2C_CTRL_STOP_MSK                      (0x04u)

#define BQ7982X_I2C_CTRL_NACK_POS                      (0x01u)
#define BQ7982X_I2C_CTRL_NACK_MSK                      (0x02u)

#define BQ7982X_I2C_CTRL_I2C_GO_POS                    (0x00u)
#define BQ7982X_I2C_CTRL_I2C_GO_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * CSPI_CTRL                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_CTRL_OFFSET                        (0x02B0u)
#define BQ7982X_CSPI_CTRL_POR_VAL                       (0x00u)

#define BQ7982X_CSPI_CTRL_CPOL_POS                      (0x06u)
#define BQ7982X_CSPI_CTRL_CPOL_MSK                      (0x40u)

#define BQ7982X_CSPI_CTRL_CPHA_POS                      (0x05u)
#define BQ7982X_CSPI_CTRL_CPHA_MSK                      (0x20u)

#define BQ7982X_POS_CSPI_CTRL_NUMBIT_BIT_4              (0x04u)
#define BQ7982X_MSK_CSPI_CTRL_NUMBIT_BIT_4              (0x10u)

#define BQ7982X_POS_CSPI_CTRL_NUMBIT_BIT_3              (0x03u)
#define BQ7982X_MSK_CSPI_CTRL_NUMBIT_BIT_3              (0x08u)

#define BQ7982X_POS_CSPI_CTRL_NUMBIT_BIT_2              (0x02u)
#define BQ7982X_MSK_CSPI_CTRL_NUMBIT_BIT_2              (0x04u)

#define BQ7982X_POS_CSPI_CTRL_NUMBIT_BIT_1              (0x01u)
#define BQ7982X_MSK_CSPI_CTRL_NUMBIT_BIT_1              (0x02u)

#define BQ7982X_POS_CSPI_CTRL_NUMBIT_BIT_0              (0x00u)
#define BQ7982X_MSK_CSPI_CTRL_NUMBIT_BIT_0              (0x01u)

/* --------------------------------------------------------------------------
 * CSPI_TX4                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_TX4_OFFSET                         (0x02B1u)
#define BQ7982X_CSPI_TX4_POR_VAL                        (0x00u)

#define BQ7982X_CSPI_TX4_DATA_BIT_7_POS                 (0x07u)
#define BQ7982X_CSPI_TX4_DATA_BIT_7_MSK                 (0x80u)

#define BQ7982X_CSPI_TX4_DATA_BIT_6_POS                 (0x06u)
#define BQ7982X_CSPI_TX4_DATA_BIT_6_MSK                 (0x40u)

#define BQ7982X_CSPI_TX4_DATA_BIT_5_POS                 (0x05u)
#define BQ7982X_CSPI_TX4_DATA_BIT_5_MSK                 (0x20u)

#define BQ7982X_CSPI_TX4_DATA_BIT_4_POS                 (0x04u)
#define BQ7982X_CSPI_TX4_DATA_BIT_4_MSK                 (0x10u)

#define BQ7982X_CSPI_TX4_DATA_BIT_3_POS                 (0x03u)
#define BQ7982X_CSPI_TX4_DATA_BIT_3_MSK                 (0x08u)

#define BQ7982X_CSPI_TX4_DATA_BIT_2_POS                 (0x02u)
#define BQ7982X_CSPI_TX4_DATA_BIT_2_MSK                 (0x04u)

#define BQ7982X_CSPI_TX4_DATA_BIT_1_POS                 (0x01u)
#define BQ7982X_CSPI_TX4_DATA_BIT_1_MSK                 (0x02u)

#define BQ7982X_CSPI_TX4_DATA_BIT_0_POS                 (0x00u)
#define BQ7982X_CSPI_TX4_DATA_BIT_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * CSPI_TX3                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_TX3_OFFSET                         (0x02B2u)
#define BQ7982X_CSPI_TX3_POR_VAL                        (0x00u)

#define BQ7982X_CSPI_TX3_DATA_BIT_7_POS                 (0x07u)
#define BQ7982X_CSPI_TX3_DATA_BIT_7_MSK                 (0x80u)

#define BQ7982X_CSPI_TX3_DATA_BIT_6_POS                 (0x06u)
#define BQ7982X_CSPI_TX3_DATA_BIT_6_MSK                 (0x40u)

#define BQ7982X_CSPI_TX3_DATA_BIT_5_POS                 (0x05u)
#define BQ7982X_CSPI_TX3_DATA_BIT_5_MSK                 (0x20u)

#define BQ7982X_CSPI_TX3_DATA_BIT_4_POS                 (0x04u)
#define BQ7982X_CSPI_TX3_DATA_BIT_4_MSK                 (0x10u)

#define BQ7982X_CSPI_TX3_DATA_BIT_3_POS                 (0x03u)
#define BQ7982X_CSPI_TX3_DATA_BIT_3_MSK                 (0x08u)

#define BQ7982X_CSPI_TX3_DATA_BIT_2_POS                 (0x02u)
#define BQ7982X_CSPI_TX3_DATA_BIT_2_MSK                 (0x04u)

#define BQ7982X_CSPI_TX3_DATA_BIT_1_POS                 (0x01u)
#define BQ7982X_CSPI_TX3_DATA_BIT_1_MSK                 (0x02u)

#define BQ7982X_CSPI_TX3_DATA_BIT_0_POS                 (0x00u)
#define BQ7982X_CSPI_TX3_DATA_BIT_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * CSPI_TX2                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_TX2_OFFSET                         (0x02B3u)
#define BQ7982X_CSPI_TX2_POR_VAL                        (0x00u)

#define BQ7982X_CSPI_TX2_DATA_BIT_7_POS                 (0x07u)
#define BQ7982X_CSPI_TX2_DATA_BIT_7_MSK                 (0x80u)

#define BQ7982X_CSPI_TX2_DATA_BIT_6_POS                 (0x06u)
#define BQ7982X_CSPI_TX2_DATA_BIT_6_MSK                 (0x40u)

#define BQ7982X_CSPI_TX2_DATA_BIT_5_POS                 (0x05u)
#define BQ7982X_CSPI_TX2_DATA_BIT_5_MSK                 (0x20u)

#define BQ7982X_CSPI_TX2_DATA_BIT_4_POS                 (0x04u)
#define BQ7982X_CSPI_TX2_DATA_BIT_4_MSK                 (0x10u)

#define BQ7982X_CSPI_TX2_DATA_BIT_3_POS                 (0x03u)
#define BQ7982X_CSPI_TX2_DATA_BIT_3_MSK                 (0x08u)

#define BQ7982X_CSPI_TX2_DATA_BIT_2_POS                 (0x02u)
#define BQ7982X_CSPI_TX2_DATA_BIT_2_MSK                 (0x04u)

#define BQ7982X_CSPI_TX2_DATA_BIT_1_POS                 (0x01u)
#define BQ7982X_CSPI_TX2_DATA_BIT_1_MSK                 (0x02u)

#define BQ7982X_CSPI_TX2_DATA_BIT_0_POS                 (0x00u)
#define BQ7982X_CSPI_TX2_DATA_BIT_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * CSPI_TX1                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_TX1_OFFSET                         (0x02B4u)
#define BQ7982X_CSPI_TX1_POR_VAL                        (0x00u)

#define BQ7982X_CSPI_TX1_DATA_BIT_7_POS                 (0x07u)
#define BQ7982X_CSPI_TX1_DATA_BIT_7_MSK                 (0x80u)

#define BQ7982X_CSPI_TX1_DATA_BIT_6_POS                 (0x06u)
#define BQ7982X_CSPI_TX1_DATA_BIT_6_MSK                 (0x40u)

#define BQ7982X_CSPI_TX1_DATA_BIT_5_POS                 (0x05u)
#define BQ7982X_CSPI_TX1_DATA_BIT_5_MSK                 (0x20u)

#define BQ7982X_CSPI_TX1_DATA_BIT_4_POS                 (0x04u)
#define BQ7982X_CSPI_TX1_DATA_BIT_4_MSK                 (0x10u)

#define BQ7982X_CSPI_TX1_DATA_BIT_3_POS                 (0x03u)
#define BQ7982X_CSPI_TX1_DATA_BIT_3_MSK                 (0x08u)

#define BQ7982X_CSPI_TX1_DATA_BIT_2_POS                 (0x02u)
#define BQ7982X_CSPI_TX1_DATA_BIT_2_MSK                 (0x04u)

#define BQ7982X_CSPI_TX1_DATA_BIT_1_POS                 (0x01u)
#define BQ7982X_CSPI_TX1_DATA_BIT_1_MSK                 (0x02u)

#define BQ7982X_CSPI_TX1_DATA_BIT_0_POS                 (0x00u)
#define BQ7982X_CSPI_TX1_DATA_BIT_0_MSK                 (0x01u)

/* --------------------------------------------------------------------------
 * CSPI_EXE                (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_EXE_OFFSET                         (0x02B5u)
#define BQ7982X_CSPI_EXE_POR_VAL                        (0x02u)


#define BQ7982X_POS_CSPI_EXE_CCS_ADDR_BIT_2             (0x05u)
#define BQ7982X_MSK_CSPI_EXE_CCS_ADDR_BIT_2             (0x20u)

#define BQ7982X_POS_CSPI_EXE_CCS_ADDR_BIT_1             (0x04u)
#define BQ7982X_MSK_CSPI_EXE_CCS_ADDR_BIT_1             (0x10u)

#define BQ7982X_POS_CSPI_EXE_CCS_ADDR_BIT_0             (0x03u)
#define BQ7982X_MSK_CSPI_EXE_CCS_ADDR_BIT_0             (0x08u)

#define BQ7982X_POS_CSPI_EXE_CCS_CTRL_BIT_1             (0x02u)
#define BQ7982X_MSK_CSPI_EXE_CCS_CTRL_BIT_1             (0x04u)

#define BQ7982X_POS_CSPI_EXE_CCS_CTRL_BIT_0             (0x01u)
#define BQ7982X_MSK_CSPI_EXE_CCS_CTRL_BIT_0             (0x02u)

#define BQ7982X_CSPI_EXE_CSPI_GO_POS                    (0x00u)
#define BQ7982X_CSPI_EXE_CSPI_GO_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_OUT1                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_OUT1_OFFSET                        (0x02C0u)
#define BQ7982X_GPIO_OUT1_POR_VAL                       (0x00u)

#define BQ7982X_GPIO_OUT1_GPIO8_POS                     (0x07u)
#define BQ7982X_GPIO_OUT1_GPIO8_MSK                     (0x80u)

#define BQ7982X_GPIO_OUT1_GPIO7_POS                     (0x06u)
#define BQ7982X_GPIO_OUT1_GPIO7_MSK                     (0x40u)

#define BQ7982X_GPIO_OUT1_GPIO6_POS                     (0x05u)
#define BQ7982X_GPIO_OUT1_GPIO6_MSK                     (0x20u)

#define BQ7982X_GPIO_OUT1_GPIO5_POS                     (0x04u)
#define BQ7982X_GPIO_OUT1_GPIO5_MSK                     (0x10u)

#define BQ7982X_GPIO_OUT1_GPIO4_POS                     (0x03u)
#define BQ7982X_GPIO_OUT1_GPIO4_MSK                     (0x08u)

#define BQ7982X_GPIO_OUT1_GPIO3_POS                     (0x02u)
#define BQ7982X_GPIO_OUT1_GPIO3_MSK                     (0x04u)

#define BQ7982X_GPIO_OUT1_GPIO2_POS                     (0x01u)
#define BQ7982X_GPIO_OUT1_GPIO2_MSK                     (0x02u)

#define BQ7982X_GPIO_OUT1_GPIO1_POS                     (0x00u)
#define BQ7982X_GPIO_OUT1_GPIO1_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_OUT2                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_OUT2_OFFSET                        (0x02C1u)
#define BQ7982X_GPIO_OUT2_POR_VAL                       (0x00u)

#define BQ7982X_GPIO_OUT2_GPIO16_POS                    (0x07u)
#define BQ7982X_GPIO_OUT2_GPIO16_MSK                    (0x80u)

#define BQ7982X_GPIO_OUT2_GPIO15_POS                    (0x06u)
#define BQ7982X_GPIO_OUT2_GPIO15_MSK                    (0x40u)

#define BQ7982X_GPIO_OUT2_GPIO14_POS                    (0x05u)
#define BQ7982X_GPIO_OUT2_GPIO14_MSK                    (0x20u)

#define BQ7982X_GPIO_OUT2_GPIO13_POS                    (0x04u)
#define BQ7982X_GPIO_OUT2_GPIO13_MSK                    (0x10u)

#define BQ7982X_GPIO_OUT2_GPIO12_POS                    (0x03u)
#define BQ7982X_GPIO_OUT2_GPIO12_MSK                    (0x08u)

#define BQ7982X_GPIO_OUT2_GPIO11_POS                    (0x02u)
#define BQ7982X_GPIO_OUT2_GPIO11_MSK                    (0x04u)

#define BQ7982X_GPIO_OUT2_GPIO10_POS                    (0x01u)
#define BQ7982X_GPIO_OUT2_GPIO10_MSK                    (0x02u)

#define BQ7982X_GPIO_OUT2_GPIO9_POS                     (0x00u)
#define BQ7982X_GPIO_OUT2_GPIO9_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_OUT3                (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_OUT3_OFFSET                        (0x02C2u)
#define BQ7982X_GPIO_OUT3_POR_VAL                       (0x00u)

#define BQ7982X_GPIO_OUT3_GPIO20_POS                    (0x03u)
#define BQ7982X_GPIO_OUT3_GPIO20_MSK                    (0x08u)

#define BQ7982X_GPIO_OUT3_GPIO19_POS                    (0x02u)
#define BQ7982X_GPIO_OUT3_GPIO19_MSK                    (0x04u)

#define BQ7982X_GPIO_OUT3_GPIO18_POS                    (0x01u)
#define BQ7982X_GPIO_OUT3_GPIO18_MSK                    (0x02u)

#define BQ7982X_GPIO_OUT3_GPIO17_POS                    (0x00u)
#define BQ7982X_GPIO_OUT3_GPIO17_MSK                    (0x01u)

/* --------------------------------------------------------------------------
 * EIS_DISABLE1            (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DISABLE1_OFFSET                    (0x0500u)
#define BQ7982X_EIS_DISABLE1_POR_VAL                   (0x00u)

#define BQ7982X_EIS_DISABLE1_CELL_8_POS                     (0x07u)
#define BQ7982X_EIS_DISABLE1_CELL_8_MSK                     (0x80u)

#define BQ7982X_EIS_DISABLE1_CELL_7_POS                     (0x06u)
#define BQ7982X_EIS_DISABLE1_CELL_7_MSK                     (0x40u)

#define BQ7982X_EIS_DISABLE1_CELL_6_POS                     (0x05u)
#define BQ7982X_EIS_DISABLE1_CELL_6_MSK                     (0x20u)

#define BQ7982X_EIS_DISABLE1_CELL_5_POS                     (0x04u)
#define BQ7982X_EIS_DISABLE1_CELL_5_MSK                     (0x10u)

#define BQ7982X_EIS_DISABLE1_CELL_4_POS                     (0x03u)
#define BQ7982X_EIS_DISABLE1_CELL_4_MSK                     (0x08u)

#define BQ7982X_EIS_DISABLE1_CELL_3_POS                     (0x02u)
#define BQ7982X_EIS_DISABLE1_CELL_3_MSK                     (0x04u)

#define BQ7982X_EIS_DISABLE1_CELL_2_POS                     (0x01u)
#define BQ7982X_EIS_DISABLE1_CELL_2_MSK                     (0x02u)

#define BQ7982X_EIS_DISABLE1_CELL_1_POS                     (0x00u)
#define BQ7982X_EIS_DISABLE1_CELL_1_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * EIS_DISABLE2            (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DISABLE2_OFFSET                    (0x0501u)
#define BQ7982X_EIS_DISABLE2_POR_VAL                   (0x00u)

#define BQ7982X_EIS_DISABLE2_CELL_16_POS                     (0x07u)
#define BQ7982X_EIS_DISABLE2_CELL_16_MSK                     (0x80u)

#define BQ7982X_EIS_DISABLE2_CELL_15_POS                     (0x06u)
#define BQ7982X_EIS_DISABLE2_CELL_15_MSK                     (0x40u)

#define BQ7982X_EIS_DISABLE2_CELL_14_POS                     (0x05u)
#define BQ7982X_EIS_DISABLE2_CELL_14_MSK                     (0x20u)

#define BQ7982X_EIS_DISABLE2_CELL_13_POS                     (0x04u)
#define BQ7982X_EIS_DISABLE2_CELL_13_MSK                     (0x10u)

#define BQ7982X_EIS_DISABLE2_CELL_12_POS                     (0x03u)
#define BQ7982X_EIS_DISABLE2_CELL_12_MSK                     (0x08u)

#define BQ7982X_EIS_DISABLE2_CELL_11_POS                     (0x02u)
#define BQ7982X_EIS_DISABLE2_CELL_11_MSK                     (0x04u)

#define BQ7982X_EIS_DISABLE2_CELL_10_POS                     (0x01u)
#define BQ7982X_EIS_DISABLE2_CELL_10_MSK                     (0x02u)

#define BQ7982X_EIS_DISABLE2_CELL_9_POS                     (0x00u)
#define BQ7982X_EIS_DISABLE2_CELL_9_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * EIS_DISABLE3            (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DISABLE3_OFFSET                    (0x0502u)
#define BQ7982X_EIS_DISABLE3_POR_VAL                   (0x00u)

#define BQ7982X_EIS_DISABLE3_CELL_24_POS                     (0x07u)
#define BQ7982X_EIS_DISABLE3_CELL_24_MSK                     (0x80u)

#define BQ7982X_EIS_DISABLE3_CELL_23_POS                     (0x06u)
#define BQ7982X_EIS_DISABLE3_CELL_23_MSK                     (0x40u)

#define BQ7982X_EIS_DISABLE3_CELL_22_POS                     (0x05u)
#define BQ7982X_EIS_DISABLE3_CELL_22_MSK                     (0x20u)

#define BQ7982X_EIS_DISABLE3_CELL_21_POS                     (0x04u)
#define BQ7982X_EIS_DISABLE3_CELL_21_MSK                     (0x10u)

#define BQ7982X_EIS_DISABLE3_CELL_20_POS                     (0x03u)
#define BQ7982X_EIS_DISABLE3_CELL_20_MSK                     (0x08u)

#define BQ7982X_EIS_DISABLE3_CELL_19_POS                     (0x02u)
#define BQ7982X_EIS_DISABLE3_CELL_19_MSK                     (0x04u)

#define BQ7982X_EIS_DISABLE3_CELL_18_POS                     (0x01u)
#define BQ7982X_EIS_DISABLE3_CELL_18_MSK                     (0x02u)

#define BQ7982X_EIS_DISABLE3_CELL_17_POS                     (0x00u)
#define BQ7982X_EIS_DISABLE3_CELL_17_MSK                     (0x01u)
/* --------------------------------------------------------------------------
 * EIS_DISABLE4            (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DISABLE4_OFFSET                    (0x0503u)
#define BQ7982X_EIS_DISABLE4_POR_VAL                   (0x00u)

#define BQ7982X_EIS_DISABLE3_CELL_26_POS                     (0x01u)
#define BQ7982X_EIS_DISABLE3_CELL_26_MSK                     (0x02u)

#define BQ7982X_EIS_DISABLE3_CELL_25_POS                     (0x00u)
#define BQ7982X_EIS_DISABLE3_CELL_25_MSK                     (0x01u)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL1_OFFSET                   (0x0510u)
#define BQ7982X_EIS_COM_CTRL1_POR_VAL                  (0x00u)

#define BQ7982X_EIS_COM_CTRL1_CS_MODE_POS              (0x03u)
#define BQ7982X_EIS_COM_CTRL1_CS_MODE_MSK              (0x08u)

#define BQ7982X_POS_EIS_COM_CTRL1_NUM_TONES            (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL1_NUM_TONES            (0x07u)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL2_OFFSET                   (0x0511u)
#define BQ7982X_EIS_COM_CTRL2_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL2_DFT_LENH             (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL2_DFT_LENH             (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL3           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL3_OFFSET                   (0x0512u)
#define BQ7982X_EIS_COM_CTRL3_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL3_DFT_LENM             (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL3_DFT_LENM             (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL4           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL4_OFFSET                   (0x0513u)
#define BQ7982X_EIS_COM_CTRL4_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL4_DFT_LENL             (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL4_DFT_LENL             (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL5           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL5_OFFSET                   (0x0514u)
#define BQ7982X_EIS_COM_CTRL5_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL5_FREQ_IDX1H           (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL5_FREQ_IDX1H           (0x07u)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL6           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL6_OFFSET                   (0x0515u)
#define BQ7982X_EIS_COM_CTRL6_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL6_FREQ_IDX1M           (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL6_FREQ_IDX1M           (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL7           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL7_OFFSET                   (0x0516u)
#define BQ7982X_EIS_COM_CTRL7_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL7_FREQ_IDX1L           (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL7_FREQ_IDX1L           (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL8           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL8_OFFSET                   (0x0517u)
#define BQ7982X_EIS_COM_CTRL8_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL8_FREQ_IDX2H           (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL8_FREQ_IDX2H           (0x07u)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL9           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL9_OFFSET                   (0x0518u)
#define BQ7982X_EIS_COM_CTRL9_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL9_FREQ_IDX2M           (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL9_FREQ_IDX2M           (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL10           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL10_OFFSET                  (0x0519u)
#define BQ7982X_EIS_COM_CTRL10_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL10_FREQ_IDX2L          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL10_FREQ_IDX2L          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL11           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL11_OFFSET                  (0x051Au)
#define BQ7982X_EIS_COM_CTRL11_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL11_FREQ_IDX3H          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL11_FREQ_IDX3H          (0x07u)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL12           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL12_OFFSET                  (0x051Bu)
#define BQ7982X_EIS_COM_CTRL12_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL12_FREQ_IDX3M          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL12_FREQ_IDX3M          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL13           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL13_OFFSET                  (0x051Cu)
#define BQ7982X_EIS_COM_CTRL13_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL13_FREQ_IDX3L          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL13_FREQ_IDX3L          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL14           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL14_OFFSET                  (0x051Du)
#define BQ7982X_EIS_COM_CTRL14_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL14_FREQ_IDX4H          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL14_FREQ_IDX4H          (0x07u)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL15           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL15_OFFSET                  (0x051Eu)
#define BQ7982X_EIS_COM_CTRL15_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL15_FREQ_IDX4M          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL15_FREQ_IDX4M          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL16           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL16_OFFSET                  (0x051Fu)
#define BQ7982X_EIS_COM_CTRL16_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL16_FREQ_IDX4L          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL16_FREQ_IDX4L          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL17           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL17_OFFSET                  (0x0520u)
#define BQ7982X_EIS_COM_CTRL17_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL17_FREQ_IDX5H          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL17_FREQ_IDX5H          (0x07u)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL18           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL18_OFFSET                  (0x0521u)
#define BQ7982X_EIS_COM_CTRL18_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_COM_CTRL18_FREQ_IDX5M          (0x00u)
#define BQ7982X_MSK_EIS_COM_CTRL18_FREQ_IDX5M          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_COM_CTRL19           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_COM_CTRL19_OFFSET                  (0x0522u)
#define BQ7982X_EIS_COM_CTRL19_POR_VAL                 (0x00u)

#define BQ7982X_EIS_COM_CTRL19_FREQ_IDX5L_POS          (0x00u)
#define BQ7982X_EIS_COM_CTRL19_FREQ_IDX5L_MSK          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL1_OFFSET                   (0x0540u)
#define BQ7982X_EIS_DFE_CTRL1_POR_VAL                  (0x00u)

#define BQ7982X_EIS_DFE_CTRL1_VC_AMPH_POS              (0x00u)
#define BQ7982X_EIS_DFE_CTRL1_VC_AMPH_MSK              (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL2_OFFSET                   (0x0541u)
#define BQ7982X_EIS_DFE_CTRL2_POR_VAL                  (0x00u)

#define BQ7982X_EIS_DFE_CTRL2_VC_AMPL_POS              (0x00u)
#define BQ7982X_EIS_DFE_CTRL2_VC_AMPL_MSK              (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL3           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL3_OFFSET                   (0x0542u)
#define BQ7982X_EIS_DFE_CTRL3_POR_VAL                  (0x00u)

#define BQ7982X_EIS_DFE_CTRL3_CS_AMPH_POS              (0x00u)
#define BQ7982X_EIS_DFE_CTRL3_CS_AMPH_MSK              (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL4           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL4_OFFSET                   (0x0543u)
#define BQ7982X_EIS_DFE_CTRL4_POR_VAL                  (0x00u)

#define BQ7982X_EIS_DFE_CTRL4_CS_AMPL_POS              (0x00u)
#define BQ7982X_EIS_DFE_CTRL4_CS_AMPL_MSK              (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL5           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL5_OFFSET                   (0x0544u)
#define BQ7982X_EIS_DFE_CTRL5_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL5_HPF_COEFH            (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL5_HPF_COEFH            (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL6           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL6_OFFSET                   (0x0545u)
#define BQ7982X_EIS_DFE_CTRL6_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL6_HPF_COEFM            (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL6_HPF_COEFM            (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL7           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL7_OFFSET                   (0x0546u)
#define BQ7982X_EIS_DFE_CTRL7_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL7_HPF_COEFL            (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL7_HPF_COEFL            (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL8           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL8_OFFSET                   (0x0547u)
#define BQ7982X_EIS_DFE_CTRL8_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL8_VC_DCC_SCALEH        (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL8_VC_DCC_SCALEH        (0x1Fu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL9           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL9_OFFSET                   (0x0548u)
#define BQ7982X_EIS_DFE_CTRL9_POR_VAL                  (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL9_VC_DCC_SCALEM        (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL9_VC_DCC_SCALEM        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL10           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL10_OFFSET                  (0x0549u)
#define BQ7982X_EIS_DFE_CTRL10_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL10_VC_DCC_SCALEL       (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL10_VC_DCC_SCALEL       (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL11           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL11_OFFSET                  (0x054Au)
#define BQ7982X_EIS_DFE_CTRL11_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL11_VC_DCC_LPFH         (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL11_VC_DCC_LPFH         (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL12           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL12_OFFSET                  (0x054Bu)
#define BQ7982X_EIS_DFE_CTRL12_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL12_VC_DCC_LPFM         (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL12_VC_DCC_LPFM         (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL13           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL13_OFFSET                  (0x054Cu)
#define BQ7982X_EIS_DFE_CTRL13_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL13_VC_DCC_LPFL         (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL13_VC_DCC_LPFL         (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL14           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL14_OFFSET                  (0x054Du)
#define BQ7982X_EIS_DFE_CTRL14_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL14_VC_DCC_DCH          (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL14_VC_DCC_DCH          (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL15           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL15_OFFSET                  (0x054Eu)
#define BQ7982X_EIS_DFE_CTRL15_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL15_VC_DCC_DCM          (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL15_VC_DCC_DCM          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL16           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL16_OFFSET                  (0x054Fu)
#define BQ7982X_EIS_DFE_CTRL16_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL16_VC_DCC_DCL          (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL16_VC_DCC_DCL          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL17           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL17_OFFSET                  (0x0550u)
#define BQ7982X_EIS_DFE_CTRL17_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL17_CS_DCC_SCALEH       (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL17_CS_DCC_SCALEH       (0x1Fu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL18           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL18_OFFSET                  (0x0551u)
#define BQ7982X_EIS_DFE_CTRL18_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL18_CS_DCC_SCALEM       (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL18_CS_DCC_SCALEM       (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL19           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL19_OFFSET                  (0x0552u)
#define BQ7982X_EIS_DFE_CTRL19_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL19_CS_DCC_SCALEL       (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL19_CS_DCC_SCALEL       (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL20           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL20_OFFSET                  (0x0553u)
#define BQ7982X_EIS_DFE_CTRL20_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL20_CS_DCC_LPFH         (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL20_CS_DCC_LPFH         (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL21           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL21_OFFSET                  (0x0554u)
#define BQ7982X_EIS_DFE_CTRL21_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL21_CS_DCC_LPFM         (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL21_CS_DCC_LPFM         (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL22           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL22_OFFSET                  (0x0555u)
#define BQ7982X_EIS_DFE_CTRL22_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL22_CS_DCC_LPFL         (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL22_CS_DCC_LPFL         (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL23           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL23_OFFSET                  (0x0556u)
#define BQ7982X_EIS_DFE_CTRL23_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL23_CS_DCC_DCH          (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL23_CS_DCC_DCH          (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL24           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL24_OFFSET                  (0x0557u)
#define BQ7982X_EIS_DFE_CTRL24_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL24_CS_DCC_DCM          (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL24_CS_DCC_DCM          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL25           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL25_OFFSET                  (0x0558u)
#define BQ7982X_EIS_DFE_CTRL25_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL25_CS_DCC_DCL          (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL25_CS_DCC_DCL          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFE_CTRL26           (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFE_CTRL26_OFFSET                  (0x0559u)
#define BQ7982X_EIS_DFE_CTRL26_POR_VAL                 (0x00u)

#define BQ7982X_POS_EIS_DFE_CTRL26_HPF_MODE            (0x07u)
#define BQ7982X_MSK_EIS_DFE_CTRL26_HPF_MODE            (0x80u)

#define BQ7982X_POS_EIS_DFE_CTRL26_EIS_DSR             (0x03u)
#define BQ7982X_MSK_EIS_DFE_CTRL26_EIS_DSR             (0x78u)

#define BQ7982X_POS_EIS_DFE_CTRL26_EIS_DFE_MODE        (0x01u)
#define BQ7982X_MSK_EIS_DFE_CTRL26_EIS_DFE_MODE        (0x06u)

#define BQ7982X_POS_EIS_DFE_CTRL26_EIS_DFE_GO          (0x00u)
#define BQ7982X_MSK_EIS_DFE_CTRL26_EIS_DFE_GO          (0x01u)

/* --------------------------------------------------------------------------
 * EIS_DFT_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */

#define BQ7982X_EIS_DFT_CTRL1_OFFSET            (0x0570u)
#define BQ7982X_EIS_DFT_CTRL1_POR_VAL           (0x00u)

#define BQ7982X_EIS_DFT_CTRL1_PHASEH_POS        (0x00u)
#define BQ7982X_EIS_DFT_CTRL1_PHASEH_MSK        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFT_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFT_CTRL2_OFFSET            (0x0571u)
#define BQ7982X_EIS_DFT_CTRL2_POR_VAL           (0x00u)

#define BQ7982X_EIS_DFT_CTRL2_PHASEM_POS        (0x00u)
#define BQ7982X_EIS_DFT_CTRL2_PHASEM_MSK        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFT_CTRL3           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFT_CTRL3_OFFSET            (0x0572u)
#define BQ7982X_EIS_DFT_CTRL3_POR_VAL           (0x00u)

#define BQ7982X_EIS_DFT_CTRL3_PHASEL_POS        (0x00u)
#define BQ7982X_EIS_DFT_CTRL3_PHASEL_MSK        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_DFT_CTRL4           (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_DFT_CTRL4_OFFSET            (0x0573u)
#define BQ7982X_EIS_DFT_CTRL4_POR_VAL           (0x00u)

#define BQ7982X_POS_EIS_DFT_CTRL4_WINDOW_DIS    (0x04u)
#define BQ7982X_MSK_EIS_DFT_CTRL4_WINDOW_DIS    (0x10u)

#define BQ7982X_POS_EIS_DFT_CTRL4_PHASE_MODE    (0x03u)
#define BQ7982X_MSK_EIS_DFT_CTRL4_PHASE_MODE    (0x08u)

#define BQ7982X_POS_EIS_DFT_CTRL4_EIS_DFT_MODE  (0x01u)
#define BQ7982X_MSK_EIS_DFT_CTRL4_EIS_DFT_MODE  (0x06u)

#define BQ7982X_POS_EIS_DFT_CTRL4_EIS_DFT_GO    (0x00u)
#define BQ7982X_MSK_EIS_DFT_CTRL4_EIS_DFT_GO    (0x01u)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */

#define BQ7982X_EIS_PWM_CTRL1_OFFSET            (0x0580u)
#define BQ7982X_EIS_PWM_CTRL1_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL1_AMP1_POS          (0x00u)
#define BQ7982X_EIS_PWM_CTRL1_AMP1_MSK          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL2_OFFSET            (0x0581u)
#define BQ7982X_EIS_PWM_CTRL2_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL2_AMP2_POS          (0x00u)
#define BQ7982X_EIS_PWM_CTRL2_AMP2_MSK          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL3           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL3_OFFSET            (0x0582u)
#define BQ7982X_EIS_PWM_CTRL3_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL3_AMP3_POS          (0x00u)
#define BQ7982X_EIS_PWM_CTRL3_AMP3_MSK          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL4           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL4_OFFSET            (0x0583u)
#define BQ7982X_EIS_PWM_CTRL4_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL4_AMP4_POS          (0x00u)
#define BQ7982X_EIS_PWM_CTRL4_AMP4_MSK          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL5           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL5_OFFSET            (0x0584u)
#define BQ7982X_EIS_PWM_CTRL5_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL5_AMP5_POS          (0x00u)
#define BQ7982X_EIS_PWM_CTRL5_AMP5_MSK          (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL6           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL6_OFFSET            (0x0585u)
#define BQ7982X_EIS_PWM_CTRL6_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL6_PHASE1_POS        (0x00u)
#define BQ7982X_EIS_PWM_CTRL6_PHASE1_MSK        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL7           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL7_OFFSET            (0x0586u)
#define BQ7982X_EIS_PWM_CTRL7_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL7_PHASE2_POS        (0x00u)
#define BQ7982X_EIS_PWM_CTRL7_PHASE2_MSK        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL8           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL8_OFFSET            (0x0587u)
#define BQ7982X_EIS_PWM_CTRL8_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL8_PHASE3_POS        (0x00u)
#define BQ7982X_EIS_PWM_CTRL8_PHASE3_MSK        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL9           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL9_OFFSET            (0x0588u)
#define BQ7982X_EIS_PWM_CTRL9_POR_VAL           (0x00u)

#define BQ7982X_EIS_PWM_CTRL9_PHASE4_POS        (0x00u)
#define BQ7982X_EIS_PWM_CTRL9_PHASE4_MSK        (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL10           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL10_OFFSET           (0x0589u)
#define BQ7982X_EIS_PWM_CTRL10_POR_VAL          (0x00u)

#define BQ7982X_EIS_PWM_CTRL10_PHASE5_POS       (0x00u)
#define BQ7982X_EIS_PWM_CTRL10_PHASE5_MSK       (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL11           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL11_OFFSET           (0x058Au)
#define BQ7982X_EIS_PWM_CTRL11_POR_VAL          (0x00u)

#define BQ7982X_POS_EIS_PWM_CTRL11_DC_SHIFTH    (0x00u)
#define BQ7982X_MSK_EIS_PWM_CTRL11_DC_SHIFTH    (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL12           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL12_OFFSET           (0x058Bu)
#define BQ7982X_EIS_PWM_CTRL12_POR_VAL          (0x00u)

#define BQ7982X_POS_EIS_PWM_CTRL12_DC_SHIFTL    (0x00u)
#define BQ7982X_MSK_EIS_PWM_CTRL12_DC_SHIFTL    (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL13           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL13_OFFSET           (0x058Cu)
#define BQ7982X_EIS_PWM_CTRL13_POR_VAL          (0x00u)

#define BQ7982X_POS_EIS_PWM_CTRL13_PWM_DIVISORH (0x00u)
#define BQ7982X_MSK_EIS_PWM_CTRL13_PWM_DIVISORH (0x0Fu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL14           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL14_OFFSET           (0x058Du)
#define BQ7982X_EIS_PWM_CTRL14_POR_VAL          (0x00u)

#define BQ7982X_POS_EIS_PWM_CTRL14_PWM_DIVISORL (0x00u)
#define BQ7982X_MSK_EIS_PWM_CTRL14_PWM_DIVISORL (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_PWM_CTRL15           (R/W-AC):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_PWM_CTRL15_OFFSET           (0x058Eu)
#define BQ7982X_EIS_PWM_CTRL15_POR_VAL          (0x00u)

#define BQ7982X_POS_EIS_PWM_CTRL15_EIS_PWM_MODE (0x01u)
#define BQ7982X_MSK_EIS_PWM_CTRL15_EIS_PWM_MODE (0x06u)

#define BQ7982X_POS_EIS_PWM_CTRL15_EIS_PWM_GO   (0x00u)
#define BQ7982X_MSK_EIS_PWM_CTRL15_EIS_PWM_GO   (0x01u)

/* --------------------------------------------------------------------------
 * EIS_MISC_CTRL           (R/W):
 * -------------------------------------------------------------------------- */
 
#define BQ7982X_EIS_MISC_CTRL_OFFSET           (0x05A0u)
#define BQ7982X_EIS_MISC_CTRL_POR_VAL          (0x00u)

#define BQ7982X_POS_EIS_MISC_CTRL_EIS_RES_SEL  (0x03u)
#define BQ7982X_MSK_EIS_MISC_CTRL_EIS_RES_SEL  (0x08u)

#define BQ7982X_POS_EIS_MISC_CTRL_EIS_RES_TONE (0x00u)
#define BQ7982X_MSK_EIS_MISC_CTRL_EIS_RES_TONE (0x07u)

/* --------------------------------------------------------------------------
 * OTP_PROG_UNLOCK2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_PROG_UNLOCK2_OFFSET      (0x06FFu)
#define BQ7982X_OTP_PROG_UNLOCK2_POR_VAL     (0x00u)

#define BQ7982X_OTP_PROG_UNLOCK2_CODE_POS    (0x00u)
#define BQ7982X_OTP_PROG_UNLOCK2_CODE_MSK    (0xFFu)

/* --------------------------------------------------------------------------
 * PARTID           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_PARTID_OFFSET            (0x0700u)
#define BQ7982X_PARTID_POR_VAL           (0x00u)

#define BQ7982X_PARTID_REV_POS           (0x00u)
#define BQ7982X_PARTID_REV_MSK           (0xFFu)

/* --------------------------------------------------------------------------
 * TAPEOUT_REV           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_TAPEOUT_REV_OFFSET       (0x0701u)
#define BQ7982X_TAPEOUT_REV_POR_VAL      (0x00u)

#define BQ7982X_POS_TAPEOUT_REV_ALL_LAYER_REV    (0x00u)
#define BQ7982X_MSK_TAPEOUT_REV_ALL_LAYER_REV    (0x0Fu)

#define BQ7982X_TAPEOUT_REV_METAL_REV_POS        (0x04u)
#define BQ7982X_TAPEOUT_REV_METAL_REV_MSK        (0x0Fu)

/* --------------------------------------------------------------------------
 * DIE_ID1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID1_OFFSET            (0x0702u)
#define BQ7982X_DIE_ID1_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID1_ID_POS            (0x00u)
#define BQ7982X_DIE_ID1_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * DIE_ID2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID2_OFFSET            (0x0703u)
#define BQ7982X_DIE_ID2_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID2_ID_POS            (0x00u)
#define BQ7982X_DIE_ID2_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * DIE_ID3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID3_OFFSET            (0x0704u)
#define BQ7982X_DIE_ID3_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID3_ID_POS            (0x00u)
#define BQ7982X_DIE_ID3_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * DIE_ID4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID4_OFFSET            (0x0705u)
#define BQ7982X_DIE_ID4_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID4_ID_POS            (0x00u)
#define BQ7982X_DIE_ID4_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * DIE_ID5           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID5_OFFSET            (0x0706u)
#define BQ7982X_DIE_ID5_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID5_ID_POS            (0x00u)
#define BQ7982X_DIE_ID5_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * DIE_ID6           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID6_OFFSET            (0x0707u)
#define BQ7982X_DIE_ID6_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID6_ID_POS            (0x00u)
#define BQ7982X_DIE_ID6_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * DIE_ID7           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID7_OFFSET            (0x0708u)
#define BQ7982X_DIE_ID7_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID7_ID_POS            (0x00u)
#define BQ7982X_DIE_ID7_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * DIE_ID8           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIE_ID8_OFFSET            (0x0709u)
#define BQ7982X_DIE_ID8_POR_VAL           (0x00u)

#define BQ7982X_DIE_ID8_ID_POS            (0x00u)
#define BQ7982X_DIE_ID8_ID_MSK            (0xFFu)

/* --------------------------------------------------------------------------
 * CUST_CRC_RSLTHI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_CRC_RSLTHI_OFFSET    (0x070Cu)
#define BQ7982X_CUST_CRC_RSLTHI_POR_VAL   (0x00u)

#define BQ7982X_CUST_CRC_RSLTHI_CRC_POS   (0x00u)
#define BQ7982X_CUST_CRC_RSLTHI_CRC_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CUST_CRC_RSLTLO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CUST_CRC_RSLTLO_OFFSET    (0x070Du)
#define BQ7982X_CUST_CRC_RSLTLO_POR_VAL   (0x00u)

#define BQ7982X_CUST_CRC_RSLTLO_CRC_POS   (0x00u)
#define BQ7982X_CUST_CRC_RSLTLO_CRC_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * OTP_STAT                  (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_STAT_OFFSET    (0x0710u)
#define BQ7982X_OTP_STAT_POR_VAL   (0x00u)

#define BQ7982X_OTP_STAT_LOADED_POS    (0x07u)
#define BQ7982X_OTP_STAT_UV_OVOK_POS   (0x06u)
#define BQ7982X_OTP_STAT_TRY_POS       (0x05u)
#define BQ7982X_OTP_STAT_UNLOCK_POS    (0x04u)
#define BQ7982X_OTP_STAT_UV_OVERR_POS  (0x03u)
#define BQ7982X_OTP_STAT_SUV_SOVERR_POS (0x02u)
#define BQ7982X_OTP_STAT_PROGERR_POS   (0x01u)
#define BQ7982X_OTP_STAT_DONE_POS      (0x00u)

#define BQ7982X_OTP_STAT_LOADED_MSK    (0x80u)
#define BQ7982X_OTP_STAT_UV_OVOK_MSK   (0x40u)
#define BQ7982X_OTP_STAT_TRY_MSK       (0x20u)
#define BQ7982X_OTP_STAT_UNLOCK_MSK    (0x10u)
#define BQ7982X_OTP_STAT_UV_OVERR_MSK  (0x08u)
#define BQ7982X_OTP_STAT_SUV_SOVERR_MSK (0x04u)
#define BQ7982X_OTP_STAT_PROGERR_MSK   (0x02u)
#define BQ7982X_OTP_STAT_DONE_MSK      (0x01u)

/* --------------------------------------------------------------------------
 * COMM_STAT           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_COMM_STAT_OFFSET    (0x0718u)
#define BQ7982X_COMM_STAT_POR_VAL   (0x00u)

#define BQ7982X_COMM_STAT_HB_ACTIVE_POS   (0x01u)
#define BQ7982X_COMM_STAT_HB_ACTIVE_MSK   (0x02u)

#define BQ7982X_COMM_STAT_MD_DET_POS   (0x00u)
#define BQ7982X_COMM_STAT_MD_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_STAT1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_STAT1_OFFSET    (0x0720u)
#define BQ7982X_GPIO_STAT1_POR_VAL   (0x00u)

#define BQ7982X_GPIO_STAT1_GPIO8_POS   (0x07u)
#define BQ7982X_GPIO_STAT1_GPIO8_MSK   (0x80u)

#define BQ7982X_GPIO_STAT1_GPIO7_POS   (0x06u)
#define BQ7982X_GPIO_STAT1_GPIO7_MSK   (0x40u)

#define BQ7982X_GPIO_STAT1_GPIO6_POS   (0x05u)
#define BQ7982X_GPIO_STAT1_GPIO6_MSK   (0x20u)

#define BQ7982X_GPIO_STAT1_GPIO5_POS   (0x04u)
#define BQ7982X_GPIO_STAT1_GPIO5_MSK   (0x10u)

#define BQ7982X_GPIO_STAT1_GPIO4_POS   (0x03u)
#define BQ7982X_GPIO_STAT1_GPIO4_MSK   (0x08u)

#define BQ7982X_GPIO_STAT1_GPIO3_POS   (0x02u)
#define BQ7982X_GPIO_STAT1_GPIO3_MSK   (0x04u)

#define BQ7982X_GPIO_STAT1_GPIO2_POS   (0x01u)
#define BQ7982X_GPIO_STAT1_GPIO2_MSK   (0x02u)

#define BQ7982X_GPIO_STAT1_GPIO1_POS   (0x00u)
#define BQ7982X_GPIO_STAT1_GPIO1_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_STAT2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_STAT2_OFFSET    (0x0721u)
#define BQ7982X_GPIO_STAT2_POR_VAL   (0x00u)

#define BQ7982X_GPIO_STAT2_GPIO16_POS   (0x07u)
#define BQ7982X_GPIO_STAT2_GPIO16_MSK   (0x80u)

#define BQ7982X_GPIO_STAT2_GPIO15_POS   (0x06u)
#define BQ7982X_GPIO_STAT2_GPIO15_MSK   (0x40u)

#define BQ7982X_GPIO_STAT2_GPIO14_POS   (0x05u)
#define BQ7982X_GPIO_STAT2_GPIO14_MSK   (0x20u)

#define BQ7982X_GPIO_STAT2_GPIO13_POS   (0x04u)
#define BQ7982X_GPIO_STAT2_GPIO13_MSK   (0x10u)

#define BQ7982X_GPIO_STAT2_GPIO12_POS   (0x03u)
#define BQ7982X_GPIO_STAT2_GPIO12_MSK   (0x08u)

#define BQ7982X_GPIO_STAT2_GPIO11_POS   (0x02u)
#define BQ7982X_GPIO_STAT2_GPIO11_MSK   (0x04u)

#define BQ7982X_GPIO_STAT2_GPIO10_POS   (0x01u)
#define BQ7982X_GPIO_STAT2_GPIO10_MSK   (0x02u)

#define BQ7982X_GPIO_STAT2_GPIO9_POS   (0x00u)
#define BQ7982X_GPIO_STAT2_GPIO9_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * GPIO_STAT3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO_STAT3_OFFSET    (0x0722u)
#define BQ7982X_GPIO_STAT3_POR_VAL   (0x00u)

#define BQ7982X_GPIO_STAT3_GPIO20_POS   (0x03u)
#define BQ7982X_GPIO_STAT3_GPIO20_MSK   (0x08u)

#define BQ7982X_GPIO_STAT3_GPIO19_POS   (0x02u)
#define BQ7982X_GPIO_STAT3_GPIO19_MSK   (0x04u)

#define BQ7982X_GPIO_STAT3_GPIO18_POS   (0x01u)
#define BQ7982X_GPIO_STAT3_GPIO18_MSK   (0x02u)

#define BQ7982X_GPIO_STAT3_GPIO17_POS   (0x00u)
#define BQ7982X_GPIO_STAT3_GPIO17_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_STAT           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_STAT_OFFSET    (0x0723u)
#define BQ7982X_BAL_STAT_POR_VAL   (0x00u)

#define BQ7982X_POS_BAL_STAT_INVALID_CBCONF   (0x06u)
#define BQ7982X_MSK_BAL_STAT_INVALID_CBCONF   (0x40u)

#define BQ7982X_BAL_STAT_OT_PAUSE_DET_POS   (0x05u)
#define BQ7982X_BAL_STAT_OT_PAUSE_DET_MSK   (0x20u)

#define BQ7982X_BAL_STAT_CB_INPAUSED_POS   (0x04u)
#define BQ7982X_BAL_STAT_CB_INPAUSED_MSK   (0x10u)

#define BQ7982X_BAL_STAT_CB_RUN_POS   (0x03u)
#define BQ7982X_BAL_STAT_CB_RUN_MSK   (0x08u)

#define BQ7982X_BAL_STAT_ABORTFLT_POS   (0x02u)
#define BQ7982X_BAL_STAT_ABORTFLT_MSK   (0x04u)

#define BQ7982X_BAL_STAT_GLOBAL_DONE_POS   (0x01u)
#define BQ7982X_BAL_STAT_GLOBAL_DONE_MSK   (0x02u)

#define BQ7982X_BAL_STAT_CB_DONE_POS   (0x00u)
#define BQ7982X_BAL_STAT_CB_DONE_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_SW_STAT1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_SW_STAT1_OFFSET    (0x0728u)
#define BQ7982X_BAL_SW_STAT1_POR_VAL   (0x00u)

#define BQ7982X_BAL_SW_STAT1_CELL8_POS   (0x07u)
#define BQ7982X_BAL_SW_STAT1_CELL8_MSK   (0x80u)

#define BQ7982X_BAL_SW_STAT1_CELL7_POS   (0x06u)
#define BQ7982X_BAL_SW_STAT1_CELL7_MSK   (0x40u)

#define BQ7982X_BAL_SW_STAT1_CELL6_POS   (0x05u)
#define BQ7982X_BAL_SW_STAT1_CELL6_MSK   (0x20u)

#define BQ7982X_BAL_SW_STAT1_CELL5_POS   (0x04u)
#define BQ7982X_BAL_SW_STAT1_CELL5_MSK   (0x10u)

#define BQ7982X_BAL_SW_STAT1_CELL4_POS   (0x03u)
#define BQ7982X_BAL_SW_STAT1_CELL4_MSK   (0x08u)

#define BQ7982X_BAL_SW_STAT1_CELL3_POS   (0x02u)
#define BQ7982X_BAL_SW_STAT1_CELL3_MSK   (0x04u)

#define BQ7982X_BAL_SW_STAT1_CELL2_POS   (0x01u)
#define BQ7982X_BAL_SW_STAT1_CELL2_MSK   (0x02u)

#define BQ7982X_BAL_SW_STAT1_CELL1_POS   (0x00u)
#define BQ7982X_BAL_SW_STAT1_CELL1_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_SW_STAT2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_SW_STAT2_OFFSET    (0x0729u)
#define BQ7982X_BAL_SW_STAT2_POR_VAL   (0x00u)

#define BQ7982X_BAL_SW_STAT2_CELL16_POS   (0x07u)
#define BQ7982X_BAL_SW_STAT2_CELL16_MSK   (0x80u)

#define BQ7982X_BAL_SW_STAT2_CELL15_POS   (0x06u)
#define BQ7982X_BAL_SW_STAT2_CELL15_MSK   (0x40u)

#define BQ7982X_BAL_SW_STAT2_CELL14_POS   (0x05u)
#define BQ7982X_BAL_SW_STAT2_CELL14_MSK   (0x20u)

#define BQ7982X_BAL_SW_STAT2_CELL13_POS   (0x04u)
#define BQ7982X_BAL_SW_STAT2_CELL13_MSK   (0x10u)

#define BQ7982X_BAL_SW_STAT2_CELL12_POS   (0x03u)
#define BQ7982X_BAL_SW_STAT2_CELL12_MSK   (0x08u)

#define BQ7982X_BAL_SW_STAT2_CELL11_POS   (0x02u)
#define BQ7982X_BAL_SW_STAT2_CELL11_MSK   (0x04u)

#define BQ7982X_BAL_SW_STAT2_CELL10_POS   (0x01u)
#define BQ7982X_BAL_SW_STAT2_CELL10_MSK   (0x02u)

#define BQ7982X_BAL_SW_STAT2_CELL9_POS   (0x00u)
#define BQ7982X_BAL_SW_STAT2_CELL9_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_SW_STAT3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_SW_STAT3_OFFSET    (0x072Au)
#define BQ7982X_BAL_SW_STAT3_POR_VAL   (0x00u)

#define BQ7982X_BAL_SW_STAT3_CELL24_POS   (0x07u)
#define BQ7982X_BAL_SW_STAT3_CELL24_MSK   (0x80u)

#define BQ7982X_BAL_SW_STAT3_CELL23_POS   (0x06u)
#define BQ7982X_BAL_SW_STAT3_CELL23_MSK   (0x40u)

#define BQ7982X_BAL_SW_STAT3_CELL22_POS   (0x05u)
#define BQ7982X_BAL_SW_STAT3_CELL22_MSK   (0x20u)

#define BQ7982X_BAL_SW_STAT3_CELL21_POS   (0x04u)
#define BQ7982X_BAL_SW_STAT3_CELL21_MSK   (0x10u)

#define BQ7982X_BAL_SW_STAT3_CELL20_POS   (0x03u)
#define BQ7982X_BAL_SW_STAT3_CELL20_MSK   (0x08u)

#define BQ7982X_BAL_SW_STAT3_CELL19_POS   (0x02u)
#define BQ7982X_BAL_SW_STAT3_CELL19_MSK   (0x04u)

#define BQ7982X_BAL_SW_STAT3_CELL18_POS   (0x01u)
#define BQ7982X_BAL_SW_STAT3_CELL18_MSK   (0x02u)

#define BQ7982X_BAL_SW_STAT3_CELL17_POS   (0x00u)
#define BQ7982X_BAL_SW_STAT3_CELL17_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_SW_STAT4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_SW_STAT4_OFFSET    (0x072Bu)
#define BQ7982X_BAL_SW_STAT4_POR_VAL   (0x00u)

#define BQ7982X_BAL_SW_STAT4_CELL26_POS   (0x01u)
#define BQ7982X_BAL_SW_STAT4_CELL26_MSK   (0x02u)

#define BQ7982X_BAL_SW_STAT4_CELL25_POS   (0x00u)
#define BQ7982X_BAL_SW_STAT4_CELL25_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_DONE1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_DONE1_OFFSET    (0x072Cu)
#define BQ7982X_BAL_DONE1_POR_VAL   (0x00u)

#define BQ7982X_BAL_DONE1_CELL8_POS   (0x07u)
#define BQ7982X_BAL_DONE1_CELL8_MSK   (0x80u)

#define BQ7982X_BAL_DONE1_CELL7_POS   (0x06u)
#define BQ7982X_BAL_DONE1_CELL7_MSK   (0x40u)

#define BQ7982X_BAL_DONE1_CELL6_POS   (0x05u)
#define BQ7982X_BAL_DONE1_CELL6_MSK   (0x20u)

#define BQ7982X_BAL_DONE1_CELL5_POS   (0x04u)
#define BQ7982X_BAL_DONE1_CELL5_MSK   (0x10u)

#define BQ7982X_BAL_DONE1_CELL4_POS   (0x03u)
#define BQ7982X_BAL_DONE1_CELL4_MSK   (0x08u)

#define BQ7982X_BAL_DONE1_CELL3_POS   (0x02u)
#define BQ7982X_BAL_DONE1_CELL3_MSK   (0x04u)

#define BQ7982X_BAL_DONE1_CELL2_POS   (0x01u)
#define BQ7982X_BAL_DONE1_CELL2_MSK   (0x02u)

#define BQ7982X_BAL_DONE1_CELL1_POS   (0x00u)
#define BQ7982X_BAL_DONE1_CELL1_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_DONE2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_DONE2_OFFSET    (0x072Du)
#define BQ7982X_BAL_DONE2_POR_VAL   (0x00u)

#define BQ7982X_BAL_DONE2_CELL16_POS   (0x07u)
#define BQ7982X_BAL_DONE2_CELL16_MSK   (0x80u)

#define BQ7982X_BAL_DONE2_CELL15_POS   (0x06u)
#define BQ7982X_BAL_DONE2_CELL15_MSK   (0x40u)

#define BQ7982X_BAL_DONE2_CELL14_POS   (0x05u)
#define BQ7982X_BAL_DONE2_CELL14_MSK   (0x20u)

#define BQ7982X_BAL_DONE2_CELL13_POS   (0x04u)
#define BQ7982X_BAL_DONE2_CELL13_MSK   (0x10u)

#define BQ7982X_BAL_DONE2_CELL12_POS   (0x03u)
#define BQ7982X_BAL_DONE2_CELL12_MSK   (0x08u)

#define BQ7982X_BAL_DONE2_CELL11_POS   (0x02u)
#define BQ7982X_BAL_DONE2_CELL11_MSK   (0x04u)

#define BQ7982X_BAL_DONE2_CELL10_POS   (0x01u)
#define BQ7982X_BAL_DONE2_CELL10_MSK   (0x02u)

#define BQ7982X_BAL_DONE2_CELL9_POS   (0x00u)
#define BQ7982X_BAL_DONE2_CELL9_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_DONE3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_DONE3_OFFSET    (0x072Eu)
#define BQ7982X_BAL_DONE3_POR_VAL   (0x00u)

#define BQ7982X_BAL_DONE3_CELL24_POS   (0x07u)
#define BQ7982X_BAL_DONE3_CELL24_MSK   (0x80u)

#define BQ7982X_BAL_DONE3_CELL23_POS   (0x06u)
#define BQ7982X_BAL_DONE3_CELL23_MSK   (0x40u)

#define BQ7982X_BAL_DONE3_CELL22_POS   (0x05u)
#define BQ7982X_BAL_DONE3_CELL22_MSK   (0x20u)

#define BQ7982X_BAL_DONE3_CELL21_POS   (0x04u)
#define BQ7982X_BAL_DONE3_CELL21_MSK   (0x10u)

#define BQ7982X_BAL_DONE3_CELL20_POS   (0x03u)
#define BQ7982X_BAL_DONE3_CELL20_MSK   (0x08u)

#define BQ7982X_BAL_DONE3_CELL19_POS   (0x02u)
#define BQ7982X_BAL_DONE3_CELL19_MSK   (0x04u)

#define BQ7982X_BAL_DONE3_CELL18_POS   (0x01u)
#define BQ7982X_BAL_DONE3_CELL18_MSK   (0x02u)

#define BQ7982X_BAL_DONE3_CELL17_POS   (0x00u)
#define BQ7982X_BAL_DONE3_CELL17_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_DONE4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_DONE4_OFFSET    (0x072Fu)
#define BQ7982X_BAL_DONE4_POR_VAL   (0x00u)

#define BQ7982X_BAL_DONE4_CELL26_POS   (0x01u)
#define BQ7982X_BAL_DONE4_CELL26_MSK   (0x02u)

#define BQ7982X_BAL_DONE4_CELL25_POS   (0x00u)
#define BQ7982X_BAL_DONE4_CELL25_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * BAL_TIME           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAL_TIME_OFFSET    (0x0730u)
#define BQ7982X_BAL_TIME_POR_VAL   (0x00u)

#define BQ7982X_BAL_TIME_TIME_UNIT_POS   (0x07u)
#define BQ7982X_BAL_TIME_TIME_UNIT_MSK   (0x80u)

#define BQ7982X_BAL_TIME_TIME_POS   (0x00u)
#define BQ7982X_BAL_TIME_TIME_MSK   (0x7Fu)

/* --------------------------------------------------------------------------
 * DIAG_STAT1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_STAT1_OFFSET    (0x0731u)
#define BQ7982X_DIAG_STAT1_POR_VAL   (0x00u)

#define BQ7982X_POS_DIAG_STAT1_SF_FREEZE_ACTIVE   (0x07u)
#define BQ7982X_MSK_DIAG_STAT1_SF_FREEZE_ACTIVE   (0x80u)

#define BQ7982X_POS_DIAG_STAT1_DIAG_BAL_FREEZE_ACTIVE   (0x06u)
#define BQ7982X_MSK_DIAG_STAT1_DIAG_BAL_FREEZE_ACTIVE   (0x40u)

#define BQ7982X_POS_DIAG_STAT1_FREEZE_ACTIVE   (0x05u)
#define BQ7982X_MSK_DIAG_STAT1_FREEZE_ACTIVE   (0x20u)

#define BQ7982X_POS_DIAG_STAT1_FREEZE_LPF_ACTIVE   (0x04u)
#define BQ7982X_MSK_DIAG_STAT1_FREEZE_LPF_ACTIVE   (0x10u)

#define BQ7982X_DIAG_STAT1_DRDY_SMON_POS   (0x03u)
#define BQ7982X_DIAG_STAT1_DRDY_SMON_MSK   (0x08u)

#define BQ7982X_DIAG_STAT1_DRDY_TMON_POS   (0x02u)
#define BQ7982X_DIAG_STAT1_DRDY_TMON_MSK   (0x04u)

#define BQ7982X_DIAG_STAT1_DRDY_VMON_POS   (0x01u)
#define BQ7982X_DIAG_STAT1_DRDY_VMON_MSK   (0x02u)

#define BQ7982X_POS_DIAG_STAT1_DRDY_PWRBIST   (0x00u)
#define BQ7982X_MSK_DIAG_STAT1_DRDY_PWRBIST   (0x01u)

/* --------------------------------------------------------------------------
 * DIAG_STAT2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_STAT2_OFFSET    (0x0732u)
#define BQ7982X_DIAG_STAT2_POR_VAL   (0x00u)

#define BQ7982X_POS_DIAG_STAT2_ECC_TEST_OK   (0x05u)
#define BQ7982X_MSK_DIAG_STAT2_ECC_TEST_OK   (0x20u)

#define BQ7982X_POS_DIAG_STAT2_DRDY_DIAG_BAL   (0x04u)
#define BQ7982X_MSK_DIAG_STAT2_DRDY_DIAG_BAL   (0x10u)

#define BQ7982X_POS_DIAG_STAT2_DRDY_CBFETOW   (0x03u)
#define BQ7982X_MSK_DIAG_STAT2_DRDY_CBFETOW   (0x08u)

#define BQ7982X_DIAG_STAT2_DRDY_DIG_POS   (0x02u)
#define BQ7982X_DIAG_STAT2_DRDY_DIG_MSK   (0x04u)

#define BQ7982X_POS_DIAG_STAT2_DRDY_ANA_GPIO   (0x01u)
#define BQ7982X_MSK_DIAG_STAT2_DRDY_ANA_GPIO   (0x02u)

#define BQ7982X_POS_DIAG_STAT2_DRDY_ANA_VCELL   (0x00u)
#define BQ7982X_MSK_DIAG_STAT2_DRDY_ANA_VCELL   (0x01u)

/* --------------------------------------------------------------------------
 * ADC_DATA_RDY           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_ADC_DATA_RDY_OFFSET    (0x0733u)
#define BQ7982X_ADC_DATA_RDY_POR_VAL   (0x00u)

#define BQ7982X_POS_ADC_DATA_RDY_DRDY_CSADC   (0x04u)
#define BQ7982X_MSK_ADC_DATA_RDY_DRDY_CSADC   (0x10u)

#define BQ7982X_POS_ADC_DATA_RDY_DRDY_DIAG_D1D2   (0x03u)
#define BQ7982X_MSK_ADC_DATA_RDY_DRDY_DIAG_D1D2   (0x08u)

#define BQ7982X_POS_ADC_DATA_RDY_DRDY_DIAG   (0x02u)
#define BQ7982X_MSK_ADC_DATA_RDY_DRDY_DIAG   (0x04u)

#define BQ7982X_POS_ADC_DATA_RDY_DRDY_GPADC   (0x01u)
#define BQ7982X_MSK_ADC_DATA_RDY_DRDY_GPADC   (0x02u)

#define BQ7982X_POS_ADC_DATA_RDY_DRDY_VCELLADC   (0x00u)
#define BQ7982X_MSK_ADC_DATA_RDY_DRDY_VCELLADC   (0x01u)

/* --------------------------------------------------------------------------
 * DEV_STAT1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEV_STAT1_OFFSET    (0x0734u)
#define BQ7982X_DEV_STAT1_POR_VAL   (0x00u)

#define BQ7982X_POS_DEV_STAT1_DIAG_ANA_GP_RUN   (0x07u)
#define BQ7982X_MSK_DEV_STAT1_DIAG_ANA_GP_RUN   (0x80u)

#define BQ7982X_POS_DEV_STAT1_FACT_CRC_DONE   (0x06u)
#define BQ7982X_MSK_DEV_STAT1_FACT_CRC_DONE   (0x40u)

#define BQ7982X_POS_DEV_STAT1_CUST_CRC_DONE   (0x05u)
#define BQ7982X_MSK_DEV_STAT1_CUST_CRC_DONE   (0x20u)

#define BQ7982X_POS_DEV_STAT1_DIAG_DIG_RUN   (0x04u)
#define BQ7982X_MSK_DEV_STAT1_DIAG_DIG_RUN   (0x10u)

#define BQ7982X_POS_DEV_STAT1_DIAG_MEAS_RUN   (0x03u)
#define BQ7982X_MSK_DEV_STAT1_DIAG_MEAS_RUN   (0x08u)

#define BQ7982X_POS_DEV_STAT1_DIAG_ANA_VC_RUN   (0x02u)
#define BQ7982X_MSK_DEV_STAT1_DIAG_ANA_VC_RUN   (0x04u)

#define BQ7982X_DEV_STAT1_GPADC_RUN_POS   (0x01u)
#define BQ7982X_DEV_STAT1_GPADC_RUN_MSK   (0x02u)

#define BQ7982X_POS_DEV_STAT1_VCELLADC_RUN   (0x00u)
#define BQ7982X_MSK_DEV_STAT1_VCELLADC_RUN   (0x01u)

/* --------------------------------------------------------------------------
 * DEV_STAT2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEV_STAT2_OFFSET    (0x0735u)
#define BQ7982X_DEV_STAT2_POR_VAL   (0x00u)

#define BQ7982X_POS_DEV_STAT2_CRYSTAL_ACTIVE   (0x07u)
#define BQ7982X_MSK_DEV_STAT2_CRYSTAL_ACTIVE   (0x80u)

#define BQ7982X_DEV_STAT2_AVDD_ON_POS   (0x06u)
#define BQ7982X_DEV_STAT2_AVDD_ON_MSK   (0x40u)

#define BQ7982X_DEV_STAT2_CSADC_RUN_POS   (0x05u)
#define BQ7982X_DEV_STAT2_CSADC_RUN_MSK   (0x20u)

#define BQ7982X_DEV_STAT2_OTCB_RUN_POS   (0x04u)
#define BQ7982X_DEV_STAT2_OTCB_RUN_MSK   (0x10u)

#define BQ7982X_DEV_STAT2_VCBDONE_RUN_POS   (0x03u)
#define BQ7982X_DEV_STAT2_VCBDONE_RUN_MSK   (0x08u)

#define BQ7982X_DEV_STAT2_SMON_RUN_POS   (0x02u)
#define BQ7982X_DEV_STAT2_SMON_RUN_MSK   (0x04u)

#define BQ7982X_DEV_STAT2_OTUT_RUN_POS   (0x01u)
#define BQ7982X_DEV_STAT2_OTUT_RUN_MSK   (0x02u)

#define BQ7982X_DEV_STAT2_OVUV_RUN_POS   (0x00u)
#define BQ7982X_DEV_STAT2_OVUV_RUN_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_SUMMARY           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_SUMMARY_OFFSET    (0x0737u)
#define BQ7982X_FAULT_SUMMARY_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_OC   (0x07u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_OC   (0x80u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_ADC_CB   (0x06u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_ADC_CB   (0x40u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_TMON   (0x05u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_TMON   (0x20u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_OVUV   (0x04u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_OVUV   (0x10u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_SYS   (0x03u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_SYS   (0x08u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_MEM   (0x02u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_MEM   (0x04u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_COMM   (0x01u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_COMM   (0x02u)

#define BQ7982X_POS_FAULT_SUMMARY_FAULT_PWR   (0x00u)
#define BQ7982X_MSK_FAULT_SUMMARY_FAULT_PWR   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_PWR1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_PWR1_OFFSET    (0x0739u)
#define BQ7982X_FAULT_PWR1_POR_VAL   (0x00u)

#define BQ7982X_FAULT_PWR1_VSS_OPEN_POS   (0x07u)
#define BQ7982X_FAULT_PWR1_VSS_OPEN_MSK   (0x80u)

#define BQ7982X_FAULT_PWR1_TSREF_UV_POS   (0x06u)
#define BQ7982X_FAULT_PWR1_TSREF_UV_MSK   (0x40u)

#define BQ7982X_FAULT_PWR1_TSREF_OV_POS   (0x05u)
#define BQ7982X_FAULT_PWR1_TSREF_OV_MSK   (0x20u)

#define BQ7982X_FAULT_PWR1_INTR_UV_POS   (0x04u)
#define BQ7982X_FAULT_PWR1_INTR_UV_MSK   (0x10u)

#define BQ7982X_FAULT_PWR1_VIO_UV_POS   (0x03u)
#define BQ7982X_FAULT_PWR1_VIO_UV_MSK   (0x08u)

#define BQ7982X_FAULT_PWR1_DVDD_OV_POS   (0x02u)
#define BQ7982X_FAULT_PWR1_DVDD_OV_MSK   (0x04u)

#define BQ7982X_FAULT_PWR1_AVDD_OV_POS   (0x01u)
#define BQ7982X_FAULT_PWR1_AVDD_OV_MSK   (0x02u)

#define BQ7982X_POS_FAULT_PWR1_PWRBIST_FAIL   (0x00u)
#define BQ7982X_MSK_FAULT_PWR1_PWRBIST_FAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_PWR2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_PWR2_OFFSET    (0x073Au)
#define BQ7982X_FAULT_PWR2_POR_VAL   (0x00u)

#define BQ7982X_FAULT_PWR2_TSREF_OSC_POS   (0x02u)
#define BQ7982X_FAULT_PWR2_TSREF_OSC_MSK   (0x04u)

#define BQ7982X_FAULT_PWR2_AVDD_OSC_POS   (0x01u)
#define BQ7982X_FAULT_PWR2_AVDD_OSC_MSK   (0x02u)

#define BQ7982X_FAULT_PWR2_NEG_CP_UV_POS   (0x00u)
#define BQ7982X_FAULT_PWR2_NEG_CP_UV_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_COMM1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_COMM1_OFFSET    (0x073Cu)
#define BQ7982X_FAULT_COMM1_POR_VAL   (0x00u)

#define BQ7982X_FAULT_COMM1_PSPI2_POS   (0x04u)
#define BQ7982X_FAULT_COMM1_PSPI2_MSK   (0x10u)

#define BQ7982X_FAULT_COMM1_COMM_BUSY_POS   (0x03u)
#define BQ7982X_FAULT_COMM1_COMM_BUSY_MSK   (0x08u)

#define BQ7982X_FAULT_COMM1_COML_POS   (0x02u)
#define BQ7982X_FAULT_COMM1_COML_MSK   (0x04u)

#define BQ7982X_FAULT_COMM1_COMH_POS   (0x01u)
#define BQ7982X_FAULT_COMM1_COMH_MSK   (0x02u)

#define BQ7982X_FAULT_COMM1_PSPI_POS   (0x00u)
#define BQ7982X_FAULT_COMM1_PSPI_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_COMM2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_COMM2_OFFSET    (0x073Du)
#define BQ7982X_FAULT_COMM2_POR_VAL   (0x00u)

#define BQ7982X_FAULT_COMM2_FT_DET1_POS   (0x07u)
#define BQ7982X_FAULT_COMM2_FT_DET1_MSK   (0x80u)

#define BQ7982X_FAULT_COMM2_FT_DET2_POS   (0x06u)
#define BQ7982X_FAULT_COMM2_FT_DET2_MSK   (0x40u)

#define BQ7982X_FAULT_COMM2_FT_DET3_POS   (0x05u)
#define BQ7982X_FAULT_COMM2_FT_DET3_MSK   (0x20u)

#define BQ7982X_FAULT_COMM2_FT_DET4_POS   (0x04u)
#define BQ7982X_FAULT_COMM2_FT_DET4_MSK   (0x10u)

#define BQ7982X_POS_FAULT_COMM2_HB_TO_FAIL1   (0x03u)
#define BQ7982X_MSK_FAULT_COMM2_HB_TO_FAIL1   (0x08u)

#define BQ7982X_POS_FAULT_COMM2_HB_TO_FAIL2   (0x02u)
#define BQ7982X_MSK_FAULT_COMM2_HB_TO_FAIL2   (0x04u)

#define BQ7982X_POS_FAULT_COMM2_HB_TO_FAIL3   (0x01u)
#define BQ7982X_MSK_FAULT_COMM2_HB_TO_FAIL3   (0x02u)

#define BQ7982X_POS_FAULT_COMM2_HB_TO_FAIL4   (0x00u)
#define BQ7982X_MSK_FAULT_COMM2_HB_TO_FAIL4   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_COMM3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_COMM3_OFFSET    (0x073Eu)
#define BQ7982X_FAULT_COMM3_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_COMM3_MD_FT_UNEXP_DET   (0x05u)
#define BQ7982X_MSK_FAULT_COMM3_MD_FT_UNEXP_DET   (0x20u)

#define BQ7982X_POS_FAULT_COMM3_MD_HB_UNEXP_DET   (0x04u)
#define BQ7982X_MSK_FAULT_COMM3_MD_HB_UNEXP_DET   (0x10u)

#define BQ7982X_POS_FAULT_COMM3_FT_UNEXP_DET   (0x03u)
#define BQ7982X_MSK_FAULT_COMM3_FT_UNEXP_DET   (0x08u)

#define BQ7982X_POS_FAULT_COMM3_HB_UNEXP_DET   (0x02u)
#define BQ7982X_MSK_FAULT_COMM3_HB_UNEXP_DET   (0x04u)

#define BQ7982X_POS_FAULT_COMM3_FRAME_FAIL   (0x01u)
#define BQ7982X_MSK_FAULT_COMM3_FRAME_FAIL   (0x02u)

#define BQ7982X_POS_FAULT_COMM3_FRAME_RESET   (0x00u)
#define BQ7982X_MSK_FAULT_COMM3_FRAME_RESET   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_MEM             (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_MEM_OFFSET    (0x0743u)
#define BQ7982X_FAULT_MEM_POR_VAL   (0x00u)

#define BQ7982X_FAULT_MEM_EIS_DED_POS   (0x07u)
#define BQ7982X_FAULT_MEM_EIS_DED_MSK   (0x80u)

#define BQ7982X_FAULT_MEM_EIS_SEC_POS   (0x06u)
#define BQ7982X_FAULT_MEM_EIS_SEC_MSK   (0x40u)

#define BQ7982X_FAULT_MEM_OTP_DED_POS   (0x05u)
#define BQ7982X_FAULT_MEM_OTP_DED_MSK   (0x20u)

#define BQ7982X_FAULT_MEM_OTP_SEC_POS   (0x04u)
#define BQ7982X_FAULT_MEM_OTP_SEC_MSK   (0x10u)

#define BQ7982X_FAULT_MEM_CUST_CRC_POS   (0x03u)
#define BQ7982X_FAULT_MEM_CUST_CRC_MSK   (0x08u)

#define BQ7982X_FAULT_MEM_FACT_CRC_POS   (0x02u)
#define BQ7982X_FAULT_MEM_FACT_CRC_MSK   (0x04u)

#define BQ7982X_FAULT_MEM_LOADERR_POS   (0x01u)
#define BQ7982X_FAULT_MEM_LOADERR_MSK   (0x02u)

#define BQ7982X_FAULT_MEM_GBLOVERR_POS   (0x00u)
#define BQ7982X_FAULT_MEM_GBLOVERR_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_SYS1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_SYS1_OFFSET    (0x0745u)
#define BQ7982X_FAULT_SYS1_POR_VAL   (0x00u)

#define BQ7982X_FAULT_SYS1_CRYSTAL_POS   (0x06u)
#define BQ7982X_FAULT_SYS1_CRYSTAL_MSK   (0x40u)

#define BQ7982X_POS_FAULT_SYS1_NUM_CELL_OV   (0x05u)
#define BQ7982X_MSK_FAULT_SYS1_NUM_CELL_OV   (0x20u)

#define BQ7982X_FAULT_SYS1_AVDD_ON_POS   (0x04u)
#define BQ7982X_FAULT_SYS1_AVDD_ON_MSK   (0x10u)

#define BQ7982X_FAULT_SYS1_LFO_POS   (0x03u)
#define BQ7982X_FAULT_SYS1_LFO_MSK   (0x08u)

#define BQ7982X_FAULT_SYS1_DRST_POS   (0x02u)
#define BQ7982X_FAULT_SYS1_DRST_MSK   (0x04u)

#define BQ7982X_FAULT_SYS1_TSHUT_POS   (0x01u)
#define BQ7982X_FAULT_SYS1_TSHUT_MSK   (0x02u)

#define BQ7982X_FAULT_SYS1_TWARN_POS   (0x00u)
#define BQ7982X_FAULT_SYS1_TWARN_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_SYS2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_SYS2_OFFSET    (0x0746u)
#define BQ7982X_FAULT_SYS2_POR_VAL   (0x00u)

#define BQ7982X_FAULT_SYS2_I2C_BUSY_POS   (0x04u)
#define BQ7982X_FAULT_SYS2_I2C_BUSY_MSK   (0x10u)

#define BQ7982X_FAULT_SYS2_I2C_LOW_POS   (0x03u)
#define BQ7982X_FAULT_SYS2_I2C_LOW_MSK   (0x08u)

#define BQ7982X_FAULT_SYS2_I2C_NACK_POS   (0x02u)
#define BQ7982X_FAULT_SYS2_I2C_NACK_MSK   (0x04u)

#define BQ7982X_FAULT_SYS2_CSPI_CS_POS   (0x01u)
#define BQ7982X_FAULT_SYS2_CSPI_CS_MSK   (0x02u)

#define BQ7982X_FAULT_SYS2_CSPI_BUSY_POS   (0x00u)
#define BQ7982X_FAULT_SYS2_CSPI_BUSY_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_SYS3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_SYS3_OFFSET    (0x0747u)
#define BQ7982X_FAULT_SYS3_POR_VAL   (0x00u)

#define BQ7982X_FAULT_SYS3_INT8_DET_POS   (0x07u)
#define BQ7982X_FAULT_SYS3_INT8_DET_MSK   (0x80u)

#define BQ7982X_FAULT_SYS3_INT7_DET_POS   (0x06u)
#define BQ7982X_FAULT_SYS3_INT7_DET_MSK   (0x40u)

#define BQ7982X_FAULT_SYS3_INT6_DET_POS   (0x05u)
#define BQ7982X_FAULT_SYS3_INT6_DET_MSK   (0x20u)

#define BQ7982X_FAULT_SYS3_INT5_DET_POS   (0x04u)
#define BQ7982X_FAULT_SYS3_INT5_DET_MSK   (0x10u)

#define BQ7982X_FAULT_SYS3_INT4_DET_POS   (0x03u)
#define BQ7982X_FAULT_SYS3_INT4_DET_MSK   (0x08u)

#define BQ7982X_FAULT_SYS3_INT3_DET_POS   (0x02u)
#define BQ7982X_FAULT_SYS3_INT3_DET_MSK   (0x04u)

#define BQ7982X_FAULT_SYS3_INT2_DET_POS   (0x01u)
#define BQ7982X_FAULT_SYS3_INT2_DET_MSK   (0x02u)

#define BQ7982X_FAULT_SYS3_INT1_DET_POS   (0x00u)
#define BQ7982X_FAULT_SYS3_INT1_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_SYS4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_SYS4_OFFSET    (0x0748u)
#define BQ7982X_FAULT_SYS4_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_SYS4_AO_MON_PFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_SYS4_AO_MON_PFAIL   (0x80u)

#define BQ7982X_FAULT_SYS4_MON_PFAIL_POS   (0x06u)
#define BQ7982X_FAULT_SYS4_MON_PFAIL_MSK   (0x40u)

#define BQ7982X_FAULT_SYS4_SMONH_DET_POS   (0x05u)
#define BQ7982X_FAULT_SYS4_SMONH_DET_MSK   (0x20u)

#define BQ7982X_FAULT_SYS4_SMONL_DET_POS   (0x04u)
#define BQ7982X_FAULT_SYS4_SMONL_DET_MSK   (0x10u)

#define BQ7982X_FAULT_SYS4_SMON_ABORT_POS   (0x03u)
#define BQ7982X_FAULT_SYS4_SMON_ABORT_MSK   (0x08u)

#define BQ7982X_FAULT_SYS4_VMON_ABORT_POS   (0x02u)
#define BQ7982X_FAULT_SYS4_VMON_ABORT_MSK   (0x04u)

#define BQ7982X_FAULT_SYS4_TMON_ABORT_POS   (0x01u)
#define BQ7982X_FAULT_SYS4_TMON_ABORT_MSK   (0x02u)

#define BQ7982X_FAULT_SYS4_MON_ABORT_POS   (0x00u)
#define BQ7982X_FAULT_SYS4_MON_ABORT_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_SYS5           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_SYS5_OFFSET    (0x0749u)
#define BQ7982X_FAULT_SYS5_POR_VAL   (0x00u)

#define BQ7982X_FAULT_SYS5_PWM_WARN_POS   (0x03u)
#define BQ7982X_FAULT_SYS5_PWM_WARN_MSK   (0x04u)

#define BQ7982X_FAULT_SYS5_EIS_WARN_POS   (0x02u)
#define BQ7982X_FAULT_SYS5_EIS_WARN_MSK   (0x02u)

#define BQ7982X_FAULT_SYS5_EIS_ABORT_POS   (0x00u)
#define BQ7982X_FAULT_SYS5_EIS_ABORT_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_SYS6           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_SYS6_OFFSET    (0x074Au)
#define BQ7982X_FAULT_SYS6_POR_VAL   (0x00u)

#define BQ7982X_FAULT_SYS6_SF_PFAIL_POS   (0x06u)
#define BQ7982X_FAULT_SYS6_SF_PFAIL_MSK   (0x40u)

#define BQ7982X_POS_FAULT_SYS6_HFO_FREQ_FAIL   (0x05u)
#define BQ7982X_MSK_FAULT_SYS6_HFO_FREQ_FAIL   (0x20u)

#define BQ7982X_POS_FAULT_SYS6_PROP_DLY_FAIL   (0x04u)
#define BQ7982X_MSK_FAULT_SYS6_PROP_DLY_FAIL   (0x10u)

#define BQ7982X_POS_FAULT_SYS6_PLL_SYNC_FAIL   (0x03u)
#define BQ7982X_MSK_FAULT_SYS6_PLL_SYNC_FAIL   (0x08u)

#define BQ7982X_POS_FAULT_SYS6_DIG_SYNC_WARN   (0x02u)
#define BQ7982X_MSK_FAULT_SYS6_DIG_SYNC_WARN   (0x04u)

#define BQ7982X_POS_FAULT_SYS6_DIG_SYNC_FAIL   (0x01u)
#define BQ7982X_MSK_FAULT_SYS6_DIG_SYNC_FAIL   (0x02u)

#define BQ7982X_FAULT_SYS6_SF_WARN_POS   (0x00u)
#define BQ7982X_FAULT_SYS6_SF_WARN_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_OV1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_OV1_OFFSET    (0x074Eu)
#define BQ7982X_FAULT_OV1_POR_VAL   (0x00u)

#define BQ7982X_FAULT_OV1_OV8_DET_POS   (0x07u)
#define BQ7982X_FAULT_OV1_OV8_DET_MSK   (0x80u)

#define BQ7982X_FAULT_OV1_OV7_DET_POS   (0x06u)
#define BQ7982X_FAULT_OV1_OV7_DET_MSK   (0x40u)

#define BQ7982X_FAULT_OV1_OV6_DET_POS   (0x05u)
#define BQ7982X_FAULT_OV1_OV6_DET_MSK   (0x20u)

#define BQ7982X_FAULT_OV1_OV5_DET_POS   (0x04u)
#define BQ7982X_FAULT_OV1_OV5_DET_MSK   (0x10u)

#define BQ7982X_FAULT_OV1_OV4_DET_POS   (0x03u)
#define BQ7982X_FAULT_OV1_OV4_DET_MSK   (0x08u)

#define BQ7982X_FAULT_OV1_OV3_DET_POS   (0x02u)
#define BQ7982X_FAULT_OV1_OV3_DET_MSK   (0x04u)

#define BQ7982X_FAULT_OV1_OV2_DET_POS   (0x01u)
#define BQ7982X_FAULT_OV1_OV2_DET_MSK   (0x02u)

#define BQ7982X_FAULT_OV1_OV1_DET_POS   (0x00u)
#define BQ7982X_FAULT_OV1_OV1_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_OV2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_OV2_OFFSET    (0x074Fu)
#define BQ7982X_FAULT_OV2_POR_VAL   (0x00u)

#define BQ7982X_FAULT_OV2_OV16_DET_POS   (0x07u)
#define BQ7982X_FAULT_OV2_OV16_DET_MSK   (0x80u)

#define BQ7982X_FAULT_OV2_OV15_DET_POS   (0x06u)
#define BQ7982X_FAULT_OV2_OV15_DET_MSK   (0x40u)

#define BQ7982X_FAULT_OV2_OV14_DET_POS   (0x05u)
#define BQ7982X_FAULT_OV2_OV14_DET_MSK   (0x20u)

#define BQ7982X_FAULT_OV2_OV13_DET_POS   (0x04u)
#define BQ7982X_FAULT_OV2_OV13_DET_MSK   (0x10u)

#define BQ7982X_FAULT_OV2_OV12_DET_POS   (0x03u)
#define BQ7982X_FAULT_OV2_OV12_DET_MSK   (0x08u)

#define BQ7982X_FAULT_OV2_OV11_DET_POS   (0x02u)
#define BQ7982X_FAULT_OV2_OV11_DET_MSK   (0x04u)

#define BQ7982X_FAULT_OV2_OV10_DET_POS   (0x01u)
#define BQ7982X_FAULT_OV2_OV10_DET_MSK   (0x02u)

#define BQ7982X_FAULT_OV2_OV9_DET_POS   (0x00u)
#define BQ7982X_FAULT_OV2_OV9_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_OV3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_OV3_OFFSET    (0x0750u)
#define BQ7982X_FAULT_OV3_POR_VAL   (0x00u)

#define BQ7982X_FAULT_OV3_OV24_DET_POS   (0x07u)
#define BQ7982X_FAULT_OV3_OV24_DET_MSK   (0x80u)

#define BQ7982X_FAULT_OV3_OV23_DET_POS   (0x06u)
#define BQ7982X_FAULT_OV3_OV23_DET_MSK   (0x40u)

#define BQ7982X_FAULT_OV3_OV22_DET_POS   (0x05u)
#define BQ7982X_FAULT_OV3_OV22_DET_MSK   (0x20u)

#define BQ7982X_FAULT_OV3_OV21_DET_POS   (0x04u)
#define BQ7982X_FAULT_OV3_OV21_DET_MSK   (0x10u)

#define BQ7982X_FAULT_OV3_OV20_DET_POS   (0x03u)
#define BQ7982X_FAULT_OV3_OV20_DET_MSK   (0x08u)

#define BQ7982X_FAULT_OV3_OV19_DET_POS   (0x02u)
#define BQ7982X_FAULT_OV3_OV19_DET_MSK   (0x04u)

#define BQ7982X_FAULT_OV3_OV18_DET_POS   (0x01u)
#define BQ7982X_FAULT_OV3_OV18_DET_MSK   (0x02u)

#define BQ7982X_FAULT_OV3_OV17_DET_POS   (0x00u)
#define BQ7982X_FAULT_OV3_OV17_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_OV4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_OV4_OFFSET    (0x0751u)
#define BQ7982X_FAULT_OV4_POR_VAL   (0x00u)

#define BQ7982X_FAULT_OV4_OV26_DET_POS   (0x01u)
#define BQ7982X_FAULT_OV4_OV26_DET_MSK   (0x02u)

#define BQ7982X_FAULT_OV4_OV25_DET_POS   (0x00u)
#define BQ7982X_FAULT_OV4_OV25_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_UV1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_UV1_OFFSET    (0x0752u)
#define BQ7982X_FAULT_UV1_POR_VAL   (0x00u)

#define BQ7982X_FAULT_UV1_UV8_DET_POS   (0x07u)
#define BQ7982X_FAULT_UV1_UV8_DET_MSK   (0x80u)

#define BQ7982X_FAULT_UV1_UV7_DET_POS   (0x06u)
#define BQ7982X_FAULT_UV1_UV7_DET_MSK   (0x40u)

#define BQ7982X_FAULT_UV1_UV6_DET_POS   (0x05u)
#define BQ7982X_FAULT_UV1_UV6_DET_MSK   (0x20u)

#define BQ7982X_FAULT_UV1_UV5_DET_POS   (0x04u)
#define BQ7982X_FAULT_UV1_UV5_DET_MSK   (0x10u)

#define BQ7982X_FAULT_UV1_UV4_DET_POS   (0x03u)
#define BQ7982X_FAULT_UV1_UV4_DET_MSK   (0x08u)

#define BQ7982X_FAULT_UV1_UV3_DET_POS   (0x02u)
#define BQ7982X_FAULT_UV1_UV3_DET_MSK   (0x04u)

#define BQ7982X_FAULT_UV1_UV2_DET_POS   (0x01u)
#define BQ7982X_FAULT_UV1_UV2_DET_MSK   (0x02u)

#define BQ7982X_FAULT_UV1_UV1_DET_POS   (0x00u)
#define BQ7982X_FAULT_UV1_UV1_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_UV2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_UV2_OFFSET    (0x0753u)
#define BQ7982X_FAULT_UV2_POR_VAL   (0x00u)

#define BQ7982X_FAULT_UV2_UV16_DET_POS   (0x07u)
#define BQ7982X_FAULT_UV2_UV16_DET_MSK   (0x80u)

#define BQ7982X_FAULT_UV2_UV15_DET_POS   (0x06u)
#define BQ7982X_FAULT_UV2_UV15_DET_MSK   (0x40u)

#define BQ7982X_FAULT_UV2_UV14_DET_POS   (0x05u)
#define BQ7982X_FAULT_UV2_UV14_DET_MSK   (0x20u)

#define BQ7982X_FAULT_UV2_UV13_DET_POS   (0x04u)
#define BQ7982X_FAULT_UV2_UV13_DET_MSK   (0x10u)

#define BQ7982X_FAULT_UV2_UV12_DET_POS   (0x03u)
#define BQ7982X_FAULT_UV2_UV12_DET_MSK   (0x08u)

#define BQ7982X_FAULT_UV2_UV11_DET_POS   (0x02u)
#define BQ7982X_FAULT_UV2_UV11_DET_MSK   (0x04u)

#define BQ7982X_FAULT_UV2_UV10_DET_POS   (0x01u)
#define BQ7982X_FAULT_UV2_UV10_DET_MSK   (0x02u)

#define BQ7982X_FAULT_UV2_UV9_DET_POS   (0x00u)
#define BQ7982X_FAULT_UV2_UV9_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_UV3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_UV3_OFFSET    (0x0754u)
#define BQ7982X_FAULT_UV3_POR_VAL   (0x00u)

#define BQ7982X_FAULT_UV3_UV24_DET_POS   (0x07u)
#define BQ7982X_FAULT_UV3_UV24_DET_MSK   (0x80u)

#define BQ7982X_FAULT_UV3_UV23_DET_POS   (0x06u)
#define BQ7982X_FAULT_UV3_UV23_DET_MSK   (0x40u)

#define BQ7982X_FAULT_UV3_UV22_DET_POS   (0x05u)
#define BQ7982X_FAULT_UV3_UV22_DET_MSK   (0x20u)

#define BQ7982X_FAULT_UV3_UV21_DET_POS   (0x04u)
#define BQ7982X_FAULT_UV3_UV21_DET_MSK   (0x10u)

#define BQ7982X_FAULT_UV3_UV20_DET_POS   (0x03u)
#define BQ7982X_FAULT_UV3_UV20_DET_MSK   (0x08u)

#define BQ7982X_FAULT_UV3_UV19_DET_POS   (0x02u)
#define BQ7982X_FAULT_UV3_UV19_DET_MSK   (0x04u)

#define BQ7982X_FAULT_UV3_UV18_DET_POS   (0x01u)
#define BQ7982X_FAULT_UV3_UV18_DET_MSK   (0x02u)

#define BQ7982X_FAULT_UV3_UV17_DET_POS   (0x00u)
#define BQ7982X_FAULT_UV3_UV17_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_UV4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_UV4_OFFSET    (0x0755u)
#define BQ7982X_FAULT_UV4_POR_VAL   (0x00u)

#define BQ7982X_FAULT_UV4_UV26_DET_POS   (0x01u)
#define BQ7982X_FAULT_UV4_UV26_DET_MSK   (0x02u)

#define BQ7982X_FAULT_UV4_UV25_DET_POS   (0x00u)
#define BQ7982X_FAULT_UV4_UV25_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_OT1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_OT1_OFFSET    (0x0757u)
#define BQ7982X_FAULT_OT1_POR_VAL   (0x00u)

#define BQ7982X_FAULT_OT1_OT8_DET_POS   (0x07u)
#define BQ7982X_FAULT_OT1_OT8_DET_MSK   (0x80u)

#define BQ7982X_FAULT_OT1_OT7_DET_POS   (0x06u)
#define BQ7982X_FAULT_OT1_OT7_DET_MSK   (0x40u)

#define BQ7982X_FAULT_OT1_OT6_DET_POS   (0x05u)
#define BQ7982X_FAULT_OT1_OT6_DET_MSK   (0x20u)

#define BQ7982X_FAULT_OT1_OT5_DET_POS   (0x04u)
#define BQ7982X_FAULT_OT1_OT5_DET_MSK   (0x10u)

#define BQ7982X_FAULT_OT1_OT4_DET_POS   (0x03u)
#define BQ7982X_FAULT_OT1_OT4_DET_MSK   (0x08u)

#define BQ7982X_FAULT_OT1_OT3_DET_POS   (0x02u)
#define BQ7982X_FAULT_OT1_OT3_DET_MSK   (0x04u)

#define BQ7982X_FAULT_OT1_OT2_DET_POS   (0x01u)
#define BQ7982X_FAULT_OT1_OT2_DET_MSK   (0x02u)

#define BQ7982X_FAULT_OT1_OT1_DET_POS   (0x00u)
#define BQ7982X_FAULT_OT1_OT1_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_OT2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_OT2_OFFSET    (0x0758u)
#define BQ7982X_FAULT_OT2_POR_VAL   (0x00u)

#define BQ7982X_FAULT_OT2_OT16_DET_POS   (0x07u)
#define BQ7982X_FAULT_OT2_OT16_DET_MSK   (0x80u)

#define BQ7982X_FAULT_OT2_OT15_DET_POS   (0x06u)
#define BQ7982X_FAULT_OT2_OT15_DET_MSK   (0x40u)

#define BQ7982X_FAULT_OT2_OT14_DET_POS   (0x05u)
#define BQ7982X_FAULT_OT2_OT14_DET_MSK   (0x20u)

#define BQ7982X_FAULT_OT2_OT13_DET_POS   (0x04u)
#define BQ7982X_FAULT_OT2_OT13_DET_MSK   (0x10u)

#define BQ7982X_FAULT_OT2_OT12_DET_POS   (0x03u)
#define BQ7982X_FAULT_OT2_OT12_DET_MSK   (0x08u)

#define BQ7982X_FAULT_OT2_OT11_DET_POS   (0x02u)
#define BQ7982X_FAULT_OT2_OT11_DET_MSK   (0x04u)

#define BQ7982X_FAULT_OT2_OT10_DET_POS   (0x01u)
#define BQ7982X_FAULT_OT2_OT10_DET_MSK   (0x02u)

#define BQ7982X_FAULT_OT2_OT9_DET_POS   (0x00u)
#define BQ7982X_FAULT_OT2_OT9_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_OT3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_OT3_OFFSET    (0x0759u)
#define BQ7982X_FAULT_OT3_POR_VAL   (0x00u)

#define BQ7982X_FAULT_OT3_OT20_DET_POS   (0x03u)
#define BQ7982X_FAULT_OT3_OT20_DET_MSK   (0x08u)

#define BQ7982X_FAULT_OT3_OT19_DET_POS   (0x02u)
#define BQ7982X_FAULT_OT3_OT19_DET_MSK   (0x04u)

#define BQ7982X_FAULT_OT3_OT18_DET_POS   (0x01u)
#define BQ7982X_FAULT_OT3_OT18_DET_MSK   (0x02u)

#define BQ7982X_FAULT_OT3_OT17_DET_POS   (0x00u)
#define BQ7982X_FAULT_OT3_OT17_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_UT1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_UT1_OFFSET    (0x075Au)
#define BQ7982X_FAULT_UT1_POR_VAL   (0x00u)

#define BQ7982X_FAULT_UT1_UT8_DET_POS   (0x07u)
#define BQ7982X_FAULT_UT1_UT8_DET_MSK   (0x80u)

#define BQ7982X_FAULT_UT1_UT7_DET_POS   (0x06u)
#define BQ7982X_FAULT_UT1_UT7_DET_MSK   (0x40u)

#define BQ7982X_FAULT_UT1_UT6_DET_POS   (0x05u)
#define BQ7982X_FAULT_UT1_UT6_DET_MSK   (0x20u)

#define BQ7982X_FAULT_UT1_UT5_DET_POS   (0x04u)
#define BQ7982X_FAULT_UT1_UT5_DET_MSK   (0x10u)

#define BQ7982X_FAULT_UT1_UT4_DET_POS   (0x03u)
#define BQ7982X_FAULT_UT1_UT4_DET_MSK   (0x08u)

#define BQ7982X_FAULT_UT1_UT3_DET_POS   (0x02u)
#define BQ7982X_FAULT_UT1_UT3_DET_MSK   (0x04u)

#define BQ7982X_FAULT_UT1_UT2_DET_POS   (0x01u)
#define BQ7982X_FAULT_UT1_UT2_DET_MSK   (0x02u)

#define BQ7982X_FAULT_UT1_UT1_DET_POS   (0x00u)
#define BQ7982X_FAULT_UT1_UT1_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_UT2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_UT2_OFFSET    (0x075Bu)
#define BQ7982X_FAULT_UT2_POR_VAL   (0x00u)

#define BQ7982X_FAULT_UT2_UT16_DET_POS   (0x07u)
#define BQ7982X_FAULT_UT2_UT16_DET_MSK   (0x80u)

#define BQ7982X_FAULT_UT2_UT15_DET_POS   (0x06u)
#define BQ7982X_FAULT_UT2_UT15_DET_MSK   (0x40u)

#define BQ7982X_FAULT_UT2_UT14_DET_POS   (0x05u)
#define BQ7982X_FAULT_UT2_UT14_DET_MSK   (0x20u)

#define BQ7982X_FAULT_UT2_UT13_DET_POS   (0x04u)
#define BQ7982X_FAULT_UT2_UT13_DET_MSK   (0x10u)

#define BQ7982X_FAULT_UT2_UT12_DET_POS   (0x03u)
#define BQ7982X_FAULT_UT2_UT12_DET_MSK   (0x08u)

#define BQ7982X_FAULT_UT2_UT11_DET_POS   (0x02u)
#define BQ7982X_FAULT_UT2_UT11_DET_MSK   (0x04u)

#define BQ7982X_FAULT_UT2_UT10_DET_POS   (0x01u)
#define BQ7982X_FAULT_UT2_UT10_DET_MSK   (0x02u)

#define BQ7982X_FAULT_UT2_UT9_DET_POS   (0x00u)
#define BQ7982X_FAULT_UT2_UT9_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_UT3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_UT3_OFFSET    (0x075Cu)
#define BQ7982X_FAULT_UT3_POR_VAL   (0x00u)

#define BQ7982X_FAULT_UT3_UT20_DET_POS   (0x03u)
#define BQ7982X_FAULT_UT3_UT20_DET_MSK   (0x08u)

#define BQ7982X_FAULT_UT3_UT19_DET_POS   (0x02u)
#define BQ7982X_FAULT_UT3_UT19_DET_MSK   (0x04u)

#define BQ7982X_FAULT_UT3_UT18_DET_POS   (0x01u)
#define BQ7982X_FAULT_UT3_UT18_DET_MSK   (0x02u)

#define BQ7982X_FAULT_UT3_UT17_DET_POS   (0x00u)
#define BQ7982X_FAULT_UT3_UT17_DET_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_GPIO1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_GPIO1_OFFSET    (0x075Eu)
#define BQ7982X_FAULT_ADC_GPIO1_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO8_AFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO8_AFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO7_AFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO7_AFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO6_AFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO6_AFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO5_AFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO5_AFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO4_AFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO4_AFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO3_AFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO3_AFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO2_AFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO2_AFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_GPIO1_GPIO1_AFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_GPIO1_GPIO1_AFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_GPIO2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_GPIO2_OFFSET    (0x075Fu)
#define BQ7982X_FAULT_ADC_GPIO2_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO16_AFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO16_AFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO15_AFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO15_AFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO14_AFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO14_AFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO13_AFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO13_AFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO12_AFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO12_AFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO11_AFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO11_AFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO10_AFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO10_AFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_GPIO2_GPIO9_AFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_GPIO2_GPIO9_AFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_GPIO3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_GPIO3_OFFSET    (0x0760u)
#define BQ7982X_FAULT_ADC_GPIO3_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_GPIO3_GPIO20_AFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_GPIO3_GPIO20_AFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_GPIO3_GPIO19_AFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_GPIO3_GPIO19_AFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_GPIO3_GPIO18_AFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_GPIO3_GPIO18_AFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_GPIO3_GPIO17_AFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_GPIO3_GPIO17_AFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_VCELL1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_VCELL1_OFFSET    (0x0761u)
#define BQ7982X_FAULT_ADC_VCELL1_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL8_AFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL8_AFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL7_AFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL7_AFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL6_AFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL6_AFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL5_AFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL5_AFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL4_AFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL4_AFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL3_AFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL3_AFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL2_AFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL2_AFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_VCELL1_CELL1_AFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_VCELL1_CELL1_AFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_VCELL2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_VCELL2_OFFSET    (0x0762u)
#define BQ7982X_FAULT_ADC_VCELL2_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL16_AFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL16_AFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL15_AFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL15_AFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL14_AFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL14_AFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL13_AFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL13_AFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL12_AFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL12_AFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL11_AFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL11_AFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL10_AFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL10_AFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_VCELL2_CELL9_AFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_VCELL2_CELL9_AFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_VCELL3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_VCELL3_OFFSET    (0x0763u)
#define BQ7982X_FAULT_ADC_VCELL3_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL24_AFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL24_AFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL23_AFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL23_AFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL22_AFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL22_AFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL21_AFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL21_AFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL20_AFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL20_AFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL19_AFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL19_AFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL18_AFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL18_AFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_VCELL3_CELL17_AFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_VCELL3_CELL17_AFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_VCELL4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_VCELL4_OFFSET    (0x0764u)
#define BQ7982X_FAULT_ADC_VCELL4_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_VCELL4_CELL26_AFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_VCELL4_CELL26_AFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_VCELL4_CELL25_AFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_VCELL4_CELL25_AFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_DIG1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_DIG1_OFFSET    (0x0765u)
#define BQ7982X_FAULT_ADC_DIG1_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL8_DFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL8_DFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL7_DFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL7_DFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL6_DFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL6_DFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL5_DFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL5_DFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL4_DFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL4_DFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL3_DFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL3_DFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL2_DFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL2_DFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_DIG1_CELL1_DFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_DIG1_CELL1_DFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_DIG2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_DIG2_OFFSET    (0x0766u)
#define BQ7982X_FAULT_ADC_DIG2_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL16_DFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL16_DFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL15_DFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL15_DFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL14_DFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL14_DFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL13_DFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL13_DFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL12_DFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL12_DFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL11_DFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL11_DFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL10_DFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL10_DFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_DIG2_CELL9_DFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_DIG2_CELL9_DFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_DIG3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_DIG3_OFFSET    (0x0767u)
#define BQ7982X_FAULT_ADC_DIG3_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL24_DFAIL   (0x07u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL24_DFAIL   (0x80u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL23_DFAIL   (0x06u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL23_DFAIL   (0x40u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL22_DFAIL   (0x05u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL22_DFAIL   (0x20u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL21_DFAIL   (0x04u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL21_DFAIL   (0x10u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL20_DFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL20_DFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL19_DFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL19_DFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL18_DFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL18_DFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_DIG3_CELL17_DFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_DIG3_CELL17_DFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_DIG4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_DIG4_OFFSET    (0x0768u)
#define BQ7982X_FAULT_ADC_DIG4_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_DIG4_CELL26_DFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_DIG4_CELL26_DFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_DIG4_CELL25_DFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_DIG4_CELL25_DFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_DIG5           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_DIG5_OFFSET    (0x0769u)
#define BQ7982X_FAULT_ADC_DIG5_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_DIG5_CS_DFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_DIG5_CS_DFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_DIG5_GP3_DFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_DIG5_GP3_DFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_DIG5_GP1_DFAIL   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_DIG5_GP1_DFAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_ADC_MISC           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_ADC_MISC_OFFSET    (0x076Au)
#define BQ7982X_FAULT_ADC_MISC_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_ADC_MISC_ADC_PFAIL   (0x03u)
#define BQ7982X_MSK_FAULT_ADC_MISC_ADC_PFAIL   (0x08u)

#define BQ7982X_POS_FAULT_ADC_MISC_DIAG_MEAS_PFAIL   (0x02u)
#define BQ7982X_MSK_FAULT_ADC_MISC_DIAG_MEAS_PFAIL   (0x04u)

#define BQ7982X_POS_FAULT_ADC_MISC_DIAG_ANA_PFAIL   (0x01u)
#define BQ7982X_MSK_FAULT_ADC_MISC_DIAG_ANA_PFAIL   (0x02u)

#define BQ7982X_POS_FAULT_ADC_MISC_DIAG_ABORT   (0x00u)
#define BQ7982X_MSK_FAULT_ADC_MISC_DIAG_ABORT   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_CB_FETOW1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_CB_FETOW1_OFFSET    (0x076Cu)
#define BQ7982X_FAULT_CB_FETOW1_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB8_FAIL   (0x07u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB8_FAIL   (0x80u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB7_FAIL   (0x06u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB7_FAIL   (0x40u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB6_FAIL   (0x05u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB6_FAIL   (0x20u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB5_FAIL   (0x04u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB5_FAIL   (0x10u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB4_FAIL   (0x03u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB4_FAIL   (0x08u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB3_FAIL   (0x02u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB3_FAIL   (0x04u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB2_FAIL   (0x01u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB2_FAIL   (0x02u)

#define BQ7982X_POS_FAULT_CB_FETOW1_CB1_FAIL   (0x00u)
#define BQ7982X_MSK_FAULT_CB_FETOW1_CB1_FAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_CB_FETOW2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_CB_FETOW2_OFFSET    (0x076Du)
#define BQ7982X_FAULT_CB_FETOW2_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB16_FAIL   (0x07u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB16_FAIL   (0x80u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB15_FAIL   (0x06u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB15_FAIL   (0x40u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB14_FAIL   (0x05u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB14_FAIL   (0x20u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB13_FAIL   (0x04u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB13_FAIL   (0x10u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB12_FAIL   (0x03u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB12_FAIL   (0x08u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB11_FAIL   (0x02u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB11_FAIL   (0x04u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB10_FAIL   (0x01u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB10_FAIL   (0x02u)

#define BQ7982X_POS_FAULT_CB_FETOW2_CB9_FAIL   (0x00u)
#define BQ7982X_MSK_FAULT_CB_FETOW2_CB9_FAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_CB_FETOW3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_CB_FETOW3_OFFSET    (0x076Eu)
#define BQ7982X_FAULT_CB_FETOW3_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB24_FAIL   (0x07u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB24_FAIL   (0x80u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB23_FAIL   (0x06u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB23_FAIL   (0x40u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB22_FAIL   (0x05u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB22_FAIL   (0x20u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB21_FAIL   (0x04u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB21_FAIL   (0x10u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB20_FAIL   (0x03u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB20_FAIL   (0x08u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB19_FAIL   (0x02u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB19_FAIL   (0x04u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB18_FAIL   (0x01u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB18_FAIL   (0x02u)

#define BQ7982X_POS_FAULT_CB_FETOW3_CB17_FAIL   (0x00u)
#define BQ7982X_MSK_FAULT_CB_FETOW3_CB17_FAIL   (0x01u)

/* --------------------------------------------------------------------------
 * FAULT_CB_FETOW4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_FAULT_CB_FETOW4_OFFSET    (0x076Fu)
#define BQ7982X_FAULT_CB_FETOW4_POR_VAL   (0x00u)

#define BQ7982X_POS_FAULT_CB_FETOW4_CB26_FAIL   (0x01u)
#define BQ7982X_MSK_FAULT_CB_FETOW4_CB26_FAIL   (0x02u)

#define BQ7982X_POS_FAULT_CB_FETOW4_CB25_FAIL   (0x00u)
#define BQ7982X_MSK_FAULT_CB_FETOW4_CB25_FAIL   (0x01u)

/* --------------------------------------------------------------------------
 * PROP_DLY_STAT1     (RP):
 * -------------------------------------------------------------------------- */
#define BQ7982X_PROP_DLY_STAT1_OFFSET    (0x0780u)
#define BQ7982X_PROP_DLY_STAT1_POR_VAL   (0x00u)

#define BQ7982X_PROP_DLY_STAT1_COUNTH_POS   (0x00u)
#define BQ7982X_PROP_DLY_STAT1_COUNTH_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * PROP_DLY_STAT2     (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_PROP_DLY_STAT2_OFFSET    (0x0781u)
#define BQ7982X_PROP_DLY_STAT2_POR_VAL   (0x00u)

#define BQ7982X_PROP_DLY_STAT2_COUNTL_POS   (0x00u)
#define BQ7982X_PROP_DLY_STAT2_COUNTL_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * HFO_FREQ_STAT1     (RP):
 * -------------------------------------------------------------------------- */
#define BQ7982X_HFO_FREQ_STAT1_OFFSET    (0x0782u)
#define BQ7982X_HFO_FREQ_STAT1_POR_VAL   (0x00u)

#define BQ7982X_HFO_FREQ_STAT1_FREQH_POS   (0x00u)
#define BQ7982X_HFO_FREQ_STAT1_FREQH_MSK   (0x03u)

/* --------------------------------------------------------------------------
 * HFO_FREQ_STAT2     (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_HFO_FREQ_STAT2_OFFSET    (0x0783u)
#define BQ7982X_HFO_FREQ_STAT2_POR_VAL   (0x00u)

#define BQ7982X_HFO_FREQ_STAT2_FREQL_POS   (0x00u)
#define BQ7982X_HFO_FREQ_STAT2_FREQL_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIG_SYNC_STAT1     (RP):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_STAT1_OFFSET    (0x0784u)
#define BQ7982X_DIG_SYNC_STAT1_POR_VAL   (0x00u)

#define BQ7982X_POS_DIG_SYNC_STAT1_SYNC_COUNTH   (0x00u)
#define BQ7982X_MSK_DIG_SYNC_STAT1_SYNC_COUNTH   (0xFFu)

/* --------------------------------------------------------------------------
 * DIG_SYNC_STAT2     (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIG_SYNC_STAT2_OFFSET    (0x0785u)
#define BQ7982X_DIG_SYNC_STAT2_POR_VAL   (0x00u)

#define BQ7982X_POS_DIG_SYNC_STAT2_SYNC_COUNTL   (0x00u)
#define BQ7982X_MSK_DIG_SYNC_STAT2_SYNC_COUNTL   (0xFFu)

/* --------------------------------------------------------------------------
 * SMART_FREEZE_STAT1     (RP):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMART_FREEZE_STAT1_OFFSET    (0x078Bu)
#define BQ7982X_SMART_FREEZE_STAT1_POR_VAL   (0x00u)

#define BQ7982X_POS_SMART_FREEZE_STAT1_SAMP_COUNTH   (0x00u)
#define BQ7982X_MSK_SMART_FREEZE_STAT1_SAMP_COUNTH   (0x1Fu)

/* --------------------------------------------------------------------------
 * SMART_FREEZE_STAT2     (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMART_FREEZE_STAT2_OFFSET    (0x078Cu)
#define BQ7982X_SMART_FREEZE_STAT2_POR_VAL   (0x00u)

#define BQ7982X_POS_SMART_FREEZE_STAT2_SAMP_COUNTL   (0x00u)
#define BQ7982X_MSK_SMART_FREEZE_STAT2_SAMP_COUNTL   (0xFFu)

/* --------------------------------------------------------------------------
 * SMART_FREEZE_STAT3     (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMART_FREEZE_STAT3_OFFSET    (0x078Du)
#define BQ7982X_SMART_FREEZE_STAT3_POR_VAL   (0x00u)

#define BQ7982X_POS_SMART_FREEZE_STAT3_SLOT_COUNT   (0x00u)
#define BQ7982X_MSK_SMART_FREEZE_STAT3_SLOT_COUNT   (0xFFu)

/* --------------------------------------------------------------------------
 * SYNC_STAT1     (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SYNC_STAT1_OFFSET    (0x0789u)
#define BQ7982X_SYNC_STAT1_POR_VAL   (0x00u)

#define BQ7982X_POS_SYNC_STAT1_HFO_FREQ_DONE   (0x05u)
#define BQ7982X_MSK_SYNC_STAT1_HFO_FREQ_DONE   (0x20u)

#define BQ7982X_POS_SYNC_STAT1_PROP_DLY_DONE   (0x04u)
#define BQ7982X_MSK_SYNC_STAT1_PROP_DLY_DONE   (0x10u)

#define BQ7982X_SYNC_STAT1_PLL_LOCK_POS        (0x03u)
#define BQ7982X_SYNC_STAT1_PLL_LOCK_MSK        (0x08u)

#define BQ7982X_POS_SYNC_STAT1_PLL_SYNC_DONE   (0x02u)
#define BQ7982X_MSK_SYNC_STAT1_PLL_SYNC_DONE   (0x04u)

#define BQ7982X_POS_SYNC_STAT1_DIG_SYNC_DONE   (0x01u)
#define BQ7982X_MSK_SYNC_STAT1_DIG_SYNC_DONE   (0x02u)

#define BQ7982X_SYNC_STAT1_DRDY_SF_POS   (0x00u)
#define BQ7982X_SYNC_STAT1_DRDY_SF_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * VCELL26_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL26_HI_OFFSET    (0x079Cu)
#define BQ7982X_VCELL26_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL26_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL26_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL26_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL26_LO_OFFSET    (0x079Du)
#define BQ7982X_VCELL26_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL26_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL26_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL25_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL25_HI_OFFSET    (0x079Eu)
#define BQ7982X_VCELL25_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL25_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL25_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL25_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL25_LO_OFFSET    (0x079Fu)
#define BQ7982X_VCELL25_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL25_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL25_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL24_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL24_HI_OFFSET    (0x07A0u)
#define BQ7982X_VCELL24_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL24_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL24_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL24_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL24_LO_OFFSET    (0x07A1u)
#define BQ7982X_VCELL24_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL24_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL24_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL23_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL23_HI_OFFSET    (0x07A2u)
#define BQ7982X_VCELL23_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL23_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL23_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL23_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL23_LO_OFFSET    (0x07A3u)
#define BQ7982X_VCELL23_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL23_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL23_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL22_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL22_HI_OFFSET    (0x07A4u)
#define BQ7982X_VCELL22_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL22_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL22_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL22_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL22_LO_OFFSET    (0x07A5u)
#define BQ7982X_VCELL22_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL22_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL22_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL21_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL21_HI_OFFSET    (0x07A6u)
#define BQ7982X_VCELL21_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL21_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL21_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL21_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL21_LO_OFFSET    (0x07A7u)
#define BQ7982X_VCELL21_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL21_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL21_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL20_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL20_HI_OFFSET    (0x07A8u)
#define BQ7982X_VCELL20_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL20_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL20_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL20_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL20_LO_OFFSET    (0x07A9u)
#define BQ7982X_VCELL20_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL20_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL20_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL19_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL19_HI_OFFSET    (0x07AAu)
#define BQ7982X_VCELL19_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL19_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL19_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL19_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL19_LO_OFFSET    (0x07ABu)
#define BQ7982X_VCELL19_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL19_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL19_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL18_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL18_HI_OFFSET    (0x07ACu)
#define BQ7982X_VCELL18_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL18_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL18_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL18_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL18_LO_OFFSET    (0x07ADu)
#define BQ7982X_VCELL18_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL18_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL18_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL17_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL17_HI_OFFSET    (0x07AEu)
#define BQ7982X_VCELL17_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL17_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL17_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL17_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL17_LO_OFFSET    (0x07AFu)
#define BQ7982X_VCELL17_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL17_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL17_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL16_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL16_HI_OFFSET    (0x07B0u)
#define BQ7982X_VCELL16_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL16_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL16_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL16_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL16_LO_OFFSET    (0x07B1u)
#define BQ7982X_VCELL16_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL16_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL16_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL15_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL15_HI_OFFSET    (0x07B2u)
#define BQ7982X_VCELL15_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL15_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL15_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL15_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL15_LO_OFFSET    (0x07B3u)
#define BQ7982X_VCELL15_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL15_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL15_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL14_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL14_HI_OFFSET    (0x07B4u)
#define BQ7982X_VCELL14_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL14_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL14_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL14_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL14_LO_OFFSET    (0x07B5u)
#define BQ7982X_VCELL14_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL14_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL14_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL13_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL13_HI_OFFSET    (0x07B6u)
#define BQ7982X_VCELL13_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL13_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL13_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL13_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL13_LO_OFFSET    (0x07B7u)
#define BQ7982X_VCELL13_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL13_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL13_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL12_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL12_HI_OFFSET    (0x07B8u)
#define BQ7982X_VCELL12_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL12_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL12_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL12_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL12_LO_OFFSET    (0x07B9u)
#define BQ7982X_VCELL12_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL12_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL12_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL11_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL11_HI_OFFSET    (0x07BAu)
#define BQ7982X_VCELL11_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL11_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL11_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL11_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL11_LO_OFFSET    (0x07BBu)
#define BQ7982X_VCELL11_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL11_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL11_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL10_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL10_HI_OFFSET    (0x07BCu)
#define BQ7982X_VCELL10_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL10_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL10_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL10_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL10_LO_OFFSET    (0x07BDu)
#define BQ7982X_VCELL10_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL10_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL10_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL9_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL9_HI_OFFSET    (0x07BEu)
#define BQ7982X_VCELL9_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL9_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL9_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL9_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL9_LO_OFFSET    (0x07BFu)
#define BQ7982X_VCELL9_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL9_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL9_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL8_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL8_HI_OFFSET    (0x07C0u)
#define BQ7982X_VCELL8_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL8_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL8_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL8_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL8_LO_OFFSET    (0x07C1u)
#define BQ7982X_VCELL8_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL8_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL8_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL7_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL7_HI_OFFSET    (0x07C2u)
#define BQ7982X_VCELL7_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL7_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL7_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL7_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL7_LO_OFFSET    (0x07C3u)
#define BQ7982X_VCELL7_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL7_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL7_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL6_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL6_HI_OFFSET    (0x07C4u)
#define BQ7982X_VCELL6_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL6_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL6_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL6_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL6_LO_OFFSET    (0x07C5u)
#define BQ7982X_VCELL6_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL6_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL6_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL5_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL5_HI_OFFSET    (0x07C6u)
#define BQ7982X_VCELL5_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL5_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL5_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL5_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL5_LO_OFFSET    (0x07C7u)
#define BQ7982X_VCELL5_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL5_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL5_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL4_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL4_HI_OFFSET    (0x07C8u)
#define BQ7982X_VCELL4_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL4_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL4_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL4_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL4_LO_OFFSET    (0x07C9u)
#define BQ7982X_VCELL4_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL4_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL4_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL3_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL3_HI_OFFSET    (0x07CAu)
#define BQ7982X_VCELL3_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL3_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL3_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL3_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL3_LO_OFFSET    (0x07CBu)
#define BQ7982X_VCELL3_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL3_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL3_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL2_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL2_HI_OFFSET    (0x07CCu)
#define BQ7982X_VCELL2_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL2_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL2_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL2_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL2_LO_OFFSET    (0x07CDu)
#define BQ7982X_VCELL2_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL2_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL2_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL1_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL1_HI_OFFSET    (0x07CEu)
#define BQ7982X_VCELL1_HI_POR_VAL   (0xFFu)

#define BQ7982X_VCELL1_HI_RESULT_POS   (0x00u)
#define BQ7982X_VCELL1_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL1_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL1_LO_OFFSET    (0x07CFu)
#define BQ7982X_VCELL1_LO_POR_VAL   (0xFFu)

#define BQ7982X_VCELL1_LO_RESULT_POS   (0x00u)
#define BQ7982X_VCELL1_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL_ACT_SUM_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_ACT_SUM_HI_OFFSET    (0x07D0u)
#define BQ7982X_VCELL_ACT_SUM_HI_POR_VAL   (0xFFu)

#define BQ7982X_POS_VCELL_ACT_SUM_HI_RESULT   (0x00u)
#define BQ7982X_MSK_VCELL_ACT_SUM_HI_RESULT   (0xFFu)

/* --------------------------------------------------------------------------
 * VCELL_ACT_SUM_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_VCELL_ACT_SUM_LO_OFFSET    (0x07D1u)
#define BQ7982X_VCELL_ACT_SUM_LO_POR_VAL   (0xFFu)

#define BQ7982X_POS_VCELL_ACT_SUM_LO_RESULT   (0x00u)
#define BQ7982X_MSK_VCELL_ACT_SUM_LO_RESULT   (0xFFu)

/* --------------------------------------------------------------------------
 * BAT_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAT_HI_OFFSET    (0x07D2u)
#define BQ7982X_BAT_HI_POR_VAL   (0xFFu)

#define BQ7982X_BAT_HI_RESULT_POS   (0x00u)
#define BQ7982X_BAT_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * BAT_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_BAT_LO_OFFSET    (0x07D3u)
#define BQ7982X_BAT_LO_POR_VAL   (0xFFu)

#define BQ7982X_BAT_LO_RESULT_POS   (0x00u)
#define BQ7982X_BAT_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CURRENT1_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CURRENT1_HI_OFFSET    (0x07D4u)
#define BQ7982X_CURRENT1_HI_POR_VAL   (0x80u)

#define BQ7982X_CURRENT1_HI_RESULT_POS   (0x00u)
#define BQ7982X_CURRENT1_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CURRENT1_MID           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CURRENT1_MID_OFFSET    (0x07D5u)
#define BQ7982X_CURRENT1_MID_POR_VAL   (0x00u)

#define BQ7982X_CURRENT1_MID_RESULT_POS   (0x00u)
#define BQ7982X_CURRENT1_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CURRENT1_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CURRENT1_LO_OFFSET    (0x07D6u)
#define BQ7982X_CURRENT1_LO_POR_VAL   (0x00u)

#define BQ7982X_CURRENT1_LO_RESULT_POS   (0x00u)
#define BQ7982X_CURRENT1_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * SMON_PEAK_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMON_PEAK_HI_OFFSET    (0x0810u)
#define BQ7982X_SMON_PEAK_HI_POR_VAL   (0xFFu)

#define BQ7982X_SMON_PEAK_HI_RESULT_POS   (0x00u)
#define BQ7982X_SMON_PEAK_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * SMON_PEAK_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_SMON_PEAK_LO_OFFSET    (0x0811u)
#define BQ7982X_SMON_PEAK_LO_POR_VAL   (0xFFu)

#define BQ7982X_SMON_PEAK_LO_RESULT_POS   (0x00u)
#define BQ7982X_SMON_PEAK_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO1_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO1_HI_OFFSET    (0x0812u)
#define BQ7982X_GPIO1_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO1_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO1_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO1_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO1_LO_OFFSET    (0x0813u)
#define BQ7982X_GPIO1_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO1_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO1_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO2_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO2_HI_OFFSET    (0x0814u)
#define BQ7982X_GPIO2_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO2_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO2_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO2_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO2_LO_OFFSET    (0x0815u)
#define BQ7982X_GPIO2_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO2_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO2_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO3_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO3_HI_OFFSET    (0x0816u)
#define BQ7982X_GPIO3_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO3_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO3_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO3_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO3_LO_OFFSET    (0x0817u)
#define BQ7982X_GPIO3_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO3_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO3_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO4_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO4_HI_OFFSET    (0x0818u)
#define BQ7982X_GPIO4_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO4_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO4_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO4_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO4_LO_OFFSET    (0x0819u)
#define BQ7982X_GPIO4_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO4_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO4_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO5_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO5_HI_OFFSET    (0x081Au)
#define BQ7982X_GPIO5_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO5_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO5_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO5_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO5_LO_OFFSET    (0x081Bu)
#define BQ7982X_GPIO5_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO5_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO5_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO6_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO6_HI_OFFSET    (0x081Cu)
#define BQ7982X_GPIO6_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO6_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO6_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO6_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO6_LO_OFFSET    (0x081Du)
#define BQ7982X_GPIO6_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO6_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO6_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO7_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO7_HI_OFFSET    (0x081Eu)
#define BQ7982X_GPIO7_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO7_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO7_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO7_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO7_LO_OFFSET    (0x081Fu)
#define BQ7982X_GPIO7_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO7_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO7_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO8_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO8_HI_OFFSET    (0x0820u)
#define BQ7982X_GPIO8_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO8_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO8_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO8_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO8_LO_OFFSET    (0x0821u)
#define BQ7982X_GPIO8_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO8_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO8_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO9_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO9_HI_OFFSET    (0x0822u)
#define BQ7982X_GPIO9_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO9_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO9_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO9_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO9_LO_OFFSET    (0x0823u)
#define BQ7982X_GPIO9_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO9_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO9_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO10_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO10_HI_OFFSET    (0x0824u)
#define BQ7982X_GPIO10_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO10_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO10_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO10_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO10_LO_OFFSET    (0x0825u)
#define BQ7982X_GPIO10_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO10_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO10_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO11_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO11_HI_OFFSET    (0x0826u)
#define BQ7982X_GPIO11_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO11_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO11_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO11_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO11_LO_OFFSET    (0x0827u)
#define BQ7982X_GPIO11_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO11_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO11_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO12_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO12_HI_OFFSET    (0x0828u)
#define BQ7982X_GPIO12_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO12_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO12_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO12_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO12_LO_OFFSET    (0x0829u)
#define BQ7982X_GPIO12_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO12_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO12_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO13_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO13_HI_OFFSET    (0x082Au)
#define BQ7982X_GPIO13_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO13_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO13_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO13_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO13_LO_OFFSET    (0x082Bu)
#define BQ7982X_GPIO13_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO13_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO13_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO14_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO14_HI_OFFSET    (0x082Cu)
#define BQ7982X_GPIO14_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO14_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO14_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO14_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO14_LO_OFFSET    (0x082Du)
#define BQ7982X_GPIO14_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO14_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO14_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO15_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO15_HI_OFFSET    (0x082Eu)
#define BQ7982X_GPIO15_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO15_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO15_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO15_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO15_LO_OFFSET    (0x082Fu)
#define BQ7982X_GPIO15_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO15_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO15_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO16_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO16_HI_OFFSET    (0x0830u)
#define BQ7982X_GPIO16_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO16_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO16_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO16_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO16_LO_OFFSET    (0x0831u)
#define BQ7982X_GPIO16_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO16_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO16_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO17_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO17_HI_OFFSET    (0x0832u)
#define BQ7982X_GPIO17_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO17_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO17_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO17_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO17_LO_OFFSET    (0x0833u)
#define BQ7982X_GPIO17_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO17_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO17_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO18_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO18_HI_OFFSET    (0x0834u)
#define BQ7982X_GPIO18_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO18_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO18_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO18_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO18_LO_OFFSET    (0x0835u)
#define BQ7982X_GPIO18_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO18_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO18_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO19_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO19_HI_OFFSET    (0x0836u)
#define BQ7982X_GPIO19_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO19_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO19_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO19_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO19_LO_OFFSET    (0x0837u)
#define BQ7982X_GPIO19_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO19_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO19_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO20_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO20_HI_OFFSET    (0x0838u)
#define BQ7982X_GPIO20_HI_POR_VAL   (0xFFu)

#define BQ7982X_GPIO20_HI_RESULT_POS   (0x00u)
#define BQ7982X_GPIO20_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * GPIO20_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_GPIO20_LO_OFFSET    (0x0839u)
#define BQ7982X_GPIO20_LO_POR_VAL   (0xFFu)

#define BQ7982X_GPIO20_LO_RESULT_POS   (0x00u)
#define BQ7982X_GPIO20_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG1_MAIN_HI           (RP):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG1_MAIN_HI_OFFSET    (0x0860u)
#define BQ7982X_DIAG1_MAIN_HI_POR_VAL   (0xFFu)

#define BQ7982X_DIAG1_MAIN_HI_RESULT_POS   (0x00u)
#define BQ7982X_DIAG1_MAIN_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG1_MAIN_MID           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG1_MAIN_MID_OFFSET    (0x0861u)
#define BQ7982X_DIAG1_MAIN_MID_POR_VAL   (0xFFu)

#define BQ7982X_DIAG1_MAIN_MID_RESULT_POS   (0x00u)
#define BQ7982X_DIAG1_MAIN_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG1_MAIN_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG1_MAIN_LO_OFFSET    (0x0862u)
#define BQ7982X_DIAG1_MAIN_LO_POR_VAL   (0xFFu)

#define BQ7982X_DIAG1_MAIN_LO_RESULT_POS   (0x00u)
#define BQ7982X_DIAG1_MAIN_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG1_RDNT_HI           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG1_RDNT_HI_OFFSET    (0x0863u)
#define BQ7982X_DIAG1_RDNT_HI_POR_VAL   (0xFFu)

#define BQ7982X_DIAG1_RDNT_HI_RESULT_POS   (0x00u)
#define BQ7982X_DIAG1_RDNT_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG1_RDNT_MID           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG1_RDNT_MID_OFFSET    (0x0864u)
#define BQ7982X_DIAG1_RDNT_MID_POR_VAL   (0xFFu)

#define BQ7982X_DIAG1_RDNT_MID_RESULT_POS   (0x00u)
#define BQ7982X_DIAG1_RDNT_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG1_RDNT_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG1_RDNT_LO_OFFSET    (0x0865u)
#define BQ7982X_DIAG1_RDNT_LO_POR_VAL   (0xFFu)

#define BQ7982X_DIAG1_RDNT_LO_RESULT_POS   (0x00u)
#define BQ7982X_DIAG1_RDNT_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIETEMP1_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIETEMP1_HI_OFFSET    (0x0866u)
#define BQ7982X_DIETEMP1_HI_POR_VAL   (0x80u)

#define BQ7982X_DIETEMP1_HI_RESULT_POS   (0x00u)
#define BQ7982X_DIETEMP1_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIETEMP1_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIETEMP1_LO_OFFSET    (0x0867u)
#define BQ7982X_DIETEMP1_LO_POR_VAL   (0x00u)

#define BQ7982X_DIETEMP1_LO_RESULT_POS   (0x00u)
#define BQ7982X_DIETEMP1_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIETEMP2_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIETEMP2_HI_OFFSET    (0x0868u)
#define BQ7982X_DIETEMP2_HI_POR_VAL   (0x80u)

#define BQ7982X_DIETEMP2_HI_RESULT_POS   (0x00u)
#define BQ7982X_DIETEMP2_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIETEMP2_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIETEMP2_LO_OFFSET    (0x0869u)
#define BQ7982X_DIETEMP2_LO_POR_VAL   (0x00u)

#define BQ7982X_DIETEMP2_LO_RESULT_POS   (0x00u)
#define BQ7982X_DIETEMP2_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * REF_CAP_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_REF_CAP_HI_OFFSET    (0x086Au)
#define BQ7982X_REF_CAP_HI_POR_VAL   (0xFFu)

#define BQ7982X_REF_CAP_HI_RESULT_POS   (0x00u)
#define BQ7982X_REF_CAP_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * REF_CAP_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_REF_CAP_LO_OFFSET    (0x086Bu)
#define BQ7982X_REF_CAP_LO_POR_VAL   (0xFFu)

#define BQ7982X_REF_CAP_LO_RESULT_POS   (0x00u)
#define BQ7982X_REF_CAP_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG_D1_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_D1_HI_OFFSET    (0x086Cu)
#define BQ7982X_DIAG_D1_HI_POR_VAL   (0xFFu)

#define BQ7982X_DIAG_D1_HI_RESULT_POS   (0x00u)
#define BQ7982X_DIAG_D1_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG_D1_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_D1_LO_OFFSET    (0x086Du)
#define BQ7982X_DIAG_D1_LO_POR_VAL   (0xFFu)

#define BQ7982X_DIAG_D1_LO_RESULT_POS   (0x00u)
#define BQ7982X_DIAG_D1_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG_D2_HI           (RM):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_D2_HI_OFFSET    (0x086Eu)
#define BQ7982X_DIAG_D2_HI_POR_VAL   (0xFFu)

#define BQ7982X_DIAG_D2_HI_RESULT_POS   (0x00u)
#define BQ7982X_DIAG_D2_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DIAG_D2_LO           (RS):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DIAG_D2_LO_OFFSET    (0x086Fu)
#define BQ7982X_DIAG_D2_LO_POR_VAL   (0xFFu)

#define BQ7982X_DIAG_D2_LO_RESULT_POS   (0x00u)
#define BQ7982X_DIAG_D2_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * REF_CAP_T0_HI           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_REF_CAP_T0_HI_OFFSET    (0x0870u)
#define BQ7982X_REF_CAP_T0_HI_POR_VAL   (0xFFu)

#define BQ7982X_REF_CAP_T0_HI_RESULT_POS   (0x00u)
#define BQ7982X_REF_CAP_T0_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * REF_CAP_T0_LO           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_REF_CAP_T0_LO_OFFSET    (0x0871u)
#define BQ7982X_REF_CAP_T0_LO_POR_VAL   (0xFFu)

#define BQ7982X_REF_CAP_T0_LO_RESULT_POS   (0x00u)
#define BQ7982X_REF_CAP_T0_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * I2C_RD_DATA           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_I2C_RD_DATA_OFFSET    (0x0880u)
#define BQ7982X_I2C_RD_DATA_POR_VAL   (0x00u)

#define BQ7982X_I2C_RD_DATA_DATA_POS   (0x00u)
#define BQ7982X_I2C_RD_DATA_DATA_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CSPI_RX4           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_RX4_OFFSET    (0x0890u)
#define BQ7982X_CSPI_RX4_POR_VAL   (0x00u)

#define BQ7982X_CSPI_RX4_DATA_POS   (0x00u)
#define BQ7982X_CSPI_RX4_DATA_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CSPI_RX3           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_RX3_OFFSET    (0x0891u)
#define BQ7982X_CSPI_RX3_POR_VAL   (0x00u)

#define BQ7982X_CSPI_RX3_DATA_POS   (0x00u)
#define BQ7982X_CSPI_RX3_DATA_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CSPI_RX2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_RX2_OFFSET    (0x0892u)
#define BQ7982X_CSPI_RX2_POR_VAL   (0x00u)

#define BQ7982X_CSPI_RX2_DATA_POS   (0x00u)
#define BQ7982X_CSPI_RX2_DATA_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * CSPI_RX1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_CSPI_RX1_OFFSET    (0x0893u)
#define BQ7982X_CSPI_RX1_POR_VAL   (0x00u)

#define BQ7982X_CSPI_RX1_DATA_POS   (0x00u)
#define BQ7982X_CSPI_RX1_DATA_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_STAT            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_STAT_OFFSET    (0x0A00u)
#define BQ7982X_EIS_STAT_POR_VAL   (0x00u)

#define BQ7982X_EIS_STAT_EIS_DFT_DRDY_POS   (0x03u)
#define BQ7982X_EIS_STAT_EIS_DFT_DRDY_MSK   (0x08u)

#define BQ7982X_EIS_STAT_EIS_DFT_RUN_POS   (0x02u)
#define BQ7982X_EIS_STAT_EIS_DFT_RUN_MSK   (0x04u)

#define BQ7982X_EIS_STAT_EIS_DFE_RUN_POS   (0x01u)
#define BQ7982X_EIS_STAT_EIS_DFE_RUN_MSK   (0x02u)

#define BQ7982X_EIS_STAT_EIS_PWM_RUN_POS   (0x00u)
#define BQ7982X_EIS_STAT_EIS_PWM_RUN_MSK   (0x01u)

/* --------------------------------------------------------------------------
 * EIS_SYNC_PHASE1            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_SYNC_PHASE1_OFFSET    (0x0A01u)
#define BQ7982X_EIS_SYNC_PHASE1_POR_VAL   (0x80u)

#define BQ7982X_POS_EIS_SYNC_PHASE1_RESULT   (0x00u)
#define BQ7982X_MSK_EIS_SYNC_PHASE1_RESULT   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_SYNC_PHASE2            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_SYNC_PHASE2_OFFSET    (0x0A02u)
#define BQ7982X_EIS_SYNC_PHASE2_POR_VAL   (0x00u)

#define BQ7982X_POS_EIS_SYNC_PHASE2_RESULT   (0x00u)
#define BQ7982X_MSK_EIS_SYNC_PHASE2_RESULT   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_SYNC_PHASE3            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_SYNC_PHASE3_OFFSET    (0x0A03u)
#define BQ7982X_EIS_SYNC_PHASE3_POR_VAL   (0x00u)

#define BQ7982X_POS_EIS_SYNC_PHASE3_RESULT   (0x00u)
#define BQ7982X_MSK_EIS_SYNC_PHASE3_RESULT   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_CS_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_CS_HI_OFFSET    (0x0A10u)
#define BQ7982X_EIS_CS_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_CS_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_CS_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_CS_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_CS_MID_OFFSET    (0x0A11u)
#define BQ7982X_EIS_CS_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_CS_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_CS_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_CS_LOW            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_CS_LOW_OFFSET    (0x0A12u)
#define BQ7982X_EIS_CS_LOW_POR_VAL   (0x00u)

#define BQ7982X_EIS_CS_LOW_RESULT_POS   (0x00u)
#define BQ7982X_EIS_CS_LOW_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC1_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC1_HI_OFFSET    (0x0A13u)
#define BQ7982X_EIS_VC1_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC1_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC1_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC1_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC1_MID_OFFSET    (0x0A14u)
#define BQ7982X_EIS_VC1_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC1_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC1_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC1_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC1_LO_OFFSET    (0x0A15u)
#define BQ7982X_EIS_VC1_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC1_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC1_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC2_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC2_HI_OFFSET    (0x0A16u)
#define BQ7982X_EIS_VC2_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC2_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC2_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC2_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC2_MID_OFFSET    (0x0A17u)
#define BQ7982X_EIS_VC2_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC2_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC2_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC2_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC2_LO_OFFSET    (0x0A18u)
#define BQ7982X_EIS_VC2_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC2_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC2_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC3_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC3_HI_OFFSET    (0x0A19u)
#define BQ7982X_EIS_VC3_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC3_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC3_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC3_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC3_MID_OFFSET    (0x0A1Au)
#define BQ7982X_EIS_VC3_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC3_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC3_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC3_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC3_LO_OFFSET    (0x0A1Bu)
#define BQ7982X_EIS_VC3_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC3_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC3_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC4_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC4_HI_OFFSET    (0x0A1Cu)
#define BQ7982X_EIS_VC4_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC4_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC4_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC4_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC4_MID_OFFSET    (0x0A1Du)
#define BQ7982X_EIS_VC4_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC4_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC4_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC4_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC4_LO_OFFSET    (0x0A1Eu)
#define BQ7982X_EIS_VC4_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC4_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC4_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC5_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC5_HI_OFFSET    (0x0A1Fu)
#define BQ7982X_EIS_VC5_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC5_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC5_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC5_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC5_MID_OFFSET    (0x0A20u)
#define BQ7982X_EIS_VC5_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC5_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC5_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC5_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC5_LO_OFFSET    (0x0A21u)
#define BQ7982X_EIS_VC5_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC5_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC5_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC6_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC6_HI_OFFSET    (0x0A22u)
#define BQ7982X_EIS_VC6_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC6_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC6_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC6_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC6_MID_OFFSET    (0x0A23u)
#define BQ7982X_EIS_VC6_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC6_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC6_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC6_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC6_LO_OFFSET    (0x0A24u)
#define BQ7982X_EIS_VC6_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC6_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC6_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC7_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC7_HI_OFFSET    (0x0A25u)
#define BQ7982X_EIS_VC7_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC7_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC7_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC7_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC7_MID_OFFSET    (0x0A26u)
#define BQ7982X_EIS_VC7_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC7_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC7_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC7_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC7_LO_OFFSET    (0x0A27u)
#define BQ7982X_EIS_VC7_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC7_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC7_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC8_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC8_HI_OFFSET    (0x0A28u)
#define BQ7982X_EIS_VC8_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC8_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC8_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC8_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC8_MID_OFFSET    (0x0A29u)
#define BQ7982X_EIS_VC8_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC8_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC8_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC8_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC8_LO_OFFSET    (0x0A2Au)
#define BQ7982X_EIS_VC8_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC8_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC8_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC9_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC9_HI_OFFSET    (0x0A2Bu)
#define BQ7982X_EIS_VC9_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC9_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC9_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC9_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC9_MID_OFFSET    (0x0A2Cu)
#define BQ7982X_EIS_VC9_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC9_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC9_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC9_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC9_LO_OFFSET    (0x0A2Du)
#define BQ7982X_EIS_VC9_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC9_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC9_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC10_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC10_HI_OFFSET    (0x0A2Eu)
#define BQ7982X_EIS_VC10_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC10_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC10_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC10_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC10_MID_OFFSET    (0x0A2Fu)
#define BQ7982X_EIS_VC10_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC10_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC10_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC10_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC10_LO_OFFSET    (0x0A30u)
#define BQ7982X_EIS_VC10_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC10_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC10_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC11_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC11_HI_OFFSET    (0x0A31u)
#define BQ7982X_EIS_VC11_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC11_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC11_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC11_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC11_MID_OFFSET    (0x0A32u)
#define BQ7982X_EIS_VC11_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC11_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC11_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC11_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC11_LO_OFFSET    (0x0A33u)
#define BQ7982X_EIS_VC11_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC11_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC11_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC12_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC12_HI_OFFSET    (0x0A34u)
#define BQ7982X_EIS_VC12_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC12_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC12_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC12_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC12_MID_OFFSET    (0x0A35u)
#define BQ7982X_EIS_VC12_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC12_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC12_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC12_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC12_LO_OFFSET    (0x0A36u)
#define BQ7982X_EIS_VC12_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC12_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC12_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC13_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC13_HI_OFFSET    (0x0A37u)
#define BQ7982X_EIS_VC13_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC13_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC13_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC13_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC13_MID_OFFSET    (0x0A38u)
#define BQ7982X_EIS_VC13_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC13_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC13_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC13_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC13_LO_OFFSET    (0x0A39u)
#define BQ7982X_EIS_VC13_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC13_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC13_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC14_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC14_HI_OFFSET    (0x0A3Au)
#define BQ7982X_EIS_VC14_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC14_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC14_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC14_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC14_MID_OFFSET    (0x0A3Bu)
#define BQ7982X_EIS_VC14_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC14_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC14_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC14_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC14_LO_OFFSET    (0x0A3Cu)
#define BQ7982X_EIS_VC14_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC14_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC14_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC15_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC15_HI_OFFSET    (0x0A3Du)
#define BQ7982X_EIS_VC15_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC15_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC15_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC15_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC15_MID_OFFSET    (0x0A3Eu)
#define BQ7982X_EIS_VC15_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC15_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC15_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC15_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC15_LO_OFFSET    (0x0A3Fu)
#define BQ7982X_EIS_VC15_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC15_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC15_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC16_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC16_HI_OFFSET    (0x0A40u)
#define BQ7982X_EIS_VC16_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC16_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC16_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC16_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC16_MID_OFFSET    (0x0A41u)
#define BQ7982X_EIS_VC16_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC16_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC16_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC16_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC16_LO_OFFSET    (0x0A42u)
#define BQ7982X_EIS_VC16_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC16_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC16_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC17_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC17_HI_OFFSET    (0x0A43u)
#define BQ7982X_EIS_VC17_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC17_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC17_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC17_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC17_MID_OFFSET    (0x0A44u)
#define BQ7982X_EIS_VC17_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC17_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC17_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC17_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC17_LO_OFFSET    (0x0A45u)
#define BQ7982X_EIS_VC17_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC17_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC17_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC18_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC18_HI_OFFSET    (0x0A46u)
#define BQ7982X_EIS_VC18_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC18_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC18_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC18_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC18_MID_OFFSET    (0x0A47u)
#define BQ7982X_EIS_VC18_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC18_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC18_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC18_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC18_LO_OFFSET    (0x0A48u)
#define BQ7982X_EIS_VC18_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC18_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC18_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC19_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC19_HI_OFFSET    (0x0A49u)
#define BQ7982X_EIS_VC19_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC19_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC19_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC19_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC19_MID_OFFSET    (0x0A4Au)
#define BQ7982X_EIS_VC19_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC19_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC19_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC19_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC19_LO_OFFSET    (0x0A4Bu)
#define BQ7982X_EIS_VC19_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC19_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC19_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC20_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC20_HI_OFFSET    (0x0A4Cu)
#define BQ7982X_EIS_VC20_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC20_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC20_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC20_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC20_MID_OFFSET    (0x0A4Du)
#define BQ7982X_EIS_VC20_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC20_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC20_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC20_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC20_LO_OFFSET    (0x0A4Eu)
#define BQ7982X_EIS_VC20_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC20_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC20_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC21_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC21_HI_OFFSET    (0x0A4Fu)
#define BQ7982X_EIS_VC21_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC21_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC21_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC21_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC21_MID_OFFSET    (0x0A50u)
#define BQ7982X_EIS_VC21_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC21_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC21_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC21_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC21_LO_OFFSET    (0x0A51u)
#define BQ7982X_EIS_VC21_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC21_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC21_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC22_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC22_HI_OFFSET    (0x0A52u)
#define BQ7982X_EIS_VC22_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC22_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC22_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC22_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC22_MID_OFFSET    (0x0A53u)
#define BQ7982X_EIS_VC22_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC22_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC22_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC22_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC22_LO_OFFSET    (0x0A54u)
#define BQ7982X_EIS_VC22_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC22_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC22_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC23_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC23_HI_OFFSET    (0x0A55u)
#define BQ7982X_EIS_VC23_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC23_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC23_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC23_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC23_MID_OFFSET    (0x0A56u)
#define BQ7982X_EIS_VC23_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC23_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC23_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC23_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC23_LO_OFFSET    (0x0A57u)
#define BQ7982X_EIS_VC23_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC23_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC23_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC24_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC24_HI_OFFSET    (0x0A58u)
#define BQ7982X_EIS_VC24_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC24_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC24_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC24_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC24_MID_OFFSET    (0x0A59u)
#define BQ7982X_EIS_VC24_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC24_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC24_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC24_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC24_LO_OFFSET    (0x0A5Au)
#define BQ7982X_EIS_VC24_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC24_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC24_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC25_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC25_HI_OFFSET    (0x0A5Bu)
#define BQ7982X_EIS_VC25_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC25_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC25_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC25_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC25_MID_OFFSET    (0x0A5Cu)
#define BQ7982X_EIS_VC25_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC25_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC25_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC25_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC25_LO_OFFSET    (0x0A5Du)
#define BQ7982X_EIS_VC25_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC25_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC25_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC26_HI            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC26_HI_OFFSET    (0x0A5Eu)
#define BQ7982X_EIS_VC26_HI_POR_VAL   (0x80u)

#define BQ7982X_EIS_VC26_HI_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC26_HI_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC26_MID            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC26_MID_OFFSET    (0x0A5Fu)
#define BQ7982X_EIS_VC26_MID_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC26_MID_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC26_MID_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * EIS_VC26_LO            (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_EIS_VC26_LO_OFFSET    (0x0A60u)
#define BQ7982X_EIS_VC26_LO_POR_VAL   (0x00u)

#define BQ7982X_EIS_VC26_LO_RESULT_POS   (0x00u)
#define BQ7982X_EIS_VC26_LO_RESULT_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DEBUG_CTRL_UNLOCK           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_CTRL_UNLOCK_OFFSET    (0x0C00u)
#define BQ7982X_DEBUG_CTRL_UNLOCK_POR_VAL   (0x00u)

#define BQ7982X_POS_DEBUG_CTRL_UNLOCK_CODE   (0x00u)
#define BQ7982X_MSK_DEBUG_CTRL_UNLOCK_CODE   (0xFFu)

/* --------------------------------------------------------------------------
 * DEBUG_COMM_CTRL1           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_COMM_CTRL1_OFFSET    (0x0C01u)
#define BQ7982X_DEBUG_COMM_CTRL1_POR_VAL   (0x02u)

#define BQ7982X_POS_DEBUG_COMM_CTRL1_CT_DIS   (0x02u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL1_CT_DIS   (0x04u)

#define BQ7982X_POS_DEBUG_COMM_CTRL1_PSPI_EN   (0x01u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL1_PSPI_EN   (0x02u)

#define BQ7982X_POS_DEBUG_COMM_CTRL1_USER_PSPI_EN   (0x00u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL1_USER_PSPI_EN   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_COMM_CTRL2           (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_COMM_CTRL2_OFFSET    (0x0C02u)
#define BQ7982X_DEBUG_COMM_CTRL2_POR_VAL   (0x1Eu)

#define BQ7982X_POS_DEBUG_COMM_CTRL2_COML_TX_EN   (0x04u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL2_COML_TX_EN   (0x10u)

#define BQ7982X_POS_DEBUG_COMM_CTRL2_COML_RX_EN   (0x03u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL2_COML_RX_EN   (0x08u)

#define BQ7982X_POS_DEBUG_COMM_CTRL2_COMH_TX_EN   (0x02u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL2_COMH_TX_EN   (0x04u)

#define BQ7982X_POS_DEBUG_COMM_CTRL2_COMH_RX_EN   (0x01u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL2_COMH_RX_EN   (0x02u)

#define BQ7982X_POS_DEBUG_COMM_CTRL2_USER_DAISY_EN   (0x00u)
#define BQ7982X_MSK_DEBUG_COMM_CTRL2_USER_DAISY_EN   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_COMM_STAT           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_COMM_STAT_OFFSET    (0x0C80u)
#define BQ7982X_DEBUG_COMM_STAT_POR_VAL   (0x33u)

#define BQ7982X_POS_DEBUG_COMM_STAT_HW_SPI_DRV   (0x05u)
#define BQ7982X_MSK_DEBUG_COMM_STAT_HW_SPI_DRV   (0x20u)

#define BQ7982X_POS_DEBUG_COMM_STAT_HW_DAISY_DRV   (0x04u)
#define BQ7982X_MSK_DEBUG_COMM_STAT_HW_DAISY_DRV   (0x10u)

#define BQ7982X_POS_DEBUG_COMM_STAT_COML_TX_ON   (0x03u)
#define BQ7982X_MSK_DEBUG_COMM_STAT_COML_TX_ON   (0x08u)

#define BQ7982X_POS_DEBUG_COMM_STAT_COML_RX_ON   (0x02u)
#define BQ7982X_MSK_DEBUG_COMM_STAT_COML_RX_ON   (0x04u)

#define BQ7982X_POS_DEBUG_COMM_STAT_COMH_TX_ON   (0x01u)
#define BQ7982X_MSK_DEBUG_COMM_STAT_COMH_TX_ON   (0x02u)

#define BQ7982X_POS_DEBUG_COMM_STAT_COMH_RX_ON   (0x00u)
#define BQ7982X_MSK_DEBUG_COMM_STAT_COMH_RX_ON   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_SEC_DED1           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_SEC_DED1_OFFSET    (0x0C81u)
#define BQ7982X_DEBUG_SEC_DED1_POR_VAL   (0x00u)

#define BQ7982X_DEBUG_SEC_DED1_BLOCKH_POS   (0x03u)
#define BQ7982X_DEBUG_SEC_DED1_BLOCKH_MSK   (0x08u)

#define BQ7982X_DEBUG_SEC_DED1_MEM_POS   (0x01u)
#define BQ7982X_DEBUG_SEC_DED1_MEM_MSK   (0x06u)

#define BQ7982X_POS_DEBUG_SEC_DED1_SEC_DED   (0x00u)
#define BQ7982X_MSK_DEBUG_SEC_DED1_SEC_DED   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_SEC_DED2           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_SEC_DED2_OFFSET    (0x0C82u)
#define BQ7982X_DEBUG_SEC_DED2_POR_VAL   (0x00u)

#define BQ7982X_DEBUG_SEC_DED2_BLOCK_POS   (0x00u)
#define BQ7982X_DEBUG_SEC_DED2_BLOCK_MSK   (0xFFu)

/* --------------------------------------------------------------------------
 * DEBUG_COMH_BIT           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_COMH_BIT_OFFSET    (0x0C83u)
#define BQ7982X_DEBUG_COMH_BIT_POR_VAL   (0x00u)

#define BQ7982X_POS_DEBUG_COMH_BIT_TRANSIT_BUF_UF   (0x03u)
#define BQ7982X_MSK_DEBUG_COMH_BIT_TRANSIT_BUF_UF   (0x08u)

#define BQ7982X_POS_DEBUG_COMH_BIT_NCS_ERR   (0x02u)
#define BQ7982X_MSK_DEBUG_COMH_BIT_NCS_ERR   (0x04u)

#define BQ7982X_POS_DEBUG_COMH_BIT_FMT_ERR   (0x01u)
#define BQ7982X_MSK_DEBUG_COMH_BIT_FMT_ERR   (0x02u)

#define BQ7982X_POS_DEBUG_COMH_BIT_RXDATA_UNEXP   (0x00u)
#define BQ7982X_MSK_DEBUG_COMH_BIT_RXDATA_UNEXP   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_COMH_FRAME           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_COMH_FRAME_OFFSET    (0x0C84u)
#define BQ7982X_DEBUG_COMH_FRAME_POR_VAL   (0x00u)

#define BQ7982X_POS_DEBUG_COMH_FRAME_TR_EOF   (0x06u)
#define BQ7982X_MSK_DEBUG_COMH_FRAME_TR_EOF   (0x20u)

#define BQ7982X_POS_DEBUG_COMH_FRAME_RC_UNEXP   (0x05u)
#define BQ7982X_MSK_DEBUG_COMH_FRAME_RC_UNEXP   (0x10u)

#define BQ7982X_POS_DEBUG_COMH_FRAME_RC_CFERR   (0x04u)
#define BQ7982X_MSK_DEBUG_COMH_FRAME_RC_CFERR   (0x08u)

#define BQ7982X_POS_DEBUG_COMH_FRAME_RC_TXDIS   (0x03u)
#define BQ7982X_MSK_DEBUG_COMH_FRAME_RC_TXDIS   (0x04u)

#define BQ7982X_POS_DEBUG_COMH_FRAME_RC_EOF   (0x01u)
#define BQ7982X_MSK_DEBUG_COMH_FRAME_RC_EOF   (0x02u)

#define BQ7982X_POS_DEBUG_COMH_FRAME_RC_CRC   (0x00u)
#define BQ7982X_MSK_DEBUG_COMH_FRAME_RC_CRC   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_COML_BIT           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_COML_BIT_OFFSET    (0x0C85u)
#define BQ7982X_DEBUG_COML_BIT_POR_VAL   (0x00u)

#define BQ7982X_POS_DEBUG_COML_BIT_TRANSIT_BUF_UF   (0x03u)
#define BQ7982X_MSK_DEBUG_COML_BIT_TRANSIT_BUF_UF   (0x08u)

#define BQ7982X_POS_DEBUG_COML_BIT_NCS_ERR   (0x02u)
#define BQ7982X_MSK_DEBUG_COML_BIT_NCS_ERR   (0x04u)

#define BQ7982X_POS_DEBUG_COML_BIT_FMT_ERR   (0x01u)
#define BQ7982X_MSK_DEBUG_COML_BIT_FMT_ERR   (0x02u)

#define BQ7982X_POS_DEBUG_COML_BIT_RXDATA_UNEXP   (0x00u)
#define BQ7982X_MSK_DEBUG_COML_BIT_RXDATA_UNEXP   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_COML_FRAME           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_COML_FRAME_OFFSET    (0x0C86u)
#define BQ7982X_DEBUG_COML_FRAME_POR_VAL   (0x00u)

#define BQ7982X_POS_DEBUG_COML_FRAME_TR_EOF   (0x06u)
#define BQ7982X_MSK_DEBUG_COML_FRAME_TR_EOF   (0x20u)

#define BQ7982X_POS_DEBUG_COML_FRAME_RC_UNEXP   (0x05u)
#define BQ7982X_MSK_DEBUG_COML_FRAME_RC_UNEXP   (0x10u)

#define BQ7982X_POS_DEBUG_COML_FRAME_RC_CFERR   (0x04u)
#define BQ7982X_MSK_DEBUG_COML_FRAME_RC_CFERR   (0x08u)

#define BQ7982X_POS_DEBUG_COML_FRAME_RC_TXDIS   (0x03u)
#define BQ7982X_MSK_DEBUG_COML_FRAME_RC_TXDIS   (0x04u)

#define BQ7982X_POS_DEBUG_COML_FRAME_RC_EOF   (0x01u)
#define BQ7982X_MSK_DEBUG_COML_FRAME_RC_EOF   (0x02u)

#define BQ7982X_POS_DEBUG_COML_FRAME_RC_CRC   (0x00u)
#define BQ7982X_MSK_DEBUG_COML_FRAME_RC_CRC   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_PSPI_BIT           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_PSPI_BIT_OFFSET    (0x0C90u)
#define BQ7982X_DEBUG_PSPI_BIT_POR_VAL   (0x00u)

#define BQ7982X_POS_DEBUG_PSPI_BIT_TRANSIT_BUF_UF   (0x04u)
#define BQ7982X_MSK_DEBUG_PSPI_BIT_TRANSIT_BUF_UF   (0x10u)

#define BQ7982X_POS_DEBUG_PSPI_BIT_FMT_ERR   (0x03u)
#define BQ7982X_MSK_DEBUG_PSPI_BIT_FMT_ERR   (0x08u)

#define BQ7982X_POS_DEBUG_PSPI_BIT_RXDATA_UNEXP   (0x02u)
#define BQ7982X_MSK_DEBUG_PSPI_BIT_RXDATA_UNEXP   (0x04u)

#define BQ7982X_POS_DEBUG_PSPI_BIT_TXFIFO_UF   (0x01u)
#define BQ7982X_MSK_DEBUG_PSPI_BIT_TXFIFO_UF   (0x02u)

#define BQ7982X_POS_DEBUG_PSPI_BIT_RXFIFO_OF   (0x00u)
#define BQ7982X_MSK_DEBUG_PSPI_BIT_RXFIFO_OF   (0x01u)

/* --------------------------------------------------------------------------
 * DEBUG_PSPI_FRAME           (R):
 * -------------------------------------------------------------------------- */
#define BQ7982X_DEBUG_PSPI_FRAME_OFFSET    (0x0C91u)
#define BQ7982X_DEBUG_PSPI_FRAME_POR_VAL   (0x00u)

#define BQ7982X_POS_DEBUG_PSPI_FRAME_TR_EOF   (0x04u)
#define BQ7982X_MSK_DEBUG_PSPI_FRAME_TR_EOF   (0x08u)

#define BQ7982X_POS_DEBUG_PSPI_FRAME_RC_CFERR   (0x03u)
#define BQ7982X_MSK_DEBUG_PSPI_FRAME_RC_CFERR   (0x04u)

#define BQ7982X_POS_DEBUG_PSPI_FRAME_RC_EOF   (0x01u)
#define BQ7982X_MSK_DEBUG_PSPI_FRAME_RC_EOF   (0x02u)

#define BQ7982X_POS_DEBUG_PSPI_FRAME_RC_CRC   (0x00u)
#define BQ7982X_MSK_DEBUG_PSPI_FRAME_RC_CRC   (0x01u)

/*   Factory Test Mode */
#define BQ7982X_FACT_TM_REG                  (0x800u)

/* --------------------------------------------------------------------------
 * OTP_SPARE   (R/W):
 * -------------------------------------------------------------------------- */
#define BQ7982X_OTP_SPARE13_OFFSET                (0x0005u)
#define BQ7982X_OTP_SPARE13_POR_VAL               (0x00u)

#define BQ7982X_OTP_SPARE12_OFFSET                (0x0006u)
#define BQ7982X_OTP_SPARE12_POR_VAL               (0x00u)

#define BQ7982X_OTP_SPARE11_OFFSET                (0x000Au)
#define BQ7982X_OTP_SPARE11_POR_VAL               (0x00u)

#define BQ7982X_OTP_SPARE10_OFFSET                (0x000Bu)
#define BQ7982X_OTP_SPARE10_POR_VAL               (0x00u)

#define BQ7982X_OTP_SPARE9_OFFSET                (0x001Bu)
#define BQ7982X_OTP_SPARE9_POR_VAL               (0x00u)

#define BQ7982X_OTP_SPARE8_OFFSET                (0x0029u)
#define BQ7982X_OTP_SPARE8_POR_VAL               (0x00u)

#define BQ7982X_OTP_SPARE7_OFFSET                (0x002Au)
#define BQ7982X_OTP_SPARE7_POR_VAL               (0x00u)


/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************

#ifdef __cplusplus
}
#endif

#endif /* BQ7982X_REGS_H */

/*********************************************************************************************************************
 * End of File: bq7982x_regs.h
 *********************************************************************************************************************/
