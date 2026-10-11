# Modular-Pi-Hat

A modular Raspberry Pi 4 controller board for **Seizo**, an AI robotic arm, with a separate passive wrist/gripper servo extender.

**Status: both KiCad designs are routed and saved in their original CAD formats for Half Life design-stage submission. Neither board is manufacturing-released or hardware-tested.** A clean design-check count is not a current-capacity, polarity, or mechanical-fit certification.

## KiCad source files (required for Half Life submission)

**Main Pi HAT:** [PCB](hardware/main/test1.kicad_pcb) · [Schematic](hardware/main/test1.kicad_sch) · [Project settings](hardware/main/test1.kicad_pro).

**Passive servo extender:** [PCB](hardware/servo-extender/SZSERVOEXTENDER.kicad_pcb) · [Schematic](hardware/servo-extender/SZSERVOEXTENDER.kicad_sch) · [Project settings](hardware/servo-extender/SZSERVOEXTENDER.kicad_pro).

The main project includes its [custom KiCad footprint library](hardware/main/Seizo_Reviewed.pretty) and [project-local fp-lib-table](hardware/main/fp-lib-table). These are required for opening and verifying the submitted board in KiCad 10.

These are **design files, not a certified manufacturing release**. The custom USB footprint, regulator load and thermal margin, external servo supply/fuse, and stacked mechanical clearances require real-world verification before fabrication or powered operation. Gerber/drill outputs are not included because they are optional for the Half Life design submission and have not passed a final manufacturing release check.

## Project images

Design images already published in the project's Half Life journal:

![Seizo servo extender design preview from the project journal](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/1cjBC8H80sSoyKk4EDv7XmS5Kk83ydwd/f90c4d5f2fa67789069b727457536aac5fe36fa165831514a70457e22a323661.png)

![Seizo servo extender work from the project journal](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/1cjBC8H80sSoyKk4EDv7XmS5Kk83ydwd/ef0e2847ac5d6ea06a5012c0e2235f3642b78acaff1b1fbda78cab0476fa1f53.png)

These images are hosted by Half Life. Their continued availability depends on that host; the external image host could not be independently loaded during this documentation update.

## What the two boards do

**Main controller:** planned Raspberry Pi GPIO interface, ESP32-S3, native USB connection, logic-power regulation, fan connection, expansion headers, and a separate external servo-power path. The Pi handles higher-level software and cameras; future ESP32 firmware will handle time-sensitive peripheral work. A stacking connector is planned, but compatibility with the existing HAT, fan clearance, pin use, and identification bus still require review. There is no completed USB hub circuit in the reviewed schematic.

**Servo extender:** a passive board near the servos. It distributes power and ground and carries two independent control signals. It needs no microcontroller or firmware. Physical mounting may use an enclosure tray or clips; a stackable mount has not yet been dimensioned.

### Four-wire cable interface

| Cable terminal pin | Net | Purpose |
| --- | --- | --- |
| 1 | `SERVO_V+` | External regulated servo supply |
| 2 | `GND` | Common ground |
| 3 | `WRIST_SIG` | Wrist control signal |
| 4 | `GRIPPER_SIG` | Gripper control signal |

On the **extender's** three-pin servo headers, pin 1 is GND, pin 2 is servo power, and pin 3 is the corresponding signal. Confirm every actual cable's orientation; do not assume the main board's existing local servo headers use this same numbered order.

Servo power is not supplied by the ESP32 3.3V regulator. No powered motor testing is authorized by these documents.

## Bill of materials and Tier 2 funding

The [Tier 2 purchasing BOM](bom.csv) covers both populated boards, their connectors, the **Littelfuse MINI 297 2A 32V fuse** (DigiKey F986-ND), the matching Keystone 3568 holder (36-3568-ND), a DigiKey OLED module and its pin-order adapter jumper leads, and two **provisional** bare-PCB fabrication estimates. It uses the actual 75k R10, 4.7k R14/R15, and four-pin Samtec SSW-104-01-G-S OLED socket selected in the cart.

**ESP32-S3-WROOM-1-N8R8 is deliberately deferred from this purchasing BOM because of backorder.** It is physically required by the unmodified KiCad design and must be obtained separately before powering/testing the completed HAT. Do not substitute ESP32-S3-WROOM-1-N8, which lacks the specified PSRAM, without a real design review. The bottom-left EEPROM components C1, JP1, R1, R2, U1 are intentionally excluded from board assembly and purchasing.

| Tier 2 budget | USD |
| --- | ---: |
| Indicative components, OLED and **two** PCB fabrication estimates, excluding ESP32 | $38.75 |
| Tier 2 funding ceiling | $65.00 |
| Nominal remaining **before** shipping, tariffs, tax and unpriced wiring | $26.25 |

