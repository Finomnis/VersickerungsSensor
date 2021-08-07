#pragma once

#include "../../../../utils/ValueWatcher.hpp"

namespace Pages::Elements::Mixins
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
