# VersickerungsSensor

DIY Messgerät zur Durchführung von Versickerungs Messung nach DIN 19682-7

## Hintergrund

Um die Versickerungsfähigkeit eines Bodens zu messen, werden
[Versickerungsversuche] durchgeführt.
Dabei muss über einen längeren Zeitraum der Wasserstand in einem Rohr (Doppelring-Infiltrometer) gemessen werden.

Dieses Projekt hat das Ziel diese Aufgabe zu vereinfachen und zu
automatisieren.
Dabei bedient es sich der Technik von TOF Laser Entfernungsmessung um
kontinuierlich den Wasserstand zu messen.

## Hardware

Die Hardware auf die das Projekt ausgerichtet ist besteht aus folgenden
Teilen:

-   Microcontroller [nRF52840]
-   Laser Entfernungssensor [TOF10120]
-   Präzisions Uhr [DS3231]
-   128x32 I2C Display mit [SSD1306] Treiber Chip

[versickerungsversuche]: https://www.sieker.de/fachinformationen/regenwasserbewirtschaftung/versickerung/article/versickerungsversuche-162.html
[nrf52840]: https://www.nordicsemi.com/Products/nRF52840
[tof10120]: https://www.electroniclinic.com/tof10120-laser-rangefinder-arduino-display-interfacing-code/
[ds3231]: https://www.maximintegrated.com/en/products/analog/real-time-clocks/DS3231.html
[ssd1306]: https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf
