/**
 *  @file		Button.cpp
 *  Project		axefx.de MIDI Borad
 *	@brief		single class representing one Button
 *	@version	1.0.0
 *  @author		Bastian Buehrig
 *	@date		14/11/13
 *  license		GPL axefx.de - 2013
 */

#include "MIDIMessage.h"



 
/**
 * Standard-Constructor
 *
 */  
MIDIMessage::MIDIMessage() {

}



/**
 * Constructor for MIDIMessage-Initialization
 *
 * @param midiChannel    MIDI-Channel for this MIDI-Message
 * @param btnFunction     Function of the switch: 
                             * PC - Program Change
                             * CC - Controller Change
 * @param ctrlNo          Controller- or Program Number, which will be send
 * @param valHigh         High-Value, send at Controller-Activation
 * @param valLow          Low-Valuem send at Controller-Deaktivation
 * @param initCtrlState   Initial Controller State (Low/High)
 * @param isMaster        The last Master-Message will control the LED-Status
 */  
MIDIMessage::MIDIMessage(byte midiChannel, String btnFunction, byte ctrlNo, byte valHigh, byte valLow, byte initCtrlState, boolean isMaster) {  
  // Setting instance-variables  
  _midiChannel = midiChannel;
  _btnFunction = btnFunction;
  _ctrlNo = ctrlNo;
  _valHigh = valHigh;
  _valLow = valLow;
  _initCtrlState = initCtrlState;
  _isMaster = isMaster;
 // Serial.println(".... initialised");
}



/**
 * Standard-Destructor
 *
 */  
MIDIMessage::~MIDIMessage() {
}



/**
 * This Method starts sending the MIDI-Messages
 *
 */
boolean MIDIMessage::sendMIDI() {
  //
  // Program Change Function
  if(_btnFunction == "PC") {
    sendPC();
    
    return true;
  }


  // 
  // Controller Change Toggle Function
  if(_btnFunction == "CCT") {
    if(_ctrlState == LOW) {
  

      sendCC(_valHigh);
      _ctrlState = HIGH;
            
      return true;

    } else {
  
      sendCC(_valLow);
      _ctrlState = LOW;

      return false;
    
    }
  }
        
        
  //
  // Controller Change Single
  if(_btnFunction == "CCS") {
    sendCC(_valHigh);
    _ctrlState = HIGH;

    return true;
  }

}



/**
 * This Method sends a Controller-Message and will 
 * Activate/Deactivate concurrent LED.
 *
 * @params value    Controller-Value which will be sent
 *
 */  
void MIDIMessage::sendCC(byte value) {
  MIDI.sendControlChange(_ctrlNo, value, _midiChannel);
}



/**
 * This Method sends a Programm-Change-Message and will 
 * Activate/Deactivate concurrent LEDs.
 *
 */  
void MIDIMessage::sendPC() {
  MIDI.sendProgramChange(_ctrlNo, _midiChannel);
}
