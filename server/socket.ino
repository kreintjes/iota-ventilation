WiFiServer server(1337);

void setupSocket() {
  server.begin();
  Serial.printf("Server started, clients can connect to %s:1337\n", WiFi.softAPIP().toString().c_str());
}

void loopSocket() {
  // Wait until client connected
  WiFiClient client = server.available();
  if(client) {
    Serial.printf("Client connected: %s\n", client.localIP().toString().c_str());
    
    while(client.connected()) {
      if(client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print("Received data: ");
        Serial.println(line);
        onDataReceive(line);
      }
      delay(1); // Give the server time to receive data
    }

    // Client disconnected: close the connection.
    client.stop();
    Serial.println("Client disonnected");
  }
}
