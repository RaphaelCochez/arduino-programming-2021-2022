/*schrijf hier je variabelen*/
int val;
int encoderPinA = 4;
int encoderPinB = 3;
int encoderButton = 2;

int encoderLast = LOW;
int n = LOW;

int buttonstate;

int x;
int positie;
enum menu {keuze1, keuze2, keuze3, keuze4};
enum menu opties;


#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int led1 = 5;
int led2 = 6;
