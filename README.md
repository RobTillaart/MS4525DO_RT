
[![Arduino CI](https://github.com/RobTillaart/MS4525DO/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/MS4525DO/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/MS4525DO/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/MS4525DO/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/MS4525DO/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/MS4525DO.svg)](https://github.com/RobTillaart/MS4525DO/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/MS4525DO/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/MS4525DO.svg?maxAge=3600)](https://github.com/RobTillaart/MS4525DO/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/MS4525DO.svg)](https://registry.platformio.org/libraries/robtillaart/MS4525DO)


# MS4525DO

Arduino library for MS4525DO pressure sensor.


## Description

The MS4525DO library can read the sensor and give the pressure in millibar,
bar or PSI or many other units. See below.

library is spin off of I2C_ASDX so there might be some leftovers...


### Related

- https://github.com/RobTillaart/pressure - pressure conversions
- https://github.com/RobTillaart/Temperature - temperature conversions 
- https://github.com/RobTillaart/I2C_ASDX - (I2C) pressure + conversions 
- https://github.com/RobTillaart/MS4525DO - (I2C) temperature pressure sensor 
- https://github.com/RobTillaart/MS5837 - (I2C) temperature pressure sensor  (incl pressure to altitude)
- https://github.com/RobTillaart/MS5611 - (I2C) temperature pressure sensor  (incl pressure to altitude)
- https://github.com/RobTillaart/MSP300 - (I2C) industrial pressure transducer
- https://swharden.com/blog/2017-04-29-precision-pressure-meter-project/


### Hardware connection

Always check datasheet for the exact pins.

```
      MS4525DO            ARDUINO
    +----------+        +----------+
    |          |        |          |
    |     GND o|--------|o GND     |
    |     VCC o|--------|o VCC     |
    |     SDA o|--------|o SDA     |
    |     SCL o|--------|o SCL     |
    |          |        |          |
    +----------+        +----------+
```


## Interface

```cpp
#include "MS4525DO.h"
```

