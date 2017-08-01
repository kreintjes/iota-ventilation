void setRelais(int pin, bool state) {
  digitalWrite(pin, !state);
}

void setRelais1(bool state) {
  Serial.print("Turning relais 1 ");
  Serial.println(state ? "on" : "off");
  setRelais(D1, state);
}

void setRelais2(bool state) {
  Serial.print("Turning relais 2 ");
  Serial.println(state ? "on" : "off");
  setRelais(D2, state);
}

void setupRelais() {
  pinMode(D1, OUTPUT);
  setRelais1(false);
  pinMode(D2, OUTPUT);
  setRelais2(false);
}