The earlier **$36.78** draft included the $6.32 backordered ESP32, which is excluded from the present order. This revised **$38.75** estimate instead includes the $9.90 DFRobot DFR0648 OLED, its $2.75 jumper-wire adapter pack, the $1.11 Samtec socket already in the cart, and two provisional $2 PCB-fabrication estimates. The final landed cost remains unknown.

### DigiKey cart and downloadable upload files

- [Add only missing 19 items](purchasing/Seizo_DigiKey_ADD_ONLY_19_missing_DigiKey_OLED.csv): use with the user's existing six-item cart; does **not** add the 2A fuse again.
- [All 25 DigiKey purchase lines](purchasing/Seizo_DigiKey_FULL_CART_25_lines_DigiKey_OLED.csv): import **only into an empty cart**.
- [Cart correction and unresolved external materials](purchasing/README.md).

DigiKey's six accepted lines totaled **$8.80** for components, with **$8.49** estimated shipping and **$2.74** estimated tariffs, or **$20.03**, **before** adding the missing components. The 17 failed import entries largely used full-reel rather than cut-tape SKUs and ambiguous vendor part numbers, not real board defects.

The fuse and holder are the same MINI 297 physical family, but the **2A rating is not a verified servo-protection design**. Confirm servo stall currents, external supply current limit, operating voltage and interconnect-wire ampacity **before powering motors**. The 3.3V regulator thermal budget, USB connector land pattern, stacking mechanical fit, and exact board fabrication quote remain open.

**DO NOT plug the DFRobot DFR0648 OLED directly into Seizo J10.** The module's physical pin order differs from J10. Use four individual male-to-female jumpers: J10 GND to OLED GND, 3V3 to VCC, SCL to SCL, SDA to SDA. The genuine cart screenshot should show **all 25 requested DigiKey product lines and the updated landed total**. The OLED module and its jumper-wire adapter are included in the corrected DigiKey import. PCB fabrication, the four-conductor servo interconnect, the deferred ESP32, and existing motors/power supplies are **not included** in the current DigiKey cart. A four-conductor cable between J11 and the extender's J1 is required unless already owned. Prices cannot be guaranteed until checkout.

`BOM.md` and `JOURNAL.md` are auto-generated by Half Life and deliberately not edited. Use Half Life's **Import from repo** function after syncing this new `bom.csv` if it supports this format; verify each displayed quantity and total.



## Firmware

[USB diagnostic firmware](firmware/seizo_diagnostics/seizo_diagnostics.ino) provides newline-terminated `PING`, `STATUS`, and `HELP` commands for initial ESP32-S3 native USB testing. It does not configure motor-control outputs, servo PWM, sensors, or Pi UART communication. It is useful bring-up code, not the completed robot firmware or a hardware emergency stop.

**Validation: not compiled for the ESP32 target and not tested on hardware yet.** Keep external servo and stepper supplies disconnected during initial bring-up. Review the firmware and build configuration before flashing.

The KiCad design uses ESP32-S3-WROOM-1-N8R8 with 8 MB flash and 8 MB PSRAM, but this backordered component is not being purchased now. Firmware target, flash configuration, PSRAM settings, USB CDC and bootloader must be validated for the eventual installed module before flashing. The diagnostic source rejects a non-S3 target or disabled USB CDC. Follow [Espressif's native USB setup instructions](https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/cdc_dfu_flash.html). No flashing or powered test has been performed as part of this repository update.

## Latest design-stage checks and remaining hardware validation

Both real KiCad source projects, including the 37 custom main-board footprints and project-local `fp-lib-table`, are already present in this GitHub repository. The project's own PCB DRC was reported as **zero errors and zero warnings** on October 11, 2026. The submitted ERC warning descriptions relate mainly to labeled unused Raspberry Pi GPIOs and two intentionally excluded EEPROM symbols. The repository does not claim an independent native DRC run after the latest modification or physical prototype testing.

Half Life's mandatory **PCB design files** checker can now be rerun. Gerber/drill files remain optional for the design-stage application and have not been approved for hardware manufacture. Review the 3.3V regulator temperature/load, servo fuse and wiring, custom USB footprint and D+/D- layout, and all connector/capacitor clearances before placing a manufacturing order or powering motors. Upload a genuine cart screenshot once the cart includes all needed parts; keep its actual order cost separate from the provisional BOM subtotal.



## Development record and assistance

The creator's original design journal is preserved in [JOURNAL.md](JOURNAL.md). AI assistance has been used for troubleshooting, parts research, this documentation update, and the initial diagnostic firmware. This does not represent hardware testing or a claim that the diagnostic firmware was written unaided. Programme eligibility and disclosure requirements must be satisfied separately.
