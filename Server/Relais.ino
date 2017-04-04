void setRelais(int pin, bool state) {
  digitalWrite(pin, !state);
}

void setRelais1(bool state) {
  setRelais(D1, state);
}

void setRelais2(bool state) {
  setRelais(D2, state);
}

void setupRelais() {
  pinMode(D1, OUTPUT);
  setRelais1(false);
  pinMode(D2, OUTPUT);
  setRelais2(false);
}
