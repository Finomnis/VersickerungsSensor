arduino-cli compile --fqbn adafruit:nrf52:feather52840 VersickerungsSensor  || EXIT /B 1
arduino-cli upload -p COM5 --fqbn adafruit:nrf52:feather52840 VersickerungsSensor  || EXIT /B 1
