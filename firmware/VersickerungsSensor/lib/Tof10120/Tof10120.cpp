#include "Tof10120.hpp"

#include <Wire.h>
#include <Peripherals.hpp>
#include <TimeHelpers.hpp>

constexpr uint32_t SENSOR_MEASUREMENT_DELAY_MS = 30;
constexpr uint32_t AVERAGING_FILTER_SIZE = 33;

TOF10120_t::TOF10120_t(uint8_t i2c_addr)
    : i2c_addr{i2c_addr}, value{0, false},
      averaging_filter{AVERAGING_FILTER_SIZE}
{
}

const Value<uint16_t> &TOF10120_t::get_value() const
{
    return value;
}

const Value<float> &TOF10120_t::get_display_filtered_value() const
{
    return averaging_filter.get_filtered_value();
}

void TOF10120_t::update_request()
{
    if (!request_pending)
    {
        // Request sensor to measure distance
        Wire.beginTransmission(i2c_addr);
        Wire.write(byte(0));
        uint8_t error = Wire.endTransmission();
        if (error != 0)
        {
            // publish error state to value callback
            value.update(0, false);
            averaging_filter.set_invalid();
            return;
        }

        request_pending = true;
        response_expected = millis() + SENSOR_MEASUREMENT_DELAY_MS;
    }
}

void TOF10120_t::update_response()
{
    if (request_pending && event_is_over(response_expected))
    {
        request_pending = false;

        // Read response
        Wire.requestFrom(i2c_addr, 2);
        if (Wire.available() != 2)
        {
            // publish error state to value callback
            value.update(0, false);
            averaging_filter.set_invalid();
            return;
        }

        uint8_t hi = Wire.read();
        uint8_t lo = Wire.read();
        uint16_t distance = hi;
        distance = distance << 8;
        distance |= lo;

        // publish sensor value to callback
        value.update(distance);
        averaging_filter.add_sample(distance);
    }
}

void TOF10120_t::update()
{
    update_response();
    update_request();
}

TOF10120_t TOF10120(I2C_DEVICES::SENSOR_TOF10120);
