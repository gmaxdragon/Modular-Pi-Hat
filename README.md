# Modular-Pi-Hat

A modular Raspberry Pi 4 controller board for **Seizo**, an AI robotic arm, with a separate passive wrist/gripper servo extender.

**Status: both KiCad designs are routed and saved in their original CAD formats for Half Life design-stage submission. Neither board is manufacturing-released or hardware-tested.** A clean design-check count is not a current-capacity, polarity, or mechanical-fit certification.

## KiCad source files (required for Half Life submission)

**Main Pi HAT:** [PCB](hardware/main/test1.kicad_pcb) · [Schematic](hardware/main/test1.kicad_sch) · [Project settings](hardware/main/test1.kicad_pro).

**Passive servo extender:** [PCB](hardware/servo-extender/SZSERVOEXTENDER.kicad_pcb) · [Schematic](hardware/servo-extender/SZSERVOEXTENDER.kicad_sch) · [Project settings](hardware/servo-extender/SZSERVOEXTENDER.kicad_pro).

The main project includes its [custom KiCad footprint library](hardware/main/Seizo_Reviewed.pretty) and [project-local fp-lib-table](hardware/main/fp-lib-table). These are required for opening and verifying the submitted board in KiCad 10.

These are **design files, not a certified manufacturing release**. The custom USB footprint, regulator load and thermal margin, external servo supply/fuse, and stacked mechanical clearances require real-world verification before fabrication or powered operation. The [main HAT Gerber/drill ZIP](fabrication/main/Seizo_Main_HAT_Gerbers.zip) and [servo extender Gerber/drill ZIP](fabrication/servo-extender/Seizo_Servo_Extender_Gerbers.zip) have now been exported from the unchanged boards using KiCad 10. These are prototype fabrication outputs, not an approved electrical or manufacturing release.

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

**ESP32-S3-WROOM-1-N8R8 is now selected from [Mouser](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D) for $6.28 per unit (quoted).** Mouser ordering number: 356-EP32S3WROOM1N8R8. It remains required by the original PCB design. Source one exact bare SMD module separately from the 25 DigiKey parts. Do not substitute the N8, 1U or a development board. The bottom-left EEPROM components C1, JP1, R1, R2, U1 are intentionally excluded from board assembly and purchasing.

| Tier 2 budget | USD |
| --- | ---: |
| Full estimated components including exact N8R8 ESP32, OLED and **two** PCB fabrication estimates | $45.05 |
| Tier 2 funding ceiling | $65.00 |
| Nominal remaining **before** shipping, tariffs, tax and unpriced wiring | $19.95 |

The previously reported **$36.78** shopping-cart figure has not been reconciled against a full cart screenshot. The $45.05 estimate reflects revised $0.18 single-piece 1uF capacitors and $0.21 tactile switches. This is NOT a cart quote. The full **$45.05** parts-plus-provisional-PCB estimate now includes the required $6.28 Mouser N8R8 ESP32, $9.90 DFRobot DFR0648 OLED, $2.75 jumper-wire adapter, $1.11 Samtec socket and two provisional $2 PCB-fabrication estimates. Shipping, tariffs, tax and unknown wiring costs are additional.

### Purchasing: 25 DigiKey parts plus one Mouser ESP32

- **New empty DigiKey cart:** [25-item CSV excluding ESP32](purchasing/Seizo_DigiKey_FULL_CART_25_lines_DigiKey_OLED.csv). Order one [ESP32 at Mouser](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D) separately.
- **Original six-item cart still unchanged:** [add 19 missing DigiKey items](purchasing/Seizo_DigiKey_ADD_ONLY_19_missing_DigiKey_OLED.csv). Order the ESP32 from Mouser separately.
- The [26-item](purchasing/Seizo_DigiKey_Cart_Upload_26.csv) and [20-item add-only](purchasing/Seizo_DigiKey_ADD_ONLY_20_missing.csv) DigiKey files include ESP32 and are archived alternatives. **Do not import those if also ordering from Mouser.**
- [Detailed purchasing instructions](purchasing/README.md).

