# Ultimate PI HAT — architecture target

This is an AI-assisted planning document, not a finished hardware design.

## Goal

Make a Raspberry Pi robotics expansion board that combines:

- ESP32-S3 real-time controller
- 6 servo signal outputs
- 16 general-purpose expansion GPIOs
- multiple USB-A and USB-C ports
- external wall power input
- onboard voltage conversion
- Raspberry Pi connection
- sensor expansion
- protection and debug features

## Recommended system split

### Raspberry Pi
High-level computer:
- AI
- cameras
- web UI
- planning
- logging

### ESP32-S3
Real-time hardware controller:
- 6 servo PWM signals
- 16 expansion GPIOs
- sensor polling
- safety/status logic
- communication with Raspberry Pi

## Raspberry Pi connection

Preferred target for the first board:

- Raspberry Pi 40-pin header for mounting, identity, and Pi-to-ESP32 UART
- ESP32 UART to Pi using the Pi GPIO header
- separate USB hub section for extra Pi USB ports

This avoids consuming one downstream USB hub port just to talk to the ESP32.

## USB target

New target:
- 1 upstream USB connection from the Raspberry Pi into the board's hub
- **7 external downstream USB 2.0 ports**
- **4 × USB-A**
- **3 × USB-C**
- externally powered hub section
- per-port protection/current limiting where practical

A realistic controller for this target is a dedicated 7-port USB 2.0 hub IC such as the Microchip USB2517 family. The exact part is not locked until the builder checks package, availability, cost, power-control requirements, and routing difficulty.

The USB hub is separate from the ESP32-S3. The ESP32 is the robotics controller; the hub expands the Raspberry Pi's USB connectivity.

USB-C downstream ports require correct USB-C CC configuration in addition to D+/D-, VBUS, ground, and ESD protection.

For the first revision, USB 2.0 is intentionally chosen over USB 3.x to keep the PCB achievable.

## Power target

Do not power servos from the Raspberry Pi.

Concept:
- external wall supply
- onboard buck conversion
- separate servo and logic/USB power branches
- common ground
- protection against accidental back-powering into the Pi

Exact regulator parts and current ratings must be selected after a real power-budget calculation.

## HAT naming

The project can use the working name **Ultimate PI HAT**.

If the finished board is marketed as a true Raspberry Pi HAT/HAT+, it should follow the Raspberry Pi HAT+ electrical/identity requirements, including the 40-pin connector and ID EEPROM requirements.

## Sensor expansion

Initial sensor target:
- I2C
- UART
- GPIO
- ultrasonic-sensor connector

A true onboard ultrasonic analog front-end is a possible later stretch goal because it is much harder than connecting a ready-made distance module.
