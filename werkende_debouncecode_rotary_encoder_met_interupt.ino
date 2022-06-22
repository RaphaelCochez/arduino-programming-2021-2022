int switchPin = 3;                        //
int switchState = HIGH;                    
int debounce = 200;
volatile int pinA = 2;   // Rotary encoder Pin A
int pinB = 4;            // Rotary encoder Pin B
volatile int pinAstateCurrent = LOW;               
volatile int pinAStateLast = pinAstateCurrent;      
int counter = 0;
void setup() {
  Serial.begin (9600);                     
  pinMode (switchPin, INPUT_PULLUP);       
  pinMode(pinA, INPUT);                    

  attachInterrupt(digitalPinToInterrupt(pinA), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(switchPin), updateButton, CHANGE);
  pinMode (pinB, INPUT);
  
}

void loop() {



}

void updateEncoder() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  pinAstateCurrent = digitalRead(pinA);
  if ((pinAStateLast == LOW) && (pinAstateCurrent == HIGH)) {
    if (interrupt_time - last_interrupt_time > debounce) {
      if (digitalRead(pinB) == HIGH) {
        counter++;
      } else {
        counter--;
      }
    }
  last_interrupt_time = interrupt_time;
  }
  pinAStateLast = pinAstateCurrent;        
}

void updateButton(){
  switchState = digitalRead(switchPin);  
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounce) {
    if (switchState == LOW) {
      //doe iets
    } 
    last_interrupt_time = interrupt_time;
  }
}
