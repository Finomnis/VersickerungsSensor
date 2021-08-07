#include "Saved.hpp"

#include "../../../utils/TimeHelpers.hpp"
#include "../../../Display/Display.hpp"

#include "Idle.hpp"

namespace SystemStateMachine::States
{
    void Saved::entry()
    {
        Serial.println("State: Saved");
        exitTime = millis() + 2000;

        Display.set_page(&page);
    }

    void Saved::update_state()
    {
        if (event_is_over(exitTime))
        {
            transit<Idle>();
        }
    }

};
