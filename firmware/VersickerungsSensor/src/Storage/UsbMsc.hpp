#pragma once

#include "Adafruit_TinyUSB.h"
#include "../utils/ValueWatcher.hpp"

class UsbMsc_t
{
public:
    UsbMsc_t();

    void init();

    void enable();
    void disable();

    void update();

    inline Value<bool> const &get_usb_connected_value()
    {
        return usb_connected_value;
    }

private:
    Adafruit_USBD_MSC usb_msc;
    Value<bool> usb_connected_value;
};

extern UsbMsc_t UsbMsc;
