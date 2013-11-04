#ifndef Morse_h
#define Button_h


#include "Arduino.h"


class Button {
  public:
    Button(int buttonPin, int ledPin);
    void setButtonFunction(String btnFunction);
    void setValueHigh(int valHigh);
    void setValueLow(int valLow);
    
  private:
    int _btnPin;          // Pin-Number for Buttons
    int _ledPin;             // Pin-Number for Button Status-LED
    String _btnFunction;   // Button-Function: PC - Program Change    -    CC - Controller Change
    int _valHigh;           // PC-Number or CC-High-Value
    int _valLow;            // CC-Low-Value
};



#endif
