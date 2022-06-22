#include <OneWire.h>
#include <DallasTemperature.h>
#define SensorDataPin 18
OneWire oneWire(SensorDataPin);//onewire setup 
DallasTemperature sensors(&oneWire); 
float tempCelcius;
enum tempDecision {tempLOW, tempHIGH, tempOK};
enum tempDecision temp;
int setTemp = 20;
int minTemp = setTemp - 1;
int maxTemp = setTemp + 2;
const long tempInterval = 120000;
unsigned long tempCount = 0;
#define led1 12
#define led2 13
#define led3 14
#define led4 25

void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
sensors.begin();
Serial.begin (115200);
}
void tempSensor (){
  sensors.setResolution(8);
  //resolutionValue 8 = 0.5 °C
  //resolutionValue 9 = 0.25 °C
  //resolutionValue 10 = 0.125 °C
  //resolutionValue 11 = 0.0625°C
  sensors.requestTemperatures();// send the command to get temperatures
  tempCelcius = sensors.getTempCByIndex(0);  
}
void tempSensorPrint (){
  Serial.print("Temperature: ");//display this text in the serial monitor
  Serial.print(tempCelcius);// print the temperature in Celsius
  Serial.print("°C");//display this text in the serial monitor
  Serial.println(""); 
}
void tempIndex (){
  unsigned long timerTemp = millis ();
  if ( tempCelcius <= minTemp){
    temp = tempHIGH;
    Serial.println ("tempLOW");}
  else if ( tempCelcius > minTemp && tempCelcius >= maxTemp){
    temp = tempLOW;
    Serial.println ("tempHIGH");}
  else if ((tempCelcius > minTemp) && (tempCelcius < maxTemp)){
    if (timerTemp - tempCount >= tempInterval){
        temp = tempOK;
        Serial.println ("tempOK");
        tempCount = millis();}}
}


void loop() {
tempSensor ();
tempSensorPrint ();
tempIndex ();
}
