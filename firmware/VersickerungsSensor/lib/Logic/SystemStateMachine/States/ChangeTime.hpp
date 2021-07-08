#pragma once

#include "../SystemState.hpp"

namespace SystemStateMachine::States
{
    class ChangeTime
        : public SystemState
    {
        void entry() override;
        void react(PressedButtonA const &e) override;
        void react(PressedButtonC const &e) override;
    };
}
