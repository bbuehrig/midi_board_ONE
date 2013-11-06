/**
 *  @file		Button.cpp
 *  Project		axefx.de MIDI Borad
 *	@brief		single class representing one Button
 *	@version	1.0.1
 *  @author		Bastian Buehrig
 *	@date		06/11/13
 *  license		GPL axefx.de - 2013
 */

#include "Button.h"


/** Set Class-Variable to Init-Program-Number */
byte Button::PRGNO = START_PROGRAM_NO;
byte Button::PRGNO_LED = 0;



 
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
 * @param btnFunction     Function of the switch: 
                             * PC - Program Change
                             * CC - Controller Change
 * @param ctrlNo          Controller- or Program Number, which will be send
 * @param valHigh         High-Value, send at Controller-Activation
 * @param valLow          Low-Valuem send at Controller-Deaktivation
 * @param initCtrlState   Initial Controller State (Low/High)
 */  
Button::Button(byte    btnPin,           /** Pin-Number where the switch is connected */
               byte    ledPin,           /** Pin-Number where the LED is connected */
               String  btnFunction,      /** Function of the switch: PC - Program Change    CC - Controller Change */
               byte    ctrlNo,           /** Controller- or Program Number, which will be send */
               byte    valHigh,          /** High-Value, send at Controller-Activation */
               byte    valLow,           /** Low-Valuem send at Controller-Deaktivation */
               byte    initCtrlState     /** Initial Controller State (Low/High) */
              ) {  
        
  // Setting instance-variables         
  _btnPin = btnPin;
  _ledPin = ledPin;
  _btnFunction = btnFunction;
  _ctrlNo = ctrlNo;
  _valHigh = valHigh;
  _valLow = valLow;
  _initCtrlState = initCtrlState;
  
  
  // Set Pin-Mode für Switch and LED
  pinMode(_btnPin, INPUT);
  digitalWrite(_btnPin, INPUT_PULLUP);    // Pullup-Resistor
  pinMode(_ledPin, OUTPUT);


  // Set initial-Button-State
  _actState = HIGH;
  
  
  // Set initial LED-State
  if(_btnFunction == "PC") {
    // Program Change
    if(_ctrlNo == Button::PRGNO) {
      digitalWrite(_ledPin, HIGH);
      
      // Send PC
      MIDI.sendProgramChange(_ctrlNo, MIDI_CHANNEL);
      
      // Save Program-Number to Class-Variable
      Button::PRGNO = _ctrlNo;
      
      // Save LED-Pin to Class-Variable
      Button::PRGNO_LED = _ledPin;
      
    } else {
      digitalWrite(_ledPin, LOW);
    }
  }
  
  
  if(_btnFunction == "CC") {
    // Controller Change
    if(_initCtrlState == LOW) {
      
      sendCC(LOW, _valLow);

    } else {

      sendCC(HIGH, _valHigh);

    }
  }
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
      // Check Button Function
      //
      // Program Change Button
      if(_btnFunction == "PC") {
        sendPC(_ctrlNo);
      }

      // Controller Change Button
      if(_btnFunction == "CC") {
        if(_ctrlState == LOW) {

          sendCC(HIGH, _valHigh);

        } else {

          sendCC(LOW, _valLow);

        }
      }

    }
  }
  
}



/**
 * This Method sends a Controller-Message and will 
 * Activate/Deactivate concurrent LED.
 *
 * @params state    Button-State for switchen the LED
 * @params value    Controller-Value which will be sent
 *
 */  
void Button::sendCC(byte state, byte value) {
  digitalWrite(_ledPin, state);
  MIDI.sendControlChange(_ctrlNo, value, MIDI_CHANNEL);
  _ctrlState = state;
}



/**
 * This Method sends a Programm-Change-Message and will 
 * Activate/Deactivate concurrent LEDs.
 *
 * @params prgNo    Program-Number to send with PC
 *
 */  
void Button::sendPC(byte prgNo) {
  // Only send PC, if it wasn't already sent
  if(Button::PRGNO != prgNo) {
    MIDI.sendProgramChange(prgNo, MIDI_CHANNEL);
  
    // Activate actual LED
    digitalWrite(_ledPin, HIGH);
  
    // Deactivate last PC-LED
    digitalWrite(Button::PRGNO_LED, LOW);
  
    // Save Program Number and LED-Pin
    Button::PRGNO = prgNo;
    Button::PRGNO_LED = _ledPin;
  }
}

















