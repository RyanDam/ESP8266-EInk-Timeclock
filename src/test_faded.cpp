// #include <Arduino.h>
// #include <PolledTimeout.h>

// esp8266::polledTimeout::periodicFastUs stepPeriod(50000);

// // the setup function runs only once at start
// void setup() {
//   Serial.begin(115200);
//   Serial.println();

//   // This next line will cause the code to use the Phase-Locked waveform generator
//   // instead of the default PWM-Locked one.  Comment it out to try the default version.
//   // For more information on choosing between the two options, see the following pull requests:
//   // Phase-Locked generator: https://github.com/esp8266/Arduino/pull/7022
//   // PWM-Locked generator:   https://github.com/esp8266/Arduino/pull/7231
//   enablePhaseLockedWaveform();

//   pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
//   analogWriteRange(1000);

//   using esp8266::polledTimeout::oneShotMs; //import the type to the local namespace

//   digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level

//   oneShotMs timeoutOn(2000);
//   while (!timeoutOn) {
//     yield();
//   }

//   stepPeriod.reset();
// }


// void loop() {
//   static const int init_val = 0;
//   static const int init_delta = 50;
//   static const int init_max_val = 1000;
//   static int val = init_val;
//   static int delta = init_delta;
//   if (stepPeriod) {
//     val += delta;
//     if (val < 0) {
//       val = delta;
//       delta = init_delta;
//     } else if (val > init_max_val) {
//       val = init_max_val-init_delta;
//       delta = -init_delta;
//     }
//     analogWrite(LED_BUILTIN, val);
//     // Serial.printf("%d\n", val);
//   }
// }