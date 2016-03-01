#include <Wire.h>
#include <LTC2453.h>
#include <LiquidCrystal_I2C.h>
#include <Streaming.h>

LTC2453 extADC;
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display

void setup() {
  Wire.begin();
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

}

void loop() {
  Serial << extADC.read() << " / " << _FLOAT(extADC.readVoltage(), 4) << " Volt" << endl;
  lcd.setCursor(0,0);
  lcd << extADC.read() << " / " << _FLOAT(extADC.readVoltage(), 4) << " Volt";
  delay(1000);
}
