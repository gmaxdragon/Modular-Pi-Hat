Ultimate Pi HAT with components: enclosure reference

Open Ultimate_Pi_HAT_with_components.stl in your CAD program, using millimeters.
It represents all 37 placed component references on the original Ultimate Pi HAT.
It is not the Seizo Screen modified HAT, an enclosure, or the complete Pi assembly.

Included:
  - Original PCB outline, mounting holes and side notch, nominal thickness1.6mm.
  - 35 component models from the installed KiCad library at the PCB placements.
  - J1 replacement: conservative solid envelope for the selected extra-tall
    Adafruit1979 stacking connector, 51x5x23mm below the PCB, with40pins above.
  - C3 replacement: conservative capacitor body (8.5mm diameter,13mm height,
    plus0.5mm seating gap). Selected part is nominally8x11.5mm; the assigned
    generic KiCad model was too short. This shape is a fitting envelope.
  - F1 native fuse holder plus an added conservative MINI fuse housing envelope.
    The fuse housing is reserved above the holder top because insertion depth
    has not been physically measured. This may reserve more space than needed.

Model coordinates:
  PCB: x0..65mm, y0..56mm, z0..1.6mm.
  Included assembled occupied bounds: x0..65mm, y-5.85..56mm, z-23..17.765mm.
  These bounds are not a finished enclosure's required internal dimensions.
  The ESP32 module antenna projects beyond the PCB edge; keep its full model.
  Preserve this scale and orientation when importing alongside the bare-board STL.

Not included:
  Raspberry Pi4, remotely wired OLED, fan body, cables/mating plugs,
  screws, nuts, standoffs, fuse removal space or screwdriver access space.
  J10's socket is modeled; the OLED itself is not mounted directly onto J10.
  It needs a corrected pin-order wiring harness and a separately chosen position.

Allow additional room for tolerances, solder joints, plugs, wire bends, cooling
and assembly/service access. Check the actual parts before final case printing,
particularly header seating, fuse insertion and the capacitor. The model has
not been checked against an assembled physical HAT. Do not put metal hardware
against the ESP32 antenna. Plain PLA does not automatically require15mm of air.

STL contains multiple component shells, with normal assembly intersections.
It is an enclosure planning reference, not a Boolean-unioned printable assembly.
Eight zero-area triangles from the native library meshes were removed.
Mesh coverage, bounds and round-trip serialization checks passed.

ASSEMBLY_MODEL_NOTES.json lists model assumptions, included references and sources.

Sources:
https://github.com/gmaxdragon/Modular-Pi-Hat/blob/main/hardware/main/test1.kicad_pcb
https://www.adafruit.com/product/1979
https://mediap.industry.panasonic.eu/assets/imported/industrial.panasonic.com/cdbs/www-data/pdf/RDF0000/RDF0000C1266.pdf
https://www.littelfuse.com/assetdocs/littelfuse-datasheet-297-mini32v?assetguid=42c9dd21-a88e-4328-8e67-2f832444faf1
