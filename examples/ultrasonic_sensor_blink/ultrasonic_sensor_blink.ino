/**********************************************
Copyright 2020 -2021, (c) The Eichen Group.
Acknowledgement(s): Daniel Ogunlolu, AmazingTech (R)
***********************************************/

#include <LiquidCrystal.h>
#include <sensors.hpp>

LiquidCrystal lcd (7,8,9,10,11,12);
ultrasonicSensor ultra(3,4);    //First argument is the trigger pin, second is echo pin.
float distance = 0.0;

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Distance:    ");
  lcd.setCursor(10, 0);
  distance = ultra.getDistance_cm();    //Measure distance in centimetres (cm)
  lcd.print(distance);
  lcd.setCursor(15,0)
  lcd.print("cm");
}
