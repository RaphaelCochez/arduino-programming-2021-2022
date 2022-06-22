int val;
int encoder0PinA = 39;
int encoder0PinB = 36;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int encoder0Button = 34;
int n = LOW;
int buttonstate;
int x;
enum temp_control_settings {temp, settings, control} ;
enum temp_control_settings opties;



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
  encoder0PinALast = n;
buttonstate = digitalRead(encoder0Button);
unsigned long timer = millis();

if (buttonstate == LOW){
  if ( timer - lastButtonPress > 50) {
    x++;}
  if (x == 0 || x == 1){
    opties = temp;}
  else if( x == 2){
    opties = control;}
  else if( x == 3){
    opties = settings;}
  else if (x > 4) {
    x = 0;}
  lastButtonPress = millis();
}

delay(1);

switch (opties){
  case temp:
Serial.print ("settemp = ");
Serial.print (encoder0Pos);
Serial.print (" C°");
Serial.println ("");
    break;
  case control:
Serial.print ("Control ");
Serial.println ("");
Serial.print (" is nu actief");
Serial.println ("");   
    break;
  case settings:
Serial.print ("settings = ");
Serial.print ("");
Serial.println ("lolol");  
Serial.print (""); 
    break;
  }


}
