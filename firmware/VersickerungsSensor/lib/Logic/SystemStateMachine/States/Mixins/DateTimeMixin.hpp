#pragma once

#include <ValueWatcher.hpp>
#include <RTC.hpp>

namespace SystemStateMachine::States::Mixins
{
    class DateTimeMixin
    {
    protected:
        DateTimeMixin();
        ValueWatcher<FormattedTime> &formatted_time();

    private:
        ValueWatcher<FormattedTime> formatted_time_value;
    };
}
