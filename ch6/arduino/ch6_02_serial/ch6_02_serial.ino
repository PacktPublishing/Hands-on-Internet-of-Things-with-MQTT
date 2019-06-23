/*
 * Hands-On Internet of Things with MQTT – Chapter 6 (02 - Serial)
 * 
 * - Send a word / phrase via serial to be displayed on the e-ink display
 * - If the word / phrase ends with an exclamation mark, the text will be colored red
 * 
 * Based on GxEPD2_Example by Jean-Marc Zingg, which is itself based on Demo Example from
 * Good Display: http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html
 * 
 * Libraries (install via library manager):
 *   - GxEPD2
 *   - Adafruit GFX
 * 
 * Waveshare e-paper discussion on Arduino forum: http://forum.arduino.cc/index.php?topic=487007.0
 */ 

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeSansBold18pt7b.h>

#define MAX_DISPAY_BUFFER_SIZE 15000ul
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8))
#define MAX_HEIGHT_3C(EPD) (EPD::HEIGHT <= (MAX_DISPAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8) ? EPD::HEIGHT : (MAX_DISPAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8))
GxEPD2_3C<GxEPD2_420c, MAX_HEIGHT_3C(GxEPD2_420c)> display(GxEPD2_420c(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5));

void setup() {
  Serial.begin(115200);
  Serial.println("starting...");
  display.init(115200);
  setText("Hello display");
  display.powerOff();
}

void loop() {
  if(Serial.available() > 0) {
        String text = Serial.readStringUntil('\n');
        Serial.print("Received: "); Serial.println(text);
        setText(text);
    }  
}

void setText(String text) {
  display.setRotation(0);
  display.setFont(&FreeSansBold18pt7b);
  char lastCharacter = text.charAt(text.length() - 1);
  if (lastCharacter == '!') {
    display.setTextColor(GxEPD_RED);  
  } else {
    display.setTextColor(GxEPD_BLACK);  
  }
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = (display.width() - tbw) / 2;
  uint16_t y = (display.height() + tbh) / 2; // y is base line!
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(text);
  } while (display.nextPage());
}
