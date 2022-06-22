
void loop() {
    Serial.print("Temperature: ");//display this text in the serial monitor
    Serial.print(tempCelcius);// print the temperature in Celsius
    Serial.print("°C");//display this text in the serial monitor
    Serial.println("");
ds3231 ();
tempSensor ();
tempSensorPrint ();
tempIndex ();
IOcontrol ();
}
