#pragma once

#include "../SystemState.hpp"

namespace SystemStateMachine::States
{
    class Recording
        : public SystemState
    {
        void entry() override;
        void react(PressedButtonA const &e) override;
    };
}
