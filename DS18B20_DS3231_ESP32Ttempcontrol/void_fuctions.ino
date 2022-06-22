void ds3231 (){
   DateTime now = rtc.now();

   if(((now.hour () == hour1)||(now.hour () == hour2)) && (now.minute () >= onMin) && (now.minute () <= offMin)){
   Serial.println("ontdooien aan ");
   ontdooi_on_OR_off = ontdooiAan;}
   else{
   Serial.println("ontdooien uit "); 
   ontdooi_on_OR_off = ontdooiUit;}
}

void tempSensor (){
    sensors.setResolution(9);
    //resolutionValue 8 = 0.5 °C
    //resolutionValue 9 = 0.25 °C
    //resolutionValue 10 = 0.125 °C
    //resolutionValue 11 = 0.0625°C
    sensors.requestTemperatures();// send the command to get temperatures
    tempCelcius = sensors.getTempCByIndex(0);  }

void tempSensorPrint (){
  Serial.print("Temperature: ");//display this text in the serial monitor
  Serial.print(tempCelcius);// print the temperature in Celsius
  Serial.print("°C");//display this text in the serial monitor
  Serial.println(""); }

void tempIndex (){
  unsigned long timerTemp = millis ();
  if ( tempCelcius <= minTemp){
    temp = tempHIGH;}
  else if ( tempCelcius > minTemp && tempCelcius >= maxTemp){
    temp = tempLOW;}
  else if ((tempCelcius > minTemp) && (tempCelcius < maxTemp)){
    if (timerTemp - tempCount >= tempInterval){
        temp = tempOK;
        tempCount = millis();}}}

void tempToLowFunction (){
unsigned long currentMillis = millis();
digitalWrite(ontdooi, LOW);
    if (ledState == 0) {
         if (currentMillis - previousMillis >= interval1) {
              previousMillis = currentMillis;
              digitalWrite(ventilator, LOW);
              ledState++;}} 
    else if(ledState == 1){
         if (currentMillis - previousMillis >= interval1) {
              previousMillis = currentMillis;
              digitalWrite(klep, LOW);
              ledState++;}}
    else if(ledState == 2){
         if (currentMillis - previousMillis >= interval1) {
              previousMillis = currentMillis;
              digitalWrite(groep, LOW);
              ledState++;}}
     else if (ledState ==3){
        ledState = 0;  }}

void tempToHighFunction (){
unsigned long currentMillis1 = millis();
digitalWrite(ontdooi, LOW);
    if (ledState1 == 0) {
         if (currentMillis1 - previousMillis1 >= interval1) {
              previousMillis1 = currentMillis1;
              digitalWrite(ventilator, HIGH);
              ledState1++;}} 
    else if(ledState1 == 1){
         if (currentMillis1 - previousMillis1 >= interval1) {
              previousMillis1 = currentMillis1;
              digitalWrite(klep, HIGH);
              ledState1++;}}
    else if(ledState1 == 2){
         if (currentMillis1 - previousMillis1 >= interval1) {
              previousMillis1 = currentMillis1;
              digitalWrite(groep, HIGH);
              ledState1++;}}
     else if (ledState1 ==3){
        ledState1 = 0;  }}

void tempIsOkFunction (){
unsigned long currentMillis2 = millis();
digitalWrite(ontdooi, LOW);
      digitalWrite(klep, LOW);
      digitalWrite(groep, LOW);
      digitalWrite(ventilator, HIGH);
      if (currentMillis2 - previousMillis2 >= interval2) {
            previousMillis2 = currentMillis2;
            digitalWrite(ventilator, LOW);
            ledState2++;}}

void ontdooiFunction (){
unsigned long currentMillis3 = millis();

    if (ledState3 == 0) {
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(ventilator, HIGH);
              ledState3 = 1;}} 
    else if(ledState3 == 1){
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(klep, LOW);
              ledState3 = 2;}}
    else if(ledState3 == 2){
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(groep, LOW);
              ledState3 = 3;}}
    else if(ledState3 == 3){
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(ontdooi, HIGH);
              ledState3++;}}
     else if (ledState3 ==4){
          ledState3 = 0;  }
}


        
void IOcontrol (){
 
  switch (ontdooi_on_OR_off) {
    case ontdooiAan:
      ontdooiFunction ();
    break;
    case ontdooiUit:
      switch (temp){
          case tempHIGH:
               tempToHighFunction ();
          break;
          case tempLOW:
               tempToLowFunction ();
          break;
          case tempOK:
               tempIsOkFunction ();
          break;}
      break;}
}
