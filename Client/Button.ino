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
  sendDataToServer();
}

void doubleClick() {
}

void longPress() {
}

void loopButton() {
  button.tick();
}
