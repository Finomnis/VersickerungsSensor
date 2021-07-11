#include "Logic.hpp"

#include "SystemStateMachine/SystemState.hpp"
#include "Events.hpp"

#include <Peripherals.hpp>
#include <Button.hpp>

using SystemStateMachine::SystemState;

Button<BUTTONS::A> &ButtonA = Button<BUTTONS::A>::get();
Button<BUTTONS::B> &ButtonB = Button<BUTTONS::B>::get();
Button<BUTTONS::C> &ButtonC = Button<BUTTONS::C>::get();

// Events
PressedButtonA buttonEventA{};
PressedButtonB buttonEventB{};
PressedButtonC buttonEventC{};
LongPressedButtonA buttonEventLongA{};
LongPressedButtonB buttonEventLongB{};
LongPressedButtonC buttonEventLongC{};

void Logic::init()
{
    ButtonA.init();
    ButtonB.init();
    ButtonC.init();

    SystemState::start();
}

void Logic::update()
{
    SystemState::update();

    if (ButtonA.was_triggered())
    {
        SystemState::dispatch(buttonEventA);
    }

    if (ButtonB.was_triggered())
    {
        SystemState::dispatch(buttonEventB);
    }

    if (ButtonC.was_triggered())
    {
        SystemState::dispatch(buttonEventC);
    }

    if (ButtonA.was_longpressed())
    {
        SystemState::dispatch(buttonEventLongA);
    }

    if (ButtonB.was_longpressed())
    {
        SystemState::dispatch(buttonEventLongB);
    }

    if (ButtonC.was_longpressed())
    {
        SystemState::dispatch(buttonEventLongC);
    }
}
