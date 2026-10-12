# Seizo Half Life Tier 2 purchasing and cart instructions

**Scope:** main Raspberry Pi HAT and separate passive servo extender. Their populated components were reconciled against the KiCad PCB and schematic files in this repository. Both boards are untested prototypes; the zero-warning KiCad DRC reported by the designer is not an electrical/thermal safety certification.

**October 11 purchasing decision:** Source the main-board U2 module, exact **ESP32-S3-WROOM-1-N8R8**, from [Mouser](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D). Mouser # **356-EP32S3WROOM1N8R8**, quantity 1, quoted unit price **$6.28**. It is the required 8 MB flash / 8 MB PSRAM version with PCB antenna, not N8 or 1U.

The engineering [bom.csv](../bom.csv) lists **25 DigiKey product lines + one Mouser ESP32 + two provisional JLCPCB bare-board fabrication lines**, all 28 rows retained. Quoted parts subtotal **$41.05**, provisional PCB estimates **$4.00**, combined **$45.05** before shipping, tariffs, taxes and still-unpriced servo wiring. Half Life Tier 2 ceiling **$65.00**, nominal remaining **$19.95** before these extra costs. Pricing and stock are not reserved.

## Correct DigiKey cart imports (ESP32 excluded)

- Start with **an empty DigiKey cart** and upload the [25-item DigiKey-only CSV](Seizo_DigiKey_FULL_CART_25_lines_DigiKey_OLED.csv). Order the Mouser ESP32 separately using the link above.
- If your cart still contains the **original six accepted items**, add [19 missing DigiKey-only items](Seizo_DigiKey_ADD_ONLY_19_missing_DigiKey_OLED.csv), and order the Mouser ESP32 separately. Check for duplicates if the cart has changed.
- The [26-item](Seizo_DigiKey_Cart_Upload_26.csv) and [20-item add-only](Seizo_DigiKey_ADD_ONLY_20_missing.csv) DigiKey files contain an ESP32 and are alternate old sourcing options. **Do not use those and also buy the module from Mouser.**

Use DigiKey Upload a List and match Part Number, Quantity and Customer Reference. Buy 1 × Mouser **356-EP32S3WROOM1N8R8** as a separate order. Save genuine evidence for both vendor carts and include all delivered costs in Half Life.

## Estimated purchasing split

| Vendor/item | USD |
| --- | ---: |
| Six DigiKey items already in original cart | $8.80 |
| Nineteen remaining DigiKey product lines | $25.97 |
| **DigiKey total, 25 lines** | **$34.77** |
| **Mouser ESP32, one module** | **$6.28** |
| **Estimated components** | **$41.05** |
| Main bare PCB estimate | $2.00 |
| Extender bare PCB estimate | $2.00 |
| **Combined provisional total** | **$45.05** |
| Half Life Tier 2 funding | $65.00 |
| Remaining before shipping/tax/tariffs/wiring | $19.95 |

The prior $36.78 cart figure is not an independently verified complete cart. PCB and vendor shipping/tariffs/taxes are unquoted. Avoid double-counting any separately ordered ESP32. The Half Life-generated BOM.md and JOURNAL.md files will overwrite manual edits; update the source bom.csv and reimport from the repo.



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

- **ESP32-S3-WROOM-1-N8R8** is included in the engineering BOM, but not in the recommended 25/19-line DigiKey-only imports. Buy it separately from [Mouser](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D), $6.28 quoted, Mouser # 356-EP32S3WROOM1N8R8. Do not substitute the non-PSRAM N8 model.
- Schematic-only EEPROM options **C1, R1, R2, U1 and JP1** are intentionally excluded from this populated board and purchase list. Extender **C1**, however, is a **real** 100uF capacitor already in the cart.
- A 4-conductor main-to-extender cable (**servo supply, ground, wrist signal and gripper signal**) is necessary unless already owned. Its route, length, conductor gauge and cost have not been specified; **not priced** in the $41.05 component subtotal.
- Raspberry Pi 4, fan, servos, their external regulated power supply, mounting bolts/spacers, any other motor drivers and physical wiring are pre-existing or not confirmed as new purchases. Verify compatibility and existing inventory, not silently assign them a $0 purchase cost.
- Each board has a separate JLCPCB order. $2 bare-board figures are estimates, **not quotes**. KiCad 10 Gerber/drill ZIPs now exist for [main](../fabrication/main/Seizo_Main_HAT_Gerbers.zip) and [extender](../fabrication/servo-extender/Seizo_Servo_Extender_Gerbers.zip), but they are **not** manufacturer-approved or hardware-safety-tested.

## To finish the Half Life cart evidence

1. Import **19 missing DigiKey-only items** if your original six-line cart is unchanged, or **25** into a new empty DigiKey cart. Source the single ESP32 via [Mouser](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D) separately.
2. Resolve any errors; check all quantities and products. In particular confirm holder **36-3568-ND**, fuse **F986-ND**, OLED **1738-DFR0648-ND**, and cables **1568-12794-ND**.
3. Take **genuine screenshots of the DigiKey and Mouser carts and their actual totals**, including shipping, tariffs and tax. Attach the required evidence in Half Life. A synthetic screenshot is not legitimate purchase evidence.
4. Sync the Half Life project and re-run its repository check. The native KiCad source files are under `hardware/main/` and `hardware/servo-extender/` and have been verified in GitHub. Do not edit auto-managed `JOURNAL.md` or `BOM.md`.

**Hardware release remains unverified:** custom USB footprint/return path, regulator thermal load, fuse rating with actual servo stall loads, exact PCB fabrication quote, and physical Pi/HAT stack fit all require confirmation. Documentation readiness is not permission to power or install in a moving robot.
