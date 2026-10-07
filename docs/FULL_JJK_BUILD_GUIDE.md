# Ultimate PI HAT — Full JJK Build Guide

> AI-assisted learning guide. This is not the builder's Half Life journal and does not represent personally completed work.

## Sanity Binding Vow

Keep the physical connector target at **4 USB-A + 4 USB-C**, but make the first revision electrically sane:

- 4 USB-A = hub downstream ports
- 3 USB-C = hub downstream ports
- 1 USB-C = dedicated ESP32-S3 service/programming port

That gives eight visible USB connectors without forcing an 8-port downstream hub cascade on the first board.

If all eight connectors must later be Pi hub ports, treat that as a Special Grade revision.

## Grade 4 — Cursed Tool Inventory

Locked targets:

- ESP32-S3 module
- 6 servo signal outputs
- 16 labeled GPIO signals
- 4 USB-A connectors
- 4 USB-C connectors total
- 7-port USB 2.0 hub section
- Raspberry Pi interface
- ultrasonic-module connector
- I2C
- UART
- screw-terminal external power input
- onboard buck conversion
- separate servo and USB/logic power branches
- BOOT and RESET
- power/status LEDs
- protection and test points

### User decisions still required

- exact screw-terminal input voltage
- exact 5 V USB current budget
- exact servo current budget
- direct ESP32 servo PWM vs dedicated servo PWM controller
- true HAT/HAT+ compliance vs companion-board branding

## Grade 3 — Binding-Vow Block Diagram

Create a KiCad project called `Ultimate-PI-HAT`.

In Schematic Editor, make these hierarchical sheets/blocks:

1. `PI_INTERFACE`
2. `ESP32_CONTROLLER`
3. `USB_HUB`
4. `SERVO_GPIO`
5. `POWER`

At first, place no real circuit parts. Add text inside each block describing what it does.

### Block responsibilities

#### PI_INTERFACE
- Raspberry Pi connector/header
- UART link to ESP32
- common ground
- optional HAT ID EEPROM later

#### ESP32_CONTROLLER
- ESP32-S3 module
- BOOT
- RESET/EN
- status LED
- dedicated USB-C service/programming connector
- 3.3 V input

#### USB_HUB
- dedicated 7-port USB 2.0 hub controller
- four USB-A downstream ports
- three USB-C downstream ports
- upstream data connection to Raspberry Pi
- ESD protection
- per-port/ganged VBUS power control as chosen

#### SERVO_GPIO
- six standard 3-pin servo headers
- sixteen labeled GPIO signals in four groups of four
- I2C
- UART
- ultrasonic-module header

#### POWER
- screw-terminal input
- reverse-polarity/protection
- 5 V USB rail
- servo rail
- 3.3 V regulator
- bulk capacitors
- current-budget test points

Grade 3 pass condition:
You can point to every block and explain why it exists.

## Grade 2 — Cursed Energy Schematic

Do the actual schematic one block at a time.

### 1. ESP32 controller

Use an ESP32-S3 module rather than the bare chip for the first board.

Reason:
- module already handles RF antenna/crystal/flash complexity
- much easier first PCB
- still gives access to plenty of GPIO

Before assigning pins:
- reserve USB pins if using native USB
- avoid strapping pins for loads that could change boot state
- check module-specific flash/PSRAM pin restrictions
- keep UART0 available for recovery/debug if practical

Add:
- 3.3 V and GND
- EN/reset network
- BOOT button
- status LED
- service USB-C

### 2. Pi interface

For the first revision, use the Raspberry Pi as the high-level computer and the ESP32 as the real-time controller.

Suggested first communication link:
- Pi UART TX -> ESP32 RX
- Pi UART RX -> ESP32 TX
- common GND

Do not power the servo rail from the Pi.

If claiming true HAT/HAT+ compliance later:
- follow the official 40-pin mechanical/electrical rules
- add the required ID EEPROM and identity data

### 3. Servo outputs

Six connectors:
- SIGNAL
- SERVO_V+
- GND

Label them:
- SERVO1
- SERVO2
- SERVO3
- SERVO4
- SERVO5
- SERVO6

For only six servos, direct ESP32 PWM is a reasonable first option.
A dedicated PWM controller can still be chosen if you want to save GPIO/timing responsibility.

Never feed servo current through the ESP32 regulator.

### 4. Sixteen GPIO

Create four groups:
- GPIO_A1..GPIO_A4
- GPIO_B1..GPIO_B4
- GPIO_C1..GPIO_C4
- GPIO_D1..GPIO_D4

Every pin should be labeled on the schematic and silkscreen.

Add nearby:
- GND pins
- 3.3 V reference pins

Do not make external GPIO 5 V tolerant unless level shifting/protection is deliberately designed.

### 5. USB hub

Use a dedicated USB 2.0 hub controller.

For the first revision:
- seven downstream ports total
- four USB-A
- three USB-C
- one upstream link to the Raspberry Pi

The eighth visible USB connector is the ESP32 service USB-C.

For every external USB data port:
- D+
- D-
- 5 V VBUS
- GND
- ESD protection near the connector

USB-C downstream ports also need correct CC1/CC2 source-side configuration.

Follow the hub-controller reference schematic and datasheet instead of inventing the analog/clock/passive values.

### 6. Power

Do a written power budget before choosing regulators.

Budget categories:
- USB hub controller
- seven downstream USB ports
- ESP32
- six servos
- LEDs/sensors
- conversion losses

