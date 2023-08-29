
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

Experimental library for the WaterMix function.

The library does some elementary math of mixing a volume of water
with a certain temperature, with another volume of another temperature.

The library uses generic volume instead of gallons or liters as 
any unit can be used. However you must use the chosen units consistently.
So, you cannot use different units simultaneously.

To use different units you can use the conversion library **Volume**.

Temperature can be Kelvin, Celsius or Fahrenheit.


#### Related

- https://github.com/RobTillaart/VolumeConverter
- https://github.com/RobTillaart/Temperature



## Interface

```cpp
#include "WaterMix.h"
```

#### Constructor

- **WaterMix()** 
- **void begin()**
- **void add(float volume, float temperature)**
- **void sub(float volume)**
- **void div(float nr)**
- **float volume()**
- **float temperature()**


## Future

#### Must

- update documentation

#### Should

- Add energy to raise temperature (joule)
- Add(WaterMix wm);


#### Could

- extend unit tests
- move code to .cpp
- performance measurements
- cool(time) == depends on many factors 
  - need to configure curve constant (only option).


#### Wont



## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,

