#define LEDPIN D3

unsigned long lastChangeTime;
bool ledState = false;
unsigned long ledDelay;

void setupLed() {
  pinMode(LEDPIN, OUTPUT);
  setLed(false);
}

void loopLed() {
  if(ledDelay == NULL || (lastChangeTime != NULL && millis() - lastChangeTime < ledDelay)) {
    return;
  }

  setLed(!ledState);
}

void blinkLed(unsigned long _ledDelay) {
  ledDelay = _ledDelay;
}

void turnLedOn() {
  ledDelay = NULL;
  setLed(true);
}

void turnLedOff() {
  ledDelay = NULL;
  setLed(false);
}

void setLed(bool state) {
  digitalWrite(LEDPIN, state);
  ledState = state;
  lastChangeTime = millis();
}

