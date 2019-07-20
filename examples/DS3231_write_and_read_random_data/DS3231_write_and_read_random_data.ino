# include <RWI2C.h>
/*DS3231_read_all_registers
  Dmytro Yakovenko. July 20,2019.
  A quick demo how to use RWI2C.h libriary to write and read a registers of
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
  Serial.print("I2C device found on 0x");
  Serial.println(adrI2C,HEX);
} 

void loop() {
  byte adr;       // address of the register
  byte dw;        // data to write
  byte dr;        // data have been readed
  boolean check;  // flag of writing success
/* 
   DS3231 addresses from 0x07 till 0x0E are used for alarms,  
   we can write there any data witout interfering with clock. 
*/
Serial.println("--------------------------------");
  for(adr=0x07;adr<0x0E;adr++){
      dw=random(0,255);           // random data
      Serial.print(adr ,HEX);
      Serial.print(" address, writing data:");
      Serial.println(dw,HEX);      
      check = rwi2c.put( adr,dw); //pur to the register. will return 0 in case of success
      if (check!=0){
        Serial.print("EEROR during writing data to register ");
        Serial.print(adr ,HEX);
        }
      dr = rwi2c.get(adr);  //geting from the register
      Serial.print(adr ,HEX);
      Serial.print(" address,  readed data:");
      Serial.println(dr,HEX);
  }
delay (5000);
}
