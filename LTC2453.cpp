/*
LTC2453
Ultra-Tiny, Differential, 16-Bit DeltaSigma ADC With I2C Interface.

Michael Ruck 29.02.2016
michael@ruck.com
*/

#include "LTC2453.h"

LTC2453::LTC2453(){
	instanceCount++;
	// if instanceCount > 1 then destroy instance / rise compile error
}

LTC2453::~LTC2453(){
	//nothing to do
}

int16_t LTC2453::read(){
  int reading_ = 0;
	
  Wire.requestFrom(LTC2453_Addr, 2);

  if (2 <= Wire.available() && millis_born + 20 <= millis()) { // if two bytes were received AND reading is outdated
    reading_ = Wire.read();  // receive high byte (overwrites previous reading)
    reading_ = reading_ << 8;    // shift high byte to be high 8 bits
    reading_ |= Wire.read(); // receive low byte as lower 8 bits
	millis_born = millis();	// save timestamp
    reading_ = reading_ - 0x8000; // move result by 0x8000 for correct zero point
	voltage = ((float)reading_ / 0x8000) * Vref;	//calculate differential voltage
	reading = reading_;
  }  
  
  return reading;
}

float LTC2453::readVoltage(){
  int reading_ = 0;
	
  Wire.requestFrom(LTC2453_Addr, 2);

  if (2 <= Wire.available() && millis_born + 20 <= millis()) { // if two bytes were received AND reading is outdated
    reading_ = Wire.read();  // receive high byte (overwrites previous reading)
    reading_ = reading_ << 8;    // shift high byte to be high 8 bits
    reading_ |= Wire.read(); // receive low byte as lower 8 bits
	millis_born = millis();	// save timestamp
    reading_ = reading_ - 0x8000; // move result by 0x8000 for correct zero point
	voltage = ((float)reading_ / 0x8000) * Vref;	//calculate differential voltage
	reading = reading_;
  } 
  
  return voltage;
}
