/*
  RWI2C.h - Library for reading/writing a byte
  from/to register of a device connected by I2C bus.
  Only one device should be connected to the bus,
  program will find it address authomaticaly.
  Created by Dmytro Yakovenko, July 20, 2019.
  Released into the public domain.
*/
#ifndef RWI2C_h
#define RWI2C_h
#include "Arduino.h"
#include <Wire.h>

class RWI2C
{
  public:
    RWI2C();
	char begin();
    char put(char a,char d);
    char get(char a);
  private:
    char _adrI2C;
	char _a;
	char _d;
};
#endif
