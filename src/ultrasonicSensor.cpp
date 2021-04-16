////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       ultrasonicSensor.cpp
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

ultrasonicSensor::ultrasonicSensor(const uint8_t &trigPin, const uint8_t &echoPin)
                                  :EchoPin(echoPin), TrigPin(trigPin)
{
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
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

float ultrasonicSensor::getDistance_mm() const
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);

  long pulse = pulseIn(EchoPin, HIGH);
  float distance = (pulse*340)/2000;
  return (distance);
}

float ultrasonicSensor::getDistance_cm() const
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);

  long pulse = pulseIn(EchoPin, HIGH);
  float distance = (pulse*340)/20000;
  return (distance);
}

float ultrasonicSensor::getDistance_m() const
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);

  long pulse = pulseIn(EchoPin, HIGH);
  float distance = (pulse*340)/2000000;
  return (distance);
}
