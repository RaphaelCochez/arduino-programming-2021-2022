#include <OneWire.h>
#include <DallasTemperature.h>
#define SensorDataPin 18

OneWire oneWire(SensorDataPin);//onewire setup 
DallasTemperature sensors(&oneWire); 

float tempCelcius;
int temp = tempCelcius;

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

void loop() {
sensors.setResolution(8);
//resolutionValue 8 = 0.5 °C
//resolutionValue 9 = 0.25 °C
//resolutionValue 10 = 0.125 °C
//resolutionValue 11 = 0.0625°C
sensors.requestTemperatures();// send the command to get temperatures
tempCelcius = sensors.getTempCByIndex(0); 

Serial.print("Temperature: ");//display this text in the serial monitor
Serial.print(tempCelcius);// print the temperature in Celsius
Serial.print("°C");//display this text in the serial monitor
Serial.println("");
}
