#include "BatteryLowState.hpp"

#include "../Battery/Battery.hpp"
#include "../Logic/Logic.hpp"
#include "../Display/Display.hpp"

BatteryLowState_t::BatteryLowState_t()
    : battery_low_state{false}
{
}

bool BatteryLowState_t::update()
{
    bool new_battery_low_state = false;

    if (Battery.get_battery_voltage_value().is_valid() &&
        Battery.get_battery_voltage_value().get() <= BATTERY_SYSTEM_STANDBY_VOLTAGE)
    {
        new_battery_low_state = true;
    }

    if (new_battery_low_state != battery_low_state)
    {
        if (new_battery_low_state == true)
        {
            enter_battery_low_state();
        }
        else
        {
            leave_battery_low_state();
        }
        battery_low_state = new_battery_low_state;
    }

    return battery_low_state;
}

void BatteryLowState_t::enter_battery_low_state()
{
    Logic::enter_battery_low_powerstate();
}

void BatteryLowState_t::leave_battery_low_state()
{
    // Run logic update once to clear pending events
    Logic::update();

    Logic::leave_battery_low_powerstate();
}

BatteryLowState_t BatteryLowState{};
