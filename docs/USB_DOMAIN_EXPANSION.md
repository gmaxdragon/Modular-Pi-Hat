# Ultimate PI HAT — USB Domain Expansion

AI-assisted planning document. The builder should make the actual schematic and routing decisions.

## Domain Expansion: Seven Ports

Target external USB ports:

- Port 1 — USB-A
- Port 2 — USB-A
- Port 3 — USB-A
- Port 4 — USB-A
- Port 5 — USB-C
- Port 6 — USB-C
- Port 7 — USB-C

Plus:

- 1 upstream USB connection from the Raspberry Pi to the USB hub controller.

## Why seven ports

Seven is a large but still realistic USB 2.0 hub target because dedicated seven-port hub controllers exist. This avoids cascading multiple hub chips just to reach a high port count.

## First-revision constraint

Keep the entire hub at **USB 2.0 High-Speed**.

Do not attempt USB 3.x in the first PCB. USB 3.x adds much harder high-speed routing, extra differential pairs, stricter impedance/layout requirements, and more connector complexity.

## USB-A port block

Each USB-A port needs, at minimum:

- D+
- D-
- 5 V VBUS
- ground
- connector shield strategy
- ESD protection
- power-current limiting/switching strategy

## USB-C downstream port block

Each USB-C downstream-facing port needs, at minimum:

- D+
- D-
- 5 V VBUS
- ground
- CC1
- CC2
- correct source-side CC configuration
- ESD protection
- power-current limiting/switching strategy
- connector shield strategy

USB-C does not become correct just because a USB-C connector is placed on the schematic.

## Power budget question

The seven ports cannot be treated as seven unlimited 5 V outputs.

Before selecting the power supply and buck converter, calculate:

- expected current per port
- worst-case total USB current
- six-servo peak current
- ESP32/logic current
- Raspberry Pi interaction
- regulator efficiency and heat

## Data routing rules to learn

- Route D+ and D- together as a differential pair.
- Avoid stubs.
- Keep the pair over a continuous reference plane.
- Minimize unnecessary vias.
- Keep ESD protection near external connectors.
- Follow the chosen hub-controller layout guide.
- Do not guess USB trace geometry.

## JJK rule

**Unlimited Void does not mean unlimited current.**

Seven connectors are allowed. Seven randomly powered connectors are not.
