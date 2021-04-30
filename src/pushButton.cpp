////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       sensors.hpp
//*FILE DESC:       Implementation file for the pushButton class.
//*FILE VERSION:    1.0
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara,
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Friday, 30 April 2021 13:15
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "sensors.hpp"

void pushButton::init()
{
  uint8_t timer = digitalPinToTimer(_pin.pin);
  _pin.bit = digitalPinToBitMask(_pin.pin);
  _pin.port = digitalPinToPort(_pin.pin);
}

bool pushButton::pressed(void)
{
  return ((*portInputRegister(_pin.port) & (_pin.bit)?HIGH:LOW));
}
