#include "Recording.hpp"

#include <Arduino.h>

#include "../../../Display/Display.hpp"
#include "../../../Storage/UsbMsc.hpp"
#include "../../../Recording/Recording.hpp"

#include "Saved.hpp"

namespace SystemStateMachine::States
{
    void Recording::entry()
    {
        Serial.println("State: Recording");

        // Disable USB storage while recording.
        // Computers can't deal with data changing while they
        // are accessing it.
        UsbMsc.disable();

        Display.set_page(&page);

        ::Recording.start();
    }

    void Recording::exit()
    {
        ::Recording.finish();

        UsbMsc.enable();
    }

    void Recording::react(PressedButtonA const &e)
    {
        transit<Saved>();
    };

    void Recording::update_state()
    {
        ::Recording.update();
    }

}
