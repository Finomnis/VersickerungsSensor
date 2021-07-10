#pragma once

#include <RTClib.h>
#include <NoMoveNoCopy.hpp>
#include <ValueWatcher.hpp>
#include "FormattingFilter.hpp"

class RTC_t : NoMoveNoCopy
{
public:
    void init();
    void update();

    inline Value<DateTime> const &get_time_value() const
    {
        return time;
    }

    inline Value<FormattedTime> const &get_formatted_time_value() const
    {
        return formatting_filter.get_formatted_time();
    }

private:
    RTC_DS3231 rtc{};
    bool rtc_connected{false};

    Value<DateTime> time{DateTime(0, 1, 1, 0, 0, 0), false};
    RTCFormattingFilter formatting_filter{};
};

extern RTC_t RTC;
