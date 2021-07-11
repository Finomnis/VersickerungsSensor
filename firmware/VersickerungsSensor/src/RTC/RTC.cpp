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

static constexpr uint8_t daysInMonth[] = {31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 21};

static uint8_t adjust(uint8_t original, int8_t delta, uint8_t modulo)
{
    int8_t adjusted = int8_t(original) + delta;
    while (adjusted < 0)
    {
        adjusted += int8_t(modulo);
    }
    adjusted %= modulo;
    return adjusted;
}

void RTC_t::adjustMinute(int8_t delta)
{
    DateTime now = rtc.now();
    // Reset second when adjusting minute
    DateTime adjusted{now.year(), now.month(), now.day(), now.hour(), adjust(now.minute(), delta, 60), 0};
    rtc.adjust(adjusted);
}

void RTC_t::adjustHour(int8_t delta)
{
    DateTime now = rtc.now();
    DateTime adjusted{now.year(), now.month(), now.day(), adjust(now.hour(), delta, 24), now.minute(), now.second()};
    rtc.adjust(adjusted);
}

void RTC_t::adjustDay(int8_t delta)
{
    DateTime now = rtc.now();

    uint16_t year = now.year();
    bool leap_year = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);

    uint8_t num_days = daysInMonth[(now.month() - 1) % 12];
    if (now.month() == 2 && leap_year)
    {
        num_days += 1;
    }

    uint8_t day = adjust(now.day() - uint8_t(1), delta, num_days) + 1;
    DateTime adjusted{now.year(), now.month(), day, now.hour(), now.minute(), now.second()};
    rtc.adjust(adjusted);
}

void RTC_t::adjustMonth(int8_t delta)
{
    DateTime now = rtc.now();
    uint8_t month = adjust(now.month() - uint8_t(1), delta, 12) + 1;
    DateTime adjusted{now.year(), month, now.day(), now.hour(), now.minute(), now.second()};
    rtc.adjust(adjusted);
}

void RTC_t::adjustYear(int8_t delta)
{
    DateTime now = rtc.now();
    uint16_t year = adjust(now.year() % 100, delta, 100) + 2000;
    DateTime adjusted{year, now.month(), now.day(), now.hour(), now.minute(), now.second()};
    rtc.adjust(adjusted);
}

RTC_t RTC{};