DigiKey's six accepted lines totaled **$8.80** for components, with **$8.49** estimated shipping and **$2.74** estimated tariffs, or **$20.03**, **before** adding the missing components. The 17 failed import entries largely used full-reel rather than cut-tape SKUs and ambiguous vendor part numbers, not real board defects.

The fuse and holder are the same MINI 297 physical family, but the **2A rating is not a verified servo-protection design**. Confirm servo stall currents, external supply current limit, operating voltage and interconnect-wire ampacity **before powering motors**. The 3.3V regulator thermal budget, USB connector land pattern, stacking mechanical fit, and exact board fabrication quote remain open.

**DO NOT plug the DFRobot DFR0648 OLED directly into Seizo J10.** Its pin order differs from J10. Use four individually mapped jumper wires: GND to GND, 3V3 to VCC, SCL to SCL and SDA to SDA. These wires are only for OLED logic, not servo power.

For the selected purchasing plan, obtain the other 25 components from DigiKey and the exact [Mouser ESP32](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D) separately. Keep genuine screenshots of both actual carts with price, shipping and taxes. The four-conductor servo cable and two PCB fabrication orders are separate. Do not count the ESP32 twice.

`BOM.md` and `JOURNAL.md` are auto-generated by Half Life and deliberately not edited. Use Half Life's **Import from repo** function after syncing this new `bom.csv` if it supports this format; verify each displayed quantity and total.



## Firmware

[USB diagnostic firmware](firmware/seizo_diagnostics/seizo_diagnostics.ino) provides newline-terminated `PING`, `STATUS`, and `HELP` commands for initial ESP32-S3 native USB testing. It does not configure motor-control outputs, servo PWM, sensors, or Pi UART communication. It is useful bring-up code, not the completed robot firmware or a hardware emergency stop.

**Validation: not compiled for the ESP32 target and not tested on hardware yet.** Keep external servo and stepper supplies disconnected during initial bring-up. Review the firmware and build configuration before flashing.

The KiCad design uses ESP32-S3-WROOM-1-N8R8 with 8 MB flash and 8 MB PSRAM. This module remains in the complete engineering BOM and is sourced separately from Mouser rather than in the selected DigiKey cart. Firmware target, flash configuration, PSRAM settings, USB CDC and bootloader must be validated for the eventual installed module before flashing. The diagnostic source rejects a non-S3 target or disabled USB CDC. Follow [Espressif's native USB setup instructions](https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/cdc_dfu_flash.html). No flashing or powered test has been performed as part of this repository update.

## Latest design-stage checks and remaining hardware validation

Both real KiCad source projects, including the 37 custom main-board footprints and project-local `fp-lib-table`, are already present in this GitHub repository. The project's own PCB DRC was reported as **zero errors and zero warnings** on October 11, 2026. The submitted ERC warning descriptions relate mainly to labeled unused Raspberry Pi GPIOs and two intentionally excluded EEPROM symbols. The repository does not claim an independent native DRC run after the latest modification or physical prototype testing.

Half Life's mandatory **PCB design files** checker can now be rerun. Separate Gerber/drill ZIPs have been generated and committed for both boards using KiCad 10; they remain unapproved for actual hardware manufacture. Review the 3.3V regulator temperature/load, servo fuse and wiring, custom USB footprint and D+/D- layout, and all connector/capacitor clearances before placing a manufacturing order or powering motors. Upload a genuine cart screenshot once the cart includes all needed parts; keep its actual order cost separate from the provisional BOM subtotal.



## Development record and assistance

The creator's original design journal is preserved in [JOURNAL.md](JOURNAL.md). AI assistance has been used for troubleshooting, parts research, this documentation update, and the initial diagnostic firmware. This does not represent hardware testing or a claim that the diagnostic firmware was written unaided. Programme eligibility and disclosure requirements must be satisfied separately.
