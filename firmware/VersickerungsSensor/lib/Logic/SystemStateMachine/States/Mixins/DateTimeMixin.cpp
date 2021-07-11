#include "DateTimeMixin.hpp"

#include <Tof10120.hpp>

namespace SystemStateMachine::States::Mixins
{
    DateTimeMixin::DateTimeMixin()
        : formatted_time_value{&RTC.get_formatted_time_value()}
    {
    }

    ValueWatcher<FormattedTime> &DateTimeMixin::formatted_time()
    {
        return formatted_time_value;
    }
}
