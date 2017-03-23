#include <ESP8266WiFi.h>

WiFiServer server(1337);

void setLed(int pin, bool state) {
  digitalWrite(pin, !state);
}

void turnOnLed(int pin) {
  setLed(pin, true);
}

void turnOffLed(int pin) {
  setLed(pin, false);
}

void setup() {
  // Initialize Serial console output
  Serial.begin(115200);
  Serial.println();

  // Initialize pins
  pinMode(BUILTIN_LED, OUTPUT);
  turnOffLed(BUILTIN_LED);

  // Set-up WiFi Access Point and TCP Server
  Serial.print("Starting AP... ");
  boolean result = WiFi.softAP("wicked", "thereisnospoon", 8, true);
  
  if(result == true) {
    Serial.println("Ready");
  } else {
    Serial.println("Failed!");
  }

  server.begin();
  Serial.printf("Server started, connect to %s:1337\n", WiFi.softAPIP().toString().c_str());
}

void loop() {
  // Wait until client connected
  WiFiClient client = server.available();
  if(client) {
    Serial.printf("Client connected: %s\n", client.localIP().toString().c_str());
    turnOnLed(BUILTIN_LED);
    
    client.println("Hoi Willem");
    
    while(client.connected()) {
      // Read line by line what the client is saying
      if(client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
      }
      delay(1); // Give the server time to receive data
    }

    // Client disconnected: close the connection.
    client.stop();
    Serial.println("Client disonnected");
    turnOffLed(BUILTIN_LED);
  }
}
