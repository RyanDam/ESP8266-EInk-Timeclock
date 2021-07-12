// /**
//  *  @filename   :   epd1in54-demo.ino
//  *  @brief      :   1.54inch e-paper display demo
//  *  @author     :   Yehui from Waveshare
//  *
//  *  Copyright (C) Waveshare     September 5 2017
//  *
//  * Permission is hereby granted, free of charge, to any person obtaining a copy
//  * of this software and associated documnetation files (the "Software"), to deal
//  * in the Software without restriction, including without limitation the rights
//  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  * copies of the Software, and to permit persons to  whom the Software is
//  * furished to do so, subject to the following conditions:
//  *
//  * The above copyright notice and this permission notice shall be included in
//  * all copies or substantial portions of the Software.
//  *
//  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  * THE SOFTWARE.
//  */
// #include "epd1in54.h"
// #include "epdpaint.h"

// #define COLORED     0
// #define UNCOLORED   1

// /**
//   * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
//   * In this case, a smaller image buffer is allocated and you have to 
//   * update a partial display several times.
//   * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
//   */
// unsigned char image[5024];
// Paint paint(image, 200, 200);    // width should be the multiple of 8 
// Epd epd;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(115200);

//   Serial.println("e-Paper init ...");
//   // lut_full_update
//   if (epd.Init(lut_partial_update) != 0) {
//       Serial.println("e-Paper init failed");
//       return;
//   }
//   /** 
//    *  there are 2 memory areas embedded in the e-paper display
//    *  and once the display is refreshed, the memory area will be auto-toggled,
//    *  i.e. the next action of SetFrameMemory will set the other memory area
//    *  therefore you have to clear the frame memory twice.
//    */
//   epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
//   epd.DisplayFrame();
//   epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
//   epd.DisplayFrame();

//   Serial.println("e-Paper init ... DONE");

//   paint.SetRotate(ROTATE_180);
//   paint.Clear(UNCOLORED);
//   paint.DrawStringAt(65, 10, "11/07", &Font20, COLORED);
//   paint.DrawCharAt(36, 34, ' ', &Font102, COLORED);
//   paint.DrawCharAt(100, 34, ' '+1, &Font102, COLORED);
//   paint.DrawCharAt(36, 114, ' '+2, &Font102, COLORED);
//   paint.DrawCharAt(100, 114, ' '+3, &Font102, COLORED);
//   epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
//   epd.DisplayFrame(); 

//   epd.Sleep();
// }

// void loop() {
//   delay(500);
// }
