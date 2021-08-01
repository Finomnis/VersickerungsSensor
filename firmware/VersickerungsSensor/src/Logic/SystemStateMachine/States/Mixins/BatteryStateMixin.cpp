#include "BatteryStateMixin.hpp"

namespace SystemStateMachine::States::Mixins
{
    BatteryStateMixin::BatteryStateMixin()
        : battery_voltage_value{&Battery.get_battery_voltage_value()},
          battery_state_value{&Battery.get_battery_state_value()}
    {
    }

    ValueWatcher<float> &BatteryStateMixin::battery_voltage()
    {
        return battery_voltage_value;
    }

    ValueWatcher<BatteryFillState> &BatteryStateMixin::battery_state()
    {
        return battery_state_value;
    }
}
