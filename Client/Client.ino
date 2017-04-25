#include <ESP8266WiFi.h>
#include "user_interface.h"

#define WIFI_SSID           "wicked"
#define WIFI_PASSWORD       "thereisnospoon"

#define VENTILATION_LOW     60.00
#define VENTILATION_HIGH    80.00

#define DELAY 100
#define DHT_READ_INTERVAL 60000

WiFiClient espClient;
boolean wifi_connected = false;

float humidity;

String lastState;

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  
  setupWiFi();
  setupDHT();
}

void loop() {
  delay(DELAY);
  loopWiFi();
  if(wifi_connected) {
    loopDHT();
    loopLogic();
  }
  yield();
}

void loopLogic() {
  String newState;
  if(humidity >= VENTILATION_HIGH) {
    newState = "high";
  } else if (humidity >= VENTILATION_LOW && humidity < VENTILATION_HIGH) {
    newState = "low";
  } else {
    newState = "off";
  }

  if(lastState == NULL || lastState != newState) {
    sendDataToServer(newState);
    lastState = newState;
  }
}

