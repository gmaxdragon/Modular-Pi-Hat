# Ultimate PI HAT — pin and port requirements

AI-assisted planning document.

## Fixed requirements

### Servo outputs
Exactly **6 servo signal channels**.

Each channel should expose:
- signal
- servo power
- ground

The servo power rail must not come from the ESP32 3.3 V rail.

## General GPIO

Exactly **16 user-accessible GPIO signals**.

Do not assign final ESP32-S3 pin numbers until:
- module choice is finalized
- USB pins are reserved
- boot/strapping pins are checked
- flash/PSRAM-reserved pins are checked
- UART/I2C assignments are chosen

The header should also expose power and ground separately from the 16 signal count.

## USB

Target:
- 4 downstream external USB ports
- 2 × USB-A
- 2 × USB-C
- 1 upstream connection to Raspberry Pi

USB 2.0 high-speed is enough for the first board.

A powered hub architecture is preferred so high-current peripherals do not depend entirely on the Pi's USB power budget.

## Raspberry Pi interface

Target:
- 40-pin HAT-style header
- UART between Pi and ESP32
- HAT ID EEPROM if the finished board is made HAT/HAT+ compliant

## Power

Target:
- external wall-power connector
- onboard buck conversion
- separate servo branch
- separate USB/logic branch
- fuse/current protection
- bulk capacitance near servo connectors
- no USB back-powering into Raspberry Pi

## Debug

Include:
- ESP32 BOOT
- ESP32 RESET
- power LED
- status LED
- clearly labeled test points
