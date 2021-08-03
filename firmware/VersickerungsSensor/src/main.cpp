
#include "Tof10120/Tof10120.hpp"
#include "Logic/Logic.hpp"
#include "Display/Display.hpp"
#include "RTC/RTC.hpp"
#include "Recording/Recording.hpp"
#include "Peripherals/Peripherals.hpp"
#include "Storage/Flash.hpp"
#include "Storage/UsbMsc.hpp"
#include "NeoPixel/NeoPixel.hpp"
#include "Battery/Battery.hpp"

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <cmath>

ValueWatcher<float> distance_value{&TOF10120.get_display_filtered_value()};

// TODO remove
#include "Display/Pages/Elements/BatteryIcon.hpp"
Pages::Elements::BatteryIcon page;

void setup()
{
    Wire.begin();

    Serial.begin(9600);
    /* Comment in following two lines to pause until Serial is attached */
    // while (!Serial)
    //     delay(100);
    Serial.println("\nVersickerungs Sensor");

    // Initialize NeoPixel
    NeoPixel.init();
    //NeoPixel.set_color(255, 255, 255);

    // Initialize display
    Display.init();

    // Initialize NeoPixel
    Battery.init();

    // Initialize clock
    RTC.init();

    // Initialize flash
    Flash.init();

    // Initialize USB MSC
    UsbMsc.init();

    // Initialize recording
    Recording.init();

    // Initialize logic
    //Logic::init();

    Display.set_page(&page);
}

void loop()
{
    // Update Battery
    Battery.update();

    // Update distance sensor
    TOF10120.update();

    // Update the clock
    RTC.update();

    // Update USB state
    UsbMsc.update();

    // Update logic and state machines
    //Logic::update();

    // Update display
    Display.update();
}
