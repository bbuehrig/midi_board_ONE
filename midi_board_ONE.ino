/**
 *  @file		midi_board_ONE.ino
 *  Project		axefx.de MIDI Borad
 *	@brief		MIDI-Board Main Program
 *	@version	1.0.2
 *  @author		Bastian Buehrig
 *	@date		14/11/13
 *  license		GPL axefx.de - 2013
 */


/****************************************************
 **
 **  Uses Arduino-MIDI-Library (v3.2)
 **  http://playground.arduino.cc/Main/MIDILibrary
 **  http://sourceforge.net/projects/arduinomidilib/
 **
 *****************************************************/

/**
 *
 *  INCLUDES
 *
 **/

//#include <Arduino.h>


// ==== Button-Class
#include "Button.h"


// ==== 3rd Party Libraries
#include <MIDI.h>              // Arduino-MIDI-Library



// ============== SETUP ===============================

/** MIDI-Channel-Number for sending the MIDI-Messages */
#define MIDI_CHANNEL_GMAJOR           1           // MIDI-Channel for sending Commands



// ============== Button-Definitions: =================
//
Button buttons[] = {
  //    Button-Pin   LED-Pin  
  Button(    8,       28 ),
  Button(    9,       29 ),
  Button(   10,       30 ),
  Button(   11,       31 ),
  Button(   12,       32 ),
  Button(   13,       33 ),
  Button(   14,       34 ),
  Button(   15,       35 ),    
};


// ================ Definitions: MIDI-Messages to all defined Buttons ====================
//               MIDI-Ch.     Funkt.  CC/PC   High  Low,  init.Ctrl.State      Master

// Button 00
MIDIMessage messagesButton00[] = {
  MIDIMessage ( MIDI_CHANNEL_GMAJOR,   "PC",      0,        0,     0,        LOW,            false  ),
  MIDIMessage ( MIDI_CHANNEL_GMAJOR,   "CCT",    10,      127,     0,        HIGH,           true )
  };


  // Button 01
MIDIMessage messagesButton01[] = {
  MIDIMessage ( MIDI_CHANNEL_GMAJOR,   "PC",      1,        0,     0,        LOW,            true  ),
  MIDIMessage ( MIDI_CHANNEL_GMAJOR,   "CCT",    11,      127,     0,        HIGH,           false )
  };

  // Button 02
MIDIMessage messagesButton02[] = {
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "PC",       2,         0,     0,        LOW,           true  )
  };

  // Button 03
MIDIMessage messagesButton03[] = {
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCT",      10,       127,     0,        LOW,           true  )     // Controller Toggle (Delay on/off)
  };

  // Button 04
MIDIMessage messagesButton04[] = {
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     20,         1,     0,        LOW,           true  )      // Calling Scene 1 (no Toggle!)
  };

  // Button 05
MIDIMessage messagesButton05[] = {
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     20,         2,     0,        LOW,           false )      // Calling Scene 2 (no Toggle!)
  };

  // Button 06
  // Calling Amp1-X (no Toggle!)
MIDIMessage messagesButton06[] = {
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     22,       127,     0,        HIGH,          true  ),      //    Amp 1 activate
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     23,         0,     0,        HIGH,          false ),      //    Amp 2 deactivate
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     32,         0,     0,        HIGH,          false )      //    Amp 1 X
  };

  // Button 07
  // Calling Amp2-Y (no Toggle!)
MIDIMessage messagesButton07[] = {
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     23,       127,     0,        HIGH,          true  ),      //    Amp 2 activate
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     22,         0,     0,        HIGH,          false ),      //    Amp 1 deactivate
  MIDIMessage( MIDI_CHANNEL_GMAJOR,   "CCS",     33,       127,     0,        HIGH,          false )      //    Amp 2 Y
  };

  // =============== Defining LED-Groups ===================
  //
byte groupPresets[] = {
  28, 29, 30
};


byte groupScenes[] = {
  32, 33
};


byte groupAmps[] = {
  34, 35
};





// ====
void setup() {
  // MIDI-Initialising
  MIDI.begin();

  // Add MIDI-Messages to the specific Button
  buttons[0].addMessages(messagesButton00, sizeof(messagesButton00) );
  buttons[1].addMessages(messagesButton01, sizeof(messagesButton01) );  
  buttons[2].addMessages(messagesButton02, sizeof(messagesButton02) );
  buttons[3].addMessages(messagesButton03, sizeof(messagesButton03) );
  buttons[4].addMessages(messagesButton04, sizeof(messagesButton04) );
  buttons[5].addMessages(messagesButton05, sizeof(messagesButton05) );
  buttons[6].addMessages(messagesButton06, sizeof(messagesButton06) );
  buttons[7].addMessages(messagesButton07, sizeof(messagesButton07) );

  // Setting LED-Groups to Buttons if needed
  buttons[0].setLEDGroup(groupPresets, sizeof(groupPresets) );
  buttons[1].setLEDGroup(groupPresets, sizeof(groupPresets) );
  buttons[2].setLEDGroup(groupPresets, sizeof(groupPresets) );

  buttons[4].setLEDGroup(groupScenes, sizeof(groupScenes) );
  buttons[5].setLEDGroup(groupScenes, sizeof(groupScenes) );

  buttons[6].setLEDGroup(groupAmps, sizeof(groupAmps) );
  buttons[7].setLEDGroup(groupAmps, sizeof(groupAmps) );

}



void loop() {
  // Read Button-State und check for activation!
  for (byte btnNo=0; btnNo < sizeof(buttons) / sizeof(Button); btnNo++) {
    buttons[btnNo].checkState();
  }

  // Read all Expression-Pedals
  // TODO
}  





