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

#ifndef B0_REG_H_
#define B0_REG_H_

#include <stdint.h>

/**
 * @brief BQ78706 register definition
 *
 * @note Verified based on Datasheet SLUSFQ3, Oct 2024
 *      Please check datasheet before using.
 */
// #define CUST_CRC_HI 0x000
// #define CUST_CRC_LO 0x001
// #define DEV_CONF1 0x002
// #define DEV_CONF2 0x003
// #define DEV_CONF2 0x004
// #define OTP_SPARE13 0x005
// #define OTP_SPARE12 0x006
// #define COMM_CONF1 0x007
// #define COMM_CONF2 0x008
// #define COMM_CONF3 0x009
// #define OTP_SPARE11 0x00A
// #define OTP_SPARE10 0x00B
// #define BBVC_POSN1 0x00C
// #define BBVC_POSN2 0x00D
// #define BBVC_POSN3 0x00E
// #define BBVC_POSN4 0x00F
// #define OV_THRESH1 0x010
// #define UV_THRESH1 0x011
// #define OV_THRESH2 0x012
// #define UV_THRESH2 0x013
// #define OTUT_THRESH1 0x014
// #define OTUT_THRESH2 0x015
// #define SMONH_THRESH 0x016
// #define SMONL_THRESH 0x017
// #define FAULT_MSK1 0x018
// #define FAULT_MSK2 0x019
// #define FAULT_MSK3 0x01A
// #define OTP_SPARE9 0x01B
// #define IDDQ_CONF 0x01C
// #define CSPI_CONF 0x01D
// #define INT_CONF 0x01E
// #define GPIO_CONF1 0x01F
// #define GPIO_CONF2 0x020
// #define GPIO_CONF3 0x021
// #define GPIO_CONF4 0x022

// typedef union {
//     struct {
//         uint8_t hb_en : 1;
//         uint8_t ftone_en : 1;
//         uint8_t nfault_en : 1;
//         uint8_t no_adj_cb : 1;
//         uint8_t cbtwarn_dis : 1;
//         uint8_t twarn_thr : 1;
//         uint8_t prot_slp_cycle : 2;
//     } fs;
//     uint8_t reg;
// } dev_conf1_t;

// typedef union {
//     struct {
//         uint8_t num_cell : 4;
//         uint8_t bb_pin_loc : 2;
//         uint8_t bb_pin_en : 1;
//         uint8_t ptc_en : 1;
//     } fs;
//     uint8_t reg;
// } dev_conf2_t;

