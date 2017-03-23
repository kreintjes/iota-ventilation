#include <ESP8266WiFi.h>

void setupWiFi() {
  Serial.print("Starting Access Point... ");
  boolean result = WiFi.softAP(WIFI_SSID, WIFI_PASSWORD, 8, true);
  
  if(result == true) {
    Serial.println("Ready");
  } else {
    Serial.println("Failed!");
  }
}
