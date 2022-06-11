////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       sensors.hpp
//*FILE DESC:       Header file for sensor library.
//*FILE VERSION:    2.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//                  Ogunlolu Daniel
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Saturday, 11 June 2022 12:01
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <stdint.h>
#include <pincontrol.hpp>

bool lightSensor::detect(uint8_t &state)
{
  return ( (read() == state) ? true : false );
}

void lightSensor::toggle(uint8_t &outPin)
{
  uint8_t condition = digitalRead(outPin);
  if(detect())
    digitalWrite(outPin, !condition);

  else
    ;
}
