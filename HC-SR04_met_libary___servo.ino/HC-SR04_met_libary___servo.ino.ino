#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int val;    // variable to read the value from the analog pin

#include <NewPing.h>
#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  delay(200);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  myservo.write(135);// sets the servo position according to the scaled value
  if (sonar.ping_cm()>= 50){
    myservo.write(135);// sets the servo position according to the scaled value
  }
  else if (sonar.ping_cm() < 20){
    myservo.write(45);// sets the servo position according to the scaled value
  }
  else{
     myservo.write(90);// sets the servo position according to the scaled value
  }
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
