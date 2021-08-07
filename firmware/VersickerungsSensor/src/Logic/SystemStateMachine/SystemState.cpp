#include "SystemState.hpp"

#include "States/Idle.hpp"
#include "States/BatteryLow.hpp"

namespace SystemStateMachine
{
    void SystemState::update()
    {
        current_state_ptr->update_state();
    }

    void SystemState::react(EnterBatteryLowPowerstate const &)
    {
        transit<SystemStateMachine::States::BatteryLow>();
    }
}

FSM_INITIAL_STATE(SystemStateMachine::SystemState,
                  SystemStateMachine::States::Idle);
