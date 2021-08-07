#include "ChangeTime.hpp"

#include "../../../Display/Display.hpp"
#include "../../../utils/TimeHelpers.hpp"

#include "ChangeTimeStateMachine.hpp"
#include "Idle.hpp"

namespace SystemStateMachine::States
{
    using ChangeTimeStateMachine::ChangeTimeState;

    void ChangeTime::entry()
    {
        Serial.println("State: ChangeTime");

        ChangeTimeState::start();

        page.set_highlight(
            ChangeTimeState::highlight_start(),
            ChangeTimeState::highlight_end());
        Display.set_page(&page);

        reset_idle_timeout();
    }

    void ChangeTime::reset_idle_timeout()
    {
        idle_timeout = millis() + IDLE_TIMEOUT_MS;
    }

    void ChangeTime::react(LongPressedButtonA const &e)
    {
        ChangeTimeState::dispatch(ChangeTimeStateMachine::IncreaseValue{});
        page.reset_blink_state();
        reset_idle_timeout();
    }

    void ChangeTime::react(PressedButtonA const &e)
    {
        ChangeTimeState::dispatch(ChangeTimeStateMachine::IncreaseValue{});
        page.reset_blink_state();
        reset_idle_timeout();
    }

    void ChangeTime::react(PressedButtonC const &e)
    {
        ChangeTimeState::dispatch(ChangeTimeStateMachine::NextField{});

        if (ChangeTimeState::is_in_state<ChangeTimeStateMachine::States::Finished>())
        {
            transit<Idle>();
            return;
        }

        page.set_highlight(
            ChangeTimeState::highlight_start(),
            ChangeTimeState::highlight_end());

        reset_idle_timeout();
    }

    void ChangeTime::update_state()
    {
        if (event_is_over(idle_timeout))
        {
            transit<Idle>();
        }
    }
};
