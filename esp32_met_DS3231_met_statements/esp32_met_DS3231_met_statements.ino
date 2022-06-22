
#include "RTClib.h"
 
RTC_DS3231 rtc;
 
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const int hour1 = 8;
const int hour2 = 20;
const int onMin = 10;
const int offMin = 29;


 
void setup () {
 
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif
 
  Serial.begin(115200);
 
  delay(1000); // wait for console opening
 
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
 
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date &amp; time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date &amp; time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}
 
void loop () {
    DateTime now = rtc.now();
     
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    Serial.println();
    delay(1000);

if(((now.hour () == hour1)||(now.hour () == hour2)) && (now.minute () >= onMin) && (now.minute () <= offMin)){
  Serial.println("functie klopt");
}
else{
  Serial.println("functie klopt niet ");
}
    
}
