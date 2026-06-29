/************************************** (C) Copyright 2022-2024 De.Power,China.
 * ************************************* DE.POWER Co., Ltd * Product R & D
 * department                                            * Software Department *
 *                                                All Rights Reserved. */
/********************************************************************************************************************
 * @file            main.c
 * @brief           None.
 * @details         no details
 * @attention       no attention
 * @author          zhuyongjun@depower.com.cn
 * @version         V2.00
 * @date            2024-07-03
 * @copyright       DE.POWER
 * *****************************************************************************************************************/
#include "main.h"
#include "ProjectConfig.h"
/******************************/
#include <stddef.h>
#include <stdio.h>
/******************************/
#include "bsp_bq7982x.h"     // [通用/核心] BQ7982x 驱动头文件 (SPI)
#include "bsp_bq7982x_app.h" // [通用/核心] BQ7982x 应用逻辑 (EIS 状态机)
// #include "TI_Adapter.h" // Add TI Adapter
#include "MSP_GPIO.h" // Add MSP_GPIO.h for GPIO_writePin
#include "MSP_SPI.h"  // Add MSP_SPI.h for SPI_writeDataBlockingFIFO
#include "MSP_UART.h" // UART print

char soft_version[4] =
    "0001"; // The first two bytes are the hardware version, and the last two  bytes are the software version.
char hard_version[4] = "0001";
char inner_version[4] = "0001";

//
// Defines
//
// #define EPWM_TIMER_TBPRD    9UL
#define MIN_HRPWM_PRD_PERCENT 0.75f
#define EPWM_TIMER_TBPRD 18
#define EIS_SCAN_EN_PORT GPIOA
#define EIS_SCAN_EN_PIN  GPIO_PIN_9

//
// Globals
// 全局变量定义

volatile float32_t sin_fs = 50.0f; // sin_fs: EIS 激励频率

// [核心] 系统任务调度相关的全局变量
volatile uint32_t gSysTickCnt = 0;    // 系统计时
volatile uint32_t gEisSysTickCnt = 0;// 任务标志位
volatile bool gTaskDigitalSync = false; 
volatile bool gTaskEisDFE   = false;    
volatile bool gTaskEisDFT   = false;    
volatile bool gTaskEisRead   = false;   
volatile bool gTaskStartEisQuery = false;       // 上位机请求启动“扫频测试”
volatile bool gTaskStartSingleEisQuery = false; // 上位机请求启动“单频测试”
volatile bool gTaskStopEisQuery = false;        // 上位机请求停止 EIS，停止后必须关闭载波/PWM/ADC/DFE
volatile bool gTaskSetEisFreq = false;          // 上位机设置单频测试频率
volatile bool gTaskWakeStackQuery = false;      // 上位机请求唤醒/重新初始化 BQ 栈
volatile bool gTaskBqResetQuery = false;        // 上位机请求 BQ 软件复位
volatile bool gTaskBqSleepQuery = false;        // PC request to put BQ stack into sleep
volatile float32_t gEisRequestedFreq = 50.0f;   // 单频测试时，上位机下发的目标频率
volatile uint8_t gEisConfigOverride = 0;        // 单频测试是否使用上位机下发的 DFT/HPF/DSR 参数
volatile uint32_t gEisRequestedDftLength = 0;   // 单频测试自定义 DFT 长度
volatile float32_t gEisRequestedHpfHz = 0.0f;   // 单频测试自定义高通滤波截止频率
volatile uint8_t gEisRequestedDsr = 0;          // 单频测试自定义降采样倍率

// EIS 状态标志：
// 0 = 空闲/等待启动；1 = 已配置并启动 PWM/ADC/DFE；2 = 已触发 DFT；
// 3 = 正在等待 BQ EIS 完成；4 = 本次测试结果已读完。
volatile uint8_t eis_run_flag = 0;
volatile uint8_t digital_sync_flag = 0;
volatile uint8_t update_frq = 0;
volatile uint8_t EIS_I2S_Enable = 0;

