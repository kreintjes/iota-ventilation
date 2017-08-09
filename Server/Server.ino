// Make sure these match between server and client
#define WIFI_SSID       "wicked"
#define WIFI_PASSWORD   "thereisnospoon"

// Turn ventilation off after no data received for this duration.
// Do not set this too low, must be higher than time required to clear bathroom of humid air.
#define FAILOVER_DURATION 1800000 // 30 minutes

unsigned long lastReceiveTime;

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  setupLed();
  setupRelais();
  setupWiFi();
  setupSocket();
}

void loop() {
  loopSocket();
  loopFailover();
}

void onDataReceive(String state) {
  if(state == "high") {
    setLed(true);
    setRelais1(false);
    delay(1000);
    setRelais2(true);
  } else if(state == "low") {
    setLed(true);
    setRelais2(false);
    delay(1000);
    setRelais1(true);
  } else {
    setLed(false);
    setRelais1(false);
    delay(1000);
    setRelais2(false);
  }
  lastReceiveTime = millis();
}

void loopFailover() {
  if(lastReceiveTime == NULL || millis() - lastReceiveTime >= FAILOVER_DURATION) {
    // No data received for long time. Simulate receiving off so ventilation shutdowns and doesn't keep running indefinitely.
    Serial.printf("No data received for FAILOVER_DURATION (%d). Simulating off request...\n", FAILOVER_DURATION);
    onDataReceive("off");
  }
}

