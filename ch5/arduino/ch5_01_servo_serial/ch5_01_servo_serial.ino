#include <Servo.h>

Servo myservo; // create servo object to control a servo

int pos = 0; // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  while (Serial.available() > 0) {
    int inputValue = Serial.parseInt();
    if (inputValue == 1) {
      myservo.write(90);
    } else { // must be a "0"
      myservo.write(0);
    }
  }
}
