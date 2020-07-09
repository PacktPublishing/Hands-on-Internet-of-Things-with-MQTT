/**
 * This sketch will help you find good opening and closing positions
 * for your specific servo motor.
 * You probably don’t need to run this sketch, only if you had problems
 * finding good positions.
 * This sketch was written after the book release, so there is no mention
 * of it in the book.
 * 
 * Servo motor must be connected to pin 9.
 * 
 * How to use:
 * - Put a sticky note (or something similar) on the tip of the servo motor,
 *   so you can see better in which direction it is pointing
 * - Upload the sketch
 * - Open the Serial Monitor
 * - Enter a number (between 0 and 180), then press the Enter key
 * - Repeat entering numbers until you find numbers that work for your
 *   specific opening and closing positions
 * - Write down the numbers for the opening and closing positions
 * - Return to the book
 * - Use the numbers you wrote down for the opening and closing positions
 *   instead of the positions used in the book
 */

#include <Servo.h>

Servo myservo; // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  while (Serial.available() > 0) {
    int inputValue = Serial.parseInt();
    Serial.print("inputValue: ");
    Serial.println(inputValue);
    myservo.write(inputValue); // move the servo to its new position
  }
}
