#include "FilteredDistanceMixin.hpp"

#include "../../../../Tof10120/Tof10120.hpp"

namespace SystemStateMachine::States::Mixins
{
    FilteredDistanceMixin::FilteredDistanceMixin()
        : filtered_distance_value{&TOF10120.get_display_filtered_value()}
    {
    }

    ValueWatcher<float> &FilteredDistanceMixin::filtered_distance()
    {
        return filtered_distance_value;
    }
}
