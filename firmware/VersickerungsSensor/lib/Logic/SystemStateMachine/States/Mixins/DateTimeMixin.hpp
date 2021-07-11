#pragma once

#include <ValueWatcher.hpp>
#include <RTC.hpp>

namespace SystemStateMachine::States::Mixins
{
    class DateTimeMixin
    {
    protected:
        DateTimeMixin();
        ValueWatcher<DateTime> &datetime();

    private:
        ValueWatcher<DateTime> datetime_value;
    };

    class FormattedDateTimeMixin
    {
    protected:
        FormattedDateTimeMixin();
        ValueWatcher<FormattedTime> &formatted_datetime();

    private:
        ValueWatcher<FormattedTime> formatted_datetime_value;
    };
}
