#ifndef L3GD20_H
#define L3GD20_H

#include <stdint.h>


/* L3GD20 I2C Addresses */
#define L3GD20_ADDRESS_0 0x6AUL
#define L3GD20_ADDRESS_1 0x6BUL

/* Register Addresses */
#define L3GD20_WHO_AM_I           0x0FUL
#define L3GD20_CTRL_REG1          0x20UL
#define L3GD20_CTRL_REG2          0x21UL
#define L3GD20_CTRL_REG3          0x22UL
#define L3GD20_CTRL_REG4          0x23UL
#define L3GD20_CTRL_REG5          0x24UL
#define L3GD20_REFERENCE          0x25UL
#define L3GD20_OUT_TEMP           0x26UL
#define L3GD20_STATUS_REG         0x27UL
#define L3GD20_OUT_X_L            0x28UL
#define L3GD20_OUT_X_H            0x29UL
#define L3GD20_OUT_Y_L            0x2AUL
#define L3GD20_OUT_Y_H            0x2BUL
#define L3GD20_OUT_Z_L            0x2CUL
#define L3GD20_OUT_Z_H            0x2DUL
#define L3GD20_FIFO_CTRL_REG      0x2EUL
#define L3GD20_FIFO_SRC_REG       0x2FUL
#define L3GD20_INT1_CFG           0x30UL
#define L3GD20_INT1_SRC           0x31UL
#define L3GD20_INT1_THS_XH        0x32UL
#define L3GD20_INT1_THS_XL        0x33UL
#define L3GD20_INT1_THS_YH        0x34UL
#define L3GD20_INT1_THS_YL        0x35UL
#define L3GD20_INT1_THS_ZH        0x36UL
#define L3GD20_INT1_THS_ZL        0x37UL
#define L3GD20_INT1_DURATION      0x38UL

/* CTRL_REG1 (0x20) Masks and Positions */
#define L3GD20_PM_Pos        3U  
#define L3GD20_PM_Msk        (0x1UL << L3GD20_PM_Pos)

#define L3GD20_Zen_Pos       2U  
#define L3GD20_Zen_Msk       (0x1UL << L3GD20_Zen_Pos)

#define L3GD20_Yen_Pos       0U  
#define L3GD20_Yen_Msk       (0x1UL << L3GD20_Yen_Pos)

#define L3GD20_Xen_Pos       1U  
#define L3GD20_Xen_Msk       (0x1UL << L3GD20_Xen_Pos)

/* CTRL_REG2 (0x21) Masks and Positions */
#define L3GD20_HPM_Pos       4U
#define L3GD20_HPM_Msk       (0x3UL << L3GD20_HPM_Pos)
#define L3GD20_HPCF_Pos       0U
#define L3GD20_HPCF_Msk      (0x3UL << L3GD20_HPCF_Pos)


/* CTRL_REG3 (0x22) Masks and Positions */
#define L3GD20_I2_DRDY_Pos   3U
#define L3GD20_I2_DRDY_Msk   (0x1UL << L3GD20_I2_DRDY_Pos)
#define L3GD20_I2_OVR_Pos    1U
#define L3GD20_I2_OVR_Msk    (0x1UL << L3GD20_I2_OVR_Pos)

/* CTRL_REG4 (0x23) Masks and Positions */
#define L3GD20_BDU_Pos       7U
#define L3GD20_BDU_Msk       (0x1UL << L3GD20_BDU_Pos)
#define L3GD20_ENDIAN_Pos    6U
#define L3GD20_ENDIAN_Msk    (0x1UL << L3GD20_ENDIAN_Pos)
#define L3GD20_FS_Pos        4U
#define L3GD20_FS_Msk        (0x3UL << L3GD20_FS_Pos)

/* CTRL_REG5 (0x24) Masks and Positions */
#define L3GD20_HPEN_Pos      4U
#define L3GD20_HPEN_Msk      (0x1UL << L3GD20_HPEN_Pos)
#define L3GD20_FIFO_EN_Pos   6U
#define L3GD20_FIFO_EN_Msk   (0x1UL << L3GD20_FIFO_EN_Pos)
#define L3GD20_BOOT_Pos      7U
#define L3GD20_BOOT_Msk      (0x1UL << L3GD20_BOOT_Pos)

/* FIFO_CTRL_REG (0x2E) Masks and Positions */
#define L3GD20_FTH_Pos       0U
#define L3GD20_FTH_Msk       (0x1FUL << L3GD20_FTH_Pos)
#define L3GD20_FIFO_MODE_Pos 6U
#define L3GD20_FIFO_MODE_Msk (0x3UL << L3GD20_FIFO_MODE_Pos)

/* FIFO_SRC_REG (0x2F) Masks and Positions */
#define L3GD20_FSS_Pos       0U
#define L3GD20_FSS_Msk       (0x1FUL << L3GD20_FSS_Pos)
#define L3GD20_FIFO_OVR_Pos  7U
#define L3GD20_FIFO_OVR_Msk  (0x1UL << L3GD20_FIFO_OVR_Pos)

