#pragma once

#include "../utils/ValueWatcher.hpp"

#include <Arduino.h>

class AveragingFilter
{
public:
    AveragingFilter(uint32_t filter_size);
    void add_sample(uint16_t value);
    void set_invalid();
    Value<float> const &get_filtered_value() const;

private:
    const uint32_t filter_size;
    uint32_t num_values;
    uint32_t sum;

    Value<float> filtered_value;
};
