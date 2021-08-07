#include "BatteryLow.hpp"

#include "../../../Display/Display.hpp"

#include "Idle.hpp"

namespace SystemStateMachine::States
{
    void BatteryLow::entry()
    {
        Serial.println("State: BatteryLow");

        Display.dim(true);
        Display.set_page(&page);
    }

    void BatteryLow::exit()
    {
        Display.dim(false);
    }

    void BatteryLow::react(LeaveBatteryLowPowerstate const &e)
    {
        transit<Idle>();
    }
};
