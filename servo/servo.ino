
#include <Servo.h>

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 9

// Create a variable to store the servo position:
int angle = 0;

void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);
}

void loop() {
  // Tell the servo to go to a particular angle:
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);

  for (angle = 90; angle <= 180; angle += 1) {
    myservo.write(angle);
    delay(15);
  }

  for (angle = 0; angle >= 90; angle -= 1) {
    myservo.write(angle);
    delay(30);
  }
  delay(1000);
}