// [核心] BQ7982x 设备实例
bq7982x_dev_t gBQDev[TOTALBOARDS] = {0};
bq7982x_syssta_t gBQSta = {0};
uint8_t gAddrResponse[TOTALBOARDS] = {0};
uint8_t gBQRxBuffer[(MAXBYTES + 6) * TOTALBOARDS + 64] = {0};

// EIS 结果解码数组
float32_t result_decode_P[ACTIVECHANNELS *
                          TOTALBOARDS]; // P 代表 相位 (Phase)
float32_t result_decode_M[ACTIVECHANNELS *
                          TOTALBOARDS]; // M 代表 阻抗幅值 (Impedance/Magnitude)

// 扫频测试参数表：下面 4 个数组按相同索引一一对应。
// 例如 current_scan_idx = 0 时，使用 0.04Hz、DFT=97656、HPF=0.04Hz、DSR=10。
// 每完成一个频点，current_scan_idx 加 1，直到 SCAN_FREQ_COUNT 全部测完。
float32_t eis_scan_freqs[] = {
    0.04f, 0.06f, 0.1f, 0.16f, 0.25f,
    0.4f, 0.63f, 1.0f, 1.5f, 2.5f,
    4.0f, 6.25f, 10.0f, 16.0f, 25.25f,
    40.0f, 63.5f, 98.0f, 151.75f, 235.0f,
    363.75f, 563.0f, 871.5f, 1348.62f, 2087.29f
};
uint32_t eis_scan_dft_lengths[] = {
    97656u, 65104u, 39063u, 30518u, 31250u,
    32552u, 31002u, 39063u, 31250u, 31250u,
    31250u, 31250u, 31250u, 31250u, 31250u,
    31250u, 31250u, 31250u, 31250u, 31250u,
    31250u, 31250u, 31250u, 31250u, 31250u
};
float32_t eis_scan_hpf_hz[] = {
    0.04f, 0.06f, 0.1f, 0.16f, 0.25f,
    0.4f, 0.63f, 1.0f, 1.5f, 2.5f,
    4.0f, 6.25f, 10.0f, 10.0f, 10.0f,
    10.0f, 10.0f, 10.0f, 10.0f, 10.0f,
    10.0f, 10.0f, 10.0f, 10.0f, 10.0f
};
uint8_t eis_scan_dsrs[] = {
    10u, 10u, 10u, 8u, 5u,
    3u, 2u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u
};
#define SCAN_FREQ_COUNT (sizeof(eis_scan_freqs) / sizeof(eis_scan_freqs[0]))

volatile uint8_t is_scanning =
    1;       // 扫频模式标志：1=按频率表连续扫频，0=只测 sin_fs 一个频点
volatile uint8_t current_scan_idx = 0;  // 当前扫描频率索引
volatile uint8_t current_freq_test_count = 0; // 当前频率的测试次数计数器
#define TEST_TIMES_PER_FREQ 1 // 每个频率测试的次数


// 存储每次扫描结果的二维数组
float32_t scan_result_P[SCAN_FREQ_COUNT][ACTIVECHANNELS *
        TOTALBOARDS]; // 存储每个频率点的 相位 (Phase)
float32_t scan_result_M[SCAN_FREQ_COUNT][ACTIVECHANNELS *
        TOTALBOARDS]; // 存储每个频率点的 阻抗幅值 (Impedance/Magnitude)
float32_t scan_result_R[SCAN_FREQ_COUNT][ACTIVECHANNELS *
        TOTALBOARDS]; // 存储每个频率点的 实部 (Real Part, 用于Nyquist图)
float32_t scan_result_I[SCAN_FREQ_COUNT][ACTIVECHANNELS *
        TOTALBOARDS]; // 存储每个频率点的 虚部 (Imaginary Part, 用于Nyquist图)

