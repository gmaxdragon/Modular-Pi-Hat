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

## Bill of materials

Source: [BOM.csv](BOM.csv), as recorded at commit `def7dec164d41e28f6db09647bfb2a51c4ae3624`. The item names, quantities, supplier links, and costs below are copied from that file. Prices are recorded estimates, not refreshed supplier quotes. PCB fabrication and shipping figures are estimates. No additional tax, customs, or unlisted wiring costs have been invented.

| Item | Qty | Supplier | Cost/item (USD) | Total cost (USD) | Link |
| --- | ---: | --- | ---: | ---: | --- |
| ESP32-S3-WROOM-1-N8R8 module, 8MB flash + 8MB PSRAM | 1 | Mouser | $6.28 | $6.28 | [Part](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D) |
| AP2112K-3.3 3.3 V LDO regulator | 1 | DigiKey | $0.28 | $0.28 | [Part](https://www.digikey.com/en/products/detail/diodes-incorporated/AP2112K-3-3TRG1/4470746) |
| 40-pin extra-tall 2x20 female stacking header | 1 | DigiKey | $2.95 | $2.95 | [Part](https://www.digikey.com/en/products/detail/adafruit-industries-llc/1979/6238003) |
| 4-way 5.08 mm Phoenix screw terminal | 2 | DigiKey | $2.28 | $4.56 | [Part](https://www.digikey.com/en/products/detail/phoenix-contact/1715747/260633) |
| 2-way 5.08 mm Phoenix screw terminal | 1 | DigiKey | $1.16 | $1.16 | [Part](https://www.digikey.com/en/products/detail/phoenix-contact/1715721/260631) |
| Breakaway 0.1 inch male pin header strips, 10-pack | 1 | DigiKey | $4.95 | $4.95 | [Part](https://www.digikey.com/en/products/detail/adafruit-industries-llc/392/21283800) |
| USB-C USB2.0 receptacle | 1 | DigiKey | $0.80 | $0.80 | [Part](https://www.digikey.com/en/products/detail/gct/USB4105-GF-A/11198441) |
| 470 uF 10 V through-hole capacitor | 1 | DigiKey | $0.71 | $0.71 | [Part](https://www.digikey.com/en/products/detail/panasonic-industry/EEU-FR1A471/9921021) |
| 100 uF 25 V through-hole capacitor | 1 | DigiKey | $0.87 | $0.87 | [Part](https://www.digikey.com/en/products/detail/kyocera-avx/RPA0609101M025B/17634433) |
| 22 uF 10 V 1206 ceramic capacitor | 1 | DigiKey | $0.47 | $0.47 | [Part](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL31A226KPHNNNE/3886945) |
| 1 uF 50 V 0805 ceramic capacitor | 3 | DigiKey | $0.18 | $0.54 | [Part](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21A105KBCLNNC/3888054) |
| 100 nF 50 V 0805 ceramic capacitor | 1 | DigiKey | $0.10 | $0.10 | [Part](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21B104KBCNNNC/3886661) |
| 10k 1 percent 0805 resistor | 4 | DigiKey | $0.10 | $0.40 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0710KL/727535) |
| 5.1k 1 percent 0805 resistor | 2 | DigiKey | $0.10 | $0.20 | [Part](https://www.digikey.com/en/products/detail/bourns-inc/CR0805-FX-5101ELF/4247942) |
| 22 ohm 1 percent 0805 resistor | 2 | DigiKey | $0.10 | $0.20 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0722RL/727735) |
| 1k 1 percent 0805 resistor | 1 | DigiKey | $0.10 | $0.10 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-071KL/727444) |
| 75k 1 percent 0805 resistor | 1 | DigiKey | $0.10 | $0.10 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0775KL/731080) |
| 100k 1 percent 0805 resistor | 1 | DigiKey | $0.11 | $0.11 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-07100KL/727544) |
| 4.7k 1 percent 0805 resistor | 2 | DigiKey | $0.10 | $0.20 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-074K7L/727929) |
| Green 0805 LED | 1 | DigiKey | $0.19 | $0.19 | [Part](https://www.digikey.com/en/products/detail/lite-on-inc/LTST-C170KGKT/386777) |
| SPST SMD tactile switch | 2 | DigiKey | $0.21 | $0.42 | [Part](https://www.digikey.com/en/products/detail/e-switch/TL3305AF160QG/5816181) |
| Keystone mini blade through-hole fuse holder | 1 | DigiKey | $1.31 | $1.31 | [Part](https://www.digikey.com/en/products/detail/keystone-electronics/3568/2137306) |
| Littelfuse MINI 297 2A 32V blade fuse, selected for prototype | 1 | DigiKey | $0.39 | $0.39 | [Part](https://www.digikey.com/en/products/detail/littelfuse-inc/0297002-WXNV/124900) |
| 0.91 inch white 128x32 SSD1306 I2C OLED breakout, DFRobot DFR0648 | 1 | DigiKey | $9.90 | $9.90 | [Part](https://www.digikey.com/en/products/detail/dfrobot/DFR0648/12324932) |
| 4-position 2.54mm Samtec OLED female socket | 1 | DigiKey | $1.11 | $1.11 | [Part](https://www.digikey.com/en/products/detail/samtec-inc/SSW-104-01-G-S/1112103) |
| 6 inch male-to-female jumper cable kit, 20 wires, for OLED J10 pin-order correction | 1 | DigiKey | $2.75 | $2.75 | [Part](https://www.digikey.com/en/products/detail/sparkfun-electronics/12794/5993859) |
| Main PCB fabrication, 5 bare boards | 1 | JLCPCB | $4.00 | $4.00 | [Ordering reference](https://jlcpcb.com/help/article/how-do-i-place-an-order) |
| Servo extender PCB fabrication, 5 bare boards | 1 | JLCPCB | $4.00 | $4.00 | [Ordering reference](https://jlcpcb.com/help/article/how-do-i-place-an-order) |
| **Parts and boards subtotal** | | | | **$49.05** | |
| Estimated total shipping | 1 | | | $30.00 | |
| **Total including estimated shipping** | | | | **$79.05** | |

The older [bom.csv](bom.csv), [bom_actual_boards.csv](bom_actual_boards.csv), and purchasing import files remain available as historical supporting records. Their earlier prices and totals must not be substituted for this table without reconciliation. This formatting update does not verify inventory, live prices, funding eligibility, or readiness to purchase.

The fuse and holder are the same MINI 297 physical family, but the **2A rating is not a verified servo-protection design**. Confirm servo stall currents, external supply current limit, operating voltage and interconnect-wire ampacity **before powering motors**. The 3.3V regulator thermal budget, USB connector land pattern, stacking mechanical fit, and exact board fabrication quote remain open.

**DO NOT plug the DFRobot DFR0648 OLED directly into Seizo J10.** Its pin order differs from J10. Use four individually mapped jumper wires: GND to GND, 3V3 to VCC, SCL to SCL and SDA to SDA. These wires are only for OLED logic, not servo power.

The four-conductor servo cable and its actual cost still need to be confirmed. It has not been assigned a fabricated price in the table.

## Firmware

[USB diagnostic firmware](firmware/seizo_diagnostics/seizo_diagnostics.ino) provides newline-terminated `PING`, `STATUS`, and `HELP` commands for initial ESP32-S3 native USB testing. It does not configure motor-control outputs, servo PWM, sensors, or Pi UART communication. It is useful bring-up code, not the completed robot firmware or a hardware emergency stop.

**Validation: not compiled for the ESP32 target and not tested on hardware yet.** Keep external servo and stepper supplies disconnected during initial bring-up. Review the firmware and build configuration before flashing.

The KiCad design uses ESP32-S3-WROOM-1-N8R8 with 8 MB flash and 8 MB PSRAM. This module remains in the complete engineering BOM and is sourced separately from Mouser rather than in the selected DigiKey cart. Firmware target, flash configuration, PSRAM settings, USB CDC and bootloader must be validated for the eventual installed module before flashing. The diagnostic source rejects a non-S3 target or disabled USB CDC. Follow [Espressif's native USB setup instructions](https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/cdc_dfu_flash.html). No flashing or powered test has been performed as part of this repository update.

## Latest design-stage checks and remaining hardware validation

Both real KiCad source projects, including the 37 custom main-board footprints and project-local `fp-lib-table`, are already present in this GitHub repository. The project's own PCB DRC was reported as **zero errors and zero warnings** on October 11, 2026. The submitted ERC warning descriptions relate mainly to labeled unused Raspberry Pi GPIOs and two intentionally excluded EEPROM symbols. The repository does not claim an independent native DRC run after the latest modification or physical prototype testing.

Half Life's mandatory **PCB design files** checker can now be rerun. Separate Gerber/drill ZIPs have been generated and committed for both boards using KiCad 10; they remain unapproved for actual hardware manufacture. Review the 3.3V regulator temperature/load, servo fuse and wiring, custom USB footprint and D+/D- layout, and all connector/capacitor clearances before placing a manufacturing order or powering motors. Upload a genuine cart screenshot once the cart includes all needed parts; keep its actual order cost separate from the provisional BOM subtotal.

## Development record and assistance

The creator's original design journal is preserved in [JOURNAL.md](JOURNAL.md). AI assistance has been used for troubleshooting, parts research, this documentation update, and the initial diagnostic firmware. This does not represent hardware testing or a claim that the diagnostic firmware was written unaided. Programme eligibility and disclosure requirements must be satisfied separately.
