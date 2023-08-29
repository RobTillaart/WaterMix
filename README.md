
[![Arduino CI](https://github.com/RobTillaart/WaterMix/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/WaterMix/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/WaterMix/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/WaterMix/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/WaterMix/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/WaterMix.svg)](https://github.com/RobTillaart/WaterMix/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/WaterMix/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/WaterMix.svg?maxAge=3600)](https://github.com/RobTillaart/WaterMix/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/WaterMix.svg)](https://registry.platformio.org/libraries/robtillaart/WaterMix)


# WaterMix

Arduino library for mixing water of different temperatures.


## Description

Experimental library for elementary math of mixing water of different temperatures.

The library does the math of mixing a volume of water of temperature T1
with a another volume with temperature temperature T2.
In fact the library will work for any liquid.

The library uses a generic volume parameter instead of gallons or liters as
this way any user selected unit can be used.
However you must use the chosen units consistently as you cannot use different
units simultaneously.

To use different units you can get some help of the volume conversion library
named **VolumeConverter** to convert the units.

The temperature unit can also be chosen by the user and can be Kelvin, Celsius,
Fahrenheit or other.
However you must use the chosen units consistently as you cannot use different
units simultaneously. Check **Temperature** library below.

This library is not meant for serious applications **use at own risk**.
That said it could be useful e.g. by doing water math for aquaria.
Finally it is very well suited for basic educational purposes.


#### Accuracy

The working range for temperature is not tested with real water.
It is expected to work with a range from 5°C to 80°C.
What the library does not include in the math (yet) is the expansion and
contraction of the water due to the temperature delta.


#### Related

- https://github.com/RobTillaart/VolumeConverter
- https://github.com/RobTillaart/Temperature


## Interface

```cpp
#include "WaterMix.h"
```

#### Constructor

- **WaterMix()** constructor, starts with no water of 0°
- **void begin()** resets to no water of 0°.
- **void add(float volume, float temperature)** add an amount of water
with temperature to the "WaterMix".
- **void sub(float volume)** subtract a volume from the "WaterMix".
Temperature won't change.
- **void div(float nr)** divide the amount of liquid, same temperature.
- **void mul(float nr)** multiply the amount of liquid, same temperature.
- **float volume()** get the current volume.
- **float temperature()** get the current temperature.


## Future

#### Must

- update documentation
- **add(WaterMix wm)** to "merge" to water contents.


#### Should

- include expansion of water due to heat.
  - 4°C is smallest for water.
  - must use defined liquid and temp scale.
  - or add an expansion function?
  - needs investigation
- **void AddEnergy(float joule)** to raise temperature (joule)
  - must use defined liquid and temp scale.
  - specific heat needed.

#### Could

- performance measurements
- cool(time) == depends on many factors
  - need to configure curve constant (only option).
  - must use defined liquid and temp scale.
- some energy functions to calculate how hot an amount of water
  should be to reach a certain temperature. Think Aquaria.
- add "unit string" + Printable interface?  idem Temp scale?
- extend unit tests
- rename to **LiquidMix** class
  - WaterMixCelsius as derived class?
  - WaterMixFahrenheit as derived class? etc.
- catch temperature below zero?
  - must use defined liquid and temp scale.
- library can be used for water and salinity too
  - other linear related things.

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,

