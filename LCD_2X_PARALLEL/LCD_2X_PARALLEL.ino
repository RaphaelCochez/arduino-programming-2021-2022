//LCDS
#include <LiquidCrystal_I2C.h> // https://github.com/johnrickman/LiquidCrystal_I2C (install as zip)
int LCD_COLUMNS = 20;
int LCD_ROWS = 4;
LiquidCrystal_I2C lcd1(0x27, 16, 4); //ADRESS IS BELANGRIJK
LiquidCrystal_I2C lcd2(0x3F, 20, 4); //LCD_COLUMNS,LCD_ROWS
void setup() {
  // put your setup code here, to run once:
lcd1.init();
lcd2.init();
lcd1.backlight();
lcd2.backlight();
lcd1.setCursor(0,0);
lcd1.print("11.04.2022");
lcd2.setCursor(0,0);
lcd2.print("12.04.2022");
delay(4000);
lcd1.clear();
lcd2.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
lcd1.setCursor(0,0);
lcd1.print("hoi");
lcd2.setCursor(0,0);
lcd2.print("raphael");
}
