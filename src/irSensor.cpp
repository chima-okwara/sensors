////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       irSensor.cpp
//*FILE DESC:       Source file for sensor library.
//*FILE VERSION:    2.0
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara(code),
//                  Ogunlolu Daniel(creative)
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Thursday, 29 April 2021 15:29
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <stdint.h>
#include <sensors.hpp>

void irSensor::begin()
{
  _pin.bit = digitalPinToBitMask(_pin.pin);
  _pin.port = digitalPinToPort(_pin.pin);
  _pin.reg = portModeRegister(_pin.port);
  _pin.out = portOutputRegister(_pin.port);
  byte oldSREG = SREG;
  cli();
  *_pin.reg &= ~_pin.bit;
  *_pin.out &= ~_pin.bit;
  SREG = oldSREG;
}

bool irSensor::detect()
{
  return ((*portInputRegister(_pin.port) & (_pin.bit))?true:false);

}

void irSensor::toggle(uint8_t &outPin)
{
  auto condition = digitalRead(outPin);
  if(detect())
    digitalWrite(outPin, !condition);

  else
    ;
}
