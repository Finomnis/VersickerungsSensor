#pragma once

#include "../../../../utils/ValueWatcher.hpp"
#include "../../../../Battery/Battery.hpp"

namespace Pages::Elements::Mixins
{
    class BatteryStateMixin
    {
    protected:
        BatteryStateMixin();
        ValueWatcher<float> &battery_voltage();
        ValueWatcher<BatteryFillState> &battery_state();

    private:
        ValueWatcher<float> battery_voltage_value;
        ValueWatcher<BatteryFillState> battery_state_value;
    };
}
