//LCDS
#include <LiquidCrystal_I2C.h> // https://github.com/johnrickman/LiquidCrystal_I2C (install as zip)
int LCD_COLUMNS = 20;
int LCD_ROWS = 4;
LiquidCrystal_I2C lcd1(0x27, LCD_COLUMNS, LCD_ROWS); //op de koma weghalen bij installeren
LiquidCrystal_I2C lcd2(0x3F, LCD_COLUMNS, LCD_ROWS);

//sensors
#include <OneWire.h>
#include <DallasTemperature.h>
#define SensorDataPin1 4
#define SensorDataPin2 5
OneWire oneWire1(SensorDataPin1);//onewire setup 
OneWire oneWire2(SensorDataPin2);//onewire setup 
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);
float tempCelcius1;
float tempCelcius2;



void setup() {
  // put your setup code here, to run once:
sensors1.begin();
sensors2.begin();
Serial.begin(9600);
//LCD setup
lcd1.init();
lcd2.init();
lcd1.backlight();
lcd2.backlight();
lcd1.setCursor(0,0);
lcd1.print("11.04.2022");
lcd2.setCursor(0,0);
lcd2.print("12.04.2022");
delay(4000);
lcd1.clear();
lcd2.clear();
}

void loop() {
sensors1.setResolution(9); //gevoeligheid sensor
sensors2.setResolution(9); //gevoeligheid sensor 
sensors1.requestTemperatures();// send the command to get temperatures
sensors2.requestTemperatures();// send the command to get temperatures
tempCelcius1 = sensors1.getTempCByIndex(0);
tempCelcius2 = sensors2.getTempCByIndex(0);
lcd1.setCursor(0,0);
lcd1.print("Sensor: ");
lcd1.print(tempCelcius1);
lcd2.setCursor(0,0);
lcd2.print("Sensor: ");
lcd2.print(tempCelcius2);
}
