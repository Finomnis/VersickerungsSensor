#pragma once

#include <Adafruit_SPIFlash.h>

class Flash_t
{
public:
    Flash_t();

    void init();

    void sync();

    inline Adafruit_SPIFlash &get_flash()
    {
        return flash;
    }

private:
    Adafruit_SPIFlash flash;
};

extern Flash_t Flash;
