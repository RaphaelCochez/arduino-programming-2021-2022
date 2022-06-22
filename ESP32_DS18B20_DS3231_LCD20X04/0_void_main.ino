/*temperatuursensor en vergelijking*/

//temperatuursensor
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

#define SensorDataPin 26
OneWire oneWire(SensorDataPin);//onewire setup 
DallasTemperature sensors(&oneWire);
float tempCelcius;

//temperatuurverwerking
enum tempDecision {tempLOW, tempHIGH, tempOK};
enum tempDecision temp;
int setTemp = 20;
int minTemp = setTemp - 1;
int maxTemp = setTemp + 2;

//ontdooing
const int ontdooimaxTemp = 5;
enum ontdooi{ontdooiAan, ontdooiUit};
enum ontdooi ontdooi_on_OR_off;
const long tempInterval = 180000;
unsigned long tempCount = 0;

//millisfucties
int ledState = 0;
int ledState1 = 0;   
int ledState2 = 0;
int ledState3 = 0;    
unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
const long interval1 = 1000;   //interval tussen switchen van de relais
const long interval2 = 30000;  //interval van de ventilator bij tempOK    

//Real Time Clock
#include "RTClib.h"
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//instellen van de ontdooitijden
int hour1 = 8;
int hour2 = 20;
int onMin = 30;
int offMin = 59;

// lcd setup
int celcius = 0;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int LCDclear = 0;

bool LCDclear1 = true;
bool LCDclear2 = true;
// I0O pinnen
#define ventilator 13
#define klep 12
#define groep 27
#define ontdooi 14
