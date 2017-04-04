void sendDataToServer(String state) {
  Serial.printf("\n[Connecting to %s ... ", WiFi.gatewayIP().toString().c_str());
  
  if (espClient.connect(WiFi.gatewayIP(), 1337))
  {
    Serial.println("connected]");
    Serial.println("[Sending a request]");
    espClient.print(state);

    espClient.stop();
    Serial.println("[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    espClient.stop();
  }
}

