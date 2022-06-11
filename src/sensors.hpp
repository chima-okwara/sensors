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
#include <pincontrol.hpp>
#ifndef _SENSORS_
#define _SENSORS_

struct Pin
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
	Pin _pin;
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
  Pin _echoPin, _trigPin;
};

class pushButton: public pin
{
public:
  pushButton(const uint8_t &apin, const uint8_t &operationState = LOW):pin::pin(apin, INPUT), _operationState{operationState}
  {

  }

  void init() { pin::set(); pin::write(HIGH); }

  bool pressed();

private:
  uint8_t _operationState;
};
#endif
