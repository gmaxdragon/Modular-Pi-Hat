# Ultimate PI HAT — JJK Build Plan

This is an AI-assisted learning plan. The actual PCB work and Half Life journal should be done and written by the builder.

## Grade 4 — Cursed Tool Inventory

Goal: understand what the board needs before drawing wires.

Do:
1. Write down the six servo channels.
2. Write down the sixteen GPIO requirement.
3. Pick the physical USB mix: 2 USB-A + 2 USB-C.
4. Decide that the Pi remains the main computer.
5. Decide that the ESP32-S3 handles real-time hardware.
6. Decide that servos use external power.

Pass condition:
You can explain every major block in one sentence.

## Grade 3 — Binding-Vow Block Diagram

Draw boxes only:

- Raspberry Pi header
- ESP32-S3
- servo outputs ×6
- GPIO ×16
- USB hub
- USB-A ×2
- USB-C ×2
- wall-power input
- buck converter
- 3.3 V regulator
- ultrasonic connector
- protection

Connect the boxes with arrows.

No PCB traces yet.

Pass condition:
Every connector has a reason to exist.

## Grade 2 — Cursed Energy Schematic

Create the schematic one block at a time.

Order:
1. ESP32-S3
2. 3.3 V regulator
3. Pi UART
4. six servo signal headers
5. sixteen GPIO header signals
6. USB hub
7. external USB connectors
8. wall-power input
9. buck converter
10. protection
11. HAT ID EEPROM if pursuing real HAT compliance

Pass condition:
ERC errors are understood, not blindly ignored.

## Grade 1 — Domain Layout

PCB placement before routing:

- Pi header location first
- USB connectors on board edges
- power input on board edge
- servo connectors grouped together
- ESP32 antenna kept clear
- buck converter kept away from sensitive USB/RF areas
- large current paths short and wide
- USB D+/D- routed as matched differential pairs
- ground plane kept continuous where possible

Pass condition:
The board is physically usable before routing starts.

## Special Grade — Unlimited Void Verification

Before ordering:

- schematic review
- ERC clean or every exception explained
- DRC clean
- USB differential routing inspected
- current path widths checked
- regulator thermal design checked
- no Pi back-power path
- ESP32 boot pins checked
- connector orientation checked
- HAT mounting holes checked
- BOM checked against real vendor stock
- 3D board view inspected

Only after this stage should money be spent.

## Sukuna Rule

Never fix an electrical uncertainty by saying "probably fine."

Read the datasheet.

## Gojo Rule

If a subsystem is too complicated for a first revision, simplify it instead of pretending it is easy.
