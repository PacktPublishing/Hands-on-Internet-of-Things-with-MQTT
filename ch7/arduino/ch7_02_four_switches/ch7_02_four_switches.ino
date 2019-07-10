int SWITCH_PIN1 = 0;
int SWITCH_PIN2 = 1;
int SWITCH_PIN3 = 2;
int SWITCH_PIN4 = 3;

void setup() {
  Serial.begin(115200);
  pinMode(SWITCH_PIN1, INPUT_PULLUP);
  pinMode(SWITCH_PIN2, INPUT_PULLUP);
  pinMode(SWITCH_PIN3, INPUT_PULLUP);
  pinMode(SWITCH_PIN4, INPUT_PULLUP);
}

void loop() {
  bool s1 = digitalRead(SWITCH_PIN1);
  bool s2 = digitalRead(SWITCH_PIN2);
  bool s3 = digitalRead(SWITCH_PIN3);
  bool s4 = digitalRead(SWITCH_PIN4);

  Serial.print(s1);
  Serial.print(", ");
  Serial.print(s2);
  Serial.print(", ");
  Serial.print(s3);
  Serial.print(", ");
  Serial.print(s4);
  Serial.println(", ");
}
