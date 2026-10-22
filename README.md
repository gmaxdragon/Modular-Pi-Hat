# Modular PI HAT

## What I made

I made a massive PCB which is a PI Hat for my robotic arm. I really wanted to streamline everything and shrink it down and make it more reliable so I made this. It's really cool.

## What it does

The big board is a massive PI Hat that can control servos, attach to sensors, and connect to the mini board which is connected by a big cable to the main board on screw terminals and it controls 2 servos for the wrist and gripper.

## Why I made it

I made it because I was having a ton of difficulties making everything move correctly and everything was all over the place. It's way simpler, easy to use, and reliable.

## My work and what I learned

I personally worked on the schematics and routing and basically, I added all the components, added power symbols, added net labels, and multiple more stuff and routed and adjusted the whole PCB. I worked through a lot of problems such as the ERCs not budging, a ton of short circuits reported in the DRC and a ton of more annoying problems. However, I learned the whole flow of how to make a schematic and a PCB and it feels really good now.

## Current status

Currently, the whole board is finished. The schematics, the routing, and testing is all good now. Nothing has been made as of now and I need to test it out and solder it once it comes.

## Help and sources

I used AI a ton in order to guide me with making the full thing and giving me instructions on how to fix some errors. Mostly, I used the ERC and DRC a ton as it's extremely helpful for me and it pinpoints where all the errors are and I used the help of some friends in school to tell me what to do. Honestly, AI helped with making the schematics and telling me what parts I need and researching meanwhile I did the work, it helped me with organizing and kicking off routing the board, it helped me when there was annoying footprint issues, and a ton of error fixing and instructions.

## Journal note

Hey, I accidentally added Week 3 one of the journal entries here, don't mind it please. I couldn't find a way to remove it.

## Bill of materials

PCB fabrication is $4.00 per board. This table includes one main PCB and one servo-extender PCB. Shipping remains the existing $30.00 estimate.

