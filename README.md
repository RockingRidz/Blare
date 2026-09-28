Blare
Blare is a coustom designed and planned alarm clock built by Me with the help of HackClub Nasa

What it does
Blare is a standalone alarm clock built with many components made to get you up in creativity. It has many switches and TFT diplay built into the 3D case.

Hardware and PCB ![PCB SCHM](images/Schematic)
I designed the PCB from scratch around an Seedx microcontroller module. The board includes:

Coustom copper wiring within the pcb.

Four push buttons for setting the time, toggling the alarm, and navigating menus.

A piezo buzzer for the alarm sound.

An TfT display connector.

Four mounting holes near the corners to attach the board securely inside the case.
![PCB Layout](images/PCB)
Enclosure
The case was designed in Onshape to house the PCB, screen, and buttons 

Design: It uses a two-part split enclosure (a base and a lid) with M3 screw posts for assembly.

Openings: Cutouts on the front for the screen, side vents for airflow and buzzer sound, and a back slot for USB power.

Firmware
The firmware is written in C++ using the Arduino framework. It drives the Tft display, tracks time, listens for button presses to adjust the time/alarm, and triggers the buzzer when the alarm goes off.

Required Libraries:

Adafruit_GFX

Adafruit_ST7789

SPI


![PCB Layout](images/SCHM)


Current State
The PCB layout is finished, the Onshape case model is split and ready for printing, and the core alarm clock code is ready for testing on hardware.
images/PCB
