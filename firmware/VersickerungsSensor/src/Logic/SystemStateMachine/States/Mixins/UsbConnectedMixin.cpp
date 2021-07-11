#include "UsbConnectedMixin.hpp"

#include "../../../../Storage/UsbMsc.hpp"

namespace SystemStateMachine::States::Mixins
{
    UsbConnectedMixin::UsbConnectedMixin()
        : usb_connected_valuewatcher{&UsbMsc.get_usb_connected_value()}
    {
    }

    ValueWatcher<bool> &UsbConnectedMixin::usb_connected()
    {
        return usb_connected_valuewatcher;
    }
}
