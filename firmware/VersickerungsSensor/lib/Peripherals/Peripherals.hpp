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
    // OLED FeatherWing buttons map to different pins depending on board:
#if defined(ESP8266)
    constexpr uint32_t A = 0;
    constexpr uint32_t B = 16;
    constexpr uint32_t C = 2;
#elif defined(ESP32)
    constexpr uint32_t A = 15;
    constexpr uint32_t B = 32;
    constexpr uint32_t C = 14;
#elif defined(ARDUINO_STM32_FEATHER)
    constexpr uint32_t A = PA15;
    constexpr uint32_t B = PC7;
    constexpr uint32_t C = PC5;
#elif defined(TEENSYDUINO)
    constexpr uint32_t A = 4;
    constexpr uint32_t B = 3;
    constexpr uint32_t C = 8;
#elif defined(ARDUINO_FEATHER52832)
    constexpr uint32_t A = 31;
    constexpr uint32_t B = 30;
    constexpr uint32_t C = 27;
#else // 32u4, M0, M4, nrf52840 and 328p
    constexpr uint32_t A = 9;
    constexpr uint32_t B = 6;
    constexpr uint32_t C = 5;
#endif
}
