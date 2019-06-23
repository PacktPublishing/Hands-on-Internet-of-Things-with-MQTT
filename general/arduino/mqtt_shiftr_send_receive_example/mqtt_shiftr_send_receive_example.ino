/**
 * Example to send and receive MQTT messages via the MQTT server shiftr.io
 * to an Arduino MKR 1010 Wifi.
 * 
 * Depends on libraries:
 *   - WiFiNINA
 *   - MQTT (by Joel Gaehwiler), there are multiple with a similar name, make sure to pick the right one
 * 
 * By default it uses the openly accessible login via username: "try" and password: "try".
 * You could easily replace these with your personal login credentials after signing up on shiftr.io.
 */

#include <WiFiNINA.h>
#include <MQTT.h>

const char WIFI_SSID[] = "name"; // set your network name here
const char WIFI_PASSWORD[] = "password"; // set your network password here
const char MQTT_SERVER[] = "broker.shiftr.io";
const int MQTT_SERVER_PORT = 1883;
const char MQTT_USERNAME[] = "try";
const char MQTT_PASSWORD[] = "try";
const char MQTT_DEVICE_NAME[] = "hellomqtt"; // can be freely picked

int status = WL_IDLE_STATUS;
WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

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

void setup() {
  Serial.begin(115200);
  connect();
}

void loop() {
  client.loop();

  if (!net.connected()) {
    connect();
  }

  // send a message every second
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("/tims-channel", "hello");
    lastMillis = millis();
  }
}
