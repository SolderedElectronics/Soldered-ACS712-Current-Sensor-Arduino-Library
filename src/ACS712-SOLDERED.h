/**
 **************************************************
 *
 * @file        ACS712-SOLDERED.h
 * @brief       Wrapper to make using library easier.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#ifndef __ACS712_SOLDERED__
#define __ACS712_SOLDERED__

#include "libs/ACS712/ACS712.h"

#define ACS712_5A  185
#define ACS712_20A 100
#define ACS712_30A 66

#ifdef __AVR__
#define ACS712_VOLTS 5.0
#else
#define ACS712_VOLTS 3.3
#endif

#ifdef ARDUINO_ARCH_ESP32
#define _ADC_RES 4095
#else
#define _ADC_RES 1023
#endif

class ACS712 : public _ACS712
{
  public:
    ACS712(int _pin, int mVperA) : _ACS712(_pin, ACS712_VOLTS, _ADC_RES, mVperA)
    {
    }
};

#endif
