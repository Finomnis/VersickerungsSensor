#include <Arduino.h>
#include <Wire.h>

#include <Tof10120.hpp>
#include <Button.hpp>

#include "peripherals.hpp"

TOF10120 sensor(I2C_DEVICES::SENSOR_TOF10120);
ValueWatcher<uint16_t> distance_value{&sensor.get_value()};

Button<BUTTONS::A> &ButtonA = Button<BUTTONS::A>::get();
Button<BUTTONS::B> &ButtonB = Button<BUTTONS::B>::get();
Button<BUTTONS::C> &ButtonC = Button<BUTTONS::C>::get();

void setup()
{
    Wire.begin();

    Serial.begin(9600);
    while (!Serial)
        delay(100);

    Serial.println("\nVersickerungs Sensor");

    // Initialize Buttons
    ButtonA.init();
    ButtonB.init();
    ButtonC.init();
}

void loop()
{
    sensor.update();

    // if (distance_value.new_value_available())
    // {
    //     Serial.print("Distance: ");
    //     if (distance_value.is_valid())
    //     {
    //         Serial.print(distance_value.get_value());
    //     }
    //     else
    //     {
    //         Serial.print("---");
    //     }
    //     Serial.println(" mm");
    // }

    if (ButtonA.was_triggered())
    {
        Serial.println("A triggered!");
    }
    if (ButtonB.was_triggered())
    {
        Serial.println("B triggered!");
    }
    if (ButtonC.was_triggered())
    {
        Serial.println("C triggered!");
    }
}
