#include <SHT1x.h>
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
 
// Specify data and clock connections and instantiate SHT1x object
#define dataPin  10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);
 #define dataPin2  12
#define clockPin2 13
SHT1x sht1x2(dataPin2, clockPin2);
void setup()
{
  Serial.begin(19200); // Open serial connection to report values to host
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
 
void loop()
{
  float temp_c;
 float temp_c2;
 float humidity;
 float humidity2;
 
  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  humidity = sht1x.readHumidity();
  temp_c2 = sht1x2.readTemperatureC();
  humidity2 = sht1x2.readHumidity();
  
  // Print Inside Data to LCD
  lcd.setCursor(0,0);
  lcd.print("IN  ");
  lcd.print(temp_c,1);
  lcd.print("C  ");
  lcd.print("");
  lcd.print("H:");
  lcd.print(humidity,0);
  lcd.print("%");
  
//Print Outside Data to LCD
  lcd.setCursor(0,1);
  lcd.print("OUT ");
  lcd.print(temp_c2,1);
  lcd.print("C  ");
  lcd.print("");
  lcd.print("H:");
  lcd.print(humidity2,0);
  lcd.print("%");

  //Serial Port logging
  Serial.println(temp_c,1);
   
  delay(2000);
}


