#define LEDPIN D3

unsigned long lastChangeTime;
bool ledState = false;
unsigned long ledSpeed;

void setLed(bool state) {
  digitalWrite(LEDPIN, state);
}

void setupLed() {
  pinMode(LEDPIN, OUTPUT);
  setLed(false);
}

void blinkLed(unsigned long _ledSpeed) {
  ledSpeed = _ledSpeed;
}

void stopBlink() {
  ledSpeed = NULL;
  setLed(false);
}

void loopLed() {
  if(ledSpeed == NULL || (lastChangeTime != NULL && millis() - lastChangeTime < ledSpeed)) {
    return;
  }
  ledState = !ledState;
  lastChangeTime = millis();

  setLed(ledState);
}

