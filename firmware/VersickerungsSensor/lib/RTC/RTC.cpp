#include "RTC.hpp"

void RTC_t::init()
{
    rtc_connected = rtc.begin();
    if (!rtc_connected)
    {
        Serial.println("Warning: Unable to communicate with RTC!");
    }

    update();
}

void RTC_t::update()
{
    if (rtc_connected)
    {
        DateTime now = rtc.now();
        if (!time.is_valid() || now.unixtime() != time.get().unixtime())
        {
            time.update(now);
            formatting_filter.update(now);
        }
    }
}

RTC_t RTC{};
