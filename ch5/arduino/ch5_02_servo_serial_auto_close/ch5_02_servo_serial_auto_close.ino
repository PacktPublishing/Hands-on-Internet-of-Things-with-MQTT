#include <Servo.h>

Servo myservo;
unsigned long lastTimeOpenend = 0;
bool isOpen = false;
int OPENING_TIME = 700;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  while (Serial.available() > 0) {
    int inputValue = Serial.parseInt();
    if (inputValue == 1) {
      lastTimeOpenend = millis();
      isOpen = true;
      myservo.write(90);
    }
  }
  if (isOpen) {
    if (millis() > lastTimeOpenend + OPENING_TIME) {
      myservo.write(0);
      isOpen = false;
    }   
  }
}
