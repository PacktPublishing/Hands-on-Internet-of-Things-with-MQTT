void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0) {
    String text = Serial.readStringUntil('\n');
    Serial.print("Received: "); Serial.println(text);
  }
}
