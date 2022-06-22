#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Raphael Cochez");
  lcd.setCursor(0,1);
  lcd.print("prototype KI V6");
   lcd.setCursor(0,2);
  lcd.print("31.01.2022");
   lcd.setCursor(0,3);
  lcd.print("Power By 5Volts");
  delay(2000);
  lcd.clear();
}
void lcdUpdate(){
  lcd.setCursor(0,0);
  lcd.print("KI KAST 1");
  lcd.setCursor(0,2);
  lcd.print("setTemp: ");
  lcd.setCursor(10,2);
  lcd.print(counter);
  lcd.setCursor(0,3);
  lcd.print("Sensor: ");
}

void loop()
{
  lcdUpdate();
}
