#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <EEPROM.h>
int address = 0;
int counter = 0;

#include <Bounce2.h>
#define BUTTON_PIN 2
#define LED_PIN 5
Bounce b = Bounce(); // Instantiate a Bounce object

void setup() {
  lcd.init();
  lcd.backlight();
  
  b.attach(BUTTON_PIN,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  b.interval(25); // Use a debounce interval of 25 milliseconds
  checkCountState();
}

void loop() {

   b.update(); // Update the Bounce instance
   if ( b.fell() ) {  // Call code if button transitions from HIGH to LOW
     counter +=1;
   }
   
   lcd.setCursor(0,0);
   lcd.print(counter); 
   

    EEPROM.update(0,counter);
  delay(100);
}
void checkCountState(){
   Serial.println("Count status after restart: ");
   counter = EEPROM.read(0);
   lcd.setCursor(0,0);
   lcd.print(counter);
}