//
// Function Prototypes
//
void SysTask_ReadEis(void);
void SysTask_DigitalSync(void);
void SysTask_SetEisDFE(void);
void SysTask_StartEisDFT(void);
static void InitBmicStack(void);
static void EisScanGpioInit(void);
static void EisScanGpioSet(uint8_t level);
static void ApplyEisTableConfig(bq7982x_dev_t *pBQDev, float32_t freq, uint32_t dft_len, float32_t hpf_hz, uint8_t dsr);

static void EisScanGpioInit(void)
{
    // PA9 用作 EIS 测试状态输出：0=未测试/已停止，1=正在单频或扫频测试。
    MSP_GPIO_Init(EIS_SCAN_EN_PORT, EIS_SCAN_EN_PIN, GPIO_Mode_Out_PP);
    MSP_GPIO_Write(EIS_SCAN_EN_PORT, EIS_SCAN_EN_PIN, 0);
}

static void EisScanGpioSet(uint8_t level)
{
    // 统一控制 EIS 测试状态 GPIO，避免各处直接操作 PA9。
    MSP_GPIO_Write(EIS_SCAN_EN_PORT, EIS_SCAN_EN_PIN, level ? 1u : 0u);
}

static void InitBmicStack(void)
{
    // 唤醒并初始化 BQ 栈。
    // 注意：此函数之前不要调用 EIS_Stop() 或写 EIS 寄存器，因为此时 BQ 可能还没醒。
    WakeStackDevice();
    AutoAddress(gAddrResponse, gBQRxBuffer);
    DisableTimeout(0, &gBQDev[0], FRMWRT_ALL_W);
    // 配置 BQ 晶振/PLL 相关模式；EIS PWM 的 32MHz 时钟来自 BQ 内部 HFO/晶振路径。
    PWM_CRYSTAL(&gBQDev[0], gBQRxBuffer);
    NVM_Register_Configuration(0, &gBQDev[0]);
    BQ7982X_SetGpio20High(0, &gBQDev[0], FRMWRT_ALL_W);
}

static void ApplyEisTableConfig(bq7982x_dev_t *pBQDev, float32_t freq, uint32_t dft_len, float32_t hpf_hz, uint8_t dsr)
{
    // 按扫频表或上位机参数，把目标频率换算成 BQ EIS 需要的寄存器参数。
    // 这里主要计算：
    // 1. freq_idx：目标频率落在 DFT 的哪个频点；
    // 2. hpf_reg：高通滤波系数寄存器值；
    // 3. dfe_wait_time / dft_wait_time：后续状态机等待时间。
    const float32_t f_sample_hz = 7812.5f;
    const float32_t pi = 3.141592654f;
    const float32_t hpf_lsb = 0.0000009536743f;
    uint32_t dft_len_reg;
    uint32_t freq_idx;
    uint32_t hpf_reg;
    float32_t bin_size_local;
    float32_t hpf_coefficient;
    float32_t dfe_wait_time;
    float32_t dft_wait_time;

    if (pBQDev == NULL || freq <= 0.0f || dft_len == 0u || hpf_hz <= 0.0f || dsr == 0u)
    {
        return;
    }

    bin_size_local = f_sample_hz / (float32_t)dsr / (float32_t)dft_len;
    freq_idx = (uint32_t)roundf(freq / bin_size_local);
    hpf_coefficient = 1.0f - 2.0f * pi * hpf_hz / (f_sample_hz / (float32_t)dsr);
    hpf_reg = (uint32_t)roundf(hpf_coefficient / hpf_lsb);
    dfe_wait_time = roundf(1.0f / hpf_hz * 5.0f);
    dfe_wait_time = (dfe_wait_time > 2.0f) ? dfe_wait_time : 2.0f;
    dft_wait_time = ceilf((float32_t)dft_len * (float32_t)dsr / f_sample_hz);
    dft_len_reg = (dft_len > 780u) ? (dft_len - 780u) : dft_len;

    pBQDev->eis_frequency = freq;
    pBQDev->freq_indxn = freq_idx;
    pBQDev->dfe_wait_time = dfe_wait_time;
    pBQDev->dft_wait_time = dft_wait_time;
    pBQDev->dft_len_struct = dft_len;
    pBQDev->hpf_coefficient = hpf_coefficient;
    pBQDev->dsr = dsr;
    pBQDev->hpf_coefficent_reg = hpf_reg;

    pBQDev->EisComCtrl2.fs.dft_lenh = (dft_len_reg >> 16) & 0x0F;
    pBQDev->EisComCtrl3.fs.dft_lenm = (dft_len_reg >> 8) & 0xFF;
    pBQDev->EisComCtrl4.fs.dft_lenl = dft_len_reg & 0xFF;
    pBQDev->EisComCtrl5.fs.freq_idx1h = (freq_idx >> 16) & 0x07;
    pBQDev->EisComCtrl6.fs.freq_idx1m = (freq_idx >> 8) & 0xFF;
    pBQDev->EisComCtrl7.fs.freq_idx1l = freq_idx & 0xFF;
    pBQDev->EisDfeCtrl26.fs.eis_dsr = dsr - 1u;
    pBQDev->EisDfeCtrl5.fs.hpf_coefh = (hpf_reg >> 16) & 0x0F;
    pBQDev->EisDfeCtrl6.fs.hpf_coefm = (hpf_reg >> 8) & 0xFF;
    pBQDev->EisDfeCtrl7.fs.hpf_coefl = hpf_reg & 0xFF;
}

