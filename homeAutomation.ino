#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "your-ssid";
const char* password = "your-password";

int lightPin = D1;  // Set the pin for the light bulb

ESP8266WebServer server(80);

void handleRoot() {
  digitalWrite(lightPin, !digitalRead(lightPin));  // Toggle the light bulb
  server.send(200, "text/plain", "Light toggled");
}

void setup() {
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, LOW);  // Turn the light off to start

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
