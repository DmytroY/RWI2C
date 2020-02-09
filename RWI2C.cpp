/*
  RWI2C.cpp - Library for reading/writing a byte
  from/to register of a device connected by I2C bus.
  Created by Dmytro Yakovenko, July 20, 2019.
  Released into the public domain.
*/
#include "Arduino.h"
#include "RWI2C.h"
#include <Wire.h>

/* Constructor of the class scan all I2C bus addresses,
find the device adress and use it for put() and get() methods*/
RWI2C::RWI2C()
{	
}
char RWI2C::begin()
{
	char _sc_adr;
	char _resp;
	Wire.begin();
	for(_sc_adr=8 ; _sc_adr<127 ; ++_sc_adr) {
      Wire.beginTransmission(_sc_adr);
      _resp = Wire.endTransmission();
      if (_resp==0) {_adrI2C=_sc_adr;}
	  //delay(5);
	}
	return(_adrI2C);
}

char RWI2C::put(char _a,char _d)
{
	Wire.begin();
	Wire.beginTransmission(_adrI2C);// Get the slave's attention, tell it we're sending a command byte
	Wire.write(_a);                 // Send address of register
	Wire.write(_d);					// send data
	return(Wire.endTransmission());	// end of transmissin, success returns 0
}
char RWI2C::get(char _a)
{
	//get a byte from I2C device reg.
	// _ardI2C - address of I2C device, a - address of memory register
	//return a byte of data readed from register
	//*DS3231 addresses 0x07...0x0D assigned for alarms and can be used for storing any data  
	//byte _d;
	Wire.beginTransmission(_adrI2C);// Get the slave's attention, tell it we're sending a command byte
	Wire.write(_a);           		// Send address of register                    
	Wire.endTransmission();			// end of transmissin
	Wire.requestFrom(_adrI2C, 1); 	// request 1 byte from slave
	while(Wire.available())
	{
		_d = Wire.read();          // считываем байт данных
    }
  return _d;
}
