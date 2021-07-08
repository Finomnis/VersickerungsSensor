#pragma once

#include "tinyfsm.hpp"
#include "Events.hpp"

namespace SystemStateMachine
{
    class SystemState : public tinyfsm::Fsm<SystemState>
    {
        // tinyfsm needs access to react, entry and exit function
        friend class Fsm;

    public:
        /* update function for timed events */
        static void update();

    private:
        /* default reaction for unhandled events */
        void react(tinyfsm::Event const &){};

        /* react overloads */
        virtual void react(PressedButtonA const &){};
        virtual void react(PressedButtonB const &){};
        virtual void react(PressedButtonC const &){};

        /* update */
        virtual void update_state(){};

        virtual void entry(void) = 0; /* pure virtual: enforce implementation in all states */
        virtual void exit(void){};    /* can be implemented by states */
    };
}
