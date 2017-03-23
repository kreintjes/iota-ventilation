// Make sure these match between server and client
#define WIFI_SSID       "wicked"
#define WIFI_PASSWORD   "thereisnospoon"

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  setupLed();
  setupWiFi();
  setupSocket();
}

void loop() {
  loopSocket();
}

void onDataReceive(String line) {
  setLed(line == "true");
}

