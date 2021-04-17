////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       irSensor.cpp
//*FILE DESC:       Source file for sensor library.
//*FILE VERSION:    1.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara(code),
//                  Ogunlolu Daniel(creative)
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Friday, 16 April 2021 19:10
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <stdint.h>
#include <sensors.hpp>

irSensor::irSensor(const uint8_t &sensorPin, const uint8_t &operationState)
                  :SensorPin {sensorPin}, OperationState {operationState}
{

}

void irSensor::begin()
{
  pinMode(SensorPin, INPUT);
}

bool irSensor::detect()
{
  return ((digitalRead(SensorPin) == OperationState) ? true : false);
}

void irSensor::toggle(uint8_t &outPin)
{
  auto condition = digitalRead(outPin);
  if(detect())
    digitalWrite(outPin, !condition);

  else
    ;
}
