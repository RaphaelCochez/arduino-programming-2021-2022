
void setup() {
  Serial.begin (115200);
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
  digitalWrite(ventilator, HIGH);
  digitalWrite(klep, HIGH);
  digitalWrite(groep, HIGH);
  digitalWrite(ontdooi, HIGH);
  Wire.setClock(10000);
  sensors.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Raphael Cochez");
  lcd.setCursor(0,1);
  lcd.print("prototype KI V6");
  lcd.setCursor(0,2);
  lcd.print("");
  lcd.setCursor(0,3);
  lcd.print("");
  delay(2000);
  lcd.clear();
}
