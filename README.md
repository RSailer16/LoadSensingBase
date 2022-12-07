# Overview
This is a modification/revision/update to the Jflyer F-16 Grip on thingiverse. in thise design i took his model and changed it and modified it to fit onto a 2020 extrusion. i then used The open Viper Hotas V2 By Bacon8tor on thingiverse, which took the original Jflyer81 model and added pcb support so you dont have to wire every wire to each button, and rather just use 5 Pos Navigation Switches From ada fruit. i created my own base that uses loadcells to measure your force applied vs ange of motion. this is realistic to the actual jet as that f-16 has a force sensing stick rather than that of a F-15 which measure where your stick is using hall effect sensors. below i will list the things i used, the code produced during this project, the issues, the versions, and everything i have used to get started.
# Parts made
## The Grip
To make the grip i used the Open Viper Hotas V2 By Bacon8tor. this is a remix of the original grip by Jflyer81 but this one has support for pcb such that you use Adafruits 5 way Thru Hole navigational switch. this means there is less soldering, 3D Printing, And effort in making this. everything went smoothely for me, but it depends on your printer. the pcbs were the tricky part, you have to order them from PCB Way or Any company that can manufactur pcbs. they take about 2 weeks to get here, and come fully assembled. they costed $20 and you get two sets of them depending on where you order them from. After all this it should go together realy well. links to all products are in the description.
## The Base
the base was probably the most tricky part. it went through many iterations, some worked some failed, but i learned from them all. the first design used traditionaly wheatstone bridge loadcells, like these seen here




<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRwDXsmqYrnBvKlI4qTI3hgRt6SoX7Hc7H-qO6vfch9yXgBGuoxTyWAQO0D7l3JEMmTnhs:https://www.phidgets.com/productfiles/3135/3135_0/Images/3150x-/0/3135_0.jpg&amp;usqp=CAU" alt="Micro Load Cell (0-50kg) - 3135_0 at Phidgets"/>
these worked well, but they had their issues, like mounting them to a metal plate, you had to buy extra brass standoffs, you needed 2020 extrusion 90 Degree corner mounts etc. it was just innefficient and it ended up being very flimsy and now sturdy. that where these loadcells came in:
<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTb2MgdJkO08hu76myKwEDyZmaogyTvwIoWKg:cdn.shopify.com/s/files/1/0559/1970/6265/products/1_f1b14fe3-3905-4217-b2a7-2311fb62a2b5.jpg%3Fv%3D1669816302&amp;usqp=CAU" alt="Buy 50 kg Load cell Online in India | Robocraze"/>
which work much much better, as the force is being distrubuted down intot he metal plate, rather than these brass standoffs. then i used HX711 Loadcell Amplifiers that were distributed by Sparkfun. these work great adn were really easy to use. 

# Other Details

