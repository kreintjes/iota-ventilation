#include <ESP8266WiFi.h>

#define WIFI_SSID           "wicked"
#define WIFI_PASSWORD       "thereisnospoon"

WiFiClient espClient;

bool ventilationOn = false;

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  
  setupWiFi();
  setupButton();
}

void loop() {
  loopButton();
  loopWiFi();
}
