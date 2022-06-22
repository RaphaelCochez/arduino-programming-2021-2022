void ds3231 (){
   DateTime now = rtc.now();
   if(((now.hour () == hour1)||(now.hour () == hour2)) && (now.minute () >= onMin) && (now.minute () <= offMin)){
   ontdooi_on_OR_off = ontdooiAan;}
   else{ 
   ontdooi_on_OR_off = ontdooiUit;}}
   
void lcdUpdate(){

  
  DateTime now = rtc.now();
  celcius = tempCelcius;
  lcd.setCursor(0,0);
  lcd.print("KI KAST 1");
  lcd.setCursor(14,0);
  lcd.print(now.hour ());
  lcd.print(":");
  lcd.print(now.minute ());
  lcd.setCursor(0,2);
  lcd.print("setTemp: ");
  lcd.setCursor(9,2);
  lcd.print(setTemp);
  lcd.setCursor(12,2);
  lcd.print("C");
  lcd.setCursor(0,3);
  lcd.print("Sensor: ");
  lcd.setCursor(9,3);
  lcd.print(celcius);
  lcd.setCursor(12,3);
  lcd.print("C");
  }
  
/*
 
 void lcdUpdateOndooien(){

  DateTime now = rtc.now();
  celcius = tempCelcius;
  lcd.setCursor(0,0);
  lcd.print("KI KAST 1");
  lcd.setCursor(14,0);
  lcd.print(now.hour ());
  lcd.print(":");
  lcd.print(now.minute ());
  lcd.setCursor(0,1);
  lcd.print("ontdooien actief");
  lcd.setCursor(0,2);
  lcd.print("setTemp: ");
  lcd.setCursor(9,2);
  lcd.print(setTemp);
  lcd.setCursor(12,2);
  lcd.print("C");
  lcd.setCursor(0,3);
  lcd.print("Sensor: ");
  lcd.setCursor(9,3);
  lcd.print(celcius);
  lcd.setCursor(12,3);
  lcd.print("C");}
*/  
void tempSensor (){
    sensors.setResolution(9); //gevoeligheid sensor
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
     else if (ledState <=3){
        ledState = 0;  }}

void tempToHighFunction (){
  unsigned long currentMillis1 = millis();
  digitalWrite(ontdooi, HIGH);
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
     else if (ledState1 <=3){
        ledState1 = 0;  }}

void tempOkFunction (){
  unsigned long currentMillis2 = millis();
  digitalWrite(ontdooi, HIGH);
  digitalWrite(klep, HIGH);
  digitalWrite(groep, HIGH);
  digitalWrite(ventilator, LOW);
    if (currentMillis2 - previousMillis2 >= interval2) {
       previousMillis2 = currentMillis2;
       digitalWrite(ventilator, HIGH);
       ledState2++;}}
void ontdooiFunction (){
  unsigned long currentMillis3 = millis();
  if (tempCelcius < ontdooimaxTemp){
    if (ledState3 == 0) {
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(ventilator, LOW);
              ledState3 = 1;}} 
    else if(ledState3 == 1){
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(klep, HIGH);
              ledState3 = 2;}}
    else if(ledState3 == 2){
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(groep, HIGH);
              ledState3 = 3;}}
    else if(ledState3 == 3){
         if (currentMillis3 - previousMillis3 >= interval1) {
              previousMillis3 = currentMillis3;
              digitalWrite(ontdooi, LOW);
              ledState3++;
        }}
     else if (ledState3 <=4){
          ledState3 = 0;  }}
     }
   
void IOcontrol (){
  switch (ontdooi_on_OR_off) {
    case ontdooiAan:
      ontdooiFunction ();
      lcdUpdateOndooien();
    break;
    case ontdooiUit:
    lcdUpdate();
      switch (temp){
          case tempHIGH:
               digitalWrite(ontdooi, HIGH);
               tempToHighFunction ();
               Serial.println("temphigh");
          break;
          case tempLOW:
               digitalWrite(ontdooi, HIGH);
               tempToLowFunction ();
               Serial.println("templow");
          break;
          case tempOK:
               tempOkFunction ();
               Serial.println("tempok");
          break;}
      break;}
}
