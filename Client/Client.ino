#include <ESP8266WiFi.h>

#define WIFI_SSID           "wicked"
#define WIFI_PASSWORD       "thereisnospoon"

#define VENTILATION_LOW     50
#define VENTILATION_HIGH    55

#define DELAY 100
#define DHT_READ_INTERVAL 6000

WiFiClient espClient;
boolean wifi_connected = false;

int humidity;

String lastState;

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();

  setupLed();
  setupWiFi();
  setupDHT();
}

void loop() {
  delay(DELAY);
  loopWiFi();
  loopLed();
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
    blinkLed(300);
  } else if (humidity >= VENTILATION_LOW && humidity < VENTILATION_HIGH) {
    newState = "low";
    blinkLed(800);
  } else {
    newState = "off";
    stopBlink();
  }

  if(lastState == NULL || lastState != newState) {
    sendDataToServer(newState);
    lastState = newState;
  }
}

