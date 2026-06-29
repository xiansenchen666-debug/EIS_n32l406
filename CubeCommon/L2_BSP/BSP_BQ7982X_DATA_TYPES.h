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

#ifndef BQ7982x_DATA_TYPES_H_
#define BQ7982x_DATA_TYPES_H_

#include "BSP_BQ7982X_REGS_TYPES.h"
/**
 * @brief Basic types definition
 */
// typedef unsigned int BOOL;
typedef signed int HANDLE;


/**
 * @brief TRUE and FALSE definition
 */
#define true 1
#define false 0
#ifndef TRUE
#define TRUE true
#endif
#ifndef FALSE
#define FALSE false
#endif

// GPIO CONF definition
#define HIGHZ 0b000
#define ADC_RATIO 0b001
#define ADC_ABS 0b010
#define DIGIT_INPUT 0b011
#define OUTPUT_H 0b100
#define OUTPUT_L 0b101
#define ADC_ABS_PU 0b110
#define ADC_ABS_PD 0b111

/**
 * @brief BQ7982X 设备结构体 (存储设备状态和配置参数)
 * 
 * 包含 BQ7982X 设备的通信状态、寄存器配置（ADC, GPIO, PWM, DFE, DFT）、
 * 以及 EIS（电化学阻抗谱）测量结果等核心信息。
 */
