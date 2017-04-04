// Make sure these match between server and client
#define WIFI_SSID       "wicked"
#define WIFI_PASSWORD   "thereisnospoon"

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
}

void onDataReceive(String state) {
  if(state == "high") {
    setLed(true);
    setRelais1(false);
    setRelais2(true);
  } else if(state == "low") {
    setLed(true);
    setRelais1(true);
    setRelais2(false);
  } else {
    setLed(false);
    setRelais1(false);
    setRelais2(false);
  }
}