| Item | Qty | Supplier | Cost/item (USD) | Total cost (USD) | Link |
| --- | ---: | --- | ---: | ---: | --- |
| ESP32-S3-WROOM-1-N8R8 module, 8MB flash + 8MB PSRAM | 1 | Mouser | $6.28 | $6.28 | [Part](https://www.mouser.com/en/ProductDetail/Espressif-Systems/ESP32-S3-WROOM-1-N8R8?qs=7D1LtPJG0i3%2F28hKFavOpQ%3D%3D) |
| AP2112K-3.3 3.3 V LDO regulator | 1 | DigiKey | $0.28 | $0.28 | [Part](https://www.digikey.com/en/products/detail/diodes-incorporated/AP2112K-3-3TRG1/4470746) |
| 40-pin extra-tall 2x20 female stacking header | 1 | DigiKey | $2.95 | $2.95 | [Part](https://www.digikey.com/en/products/detail/adafruit-industries-llc/1979/6238003) |
| 4-way 5.08 mm Phoenix screw terminal | 2 | DigiKey | $2.28 | $4.56 | [Part](https://www.digikey.com/en/products/detail/phoenix-contact/1715747/260633) |
| 2-way 5.08 mm Phoenix screw terminal | 1 | DigiKey | $1.16 | $1.16 | [Part](https://www.digikey.com/en/products/detail/phoenix-contact/1715721/260631) |
| Breakaway 0.1 inch male pin header strips, 10-pack | 1 | DigiKey | $4.95 | $4.95 | [Part](https://www.digikey.com/en/products/detail/adafruit-industries-llc/392/21283800) |
| USB-C USB2.0 receptacle | 1 | DigiKey | $0.80 | $0.80 | [Part](https://www.digikey.com/en/products/detail/gct/USB4105-GF-A/11198441) |
| 470 uF 10 V through-hole capacitor | 1 | DigiKey | $0.71 | $0.71 | [Part](https://www.digikey.com/en/products/detail/panasonic-industry/EEU-FR1A471/9921021) |
| 100 uF 25 V through-hole capacitor | 1 | DigiKey | $0.87 | $0.87 | [Part](https://www.digikey.com/en/products/detail/kyocera-avx/RPA0609101M025B/17634433) |
| 22 uF 10 V 1206 ceramic capacitor | 1 | DigiKey | $0.47 | $0.47 | [Part](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL31A226KPHNNNE/3886945) |
| 1 uF 50 V 0805 ceramic capacitor | 3 | DigiKey | $0.18 | $0.54 | [Part](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21A105KBCLNNC/3888054) |
| 100 nF 50 V 0805 ceramic capacitor | 1 | DigiKey | $0.10 | $0.10 | [Part](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21B104KBCNNNC/3886661) |
| 10k 1 percent 0805 resistor | 4 | DigiKey | $0.10 | $0.40 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0710KL/727535) |
| 5.1k 1 percent 0805 resistor | 2 | DigiKey | $0.10 | $0.20 | [Part](https://www.digikey.com/en/products/detail/bourns-inc/CR0805-FX-5101ELF/4247942) |
| 22 ohm 1 percent 0805 resistor | 2 | DigiKey | $0.10 | $0.20 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0722RL/727735) |
| 1k 1 percent 0805 resistor | 1 | DigiKey | $0.10 | $0.10 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-071KL/727444) |
| 75k 1 percent 0805 resistor | 1 | DigiKey | $0.10 | $0.10 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0775KL/731080) |
| 100k 1 percent 0805 resistor | 1 | DigiKey | $0.11 | $0.11 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-07100KL/727544) |
| 4.7k 1 percent 0805 resistor | 2 | DigiKey | $0.10 | $0.20 | [Part](https://www.digikey.com/en/products/detail/yageo/RC0805FR-074K7L/727929) |
| Green 0805 LED | 1 | DigiKey | $0.19 | $0.19 | [Part](https://www.digikey.com/en/products/detail/lite-on-inc/LTST-C170KGKT/386777) |
| SPST SMD tactile switch | 2 | DigiKey | $0.21 | $0.42 | [Part](https://www.digikey.com/en/products/detail/e-switch/TL3305AF160QG/5816181) |
| Keystone mini blade through-hole fuse holder | 1 | DigiKey | $1.31 | $1.31 | [Part](https://www.digikey.com/en/products/detail/keystone-electronics/3568/2137306) |
| Littelfuse MINI 297 2A 32V blade fuse, selected for prototype | 1 | DigiKey | $0.39 | $0.39 | [Part](https://www.digikey.com/en/products/detail/littelfuse-inc/0297002-WXNV/124900) |
| 0.91 inch white 128x32 SSD1306 I2C OLED breakout, DFRobot DFR0648 | 1 | DigiKey | $9.90 | $9.90 | [Part](https://www.digikey.com/en/products/detail/dfrobot/DFR0648/12324932) |
| 4-position 2.54mm Samtec OLED female socket | 1 | DigiKey | $1.11 | $1.11 | [Part](https://www.digikey.com/en/products/detail/samtec-inc/SSW-104-01-G-S/1112103) |
| 6 inch male-to-female jumper cable kit, 20 wires, for OLED J10 pin-order correction | 1 | DigiKey | $2.75 | $2.75 | [Part](https://www.digikey.com/en/products/detail/sparkfun-electronics/12794/5993859) |
| Main PCB fabrication, 1 bare board | 1 | JLCPCB | $4.00 | $4.00 | [Ordering reference](https://jlcpcb.com/help/article/how-do-i-place-an-order) |
| Servo extender PCB fabrication, 1 bare board | 1 | JLCPCB | $4.00 | $4.00 | [Ordering reference](https://jlcpcb.com/help/article/how-do-i-place-an-order) |
| **Parts and boards subtotal** | | | | **$49.05** | |
| Estimated total shipping | 1 | | | $30.00 | |
| **Total including estimated shipping** | | | | **$79.05** | |

[BOM.csv](BOM.csv) contains the same items and prices. [bom.csv](bom.csv) includes part numbers and assembly notes. Tax, customs and unlisted wiring costs are not included in the total above.

## Design files

| Board | Schematic | PCB | KiCad project | Gerbers and drills |
| --- | --- | --- | --- | --- |
| Main Pi HAT | [Schematic](hardware/main/test1.kicad_sch) | [PCB](hardware/main/test1.kicad_pcb) | [Project](hardware/main/test1.kicad_pro) | [ZIP](fabrication/main/Seizo_Main_HAT_Gerbers.zip) |
| Servo extender | [Schematic](hardware/servo-extender/SZSERVOEXTENDER.kicad_sch) | [PCB](hardware/servo-extender/SZSERVOEXTENDER.kicad_pcb) | [Project](hardware/servo-extender/SZSERVOEXTENDER.kicad_pro) | [ZIP](fabrication/servo-extender/Seizo_Servo_Extender_Gerbers.zip) |

[Footprint library](hardware/main/Seizo_Reviewed.pretty) · [Footprint library table](hardware/main/fp-lib-table) · [Journal](JOURNAL.md) · [Parts and wiring notes](purchasing/README.md) · [Fabrication notes](fabrication/GERBER_EXPORT_README.md)

[USB diagnostic firmware](firmware/seizo_diagnostics/seizo_diagnostics.ino): AI-assisted; not compiled for the ESP32 target or tested on hardware yet.

## Project images

![Servo extender PCB](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/1cjBC8H80sSoyKk4EDv7XmS5Kk83ydwd/f90c4d5f2fa67789069b727457536aac5fe36fa165831514a70457e22a323661.png)

![Servo extender design](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/1cjBC8H80sSoyKk4EDv7XmS5Kk83ydwd/ef0e2847ac5d6ea06a5012c0e2235f3642b78acaff1b1fbda78cab0476fa1f53.png)
