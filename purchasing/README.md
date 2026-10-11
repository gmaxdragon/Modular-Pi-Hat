# Seizo Tier 2 parts and DigiKey cart corrections

The **main Pi HAT** and separate **passive servo extender** have committed KiCad schematic, PCB and project files under `hardware/main/` and `hardware/servo-extender/`. This purchasing list was reconciled against their actual populated footprints. **ESP32-S3-WROOM-1-N8R8 is explicitly excluded from the current purchase due to reported backorder**, but it remains essential to complete the HAT later. The N8 variant without R8 PSRAM is not the same part.

## Which file to upload

**For the existing DigiKey cart**, which already contains six accepted lines, import [17 missing lines](Seizo_DigiKey_ADD_ONLY_17_missing.csv). **Do not** import the 23-line file into that cart or you will double-order the six accepted lines, including the fuse.

For a **new empty DigiKey cart**, use [all 23 DigiKey lines](Seizo_DigiKey_FULL_CART_23_lines.csv). Import format: `Part Number, Quantity, Customer Reference`. The cut-tape codes with `CT` / `-1-ND` replace the rejected tape-and-reel codes with `TR` / `-2-ND`.

The user-provided original cart had six accepted items: two Phoenix 1715747 4-position terminals, one Phoenix 1715721 2-position terminal, one Samtec SSW-104-01-G-S 4-pin socket, one Panasonic EEU-FR1A471 470 uF capacitor, one KYOCERA RPA0609101M025B 100 uF capacitor, and the **Littelfuse 0297002.WXNV 2A 32 V MINI fuse**. The exact accepted component subtotal was **$8.80**, with **$8.49** estimated shipping and **$2.74** estimated tariffs. Thus the existing **$20.03** does **not** represent the completed order.

**Missing fuse holder:** Keystone **3568**, DigiKey **36-3568-ND**, is included in the 17-line add-only CSV. It is physically designed for the MINI 297 fuse series; DigiKey's **F986-ND** fuse is already in the cart. The fuse rating is **provisional**, not validated against servo supply or wiring.

## Tier 2 cost tracking

The reconciled [project BOM](../bom.csv) is an **indicative $30.99** for the non-ESP32 components, OLED from a separate retailer, and two provisional $2 PCB fabrication estimates. Tier 2 cap is **$65**. Estimated tariffs, shipping, tax, servo/power wire, any cable, and the future ESP32 are not included in that subtotal. There is no verified final whole-project landed quote.

## Items not in DigiKey import

- ESP32-S3-WROOM-1-N8R8: deferred because of backorder, **required** before the board works.
- Small I2C OLED: proposed ICStation 9934, $4.89 estimate, separate retailer, pin mapping GND/VCC/SCL/SDA and physical socket mating must be checked.
- Two **separate** prototype PCB fabrication orders (main HAT and extender), $2 each only *provisional* and not actual JLCPCB invoices.
- Four-conductor main-to-extender cable and correct power/ground wiring: required unless already owned; length, gauge, material and price not established.
- User's Raspberry Pi, pre-existing fan, robotic-arm servos and motor supply: not billed to this project; verify ownership and compatibility.
- EEPROM C1, R1, R2, JP1 and U1: deliberately excluded from PCB assembly.

## Release cautions

Neither DigiKey stock availability nor KiCad zero DRC warnings certify the custom PCB's USB land pattern, regulator thermal margin, Pi header mechanical stack, or suitability of a 2A servo fuse. Never energize the servos before supply, fuse, stall current and wire rating are verified.

Take a **genuine screenshot** of the complete updated DigiKey cart after the missing items have been added. A synthesized cart image would not substantiate the order.
