#pragma once

#include <Arduino.h>
#include <ValueWatcher.hpp>
#include <NoMoveNoCopy.hpp>

#include "AveragingFilter.hpp"

class TOF10120_t
{
    NOMOVE_NOCOPY(TOF10120_t);

public:
    TOF10120_t(uint8_t i2c_addr);
    void update();

    const Value<uint16_t> &get_value() const;
    const Value<float> &get_display_filtered_value() const;

private:
    void update_request();
    void update_response();

private:
    uint8_t i2c_addr;
    Value<uint16_t> value;
    bool request_pending = false;
    uint32_t response_expected = 0;
    AveragingFilter averaging_filter;
};

extern TOF10120_t TOF10120;
