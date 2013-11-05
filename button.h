#ifndef Button_h
#define Button_h


#include <Arduino.h>


class Button {
  public:
    byte _btnPin;            // Pin-Number for Buttons
    byte _ledPin;            // Pin-Number for Button Status-LED
    String _btnFunction;     // Button-Function: PC - Program Change    -    CC - Controller Change
    byte _ctrlNo;            // Controller-Number or PC-Number
    byte _valHigh;           // CC-High-Value
    byte _valLow;            // CC-Low-Value

    Button();
    ~Button();
    Button(byte btnPin, byte ledPin, String btnFunction, byte ctrlNo, byte valHigh, byte valLow);
};



#endif
