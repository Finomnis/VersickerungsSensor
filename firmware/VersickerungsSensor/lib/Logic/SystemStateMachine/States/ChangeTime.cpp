#include "ChangeTime.hpp"

#include <Arduino.h>
#include <Display_128x32.hpp>

#include "ChangeTimeStateMachine.hpp"
#include "Idle.hpp"

namespace SystemStateMachine::States
{
    using ChangeTimeStateMachine::ChangeTimeState;

    void ChangeTime::entry()
    {
        Serial.println("State: ChangeTime");

        ChangeTimeState::start();

        reset_blink_state();
        update_display();
    }

    void ChangeTime::react(PressedButtonA const &e)
    {
        ChangeTimeState::dispatch(ChangeTimeStateMachine::IncreaseValue{});
        reset_blink_state();
        update_display();
    };

    void ChangeTime::react(PressedButtonC const &e)
    {
        ChangeTimeState::dispatch(ChangeTimeStateMachine::NextField{});

        if (ChangeTimeState::is_in_state<ChangeTimeStateMachine::States::Finished>())
        {
            transit<Idle>();
        }
        else
        {
            reset_blink_state();
            update_display();
        }
    };

    void ChangeTime::update_state()
    {
        bool changed = false;

        changed |= blink_state().new_value_available();
        changed |= formatted_datetime().new_value_available();
        changed |= datetime().new_value_available();

        if (changed)
        {
            update_display();
        }
    }

    void ChangeTime::update_display()
    {
        if (datetime().is_valid())
        {
            Display_128x32.show_changetimepage(
                formatted_datetime().get().str,
                ChangeTimeState::highlight_start(),
                ChangeTimeState::highlight_end(),
                true, //TODO
                true, //TODO
                blink_state().get());
        }
        else
        {
            Display_128x32.show_changetimepage(
                "Clock Error",
                0,
                0,
                true, //TODO
                true, //TODO
                true);
        }
    }
};
