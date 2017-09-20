void setLed(bool state) {
  digitalWrite(BUILTIN_LED, !state); // For some reason we need to invert this for the BUILTIN_LED (true is off, false is on).
}

void setupLed() {
  pinMode(BUILTIN_LED, OUTPUT);
  setLed(false);
}

