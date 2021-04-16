////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       sensors.hpp
//*FILE DESC:       Header file for sensor library.
//*FILE VERSION:    1.0
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara(code),
//                  Ogunlolu Daniel(creative)
//*LICENSE:         MIT License.
//*LAST MODIFIED:   Friday, 16 April 2021 13:38
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <stdint.h>
#ifndef _SENSORS_
#define _SENSORS_


class irSensor

{
public:
  irSensor(const uint8_t &sensorPin);
	irSensor(const uint8_t &sensorPin, const uint8_t &operationState);

  bool detect(void);
  void toggle(uint8_t &outPin);

private:
	uint8_t SensorPin, OperationState;

};

class ultrasonicSensor
{
public:
  ultrasonicSensor(const uint8_t &trigPin, const uint8_t &echoPin);
  bool detect_mm(float &distance);
  bool detect_cm(float &distance);
  bool detect_m(float &distance);

  float getDistance_mm(void)const;
  float getDistance_cm(void)const;
  float getDistance_m(void)const;

private:
  uint8_t EchoPin, TrigPin, OperationState;
};

#endif
