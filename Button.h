#ifndef Button_h
#define Button_h

/**
 *  @file		Button.h
 *  Project		axefx.de MIDI Borad
 *	@brief		Header-File for single class representing one Button
 *	@version	1.0.0
 *  @author		Bastian Buehrig
 *	@date		05/11/13
 *  license		GPL axefx.de - 2013
 */
 
 

// ==== Setup-File: Edit for you own MIDI-Board
#include "setup.h"

// ==== Arduino-Standard-Lib
#include <Arduino.h>

// ==== 3rd Party Libraries
#include <MIDI.h>              // Arduino-MIDI-Library




class Button {
  public:
    // Class Variable
    static byte PRGNO;       // Actual Program Number
    static byte PRGNO_LED;   // Actual LED-Pin for PC-Button    

    // Public Attributes
    byte _btnPin;            // Pin-Number for Buttons
    byte _ledPin;            // Pin-Number for Button Status-LED
    String _btnFunction;     // Button-Function: PC - Program Change    -    CC - Controller Change
    byte _ctrlNo;            // Controller-Number or PC-Number
    byte _valHigh;           // CC-High-Value
    byte _valLow;            // CC-Low-Value
    byte _initCtrlState;     // Contoller-State at the beginning

    // Constructors
    Button();
    Button(byte btnPin, byte ledPin, String btnFunction, byte ctrlNo, byte valHigh, byte valLow, byte initCtrlState);
    
    // Destructors
    ~Button();    
    
    // Public functions
    void checkState();
    
  
  private:
    // Private Attributes
    byte _actState;          // Actual Button-State:  LOW - unpressed    HIGH - pressed
    byte _ctrlState;         // Controller State:     LOW - unset        HIGH - set
    
    // Private Functions
    void sendCC(byte state, byte value);
    void sendPC(byte prgNo);

};



#endif
