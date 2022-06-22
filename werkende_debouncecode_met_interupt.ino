const byte ledPin = 4;
const byte interruptPin = 2;
volatile byte state = LOW;
int debounce = 200;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), my_interrupt_handler, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);

}

void my_interrupt_handler()
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > debounce) 
  {
    state = !state;
  }
  last_interrupt_time = interrupt_time;
}
