
#include <Bounce2.h>

Bounce2::Button button = Bounce2::Button();


#define BUTTON_PIN 2 
#define LED_PIN 5
bool ledState = LOW;

void setup() {
  button.attach(BUTTON_PIN, INPUT ); 
  button.interval(5); 
  button.setPressedState(LOW); 
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,ledState);
}

void loop() {
  button.update();
  if ( button.pressed() ) {
    ledState = !ledState;
    digitalWrite(LED_PIN,ledState);

  }
}
