/*
   Bas on Tech - Arduino tutorial
   https://arduino-lessen.nl

   PIN AANSLUITINGEN LCD

   SDA is serial data
   SCL is serial clock

   GND --> GND (wit)
   VCC --> 5V  (grijs)
   SDA --> A4  (rood)
   SCL --> A5  (blauw)

   I2C aansluitingen per Arduino:
   Uno, Ethernet    A4 (SDA), A5 (SCL)
   Mega2560         20 (SDA), 21 (SCL)
   Leonardo          2 (SDA),  3 (SCL)
   Due              20 (SDA), 21 (SCL) of SDA1, SCL1

*/

//// ALGEMEEN ////

// Variabele voor het aantal milliseconden sinds de Arduino is gestart
unsigned long currentMillis = 0;       

//// LCD SCHERM ////

// Bibliotheek voor communicatie met I2C / TWI apparaten
#include <Wire.h>

// Bibliotheek voor het LCD scherm
#include <LiquidCrystal_I2C.h>

/*
   Stel hier in welke chip en foromaat LCD je hebt
   Gebruik 0x27 als je chip PCF8574 hebt van NXP
   Gebruik 0x3F als je chip PCF8574A hebt van Ti (Texas Instruments)
   De laatste twee getallen geven het formaat van je LCD aan
   bijvoorbeeld 20x4 of 16x2
*/
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);

const int LCDWidth = 20;
const int LCDHeight = 4;

/*
   Deze iconen zijn online gemaakt met de LCD symbool generator op:
   https://maxpromer.github.io/LCD-Character-Creator/
*/
const byte clockIcon[] = {
  0x0E,
  0x11,
  0x15,
  0x15,
  0x17,
  0x11,
  0x11,
  0x0E
};

const byte finishFlagIcon[] = {
  0x1F,
  0x15,
  0x1B,
  0x15,
  0x1F,
  0x11,
  0x11,
  0x11
};

const int intervalLCD = 250;                // update het LCD scherm elke 250ms
unsigned long previousMillisLCD = 0;        // tijdstip in milliseconden van vorige LCD update

//// DRUKKNOPPEN ////
const int intervalButtonRead = 100;         // tijd in milliseconden tussen het uitlezen van de drukknop
unsigned long previousMillisButton = 0;     // tijdstip in milliseconden van vorig uitleesmoment van drukknop

const int buttonStartPin = 12;              // start/stop knop pin
int buttonStartState = LOW;                 // staat van de start/stop knop
int buttonStartStatePrevious = LOW;         // vorige staat van start/stop knop

const int buttonResetPin = 10;              // reset knop pin
int buttonResetState = LOW;                 // staat van de reset knop
int buttonResetStatePrevious = LOW;         // vorige staat van reset knop

bool redrawLCD = true;                      // geeft aan of het scherm moet worden bijgewerkt


//// STOPWATCH ////
bool stopWatchActive = false;                 // geeft aan of de stopwacht loopt
unsigned long stopWatchMillis = 0;          // tijdstip in milliseconden waarop stopwatch begon te lopen
unsigned long stopWatchTimeElapsed = 0;     // verstreken tijd in milliseconden sinds stopwatch begon te lopen

// Start de stopwatch
void stopWatchStart() {
  stopWatchMillis = currentMillis;
  stopWatchActive = true;
  redrawLCD = true;
}

// Stopt de stopwatch
void stopWatchStop() {
  stopWatchTimeElapsed = currentMillis - stopWatchMillis;
  stopWatchActive = false;
  redrawLCD = true;
}

// Reset de stopwatch
void stopWatchReset() {
  stopWatchActive = false;
  stopWatchMillis = 0;
  stopWatchTimeElapsed = 0;
  buttonStartState = LOW;                  
  buttonStartStatePrevious = LOW;
  buttonResetState = LOW;                  
  buttonResetStatePrevious = LOW;
  redrawLCD = true;
}

//// OPMAAK FUNCTIES ////

// Zorgt dat getallen onder de 10 een extra 0 krijgen dus 8 wordt 08, 1 wordt 01 etc.
String formatZeros(int number) {

  if (number < 10) {
    return "0" + String(number);
  } else {
    return String(number);
  }
}

// Maakt van de tijd in ms. een String bijv. "0:01:23.495" voor 0 uur, 1 minuut, 23 seconden en 495 honderdste.
String formatTimeToString(unsigned long time) {

  unsigned long timeSeconds = time / 1000;       // zet de milliseconden om in seconden door te delen door 1000
  int mSeconds = time % 1000;                    // de rest milliseconden wat nog overblijft na het delen 

  int hours = timeSeconds / 3600;                // bereken de uren door te delen door 3600 (3600 seconden = 60 seconden x 60 minuten)
  int remainder = timeSeconds % 3600;            // bereken de overgebleven seconden door te rest-delen door 3600. (3600 seconden = 60 seconden x 60 minuten)

  int minutes = remainder / 60;                  // bereken de minuten door te delen door 60 (1 minuut = 60 seconden)
  int seconds = remainder % 60;                  // bereken de seconden door te rest-delen door 60 (1 minuut = 60 seconden)

  // Maak van 9 -> "009" en van 87 -> "087"
  if (mSeconds < 10) {
    mSeconds = "00" + mSeconds;
  } else if (mSeconds < 100) {
    mSeconds = "0" + mSeconds;
  }

  return String(hours) + ":" + formatZeros(minutes) + ":" + formatZeros(seconds) + "." + String(mSeconds);
}

