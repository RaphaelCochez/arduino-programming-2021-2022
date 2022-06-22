#include <EEPROM.h>
//setup knoppen
const int button1 = 2;
const int button2 = 3;
volatile bool state1 = LOW;
volatile bool state2 = LOW;

//setup leds
const int LED_CHANNEL_COUNT = 3;
const int LED_COUNT = 3;
int LED_PINS[LED_CHANNEL_COUNT] = {4, 5, 6};
int ledState1 = LOW;
int ledState2 = LOW; 
int ledState3 = LOW;  
enum LEDS {
  LED_VEILIG = 0,
  LED_GEVAAR_1 = 1,
  LED_GEVAAR_2 = 2
};
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
const long interval = 1000;


//setup states
int state_sensor2 = 0;

enum PROGRAM {
VEILIG = 0,
TREIN_AANKOMST = 1,
TREIN_VERTREK = 2  
};
enum PROGRAM opties;


//setup eeprom
int lastbuttonstate = 1;
long unsigned int lastpress;
int debouncetime = 20;
int counter;

void setup() {
// IO pinnen  

pinMode(button1,INPUT);
pinMode(button2,INPUT);

for(int i=0; i< LED_COUNT; i++){
    pinMode(LED_PINS[i], OUTPUT);
}
attachInterrupt(digitalPinToInterrupt(button1), myISR1, RISING);
attachInterrupt(digitalPinToInterrupt(button2), myISR2, RISING);

// serieele communicatie
Serial.begin(9600);
// de counter de waarde van adres O geven
counter = EEPROM.read(0);
// een 0 naar adres 0 schrijven om bijvoorbeeld de counter te kunnen resetten
EEPROM.write(0,0);
}

void loop() {
unsigned long currentMillis = millis();
switch(opties){
  case VEILIG:
    if (currentMillis - previousMillis1 >= interval) {
        previousMillis1 = currentMillis;
        if (ledState1 == LOW) {
          ledState1 = HIGH;
        } else {
          ledState1 = LOW;
        }
        digitalWrite(LED_PINS[LED_VEILIG],ledState1);
      }
  break;
  case TREIN_AANKOMST:
        digitalWrite(LED_PINS[LED_VEILIG], LOW);
        if(currentMillis - previousMillis2 > interval) {
        previousMillis2 = currentMillis;   
        if (ledState2 == LOW)
        ledState2 = HIGH;
        else
        ledState2 = LOW;
        digitalWrite(LED_PINS[LED_GEVAAR_1], ledState2);
        digitalWrite(LED_PINS[LED_GEVAAR_2], !ledState2);
        }
  break;
  case TREIN_VERTREK:
  
  break;
  }
}

void myISR1() {
    delay(50);
    state1 = !state1; 
    if (state1 =! !state1){
    opties = VEILIG;  
    }
}
void myISR2() {
    delay(50);
    state2 = !state2; 
    if (state2 =! !state2){
    state_sensor2++;  
    }
    if (state_sensor2 == 1){
    opties = TREIN_AANKOMST;    
    }
    else if (state_sensor2 == 2){
    opties = TREIN_VERTREK;  
    }
    else if (state_sensor2 > 2){
    state_sensor2 = 0;
    }

}
