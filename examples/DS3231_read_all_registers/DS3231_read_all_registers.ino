# include <RWI2C.h>
/*DS3231_read_all_registers
  Dmytro Yakovenko. July 20,2019.
  A quick demo how to use RWI2C.h libriary to read all memory registers of
  real time clock module DS3231.
  To use the hardware I2C (TWI) interface of the Arduino you must connect
  the pins as follows: 
  DS3231 SDA pin   -> Arduino dedicated SDA pin
  DS3231 SCL pin   -> Arduino dedicated SCL pin
  Tested with Arduino Uno, Arduino Mega.
 */
  RWI2C rwi2c;

void setup() {
   Serial.begin(9600);           Serial.println("Serial.begin(9600)");
  
  /* method .begin() will scan I2C bus addresses from 8 till 126,
  find a device adress, return it and will use it for .put() and .get()
  methods in the libriary RWI2C.h*/
  byte adrI2C = rwi2c.begin();
  Serial.print("I2C device found on 0x"); Serial.println(adrI2C,HEX);
} 

void loop() {
  byte adr;
  byte d;
  Serial.println("Reading registers from 00h till 12h:");
  for (adr=0x00; adr<0x13; ++adr){
       d=rwi2c.get(adr);
       Serial.print(adr,HEX); Serial.print(" : ");  Serial.println(d,HEX);
  }
//  register 0x00 keeps seconds. You can see in the Serial Monitor how it ticking
delay (5000);
}
