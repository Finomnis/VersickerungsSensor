#pragma once

#include "../SystemState.hpp"

#include "../../../Display/Pages/SavedPage.hpp"

namespace SystemStateMachine::States
{
    class Saved
        : public SystemState
    {
        void entry() override;
        void update_state() override;

    private:
        uint32_t exitTime;
        Pages::SavedPage page{};
    };
}
