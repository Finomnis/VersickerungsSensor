#include "FormattingFilter.hpp"

#include <Arduino.h>

RTCFormattingFilter::RTCFormattingFilter()
    : filtered_value{FormattedTime{}, false}
{
    set_invalid();
}

void RTCFormattingFilter::update(DateTime time)
{
    FormattedTime value{};
    snprintf(value.str, sizeof(value.str), "%02d.%02d.%02d %02d:%02d",
             time.day(), time.month(), time.year() % 100, time.hour(), time.minute());

    if (!filtered_value.is_valid() || 0 != strncmp(value.str, filtered_value.get().str, sizeof(value.str)))
    {
        filtered_value.update(value);
    }
}

Value<FormattedTime> const &RTCFormattingFilter::get_formatted_time() const
{
    return filtered_value;
}

void RTCFormattingFilter::set_invalid()
{
    FormattedTime value{};
    snprintf(value.str, sizeof(value.str), "--.--.-- --:--");
    filtered_value.update(value);
}
