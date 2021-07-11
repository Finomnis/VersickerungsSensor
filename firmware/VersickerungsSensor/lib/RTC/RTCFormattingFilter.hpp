#pragma once

#include <ValueWatcher.hpp>
#include <Arduino.h>
#include <RTClib.h>

struct FormattedTime
{
    char str[19] = {0};
};

class RTCFormattingFilter
{
public:
    RTCFormattingFilter();

    void update(DateTime time);
    void set_invalid();

    Value<FormattedTime> const &get_formatted_time() const;

private:
    Value<FormattedTime> filtered_value;
};
