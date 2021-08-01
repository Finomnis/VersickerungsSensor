#include "Saved.hpp"

#include <Arduino.h>
#include "../../../utils/TimeHelpers.hpp"
#include "../../../Display/Display_128x32.hpp"

#include "Idle.hpp"

namespace SystemStateMachine::States
{
    void Saved::entry()
    {
        Serial.println("State: Saved");
        exitTime = millis() + 2000;

        update_display();
    }

    void Saved::update_state()
    {
        bool changed = false;

        changed |= formatted_datetime().new_value_available();
        changed |= blink_state().new_value_available();
        changed |= usb_connected().new_value_available();
        changed |= battery_state().new_value_available();

        if (changed)
        {
            update_display();
        }

        if (event_is_over(exitTime))
        {
            transit<Idle>();
        }
    }

    void Saved::update_display()
    {
        Display_128x32.show_mainpage_text(
            formatted_datetime().get().str,
            "Gespeichert",
            false,
            false, //TODO
            usb_connected().get(),
            blink_state().get(),
            battery_state().get(),
            false);
    }
};
