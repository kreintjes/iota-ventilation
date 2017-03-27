void sendDataToServer() {
  Serial.printf("\n[Connecting to %s ... ", WiFi.gatewayIP().toString().c_str());
  
  if (espClient.connect(WiFi.gatewayIP(), 1337))
  {
    ventilationOn = !ventilationOn;
    Serial.println("connected]");
    Serial.println("[Sending a request]");
    espClient.print(ventilationOn ? "true" : "false");

    espClient.stop();
    Serial.println("[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    espClient.stop();
  }
}

