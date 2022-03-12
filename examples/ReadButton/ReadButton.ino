/*
 * Test program for a push button input
 */

#include <ButtonReader.h>

// Instantiate the reader
ButtonReader btn(A0);

// Remember the last state
BtnState lastState;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  delay(1000);

  // Read the initial state
  lastState = btn.readState();
}

// the loop function runs over and over again forever
void loop() {
  BtnState state = btn.readState();

  switch (state) {
    case isPassive:
      if (lastState != isPassive) {
        Serial.println("Button is passive");
      }
      break;
    case isPressed:
      Serial.println("Button pressed");
      break;
    case isActive:
      if (lastState != isActive) {
        Serial.println("Button is active");
      }
      break;
    case isReleased:
      Serial.println("Button released");
      break;
  }

  lastState = state;
}

