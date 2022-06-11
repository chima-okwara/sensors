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



bool irSensor::detect()
{
  return ( (read() == _pin.operationState) ? true : false);
}

void irSensor::toggle(uint8_t &outPin)
{
  uint8_t condition = digitalRead(outPin);
  if(detect())
    digitalWrite(outPin, !condition);

  else
    ;
}
