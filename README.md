Blare
Blare is a custom alarm clock I built for Hack Club's Stardance project. I wanted to make something practical that looks good on a desk and actually gets me out of bed in the morning.

What it does
At its core, Blare is a standalone desktop alarm clock. It runs off a custom PCB I designed in KiCad, sits inside a custom 3D-printed case, and uses a color display to show the time and alarm status.

Hardware and PCB ![PCB SCHM](images/Schematic)
I designed the PCB from scratch around an ESP32 microcontroller module. The board includes:

An ESP32 footprint to handle the clock logic.

Four push buttons for setting the time, toggling the alarm, and navigating menus.

A piezo buzzer for the alarm sound.

An ST7789 display connector.

Four mounting holes near the corners to attach the board securely inside the case.
![PCB Layout](images/PCB)
Enclosure
The case was designed in Onshape to house the PCB, screen, and buttons snugly.

Size: 95mm x 74mm x 35mm.

Design: It uses a two-part split enclosure (a base and a lid) with M3 screw posts for assembly.

Openings: Cutouts on the front for the screen, side vents for airflow and buzzer sound, and a back slot for USB power.

Firmware
The firmware is written in C++ using the Arduino framework. It drives the ST7789 display, tracks time, listens for button presses to adjust the time/alarm, and triggers the buzzer when the alarm goes off.

Required Libraries:

Adafruit_GFX

Adafruit_ST7789

SPI

Repository Structure
cad/: Onshape exports, including STL and STEP files for the lid and base.

firmware/: Arduino source code for the clock.

pcb/: KiCad schematics and board layout files.

production/: Manufacturing files like Gerber files and assembly drawings.
![PCB Layout](images/SCHM)


Current State
The PCB layout is finished, the Onshape case model is split and ready for printing, and the core alarm clock code is ready for testing on hardware.
images/PCB
