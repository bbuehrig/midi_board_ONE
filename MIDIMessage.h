#ifndef MIDIMessage_h
#define MIDIMessage_h

/**
 *  @file		Button.h
 *  Project		axefx.de MIDI Borad
 *	@brief		Header-File for single class representing one Button
 *	@version	1.0.0
 *  @author		Bastian Buehrig
 *	@date		14/11/13
 *  license		GPL axefx.de - 2013
 */

// ==== Arduino-Standard-Lib
#include <Arduino.h>

// ==== 3rd Party Libraries
#include <MIDI.h>              // Arduino-MIDI-Library


class MIDIMessage {
public:
  // Class Variable

  // Public Attributes
  byte _ctrlState;                 // Controller State:     LOW - unset        HIGH - set
  boolean _isMaster;        // Master-Messages will control the LED
  byte _midiChannel;       // MIDI-Channel for MIDI-Message

  String _btnFunction;     // Button-Function: PC - Program Change    -    CCT - Controller Change (Toggle)    -    CCS - Controller Change Send


  // Constructors
  MIDIMessage();
  MIDIMessage(byte midiChannel, String btnFunction, byte ctrlNo, byte valHigh, byte valLow, byte initCtrlState, boolean isMaster);

  // Destructors
  ~MIDIMessage();    

  // Public functions
  boolean sendMIDI();


private:
  // Private Attributes
  byte _ctrlNo;            // Controller-Number or PC-Number
  byte _valHigh;           // CC-High-Value
  byte _valLow;            // CC-Low-Value
  byte _initCtrlState;     // Contoller-State at the beginning


  // Private Functions
  void sendCC(byte value);
  void sendPC();
};



#endif






