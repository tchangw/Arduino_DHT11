#include <dht.h>
#include <LiquidCrystal.h>

// 'front' of DHT-11
//    _____
//   |+++++|  
//   |+++++|
//   |+++++|
//   | | | |
//   1 2 3 4
//
// 1. VCC+
// 2. Data
// 3. 
// 4. Ground-

dht DHT;

#define DHT11_PIN 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temp;
float humidity;

void setup(){
  Serial.begin(9600);

  // set up the LCD's number of rows and columns
  lcd.begin(16,2);
  lcd.print("Temperature: ");
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  temp = DHT.temperature;
  humidity = DHT.humidity;
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");
  delay(300);
}

