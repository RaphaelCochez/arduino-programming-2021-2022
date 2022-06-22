/*schrijf hier je LCD code*/
void keuzeLCD1(){
  lcd.setCursor(0,0);
  lcd.print("         ");
  lcd.setCursor(0,0);
  lcd.print("-> optie 1");
  lcd.setCursor(0,1);
  lcd.print("          ");
  lcd.setCursor(0,1);
  lcd.print("   optie 2");
}
void keuzeLCD2(){
  lcd.setCursor(0,0);
  lcd.print("          ");
  lcd.setCursor(0,0);
  lcd.print("   optie 1");
  lcd.setCursor(0,1);
  lcd.print("          ");
  lcd.setCursor(0,1);
  lcd.print("-> optie 2");
}
void keuzeLCD3(){
  lcd.setCursor(0,0);
  lcd.print("         ");
  lcd.setCursor(0,0);
  lcd.print("-> optie 3");
  lcd.setCursor(0,1);
  lcd.print("          ");
  lcd.setCursor(0,1);
  lcd.print("   optie 4");
}
void keuzeLCD4(){
  lcd.setCursor(0,0);
  lcd.print("          ");
  lcd.setCursor(0,0);
  lcd.print("   optie 3");
  lcd.setCursor(0,1);
  lcd.print("          ");
  lcd.setCursor(0,1);
  lcd.print("-> optie 4");
}

void actiekeuze1(){
  bool button = readencoderButton();
  if (button == true){
    digitalWrite(led1, HIGH);
  }
}
void actiekeuze2(){
  bool button = readencoderButton();
  if (button == true){
    digitalWrite(led1, LOW);
  }
}
void actiekeuze3(){
  bool button = readencoderButton();
  if (button == true){
    digitalWrite(led2, HIGH);
  }
}
void actiekeuze4(){
  bool button = readencoderButton();
  if (button == true){
    digitalWrite(led2, LOW);
  }
}
