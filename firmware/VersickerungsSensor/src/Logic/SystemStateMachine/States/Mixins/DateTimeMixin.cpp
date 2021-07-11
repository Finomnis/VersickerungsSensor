#include "DateTimeMixin.hpp"

#include "../../../../Tof10120/Tof10120.hpp"

namespace SystemStateMachine::States::Mixins
{
    FormattedDateTimeMixin::FormattedDateTimeMixin()
        : formatted_datetime_value{&RTC.get_formatted_time_value()}
    {
    }

    ValueWatcher<FormattedTime> &FormattedDateTimeMixin::formatted_datetime()
    {
        return formatted_datetime_value;
    }

    DateTimeMixin::DateTimeMixin()
        : datetime_value{&RTC.get_time_value()}
    {
    }

    ValueWatcher<DateTime> &DateTimeMixin::datetime()
    {
        return datetime_value;
    }
}
