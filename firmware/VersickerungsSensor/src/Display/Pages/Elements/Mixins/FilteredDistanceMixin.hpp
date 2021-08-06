#pragma once

#include "../../../../utils/ValueWatcher.hpp"

namespace Pages::Elements::Mixins
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
