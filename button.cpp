/*!
 *  @file		button.cpp
 *  Project		axefx.de MIDI Borad
 *	@brief		Class of a Switch-Button
 *	@version	0.0.1
 *  @author		Bastian Buehrig
 *	@date		04/11/13
 *  license		GPL axefx.de - 2013
 */

#include "Arduino.h"
#include "Button.h"
  

Button::Button(int btnPin, int ledPin) {
  _btnPin = btnPin;
  _ledPin = ledPin;
}
  
  
void Button::setButtonFunction(String btnFunction) {
  _btnFunction = btnFunction;
}

void Button::setValueHigh(int valHigh) {
  _valHigh = valHigh;
}

void Button::setValueLow(int valLow) {
  _valLow = valLow;
}


