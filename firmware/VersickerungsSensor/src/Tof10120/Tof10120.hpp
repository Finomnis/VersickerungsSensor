#pragma once

#include <Arduino.h>

#include "../utils/ValueWatcher.hpp"
#include "../utils/NoMoveNoCopy.hpp"

#include "AveragingFilter.hpp"

class TOF10120_t : NoMoveNoCopy
{
public:
    TOF10120_t(uint8_t i2c_addr);
    void update();

    const Value<uint16_t> &get_value() const;
    const Value<float> &get_display_filtered_value() const;

private:
    void read_sensor_value();

private:
    uint8_t i2c_addr;
    Value<uint16_t> value;
    AveragingFilter averaging_filter;
};

extern TOF10120_t TOF10120;
