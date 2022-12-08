# Assembly
## Base 
### 1) First Start by Ordering/Buying the following
   - 2020 Extrusion
   - M4 Bolts
   - M4 T-Nut
   - Load Sensors
   - HX711
   - Teensy 4.0
### 2) Printing
next youll need the parts to print the base. print out every part listen in the STL-Files, then in folder "Base" youll find all the needed stl files to print these out.
once you have all 5 peice printed out you can begin to put it together
    1) first your gonna take the Base and take ribbon cable and wire it through the cut outs on the bottom. i used 28 guage 6 wire, ribbon cable, this is just to keep it more tidy.
    2) once the wiring is routed, use the wiring diagram to help make this easier. you solder 2 wires to GRN and 2 wires to WHT and one to RED and one to BLK. you need to follow the wiring diagram but once the wires are through the base you then solder the load sensors onto them. 
    
    
![image](https://user-images.githubusercontent.com/98432267/206462951-42a1bc23-779a-4f0f-ab2c-1664ebf527a6.png)
### 3) Testing Loadsensors
once yout finish soldering everything i highly recommend running the HX711_Basic_Example code on the teensy, and test that the loadsensors are outputting numbers. once you run this on both pairs, move on to the next step.
### 4) Assemblng the Base
  - once you figure out that the loadcells are working and wire them to the pcb or to the teensy directly. your gonna start assembling the stick. make sure the loadcells are TEMPORARILY held in place. i did this by using hot glue and just stick tabs on the side to hold them down. then you take the part "O-ring-Plate" and place it on top of the loadsensors. put the M4 bolt through the center hole, and then through the O-Ring-Plate.
  - once this is done you can take your rubber O-Ring and place it into the notch on the O-Ring-Plate. this creates some movement in your stick.
  - Next you heatsink the M4 Bolt in the Part "2020-Extrusion-Mount" in the hexagon on the bottom. do this by using your soldering iron and heating up the nut until eventually it sinks into the print. make it flush with the rest of the print. watch this video for tips on this:
 https://www.youtube.com/watch?v=GP1qrN-ONTA
  - then you can put the 2020 extrusion and the T-Nuts to secure it. next you can put the 2020 Extrusion and the "2020 Extrusion mount" onto the screw you put in earlier. screw this down until you get the retension you like. tightening this screw controls how much force is needed to move the stick.
   - Screw Looser = Less force needed for max deflection
   - Screw Tight = More force needed for max Deflection
  - once you have this done the base is pretty much complete. you can use it as is, or attatch it to a aluminum plate (Highly recomended). to prevent the cable from ripping away the usb out of the teensy you use 
