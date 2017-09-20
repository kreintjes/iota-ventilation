#include <ESP8266WiFi.h>

#define WIFI_SSID           "wicked"
#define WIFI_PASSWORD       "thereisnospoon"

#define VENTILATION_LOW_ON      55 // Low mode will be turned on when humidity is at least this value.
#define VENTILATION_LOW_OFF     50 // Low mode will only be turned of when humidity is below this value. Use same value as on if you do not want an on/off gap.

#define VENTILATION_HIGH_ON     60 // High mode will be turned on when humidity is at least this value.
#define VENTILATION_HIGH_OFF    55 // High mode will only be turned of when humidity is below this value. Use same value as on if you do not want an on/off gap.

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
  if(humidity >= VENTILATION_HIGH_ON || (lastState == "high" && humidity >= VENTILATION_HIGH_OFF)) {
    newState = "high";
    turnLedOn();
  } else if (humidity >= VENTILATION_LOW_ON || ((lastState == "high" || lastState == "low") && humidity >= VENTILATION_LOW_OFF)) {
    newState = "low";
    blinkLed(500);
  } else {
    newState = "off";
    turnLedOff();
  }

  if(lastState == NULL || lastState != newState) {
    sendDataToServer(newState);
    lastState = newState;
  }
}

