# simon-says
my fourth project for fallout

**what is this project**
- test out your memory with this memory game!
- this project tests your sequence memory, in having a sequence that increases in length after everytime you get it right
- see how far you can go! how many can you remember in a row

**how to use it**
- print out the pcb and the case
- put them together (using the screws as described in the BOM)
- then try and see how many you can remember!
- for more information on how it works, see the `how it works` part!

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
<img width="1162" height="925" alt="image" src="https://github.com/user-attachments/assets/e7aa2284-9b87-4625-9c91-26126afe8715" />

the footprint:
<img width="350" height="490" alt="image" src="https://github.com/user-attachments/assets/f364a5a7-b056-40db-be11-870c7550b49e" />

the 3d model:
<img width="629" height="702" alt="image" src="https://github.com/user-attachments/assets/9ebf9c21-01b6-4ee2-b978-3aae74b8c959" />

the exploded view:
<img width="607" height="694" alt="image" src="https://github.com/user-attachments/assets/7d20d027-4b69-4b98-862a-eb666743f60f" />

zine:
<img width="618" height="873" alt="image" src="https://github.com/user-attachments/assets/6d642466-0400-459b-95b7-0a0a0d30e946" />

bom:
<img width="793" height="440" alt="image" src="https://github.com/user-attachments/assets/804e4ecd-34b8-4260-aeae-57d8eafcf0f6" />
total project cost: $36.28 (however will already have components spare from other projects like cherry mx switches, key caps)






