#pragma once

#include <Adafruit_SPIFlash.h>
#include <SdFat.h>

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

    inline FatFileSystem &get_fatfs()
    {
        return fatfs;
    }

private:
    Adafruit_SPIFlash flash;
    FatFileSystem fatfs;
};

extern Flash_t Flash;
