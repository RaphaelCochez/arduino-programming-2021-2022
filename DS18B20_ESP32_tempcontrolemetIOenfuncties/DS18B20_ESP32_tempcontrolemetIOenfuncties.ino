/*temperatuursensor en vergelijking*/
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
/*millis fucties*/
int ledState = 0;
int ledState1 = 0;   
int ledState2 = 0;
int ledState3 = 0;    
unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
const long interval = 1000;    
const long interval2 = 30000;    

/*IO pinnen */
#define led1 13
#define led2 12
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
delay (1000);
}
void tempSensor (){
  sensors.setResolution(9);
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
    temp = tempHIGH;}
  else if ( tempCelcius > minTemp && tempCelcius >= maxTemp){
    temp = tempLOW;}
  else if ((tempCelcius > minTemp) && (tempCelcius < maxTemp)){
    if (timerTemp - tempCount >= tempInterval){
        temp = tempOK;
        tempCount = millis();}}
}
void een (){
unsigned long currentMillis = millis();
    if (ledState == 0) {
         if (currentMillis - previousMillis >= interval) {
              previousMillis = currentMillis;
              digitalWrite(led1, LOW);
              ledState++;}} 
    else if(ledState == 1){
         if (currentMillis - previousMillis >= interval) {
              previousMillis = currentMillis;
              digitalWrite(led2, LOW);
              ledState++;}}
    else if(ledState == 2){
         if (currentMillis - previousMillis >= interval) {
              previousMillis = currentMillis;
              digitalWrite(led3, LOW);
              ledState++;}}
     else if (ledState ==3){
        ledState = 0;  }
}
void twee (){
unsigned long currentMillis1 = millis();
    if (ledState1 == 0) {
         if (currentMillis1 - previousMillis1 >= interval) {
              previousMillis1 = currentMillis1;
              digitalWrite(led1, HIGH);
              ledState1++;}} 
    else if(ledState1 == 1){
         if (currentMillis1 - previousMillis1 >= interval) {
              previousMillis1 = currentMillis1;
              digitalWrite(led2, HIGH);
              ledState1++;}}
    else if(ledState1 == 2){
         if (currentMillis1 - previousMillis1 >= interval) {
              previousMillis1 = currentMillis1;
              digitalWrite(led3, HIGH);
              ledState1++;}}
     else if (ledState1 ==3){
        ledState1 = 0;  }
}
void drie (){
unsigned long currentMillis2 = millis();
    
    
              digitalWrite(led2, LOW);
              digitalWrite(led3, LOW);
              digitalWrite(led3, HIGH);
          if (currentMillis2 - previousMillis2 >= interval2) {
              previousMillis2 = currentMillis2;
              digitalWrite(led3, LOW);
              ledState2++;}
 
}

void vier (){
unsigned long currentMillis3 = millis();
    if (ledState3 == 0) {
         if (currentMillis3 - previousMillis3 >= interval) {
              previousMillis3 = currentMillis3;
              digitalWrite(led1, HIGH);
              ledState3++;}} 
    else if(ledState1 == 3){
         if (currentMillis3 - previousMillis3 >= interval) {
              previousMillis3 = currentMillis3;
              digitalWrite(led2, HIGH);
              ledState3++;}}
    else if(ledState3 == 2){
         if (currentMillis3 - previousMillis3 >= interval) {
              previousMillis3 = currentMillis3;
              digitalWrite(led3, HIGH);
              ledState3++;}}
    else if(ledState3 == 3){
         if (currentMillis3 - previousMillis3 >= interval) {
              previousMillis3 = currentMillis3;
              digitalWrite(led4, HIGH);
              ledState3++;}}
     else if (ledState3 ==4){
        ledState3 = 0;  }
}
void IOcontrol (){
  switch (temp){
    case tempHIGH:
      twee ();
    break;
    case tempLOW:
      een ();
    break;
    case tempOK:
      drie ();
    break;
  }
}


void loop() {
tempSensor ();
tempSensorPrint ();
tempIndex ();
IOcontrol ();
}
