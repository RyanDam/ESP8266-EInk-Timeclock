/**
 *  @filename   :   epd1in54-demo.ino
 *  @brief      :   1.54inch e-paper display demo
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     September 5 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
 
#include <NTPClient.h>               // Include NTPClient library
#include <TimeLib.h>                 // Include Arduino time library

#include "epd1in54.h"
#include "epdpaint.h"

#ifndef STASSID
#define STASSID "Ngoc Quynh 2.4G"
#define STAPSK  "dangki3gdi"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

#define COLORED     0
#define UNCOLORED   1

/**
  * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
  * In this case, a smaller image buffer is allocated and you have to 
  * update a partial display several times.
  * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
  */
unsigned char image[5024];
Paint paint(image, 200, 200);    // width should be the multiple of 8 
Epd epd;

WiFiUDP ntpUDP;
#define NTP_OFFSET   25200     // In seconds, +7h
#define NTP_INTERVAL 2 * 60 * 60 * 1000    // In miliseconds, 2h
#define NTP_ADDRESS  "time.nist.gov"
// 'time.nist.gov' is used (default server) with +1 hour offset (3600 seconds) 7200 seconds (7200000 milliseconds, 2h) update interval
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

char Time[] = "00:00:00";
char Date[] = "00/00";
byte last_minute, minute_, hour_, day_, month_;
int year_;

void draw_string(const char* text, int x=0, int y=0, int width=200, int height=200, bool clear=true) {
  paint.SetRotate(ROTATE_180);
  if (clear) {
    paint.Clear(UNCOLORED);
  }
  paint.DrawStringAt(4, 4, text, &Font12, COLORED);
  epd.SetFrameMemory(paint.GetImage(), x, y, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("e-Paper init ...");
  // lut_full_update
  if (epd.Init(lut_full_update) != 0) {
      Serial.println("e-Paper init failed");
      return;
  }
  /** 
   *  there are 2 memory areas embedded in the e-paper display
   *  and once the display is refreshed, the memory area will be auto-toggled,
   *  i.e. the next action of SetFrameMemory will set the other memory area
   *  therefore you have to clear the frame memory twice.
   */
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();

  paint.SetRotate(ROTATE_180);

  Serial.println("e-Paper init ... DONE");

  delay(100);

  draw_string("Connecting to WIFI");
  Serial.println("Connecting to WIFI");

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WIFI.");
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");

  draw_string("Connecting to WIFI CONNECTED");

  timeClient.begin();

  delay(500);
  epd.Sleep();
}

void loop() {
  timeClient.update();
  unsigned long unix_epoch = timeClient.getEpochTime();    // Get Unix epoch time from the NTP server
  
  minute_ = minute(unix_epoch);
  if (last_minute != minute_) {
 
    minute_ = minute(unix_epoch);
    hour_   = hour(unix_epoch);
    day_    = day(unix_epoch);
    month_  = month(unix_epoch);
    year_   = year(unix_epoch);
 
    Time[4]  = minute_ % 10;
    Time[3]  = minute_ / 10;
    Time[1]  = hour_   % 10;
    Time[0]  = hour_   / 10;
 
    Date[0]  = day_   / 10 + 48;
    Date[1]  = day_   % 10 + 48;
    Date[3]  = month_  / 10 + 48;
    Date[4]  = month_  % 10 + 48;
    // Date[8] = (year_   / 10) % 10 + 48;
    // Date[9] = year_   % 10 % 10 + 48;
 
    paint.Clear(UNCOLORED);
    paint.DrawStringAt(65, 10, Date, &Font20, COLORED);
    paint.DrawCharAt(36, 34, ' '+Time[0], &Font102, COLORED);
    paint.DrawCharAt(100, 34, ' '+Time[1], &Font102, COLORED);
    paint.DrawCharAt(36, 114, ' '+Time[3], &Font102, COLORED);
    paint.DrawCharAt(100, 114, ' '+Time[4], &Font102, COLORED);
    epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame(); 

    last_minute = minute_;
    epd.Sleep();
  }

  delay(50000); // 50s
}
