#pragma once

#include "../SystemState.hpp"

#include "../../../Display/Pages/BatteryLowPage.hpp"

namespace SystemStateMachine::States
{
    class BatteryLow
        : public SystemState
    {
        void entry() override;
        void exit() override;
        void react(LeaveBatteryLowPowerstate const &e) override;

    private:
        Pages::BatteryLowPage page{};
    };
}
