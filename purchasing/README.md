# Seizo Half Life Tier 2 purchasing and cart instructions

**Scope:** main Raspberry Pi HAT and separate passive servo extender. Their populated components were reconciled against the KiCad PCB and schematic files in this repository. Both boards are untested prototypes; the zero-warning KiCad DRC reported by the designer is not an electrical/thermal safety certification.

**October 11 update:** The complete [bom.csv](../bom.csv) contains 28 estimate lines, **$45.09** for 26 DigiKey product lines (including the exact N8R8 ESP32) plus two provisional PCB fabrication lines. The new recommended CSV files are **26 products for an empty cart** and **20 missing products for the unchanged original six-item cart**. Older 25/19-line files omit the ESP32 and are archived for a separately sourced module. The new 26/20-line CSV files already include **one ESP32-S3-WROOM-1-N8R8**, so do not add a duplicate; online unit price snapshot **$6.32**, DigiKey [part listing](https://www.digikey.com/en/products/detail/espressif-systems/ESP32-S3-WROOM-1-N8R8/15295891). The user's previously reported **$36.78** cart figure is not independently verified and does not match the complete engineering estimate.

## Exact cart files (do not duplicate six existing items)

**Existing DigiKey cart with exactly the original six accepted products:** upload [20 missing line items including N8R8 ESP32](Seizo_DigiKey_ADD_ONLY_20_missing.csv). Do not use if you have already added other items or changed the original six; reconcile duplicates first. The original [19-item CSV](Seizo_DigiKey_ADD_ONLY_19_missing_DigiKey_OLED.csv) omits the ESP32, and is preserved as a historical alternate.

**Brand-new EMPTY DigiKey cart/list:** upload [all 26 items including N8R8 ESP32](Seizo_DigiKey_Cart_Upload_26.csv). Do not use it with a partially filled cart. The historical [25-line CSV](Seizo_DigiKey_FULL_CART_25_lines_DigiKey_OLED.csv) deliberately excludes the ESP32; use it ONLY if purchasing that exact module externally.

CSV files are for DigiKey's **Upload a List** flow; check column mapping for `Part Number`, `Quantity`, and `Customer Reference`. Headerless text files are for **Bulk Add**, which explicitly expects lines in `quantity, part number, reference` order. If you manually added some rejected parts since the six-item screenshot, remove duplicates before using the add-only file. Every SKU and availability must be confirmed in the actual cart.

## Actual items and corrected estimate

| Item | USD |
| --- | ---: |
| Six existing DigiKey items, exactly as shown in screenshot | $8.80 |
| Remaining 19 DigiKey items, estimated displayed unit prices | $25.97 |
| **Estimated original 25-line DigiKey parts subtotal (without ESP32)** | **$34.77** |
| Additional ESP32-S3-WROOM-1-N8R8, current quote to verify in cart | $6.32 |
| **Estimated 26-line DigiKey parts subtotal** | **$41.09** |
| Main HAT board fabrication, *provisional* | $2.00 |
| Servo extender fabrication, *provisional* | $2.00 |
| **Estimated components + two bare PCB fabrication orders including ESP32** | **$45.09** |
| **Half Life Tier 2 budget** | **$65.00** |
| Nominal available **before** shipping, tax, tariffs, and servo wiring | **$19.91** |

Your **$36.78** cart total must be verified against a real current screenshot. The **$45.09** full engineering estimate includes the actual N8R8 ESP32, DFRobot OLED module, Samtec socket, correctly pinned jumper cables and two separate provisional bare-PCB fabrication amounts. The first partial cart displayed **$8.49 shipping** and **$2.74 tariffs** with just six accepted items. Freight, tariffs and tax for the full cart plus PCB fabrication shipping have not been quoted. Do not treat $45.09 as an all-in checkout cost.


## Exact-module ESP32 sourcing fallback (checked October 11, 2026)

DigiKey [N8R8 cut-tape listing](https://www.digikey.com/en/products/detail/espressif-systems/ESP32-S3-WROOM-1-N8R8/15295891): **5407-ESP32-S3-WROOM-1-N8R8CT-ND**, listed $6.32. Public indexed stock counts have varied, including earlier unavailable and later positive counts. **The live cart is decisive.**

If unavailable, purchase the SAME Espressif manufacturer part **ESP32-S3-WROOM-1-N8R8**, not a replacement footprint or development board:

- [Mouser exact module](https://www.mouser.com/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8), about **$6.28** for one, stock shown on recent supplier page.
- [LCSC C2913201 exact module](https://www.lcsc.com/product-detail/wifi%20modules_espressif%20systems_esp32-s3-wroom-1-n8r8_C2913201.html), about **$5.04** for one, stock shown on supplier page. International shipping and duty may outweigh the lower part price.

Choose the lowest *delivered* quote; do not double-count ESP32 in the BOM. If bought externally, remove just the line from the DigiKey *cart*, keep it as a required line in `bom.csv`, and replace its unit price/vendor with the actual source only once confirmed. Do not silently alter the KiCad symbol/footprint or substitute N8/1U.

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

- **ESP32-S3-WROOM-1-N8R8** (8 MB flash / 8 MB PSRAM) is included in the BOM and the new 26/20-line cart CSVs at a $6.32 USD DigiKey price snapshot, but missing from historical 25/19-line imports. The complete HAT cannot operate without it. Add this exact module to your shopping cart and verify stock; do not substitute the non-PSRAM N8 model.
- Schematic-only EEPROM options **C1, R1, R2, U1 and JP1** are intentionally excluded from this populated board and purchase list. Extender **C1**, however, is a **real** 100uF capacitor already in the cart.
- A 4-conductor main-to-extender cable (**servo supply, ground, wrist signal and gripper signal**) is necessary unless already owned. Its route, length, conductor gauge and cost have not been specified; **not priced** in the $41.09.
- Raspberry Pi 4, fan, servos, their external regulated power supply, mounting bolts/spacers, any other motor drivers and physical wiring are pre-existing or not confirmed as new purchases. Verify compatibility and existing inventory, not silently assign them a $0 purchase cost.
- Each board has a separate JLCPCB order. $2 bare-board figures are estimates, **not quotes**. KiCad 10 Gerber/drill ZIPs now exist for [main](../fabrication/main/Seizo_Main_HAT_Gerbers.zip) and [extender](../fabrication/servo-extender/Seizo_Servo_Extender_Gerbers.zip), but they are **not** manufacturer-approved or hardware-safety-tested.

## To finish the Half Life cart evidence

1. Import **20 missing items** to the unchanged original six-line DigiKey cart (or **26** to a new empty cart/list). If DigiKey shows unavailable N8R8 stock, source the exact module externally and remove only its DigiKey cart line.
2. Resolve any errors; check all quantities and products. In particular confirm holder **36-3568-ND**, fuse **F986-ND**, OLED **1738-DFR0648-ND**, and cables **1568-12794-ND**.
3. Take **genuine screenshots of the updated cart and actual totals**, including shipping/tariffs. If ESP32 is sourced from another vendor, preserve evidence of that separately and include its actual cost. Attach the required evidence in Half Life. A synthetic screenshot is not legitimate purchase evidence.
4. Sync the Half Life project and re-run its repository check. The native KiCad source files are under `hardware/main/` and `hardware/servo-extender/` and have been verified in GitHub. Do not edit auto-managed `JOURNAL.md` or `BOM.md`.

**Hardware release remains unverified:** custom USB footprint/return path, regulator thermal load, fuse rating with actual servo stall loads, exact PCB fabrication quote, and physical Pi/HAT stack fit all require confirmation. Documentation readiness is not permission to power or install in a moving robot.