Keep:
- USB/logic 5 V rail
- servo rail
- 3.3 V logic rail

Do not assume all USB ports can deliver unlimited current.

Use:
- fuse/resettable protection
- reverse-polarity protection if appropriate
- bulk capacitance on servo rail
- local decoupling at ICs
- current-limited USB VBUS switches if supported by the design

Do not create a path that back-powers the Raspberry Pi.

### 7. Ultrasonic connector

First revision:
use a connector for a known ultrasonic module.

Do not build the ultrasonic analog front-end into the PCB until the digital board works.

## Grade 1 — Domain Layout

### Layer count

Prefer 4 layers for this design:
1. Top: components/signals
2. Ground plane
3. Power/signals
4. Bottom signals

This makes USB and ESP32 layout easier than a crowded 2-layer board.

### Placement order

1. Decide board outline
2. Place Pi connector
3. Place USB connectors on edges
4. Place screw terminal on edge
5. Place servo headers together
6. Place ESP32 with antenna keepout clear
7. Place hub controller close to USB routing area
8. Place ESD parts close to USB connectors
9. Place power regulators close to power input/load branches
10. Place bulk capacitors near servo power distribution
11. Place GPIO headers
12. Place buttons/LEDs where humans can reach/see them

### Routing order

1. USB D+/D- differential pairs
2. power/high-current rails
3. 3.3 V logic
4. servo signals
5. UART/I2C
6. GPIO
7. LEDs/buttons

### USB routing

- route D+ and D- together
- target the impedance required by the USB reference design
- keep lengths close
- minimize vias
- keep a continuous ground reference below them
- no long stubs
- do not route high-current switching traces under/alongside them

### ESP32 antenna

Keep copper/components away from the module antenna keepout region according to the module datasheet.

### Ground

Use a continuous ground plane.
Do not randomly split the USB ground and logic ground.

## Special Grade — Unlimited Void Verification

Before ordering:

### Schematic
- ERC run
- every warning understood
- no floating power pins
- no accidental 5 V on 3.3 V GPIO
- ESP32 boot/strapping pins checked
- USB-C CC networks checked
- hub reference circuit checked against datasheet
- regulator feedback networks checked
- servo rail isolated from Pi power

### PCB
- DRC run
- USB pair rules checked
- no antenna keepout violation
- power trace widths/pours checked
- screw-terminal polarity obvious
- connector pin 1 orientations checked
- mounting holes checked
- silkscreen labels readable
- no copper too close to board edge

### 3D inspection
- every connector points the correct way
- USB plugs have physical clearance
- servo plugs fit next to each other
- board does not collide with Raspberry Pi connectors/case

### BOM
- every part has exact manufacturer part number
- package matches footprint
- real vendor stock checked
- quantities correct
- total project cost calculated
- do not buy before the applicable Hack Club funding rules allow it

## Manufacturing

When verification passes:

1. Plot Gerbers
2. Generate drill files
3. Generate position files if assembly is used
4. Export BOM
5. Zip manufacturing outputs
6. Re-open the Gerbers in a viewer
7. Compare every layer visually
8. Only then submit/order

## Bring-up

Never plug everything in at once.

### Stage A
Bare board inspection:
- shorts
- solder bridges
- polarity
- connector orientation

### Stage B
Power only:
- no Pi
- no servos
- no USB devices
- verify each rail with a multimeter

### Stage C
ESP32:
- flash a simple test program
- verify serial/debug
- blink status LED

### Stage D
Pi communication:
- verify UART packets both directions

### Stage E
GPIO:
- test one GPIO at a time

### Stage F
Servo:
- external servo power
- one unloaded servo
- one channel
- small bounded movement
- then add remaining channels

### Stage G
USB:
- connect hub upstream
- test one downstream port
- then test remaining ports individually
- then test multiple devices

### Stage H
Sensors:
- ultrasonic module
- I2C
- UART expansion

## Firmware learning path

Write small pieces, not one giant program:

1. print firmware version
2. receive Pi command
3. reply PONG
4. set one GPIO
5. read one GPIO
6. drive one servo
7. drive six servos
8. read ultrasonic sensor
9. status/fault reporting
10. watchdog/failsafe

Example command concept:

- `PING`
- `GPIO 3 HIGH`
- `GPIOREAD 3`
- `SERVO 2 1500`
- `DIST?`

The exact protocol should be designed and understood by the builder.

## CAD

Tinkercad is fine for:
- rough enclosure ideas
- visualizing connector cutouts
- basic mounting concepts

For a precise enclosure around the final PCB, Onshape will be much easier because the PCB can be exported as a STEP model and referenced accurately.

Do not design the enclosure before the connector placement is stable.

## Half Life workflow

For each real work session:

1. start the required tracking/journal flow
2. do actual design work
3. save screenshots/photos
4. write the journal entry yourself
5. record the decision you made
6. stop tracking when you stop working

Do not claim:
- unattended runtime
- old work
- duplicate hours submitted elsewhere
- time spent only waiting for installs/downloads

## JJK Rules

### Sukuna Rule
If you do not know why a component is there, do not route it.

### Gojo Rule
Keep the design understandable. Complexity that you cannot verify is not strength.

### Nanami Rule
Do the boring checks before ordering.

### Todo Rule
Ask one question at a time when stuck.

### Mahoraga Rule
Adapt after failures, but record exactly what changed.
