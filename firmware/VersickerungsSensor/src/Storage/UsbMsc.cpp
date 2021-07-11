#include "UsbMsc.hpp"

#include "Flash.hpp"
#include "device/usbd.h"

namespace
{
    int32_t msc_read_cb(uint32_t lba, void *buffer, uint32_t bufsize)
    {
        return Flash.get_flash().readBlocks(lba, (uint8_t *)buffer, bufsize / 512) ? bufsize : -1;
    }

    int32_t msc_write_cb(uint32_t lba, uint8_t *buffer, uint32_t bufsize)
    {
        return Flash.get_flash().writeBlocks(lba, buffer, bufsize / 512) ? bufsize : -1;
    }

    void msc_flush_cb(void)
    {
        Flash.sync();
    }
}

UsbMsc_t::UsbMsc_t()
{
}

void UsbMsc_t::init()
{
    // Set disk vendor id, product id and revision with string up to 8, 16, 4 characters respectively
    usb_msc.setID("Finomnis", "Distance Logs", "1.0");

    // Set callback
    usb_msc.setReadWriteCallback(msc_read_cb, msc_write_cb, msc_flush_cb);

    // Set disk size, block size should be 512 regardless of spi flash page size
    usb_msc.setCapacity(Flash.get_flash().size() / 512, 512);

    // MSC is ready for read/write
    usb_msc.setUnitReady(true);

    usb_msc.begin();
}

void UsbMsc_t::update()
{
    Serial.println(tud_mounted());
}

void UsbMsc_t::enable()
{
    usb_msc.setUnitReady(true);
}

void UsbMsc_t::disable()
{
    usb_msc.setUnitReady(false);
}

UsbMsc_t UsbMsc{};
