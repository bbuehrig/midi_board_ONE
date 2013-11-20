/**
 *  @file		Button.cpp
 *  Project		axefx.de MIDI Borad
 *	@brief		single class representing one Button
 *	@version	1.0.3
 *  @author		Bastian Buehrig
 *	@date		14/11/13
 *  license		GPL axefx.de - 2013
 */

#include "Button.h"



/**
 * Standard-Constructor
 *
 */
Button::Button() {

}



/**
 * Constructor for Button-Initialization
 *
 * @param btnPin          Pin-Number where the switch is connected
 * @param ledPin          Pin-Number where the LED is connected
 */
Button::Button(byte    btnPin,           /** Pin-Number where the switch is connected */
byte    ledPin            /** Pin-Number where the LED is connected */
) {  

  // Setting instance-variables         
  _btnPin = btnPin;
  _ledPin = ledPin;

  // Initialise quantity of MIDI-Messages and LED-Groups
  _messagesQty = 0;
  _ledGroupQty = 0;


  // Set Pin-Mode für Switch and LED
  pinMode(_btnPin, INPUT_PULLUP);
  pinMode(_ledPin, OUTPUT);


  // Set initial-Button-State
  _actState = HIGH;

}



/**
 * Standard-Destructor
 *
 */
Button::~Button() {
}



/**
 * This method will called, to check Button-State and will
 * send a configured MIDI-Message. Depending on the
 * Button-Configuration will send a PC or CC Message
 *
 * @return    void
 */
void Button::checkState() {
  // Check if Button-State is different from the call before
  byte actState = digitalRead(_btnPin);

  if(_actState != actState) {
    // Button state was changed --> Do something!
    // Save aktcual Button State
    _actState = actState;


    if(actState == LOW) {    
      // Only do, if Button is pressed!
      //

      // First switch off all LEDs of the LED-Group!
      if(_ledGroupQty > 0 ) {
        for(byte i = 0; i < _ledGroupQty; i++) {
          Serial.println(_ledGroup[i]);
          digitalWrite(_ledGroup[i], LOW);
        }
      }


      // Iterate all MIDI-Messages
      for (byte i = 0; i < _messagesQty; i++) {  

        // Send MIDI-Messages
        if(_messages[i]._isMaster) {
          // It is a master-Button --> LED-Control!
          boolean rc = _messages[i].sendMIDI();

          // Checking LED-Status
          if(rc) {
            // LED on!
            digitalWrite(_ledPin, HIGH);

          } 
          else {
            // LED off!
            digitalWrite(_ledPin, LOW);

          };

        } 
        else {
          // Only a slave Button --> Send MIDI-Message and don't control any LED
          _messages[i].sendMIDI();
        }

      }
    }
  }

}



/**
 * This method will add an array of MIDI-Messages to the Button for Itereation.
 *
 * Button-Configuration will send a PC or CC Message
 *
 * @param      midiMessage[]    Array of MIDI-Messages
 * @param      messagesQty      size of the array to calculate quantity of array-elements
 */
void Button::addMessages(MIDIMessage midiMessage[], byte messagesQty) {
  // Set instance-variables
  _messages = midiMessage;
  _messagesQty = messagesQty / sizeof(MIDIMessage);
}

/**
 * This Method adds a full LED-Group to the actual Button
 * for disable the LEDS at any change
 *
 * @param ledGroup      Array of all LED-Pins
 * @param messagesQty   Size of the array to calculate quantity of the array-elements
 *
 */
void Button::setLEDGroup(byte ledGroup[], byte ledGroupQty) {
  // Set Instance-variables
  _ledGroup = ledGroup;
  _ledGroupQty = ledGroupQty / sizeof(byte);
}


