////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       sensors.hpp
//*FILE DESC:       Implementation file for the pushButton class.
//*FILE VERSION:    1.0
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara,
//*LICENSE:         Academic Free License.
//*LAST MODIFIED:   Friday, 30 April 2021 13:15
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "sensors.hpp"

bool pushButton::pressed(void)
{
  return ((pin::read()==_operationState)?true:false);
}