/* 
 * Rekent uit hoe veel ruimte je aan de zijkant moet overlaten om in het midden uit te komen
 * Stel je scherm is 20 breed, je tekst is 16 breed. Je wilt dan aan beide kanten 2 posities vrijhouden
 * Offset kun je gebruiken als je bijvoorbeeld voor je tekst nog een symbool zet.
 */
int getMarginForCenter(String text, int offset) {
  int margin = LCDWidth - (text.length() + offset);
  return margin / 2;
}

// Functie voor het uitlezen van de drukknop
void readButtonState() {

  // Als het tijdsverschil met de vorige uitlezing groter is dan intervalButtonRead
  if (currentMillis - previousMillisButton > intervalButtonRead) {

    // Lees de digitale waarden van de schakelaars (LOW/HIGH)
    buttonStartState = digitalRead(buttonStartPin);
    buttonResetState = digitalRead(buttonResetPin);

    // Als de start knop is ingedrukt
    if (buttonStartState == HIGH && buttonStartStatePrevious == LOW) {

      // Als de stopwatch nog niet loopt start deze. Loopt de stopwatch, stop deze.
      if (!stopWatchActive) {
        stopWatchStart();
      } else {
        stopWatchStop();
      }

      buttonStartStatePrevious = HIGH;

    }

    // Als de start knop wordt losgelaten en de stopwatch loopt
    if (buttonStartState == LOW && buttonStartStatePrevious == HIGH && stopWatchActive) {
      buttonStartStatePrevious = LOW;
    }

    // Als de reset knop wordt ingedrukt, reset de stopwatch
    if (buttonResetState == HIGH) {
      stopWatchReset();
    }

    // sla het huidige tijdstip op in previousMillisButton
    previousMillisButton = currentMillis;

  }
}


// Functie om het LCD scherm bij te werken
void updateLCD() {

  // Als het tijdsverschil met de vorige uitlezing groter is dan intervalLCD
  if (currentMillis - previousMillisLCD > intervalLCD) {

    if (redrawLCD || stopWatchActive) {

      lcd.clear();

      // Als de stopwacth niet loopt en de verstreken tijd is 0
      if (!stopWatchActive && stopWatchTimeElapsed == 0) {
        lcd.setCursor(0, 0);                 // zet de cursor op positie 1, regel 1
        lcd.print("DRUK OP DE STARTKNOP");
        lcd.setCursor(0, 2);                 // zet de cursor op positie 1, regel 3
        lcd.print(" OM TIJD TE STARTEN");
      }

      // Als de stopwatch loopt
      if (stopWatchActive) {

        // Bereken de verstreken tijd en maak deze op in het U:MM:SS.m formaat
        String formattedTime = formatTimeToString(currentMillis - stopWatchMillis);
        
        // Bereken het midden voor de tekst met getMarginForCenter(formattedTime, 4)
        // De offset van 4 komt door de volgende posities:
        // 1. het klok icoon
        // 2. de spatie achter het klok icoon
        // 3. de m van ms
        // 4. de s van ms
        lcd.setCursor(getMarginForCenter(formattedTime, 4), 1);

        lcd.write(0);                // teken het klok icoon van geheugenpositie 0
        lcd.print(" ");              // schrijf een spatie
        lcd.print(formattedTime);    // schrijf de verstreken tijd
        lcd.print("ms");             // schrijf ms
      }

      // Als de stopwatch is stop gezet
      if (!stopWatchActive && stopWatchTimeElapsed > 0) {

        // Bereken het midden voor de tekst met getMarginForCenter(formatTimeToString(stopWatchTimeElapsed), 2)
        // De offset van 2 komt door de volgende posities:
        // 1. het finish icoon
        // 2. de spatie achter het finish icoon
        lcd.setCursor(getMarginForCenter(formatTimeToString(stopWatchTimeElapsed), 2), 1);

        lcd.write(1);                                  // teken het finish icoon van geheugenpositie 0
        lcd.print(" ");                                // schrijf een spatie
        lcd.print(formatTimeToString(stopWatchTimeElapsed));   // schrijf de opgemaakte verstreken tijd
        lcd.setCursor(0, 3);                           // zet de cursor op positie 1, regel 4
        lcd.print("DRUK OP DE RESETKNOP");             
      }

      redrawLCD = false;
      
    }

    // sla het huidige tijdstip op in previousMillisLCD
    previousMillisLCD = currentMillis;

  }

}

void setup() {
  Serial.begin(9600);                   // stel de seri??le monitor in

  // LCD
  lcd.init();                           // initialiseer het LCD scherm
  lcd.backlight();                      // zet de backlight aan
  lcd.createChar(0, clockIcon);         // definieer een symbool in geheugen positie 0
  lcd.createChar(1, finishFlagIcon);    // definieer een symbool in geheugen positie 0

}

void loop() {

  currentMillis = millis();             // sla de huidige tijd op
  readButtonState();                    // lees de huidige staat van de drukknopen uit
  updateLCD();                          // werk het LCD scherm bij

}

