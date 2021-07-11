#include "ChangeTimeStateMachine.hpp"

#include "../../../RTC/RTC.hpp"

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
        RTC.adjustMinute();
    }

    void EditHour::react(IncreaseValue const &e)
    {
        RTC.adjustHour();
    }

    void EditYear::react(IncreaseValue const &e)
    {
        RTC.adjustYear();
    }

    void EditMonth::react(IncreaseValue const &e)
    {
        RTC.adjustMonth();
    }

    void EditDay::react(IncreaseValue const &e)
    {
        RTC.adjustDay();
    }
}

FSM_INITIAL_STATE(SystemStateMachine::States::ChangeTimeStateMachine::ChangeTimeState,
                  SystemStateMachine::States::ChangeTimeStateMachine::States::EditMinute);