int main(void)
{
    /* Configure SysTick for 1ms interrupts and DEVICE_DELAY_US */
    systick_init();
    
    /* Initialize UART1 for printf (115200 baudrate) */
    log_uart_init(115200);
    EisScanGpioInit();


    // [通用/核心] BQ7982x 参数初始化
    BQParamInit(&gBQDev[0], &gBQSta);
    update_frq = 0;   // 上电后不立即配置 EIS，等待上位机启动命令
    is_scanning = 0;  // 上电默认不扫频，只有收到扫频命令后才置 1
    
    while (1)
    {
        // 上位机请求停止 EIS：
        // 立即关闭 BQ 的 EIS PWM/ADC/DFE，清掉所有单频/扫频状态。
        // 这个分支用于测试过程中人工停止，或者异常时强制停载波和激励电流。
        if (gTaskStopEisQuery)
        {
            gTaskStopEisQuery = false;
            EIS_Stop(0, &gBQDev[0], FRMWRT_ALL_W);
            is_scanning = 0;
            current_scan_idx = 0;
            current_freq_test_count = 0;
            update_frq = 0;
            gTaskEisDFT = false;
            gTaskEisRead = false;
            eis_run_flag = 0;
            EisScanGpioSet(0);
            continue;
        }

        // 上位机请求唤醒 BQ 栈：
        // 这里只清 MCU 侧的 EIS 状态，然后调用 InitBmicStack() 唤醒/初始化 BQ。
        // 这里不能调用 EIS_Stop()，因为 BQ 可能还没醒，提前写 EIS 寄存器会影响唤醒通信。
        if (gTaskWakeStackQuery)
        {
            gTaskWakeStackQuery = false;
            is_scanning = 0;
            current_scan_idx = 0;
            current_freq_test_count = 0;
            update_frq = 0;
            gTaskEisDFT = false;
            gTaskEisRead = false;
            eis_run_flag = 0;
            EisScanGpioSet(0);
            InitBmicStack();
            printf("ACK_WAKE\r\n");
            continue;
        }

        // 上位机请求 BQ 软件复位：
        // 先清 MCU 侧 EIS 状态，再给 BQ 发 soft reset，最后回复 ACK_RESET。
        if (gTaskBqResetQuery)
        {
            gTaskBqResetQuery = false;
            is_scanning = 0;
            current_scan_idx = 0;
            current_freq_test_count = 0;
            update_frq = 0;
            gTaskEisDFT = false;
            gTaskEisRead = false;
            eis_run_flag = 0;
            EisScanGpioSet(0);
            BQ7982X_SoftReset(0, FRMWRT_SGL_W);
            InitBmicStack();
            printf("ACK_RESET\r\n");
            continue;
        }

        // 上位机只修改单频测试频率：
        // 这里仅更新 sin_fs，不会立即启动测试；真正启动由 gTaskStartSingleEisQuery 触发。
        if (gTaskBqSleepQuery)
        {
            gTaskBqSleepQuery = false;
            EIS_Stop(0, &gBQDev[0], FRMWRT_ALL_W);
            is_scanning = 0;
            current_scan_idx = 0;
            current_freq_test_count = 0;
            update_frq = 0;
            gTaskEisDFT = false;
            gTaskEisRead = false;
            eis_run_flag = 0;
            EisScanGpioSet(0);
            BQ7982X_GotoSleep(0, FRMWRT_ALL_W);
            printf("ACK_SLEEP\r\n");
            continue;
        }

        if (gTaskSetEisFreq)
        {
            gTaskSetEisFreq = false;
            if (gEisRequestedFreq > 0.0f)
            {
                sin_fs = gEisRequestedFreq;
            }
        }

        // 上位机启动单频 EIS 测试：
        // is_scanning=0 表示不走频率表，只测 sin_fs 当前频率。
        // update_frq=1 会触发后面的 SysTask_SetEisDFE()，完成参数配置并打开 PWM/ADC/DFE。
        if (gTaskStartSingleEisQuery)
        {
            gTaskStartSingleEisQuery = false;
            is_scanning = 0;
            current_scan_idx = 0;
            current_freq_test_count = 0;
            EisScanGpioSet(1);
            update_frq = 1;
        }

        // 上位机启动扫频 EIS 测试：
        // is_scanning=1 表示按 eis_scan_freqs[] 参数表，从第 0 个频点开始连续测试。
        // 每个频点测完后，SysTask_ReadEis() 会自动推进 current_scan_idx。
        if (gTaskStartEisQuery)
        {
            gTaskStartEisQuery = false;
            EisScanGpioSet(1);
            is_scanning = 1;
            current_scan_idx = 0;
            current_freq_test_count = 0;
            update_frq = 1;
        }

        /****************************************************************
         *  EISDFE task
         *  [通用/核心] EIS DFE 配置与启动任务
         *  (使用 BQ7982x 内部激励时，此任务负责启动内部 PWM)
         */
        if (update_frq == 1)
        {
            // 单频启动、扫频启动、扫频切换到下一个频点，都会走到这里。
            // 该函数会根据当前模式配置 EIS 参数，然后打开 BQ 内部 PWM/ADC/DFE。
            gEisSysTickCnt = 0;
            SysTask_SetEisDFE();
            update_frq = 0;
            continue;
        }
        /****************************************************************
         *  EISDFT task
         *  [通用/核心] EIS DFT 启动任务 (Smart Freeze)
         */
        if (gTaskEisDFT == true)
        {
            // DFE 等待时间到后触发：启动 BQ 的 Smart Freeze/DFT。
            DEVICE_DELAY_MS(10);
            SysTask_StartEisDFT();
            gTaskEisDFT = false;
            continue;
        }
        /****************************************************************
         *  EISREAD task
         *  [通用/核心] EIS 结果读取与计算任务
         */
        if (gTaskEisRead == true)
        {
            // DFT 等待时间到后触发：读取 BQ 结果寄存器并计算/上报阻抗。
            SysTask_ReadEis();
            gTaskEisRead = false;
            continue;
        }
    }
}

