#include "L3GD20.h"
#include "main.h"

extern hspi1;
/* Đọc dữ liệu từ các thanh ghi */
int L3GD20_IO_Read(uint8_t reg, uint8_t *data, uint8_t size)
{
    uint8_t txBuffer[1] = {reg};  // Địa chỉ thanh ghi cần đọc
    SPI_HandleTypeDef *hspi = &hspi1;  // Sử dụng SPI đã được cấu hình

    // Truyền dữ liệu để chọn thanh ghi
    HAL_SPI_Transmit(hspi, txBuffer, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(hspi, data, size, HAL_MAX_DELAY);

    return 0;  // Thành công
}

/* Ghi dữ liệu vào các thanh ghi */
int L3GD20_IO_Write(uint8_t reg, uint8_t value)
{
    uint8_t txBuffer[2] = {reg, value};  // Địa chỉ thanh ghi và giá trị cần ghi
    SPI_HandleTypeDef *hspi = &hspi1;  // Sử dụng SPI đã được cấu hình

    // Ghi dữ liệu vào thanh ghi
    HAL_SPI_Transmit(hspi, txBuffer, 2, HAL_MAX_DELAY);

    return 0;  // Thành công
}

/* Đọc WHO_AM_I từ L3GD20 */
uint8_t L3GD20_Read_WhoAmI(void)
{
    uint8_t whoAmI = 0;
    L3GD20_IO_Read(L3GD20_WHO_AM_I, &whoAmI, 1);  // Đọc WHO_AM_I từ cảm biến
    return whoAmI;  // Trả về ID thiết bị
}

/* Đọc trục X, Y, Z từ cảm biến */
void L3GD20_Read_Axes(int16_t *X, int16_t *Y, int16_t *Z)
{
    uint8_t data[6];  // Lưu trữ dữ liệu đọc từ cảm biến

    // Đọc 6 byte dữ liệu từ OUT_X_L, OUT_X_H, OUT_Y_L, OUT_Y_H, OUT_Z_L, OUT_Z_H
    L3GD20_IO_Read(L3GD20_OUT_X_L, data, 6);

    // Chuyển đổi dữ liệu từ các byte thành giá trị 16-bit
    *X = (int16_t)((data[1] << 8) | data[0]);
    *Y = (int16_t)((data[3] << 8) | data[2]);
    *Z = (int16_t)((data[5] << 8) | data[4]);
}

/* Khởi tạo L3GD20 */
void L3GD20_Init(L3GD20_InitTypeDef *L3GD20_InitStruct)
{
    uint8_t data = 0;

    // Cấu hình Power Mode
    data = L3GD20_InitStruct->Power_Mode;
    L3GD20_IO_Write(L3GD20_CTRL_REG1, data);

    // Cấu hình Output Data Rate (ODR)
    data = L3GD20_InitStruct->Output_DataRate;
    L3GD20_IO_Write(L3GD20_CTRL_REG1, data);

    // Cấu hình trục
    data = L3GD20_InitStruct->Axes_Enable;
    L3GD20_IO_Write(L3GD20_CTRL_REG1, data);

    // Cấu hình Full Scale
    data = L3GD20_InitStruct->Full_Scale;
    L3GD20_IO_Write(L3GD20_CTRL_REG4, data);
}

