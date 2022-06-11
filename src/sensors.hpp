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

//TODO:
//Add support for PIR sensors, Touch sensors, Pressure sensors, Moisture sensors.

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

class lightSensor : public virtual inputPin
{
public:
  using inputPin::inputPin;
  lightSensor() = default;
  explicit lightSensor(const uint8_t &sensorPin):inputPin(sensorPin), _pin.pin(sensorPin)
  {

  }

  bool detect(uint8_t &state);
  void toggle(uint8_t &outputPin);

private:
	Pin _pin;
};


class irSensor : public virtual lightSensor
{
public:
  using lightSensor::lightSensor;
  irSensor() = default;
	explicit irSensor(const uint8_t &sensorPin, const uint8_t &operationState == LOW):lightSensor(sensorPin), _pin.operationState(operationState)
  {

  }

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
