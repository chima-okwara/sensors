////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       sensors.hpp
//*FILE DESC:       Header file for sensor library.
//*FILE VERSION:    2.1
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara(code),
//                  Ogunlolu Daniel(creative)
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Friday, 30 April 2021 13:15
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <stdint.h>
#ifndef _SENSORS_
#define _SENSORS_

struct pin
{
  uint8_t pin { }, operationState { }, bit { }, port { };
  volatile uint8_t *reg { }, *out { };
  bool set;
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

class pushButton
{
public:
  pushButton(const uint8_t &pin, const uint8_t &operationState = LOW)
  {
    _pin.pin = pin;
    _pin.operationState = operationState;
  }

  void init();

  bool pressed();

private:
  pin _pin;
};
#endif
