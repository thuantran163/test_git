#ifndef __GYROSCOPE_INSTANCE_H__
#define __GYROSCOPE_INSTANCE_H__

#include <stdint.h>
#include <stdio.h>

/* Status type definition */
typedef enum
{
    GYROSCOPE_OK      = 0,
    GYROSCOPE_ERROR   = 1,
    GYROSCOPE_TIMEOUT = 2
} GYROSCOPE_StatusTypeDef;

/* Driver function structure for Gyroscope */
typedef struct
{
    void     (*Init)(uint16_t);
    void     (*DeInit)(void);
    uint8_t  (*ReadID)(void);
    void     (*Reset)(void);
    void     (*LowPower)(uint16_t);
    void     (*ConfigIT)(uint16_t);
    void     (*EnableIT)(uint8_t);
    void     (*DisableIT)(uint8_t);
    uint8_t  (*ITStatus)(uint16_t, uint16_t);
    void     (*ClearIT)(void);
    void     (*FilterConfig)(uint8_t);
    void     (*FilterCmd)(uint8_t);
    void     (*GetXYZ)(int16_t *);
} GYROSCOPE_DrvTypeDef;

/* Initialization structure for Gyroscope */
typedef struct
{
    uint8_t Power_Mode;
    uint8_t GyroOutput_DataRate;
    uint8_t Axes_Enable;
    uint8_t High_Resolution;
    uint8_t BlockData_Update;
    uint8_t Endianness;
    uint8_t GyroFull_Scale;
    uint8_t Communication_Mode;
} GYROSCOPE_InitTypeDef;

/* Filter configuration structure */
typedef struct
{
    uint8_t HighPassFilter_Mode_Selection;
    uint8_t HighPassFilter_CutOff_Freq;
    uint8_t HighPassFilter_AOI1;
    uint8_t HighPassFilter_AOI2;
    uint8_t HighPassFilter_Data_Sel;
    uint8_t HighPassFilter_Stat;
} GYROSCOPE_FilterConfigTypeDef;


int GYROSCOPE_IO_Read(uint8_t reg, uint8_t *data, uint8_t size);
int GYROSCOPE_IO_Write(uint8_t reg, uint8_t value);
void GYROSCOPE_IO_Init(void);
void GYROSCOPE_IO_Write(uint8_t *pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite);
void GYROSCOPE_IO_Read(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead);

#endif /* __GYROSCOPE_INSTANCE_H__ */

