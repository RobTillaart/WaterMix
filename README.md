
[![Arduino CI](https://github.com/RobTillaart/WaterMix/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/WaterMix/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/WaterMix/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/WaterMix/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/WaterMix/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/WaterMix.svg)](https://github.com/RobTillaart/WaterMix/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/WaterMix/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/WaterMix.svg?maxAge=3600)](https://github.com/RobTillaart/WaterMix/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/WaterMix.svg)](https://registry.platformio.org/libraries/robtillaart/WaterMix)


# WaterMix

Arduino library for mixing water with different temperatures.


## Description

**Warning: Experimental**

Experimental library for elementary math of mixing water with different temperatures.

The library provides math for mixing a volume of water with temperature T1
with a another volume with temperature temperature T2.
In fact the library will work for any single liquid (TODO: liquidMix class),
although some functions are **water specific**.

This library is useful e.g. by doing "water math" for aquaria or cooking.
Also the library is well suited for basic educational purposes.


#### Limitations

The library uses a generic volume parameter instead of gallons or liters as
this way any user selected unit can be used.
However you must use the chosen units consistently as the library cannot handle
different units simultaneously.

To use different units for volume you can convert them with the library named
**VolumeConverter**.

The temperature unit can also be chosen by the user and can be Kelvin, Celsius,
Fahrenheit or other.
However you must use the chosen units consistently as the library cannot handle
different units simultaneously. Check **Temperature** library below for conversion.


#### Accuracy

The working range for temperature is not tested with real water.
It is expected to work quite well for water with a range from 5°C to 80°C.
In the basic math the **add()** function assumes there is no expansion so
the density is identical for "both volumes of waters".

Of course this is incorrect, therefore it is expected to have a difference
between the theoretical values and doing the mixing in practice.
However the delta's are expected to be small, less than 1% in many cases.
Given the accuracy of volume measurement and temperature measurement,
this delta is often acceptable.

If one wants a more exact answer, one should use the **addExact()** function
as this compensates for the density of the water at a given temperature.


#### Related

- https://github.com/RobTillaart/Temperature
- https://github.com/RobTillaart/VolumeConverter
- https://github.com/RobTillaart/weight


## Interface

```cpp
#include "WaterMix.h"
```

#### Constructor

- **WaterMix()** constructor, starts with no water of 0°
- **void begin(float volume = 0, float temperature = 0)**
sets initial values, default no water of 0°.

#### Math

- **void add(float volume, float temperature)** add an amount of water
with temperature to the "WaterMix".
- **void addExact(float volume, float temperature)**  Water only!
add an amount of water with temperature to the "WaterMix".
The math is calculated including using the density of the water.
This is slower as **add()** but more exact.
Note the temperature must be in °C.
- **void sub(float volume)** subtract a volume from the "WaterMix".
Temperature won't change.
- **void div(float nr)** divide the amount of liquid, same temperature.
- **void mul(float nr)** multiply the amount of liquid, same temperature.

#### Getters

- **float volume()** get the current volume.
- **float temperature()** get the current temperature.
- **float mass()** get the mass of the current volume. Water only!

#### Converters

- **float volume2mass(float volume, float temperature)** idem, Water only!
Use volume == 1 to get the density at a certain temperature.
- **float mass2volume(float mass, float temperature)** idem, Water only!


## Performance

Most functions are just fast, the only that do the core math are add() 
and addExact(). 
The WaterMix_exact.ino sketch provides some performance figures shown
here. 
Note that the **addExact()** differs in runtime as it uses a linear lookup
for the density so the numbers below are indicative.

|  Function    |  time (us)  |  Notes  |
|:------------:|:-----------:|:--------|
|   add()      |    72       |
|  addExact()  |   576       |  most accurate  |

Note it is possible to tune the linear lookup of the density by reducing 
the amount of interpolation points in the tables (at your own risk).
This will reduce the accuracy however still be better than the fast **add()**.

Performance of **addExact()** can be improved by caching the mass of the water.
To be investigated.


## Volumetric Coefficient of Expansion

The VCE is not supported in the library.
(0.1.1 supports an **addExact()** for water only, temperature in °C)

The VCE is useful as background information as the theoretical volumes calculated
in this library will differ from reality due to the VCE effect.
This difference depends on the liquid used and the delta temperature.


#### Water

The VCE of water depends on the temperature.

Source: - https://www.engineeringtoolbox.com/water-density-specific-weight-d_595.html

|  Temp °C  |  density    |  % wrt 4°C |  V.C.E (\*10<sup>-4</sup>) |  Notes  |
|:---------:|:------------|:----------:|:---------------------------|:--------|
|    0.1    |  0,9998495  |  0,0125    |  -0.68  |  note negative value
|    1      |  0,9999017  |  0,0073    |  -0.50  |  note negative value
|    4      |  0,9999749  |  0,0000    |  0.003  |
|    10     |  0,9997000  |  0,0275    |  0.88   |
|    15     |  0,9991026  |  0,0873    |  1.51   |
|    20     |  0,9982067  |  0,1771    |  2.07   |
|    25     |  0,9970470  |  0,2937    |  2.57   |
|    30     |  0,9956488  |  0,4345    |  3.03   |
|    35     |  0,9940326  |  0,5978    |  3.45   |
|    40     |  0,9922152  |  0,7821    |  3.84   |
|    45     |  0,9902100  |  0,9861    |  4.20   |
|    50     |  0,9880400  |  1,2079    |  4.54   |
|    55     |  0,9856900  |  1,4492    |  4.86   |
|    60     |  0,9832000  |  1,7062    |  5.16   |
|    65     |  0,9805500  |  1,9810    |  5.44   |
|    70     |  0,9777600  |  2,2720    |  5.71   |
|    75     |  0,9748400  |  2,5784    |  5.97   |
|    80     |  0,9717900  |  2,9003    |  6.21   |
|    85     |  0,9686100  |  3,2381    |  6.44   |
|    90     |  0,9653100  |  3,5911    |  6.66   |
|    95     |  0,9618900  |  3,9594    |  6.87   |
|    100    |  0,9583500  |  4,3434    |  7.03   |


#### Other liquids

Unknown if these liquids are expanding linear or not.

Source: - https://www.engineeringtoolbox.com/cubical-expansion-coefficients-d_1262.html
(extended table)

|  Liquid                               |  V.C.E. per °C  |  V.C.E. per °F  |
|:--------------------------------------|:----------------|:----------------|
|  Acetone                              |  0.00143        |  0.00794        |
|  Alcohol, ethyl (ethanol)             |  0.00109        |  0.000606       |
|  Alcohol, methyl (methanol,CH3OH)     |  0.00149        |  0.000828       |
|  Calcium Chloride, 5.8%               |  0.00025        |  0.00014        |
|  Engine oil                           |  0.0007         |  0.00039        |
|  Ethylene glycol                      |  0.00057        |  0.000312       |
|  Gasoline                             |  0.00095        |  0.000528       |
|  Glycerine (glycerol)                 |  0.00050        |  0.000278       |
|  Oil (unused engine oil)              |  0.00070        |  0.000389       |
|  Olive oil                            |  0.00070        |  0.000389       |
|  Paraffin oil                         |  0.000764       |  0.000424       |
|  Petroleum                            |  0.0010         |  0.00056        |
|  Potassium chloride, 24.3%            |  0.00035        |  0.000194       |
|  Sodium                               |  0.00027        |  0.00015        |
|  Sodium chloride, 20.6%               |  0.00041        |  0.000228       |


## Future

#### Must

- update documentation
  - library can be used for water and salinity and other linear related things.
- investigate linear expansion 
  - VCE as parameter.


#### Should

- create base class **LiquidMix** and derive a specific **WaterMix** from it.
  - code is quite identical, easy to split/strip water specific functions
  - **WaterMix** can include specific heat, density, VCE etc.
  - 0.2.0
  - **WaterMixF()** Fahrenheit, as derived class too.
  - **WaterMixK()** Kelvin?
- do not make the library too complex (see could below).
- extend unit tests
- investigate the caching of the mass of the water.
  - add Exact only, 4 bytes..


#### Could

- cool(time) == depends on many factors
  - need to configure curve constant (only option).
  - must use defined liquid and temp scale.
- catch temperature below zero?
  - must use defined liquid and temp scale.
  - user responsibility for now.
- **void AddEnergy(float joule)** to raise temperature (joule)
  - must use defined liquid and temp scale.
  - specific heat needed.  (Water only?)
- replace div and mul with operators \* and \/
- use double iso float?


#### Wont (or on special request)

- add "unit string" + Printable interface?
  -idem Temp scale?
- energy functions to calculate how hot an amount of water
  should be to reach a certain temperature.
  - Think Aquaria or cooking.


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,

