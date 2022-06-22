const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;

byte dataRED;
byte dataGREEN;
byte data;
byte dataArray[10];

void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
dataArray[0] = 0xFF; //11111111
dataArray[1] = 0xFE; //11111110
dataArray[2] = 0xFC; //11111100
dataArray[3] = 0xF8; //11111000
dataArray[4] = 0xF0; //11110000
dataArray[5] = 0xE0; //11100000
dataArray[6] = 0xC0; //11000000
dataArray[7] = 0x80; //10000000
dataArray[8] = 0x00; //00000000
dataArray[9] = 0xE0; //11100000
}

void loop() {
  // put your main code here, to run repeatedly:
    
    shiftOutPin (1,true);
}
void shiftOutPin (int pin, bool state){
   if (state == true){
    data = dataArray[pin];
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, data);
    digitalWrite(latchPin, 1);
   }
   if state == false){
    
   }
}

void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);
  for (i=7; i>=0; i--)  {
  digitalWrite(myClockPin, 0);
    if ( myDataOut & (1<<i) ) {
      pinState= 1;}
    else {
      pinState= 0;}
  digitalWrite(myDataPin, pinState);
  digitalWrite(myClockPin, 1);
  digitalWrite(myDataPin, 0);}
  digitalWrite(myClockPin, 0);}
