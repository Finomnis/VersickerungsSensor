#pragma once

#include "../SystemState.hpp"

#include "../../../Display/Pages/MainPage.hpp"

namespace SystemStateMachine::States
{
    class Recording
        : public SystemState
    {
        void entry() override;
        void exit() override;

        void react(PressedButtonA const &e) override;

        void update_state() override;

    private:
        Pages::MainPage page{true};
    };
}
