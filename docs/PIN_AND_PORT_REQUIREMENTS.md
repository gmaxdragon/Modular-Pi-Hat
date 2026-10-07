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
- **8 downstream external USB 2.0 ports**
- **4 × USB-A**
- **4 × USB-C**
- **1 upstream hub connection to Raspberry Pi**
- powered-hub architecture

The hub section should not depend entirely on the Raspberry Pi's USB power budget.

USB design requirements to learn and verify:
- dedicated 7-port hub controller
- 24 MHz/reference-clock requirements if required by the chosen controller
- upstream and downstream USB 2.0 D+/D- differential pairs
- ESD protection at external connectors
- USB-A VBUS switching/current limiting
- USB-C CC1/CC2 source configuration for downstream-facing USB-C ports
- no accidental VBUS back-power path into the Raspberry Pi
- adequate 5 V current budget for all seven ports
- connector shell grounding strategy

Do not pick the final hub IC or power switches until the datasheets are read.

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


## Grade 4 choices locked

- Servo connectors: standard 3-pin servo headers, individually labeled.
- GPIO: four groups of four signal pins, every GPIO individually labeled.
- Power input: screw terminal.
- USB physical target: four USB-A plus four USB-C external ports.
