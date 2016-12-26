#7-Segments-Clock

##The purpose

This is a 7 Segments Clock project, developed from zero, using authoral **hardware and software**. The clock counts hours, minutes and seconds, using an ATMEGA328P microcontroller, from ATMEL. The 7 Segments Clock was developed as a personal project and it was mounted on an universal soldering board, according with Proteus folder schematics (that I developed).

##Utility

The code was developed specifically to **ATMEGA328P microcontroller** using **ATMEL Studio IDE**. However, if some changes were made, mainly in initialization, configuration and some registers, **the project can be adapted to other microcontroller families, from other manufacturers** and IDEs.

During project development it were developed some functions and code definitions that enhance flux code and let the code better to be readed. I will cover some of this methods along the file. :)

##How it works?

The clock starts marking hour from 00:00, in the moment that it's powered. **To adjust time until desired hour and minute you have to use the board push buttons** (in the right side of microcontroller). In the moment that the circuit is **de-energized**, the clock **loses its reference** and the actual time because it does not have a memory hardware implemented in board.

However, if you need to store the last marked hour, even with the circuit de-energized, you can use a RTC hardware, and only read its time variables, than display it in the 7 Segments array. In other way, according to what I said during Binary Clock project (that I developed and its here in Github), I think that this kind of "upgrade" is not nice because it makes you miss the essence of build a real clock, since thinking in clock logic, counters, until software otimization and implementation.

*- The .c file contains the developed code in C.* </br>
*- The .asm file contains the code translated to assembly* </br>
*- The .hex file is the ready to burn file, containing the code in hexadecimal language.* </br>
*- The other files are configuration files, created by compiler.* </br>
*- Inside /Proteus folder it is the project hardware schematic* </br>

Below there is an imagem of the project hardware described in Proteus. 

**Insert image**

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

Below, there is an image of the circuit mounted in an universal soldering board.

**Insert Image**

##Copyrigths

**The project can be reproduced without any problems.** </br>
However, I only ask you to **keep author credits.** :)


Enjoy!

Hollweg

