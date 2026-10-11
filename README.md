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

## Bill of materials and budget

The updated [bom.csv](bom.csv) includes **27 indicative purchasing lines** for the main HAT and the passive servo extender. It matches the populated schematic references: ESP32-S3-WROOM-1-N8R8 with 8 MB flash and 8 MB PSRAM, 75k R10, 4.7k R14/R15, 0.91-inch OLED, fuse holder, and estimated bare-board fabrication. The excluded bottom-left EEPROM circuit is not budgeted as installed hardware.

**Draft parts-plus-two-PCB subtotal: $36.78 USD** (not a final supplier quote). Prices and part substitutes must be checked against the final assembly. The 2A fuse row is explicitly an **unapproved price placeholder**, not a selected protective device. Shipping, cables/wire, tax and any new electrical protection are not priced.

| Allocation | USD |
| --- | ---: |
| Draft populated components and two bare-board fabrication estimates | $36.78 |
| Protected contingency | $10.00 |
| Remaining for shipping, tax, wiring, and hardware revisions | $53.22 |
| **Current Tier 3 funding ceiling** | **$100.00** |

The automatically generated BOM.md and JOURNAL.md belong to Half Life and must not be edited directly. Once this repository syncs, use the Half Life project’s **Import from repo** control to update its online parts form from bom.csv, then review every price and quantity.

### Purchasing holds

- Reconcile quantities and footprints against the latest saved native KiCad designs. Both native source projects are now included above. Reconcile the final purchased parts against the exact PCB footprints before ordering.
- Select the fuse from the actual servo current, supply, wiring, and protection requirements. The schematic's generic `Fuse` entry has no validated rating yet. Confirm cable length before choosing its wire gauge and buying it.
- Check the exact USB-C receptacle, both terminal types, capacitor lead dimensions, switches, LED polarity, and stacking header against their PCB footprints. The capacitor used for costing the extender has a 0.248-inch body diameter and 0.098-inch lead pitch; final lead-hole fit must still be verified.
- Verify the 3.3V regulator's current and thermal margins, ESP32 antenna clearance, USB layout, and existing-HAT electrical compatibility. The AP2112's nominal current rating is not a thermal sign-off.
- Get actual fabrication, shipping, tax, and tariff totals before importing a final funding request or ordering.

`BOM.md` and `JOURNAL.md` are generated by Half Life and intentionally remain untouched. Editing them here does not update the platform and can be overwritten during sync. The platform's **Import from repo** control can be used to attempt importing `bom.csv`; the importer schema and resulting quantities/prices must be checked. Do not submit the USD 36.78 electronic subtotal as the complete project cost.

## Firmware

[USB diagnostic firmware](firmware/seizo_diagnostics/seizo_diagnostics.ino) provides newline-terminated `PING`, `STATUS`, and `HELP` commands for initial ESP32-S3 native USB testing. It does not configure motor-control outputs, servo PWM, sensors, or Pi UART communication. It is useful bring-up code, not the completed robot firmware or a hardware emergency stop.

**Validation: not compiled for the ESP32 target and not tested on hardware yet.** Keep external servo and stepper supplies disconnected during initial bring-up. Review the firmware and build configuration before flashing.

For the proposed ESP32-S3-WROOM-1-N8, use Arduino's ESP32S3 Dev Module target with USB CDC On Boot enabled, Hardware CDC and JTAG USB mode, UART0 / Hardware CDC upload mode, an 8MB flash configuration, and PSRAM disabled. The source rejects a non-S3 target or disabled USB CDC. Follow [Espressif's native USB setup instructions](https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/cdc_dfu_flash.html). No flashing or powered test has been performed as part of this repository update.

## Latest main-schematic review

The supplied `ERC3.rpt`, dated October 8, 2026 at 21:15:43, reports **0 errors and 31 warnings**:

| Count | Warning group | Review needed |
| ---: | --- | --- |
| 24 | Labels connected to one unused Raspberry Pi GPIO pin | Check that each is intentionally unused by this board; preserve physical pass-through access |
| 1 | Isolated `PI_FAN` net label | The fan power connection still needs to join the actual Pi 5V supply net |
| 2 | Unconnected wire endpoints | Inspect the highlighted endpoints; do not assume the intended signals are connected |
| 2 | Library-symbol differences | Review the EEPROM bypass capacitor and write-protect jumper before accepting library changes |
| 1 | `+5V` and `PI_5V` on the same net | Resolve naming consistently; this warning alone is not a short circuit |
| 1 | Local and global `GND` naming overlap | Make the ground-label representation consistent |

The report also lists ignored ERC checks, including footprint-filter mismatch checking. Do not equate zero reported errors with complete electrical or footprint validation.

## Before submission or manufacture

Upload the actual latest main and extender `.kicad_sch` and `.kicad_pcb` designs, plus their project settings where available. These are still missing from the repository. Do not use stale snapshots or fabricated empty design files to satisfy the checker.

Then complete schematic review, main-board layout, footprint-to-part verification, DRC including unconnected items and schematic parity, and physical fit review. Export genuine Gerbers and drill outputs only from the reviewed boards. The final BOM must include the real fabrication and landed-order costs. The project cover image must be set separately in Half Life.

## Development record and assistance

The creator's original design journal is preserved in [JOURNAL.md](JOURNAL.md). AI assistance has been used for troubleshooting, parts research, this documentation update, and the initial diagnostic firmware. This does not represent hardware testing or a claim that the diagnostic firmware was written unaided. Programme eligibility and disclosure requirements must be satisfied separately.
