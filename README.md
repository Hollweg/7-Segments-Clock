#7-Segments-Clock

##The purpose

This is a 7 Segments Clock project, developed from zero, using authoral **hardware and software**. The clock marks **hours, minutes and seconds, using an ATMEGA328P microcontroller**, from ATMEL. The 7 Segments Clock was developed as a personal project and it was built on an **universal soldering breadboard**, according with Proteus folder schematics inside this project. During this README I'll explain how to develop your own 7 Segments Clock. :)

Here is an image about the project final result:

![Imgur](http://i.imgur.com/BjCu3v1.jpg) 

##Utility

The code was developed specifically to **ATMEGA328P microcontroller** using **ATMEL Studio IDE**. However, if some changes were made, mainly in initialization, configuration and some registers, **the project can be adapted to other microcontroller families, from other manufacturers** and IDEs. The idea to build a 7 Segments Clock is the same, but some things will change, like timer registers, I/O and ADC configurations.

##How it works?

The clock starts marking time from 00:00, in the moment that it's powered. **To adjust time until desired hour and minute you have to use the circuit push buttons** (in the right side of microcontroller). We have two push buttons, one to increment hours and another one to increment minutes. 

**This project algorithm marks hours, minutes and seconds, but it was built only with 4 displays, marking hours and minutes. However, if you want to build a full clock (using seconds markers too) it is only necessary to add two 7 Segments displays and connect it on 2 non used microcontroller ports.**

**The code was developed with the full clock logic, but when I burn it to microcontroller I comment one of markers (seconds, for example - "CalculateSeconds" function) and it marks Hours + Minutes. In the other hand, if I want to see Minutes + Seconds you need to comment "CalculateHours" function and it will display Minutes + Seconds.**

In the moment that the circuit is **de-energized**, the clock **loses its reference** and the current time because it does not have a memory hardware implemented in circuit.

However, if you need to store the **last marked time, even with the circuit de-energized, you can use a RTC hardware and only read its time variables, than display it in the 7 Segments array.** In other way, according to what I said during Binary Clock project (here in github.com/hollwe/binary-clock), I think that this kind of "upgrade" is not interesting to this kind of project because it **makes you miss the essence of build a real clock, since thinking in clock logic, counters, timers, until software otimization and implementation.**

*- The .c file contains the developed code in C.* </br>
*- The .asm file contains the code translated to assembly* </br>
*- The .hex file is the ready to burn file, containing the code in hexadecimal language.* </br>
*- The other files are configuration files, created by compiler.* </br>
*- Inside /Proteus folder it is the project hardware schematic* </br>

Below there is an image of the project hardware described in Proteus (using four 7 Segments Display). 

![Imgur](http://i.imgur.com/T5LGVun.png)

You can acess the hardware files in the project folder /Proteus.

##Using four 7-Segments Displays

You can see in the final result project image that I used a **7 Segments Display array** (model CAI5461AH), **already multiplexed and easier to be used.**

However, you can develop the same project **using four 7 Segments Displays.**  </br>
Before use the 7 Segments Array I tested the circuit and the code in a breadboard with four 7 Segments Displays. </br>
The only difference is that **you need to multiplex the pins manually and connect a resistor between microcontroller port and display control pins** (there is 2 control pins (shared) by display). </br>
**In the other hand, using the 7 Segments Display array it is not necessary to connect the display resistors because they are considered in its internal circuit.**

Below there is an image of a single 7 Segments Display schematic pins:

![Imgur](http://i.imgur.com/6OF4lW5.gif)

![Imgur](http://i.imgur.com/uOHj8T3.gif)

Here you can see four 7 Segments Display multiplexed .gif:

[Imgur](http://i.imgur.com/3Io3QAH.gifv)

**In the image you can see that it was used transistors to enable each display control pin, but this is not needed.** </br>
I developed the **switch system by software.** Every time when a display is enabled (5V - common cathode), the microcontroller sends to the other display control pins 0V, assuring that we will have only one display active at a time. 

And here is an image of the circuit built using four 7 Segments Display, as commented (the code burned for an array or separated displays is exactly the same).

![Imgur](http://i.imgur.com/Zn7HhOp.jpg)

There is not necessary to build your own hardware to see the project working, **if you want to build it on an Arduino UNO board** (or another Arduino board that uses ATMEGA328P), **you need to burn the code to ATMEGA328P via ATMEL Studio** (you can see <a href="https://www.embarcados.com.br/atmel-studio/">this link</a> to configure Atmel Studio to burn code for Arduino) **and connect the display and buttons directly in Arduino I/O pins.**

**Below, I described the hardware connections to make it easy to build the project. Take a look. :)**

**7 Segments LEDs:**

Segment a - ATMEGA328P PD2 - Arduino Uno Digital pin 2 </br>
Segment b - ATMEGA328P PD3 - Arduino Uno Digital pin 3 </br>
Segment c - ATMEGA328P PD4 - Arduino Uno Digital pin 4 </br>
Segment d - ATMEGA328P PD5 - Arduino Uno Digital pin 5 </br>
Segment e - ATMEGA328P PD6 - Arduino Uno Digital pin 6 </br>
Segment f - ATMEGA328P PD7 - Arduino Uno Digital pin 7 </br>
Segment g - ATMEGA328P PB0 - Arduino Uno Digital pin 8 </br>
Minutes right display control - ATMEGA328P PB2 - Arduino Uno Digital pin 10 </br>
Minutes left display control - ATMEGA328P PB3 - Arduino Uno Digital pin 11 </br>
Hours right display control - ATMEGA328P PB4 - Arduino Uno Digital pin 12 </br>
Hours left display control - ATMEGA328P PB5 - Arduino Uno Digital pin 13 </br>

**Push Buttons:**

Reset - ATMEGA328P PC6 - Arduino UNO Reset pin </br>
Minutes increment - ATMEGA328P PC1 - Arduino UNO Analog Input 1 (take care: Input pin 1, not Input pin 0) </br>
Hours increment - ATMEGA328P PC2 - Arduino UNO Analog Input 2 </br>

**Obs.1**: If you use four 7 Segments Display all the 7 Segments LEDs are connected together. </br>
**Obs.2**: If you use four 7 Segments Display, every display needs its own input resistor (~~270 ohms --- ~~1k ohms). </br>
In addition, the control pins must be connected in its two COM pins. </br>
**Obs.3**: Be careful with the type of 7 Segments Display you'll be using. </br>
There are two different types: Common Anode and Common Cathode. </br>
Common Cathode has its control pin ON using HIGH (5V) logical signal. </br> 
Common Anode has its control pin ON using LOW (0V) logical signal. </br>

##Which was used in project?

**List of materials**:

1. 1 x ATMEGA328P microcontroller <br>
2. 1 x 28 pins header</br>
3. 3 x Push button </br>
4. 3 x Resistor 1k ohm (+4 if you use four 7 Segments Display) </br>
5. 1 x 16MHz Crystal  </br>
6. 2 x 22pF Capacitors </br>
7. 1 x 100nF Capacitors </br>
8. 1 x 7 Segments Display Array </br>
9. 1 x Female P4 Jack </br>
10. 1 x 10x5cm Universal Soldering Board </br>

##Circuit Voltage 

The developed circuit is energized with 5V. </br>
You can adapt a simple 9V battery + 7805 voltage regulator or connect directly an smartphone charger to a P4 jack. 

**How to do it?**

**Step 1:** Take a 5V power source and cut the USB cable (assuming that its does not have a P4 jack), letting only 2 pins available: VCC and GND (the only ones you'll need). </br>
**Step 2:** Connect VCC and GND directly into P4 jack. (be careful with the polarity)

Your power suplly is ready. </br>
There is below an image of the power supply I used:

![Imgur](http://i.imgur.com/477PfSB.jpg) </br>

Finally, there is an image of the circuit working very well:

![Imgur](http://i.imgur.com/myghT7r.jpg)

##Copyrigths

**The project can be reproduced without any problems.** </br>
However, I only ask you to **keep author credits.** :)


Enjoy!

Hollweg

