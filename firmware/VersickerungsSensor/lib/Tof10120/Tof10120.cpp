#include "Tof10120.hpp"

#include <Wire.h>
#include <Peripherals.hpp>

constexpr unsigned long SENSOR_MEASUREMENT_DELAY_MS = 30;

TOF10120_t::TOF10120_t(uint8_t i2c_addr)
    : i2c_addr{i2c_addr}, value{0, false}
{
}

const Value<uint16_t> &TOF10120_t::get_value() const
{
    return value;
}

void TOF10120_t::update_request()
{
    if (!requestPending)
    {
        // Request sensor to measure distance
        Wire.beginTransmission(i2c_addr);
        Wire.write(byte(0));
        uint8_t error = Wire.endTransmission();
        if (error != 0)
        {
            // publish error state to value callback
            value.update(0, false);
            return;
        }

        requestPending = true;
        responseExpected = millis() + SENSOR_MEASUREMENT_DELAY_MS;
    }
}

void TOF10120_t::update_response()
{
    if (requestPending && (int32_t(millis() - responseExpected) >= 0))
    {
        requestPending = false;

        // Read response
        Wire.requestFrom(i2c_addr, 2);
        if (Wire.available() != 2)
        {
            // publish error state to value callback
            value.update(0, false);
            return;
        }

        uint8_t hi = Wire.read();
        uint8_t lo = Wire.read();
        uint16_t distance = hi;
        distance = distance << 8;
        distance |= lo;

        // publish sensor value to callback
        value.update(distance);
    }
}

void TOF10120_t::update()
{
    update_response();
    update_request();
}

TOF10120_t TOF10120(I2C_DEVICES::SENSOR_TOF10120);
