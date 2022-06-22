const int rotary_pin_count = 3;
int rotary_encoder[]{3,4,5};
enum rotary_pin {links = 0, rechts = 1, knop = 2};

int state[]{LOW, LOW};
enum state_pin{NEW = 0, LAST = 1 };
int rotary_encoder_positie = 0;


const int led_pin_count = 2;
int led[]{6,7};
enum led_pin{led_links = 0, led_rechts = 1 };




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  for (int r= 0; r < rotary_pin_count; r++) {
    pinMode(rotary_encoder[r], INPUT);}
  for (int i= 0; i < led_pin_count; i++) {
    pinMode(led[i], OUTPUT);}
}

void read_rotary_encoder (){
  if ((state[LAST] == LOW)) {
    if (digitalRead(rotary_encoder[links])== LOW) {
      rotary_encoder_positie--;}
      else {
      rotary_encoder_positie++;}
  }
  delay(10);
  state[LAST] = state[NEW];
}

void loop() {
read_rotary_encoder ();
Serial.println(rotary_encoder_positie);
}
