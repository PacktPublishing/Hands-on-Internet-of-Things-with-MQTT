/*
 * Hands-On Internet of Things with MQTT – Chapter 6
 * 
 * This is the starting point for the project, a stripped down version of the GxEPD2-library example,
 * just leaving the parts we need.
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
#include <Fonts/FreeMonoBold9pt7b.h>

#define MAX_DISPAY_BUFFER_SIZE 15000ul
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPAY_BUFFER_SIZE / (EPD::WIDTH / 8))
#define MAX_HEIGHT_3C(EPD) (EPD::HEIGHT <= (MAX_DISPAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8) ? EPD::HEIGHT : (MAX_DISPAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8))
GxEPD2_3C<GxEPD2_420c, MAX_HEIGHT_3C(GxEPD2_420c)> display(GxEPD2_420c(/*CS=4*/ 4, /*DC=*/ 7, /*RST=*/ 6, /*BUSY=*/ 5));

const char HelloWorld[] = "Hello World";

void setup() {
  Serial.begin(115200);
  Serial.println("starting...");
  display.init(115200);
  helloWorld();
  display.powerOff();
}

void loop() {}

void helloWorld() {
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = (display.width() - tbw) / 2;
  uint16_t y = (display.height() + tbh) / 2; // y is base line!
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(HelloWorld);
  } while (display.nextPage());
}
