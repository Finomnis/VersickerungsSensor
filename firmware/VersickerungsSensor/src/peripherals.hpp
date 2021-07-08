#pragma once

#include <Arduino.h>

namespace I2C_DEVICES
{
    constexpr uint8_t SENSOR_TOF10120 = 0x52;
    constexpr uint8_t DISPLAY_SSD1306 = 0x3C;
    constexpr uint8_t CLOCK_DS3231 = 0x68;
}

namespace BUTTONS
{
    constexpr uint32_t A = 9;
    constexpr uint32_t B = 6;
    constexpr uint32_t C = 5;
}
