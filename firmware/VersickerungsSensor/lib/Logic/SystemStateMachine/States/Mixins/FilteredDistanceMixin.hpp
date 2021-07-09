#pragma once

#include <ValueWatcher.hpp>

namespace SystemStateMachine::States::Mixins
{
    class FilteredDistanceMixin
    {
    protected:
        FilteredDistanceMixin();
        ValueWatcher<float> &filtered_distance();

    private:
        ValueWatcher<float> filtered_distance_value;
    };
}
