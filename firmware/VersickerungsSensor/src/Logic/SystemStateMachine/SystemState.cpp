#include "SystemState.hpp"

#include "States/Idle.hpp"

namespace SystemStateMachine
{
    void SystemState::update()
    {
        current_state_ptr->update_state();
    }
}

FSM_INITIAL_STATE(SystemStateMachine::SystemState,
                  SystemStateMachine::States::Idle);
