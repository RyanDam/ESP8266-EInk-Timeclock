// /*
//    Copyright (c) 2015, Majenko Technologies
//    All rights reserved.

//    Redistribution and use in source and binary forms, with or without modification,
//    are permitted provided that the following conditions are met:

//  * * Redistributions of source code must retain the above copyright notice, this
//      list of conditions and the following disclaimer.

//  * * Redistributions in binary form must reproduce the above copyright notice, this
//      list of conditions and the following disclaimer in the documentation and/or
//      other materials provided with the distribution.

//  * * Neither the name of Majenko Technologies nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.

//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
//    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
//    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//    ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */

// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <WiFiClient.h>
// #include <ESP8266WebServer.h>
// #include <ESP8266mDNS.h>

// #ifndef STASSID
// #define STASSID "Ngoc Quynh 2.4G"
// #define STAPSK  "dangki3gdi"
// #endif

// const char *ssid = STASSID;
// const char *password = STAPSK;

// ESP8266WebServer server(80);

// void handleRoot() {                         // When URI / is requested, send a web page with a button to toggle the LED
//   server.send(200, "text/html", "<form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>");
// }

// void handleLED() {                          // If a POST request is made to URI /LED
//   digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));      // Change the state of the LED
//   server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
//   server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
// }

// void handleNotFound() {
//   digitalWrite(LED_BUILTIN, 1);
//   String message = "File Not Found\n\n";
//   message += "URI: ";
//   message += server.uri();
//   message += "\nMethod: ";
//   message += (server.method() == HTTP_GET) ? "GET" : "POST";
//   message += "\nArguments: ";
//   message += server.args();
//   message += "\n";

//   for (uint8_t i = 0; i < server.args(); i++) {
//     message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
//   }

//   server.send(404, "text/plain", message);
//   digitalWrite(LED_BUILTIN, 0);
// }

// void setup(void) {
//   pinMode(LED_BUILTIN, OUTPUT);
//   digitalWrite(LED_BUILTIN, 0);

//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   Serial.println("");

//   // Wait for connection
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.print("Connected to ");
//   Serial.println(ssid);
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   if (MDNS.begin("esp8266")) {
//     Serial.println("MDNS responder started");
//   }

//   server.on("/", handleRoot);
//   server.on("/LED", HTTP_POST, handleLED);
//   server.on("/inline", []() {
//     server.send(200, "text/plain", "this works as well");
//   });
//   server.onNotFound(handleNotFound);
//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop(void) {
//   server.handleClient();
//   MDNS.update();
// }
