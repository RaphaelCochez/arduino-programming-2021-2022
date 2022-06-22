int val;
int encoder0PinA = 39;
int encoder0PinB = 36;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int encoder0Button = 34;
int n = LOW;
int buttonstate;
unsigned long lastButtonPress = 0;
void setup() {
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (encoder0Button, INPUT);
  Serial.begin (115200);
}

void loop() {
  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
  }
  if(encoder0Pos > 20 || encoder0Pos < -20){
    encoder0Pos = 0;
  }
  encoder0PinALast = n;
buttonstate = digitalRead(encoder0Button);
unsigned long x = millis();

if (buttonstate == LOW){
  if ( x - lastButtonPress > 50) {
      Serial.println("Button pressed!");
    }

    // Remember last button press event
    lastButtonPress = millis();
}

delay(1);




Serial.print ("settemp = ");
Serial.print (encoder0Pos);
Serial.print (" C°");
Serial.println ("");

}
