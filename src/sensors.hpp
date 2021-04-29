////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       sensors.hpp
//*FILE DESC:       Header file for sensor library.
//*FILE VERSION:    2.0
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara(code),
//                  Ogunlolu Daniel(creative)
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Thursday, 29 April 2021 15:29
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <stdint.h>
#ifndef _SENSORS_
#define _SENSORS_

struct pin
{
  uint8_t pin { }, operationState { }, bit { }, port { };
  volatile uint8_t *reg { }, *out { };
};

class irSensor
{
public:
	irSensor(const uint8_t &sensorPin, const uint8_t &operationState)
  {
    _pin.pin = sensorPin;
    _pin.operationState = operationState;
  }
  irSensor(const uint8_t &sensorPin)
          :irSensor {sensorPin, LOW}
  { }

  irSensor() = default;

  void begin();

  bool detect(void);
  void toggle(uint8_t &outPin);

private:
	pin _pin;
};

class ultrasonicSensor
{
public:
  ultrasonicSensor(const uint8_t &trigPin, const uint8_t &echoPin)
  {
    _trigPin.pin = trigPin;
    _echoPin.pin = echoPin;
  }
  ultrasonicSensor() = default;

  void begin();

  bool detect_m(float &distance);
  bool detect_cm(float &distance);
  bool detect_mm(float &distance);

  float getDistance_m(void)const;
  float getDistance_cm(void)const { return (getDistance_m()*100); }
  float getDistance_mm(void)const { return (getDistance_m()*1000); }

private:
  pin _echoPin, _trigPin;
};

#endif
