midi_board_ONE
==============


axefx.de Free MIDI-Board Project
--------------------------------
This Project was born in the axefx.de community. It is already in testing and planing status. For more informations visit forum-thread. All in German!! [DIY MIDI-Board](http://www.axefx.de/showthread.php/1040-DYI-MIDI-Fu%C3%9Fleiste-selber-baune)

The goal of the project will be an Ardurino-Based MIDI-Controller...

This first Version only sends pre-defined PC or CC Messages. The Buttons will become static MIDI-Program-Change-Numbers. There is no Bank-Switching known from other MIDI-Boards.


Requierements
-------------
This project requieres the installation of the Arduino-MIDI-Library. Visit [http://playground.arduino.cc/Main/MIDILibrary](http://playground.arduino.cc/Main/MIDILibrary) for downloading and installing this library.


Setup
-----
To Setup an configure your personal board, you have to modify some variables.

### setup.h
The file setup.h defines the most important global parameters. There are thre parameters to configure your base settings of your MIDI-Board:

* MAX_BUTTONS
	Here you define the numbers of switch-buttons on your board
* MIDI_CHANNEL
	MIDI-Channel-Number for sending your MIDI-Messages
* START_PROGRAM_NO
	This is the Preset/MIDI-Program-Number that will send by starting up your board


### Button-Definition
To define, what kind of messages the buttons will send, you have to go to the main file "midi_board_ONE.ino". At the moment you can find and change the button-definitions in this file. In the "setup()" function there are some lines like:

	buttons[0] = new Button(    3,       13,      "PC",    0,      0,     0,        LOW );
	buttons[1] = new Button(    4,       14,      "PC",    0,      0,     0,        LOW );
	buttons[2] = new Button(    5,       15,      "PC",    2,      0,     0,        LOW );
	buttons[3] = new Button(    6,       16,      "PC",    3,      0,     0,        LOW );
	buttons[4] = new Button(    7,       17,      "CC",   20,    127,     0,        LOW );
	buttons[5] = new Button(    8,       18,      "CC",   21,    127,     0,        LOW );
	buttons[6] = new Button(    9,       19,      "CC",   22,    127,     0,       HIGH );
	buttons[7] = new Button(   10,       20,      "CC",   23,    127,     0,       HIGH );

You have to add some lines, if you changed the MAX_BUTTONS variable!!!

One line represents one Button. The Attributes after "new Button" are:
1. Button-Pin, where your Button is connected on the Arduino-Board
2. LED-Pin, where your Status-LED is connected on the Arduino-Board
3. Button-Function: PC - Program Change  CC - Controller Change
4. First Byte, that will be send
	- If it is a PC-Button, here you have to put your Programm-Number.
	- If it is a CC-Button, here you have to put you Controller-Number.
5. High-Value, that will be send at a CC-Message depending on the Button-State (Activate)
6. Low-Value, that will be send at a CC-Message depending on the Button-State (Deactivate)
7. Initialising CC-Value. You can control, is one controller activated/deactivated at startup