typedef struct {
    // ====================================================
    // 1. 均衡控制相关寄存器 (Cell Balancing Control)
    // ====================================================
    cb_cellx_ctrl_t CbCellxCtrl;      // 电池均衡开启/关闭控制
    bal_ctrl1_t BalCtrl1;             // 均衡控制寄存器1
    bal_ctrl2_t BalCtrl2;             // 均衡控制寄存器2 (包含暂停/恢复均衡控制)
    // dev_conf1_t DevConf1;
    // dev_conf2_t DevConf2;
    dev_conf5_t DevConf5;             // 设备配置寄存器5
    otcb_thresh_t OtcbThresh;         // 均衡过温保护阈值
    vcbdone_thresh_t VcbdoneThresh;   // 均衡完成电压阈值
    ovuv_ctrl2_t OvuvCtrl2;           // 过压/欠压控制寄存器2
    bal_stat_t BalStat;               // 均衡状态指示
    bal_ctrl3_t BalCtrl3;             // 均衡控制寄存器3
    bal_time_t BalTime;               // 均衡时间设置

    // ====================================================
    // 2. ADC 采样与配置寄存器 (ADC Sampling & Configuration)
    // ====================================================
    adc_ctrl1_t AdcCtrl1;             // ADC 控制寄存器1 (主控)
    adc_ctrl2_t AdcCtrl2;             // ADC 控制寄存器2
    adc_ctrl3_t AdcCtrl3;             // ADC 控制寄存器3 (含滤波冻结控制)
    adc_ctrl4_t AdcCtrl4;             // ADC 控制寄存器4

    bbvc_posn2_t BbvcPosn2;           // 汇流排电压连接位置配置2
    bbvc_posn3_t BbvcPosn3;           // 汇流排电压连接位置配置3

    adc_conf_t AdcConf;               // ADC 延迟等配置
    uv_disable2_t UvDisable2;         // 欠压检测禁用掩码2
    diag_adc_ctrl1_t DiagAdcCtrl1;    // 诊断 ADC 控制1
    diag_adc_ctrl2_t DiagAdcCtrl2;    // 诊断 ADC 控制2
    diag_adc_ctrl3_t DiagAdcCtrl3;    // 诊断 ADC 控制3
    adc_data_rdy_t AdcDataRdy;        // ADC 数据就绪状态标志
    diag_stat1_t DiagStat1;           // 诊断状态1
    diag_stat2_t DiagStat2;           // 诊断状态2
    
    // ====================================================
    // 3. GPIO 与外设状态配置 (GPIO & Peripheral Config)
    // ====================================================
    gpio_stat1_t GpioStat1;           // GPIO 状态指示1
    gpio_conf1_t GpioConf1;           // GPIO1 配置 (如复用为ADC或输出)
    gpio_conf2_t GpioConf2;           // GPIO2 配置
    gpio_conf3_t GpioConf3;           // GPIO3 配置
    gpio_conf4_t GpioConf4;           // GPIO4 配置 (如复用为 EIS PWM)
    gpio_conf5_t GpioConf5;           // GPIO5 配置
    gpio_conf6_t GpioConf6;           // GPIO6 配置
    gpio_conf7_t GpioConf7;           // GPIO7 配置
    gpio_conf8_t GpioConf8;           // GPIO8 配置
    gpio_conf9_t GpioConf9;           // GPIO9 配置
    gpio_conf10_t GpioConf10;         // GPIO10 配置
    //yan
    otut_ctrl2_t Otutctrl2;           // 过温/欠温控制寄存器2

    // ====================================================
    // 4. 故障诊断与保护状态 (Diagnostics & Fault Status)
    // ====================================================
    fault_summary_t FaultSummary;     // 故障状态汇总 (总览各类故障)
    // fault_rst1_t FaultRst1;
    // fault_rst2_t FaultRst2;
    fault_pwr1_t FaultPwr1;           // 电源故障指示1
    fault_pwr2_t FaultPwr2;           // 电源故障指示2
    fault_comm_t FaultComm;           // 通信故障指示
    fault_otp_t FaultOtp;             // OTP/NVM 存储故障指示

    // ====================================================
    // 5. 电压/温度采样数据缓存 (Voltage & Temperature Data)
    // ====================================================
    // GPIO1 ~ GPIO11 采样电压 (绝对值与比率值)
    float GPIOxVoltage[11];           // GPIOx 实际计算电压
    float GPIOxVoltageA[11];          // GPIOx 计算电压 A 组缓存
    float GPIOxVoltageB[11];          // GPIOx 计算电压 B 组缓存
    uint8_t VGPIOSinglex[11 * 2];     // GPIOx 原始寄存器采样数据 (双字节)
    float GPIOTemp[11];               // 映射为温度后的值

    uint8_t VcellOffsetx[26];         // 电芯电压偏移量
    uint8_t VcellSinglex[26 * 2];     // 电芯原始寄存器采样数据 (双字节)
    float Vcellx[26];                 // 电芯实际计算电压 (V)
    float VcellxA[26];                // 电芯计算电压 A 组缓存
    float VcellxB[26];                // 电芯计算电压 B 组缓存

    // ====================================================
    // 6. EIS 电压/电流原始采样与转换数据 (EIS Raw & Decoded Data)
    // ====================================================
    // EIS Voltage data (R: Real, I: Imaginary)
    uint8_t VCeis_R[26 * 3];          // 电压实部 原始数据 (每通道3字节)
    uint8_t VCeis_I[26 * 3];          // 电压虚部 原始数据 (每通道3字节)
    int32_t debug[26];                // 内部调试/转换用缓存
    float VCeis_R_Decode[26];         // 解析后的电压实部 (V)
    float VCeis_I_Decode[26];         // 解析后的电压虚部 (V)
    
    // EIS Current data
    uint8_t CSeis_R[3];               // 电流实部 原始数据 (3字节)
    uint8_t CSeis_I[3];               // 电流虚部 原始数据 (3字节)
    float CSeis_R_Decode[1];          // 解析后的电流实部 (A)
    float CSeis_I_Decode[1];          // 解析后的电流虚部 (A)
    
    // ====================================================
    // 7. EIS 阻抗计算最终结果 (EIS Impedance Final Results)
    // ====================================================
    float Zeis_R_Decode[26];          // 阻抗实部 (Real part of Impedance)
    float Zeis_I_Decode[26];          // 阻抗虚部 (Imaginary part of Impedance)
    // 注意：变量命名约定：M代表幅值(Magnitude)，P代表相位(Phase)
    float Zeis_M_Decode[26];          // 阻抗幅值 (Magnitude of Impedance, 单位: Ohm)
    float Zeis_P_Decode[26];          // 阻抗相位 (Phase of Impedance, 单位: 度/Deg)

    // ====================================================
    // 8. 其他系统参数与诊断寄存器 (Other System/Diag Regs)
    // ====================================================
    float Vbusbar;                    // 汇流排电压
    float Diag_rdnt_cbbb;             // 冗余诊断数据
    float Diag_main_vc;               // 主电压诊断数据

    dev_stat1_t DevStat1;             // 设备状态寄存器1
    dev_stat2_t DevStat2;             // 设备状态寄存器2
    fault_adc_misc_t FaultAdcMisc;    // ADC 杂项故障
    fault_adc_gpio1_t FaultAdcGpio1;  // GPIO ADC 故障1
    fault_adc_gpio2_t FaultAdcGpio2;  // GPIO ADC 故障2
    fault_adc_vcell1_t FaultAdcVcell1;// 电芯电压 ADC 故障1
    fault_adc_vcell2_t FaultAdcVcell2;// 电芯电压 ADC 故障2
    fault_adc_vcell3_t FaultAdcVcell3;// 电芯电压 ADC 故障3

    otp_prog_unlock1_t OtpProgUnlock1;// OTP 编程解锁1
    otp_prog_unlock2_t OtpProgUnlock2;// OTP 编程解锁2
    otp_stat_t OtpStat;               // OTP 状态
    control2_t Control2;              // 系统控制寄存器2
    control1_t Control1;              // 系统控制寄存器1 (包含关机控制等)

    diag_misc_ctrl2_t DiagMiscCtrl2;  // 杂项诊断控制2
    fault_cb_fetow1_t FaultCbFetow1;  // 均衡 FET 开路故障1
    fault_cb_fetow2_t FaultCbFetow2;  // 均衡 FET 开路故障2
    fault_cb_fetow3_t FaultCbFetow3;  // 均衡 FET 开路故障3

    // ====================================================
    // 9. EIS 核心配置寄存器组 (EIS Core Registers)
    // ====================================================
// new EIS
    eis_stat_t EisStat;               // EIS 运行状态 (DFE/DFT完成标志)
    eis_misc_ctrl_t EisMiscCtrl;      // EIS 杂项控制 (使能/复位)
    debug_ctrl_unlock_t DebugCtrlUnlock; // 隐藏调试解锁
    debug_comm_ctrl1_t DebugCommCtrl1;   // 隐藏调试控制 (如禁用通信超时)

    // PWM 配置 (用于生成正弦波激励)
    eis_pwm_ctrl1_t EisPwmCtrl1;
    // eis_pwm_ctrl2_t Eis_Pwm_Ctrl2; //resd
    // eis_pwm_ctrl3_t Eis_Pwm_Ctrl3;
    // eis_pwm_ctrl4_t Eis_Pwm_Ctrl4;
    // eis_pwm_ctrl5_t Eis_Pwm_Ctrl5;
    eis_pwm_ctrl6_t EisPwmCtrl6;
    // eis_pwm_ctrl7_t Eis_Pwm_Ctrl7;
    // eis_pwm_ctrl8_t Eis_Pwm_Ctrl8;
    // eis_pwm_ctrl9_t Eis_Pwm_Ctrl9;
    // eis_pwm_ctrl10_t Eis_Pwm_Ctrl10;    
    eis_pwm_ctrl11_t EisPwmCtrl11;    
    eis_pwm_ctrl12_t EisPwmCtrl12;   
    eis_pwm_ctrl13_t EisPwmCtrl13;      
    eis_pwm_ctrl14_t EisPwmCtrl14;   
    eis_pwm_ctrl15_t EisPwmCtrl15;  

    // DFT 配置 (离散傅里叶变换计算参数)
    eis_dft_ctrl1_t EisDftCtrl1;          
    eis_dft_ctrl2_t EisDftCtrl2;
    eis_dft_ctrl3_t EisDftCtrl3;          
    eis_dft_ctrl4_t EisDftCtrl4;

    // DFE 配置 (数字前端，包含增益、滤波)
    eis_dfe_ctrl1_t EisDfeCtrl1;
    eis_dfe_ctrl2_t EisDfeCtrl2;
    eis_dfe_ctrl3_t EisDfeCtrl3;
    eis_dfe_ctrl4_t EisDfeCtrl4;
    eis_dfe_ctrl5_t EisDfeCtrl5;
    eis_dfe_ctrl6_t EisDfeCtrl6;
    eis_dfe_ctrl7_t EisDfeCtrl7;
    eis_dfe_ctrl8_t EisDfeCtrl8;   
    eis_dfe_ctrl9_t EisDfeCtrl9; 
    eis_dfe_ctrl10_t EisDfeCtrl10;
    eis_dfe_ctrl11_t EisDfeCtrl11;
    eis_dfe_ctrl12_t EisDfeCtrl12;
    eis_dfe_ctrl13_t EisDfeCtrl13;
    eis_dfe_ctrl14_t EisDfeCtrl14;
    eis_dfe_ctrl15_t EisDfeCtrl15;
    eis_dfe_ctrl16_t EisDfeCtrl16;
    eis_dfe_ctrl17_t EisDfeCtrl17;
    eis_dfe_ctrl18_t EisDfeCtrl18;   
    eis_dfe_ctrl19_t EisDfeCtrl19; 
    eis_dfe_ctrl20_t EisDfeCtrl20;   
    eis_dfe_ctrl21_t EisDfeCtrl21;
    eis_dfe_ctrl22_t EisDfeCtrl22;
    eis_dfe_ctrl23_t EisDfeCtrl23;
    eis_dfe_ctrl24_t EisDfeCtrl24;
    eis_dfe_ctrl25_t EisDfeCtrl25;
    eis_dfe_ctrl26_t EisDfeCtrl26;

    // COM 配置 (EIS通信、中断等)
    eis_com_ctrl1_t EisComCtrl1;
    eis_com_ctrl2_t EisComCtrl2;
    eis_com_ctrl3_t EisComCtrl3;
    eis_com_ctrl4_t EisComCtrl4; 
    eis_com_ctrl5_t EisComCtrl5;
    eis_com_ctrl6_t EisComCtrl6;
    eis_com_ctrl7_t EisComCtrl7;  
    
    // ====================================================
    // 10. 系统级同步与频率控制 (System Sync & Freq Control)
    // ====================================================
    smart_freeze_ctrl1_t SmartFreezeCtrl1;  
    smart_freeze_ctrl2_t SmartFreezeCtrl2;  
    smart_freeze_stat3_t SmartFreezeStat3;
    hfo_freq_ctrl1_t HfoFreqCtrl1;          // 高频振荡器控制1
    hfo_freq_ctrl2_t HfoFreqCtrl2;          // 高频振荡器控制2
    pll_sync_ctrl1_t PllSyncCtrl1;          // PLL 同步控制1
    pll_sync_ctrl2_t PllSyncCtrl2;          // PLL 同步控制2

    dig_sync_ctrl1_t DigSyncCtrl1;          // 数字同步控制1
    dig_sync_ctrl2_t DigSyncCtrl2;          // 数字同步控制2
    dig_sync_ctrl3_t DigSyncCtrl3;          // 数字同步控制3
    dig_sync_ctrl4_t DigSyncCtrl4;          // 数字同步控制4
    dig_sync_ctrl5_t DigSyncCtrl5;          // 数字同步控制5
    dig_sync_ctrl6_t DigSyncCtrl6;          // 数字同步控制6
    dig_sync_ctrl7_t DigSyncCtrl7;          // 数字同步控制7
    dig_sync_ctrl8_t DigSyncCtrl8;          // 数字同步控制8
    dig_sync_ctrl9_t DigSyncCtrl9;          // 数字同步控制9
    dig_sync_ctrl10_t DigSyncCtrl10;        // 数字同步控制10
    dig_sync_ctrl11_t DigSyncCtrl11;        // 数字同步控制11
    dig_sync_ctrl12_t DigSyncCtrl12;        // 数字同步控制12
    dig_sync_ctrl13_t DigSyncCtrl13;        // 数字同步控制13

    comm_conf1_t CommConf1;                 // 通信配置1 (如设备群组配置)

    dev_conf1_t DevConf1;                   // 设备配置1
    dev_conf2_t DevConf2;                   // 设备配置2 (含电芯数量配置)
    dev_conf3_t DevConf3;                   // 设备配置3 (含晶振使能)

    smart_freeze_conf_t SmartFreezeConf;    // 智能冻结配置

    adc_ctrl5_t AdcCtrl5;                   // ADC 控制寄存器5

    ov_thresh1_t OvThresh1;                 // 过压阈值1
    uv_thresh1_t UvThresh1;                 // 欠压阈值1
    ov_thresh2_t OvThresh2;                 // 过压阈值2
    uv_thresh2_t UvThresh2;                 // 欠压阈值2
    otut_thresh1_t OtutThresh1;             // 过温/欠温阈值1
    otut_thresh2_t OtutThresh2;             // 过温/欠温阈值2
    smonh_thresh_t SmonhThresh;             // 监测阈值上限
    smonl_thresh_t SmonlThresh;             // 监测阈值下限

    mon_ctrl_t MonCtrl;                     // 监测控制

    dig_sync_conf1_t DigSyncConf1;          // 数字同步配置1
    dig_sync_conf2_t DigSyncConf2;          // 数字同步配置2
    dig_sync_stat1_t DigSyncStat1;          // 数字同步状态1
    dig_sync_stat2_t DigSyncStat2;          // 数字同步状态2
    
    // ----------------------------------------------------
    // EIS (Electrochemical Impedance Spectroscopy) State & Parameters
    // ----------------------------------------------------
    uint16_t sync_count;         // 同步计数器 (Sync Counter)
    uint8_t freq_adj;            // 频率调整值 (Frequency Adjustment)
    int current_delta;           // 同步计数差值 (Current Delta)
    uint32_t dft_len_struct;     // DFT计算长度 (Discrete Fourier Transform Length)
    uint32_t dfe_wait_time;      // DFE(数字前端)滤波器等待稳定时间 (DFE Wait Time)
    uint32_t freq_indxn;         // 当前扫描的频率索引 (Frequency Index for Multi-frequency Scan)
    uint32_t dft_wait_time;      // DFT计算等待时间 (DFT Wait Time)
    uint8_t dsr;                 // 降采样率 (Down Sample Rate)
    float hpf_coefficient;       // 数字高通滤波器系数 (High Pass Filter Coefficient)
    uint32_t hpf_coefficent_reg; // HPF系数寄存器配置值
    float eis_frequency;         // 当前配置的EIS目标检测频率 (Target EIS Frequency, e.g. 0.1k - 1k Hz)
    float bin_size;              // 频谱的频率分辨率 (Frequency Resolution/Bin Size)
} bq7982x_dev_t;

/**
 * @brief BQ7982x Register table
 *
 */
typedef struct {
    uint8_t TaskStatus;
    volatile uint8_t TaskDelayReady;

    int8_t RecoveryMode;
    int8_t RecoveryMode_Reverse;

    int8_t FaultNode;
    int8_t BrokenNodeID;
    int8_t FaultNode_Reverse;
    int8_t BrokenNodeID_Reverse;

    int8_t StackTopNodeID;
    int8_t StackTopNodeID_Reverse;

    int8_t CANIDSet;
} bq7982x_syssta_t;

#endif /* BQ79826_DATA_TYPES_H_ */
