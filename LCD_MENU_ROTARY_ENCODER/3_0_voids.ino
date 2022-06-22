/*schrijf hier je methodes */
int readEncoder(){
  n = digitalRead(encoderPinA);
  if ((encoderLast == LOW) && (n == HIGH)) {
    if (digitalRead(encoderPinB) == LOW) {
      positie -= 1;} 
      else {
      positie += 1;}}
  encoderLast = n;
  if (positie > 40 || positie < -1){
    positie = 0;
  }
  return positie;
}
bool readencoderButton(){
bool keuze;  
if (digitalRead(encoderButton) == false){
    keuze = true;
}
else{
  keuze = false;
}
return keuze;
}

void menuselect(int a){
switch(a){
  case 1:
    keuzeLCD1();
    actiekeuze1();
    break;
  case 10:
    keuzeLCD2();
    actiekeuze2();
    break;
  case 20:
    keuzeLCD3();
    actiekeuze3();
    break;
  case 30:
    keuzeLCD4();
    actiekeuze4();
    break;}
}
