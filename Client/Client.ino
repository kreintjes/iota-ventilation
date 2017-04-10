#include <ESP8266WiFi.h>
#include "user_interface.h"

#define WIFI_SSID           "wicked"
#define WIFI_PASSWORD       "thereisnospoon"

#define VENTILATION_LOW     60.00
#define VENTILATION_HIGH    80.00

WiFiClient espClient;
boolean wifi_connected = false;

float humidity;

void setup() {
  Serial.begin(115200);
  //delay(10);
  Serial.println();
  
  setupWiFi();
  setupDHT();
}

void loop() {
  delay(100);
  loopWiFi();
  if(wifi_connected) {
    loopDHT();
    loopLogic();
  }
  yield();
}

void loopLogic() {
  if(humidity >= VENTILATION_HIGH) {
    sendDataToServer("high");
  } else if (humidity >= VENTILATION_LOW && humidity < VENTILATION_HIGH) {
    sendDataToServer("low");
  } else {
    sendDataToServer("off");
  }
}

