#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2        // DHT22 data pin connected to digital pin 2
#define DHTTYPE DHT22   // Use DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change to 0x3F if not working

void setup() {
  dht.begin();
  lcd.init();      
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp & Humidity");
  delay(2000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sensor Error!");
    delay(2000);
    return;
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t,1); // 1 decimal place
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(h,1);
  lcd.print(" %");

  delay(2000);
}
