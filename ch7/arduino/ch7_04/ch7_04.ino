int SWITCH_PIN1 = 0;
int SWITCH_PIN2 = 1;
int SWITCH_PIN3 = 2;
int SWITCH_PIN4 = 3;
int CHECK_MILLIS = 50;
int CHECK_ITERATIONS = 15;

unsigned long lastCheckMillis = 0;
unsigned long sameSideCounter = 0;

int currentRestingSide = -1;
int previousSide = -1;
int currentSide = -1;


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
  
  /*
  Serial.print(s1);
  Serial.print(", ");
  Serial.print(s2);
  Serial.print(", ");
  Serial.print(s3);
  Serial.print(", ");
  Serial.print(s4);
  Serial.println(", ");
  */

  if (s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1) {
    currentSide = 0; // bottom
  } else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) {
    currentSide = 1; // top
  } else if (s1 == 0 && s2 == 1 && s3 == 0 && s4 == 1) {
    currentSide = 2;
  } else if (s1 == 1 && s2 == 0 && s3 == 1 && s4 == 0) {
    currentSide = 3;
  } else if (s1 == 1 && s2 == 1 && s3 == 0 && s4 == 0) {
    currentSide = 4;
  } else if (s1 == 0 && s2 == 0 && s3 == 1 && s4 == 1) {
    currentSide = 5;
  }

  if (currentSide != currentRestingSide) {
    if (previousSide == currentSide) {
      unsigned long currentMillis = millis();
      if (currentMillis > lastCheckMillis + CHECK_MILLIS) {
        sameSideCounter += 1;  
        lastCheckMillis = currentMillis;
      }
    } else {
      sameSideCounter = 0;
    }
    if (sameSideCounter >= CHECK_ITERATIONS) {
      // the side changed and it is in a stable state
      currentRestingSide = currentSide;
      Serial.print("Side changed: "); Serial.println(currentRestingSide);
    }
  }

  previousSide = currentSide;
}
