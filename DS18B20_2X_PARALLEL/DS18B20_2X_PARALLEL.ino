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
}

void loop() {
sensors1.setResolution(9); //gevoeligheid sensor
sensors2.setResolution(9); //gevoeligheid sensor 
sensors1.requestTemperatures();// send the command to get temperatures
sensors2.requestTemperatures();// send the command to get temperatures
tempCelcius1 = sensors1.getTempCByIndex(0);
tempCelcius2 = sensors2.getTempCByIndex(0);
Serial.print("Temperature: ");//display this text in the serial monitor
Serial.print(tempCelcius1);// print the temperature in Celsius
Serial.print("°C");//display this text in the serial monitor
Serial.println("");
Serial.print("Temperature: ");//display this text in the serial monitor
Serial.print(tempCelcius2);// print the temperature in Celsius
Serial.print("°C");//display this text in the serial monitor
Serial.println("");
}
