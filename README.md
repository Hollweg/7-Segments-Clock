#7-Segments-Clock

##The purpose

This is a 7 Segments Clock project, developed from zero, using authoral **hardware and software**. The clock marks hours, minutes and seconds, using an ATMEGA328P microcontroller, from ATMEL. The 7 Segments Clock was developed as a personal project and it was built on an universal soldering breadboard, according with Proteus folder schematics inside this project.

##Utility

The code was developed specifically to **ATMEGA328P microcontroller** using **ATMEL Studio IDE**. However, if some changes were made, mainly in initialization, configuration and some registers, **the project can be adapted to other microcontroller families, from other manufacturers** and IDEs. The idea to build a 7 Segments Clock is the same, but some things will change, like timer registers, I/O and ADC configurations.

During project development it were implemented some functions and code definitions that enhance flux code and let the code better to be readed. I will cover some of this implementeded methods along the explanation file. :)

##How it works?

The clock starts marking time from 00:00, in the moment that it's powered. **To adjust time until desired hour and minute you have to use the circuit push buttons** (in the right side of microcontroller). We have two push buttons, one to increment hours and another to increment minutes. This project marks hours, minutes and seconds, but it was built only with 4 displays, marking hours and minutes. However, if you want to build a full clock (using seconds markers too) it is only necessary to add two 7 Segments displays and connect it on 2 non used microcontroller ports. 

**The code was developed with the full clock logic, but when I burn it to microcontroller I comment one of markers (seconds, for example - "CalculateSeconds" function) and it marks Hours + Minutes. In the other hand, if I want to see Minutes + Seconds you need to comment "CalculateHours" function and it will display Minutes + Seconds.**

In the moment that the circuit is **de-energized**, the clock **loses its reference** and the actual time because it does not have a memory hardware implemented in circuit.

However, if you need to store the last marked time, even with the circuit de-energized, you can use a RTC hardware and only read its time variables, than display it in the 7 Segments array. In other way, according to what I said during Binary Clock project (that I developed and its here in github.com/hollwe/binary-clock), I think that this kind of "upgrade" is not interesting to this kind of project because it makes you miss the essence of build a real clock, since thinking in clock logic, counters, timers, until software otimization and implementation.

*- The .c file contains the developed code in C.* </br>
*- The .asm file contains the code translated to assembly* </br>
*- The .hex file is the ready to burn file, containing the code in hexadecimal language.* </br>
*- The other files are configuration files, created by compiler.* </br>
*- Inside /Proteus folder it is the project hardware schematic* </br>

Below there is an image of the project hardware described in Proteus. 

**Insert image**

##Using four 7-Segments Displays

In this project you can see that I used a 7 Segments Display array (model XXXXXXX), already multiplexed and easier to be used.
However, you can develop the same project using four 7 Segments Displays. 
The only difference is that you need to multiplex the pins manually and connect a resistor between microcontroller port and display control pins (there is 2 control pins by display and each one must have its own input resistor)
In the other hand, using the 7 Segments Display array it is not necessary to connect the display resistors because they are considered in the array internal circuit.

Below there is an image of a single 7 Segments Display schematic pins:

**Insert Image**

Here you can see how to connect the four 7 Segments Display multiplexed:

**Insert Image**

And here is an image of the circuit built using four 7 Segments Display, as commented (the code burned is exactly the same):

**Insert Image**

There is not needed to build your own hardware to see the project working, if you want to build it on an Arduino UNO board, for example, you need to burn the code using ATMEGA328P (you can see this link to configure the IDE to burn code for Arduino) and connect the display and buttons directly in Arduino I/O pins.
Below, I described the hardware connections to make it easy to build the project, take a look. :) 

7 Segments LEDs:

a -
b -
c -
d -
e -
f -
g -
Minutes right display control -
Minutes left display control - 
Hours right display control - 
Hours left display control - 

Push Buttons:

Reset - 
Minutes increment - 
Hours increment - 

##Which was used in project?

**List of materials**:

1. 1 x ATMEGA328P microcontroller <br>
2. 1 x 28 pins header</br>
3. 3 x Push button </br>
4. 3 x Resistor 1k ohm </br>
5. 1 x 16MHz Crystal  </br>
6. 2 x 22pF Capacitors </br>
7. 1 x 100nF Capacitors </br>
8. 1 x 7 Segments Display Array </br>
9. 1 x Female P4 Jack </br>
10. 1 x 10x5cm Universal Soldering Board </br>

Below, there is an image of the project built in an universal soldering breadboard.

**Insert Image**

##Circuit Voltage 

The developed circuit is energized with 5V. 
You can adapt a simple 9V battery + 7805 voltage regulator or connect directyle a smartphone charger to the P4 jack (I did this). 

**How to do it?**

1 Step: Take an USB cable and cut the cable, letting only 2 pins available: VCC and GND.
2 Step: I took an smartphone power source that is connected with an USB cable (I recommend this type) or you need to cut the cable of the power source (maybe it will generate problems to charge your phone inthe future :P)
3 Step: Connect VCC and GND in a P4 jack.

Your power suplly is ready.
There is below two images of the power supply:

**Insert Image**
**Insert Image**

##Copyrigths

**The project can be reproduced without any problems.** </br>
However, I only ask you to **keep author credits.** :)


Enjoy!

Hollweg

