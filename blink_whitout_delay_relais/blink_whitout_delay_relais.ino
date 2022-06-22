#define led1 27
#define led2 14
#define led3 12
#define led4 13

int ledState = 0;
int ledState1 = 0;   
int ledState2 = 0;  
unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
const long interval = 2000;    
const long interval2 = 30000;     
void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH); 
delay(1000);
}

void test1(){
    unsigned long currentMillis = millis();
    if (ledState == 0) {
         if (currentMillis - previousMillis >= interval) {
              previousMillis = currentMillis;
              digitalWrite(led1, LOW);
              ledState++;}} 
    else if(ledState == 1){
         if (currentMillis - previousMillis >= interval) {
              previousMillis = currentMillis;
              digitalWrite(led2, LOW);
              ledState++;}}
    else if(ledState == 2){
         if (currentMillis - previousMillis >= interval) {
              previousMillis = currentMillis;
              digitalWrite(led3, LOW);
              ledState++;}}
    else if(ledState == 3){
         if (currentMillis - previousMillis >= interval) {
              previousMillis = currentMillis;
              digitalWrite(led4, LOW);
              ledState++;}}
     else if (ledState ==4){
        ledState = 0;  }
}

void test2(){
    unsigned long currentMillis1 = millis();
    if (ledState1 == 0) {
         if (currentMillis1 - previousMillis1 >= interval) {
              previousMillis1 = currentMillis1;
              digitalWrite(led1, HIGH);
              ledState1++;}} 
    else if(ledState1 == 1){
         if (currentMillis1 - previousMillis1 >= interval) {
              previousMillis1 = currentMillis1;
              digitalWrite(led2, HIGH);
              ledState1++;}}
    else if(ledState1 == 2){
         if (currentMillis1 - previousMillis1 >= interval) {
              previousMillis1 = currentMillis1;
              digitalWrite(led3, HIGH);
              ledState1++;}}
    else if(ledState1 == 3){
         if (currentMillis1 - previousMillis1 >= interval) {
              previousMillis1 = currentMillis1;
              digitalWrite(led4, HIGH);
              ledState1++;}}
     else if (ledState1 ==4){
        ledState1 = 0;  }
}


void test3(){
    unsigned long currentMillis2 = millis();
    if (ledState2 == 0) {
         if (currentMillis2 - previousMillis2 >= interval) {
              previousMillis2 = currentMillis2;
              digitalWrite(led1, LOW);
              ledState2++;}} 
    else if(ledState2 == 1){
         if (currentMillis2 - previousMillis2 >= interval) {
              previousMillis2 = currentMillis2;
              digitalWrite(led2, LOW);
              ledState2++;}}
    else if(ledState2 == 2){
         if (currentMillis2 - previousMillis2 >= interval) {
              previousMillis2 = currentMillis2;
              digitalWrite(led3, LOW);
              ledState2++;}}
    else if(ledState2 == 3){
         if (currentMillis2 - previousMillis2 >= interval) {
              previousMillis2 = currentMillis2;
              digitalWrite(led3, HIGH);
              ledState2++;}}
     else if (ledState2 == 4){
          if (currentMillis2 - previousMillis2 >= interval2) {
              previousMillis2 = currentMillis2;
              digitalWrite(led2, HIGH);
              ledState2++;}}
     else if (ledState2 == 5){
          if (currentMillis2 - previousMillis2 >= interval2) {
              previousMillis2 = currentMillis2;
              digitalWrite(led1, HIGH);
              ledState2++;}}
     else if (ledState2 == 6){
              ledState2 = 0;}
}


void loop() {
  // put your main code here, to run repeatedly:



test3();
}
