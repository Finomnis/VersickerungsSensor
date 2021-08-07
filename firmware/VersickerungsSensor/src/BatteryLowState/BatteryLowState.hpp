#pragma once

#include "../utils/ValueWatcher.hpp"
#include "../utils/NoMoveNoCopy.hpp"

class BatteryLowState_t : NoMoveNoCopy
{
public:
    static constexpr float BATTERY_SYSTEM_STANDBY_VOLTAGE = 3.5f;

public:
    BatteryLowState_t();

    bool update();

private:
    void enter_battery_low_state();
    void leave_battery_low_state();

private:
    bool battery_low_state;
};

extern BatteryLowState_t BatteryLowState;
