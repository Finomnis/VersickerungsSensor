#include "ChangeTimeStateMachine.hpp"

namespace SystemStateMachine::States::ChangeTimeStateMachine
{
    int32_t ChangeTimeState::highlight_start()
    {
        return current_state_ptr->get_highlight_start();
    }
    int32_t ChangeTimeState::highlight_end()
    {
        return current_state_ptr->get_highlight_end();
    }
}

namespace SystemStateMachine::States::ChangeTimeStateMachine::States
{
    void EditMinute::react(IncreaseValue const &e)
    {
        Serial.println("Add minute!");
    }

    void EditHour::react(IncreaseValue const &e)
    {
        Serial.println("Add hour!");
    }

    void EditYear::react(IncreaseValue const &e)
    {
        Serial.println("Add year!");
    }

    void EditMonth::react(IncreaseValue const &e)
    {
        Serial.println("Add month!");
    }

    void EditDay::react(IncreaseValue const &e)
    {
        Serial.println("Add day!");
    }
}

FSM_INITIAL_STATE(SystemStateMachine::States::ChangeTimeStateMachine::ChangeTimeState,
                  SystemStateMachine::States::ChangeTimeStateMachine::States::EditMinute);
