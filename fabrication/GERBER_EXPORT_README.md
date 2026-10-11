# Seizo fabrication outputs (main HAT and servo extender)

These are two different PCBs and must have two different manufacturer upload ZIPs.

The repository contains the native designs:
- `hardware/main/test1.kicad_pcb` and `test1.kicad_sch`
- `hardware/extender/SZSERVOEXTENDER.kicad_pcb` and `SZSERVOEXTENDER.kicad_sch`

**The manufacturer-ready Gerber / drill files have not yet been exported. Do not treat a .kicad_pcb as a ZIP of manufacturing data.**

## Export procedure in KiCad 10, repeated for EACH board

1. Open that PCB in KiCad PCB Editor; save. Refill filled zones with `B`.
2. Run **Inspect -> Design Rules Checker**, including a copper-zone refill. Record a current report; earlier DRC reports for older revisions are not valid for these files.
3. Select **File -> Fabrication Outputs -> Gerbers (.gbr)** (or File -> Plot; format Gerber).
4. Use an EMPTY output directory for that board (for example `gerbers/main/` or `gerbers/extender/`). Select **F.Cu**, **B.Cu**, **F.Mask**, **B.Mask**, **F.SilkS**, **B.SilkS**, **Edge.Cuts**. Do NOT mirror.
5. Click **Plot**.
6. In the plot window, select **Generate Drill Files**. Set **Excellon** format, use normal (unmirrored) coordinates, and generate plated and non-plated drill files (PTH/NPTH). Use the SAME output folder.
7. Open the Gerbers together with drill layers using KiCad GerbView or the fabricator's viewer. Confirm both the full board outline and EVERY mounting and component hole, the USB locating holes, and both mask/silkscreen layers.
8. ZIP the generated contents of ONE board's Gerber directory, keeping the actual `.gbr` and `.drl` files together. Do not combine the two boards in one ZIP.
9. Upload each ZIP independently for fabrication quote and DFM check. Select two copper layers and verify the intended board thickness and solder mask (red) before ordering.

## Important unclosed hardware decisions

- F1: MINI holder Keystone 3568, fuse Littelfuse 0297002.WXNV (2 A, 32 V). **2 A is only a provisional prototype choice.** Confirm servo voltage, combined peak/stall current, wire capacity, and fuse nuisance-blow behavior before applying servo power.
- U3 AP2112K-3.3: regulator dissipation and acceptable current from local 3.3V are not fully qualified.
- J8 USB-C: customized land pattern and USB data return geometry need vendor/engineering review.
- Main Pi socket J1 and the OLED module require physical mechanical confirmation. The selected OLED pins are in a different order from J10; use individual jumpers, never plug it directly in.
- U2 ESP32-S3-WROOM-1-N8R8 is intentionally **not included in the immediate DigiKey order**, so the board cannot operate fully until the correct module is sourced.

The current DigiKey upload file is `DigiKey_Bulk_Add_No_ESP32.csv`. Its order subtotal is an estimate; shipping, tariffs and fabrication are not final.
