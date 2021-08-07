#pragma once

#include "../../../../utils/ValueWatcher.hpp"
#include "../../../../RTC/RTC.hpp"

namespace Pages::Elements::Mixins
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