// [通用/核心] EIS 读取任务
void SysTask_ReadEis(void)
{
    uint8_t i;

    // 先问 BQ：本次 EIS/DFT 是否已经完成。
    // 返回 0 表示还没完成，本次不读结果，等待下一次 gTaskEisRead 调度。
    if (EISCompleteCheck(0, &gBQDev[0], gBQRxBuffer, FRMWRT_SGL_R) == 0)
    {
        eis_run_flag = 3;
        return;
    }

    // BQ 已完成：读取电压通道 CV 和电流通道 CC 的 EIS 结果。
    Read_EIS_CV(0, &gBQDev[0], gBQRxBuffer, FRMWRT_SGL_R);
    Read_EIS_CC(0, &gBQDev[0], gBQRxBuffer, FRMWRT_SGL_R);

    // 根据 CV/CC 结果计算阻抗，输出包含：
    // result_decode_M/P：幅值和相位；
    // gBQDev[0].Zeis_R_Decode / Zeis_I_Decode：实部和虚部。
    EIS_Z_Cal(&gBQDev[0], result_decode_P, result_decode_M);

    // 扫频模式：保存当前频点结果，上报数据，然后决定是否切换到下一个频点。
    if (is_scanning)
    {
        // 保存当前频点所有通道的结果，方便后续绘图或回看。
        for (i = 0; i < ACTIVECHANNELS * TOTALBOARDS; i++)
        {
            scan_result_P[current_scan_idx][i] = result_decode_P[i];
            scan_result_M[current_scan_idx][i] = result_decode_M[i];
            scan_result_R[current_scan_idx][i] = gBQDev[0].Zeis_R_Decode[i];
            scan_result_I[current_scan_idx][i] = gBQDev[0].Zeis_I_Decode[i];
        }
        
        // 向上位机逐通道上报当前频点结果。
        // 格式：EIS_DATA,频率,本频点第几次测试,通道号,实部,虚部,幅值,相位
        for (i = 0; i < ACTIVECHANNELS * TOTALBOARDS; i++)
        {
            printf("EIS_DATA,%.6f,%u,%u,%.6f,%.6f,%.6f,%.6f\r\n",
                   eis_scan_freqs[current_scan_idx],
                   (unsigned int)(current_freq_test_count + 1),
                   (unsigned int)i,
                   scan_result_R[current_scan_idx][i], scan_result_I[current_scan_idx][i],
                   scan_result_M[current_scan_idx][i], scan_result_P[current_scan_idx][i]);
        }
        log_uart_wait_tx_complete();

        current_freq_test_count++;
        if (current_freq_test_count < TEST_TIMES_PER_FREQ)
        {
            // 当前频点还需要重复测试：重新配置并再次启动同一个频率。
            update_frq = 1;
            eis_run_flag = 0;
            return;
        }

        // 当前频点测试次数已满足，切换到扫频表的下一个频点。
        current_freq_test_count = 0;
        current_scan_idx++;
        if (current_scan_idx < SCAN_FREQ_COUNT)
        {
            // 还有下一个频点：置 update_frq，让主循环重新配置 BQ 并启动下一次 EIS。
            update_frq = 1;
            eis_run_flag = 0;
            return;
        }
        else
        {
            // 扫频表全部完成：
            // 关闭 BQ 内部 PWM/ADC/DFE，避免扫频结束后仍有载波和激励电流。
            EIS_Stop(0, &gBQDev[0], FRMWRT_ALL_W);
            printf("EIS_DONE\r\n");
            log_uart_wait_tx_complete();
            
            // 清扫频状态并拉低测试状态 GPIO。
            is_scanning = 0;
            current_scan_idx = 0;
            current_freq_test_count = 0;
            EisScanGpioSet(0);
        }
    }
    else
    {
        // 单频模式：只上报 sin_fs 这个频点的一次结果。
        // 格式：EIS_DATA,频率,固定为1,通道号,实部,虚部,幅值,相位
        for (i = 0; i < ACTIVECHANNELS * TOTALBOARDS; i++)
        {
            printf("EIS_DATA,%.6f,1,%u,%.6f,%.6f,%.6f,%.6f\r\n",
                   sin_fs,
                   (unsigned int)i,
                   gBQDev[0].Zeis_R_Decode[i], gBQDev[0].Zeis_I_Decode[i],
                   result_decode_M[i], result_decode_P[i]);
        }
        log_uart_wait_tx_complete();

        // 单频测试完成后同样关闭 BQ 内部 PWM/ADC/DFE，避免测试结束后继续输出载波/激励。
        EIS_Stop(0, &gBQDev[0], FRMWRT_ALL_W);
        printf("EIS_DONE\r\n");
        log_uart_wait_tx_complete();
        EisScanGpioSet(0);
    }
    eis_run_flag = 4;
    return;
}

