/*
LTC2453
Ultra-Tiny, Differential, 16-Bit DeltaSigma ADC With I2C Interface.

Michael Ruck 29.02.2016
michael@ruck.com
*/

#ifndef LTC2453_H
#define LTC2453_H
#include <Arduino.h>
#include <Wire.h>

class LTC2453{
	public:
		LTC2453(void);
		~LTC2453(void);
		float voltage;
		float Vref=3.3;
		int16_t read(void);
		/*
		operator int16_t(void) {
			return read();
		};*/
		int reading = 0;
		float readVoltage(void);
		int instanceCount=0;
		
	private:
		int LTC2453_Addr = 0b0010100;
		long millis_born = 0;
};

#endif