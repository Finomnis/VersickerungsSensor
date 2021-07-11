#pragma once

#include "../utils/NoMoveNoCopy.hpp"
#include "../utils/ValueWatcher.hpp"

#include "RTCFormattingFilter.hpp"

#include <RTClib.h>

class RTC_t : NoMoveNoCopy
{
public:
    void init();
    void update();

    void adjustMinute(int8_t delta = 1);
    void adjustHour(int8_t delta = 1);
    void adjustDay(int8_t delta = 1);
    void adjustMonth(int8_t delta = 1);
    void adjustYear(int8_t delta = 1);

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
