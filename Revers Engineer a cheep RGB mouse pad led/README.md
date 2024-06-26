## Story
We bought a mouse pad that has RGB included. After using some day the light has stoped working. we took out the circuit and checked the problem . the problem was the unknown micro controlar has broken down.
and without knowing the ic model or name we cannot replace it . so we have decided to modify the board because the light was functiong as expected. and for testing we found out the correct points to conncet our
test arduino nano.

The Connection is like:
```
VCC(1) ------------> 5(v)
VCC(2) ------------> 5(v)
R  ----------------> 9
G  ----------------> 10
B  ----------------> 11
```
In our case the ckt looks like :
<img src="https://github.com/ProgrammerNinja/Our-Random_Arduino_Projects/blob/main/Revers%20Engineer%20a%20cheep%20RGB%20mouse%20pad%20led/img/Project_img1.png">

And after some testing we figured out the color secquece of the RGB led.
```
The Analog Wirte Vale:
* 255, 0, 0     -----------> Cyan          * 0, 255, 0    -------------> Magenta
* 0, 0, 255     -----------> Yellow        * 0, 255, 255  -------------> Red
* 255, 0, 255   -----------> Green         * 255, 255, 0  -------------> Blue
* 255, 255, 255 -----------> OFF           * 0 , 0, 0     -------------> White
```

<img src="https://github.com/ProgrammerNinja/Our-Random_Arduino_Projects/blob/main/Revers%20Engineer%20a%20cheep%20RGB%20mouse%20pad%20led/img/Project_img5.png">


Next Steps:
- Buy ESP8266.
- Make Color select logic.
- Make web server.
- Design Web UI.
- Modify CKT.
- Build Enclosure.