typedef union {
    struct {
        uint8_t cell9 : 1;
        uint8_t cell10 : 1;
        uint8_t cell11 : 1;
        uint8_t cell12 : 1;
        uint8_t cell13 : 1;
        uint8_t cell14 : 1;
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
} bbvc_posn2_t;

typedef union {
    struct {
        uint8_t cell1 : 1;
        uint8_t cell2 : 1;
        uint8_t cell3 : 1;
        uint8_t cell4 : 1;
        uint8_t cell5 : 1;
        uint8_t cell6 : 1;
        uint8_t cell7 : 1;
        uint8_t cell8 : 1;
    } fs;
    uint8_t reg;
} bbvc_posn3_t;

typedef union {
    struct {
        uint8_t adc_dly : 8;

    } fs;
    uint8_t reg;
} adc_conf_t;

typedef union {
    struct {
        uint8_t cell1 : 1;
        uint8_t cell2 : 1;
        uint8_t cell3 : 1;
        uint8_t cell4 : 1;
        uint8_t cell5 : 1;
        uint8_t cell6 : 1;
        uint8_t cell7 : 1;
        uint8_t cell8 : 1;
    } fs;
    uint8_t reg;
} uv_disable2_t;

typedef union {
    struct {
        uint8_t msk_pwr : 1;
        uint8_t msk_sys : 1;
        uint8_t msk_cb : 1;
        uint8_t msk_ov : 1;
        uint8_t msk_uv : 1;
        uint8_t msk_ot : 1;
        uint8_t msk_ut : 1;
        uint8_t rsvd : 1;
    } fs;
    uint8_t reg;
} fault_msk1_t;

typedef union {
    struct {
        uint8_t msk_comm_uart : 1;
        uint8_t msk_comm_dsy : 1;
        uint8_t msk_comm_hb : 1;
        uint8_t msk_comm_ftone : 1;
        uint8_t msk_comm_fcomm : 1;
        uint8_t msk_otp_data : 1;
        uint8_t msk_otp_crc : 1;
        uint8_t msk_adc : 1;
    } fs;
    uint8_t reg;
} fault_msk2_t;

typedef union {
    struct {
        uint8_t gpio1 : 3;
        uint8_t gpio2 : 3;
        // uint8_t spi_en : 1;
        uint8_t spare : 2;
    } fs;
    uint8_t reg;
} gpio_conf1_t;

typedef union {
    struct {
        uint8_t gpio3 : 3;
        uint8_t gpio4 : 3;
        uint8_t spare : 2;
    } fs;
    uint8_t reg;
} gpio_conf2_t;

typedef union {
    struct {
        uint8_t gpio5 : 3;
        uint8_t gpio6 : 3;
        uint8_t spare : 2;
    } fs;
    uint8_t reg;
} gpio_conf3_t;

typedef union {
    struct {
        uint8_t gpio7 : 3;
        uint8_t gpio8 : 3;
        uint8_t eis_pwm_en : 1;
        uint8_t spare : 1;
    } fs;
    uint8_t reg;
} gpio_conf4_t;

typedef union {
    struct {
        uint8_t gpio9 : 3;
        uint8_t gpio10 : 3;
        uint8_t i2c_en : 1;
        uint8_t spare : 1;
    } fs;
    uint8_t reg;
} gpio_conf5_t;

typedef union {
    struct {
        uint8_t gpio11 : 3;
        uint8_t gpio12 : 3;
        uint8_t spare : 2;
    } fs;
    uint8_t reg;
} gpio_conf6_t;

typedef union {
    struct {
        uint8_t gpio13 : 3;
        uint8_t gpio14 : 3;
        uint8_t cspi_en : 1;
        uint8_t spare : 1;
    } fs;
    uint8_t reg;
} gpio_conf7_t;

typedef union {
    struct {
        uint8_t gpio15 : 3;
        uint8_t gpio16 : 3;
        uint8_t spare : 2;
    } fs;
    uint8_t reg;
} gpio_conf8_t;

typedef union {
    struct {
        uint8_t gpio17 : 3;
        uint8_t gpio18 : 3;
        uint8_t spare : 2;
    } fs;
    uint8_t reg;
} gpio_conf9_t;

typedef union {
    struct {
        uint8_t gpio19 : 3;
        uint8_t gpio20 : 3;
        uint8_t spare : 2;
    } fs;
    uint8_t reg;
} gpio_conf10_t;

typedef union {
    struct {
        uint8_t offset_lo : 4;
        uint8_t offset_hi : 4;
    } fs;
    uint8_t reg;
} vcell_offsetx_t;

typedef union {
    struct {
        uint8_t bb_pin_loc2 : 3;
        uint8_t bb_pin_en2 : 1;
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
} dev_conf5_t;
// CUSTOMER CONTROL REGISTERS

typedef union {
    struct {
        uint8_t code : 8;
    } fs;
    uint8_t reg;
} otp_prog_unlock1_t;

typedef union {
    struct {
        uint8_t addr_wr : 1;
        uint8_t soft_reset : 1;
        uint8_t goto_sleep : 1;
        uint8_t goto_shutdown : 1;
        uint8_t send_slptoact : 1;
        uint8_t send_wake : 1;
        uint8_t send_sd_hw_rst : 1;
        uint8_t dir_sel : 1;
    } fs;
    uint8_t reg;
} control1_t;

typedef union {
    struct {
        uint8_t tsref_en : 1;
        uint8_t prog_go : 1;
        uint8_t send_hw_rst_blast : 1;
        uint8_t addr_wr : 1;
        uint8_t rsvd2 : 4;
    } fs;
    uint8_t reg;
} control2_t;

typedef union {
    struct {
        uint8_t diag_meas_go : 1;
        uint8_t diag_d1d2_sel : 3;
        uint8_t rsvd : 4;        
    } fs;
    uint8_t reg;
} adc_ctrl1_t;

typedef union {
    struct {
        uint8_t diag1_ana_sel : 5;
        uint8_t diag1_vcell_gpio : 1;
        uint8_t flip_reset : 1;
        uint8_t flip_read_en : 1;
    } fs;
    uint8_t reg;
} adc_ctrl2_t;

typedef union {
    struct {
        uint8_t adc_go : 1;
        uint8_t adc_mode : 2;
        uint8_t lpf_vcell_en : 1;
        uint8_t lpf_vcell : 3;
        uint8_t freeze_en : 1;
    } fs;
    uint8_t reg;
} adc_ctrl3_t;

// typedef union {
//     struct {
//         uint8_t diag_ana_sel : 5;
//         uint8_t diag_vcell_gpio : 1;
//         uint8_t rsvd : 1;
//         uint8_t freeze_lpf_en : 1;
//     } fs;
//     uint8_t reg;
// } adc_ctrl3_t_78;

typedef union {
    struct {
        uint8_t gp_dr : 1;
        uint8_t csadc_mode : 1;
        uint8_t adc_dly_mode : 1;
        uint8_t freeze_lpf_en : 1;
        uint8_t rsvd : 4;        
    } fs;
    uint8_t reg;
} adc_ctrl4_t;

typedef union {
    struct {
        uint8_t lpf_cs_en : 1;
        uint8_t lpf_cs : 3;
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
} adc_ctrl5_t;

typedef union {
    struct {
        uint8_t vcell_thr : 6;
        uint8_t rsvd : 1;
        uint8_t vcell_filt : 1;
    } fs;
    uint8_t reg;
} diag_adc_ctrl1_t;

typedef union {
    struct {
        uint8_t gpio_thr : 3;
        uint8_t rsvd : 1;
        uint8_t bb_thr : 2;
        uint8_t rsvd2 : 2;
    } fs;
    uint8_t reg;
} diag_adc_ctrl2_t;

typedef union {
    struct {
        uint8_t diag_ana_go : 1;
        uint8_t diag_ana_mode : 2;
        uint8_t bb_meas_mode : 1;
        uint8_t diag_dig_en : 1;
        uint8_t rsvd : 3;
    } fs;
    uint8_t reg;
} diag_adc_ctrl3_t;

typedef union {
    struct {
        uint8_t margin_go : 1;
        uint8_t margin_mode : 3;
        uint8_t flip_fact_crc : 1;
        uint8_t flip_tr_crc : 1;
        uint8_t spi_loopback : 1;
        uint8_t rsvd : 1;
    } fs;
    uint8_t reg;
} diag_misc_ctrl1_t;

typedef union {
    struct {
        uint8_t pwrbist_go : 1;
        uint8_t pwrbist_no_rst : 1;
        uint8_t diag_cbfetow_go : 1;
        uint8_t rsvd : 5;
    } fs;
    uint8_t reg;
} diag_misc_ctrl2_t;

typedef union {
    struct {
        uint8_t time : 5;
        uint8_t rsvd : 3;
    } fs;
    uint8_t reg;
} cb_cellx_ctrl_t;

typedef union {
    struct {
        uint8_t cb_thr : 7;
        uint8_t rsvd : 1;
    } fs;
    uint8_t reg;
} vcbdone_thresh_t;

typedef union {
    struct {
        uint8_t otcb_thr : 4;
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
} otcb_thresh_t;

typedef union {
    struct {
        uint8_t ovuv_go : 1;
        uint8_t ovuv_mode : 2;
        uint8_t rsvd : 5;
    } fs;
    uint8_t reg;
} ovuv_ctrl2_t;

typedef union {
    struct {
        uint8_t otut_go : 1;
        uint8_t otut_mode : 2;
        uint8_t rsvd : 5;
    } fs;
    uint8_t reg;
} otut_ctrl2_t;

typedef union {
    struct {
        uint8_t pwm : 6;
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
} bal_ctrl1_t;

typedef union {
    struct {
        uint8_t bal_go : 1;
        uint8_t auto_bal : 1;
        uint8_t bal_act : 1;
        uint8_t otcb_en : 1;
        uint8_t fltstop_en : 1;
        uint8_t cb_pause : 1;
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
} bal_ctrl2_t;

typedef union {
    struct {
        uint8_t bal_time_go : 1;
        uint8_t bal_time_sel : 5;
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
} bal_ctrl3_t;

typedef union {
    struct {
        uint8_t rst_pwr : 1;
        uint8_t rst_sys : 1;
        uint8_t rst_cb : 1;
        uint8_t rst_ov : 1;
        uint8_t rst_uv : 1;
        uint8_t rst_ot : 1;
        uint8_t rst_ut : 1;
        uint8_t rsvd : 1;
    } fs;
    uint8_t reg;
} fault_rst1_t;

typedef union {
    struct {
        uint8_t rst_comm_uart : 1;
        uint8_t rst_comm_dsy : 1;
        uint8_t rst_comm_hb : 1;
        uint8_t rst_comm_ftone : 1;
        uint8_t rst_comm_fcomm : 1;
        uint8_t rst_otp_data : 1;
        uint8_t rst_otp_crc : 1;
        uint8_t rst_adc : 1;
    } fs;
    uint8_t reg;
} fault_rst2_t;

typedef union {
    struct {
        uint8_t code : 8;
    } fs;
    uint8_t reg;
} otp_prog_unlock2_t;

typedef union {
    struct {
        uint8_t done : 1;
        uint8_t progerr : 1;
        uint8_t suv_soverr : 1;
        uint8_t uv_overr : 1;
        uint8_t unlock : 1;
        uint8_t _try : 1;
        uint8_t uv_ovok : 1;
        uint8_t loader : 1;
    } fs;
    uint8_t reg;
} otp_stat_t;

typedef union {
    struct {
        uint8_t GPIO9 : 1;
        uint8_t GPIO10 : 1;
        uint8_t GPIO11 : 1;
        uint8_t rsvd : 5;
    } fs;
    uint8_t reg;
} gpio_stat1_t;

typedef union {
    struct {
        uint8_t cb_done : 1;
        uint8_t abortflt : 1;
        uint8_t cb_run : 1;
        uint8_t cb_inpause : 1;
        uint8_t ot_pause_det : 1;
        uint8_t invalid_cbconf : 1;
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
} bal_stat_t;

typedef union {
    struct {
        uint8_t time : 7;
        uint8_t time_unit : 1;
    } fs;
    uint8_t reg;
} bal_time_t;

typedef union {
    struct {
        uint8_t drdy_pwrbist : 1;
        uint8_t drdy_ovuv : 1;
        uint8_t drdy_otut : 1;
        uint8_t ecc_test_ok : 1;
        uint8_t freeze_active : 1;
        uint8_t freeze_lpf_active : 1;
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
} diag_stat1_t;

typedef union {
    struct {
        uint8_t drdy_ana_vcell : 1;
        uint8_t drdy_ana_gpio : 1;
        uint8_t drdy_dig : 1;
        uint8_t drdy_cbfetow : 1;
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
} diag_stat2_t;

typedef union {
    struct {
        uint8_t drdy_vcelladc : 1;
        uint8_t drdy_gpadc : 1;
        uint8_t drdy_diag : 1;
        uint8_t drdy_diag_d1d2 : 1;
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
} adc_data_rdy_t;

typedef union {
    struct {
        uint8_t vcelladc_run : 1;
        uint8_t gpadc_run : 1;
        uint8_t diag_ana_run : 1;
        uint8_t ovuv_run : 1;
        uint8_t otut_run : 1;
        uint8_t cust_crc_done : 1;
        uint8_t fact_crc_done : 1;
        uint8_t diag_meas_run : 1;
    } fs;
    uint8_t reg;
} dev_stat1_t;

typedef union {
    struct {
        uint8_t avdd_on : 1;
        uint8_t diag_dig_run : 1;
        uint8_t rsvd : 6;
    } fs;
    uint8_t reg;
} dev_stat2_t;

typedef union {
    struct {
        uint8_t fault_pwr : 1;
        uint8_t fault_comm : 1;
        uint8_t fault_otp : 1;
        uint8_t fault_sys : 1;
        uint8_t fault_ovuv : 1;
        uint8_t fault_otut : 1;
        uint8_t fault_adc_cb : 1;
        uint8_t rsvd : 1;
    } fs;
    uint8_t reg;
} fault_summary_t;

typedef union {
    struct {
        uint8_t avdd_ov : 1;
        uint8_t avdd_osc : 1;
        uint8_t dvdd_ov : 1;
        uint8_t tsref_ov : 1;
        uint8_t tsref_uv : 1;
        uint8_t tsref_osc : 1;
        uint8_t vss_open : 1;
        uint8_t pwrbist_fail : 1;
    } fs;
    uint8_t reg;
} fault_pwr1_t;

typedef union {
    struct {
        uint8_t neg_cpump : 1;
        uint8_t rsvd : 7;
    } fs;
    uint8_t reg;
} fault_pwr2_t;

typedef union {
    struct {
        uint8_t stop_det : 1;
        uint8_t commclr_det : 1;
        uint8_t uart_frame : 1;
        uint8_t comh : 1;
        uint8_t coml : 1;
        uint8_t hb_fail : 1;
        uint8_t ftone_det : 1;
        uint8_t fcomm_det : 1;
    } fs;
    uint8_t reg;
} fault_comm_t;

typedef union {
    struct {
        uint8_t gbloverr : 1;
        uint8_t loaderr : 1;
        uint8_t fact_crc : 1;
        uint8_t cust_crc : 1;
        uint8_t sec_det : 1;
        uint8_t ded_det : 1;
        uint8_t revd : 2;
    } fs;
    uint8_t reg;
} fault_otp_t;

typedef union {
    struct {
        uint8_t twarn : 1;
        uint8_t tshut : 1;
        uint8_t drst : 1;
        uint8_t lfo : 1;
        uint8_t i2c_nack : 1;
        uint8_t i2c_low : 1;
        uint8_t avdd_on : 2;
        uint8_t revd : 1;
    } fs;
    uint8_t reg;
} fault_sys_t;
typedef union {
    struct {
        uint8_t ch_1_DET : 1;
        uint8_t ch_2_DET : 1;
        uint8_t ch_3_DET : 1;
        uint8_t ch_4_DET : 1;
        uint8_t ch_5_DET : 1;
        uint8_t ch_6_DET : 1;
        uint8_t ch_7_DET : 1;
        uint8_t ch_8_DET : 1;
    } fs;
    uint8_t reg;
} fault_1_t;
typedef union {
    struct {
        uint8_t ch_9_DET : 1;
        uint8_t ch_10_DET : 1;
        uint8_t ch_11_DET : 1;
        uint8_t ch_12_DET : 1;
        uint8_t ch_13_DET : 1;
        uint8_t ch_14_DET : 1;
        uint8_t ch_15_DET : 1;
        uint8_t ch_16_DET : 1;
    } fs;
    uint8_t reg;
} fault_2_t;
typedef union {
    struct {
        uint8_t ch_17_DET : 1;
        uint8_t ch_18_DET : 1;
        uint8_t ch_19_DET : 1;
        uint8_t ch_20_DET : 1;
        uint8_t ch_21_DET : 1;
        uint8_t ch_22_DET : 1;
        uint8_t ch_23_DET : 1;
        uint8_t ch_24_DET : 1;
    } fs;
    uint8_t reg;
} fault_3_t;
typedef union {
    struct {
        uint8_t ch_25_DET : 1;
        uint8_t ch_26_DET : 1;
        uint8_t revd : 6;  
    } fs;
    uint8_t reg;
} fault_4_t;

typedef union {
    struct {
        uint8_t gpio9_afail : 1;
        uint8_t gpio10_afail : 1;
        uint8_t gpio11_afail : 1;
        uint8_t revd : 5;
    } fs;
    uint8_t reg;
} fault_adc_gpio1_t;

typedef union {
    struct {
        uint8_t gpio1_afail : 1;
        uint8_t gpio2_afail : 1;
        uint8_t gpio3_afail : 1;
        uint8_t gpio4_afail : 1;
        uint8_t gpio5_afail : 1;
        uint8_t gpio6_afail : 1;
        uint8_t gpio7_afail : 1;
        uint8_t gpio8_afail : 1;
    } fs;
    uint8_t reg;
} fault_adc_gpio2_t;

typedef union {
    struct {
        uint8_t cell17_afail : 1;
        uint8_t cell18_afail : 1;
        uint8_t revd : 6;
    } fs;
    uint8_t reg;
} fault_adc_vcell1_t;

typedef union {
    struct {
        uint8_t cell9_afail : 1;
        uint8_t cell10_afail : 1;
        uint8_t cell11_afail : 1;
        uint8_t cell12_afail : 1;
        uint8_t cell13_afail : 1;
        uint8_t cell14_afail : 1;
        uint8_t cell15_afail : 1;
        uint8_t cell16_afail : 1;
    } fs;
    uint8_t reg;
} fault_adc_vcell2_t;

typedef union {
    struct {
        uint8_t cell1_afail : 1;
        uint8_t cell2_afail : 1;
        uint8_t cell3_afail : 1;
        uint8_t cell4_afail : 1;
        uint8_t cell5_afail : 1;
        uint8_t cell6_afail : 1;
        uint8_t cell7_afail : 1;
        uint8_t cell8_afail : 1;
    } fs;
    uint8_t reg;
} fault_adc_vcell3_t;

typedef union {
    struct {
        uint8_t cell9_dfail : 1;
        uint8_t cell10_dfail : 1;
        uint8_t cell11_dfail : 1;
        uint8_t cell12_dfail : 1;
        uint8_t cell13_dfail : 1;
        uint8_t cell14_dfail : 1;
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
} fault_adc_dig2_t;

typedef union {
    struct {
        uint8_t cell1_dfail : 1;
        uint8_t cell2_dfail : 1;
        uint8_t cell3_dfail : 1;
        uint8_t cell4_dfail : 1;
        uint8_t cell5_dfail : 1;
        uint8_t cell6_dfail : 1;
        uint8_t cell7_dfail : 1;
        uint8_t cell8_dfail : 1;
    } fs;
    uint8_t reg;
} fault_adc_dig3_t;

typedef union {
    struct {
        uint8_t diag_ana_abort : 1;
        uint8_t diag_ana_pfail : 1;
        uint8_t diag_meas_pfail : 1;
        uint8_t adc_pfail : 1;
        uint8_t revd : 4;
    } fs;
    uint8_t reg;
} fault_adc_misc_t;

typedef union {
    struct {
        uint8_t cb17_fail : 1;
        uint8_t cb18_fail : 1;
        uint8_t revd : 6;
    } fs;
    uint8_t reg;
} fault_cb_fetow1_t;

typedef union {
    struct {
        uint8_t cb9_fail : 1;
        uint8_t cb10_fail : 1;
        uint8_t cb11_fail : 1;
        uint8_t cb12_fail : 1;
        uint8_t cb13_fail : 1;
        uint8_t cb14_fail : 1;
        uint8_t cb15_fail : 1;
        uint8_t cb16_fail : 1;
    } fs;
    uint8_t reg;
} fault_cb_fetow2_t;

typedef union {
    struct {
        uint8_t cb1_fail : 1;
        uint8_t cb2_fail : 1;
        uint8_t cb3_fail : 1;
        uint8_t cb4_fail : 1;
        uint8_t cb5_fail : 1;
        uint8_t cb6_fail : 1;
        uint8_t cb7_fail : 1;
        uint8_t cb8_fail : 1;
    } fs;
    uint8_t reg;
} fault_cb_fetow3_t;

//20250910
typedef union {
    struct {
        uint8_t rsvd : 8;
    } fs;
    uint8_t reg;
} debug_ctrl_unlock_t;

typedef union {
    struct {
        uint8_t user_pspi_en : 1;
        uint8_t pspi_en : 1;
        uint8_t ct_dis : 1;
        uint8_t rsvd : 5;
    } fs;
    uint8_t reg;
} debug_comm_ctrl1_t;


typedef union {
    struct {
        uint8_t eis_res_tone : 3;   //0b000 = The EIS result registers report tone 1 results.
        uint8_t eis_res_sel : 1;    //0b0 = The EIS result registers report the real portion of the impedance values.0b1 = The EIS result registers report imaginary portion of the impedance values.
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
} eis_misc_ctrl_t;

typedef union {
    struct {
        uint8_t eis_pwm_run : 1;    //This field reports the status of EIS pulse width modulation subsystem:
        uint8_t eis_dfe_run : 1;    //This field reports the status of EIS digital front end subsystem;
        uint8_t eis_dft_run : 1;    //This field reports the status of EIS discrete Fourier transform subsystem
        uint8_t eis_dft_rdy : 1;    //This field reports whether the EIS discrete Fourier transform data is ready. This field is cleared when EIS_DFT_CTRL4[EIS_DFT_GO] is written to 1 and is set when the EIS DFT calculations are complete.
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
} eis_stat_t;

typedef union {
    struct {
        uint8_t phaseh : 8;    
    } fs;
    uint8_t reg;
} eis_dft_ctrl1_t;

typedef union {
    struct {
        uint8_t phasem : 8;    
    } fs;
    uint8_t reg;
} eis_dft_ctrl2_t;

typedef union {
    struct {
        uint8_t phasel : 8;    
    } fs;
    uint8_t reg;
} eis_dft_ctrl3_t;

typedef union {
    struct {
        uint8_t eis_dft_go : 1;    //This field controls starting the EIS discrete Fourier transform measurement. This field samples the related register fields listed in the GO bits table when written to 1. This field is self-cleared and will always read back 0. Writing 0 to this field has no effect:
        uint8_t eis_dft_mode : 2;    //This field controls the EIS discrete Fourier transform mode:
        uint8_t phase_mode : 1;    //This field controls the EIS discrete Fourier transform phase offset selection:
        uint8_t window_dis : 1;    //This field controls starting the EIS discrete Fourier transform windowing function:
        uint8_t rsvd : 3;
    } fs;
    uint8_t reg;
} eis_dft_ctrl4_t;

typedef union {
    struct {
        uint8_t amp1 : 8;    

    } fs;
    uint8_t reg;
} 
eis_pwm_ctrl1_t;

typedef union {
    struct {
        uint8_t phase1 : 8;    
    } fs;
    uint8_t reg;
} eis_pwm_ctrl6_t;

typedef union {
    struct {
        uint8_t dc_shifth : 4;    
        uint8_t rsvd : 4;    
    } fs;
    uint8_t reg;
} eis_pwm_ctrl11_t;

typedef union {
    struct {
        uint8_t dc_shiftl : 8;    
    } fs;
    uint8_t reg;
} eis_pwm_ctrl12_t;

typedef union {
    struct {
        uint8_t pwm_divisorh : 4;    
        uint8_t rsvd : 4; 
    } fs;
    uint8_t reg;
} eis_pwm_ctrl13_t;

typedef union {
    struct {
        uint8_t pwm_divisorl : 8;    
    } fs;
    uint8_t reg;
} eis_pwm_ctrl14_t;

typedef union {
    struct {
        uint8_t eis_pwm_go : 1; //This field controls starting the EIS pulse width modulator. This field samples the related register fields listed in the GO bits table when written to 1. This field is self-cleared and will always read back 0. Writing 0 to this field has no effect:   
        uint8_t eis_pwm_mode : 2; 
        uint8_t rsvd : 5; 
    } fs;
    uint8_t reg;
} eis_pwm_ctrl15_t;

typedef union {
    struct {
        uint8_t vc_amph : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl1_t;

typedef union {
    struct {
        uint8_t vc_ampl : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl2_t;

typedef union {
    struct {
        uint8_t cs_amph : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl3_t;

typedef union {
    struct {
        uint8_t cs_ampl : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl4_t;

typedef union {
    struct {
        uint8_t hpf_coefh : 4; 
        uint8_t rsvd : 4;
    } fs;
    uint8_t reg;
}eis_dfe_ctrl5_t;

typedef union {
    struct {
        uint8_t hpf_coefm : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl6_t;

typedef union {
    struct {
        uint8_t hpf_coefl : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl7_t;

typedef union {
    struct {
        uint8_t vc_dcc_scaleh : 5; 
        uint8_t rsvd : 3;
    } fs;
    uint8_t reg;
}eis_dfe_ctrl8_t;

typedef union {
    struct {
        uint8_t vc_dcc_scalem : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl9_t;

typedef union {
    struct {
        uint8_t vc_dcc_scalel : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl10_t;

typedef union {
    struct {
        uint8_t vc_dcc_lpfh : 5; 
        uint8_t rsvd : 3;
    } fs;
    uint8_t reg;
}eis_dfe_ctrl11_t;

typedef union {
    struct {
        uint8_t vc_dcc_lpfm : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl12_t;

typedef union {
    struct {
        uint8_t vc_dcc_lpfl : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl13_t;


typedef union {
    struct {
        uint8_t vc_dcc_dch : 3; 
        uint8_t rsvd : 5;
    } fs;
    uint8_t reg;
}eis_dfe_ctrl14_t;

typedef union {
    struct {
        uint8_t vc_dcc_dcm : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl15_t;

typedef union {
    struct {
        uint8_t vc_dcc_dcl : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl16_t;

typedef union {
    struct {
        uint8_t cs_dcc_scaleh : 5; 
        uint8_t rsvd : 3;        
    } fs;
    uint8_t reg;
}eis_dfe_ctrl17_t;

typedef union {
    struct {
        uint8_t cs_dcc_scalem : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl18_t;

typedef union {
    struct {
        uint8_t cs_dcc_scalel : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl19_t;

typedef union {
    struct {
        uint8_t cs_dcc_lpfh : 5; 
        uint8_t rsvd : 3;        
    } fs;
    uint8_t reg;
}eis_dfe_ctrl20_t;

typedef union {
    struct {
        uint8_t cs_dcc_lpfm : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl21_t;

typedef union {
    struct {
        uint8_t cs_dcc_lpfl : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl22_t;

typedef union {
    struct {
        uint8_t cs_dcc_dch : 4; 
        uint8_t rsvd : 4;  
    } fs;
    uint8_t reg;
}eis_dfe_ctrl23_t;

typedef union {
    struct {
        uint8_t cs_dcc_dcm : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl24_t;

typedef union {
    struct {
        uint8_t cs_dcc_dcl : 8; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl25_t;

typedef union {
    struct {
        uint8_t eis_dfe_go : 1; 
        uint8_t eis_dfe_mode : 2; 
        uint8_t eis_dsr : 4; 
        uint8_t hpf_mode : 1; 
    } fs;
    uint8_t reg;
}eis_dfe_ctrl26_t;

typedef union {
    struct {
        uint8_t num_tones : 3; 
        uint8_t cs_mode : 1; 
        uint8_t rsvd : 4; 
    } fs;
    uint8_t reg;
}eis_com_ctrl1_t;

typedef union {
    struct {
        uint8_t dft_lenh : 4; 
        uint8_t rsvd : 4; 
    } fs;
    uint8_t reg;
}eis_com_ctrl2_t;

typedef union {
    struct {
        uint8_t dft_lenm : 8; 
    } fs;
    uint8_t reg;
}eis_com_ctrl3_t;

typedef union {
    struct {
        uint8_t dft_lenl : 8; 
    } fs;
    uint8_t reg;
}eis_com_ctrl4_t;

typedef union {
    struct {
        uint8_t freq_idx1h : 3; 
        uint8_t rsvd : 5; 
    } fs;
    uint8_t reg;
}eis_com_ctrl5_t;

typedef union {
    struct {
        uint8_t freq_idx1m : 8; 
    } fs;
    uint8_t reg;
}eis_com_ctrl6_t;

typedef union {
    struct {
        uint8_t freq_idx1l : 8; 
    } fs;
    uint8_t reg;
}eis_com_ctrl7_t;

typedef union {
    struct {
        uint8_t slot_sel : 8; 
    } fs;
    uint8_t reg;
}smart_freeze_ctrl1_t;

typedef union {
    struct {
        uint8_t sf_go : 1; 
        uint8_t sf_mode : 2; 
    } fs;
    uint8_t reg;
}smart_freeze_ctrl2_t;

typedef union {
    struct {
        uint8_t slot_count : 8;
    } fs;
}smart_freeze_stat3_t;

typedef union {
    struct {
        uint8_t freq_adj : 8; 
    } fs;
    uint8_t reg;
}hfo_freq_ctrl1_t;

typedef union {
    struct {
        uint8_t freq_go : 1; 
    } fs;
    uint8_t reg;
}hfo_freq_ctrl2_t;
//skip EIS tone 2~5

typedef union {
    struct {
        uint8_t pll_dev_mode : 3; 
        uint8_t pll_sync_dir : 1; 
        uint8_t pll_sync_wait : 1; 
        uint8_t rsvd : 3;
    } fs;
    uint8_t reg;
}pll_sync_ctrl1_t;

typedef union {
    struct {
        uint8_t pll_sync_go : 1; 
        uint8_t rsvd : 7;
    } fs;
    uint8_t reg;
}pll_sync_ctrl2_t;

typedef union {
    struct {
        uint8_t sync_dev_go : 1; 
        uint8_t sync_dev_mode : 2; 
        uint8_t sync_dev_dir : 1; 
        uint8_t sync_dev_frame : 1; 
        uint8_t freeze_count_en : 1; 
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
}dig_sync_ctrl3_t;

typedef union {
    struct {
        uint8_t ref_counth : 8; 
    } fs;
    uint8_t reg;
}dig_sync_ctrl4_t;

typedef union {
    struct {
        uint8_t ref_countl : 8; 
    } fs;
    uint8_t reg;
}dig_sync_ctrl5_t;

typedef union {
    struct {
        uint8_t dig_sync_go : 1; 
        uint8_t dig_sync_mode : 2; 
        uint8_t sync_adc_reset : 1; 
        uint8_t dig_sync_wait : 1; 
        uint8_t dig_sync_start : 1; 
        uint8_t rsvd : 2;
    } fs;
    uint8_t reg;
}dig_sync_ctrl6_t;

typedef union {
    struct {
        uint8_t crc_length : 1; 
        uint8_t frame_en : 1; 
        uint8_t group : 2; 
        uint8_t frame_link : 1; 
        uint8_t hb_timer : 1; 
        uint8_t hb_to_timer : 1;
        uint8_t md_hb_to_timer : 1;
    } fs;
    uint8_t reg;
}comm_conf1_t;

typedef union {
    struct {
        uint8_t nfault_en : 1; 
        uint8_t tsref_dly : 2; 
        uint8_t deepsleep_dis : 1; 
        uint8_t vio_uv_ds_dis : 1;
        uint8_t cbtwarn_thr : 1; 
        uint8_t spare : 2; 
    } fs;
    uint8_t reg;
}dev_conf1_t;

typedef union {
    struct {
        uint8_t num_cell : 5; 
        uint8_t mon_cycle : 3;  
    } fs;
    uint8_t reg;
}dev_conf2_t;

typedef union {
    struct {
        uint8_t no_adj_cb : 1; 
        uint8_t cbtwarn_dis : 1; 
        uint8_t twarn_thr : 1; 
        uint8_t cbadc_offset : 2; 
        uint8_t i_cb_lkg : 1; 
        uint8_t ptc_en : 1; 
        // uint8_t reserved : 1; 
        uint8_t crystal_en : 1; 
    } fs;
    uint8_t reg;
}dev_conf3_t;

typedef union {
    struct {
        uint8_t samp_len : 3; 
        uint8_t slot_len : 2; 
        uint8_t spare : 3; 
    } fs;
    uint8_t reg;
}smart_freeze_conf_t;

typedef union {
    struct {
        uint8_t ov_thr : 8; 
    } fs;
    uint8_t reg;
}ov_thresh1_t;

typedef union {
    struct {
        uint8_t uv_thr : 6; 
        uint8_t spare : 2; 
    } fs;
    uint8_t reg;
}uv_thresh1_t;

typedef union {
    struct {
        uint8_t ov_thr : 8; 
    } fs;
    uint8_t reg;
}ov_thresh2_t;

typedef union {
    struct {
        uint8_t uv_thr : 6; 
        uint8_t spare : 2; 
    } fs;
    uint8_t reg;
}uv_thresh2_t;

typedef union {
    struct {
        uint8_t ot_thr : 4; 
        uint8_t ut_thr : 4; 
    } fs;
    uint8_t reg;
}otut_thresh1_t;

typedef union {
    struct {
        uint8_t ot_thr : 4; 
        uint8_t ut_thr : 4; 
    } fs;
    uint8_t reg;
}otut_thresh2_t;

typedef union {
    struct {
        uint8_t smonh_thr : 8; 
    } fs;
    uint8_t reg;
}smonh_thresh_t;

typedef union {
    struct {
        uint8_t smonl_thr : 8; 
    } fs;
    uint8_t reg;
}smonl_thresh_t;

typedef union {
    struct {
        uint8_t mon_go : 1;
        uint8_t ovuv_mode : 1; 
        uint8_t otut_mode : 1; 
        uint8_t smon_mode : 1;
        uint8_t vcbdone_mode : 1;
        uint8_t otcb_mode : 1;
        uint8_t smon_peak_mode : 1;
        uint8_t smon_peak_rst : 1;
    } fs;
    uint8_t reg;
}mon_ctrl_t;

typedef union {
    struct {
        uint8_t addrh : 8;
    } fs;
    uint8_t reg;
}dig_sync_conf1_t;

typedef union {
    struct {
        uint8_t addrl : 8;
    } fs;
    uint8_t reg;
}dig_sync_conf2_t;

typedef union {
    struct {
        uint8_t sync_counth : 8;
    } fs;
    uint8_t reg;
}dig_sync_stat1_t;

typedef union {
    struct {
        uint8_t sync_countl : 8;
    } fs;
    uint8_t reg;
}dig_sync_stat2_t;
#endif /* B0_REG_H_ */
