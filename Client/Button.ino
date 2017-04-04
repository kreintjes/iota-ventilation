#include "OneButton.h"

#define BUTTONPIN 0 // D3

OneButton button(BUTTONPIN, true);

void setupButton() {
  pinMode(BUTTONPIN, INPUT);
  
  button.setClickTicks(300);
  button.setPressTicks(600);

  button.attachClick(singleClick);
  button.attachDoubleClick(doubleClick);
  button.attachLongPressStart(longPress);
}

void singleClick() {
  sendDataToServer("off");
}

void doubleClick() {
  sendDataToServer("low");
}

void longPress() {
  sendDataToServer("high");
}

void loopButton() {
  button.tick();
}
