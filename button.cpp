/*!
 *  @file		button.cpp
 *  Project		axefx.de MIDI Borad
 *	@brief		Class of a Switch-Button
 *	@version	0.0.1
 *  @author		Bastian Buehrig
 *	@date		04/11/13
 *  license		GPL axefx.de - 2013
 */

#include "Button.h"
  
Button::Button() {
}


Button::Button(byte    btnPin, 
               byte    ledPin,
               String  btnFunction,
               byte    ctrlNo,
               byte    valHigh,
               byte    valLow) {
                 
  _btnPin = btnPin;
  _ledPin = ledPin;
  _btnFunction = btnFunction;
  _ctrlNo = ctrlNo;
  _valHigh = valHigh;
  _valLow = valLow;

}


Button::~Button() {
}
