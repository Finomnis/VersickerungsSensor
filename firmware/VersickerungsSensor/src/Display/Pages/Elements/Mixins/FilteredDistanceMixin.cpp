#include "FilteredDistanceMixin.hpp"

#include "../../../../Tof10120/Tof10120.hpp"

namespace Pages::Elements::Mixins
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
