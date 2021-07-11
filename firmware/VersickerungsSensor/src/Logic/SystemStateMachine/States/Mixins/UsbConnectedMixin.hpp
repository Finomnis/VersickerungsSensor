#pragma once

#include "../../../../utils/ValueWatcher.hpp"

namespace SystemStateMachine::States::Mixins
{
    class UsbConnectedMixin
    {
    protected:
        UsbConnectedMixin();
        ValueWatcher<bool> &usb_connected();

    private:
        ValueWatcher<bool> usb_connected_valuewatcher;
    };
}
