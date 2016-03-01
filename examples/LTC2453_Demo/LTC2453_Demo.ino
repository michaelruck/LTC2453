#include <Wire.h>
#include <LTC2453.h>

LTC2453 extADC;

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  Serial.print(extADC.read());
  Serial.print(" / ");
  Serial.println(extADC.readVoltage(), 4);
  delay(1000);
}