## Buying Guide
### Base
1) [LoadSensors](https://www.amazon.com/Weighing-Resistance-Half-Bridge-Amplifier-Arduino/dp/B097T3SX6W/ref=sr_1_4?keywords=load+sensors&qid=1670266200&sr=8-4) (Need) $12.99
    - those come with HX711s which might work for you but they arent able to be put into 80 Hz Mode so they might appear slow to some people. they come extra at no cost so its no problem.
2) [HX711](https://www.sparkfun.com/products/13879) (Need) X2 $10.95
3) [M4 Bolts](https://www.amazon.com/HELIFOUNER-Pieces-Button-Washers-Stainless/dp/B09GRHHXT5/ref=sr_1_3?keywords=m4+bolts&qid=1670266352&sr=8-3) (Need) $11.99
4) [Hose O-Ring](https://www.amazon.com/PAGOW-Rings-Pressure-Connect-Coupler/dp/B07RZBHSNG/ref=sr_1_8?crid=1SM57JTUYDIQQ&keywords=hose+O+ring&qid=1670266422&sprefix=hose+o+rin%2Caps%2C160&sr=8-8) (Optional But Highly Recomended) $6.99
5) [Teensy Board 4.0](https://www.pjrc.com/store/teensy40.html) (Need This Or Pro Micro) $23.8
    - the alternative to this is the arduino pro micro as they are much much easier to get, and to distribute. they are cheaper and look better for most people but what i found is the faster teensy 4.0 performs better as it can update the inputs faster. meaning the stick doesnt have a delay. arduinos can be bought [here](https://www.amazon.com/OSOYOO-ATmega32U4-arduino-Leonardo-ATmega328/dp/B012FOV17O) if needed.
6) [PCB Prototype Boards](https://www.amazon.com/Smraza-Soldering-Electronic-Compatible-Prototype/dp/B07NM68FXK/ref=sr_1_5?crid=2M63TGCY4MVN4&keywords=pcb+prototype+board&qid=1670426995&sprefix=pcb+prototype+boar%2Caps%2C146&sr=8-5) (Optional. Makes things more neat) $12.99
7) [M4 T-Nuts](https://www.amazon.com/SpzcdZa-Sliding-Fastener-Aluminum-Extrusion/dp/B08145QK3B/ref=sr_1_3?crid=3V0IXE3Q942RF&keywords=m4+t+nuts&qid=1670427050&sprefix=m4+t+nuts%2Caps%2C244&sr=8-3) (Need) $6.99
8) [2020 Extrusion](https://www.amazon.com/European-Standard-Anodized-Aluminum-Extrusion/dp/B0B2MS2WDR/ref=sr_1_7?crid=3UK59P2XWAEUK&keywords=2020+extrusion&qid=1670427099&sprefix=2020+extrusion%2Caps%2C178&sr=8-7) (Need) $7.99
9) [Aluminum Plate](https://www.amazon.com/Aluminum-Thickness-Double-Sided-Attached-Plates/dp/B08P16R87J/ref=sr_1_3?crid=3BVQB6U8EU4HD&keywords=aluminum+plate+6x6&qid=1670427246&sprefix=aluminum+plate+6x6%2Caps%2C131&sr=8-3) (Optional) $17.99
#### Max Price for the base is $116.64
   - Buying Everything on this list
#### Lowest Price for the base is $85.6
   - Buying only the "Need" Items
### Grip
1) [M3 Bolts](https://www.amazon.com/DYWISHKEY-Pieces-Socket-Screws-Wrench/dp/B07VRC5RJ8/ref=sr_1_4?crid=3M73TY7A1YCY&keywords=m3&qid=1670427689&sprefix=m%2Caps%2C331&sr=8-4) (Need) $12.69
2) [PCBS] $22.42
3) Ball Point Pen Spring (Optional)
4) [4.3x6.6mm Tact Switches](https://www.amazon.com/4-3mm-Momentary-Tactile-Button-Switch/dp/B0796QL57S/ref=sr_1_3?crid=29V90019VENFP&keywords=m34.36x6+tact+switches&qid=1670427768&sprefix=m34.36x6+tact+switches%2Caps%2C114&sr=8-3) (Need) $6.99
5) [M4 Bolts](https://www.amazon.com/HELIFOUNER-Pieces-Button-Washers-Stainless/dp/B09GRHHXT5/ref=sr_1_5?crid=1Z96RJ9RP1Q16&keywords=M4+Bolts&qid=1670427799&sprefix=m4+bolt%2Caps%2C148&sr=8-5) (Need) $11.99

#### Max Price For the Grip is $54.09

## Total Cost for it all is $170
  - this is relatively expensive if you just look at it, but that compared to its [Competitor](https://realsimulator.com/fssb-r3-lighting/) which costs nearly $600 and not even coming with a grip. this is pretty good. to buy a manufactured version of this design, would cost you nearly $850 in total for the base and grip.
    
# Code
- the code will be placed in the top of the Repo, i will attatch multiple files. look here to refrence what code you need
    - HX711_Basic_Example: this is used to test if your loadcells are registering. i used this to test my wiring before i permanently attatched everything. all you need for this sketch is to change the pins for what you attatched your hx711 to. if your HX711 Data is to pin 2 and CLK is to pin 3 then set those variables in the sketch. after this you can load it onto the teensy board, and see in the serial print the numbers. their gonna be in the thousands, its just a raw number so dont worry about the values. this is just to test that the numbers show up or move. if the serial moniter shows "HX711 Not Found" then you have a wiring issue. make sure the hx711 VCC and VDD are bridged on the hx711 and that the hx711 is getting 5v not 3v.
    - HX711_Joystick_Example: this is to test that your stick is registering as a joystick. make sure your teensy board is set to "Keyboard Mouse Serial Joystick" in the tools menu, and upload the sketch, making sure the pins are corresponding to each Data And CLK on the HX711s. then in the bottom of your computer search in the search bar "joy.cpl" from there you should be able to see the "keyboard Mouse Serial Joystick" in that menu. click on it, and select properties. then Calibrate. follow that manu and you should be able to see the joysticks registering.
    - Grip_Mux_Example: this sketch is to test the multiplexors, and that their working. wire the multiplexors up to the board, and change the values in the sketch so that they are correctly corresponding. then upload the sketch and you should see in the serial moniter a ton of Zeros. when you press one of the button, a 1 will switch into the place of the Zeros. test that this happens for every switch. once this is done, your stick is fully functional. you just have to peice it together
    - Joy_Final: this is the final sketch combining all of the Multiplexors and the HX711s. 
## Sources
- [Really Cool Visualization of what im doing](https://www.youtube.com/watch?v=0AL7oeH1EnU)
- [Very First Design i Based off of](https://forum.dcs.world/topic/289020-force-sense-stickdiy/)
- [F-16 3D Print By Jflyer81 Thingiverse](https://www.thingiverse.com/thing:4544115)
- [F-16 3D Print With PCBS By bacon8tor](https://www.thingiverse.com/thing:4924037)
