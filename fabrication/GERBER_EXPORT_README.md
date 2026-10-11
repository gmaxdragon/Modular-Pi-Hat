# Seizo Gerber and drill exports

Both fabrication archives were generated from the **unchanged** KiCad 10 PCB source files by the automated GitHub Action [Export Seizo Gerbers and drills](../.github/workflows/export-gerbers.yml).

| Board | Complete fabrication ZIP |
|---|---|
| Main Pi HAT | [Seizo_Main_HAT_Gerbers.zip](main/Seizo_Main_HAT_Gerbers.zip) |
| Passive servo extender | [Seizo_Servo_Extender_Gerbers.zip](servo-extender/Seizo_Servo_Extender_Gerbers.zip) |

Both ZIPs contain KiCad-exported front/back copper, solder mask, paste, silkscreen, Edge.Cuts, and **Excellon drill files**. Their existence and archive integrity were checked by the export job. **They have not been approved by the PCB manufacturer and are not evidence of electrical safety.**

For a quote, submit each ZIP as a **separate board**. Use 2 copper layers and 0.06299 inch nominal (1.6 mm) board thickness; set red solder mask and white silkscreen if those are your desired finishes. Check material, copper weight, delivery, shipping, taxes and any additional cost before ordering. KiCad units shown here are converted to inches for convenience.

## Pre-order review still required

- Open each ZIP in GerbView or the fabricator's Gerber viewer to confirm outline, front/back orientation, all holes, solder mask, component pad exposure and labels.
- Confirm four Pi mounting holes and both USB locating holes do not trigger destructive automated copper removal or an unapproved fabrication change.
- Match the USB-C connector's exact mechanical footprint/land pattern to the selected GCT part.
- Check Raspberry Pi mounting, stacking header and fan/body clearances.
- Confirm regulator heat/current budget, servo supply, fuse ampere rating, motor stall current and main-to-extender cable gauge before powering.
- Confirm the 4-pin OLED accessory has a **different physical pin order** from the board's J10; connect by four mapped jumper wires, never plug the OLED directly into the socket.

**These files support a design-stage Half Life PCB submission.** They do not establish a validated, powered or manufacturing-released production design.