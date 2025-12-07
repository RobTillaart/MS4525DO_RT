#pragma once
//
//    FILE: MS4525DO.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2025-12-06
// PURPOSE: Arduino library for MS4525DO pressure and temperature sensor.
//     URL: https://github.com/RobTillaart/MS4525DO_RT


//  TODO adjust comments.


//  TESTED TYPES - type A 10% - 90% only
//
//  ADDRESS   PRESSURE   RANGE          TYPE      P   A T V
//  0x58      100 psi    0..6895 mBar   SSCDANN 100PG 5 A 5
//  0x38       60 psi    0..4137 mbar   SSCDANN 060PG 3 A 5
//  0x28       30 psi    0..2068 mbar   SSCDANN 030PG 2 A 5
//
//  P = pressure range
//  A = I2C address indicator
//  T = accuracy range
//  V = voltage (3 volt also supported, not tested)
//


#include "Wire.h"
#include "Arduino.h"


#define MS4525DO_LIB_VERSION              (F("0.1.0"))

#define PSI2MILLIBAR                      (68.9475729)
#define MILLIBAR2PSI                      (0.01450377377)

#define MS4525DO_OK                        1
#define MS4525DO_INIT                      0
#define MS4525DO_READ_ERROR               -1
#define MS4525DO_OVF_ERROR                -2
#define MS4525DO_CONNECT_ERROR            -3
#define MS4525DO_CONFIG_ERROR             -4


class MS4525DO
{
public:
  MS4525DO(uint8_t address, TwoWire *wire = &Wire);

  //       psi: 150, 100, 50, 30, 15, 5, 2, 1
  //       type: 'A' (default) or 'B'
  bool     begin(uint8_t psi, char type = 'A');
  void     reset();
  bool     isConnected();
  uint8_t  getAddress();


  //  returns status OK (1) or ERROR ( other )
  int      read();

  //  returns the pressure of last successful read
  float    getMilliBar()   { return _pressure; };
  float    getPSI()        { return _pressure * MILLIBAR2PSI; };
  float    getCelsius()    { return _temperature; };
  float    getFahrenheit() { return _temperature * 1.8 + 32.0; };


  //  # errors since last good read
  uint16_t errorCount() { return _errorCount; };
  //  timestamp of last good read
  uint32_t lastRead()   { return _lastRead; };
  //  get the last state
  int      state()      { return _state; };

  //  debugging / own conversion.
  int      rawPressureCount()    { return _rpc; };
  int      rawTemperatureCount() { return _rtc; };


private:
  uint8_t  _address;
  TwoWire*  _wire;

  float    _maxPressure;  //  mBar
  float    _pressure;     //  mBar
  float    _temperature;  //  Celsius
  int      _rpc;          //  raw counter for debugging.
  int      _rtc;          //  raw counter for debugging.

  uint8_t  _state;
  uint32_t _errorCount;
  uint32_t _lastRead;
  char     _type;
};


//  -- END OF FILE --

