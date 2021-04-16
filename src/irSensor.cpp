////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       irSensor.cpp
//*FILE DESC:       Source file for sensor library.
//*FILE VERSION:    1.0
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara(code),
//                  Ogunlolu Daniel(creative)
//*LICENSE:         MIT License.
//*LAST MODIFIED:   Friday, 16 April 2021 13:38
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <stdint.h>
#include <sensors.hpp>

irSensor::irSensor(const uint8_t &sensorPin)
                  :SensorPin(sensorPin), OperationState(LOW)
{
  pinMode(SensorPin, INPUT);
}

irSensor::irSensor(const uint8_t &sensorPin, const uint8_t &operationState)
                  :SensorPin(sensorPin), OperationState(operationState)
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