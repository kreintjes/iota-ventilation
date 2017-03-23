void setLed(bool state) {
  digitalWrite(BUILTIN_LED, !state);
}

void turnOnLed() {
  setLed(true);
}

void turnOffLed() {
  setLed(false);
}

void setupLed() {
  pinMode(BUILTIN_LED, OUTPUT);
  turnOffLed();
}

