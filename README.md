# simon-says
my fourth project for fallout

**what is this project**
- test out your memory with this memory game!
- this project tests your sequence memory, in having a sequence that increases in length after everytime you get it right
- see how far you can go! how many can you remember in a row

**assembly instructions**
- print out the pcb and the case, and purchase the components meantioned in the bom
- put the pcb in the case
- put on the lid. then attach the screws mentioned in the BOM to fix the pcb in place.
- flash the firmware to the xiao-esp32 through the arduino ide (via usb)
- keep it plugged into your computer, as that will be the power source!
- try and see how many you can remember!

**inspiration for the project**
- having played the sequence memory game on [human benchark](humanbenchmark.com), i wanted to have a physical version of this that i could play with!
- i thought it would be a good way to try and improve my memory as having it in physical form i think makes me more likely to use it.

**how it works**
- the project will show the seqence of keys 1 by 1, you simply copy these!
- see how many of these you can remember!
- if you have a high score, the project  will flash 3 times (this high score is stored on the permanent storage of esp-32 board. (using preferences.h)
- if you press the wrong key, then all leds will flash once, and the sequence will reset, (back to a seqeunce of length 1, then you have to memorize a new sequence)
- keep trying to beat the PB!

**how this project was made**
- case made using fusion360
- pcb made using kicad
- in the 3d model, the keycaps and cherry-switches were imported as step files from repos on github.

**screenshots**
the schematic:

<img width="898" height="855" alt="image" src="https://github.com/user-attachments/assets/43baacfd-7cc2-4a74-997c-7bdac36b3f99" />


the footprint:

<img width="402" height="486" alt="image" src="https://github.com/user-attachments/assets/165b947b-28cb-428b-8ef0-23dc223c968e" />


the 3d model:

<img width="438" height="600" alt="image" src="https://github.com/user-attachments/assets/dbc02224-81fa-4518-9cb2-6f3bc92039c1" />



zine:

<img width="675" height="965" alt="image" src="https://github.com/user-attachments/assets/97feec5b-321c-41c0-903f-621c8a15289f" />

pcb 3d:

<img width="537" height="687" alt="image" src="https://github.com/user-attachments/assets/cfd0daa3-5020-479d-8468-4755c3a956ab" />




bom:

<img width="793" height="440" alt="image" src="https://github.com/user-attachments/assets/804e4ecd-34b8-4260-aeae-57d8eafcf0f6" />

total project cost: $28.53 (however will already have components spare from other projects like cherry mx switches, key caps)






