void setup() {
lcd.init();                     
lcd.backlight();
lcd.clear();
pinMode (encoderPinA, INPUT);
pinMode (encoderPinB, INPUT);
pinMode (encoderButton, INPUT);
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
Serial.begin (9600);
}
