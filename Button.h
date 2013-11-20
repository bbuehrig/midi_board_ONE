#ifndef Button_h
#define Button_h

/**
 *  @file		Button.h
 *  Project		axefx.de MIDI Borad
 *	@brief		Header-File for single class representing one Button
 *	@version	1.0.3
 *  @author		Bastian Buehrig
 *	@date		14/11/13
 *  license		GPL axefx.de - 2013
 */

// ==== Project Libraries
#include "MIDIMessage.h"






class Button {
  public:
    // Class Variable


    // Public Attributes


    // Constructors
    Button();
    Button(byte btnPin, byte ledPin);
    
    // Destructors
    ~Button();    
    
    // Public functions
    void checkState();
    void addMessages(MIDIMessage midiMessages[], byte messagesQty);
    void setLEDGroup(byte ledGroup[], byte ledGroupQty);
    
  
  private:
    // Private Attributes
    byte _actState;               // Actual Button-State:  LOW - unpressed    HIGH - pressed

    byte _btnPin;                 // Pin-Number for Buttons
    byte _ledPin;                 // Pin-Number for Button Status-LED
    byte _messagesQty;            // Quantity of Midi Messages
    byte _ledGroupQty;
    
    
    MIDIMessage *_messages;
    byte *_ledGroup;
    
    boolean status;
    // Private Functions


};



#endif




