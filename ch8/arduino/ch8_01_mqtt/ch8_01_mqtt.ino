#include <WiFiNINA.h>
#include <MQTT.h>

const char WIFI_SSID[] = "hodor"; // set your network name here
const char WIFI_PASSWORD[] = "07055517105068205046"; // set your network password here
const char MQTT_SERVER[] = "broker.shiftr.io";
const int MQTT_SERVER_PORT = 1883;
const char MQTT_USERNAME[] = "try";
const char MQTT_PASSWORD[] = "try";
const char MQTT_DEVICE_NAME[] = "hellomqtt"; // can be freely picked

int status = WL_IDLE_STATUS;
WiFiClient net;
MQTTClient client;

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

unsigned long sideMillis[] = {0, 0, 0, 0, 0, 0};
unsigned long sideTimerStartMillis = 0;
String activityNames[] = {
  "Exercising",
  "Eating",
  "Watching TV",
  "Working on Arduino",
  "Social Media",
  "Sleeping"
};

int PUBLISH_MILLIS = 1000 * 10; // 10 seconds
unsigned long lastPublishMillis = 0;

void setup() {
  Serial.begin(115200);
  pinMode(SWITCH_PIN1, INPUT_PULLUP);
  pinMode(SWITCH_PIN2, INPUT_PULLUP);
  pinMode(SWITCH_PIN3, INPUT_PULLUP);
  pinMode(SWITCH_PIN4, INPUT_PULLUP);
  connect();
}

void loop() {
  unsigned long currentMillis = millis();
  client.loop();

  if (!net.connected()) {
    connect();
  }
  
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
      if (previousSide != -1) {
        unsigned long activityMillis = currentMillis - sideTimerStartMillis;
        sideMillis[previousSide] += activityMillis;
        Serial.print("Time spent on ");
        Serial.print(activityNames[previousSide]);
        Serial.print(": ");
        Serial.print(sideMillis[previousSide] / 1000);
        Serial.println(" seconds");
      }
      sideTimerStartMillis = currentMillis;
    }
  }

  if (currentRestingSide != -1) {
    if (currentMillis > lastPublishMillis + PUBLISH_MILLIS) {
      unsigned long activityMillis = currentMillis - sideTimerStartMillis;
      unsigned long timeSpend = (sideMillis[currentRestingSide] + activityMillis) / 1000; // seconds
      String text = activityNames[currentRestingSide] + ": " + timeSpend + " seconds";
      Serial.println(text);
      client.publish("/tims-channel/cube/activity", text); 
      lastPublishMillis = currentMillis;
    }
  }

  previousSide = currentSide;
}

void connect() {
  // first connect to the wifi
  Serial.print("Checking wifi...");
  while (status != WL_CONNECTED) {
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(".");
    delay(1000);
  }
  Serial.println(); Serial.print("Connected to WiFi!"); Serial.println();

  // second connect to the MQTT server
  client.begin(MQTT_SERVER, MQTT_SERVER_PORT, net);
  Serial.println("Connecting to MQTT server...");
  while (!client.connect(MQTT_DEVICE_NAME, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected to MQTT server");

  // define what should happen when messages are incoming
  client.onMessage(messageReceived);
  
  // subscribe to MQTT topics
  client.subscribe("/tims-channel");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}
