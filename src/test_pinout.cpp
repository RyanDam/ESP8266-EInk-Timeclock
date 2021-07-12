// #include <Arduino.h>

// esp8266::polledTimeout::periodicFastUs stepPeriod(50000);

// // static const uint8_t D0   = 16;
// // static const uint8_t D1   = 5;
// // static const uint8_t D2   = 4;
// // static const uint8_t D3   = 0;
// // static const uint8_t D4   = 2;
// // static const uint8_t D5   = 14;
// // static const uint8_t D6   = 12;
// // static const uint8_t D7   = 13;
// // static const uint8_t D8   = 15;
// // static const uint8_t D9   = 3;
// // static const uint8_t D10  = 1;

// // controller
// #define PIN_BUSY  5 // D1
// #define PIN_DC    4 // D2

// // hspi
// #define PIN_SDI   13 // D8
// #define PIN_CS    15 // D4
// #define PIN_CLK   14 // D6

// // the setup function runs only once at start
// void setup() {
//   Serial.begin(115200);
//   Serial.println();

//   pinMode(PIN_BUSY, OUTPUT); // busy
//   pinMode(PIN_DC, OUTPUT); // d/c

//   pinMode(PIN_SDI, OUTPUT); // sdi
//   pinMode(PIN_CS, OUTPUT); // cs

//   pinMode(PIN_CLK, OUTPUT); // clk
// }

// void loop() {

//   // pre-init
//   digitalWrite(PIN_BUSY, LOW);
//   digitalWrite(PIN_DC, LOW);
//   digitalWrite(PIN_SDI, LOW);
//   digitalWrite(PIN_CS, LOW);
//   digitalWrite(PIN_CLK, LOW);

//   // checking
//   digitalWrite(PIN_BUSY, HIGH);
//   delay(200);
//   digitalWrite(PIN_BUSY, LOW);
//   delay(200);

//   digitalWrite(PIN_DC, HIGH);
//   delay(200);
//   digitalWrite(PIN_DC, LOW);
//   delay(200);

//   digitalWrite(PIN_SDI, HIGH);
//   delay(200);
//   digitalWrite(PIN_SDI, LOW);
//   delay(200);

//   digitalWrite(PIN_CS, HIGH);
//   delay(200);
//   digitalWrite(PIN_CS, LOW);
//   delay(200);

//   digitalWrite(PIN_CLK, HIGH);
//   delay(200);
//   digitalWrite(PIN_CLK, LOW);
//   delay(200);

//   delay(2000);
// }