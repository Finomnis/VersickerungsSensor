#pragma once

#include "Adafruit_TinyUSB.h"

class UsbMsc_t
{
public:
    UsbMsc_t();

    void init();

    void enable();
    void disable();

    void update();

private:
    Adafruit_USBD_MSC usb_msc;
};

extern UsbMsc_t UsbMsc;
