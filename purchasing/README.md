# Seizo Half Life Tier 2 purchasing and cart instructions

**Scope:** main Raspberry Pi HAT and separate passive servo extender. Their populated components were reconciled against the KiCad PCB and schematic files in this repository. Both boards are untested prototypes; the zero-warning KiCad DRC reported by the designer is not an electrical/thermal safety certification.

## Exact cart files (do not duplicate six existing items)

**Existing DigiKey cart with six accepted products:** upload [19 missing line items](Seizo_DigiKey_ADD_ONLY_19_missing_DigiKey_OLED.csv), or paste the [19-line headerless Bulk Add list](Seizo_DigiKey_BULK_ADD_MISSING_19.txt). These lists deliberately **do not** add another 2A fuse, the two 4-way terminal blocks, the 2-way terminal, the OLED female socket, or the two radial capacitors already in the cart.

**Brand-new EMPTY DigiKey cart:** upload [all 25 line items](Seizo_DigiKey_FULL_CART_25_lines_DigiKey_OLED.csv), or paste the [25-line headerless Bulk Add list](Seizo_DigiKey_BULK_ADD_FULL_25.txt). Do not use this on a partially filled cart.

CSV files are for DigiKey's **Upload a List** flow; check column mapping for `Part Number`, `Quantity`, and `Customer Reference`. Headerless text files are for **Bulk Add**, which explicitly expects lines in `quantity, part number, reference` order. If you manually added some rejected parts since the six-item screenshot, remove duplicates before using the add-only file. Every SKU and availability must be confirmed in the actual cart.

## Actual items and corrected estimate

| Item | USD |
| --- | ---: |
| Six existing DigiKey items, exactly as shown in screenshot | $8.80 |
| Remaining 19 DigiKey items, estimated displayed unit prices | $25.95 |
| **Estimated 25-line DigiKey parts subtotal** | **$34.75** |
| Main HAT board fabrication, *provisional* | $2.00 |
| Servo extender fabrication, *provisional* | $2.00 |
| **Estimated components + two bare PCB fabrication orders** | **$38.75** |
| **Half Life Tier 2 budget** | **$65.00** |
| Nominal available **before** shipping, tax, tariffs, servo wiring, and future ESP32 | **$26.25** |

Your previous **$36.78** draft is superseded. It counted a backordered ESP32 and a cheaper OLED plan; the current estimate has no ESP32 but includes the DFRobot OLED module, Samtec socket, and correctly pinned jumper cables. The first, incomplete cart showed **$8.49 estimated shipping** and **$2.74 estimated tariffs** on just six accepted items, for $20.03. Freight, tariff and tax for the completed cart, plus PCB fabrication shipping, are **not yet quoted**. Do not treat $38.75 as the all-in checkout cost.

## Fuse and connector: selected separately

- **Fuse already in cart:** Littelfuse MINI 297, **0297002.WXNV**, 2A, 32VDC, DigiKey **F986-ND**, $0.39.
- **Fuse holder still to add:** Keystone **3568**, DigiKey **36-3568-ND**, $1.31. It is a MINI 297 PCB holder matching board F1 and the fuse family. These are TWO purchasable components for one board position.
- **2A is an initial candidate rating, not an approved servo-current limit**: stall current, voltage, source limit and wire gauge/length must be checked before powering any servos.

## OLED and pin order: do not plug it directly into the PCB socket

Selected: DFRobot **DFR0648**, DigiKey **1738-DFR0648-ND**, $9.90, 0.91-inch 128×32 I2C OLED. Samtec **SSW-104-01-G-S** four-position female socket, DigiKey **612-SSW-104-01-G-S-ND**, $1.11 is already in the cart. SparkFun **12794** male-to-female jumper pack, DigiKey **1568-12794-ND**, $2.75 is among the 19 missing.

**The display's physical 4-pin order differs from Seizo J10.** Direct insertion can apply power to the wrong pins. Use four individually connected wires with mapping:
- Seizo J10 pin 1 GND to OLED GND
- Seizo J10 pin 2 3V3 to OLED VCC
- Seizo J10 pin 3 SCL to OLED SCL
- Seizo J10 pin 4 SDA to OLED SDA

Solder four male header pins to the OLED from the purchased breakaway header pack. The chosen jumper pack is 28 AWG; these leads are for **OLED logic only**, not the servo supply. The DFRobot module's physical size and wiring route still need physical confirmation.

## Excluded, future or already owned hardware

- **ESP32-S3-WROOM-1-N8R8** (8 MB flash / 8 MB PSRAM) is **deferred due to backorder and not in the purchase subtotal**, as requested. It **remains on the PCB and schematic**, and the complete HAT cannot operate without installing it. Do not substitute N8 (without PSRAM) casually.
- Schematic-only EEPROM options **C1, R1, R2, U1 and JP1** are intentionally excluded from this populated board and purchase list. Extender **C1**, however, is a **real** 100uF capacitor already in the cart.
- A 4-conductor main-to-extender cable (**servo supply, ground, wrist signal and gripper signal**) is necessary unless already owned. Its route, length, conductor gauge and cost have not been specified; **not priced** in the $38.75.
- Raspberry Pi 4, fan, servos, their external regulated power supply, mounting bolts/spacers, any other motor drivers and physical wiring are pre-existing or not confirmed as new purchases. Verify compatibility and existing inventory, not silently assign them a $0 purchase cost.
- Each board has a separate JLCPCB order. $2 bare-board figures are estimates, **not quotes**. Gerber/drill exports are optional for the Half Life design submission, and not uploaded as manufacturing-approved artifacts.

## To finish the Half Life cart evidence

1. Import **19 missing items** to the current six-line DigiKey cart (or **25** to an empty cart).
2. Resolve any errors; check all quantities and products. In particular confirm holder **36-3568-ND**, fuse **F986-ND**, OLED **1738-DFR0648-ND**, and cables **1568-12794-ND**.
3. Take a **genuine screenshot of the entire updated cart** showing items, totals, shipping/tariffs, then attach it in Half Life. A synthetic screenshot is not legitimate purchase evidence.
4. Sync the Half Life project and re-run its repository check. The native KiCad source files are under `hardware/main/` and `hardware/servo-extender/` and have been verified in GitHub. Do not edit auto-managed `JOURNAL.md` or `BOM.md`.

**Hardware release remains unverified:** custom USB footprint/return path, regulator thermal load, fuse rating with actual servo stall loads, exact PCB fabrication quote, and physical Pi/HAT stack fit all require confirmation. Documentation readiness is not permission to power or install in a moving robot.
