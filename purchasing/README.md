# Week 1 parts and wiring notes

[Project explanation and BOM table](../README.md) · [BOM.csv](../BOM.csv) · [Detailed parts list](../bom.csv)

## Purchasing totals

| Vendor/item | USD |
| --- | ---: |
| DigiKey components, 25 product lines | $34.77 |
| Mouser ESP32, one module | $6.28 |
| Components subtotal | $41.05 |
| Main PCB, one board | $4.00 |
| Servo extender PCB, one board | $4.00 |
| Parts and boards subtotal | $49.05 |
| Estimated shipping | $30.00 |
| Total including estimated shipping | $79.05 |

The PCB price is $4.00 per board, as confirmed by the project owner. Component prices are retained from the existing parts list. Tax, customs and unlisted wiring costs are not included above. Check the actual cart totals before purchasing.

## Cart imports

- For an empty DigiKey cart, use the [25-item DigiKey-only CSV](Seizo_DigiKey_FULL_CART_25_lines_DigiKey_OLED.csv).
- Only when the original six-item cart is unchanged, use the [19-item add-only CSV](Seizo_DigiKey_ADD_ONLY_19_missing_DigiKey_OLED.csv).
- Order one **ESP32-S3-WROOM-1-N8R8** separately from [Mouser](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D), part **356-EP32S3WROOM1N8R8**. Do not substitute the N8 or 1U version.
- The older [26-item](Seizo_DigiKey_Cart_Upload_26.csv) and [20-item add-only](Seizo_DigiKey_ADD_ONLY_20_missing.csv) imports also contain an ESP32. Do not use those and separately buy a second module by accident.

## Fuse and holder

| Item | Manufacturer part | DigiKey part | Cost |
| --- | --- | --- | ---: |
| 2A, 32V MINI blade fuse | Littelfuse 0297002.WXNV | F986-ND | $0.39 |
| MINI fuse holder | Keystone 3568 | 36-3568-ND | $1.31 |

These are two purchased items for the F1 board position. The fuse rating still needs to be checked against servo stall current, supply current limit and wire capacity before powered testing.

## OLED wiring

**Do not plug the DFRobot DFR0648 display directly into J10.** The display and board have different pin orders. Use four individually mapped jumper wires:

| Main board J10 | DFR0648 display |
| --- | --- |
| Pin 1: GND | GND |
| Pin 2: 3V3 | VCC |
| Pin 3: SCL | SCL |
| Pin 4: SDA | SDA |

Use the listed Samtec SSW-104-01-G-S socket and SparkFun 12794 jumper wires. Those jumper wires are for the display's logic connections, not servo power.

## Main board to servo extender

| Cable terminal pin | Net | Purpose |
| --- | --- | --- |
| 1 | SERVO_V+ | External regulated servo supply |
| 2 | GND | Common ground |
| 3 | WRIST_SIG | Wrist control signal |
| 4 | GRIPPER_SIG | Gripper control signal |

On the extender's three-pin servo headers, pin 1 is GND, pin 2 is servo power and pin 3 is the corresponding signal. Confirm the actual cable orientation and the main board's header order separately. Servo power is not supplied by the ESP32's 3.3V regulator.

The four-conductor cable's length, wire gauge and cost still need to be confirmed. The Raspberry Pi, fan, servos, power supply and mounting hardware should be checked against existing inventory before buying duplicates.

## Before assembly and powered testing

The boards have not been manufactured or physically tested. The regulator's load and temperature, USB footprint, servo fuse sizing, cable capacity and Pi/HAT mechanical fit still need checking. CAD checks do not replace those tests.

Keep the main PCB's intentionally excluded EEPROM parts separate from populated components. Extender C1 is a real 100uF capacitor and remains in the BOM.

The [main PCB](../fabrication/main/Seizo_Main_HAT_Gerbers.zip) and [servo extender](../fabrication/servo-extender/Seizo_Servo_Extender_Gerbers.zip) have separate Gerber/drill archives. Follow the [fabrication notes](../fabrication/GERBER_EXPORT_README.md) when checking these outputs.

## Journal source

[JOURNAL.md](../JOURNAL.md) is mirrored from Half-Life and can be overwritten by its next sync. The author's note about the misplaced Week 3 entry is in the [README](../README.md#journal-note). Adding that note does not remove the entry or alter the hours recorded in Half-Life.
