/*temperatuursensor en vergelijking*/
#include <OneWire.h>
#include <DallasTemperature.h>
#define SensorDataPin 18
OneWire oneWire(SensorDataPin);//onewire setup 
DallasTemperature sensors(&oneWire);
//waarde van de sensor 
float tempCelcius;
//tempStateEnumDeclaration 
enum tempDecision {tempLOW, tempHIGH, tempOK};
enum tempDecision temp;
//instellen van de temperatuur
int setTemp = 20;
int minTemp = setTemp - 1;
int maxTemp = setTemp + 2;
// ontdooien maximale temperatuurstijging 
const int ontdooimaxTemp = 25;
// declaratie van de tempOKinterval
const long tempInterval = 120000;
unsigned long tempCount = 0;
/*millis fucties*/
int ledState = 0;
int ledState1 = 0;   
int ledState2 = 0;
int ledState3 = 0;    
unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
//interval tussen switchen van de relais
const long interval1 = 1000;
//interval van de ventilator bij tempOK    
const long interval2 = 30000;    

#include "RTClib.h"
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//instellen van de ontdooitijden
int hour1 = 8;
int hour2 = 21;
int onMin = 1;
int offMin = 30;
//ontdooiFunctieEnumDeclaratie
enum ontdooi{ontdooiAan, ontdooiUit};
enum ontdooi ontdooi_on_OR_off;



/*IO pinnen */
#define ventilator 13
#define klep 12
#define groep 14
#define ontdooi 27

void setup() {
  // put your setup code here, to run once:
  #ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
  #endif
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);}
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));}


pinMode(ventilator,OUTPUT);
pinMode(klep,OUTPUT);
pinMode(groep,OUTPUT);
pinMode(ontdooi,OUTPUT);
sensors.begin();
Serial.begin (115200);
delay (1000);
}
