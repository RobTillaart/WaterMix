#pragma once
//
//    FILE: WaterMix.h
//  AUTHOR: Rob Tillaart
// PURPOSE: Arduino library for mixing water
// VERSION: 0.1.0
//     URL: https://github.com/RobTillaart/WaterMix


#include "Arduino.h"


#define WATERMIX_LIB_VERSION     (F("0.1.0"))


class WaterMix
{
public:
  WaterMix()
  {
    _volume = 0;
    _temperature = 0;
  }


  void begin()
  {
    _volume = 0;
    _temperature = 0;
  }


  void add(float volume, float temperature)
  {
    float vol = _volume + volume;
    float temp = (_volume * _temperature + volume * temperature) / vol;
    _volume = vol;
    _temperature = temp;
  }


  void sub(float volume)
  {
    _volume -= volume;
    //  temperature does not change.
  }


  void div(float nr)
  {
    _volume /= nr;
    //  temperature does not change.
  }


  float volume() 
  {
    return _volume;
  }


  float temperature()
  {
    return _temperature;
  }


private:
  float   _volume;
  float   _temperature;
};


//  -- END OF FILE --
