#pragma once

#include "../SystemState.hpp"

#include "../../../Display/Pages/MainPage.hpp"

namespace SystemStateMachine::States
{
    class Idle
        : public SystemState
    {
        void entry() override;
        void react(PressedButtonA const &e) override;
        void react(PressedButtonC const &e) override;

    private:
        Pages::MainPage page{false};
    };
}
