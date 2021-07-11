
#include "Tof10120/Tof10120.hpp"
#include "Logic/Logic.hpp"
#include "Display/Display_128x32.hpp"
#include "RTC/RTC.hpp"
#include "Recording/Recording.hpp"
#include "Peripherals/Peripherals.hpp"

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <cmath>

ValueWatcher<float> distance_value{&TOF10120.get_display_filtered_value()};

void setup()
{
    Wire.begin();

    Serial.begin(9600);

    /* Comment in following two lines to pause until Serial is attached */
    // while (!Serial)
    //     delay(100);

    Serial.println("\nVersickerungs Sensor");

    // Initialize display
    Display_128x32.init();

    // Initialize clock
    RTC.init();

    // Initialize recording
    Recording.init();

    // Initialize logic
    Logic::init();
}

void loop()
{
    // Update distance sensor
    TOF10120.update();

    // Update the clock
    RTC.update();

    // Update logic and state machines
    Logic::update();
}
