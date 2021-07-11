#include "Flash.hpp"

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

Flash_t::Flash_t()
    : flash{&flashTransport}
{
}

void Flash_t::init()
{
    flash.begin();
}

void Flash_t::sync()
{
    flash.syncBlocks();
}

Flash_t Flash{};
