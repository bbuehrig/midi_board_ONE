/*!
 *  @file		midi_board_ONE.ino
 *  Project		axefx.de MIDI Borad
 *	@brief		MIDI-Board Main Program
 *	@version	0.0.1
 *  @author		Bastian Buehrig
 *	@date		04/11/13
 *  license		GPL axefx.de - 2013
 */


/****************************************************
 **
 **  Uses Arduino-MIDI-Library (v3.2)
 **  http://playground.arduino.cc/Main/MIDILibrary
 **  http://sourceforge.net/projects/arduinomidilib/
 **
 *****************************************************/


// ==== 3rd Party Libraries
#include <MIDI.h>              // Arduino-MIDI-Library
#include "Button.h"



const int MAX_BUTTONS = 8;              // Numbers of Buttons of the board


Button *buttons[MAX_BUTTONS - 1];




void setup() {
  // Button-Definition
  buttons[0] = new Button(  3,  13,  "PC",  0,  0, 0);
  buttons[1] = new Button(  3,  13,  "PC",  0,  0, 0);
  buttons[2] = new Button(  5,  15,  "PC",  2,  0, 0);
  buttons[3] = new Button(  6,  16,  "PC",  3,  0, 0);
  buttons[4] = new Button(  7,  17,  "CC",  20,  127, 0);
  buttons[5] = new Button(  8,  18,  "CC",  21,  127, 0);
  buttons[6] = new Button(  9,  19,  "CC",  22,  127, 0);
  buttons[7] = new Button( 10,  20,  "CC",  23,  127, 0);
}



void loop() {
}