// [通用/核心] EIS DFE 配置任务
void SysTask_SetEisDFE(void)
{
    static uint8_t eis_f_count = 7;
    uint32_t table_dft_len = 0u;
    float32_t table_hpf_hz = 0.0f;
    uint8_t table_dsr = 0u;
    if (is_scanning)
    {
        EisScanGpioSet(1);
    }

    // 扫频模式：从扫频表读取当前频点的频率、DFT 长度、HPF 和 DSR。
    if (is_scanning)
    {
        gBQDev[0].eis_frequency = eis_scan_freqs[current_scan_idx];
        table_dft_len = eis_scan_dft_lengths[current_scan_idx];
        table_hpf_hz = eis_scan_hpf_hz[current_scan_idx];
        table_dsr = eis_scan_dsrs[current_scan_idx];
    }
    else
    {
        // 单频模式：使用 sin_fs 作为测试频率。
        // 如果上位机额外下发了 DFT/HPF/DSR，则覆盖默认计算结果。
        gBQDev[0].eis_frequency = sin_fs;
        if (gEisConfigOverride)
        {
            table_dft_len = gEisRequestedDftLength;
            table_hpf_hz = gEisRequestedHpfHz;
            table_dsr = gEisRequestedDsr;
        }
    }

    // 根据目标频率计算 BQ EIS 所需的默认参数。
    EIS_Para_Calculation(0, &gBQDev[0], gBQDev[0].eis_frequency);
    if (table_dft_len > 0u && table_hpf_hz > 0.0f && table_dsr > 0u)
    {
        // 如果扫频表或上位机提供了明确参数，则用这些参数覆盖默认计算值。
        ApplyEisTableConfig(&gBQDev[0], gBQDev[0].eis_frequency, table_dft_len, table_hpf_hz, table_dsr);
    }

    // 写 BQ EIS 配置寄存器，包括频点、DFT 长度、HPF、DSR、PWM 分频等。
    // 当前 EIS_Config() 中已把 BQ PWM 载波设置为 31.25kHz。
    EIS_Config(0, &gBQDev[0], FRMWRT_ALL_W);

    // 启动 BQ 内部 PWM、ADC、DFE。
    // 从这里开始，BQ 会输出 EIS 载波/激励，直到测试结束或 EIS_Stop() 被调用。
    EIS_PWM(0, &gBQDev[0], FRMWRT_ALL_W);

    eis_run_flag = 1;
    eis_f_count++;
    return;
}

// [通用/核心] EIS DFT 启动任务
void SysTask_StartEisDFT(void)
{
    // 启动智能冻结 (触发 DFT)
    EIS_SMART_FREEZE(0, &gBQDev[0], gBQRxBuffer, FRMWRT_ALL_R);
    eis_run_flag = 2;
    return;
}

// [通用/核心] 数字同步任务
void SysTask_DigitalSync(void)
{
    // 发送同步帧
    DigitalSyncEvery10ms(0, &gBQDev[0], gBQRxBuffer, FRMWRT_ALL_R);
    // 检查同步状态
    digital_sync_flag = CheckSyncStatus(&gBQDev[0]);
    return;
}
