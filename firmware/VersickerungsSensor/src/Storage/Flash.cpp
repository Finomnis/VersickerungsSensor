#include "Flash.hpp"

#include "../RTC/RTC.hpp"

namespace
{
    // Uncomment to run example with FRAM
    // #define FRAM_CS   A5
    // #define FRAM_SPI  SPI

#if defined(FRAM_CS) && defined(FRAM_SPI)
    Adafruit_FlashTransport_SPI flashTransport(FRAM_CS, FRAM_SPI);

#elif defined(ARDUINO_ARCH_ESP32)
    // ESP32 use same flash device that store code.
    // Therefore there is no need to specify the SPI and SS
    Adafruit_FlashTransport_ESP32 flashTransport;

#else
// On-board external flash (QSPI or SPI) macros should already
// defined in your board variant if supported
// - EXTERNAL_FLASH_USE_QSPI
// - EXTERNAL_FLASH_USE_CS/EXTERNAL_FLASH_USE_SPI
#if defined(EXTERNAL_FLASH_USE_QSPI)
    Adafruit_FlashTransport_QSPI flashTransport;

#elif defined(EXTERNAL_FLASH_USE_SPI)
    Adafruit_FlashTransport_SPI flashTransport(EXTERNAL_FLASH_USE_CS, EXTERNAL_FLASH_USE_SPI);

#else
#error No QSPI/SPI flash are defined on your board variant.h !
#endif
#endif
}

namespace
{
    void dateTime(uint16_t *date, uint16_t *time)
    {
        // User gets date and time from GPS or real-time clock here
        DateTime const &t = RTC.get_time_value().get();

        // return date using FAT_DATE macro to format fields
        *date = FAT_DATE(t.year(), t.month(), t.day());

        // return time using FAT_TIME macro to format fields
        *time = FAT_TIME(t.hour(), t.minute(), t.second());
    }
}

Flash_t::Flash_t()
    : flash{&flashTransport}
{
}

void Flash_t::init()
{
    flash.begin();
    // Init file system on the flash
    fatfs.begin(&flash);
    FatFile::dateTimeCallback(dateTime);
}

void Flash_t::sync()
{
    flash.syncBlocks();
    fatfs.cacheClear();
}

Flash_t Flash{};
