int SWITCH_PIN = 0;

void setup() {
  Serial.begin(115200);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  bool s1 = digitalRead(SWITCH_PIN);
  Serial.println(s1);
}
