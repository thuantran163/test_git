#include "Gyroscope_Instance.h"
#include "L3GD20.h"
#include "main.h"

// Khởi tạo cảm biến L3GD20 thông qua cấu hình từ Gyroscope_Instance
void GYROSCOPE_Init(uint16_t config)
{
    L3GD20_InitTypeDef L3GD20_InitStruct;

    // Cấu hình các tham số cho cảm biến L3GD20 qua Gyroscope_Instance
    L3GD20_InitStruct.Power_Mode = L3GD20_NORMAL;
    L3GD20_InitStruct.Output_DataRate = L3GD20_ODR_190Hz;
    L3GD20_InitStruct.Axes_Enable = 0x07;  // Enable X, Y, Z axes
    L3GD20_InitStruct.Full_Scale = L3GD20_FS_250;

    // Gọi hàm khởi tạo của L3GD20 để cấu hình cảm biến
    L3GD20_Init(&L3GD20_InitStruct);
}

// Đọc WHO_AM_I từ L3GD20
uint8_t GYROSCOPE_ReadID(void)
{
    return L3GD20_Read_WhoAmI();  // Sử dụng hàm từ L3GD20 để đọc WHO_AM_I
}

// Đọc trục X, Y, Z từ cảm biến
void GYROSCOPE_ReadXYZ(int16_t *X, int16_t *Y, int16_t *Z)
{
    L3GD20_Read_Axes(X, Y, Z);  // Sử dụng hàm từ L3GD20 để đọc trục X, Y, Z
}

// Hàm cấu hình trục (có thể tắt bật các trục)
void GYROSCOPE_Set_Axes(uint8_t X_Axis, uint8_t Y_Axis, uint8_t Z_Axis)
{
    L3GD20_Set_Axes(X_Axis, Y_Axis, Z_Axis);  // Cấu hình trục qua L3GD20
}

// Thiết lập phạm vi đo (Full Scale)
void GYROSCOPE_Set_FullScale(L3GD20_FullScale_t scale)
{
    L3GD20_Set_FullScale(scale);  // Sử dụng L3GD20 để thiết lập phạm vi đo
}

// Thiết lập Output Data Rate (ODR)
void GYROSCOPE_Set_OutputDataRate(L3GD20_OutputDataRate_t odr)
{
    L3GD20_Set_OutputDataRate(odr);  // Sử dụng L3GD20 để thiết lập ODR
}

// Cấu hình bộ lọc high-pass (filter)
void GYROSCOPE_Set_HighPassFilter(L3GD20_HighPassFilter_t mode, uint8_t cutoff)
{
    L3GD20_Set_HighPassFilter(mode, cutoff);  // Sử dụng L3GD20 để thiết lập bộ lọc high-pass
}

// Đọc nhiệt độ từ cảm biến
int16_t GYROSCOPE_ReadTemperature(void)
{
    return L3GD20_Read_Temperature();  // Đọc nhiệt độ từ L3GD20
}

// Cấu hình FIFO
void GYROSCOPE_Set_FIFO(L3GD20_FifoMode_t mode, uint8_t threshold)
{
    L3GD20_Set_FIFO(mode, threshold);  // Sử dụng L3GD20 để cấu hình FIFO
}

// Đọc trạng thái FIFO
uint8_t GYROSCOPE_ReadFIFOStatus(void)
{
    return L3GD20_Read_FIFOStatus();  // Đọc trạng thái FIFO từ L3GD20
}

// Cấu hình và xóa ngắt (interrupt)
void GYROSCOPE_EnableInterrupt(uint8_t interrupt, uint8_t enable)
{
    L3GD20_Enable_Interrupt(interrupt, enable);  // Cấu hình ngắt qua L3GD20
}

void GYROSCOPE_ClearInterrupt(uint8_t interrupt)
{
    L3GD20_Clear_Interrupt(interrupt);  // Xóa ngắt qua L3GD20
}

