void setLed(bool state) {
  digitalWrite(BUILTIN_LED, !state);
}

void setupLed() {
  pinMode(BUILTIN_LED, OUTPUT);
  setLed(false);
}

