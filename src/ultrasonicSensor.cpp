////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       ultrasonicSensor.cpp
//*FILE DESC:       Source file for sensor library.
//*FILE VERSION:    2.0
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara(code),
//                  Ogunlolu Daniel(creative)
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Thursday, 29 April 2021 15:29
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <wiring_private.h>
#include <pins_arduino.h>
#include <stdint.h>
#include <sensors.hpp>

void ultrasonicSensor::begin()
{
  _echoPin.bit = digitalPinToBitMask(_echoPin.pin);
  _echoPin.port = digitalPinToPort(_echoPin.pin);
  _echoPin.reg = portModeRegister(_echoPin.port);
  _echoPin.out = portOutputRegister(_echoPin.port);

  _trigPin.bit = digitalPinToBitMask(_trigPin.pin);
  _trigPin.port = digitalPinToPort(_trigPin.pin);
  _trigPin.reg = portModeRegister(_trigPin.port);
  _trigPin.out = portOutputRegister(_trigPin.port);

  uint8_t oldSREG = SREG;
  cli();
  *_echoPin.reg &= ~_echoPin.bit;
  *_echoPin.out &= ~_echoPin.bit;
  *_trigPin.reg |= _trigPin.bit;
  SREG = oldSREG;
}

bool ultrasonicSensor::detect_mm(float &distance)
{
  return ((getDistance_mm() >= distance) ? (true) : (false));
}

bool ultrasonicSensor::detect_cm(float &distance)
{
  return ((getDistance_cm() >= distance) ? (true) : (false));
}

bool ultrasonicSensor::detect_m(float &distance)
{
  return ((getDistance_m() >= distance) ? (true) : (false));
}


float ultrasonicSensor::getDistance_m() const
{
  float pulseDur { };
  //Generate pulse:
  *_trigPin.out &= ~_trigPin.bit;
  delayMicroseconds(2);
  *_trigPin.out |= _trigPin.bit;
  delayMicroseconds(10);
  *_trigPin.out &= ~_trigPin.bit;
  delayMicroseconds(2);

  uint8_t statemask = (HIGH?_echoPin.bit:0);
  unsigned long maxloops = microsecondsToClockCycles(1000000L)/16;

  unsigned long width = countPulseASM(portInputRegister(_echoPin.port), _echoPin.bit, statemask, maxloops);

  if(width)
    pulseDur = clockCyclesToMicroseconds(width*16+16);

  return ((pulseDur*340)/2000000);
}
