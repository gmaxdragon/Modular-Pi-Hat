# Modular Pi HAT: manufacturing and cost release review (2026-10-24)

**Digital source present; manufacturing/electrical commissioning NOT validated in hardware.** This is a technical review. It does not amend the author's journal or imply the PCBs were built.

## Native files already published

- Main: [KiCad project](../hardware/main/test1.kicad_pro), [schematic](../hardware/main/test1.kicad_sch), [PCB](../hardware/main/test1.kicad_pcb).
- Servo extender: [KiCad project](../hardware/servo-extender/SZSERVOEXTENDER.kicad_pro), [schematic](../hardware/servo-extender/SZSERVOEXTENDER.kicad_sch), [PCB](../hardware/servo-extender/SZSERVOEXTENDER.kicad_pcb).
- Manufacturing previews: [main](../fabrication/main/Seizo_Main_HAT_Gerbers.zip), [extender](../fabrication/servo-extender/Seizo_Servo_Extender_Gerbers.zip). These are separate fabrication jobs; send neither to production without preview/connector checks.

## Reconciled archived estimate

The public [BOM.csv](../BOM.csv) has 28 purchase/fab lines plus a $30 **estimated** shipping row. Listed parts/PCB estimate = **$49.05** and estimated total = **$79.05** before taxes, tariffs or missing wiring/mechanical items. Two board lines each use an unverified $4 allowance; **do not represent the number of PCBs delivered per lot or current prices as verified.** The cost leaves only $20.95 below a hypothetical $100 allowance, and exceeds a $65 allowance by $14.05 already, before omissions. Check the tier shown in Half-Life and the real cart, not a presumed tier.

The [manufacturer part-to-board map](../bom_actual_boards.csv) is the per-ref purchasing source. Critical SKUs: ESP32-S3-WROOM-1-N8R8 (8MB flash, 8MB PSRAM) from Mouser; separate Keystone 3568 MINI fuseholder and Littelfuse 0297002.WXNV fuse; DFRobot DFR0648 OLED **cannot** mate directly to J10 due to pin order; use labeled individual leads as specified in [purchase instructions](../purchasing/README.md).

## Required review before fab

1. Review both native projects in installed KiCad and rerun ERC/DRC with up-to-date footprints and symbols. Old archived validation is not today's rerun.
2. Verify USB4105-GF-A real mechanical pad/anchor drawing, solder mask, support tabs and 5V VBUS protection, then use the fabricator's preview for both boards.
3. Verify the 40-pin extra-tall HAT header height/underside, Raspberry Pi mounting, fan access and separation from 5V external servo power; do not connect two sources into Pi 5V.
4. Verify regulator AP2112K-3.3 thermal current under ESP32 worst-case Wi-Fi, OLED and sensors, and bulk capacitor placement; do not blindly power motors from the LDO.
5. Calculate MAX servo startup/stall current versus 2A fuse, supply rating, terminal temperature and actual four-conductor extender cable gauge. Place a **physical** reachable stop in the actual setup before supervised motor tests.
6. Mount OLED remotely. J10 is GND/3V3/SCL/SDA and the DFR0648 physical header order is different. Map by pad labels with individually insulated jumper leads and check polarity before power.
7. Confirm all quantity/price details in live DigiKey/Mouser and PCB fab carts, $30 shipping estimate, total landed shipping/tax, cables, M3 hardware, enclosure, ribbon strain relief and tools. Unquoted is never $0.
8. First hardware tests (after assembly) must be done current-limited and with motors disconnected; check no shorts, correct rails, USB enumeration and ESP32 firmware communications. Add controlled servo tests only after hardware safeguards and mechanical bounds are validated.

**No physical power-on, manufacturer preview approval, fab checkout or ordered parts were performed in this review.** The robot's automatic physical motion remains disabled.