/* INT1_CFG (0x30) Masks and Positions */
#define L3GD20_INT_LATCH_Pos 6U
#define L3GD20_INT_LATCH_Msk (0x1UL << L3GD20_INT_LATCH_Pos)
#define L3GD20_INT_AXES_Pos  3U
#define L3GD20_INT_AXES_Msk  (0x7UL << L3GD20_INT_AXES_Pos)
#define L3GD20_THS_Pos       0U
#define L3GD20_THS_Msk       (0x7FUL << L3GD20_THS_Pos)

/* Enums for Configuration */
typedef enum {
    L3GD20_POWER_DOWN = 0x00,
    L3GD20_SLEEP = 0x01,
    L3GD20_NORMAL = 0x02
} L3GD20_PowerMode_t;

typedef enum {
    L3GD20_ODR_95Hz = 0x00,
    L3GD20_ODR_190Hz = 0x01,
    L3GD20_ODR_380Hz = 0x02,
    L3GD20_ODR_760Hz = 0x03
} L3GD20_OutputDataRate_t;

typedef enum {
    L3GD20_FS_250 = 0x00,
    L3GD20_FS_500 = 0x01,
    L3GD20_FS_2000 = 0x02
} L3GD20_FullScale_t;

typedef enum {
    L3GD20_HPF_MODE_NORMAL = 0x00,
    L3GD20_HPF_MODE_REFERENCE = 0x01,
    L3GD20_HPF_MODE_AUTORESET = 0x02,
    L3GD20_HPF_MODE_PASS = 0x03
} L3GD20_HighPassFilter_t;

typedef enum {
    L3GD20_FIFO_MODE_BYPASS = 0x00,
    L3GD20_FIFO_MODE_FIFO = 0x01,
    L3GD20_FIFO_MODE_STREAM = 0x02,
    L3GD20_FIFO_MODE_STREAM_TO_FIFO = 0x03
} L3GD20_FifoMode_t;

/* Struct for Initialization */
typedef struct {
    L3GD20_PowerMode_t Power_Mode;
    L3GD20_OutputDataRate_t Output_DataRate;
    uint8_t Axes_Enable;
    uint8_t Bandwidth;
    uint8_t BlockData_Update;
    uint8_t Endianness;
    L3GD20_FullScale_t Full_Scale;
} L3GD20_InitTypeDef;

/* Struct for Filter Configuration */
typedef struct {
    L3GD20_HighPassFilter_t HighPassFilter_Mode;
    uint8_t HighPassFilter_CutOff;
} L3GD20_FilterConfigTypeDef;

/* Struct for Interrupt Configuration */
typedef struct {
    uint8_t Latch_Request;
    uint8_t Interrupt_Axes;
    uint8_t Threshold;
    uint8_t Duration;
} L3GD20_InterruptConfigTypeDef;

/* Struct for FIFO Configuration */
typedef struct {
    uint8_t FIFO_Threshold;
    L3GD20_FifoMode_t FIFO_Mode;
} L3GD20_FifoConfigTypeDef;

typedef struct
{
    int16_t X;
    int16_t Y;
    int16_t Z;
}L3GD20_XYZ_Value_TypeDef;


/* Initialize L3GD20 with given configuration */
void L3GD20_Init(L3GD20_InitTypeDef *L3GD20_InitStruct);

/* Read WHO_AM_I register to verify device */
uint8_t L3GD20_Read_WhoAmI(void);

/* Read I2C address */
uint8_t L3GD20_Read_I2CAddress(void);

/* Read raw data from X, Y, and Z axes */
void L3GD20_Read_Axes(int16_t *X, int16_t *Y, int16_t *Z);

/* Read temperature data */
int16_t L3GD20_Read_Temperature(void);

/* Enable/Disable axes */
void L3GD20_Set_Axes(uint8_t X_Axis, uint8_t Y_Axis, uint8_t Z_Axis);

/* Set full scale range (±250, ±500, ±2000 dps) */
void L3GD20_Set_FullScale(L3GD20_FullScale_t scale);

/* Set Output Data Rate (ODR) */
void L3GD20_Set_OutputDataRate(L3GD20_OutputDataRate_t odr);

/* Configure high-pass filter */
void L3GD20_Set_HighPassFilter(L3GD20_HighPassFilter_t mode, uint8_t cutoff);

/* Configure FIFO */
void L3GD20_Set_FIFO(L3GD20_FifoMode_t mode, uint8_t threshold);

/* Enable/Disable interrupts */
void L3GD20_Enable_Interrupt(uint8_t interrupt, uint8_t enable);

/* Read FIFO status */
uint8_t L3GD20_Read_FIFOStatus(void);

/* Clear interrupt flags */
void L3GD20_Clear_Interrupt(uint8_t interrupt);

#endif // L3GD20_H

