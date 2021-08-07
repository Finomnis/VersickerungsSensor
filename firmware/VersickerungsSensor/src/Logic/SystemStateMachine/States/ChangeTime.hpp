#pragma once

#include "../SystemState.hpp"

#include "../../../Display/Pages/ChangeTimePage.hpp"

namespace SystemStateMachine::States
{
    class ChangeTime
        : public SystemState
    {
        static constexpr uint32_t IDLE_TIMEOUT_MS = 10000;

        void entry() override;

        void react(PressedButtonA const &e) override;
        void react(LongPressedButtonA const &e) override;
        void react(PressedButtonC const &e) override;

        void update_state() override;

    private:
        void reset_idle_timeout();
        uint32_t idle_timeout{0};

    private:
        Pages::ChangeTimePage page{};
    };
}
