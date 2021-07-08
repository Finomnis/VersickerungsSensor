#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Tof10120.hpp>
#include <Logic.hpp>

#include "peripherals.hpp"

void setup()
{
    Wire.begin();

    Serial.begin(9600);
    while (!Serial)
        delay(100);

    Serial.println("\nVersickerungs Sensor");

    // Initialize logic
    Logic::init();
}

void loop()
{
    // Update distance sensor
    TOF10120.update();

    // Update logic and state machines
    Logic::update();
}
