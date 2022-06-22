const int LED_COUNT = 3;
int LED_PINS[LED_COUNT] = {5, 6, 7};
enum LEDS {
  led_rood  = 0,
  led_groen = 1,
  led_geel  = 2
};
void setup() {
  for(int i=0; i< LED_COUNT; i++){
    pinMode(LED_PINS[i], OUTPUT);
  }
  Serial.begin(9600);  
}

void loop() {
  
while (Serial.available() == 0){}  
String v = Serial.readString();
int var = v.toInt();
switch (var){
  case 0:
    digitalWrite(LED_PINS[led_rood],LOW);
    break;
  case 1:
    digitalWrite(LED_PINS[led_rood],HIGH);
    break;
  case 2:
    digitalWrite(LED_PINS[led_groen],LOW);
    break;
  case 3:
    digitalWrite(LED_PINS[led_groen],HIGH);
    break;
  case 4:
    digitalWrite(LED_PINS[led_geel],LOW);
  break;
  case 5:
    digitalWrite(LED_PINS[led_geel],HIGH);
  break;
}

}
