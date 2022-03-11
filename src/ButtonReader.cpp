/*
 * ButtonReader - Reliably get Arduino button/toggle/switch input
 *
 * Copyright (c) 2022 Volker Wiegand <volker@railduino.de>
 * Distributed under MIT license - see LICENSE for details
 *
 */

#include "Arduino.h"
#include "ButtonReader.h"

/*
 * The constructor has two arguments:
 * - pin     - Button input pin
 * - timer   - Debounce timer (default 50 msec)
 */

ButtonReader::ButtonReader(int pin, unsigned long timer)
{
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);

  _timer = timer;

  _startup = true;
}

/*
 * There is a shortcut if the debounce timer is 50 milliseconds
 */

ButtonReader::ButtonReader(int pin): ButtonReader(pin, defaultTimer)
{
}

/*
 * The readValue() function returns one of four possible states:
 * - isPassive    - the button is idle
 * - isPressed    - the button has just been pressed
 * - isActive     - the button is held down
 * - isReleased   - the button has just been released
 *
 * During normal course of operation it is the only
 * function that needs to be called during loop().
 */

BtnState ButtonReader::readValue(void)
{
  int value = digitalRead(_pin);
  unsigned long now = millis();

  if (_startup) {
    _prev = _last = _curr = value;
    _state = (value == HIGH) ? isPassive : isActive;
    _seen = now;
    _startup = false;
    return _state;
  }

  if (value != _last) {
    _last = value;
    _seen = now;
  }

  if ((now - _seen) >= _timer) {
    _prev = _curr;
    _curr = value;
  }

  if (_prev == HIGH) {
    if (_curr == HIGH) { // HIGH -> HIGH
      _state = isPassive;
    } else {             // HIGH -> LOW
      _state = isPressed;
    }
  } else {
    if (_curr == HIGH) { // LOW -> HIGH
      _state = isReleased;
    } else {             // LOW -> LOW
      _state = isActive;
    }
  }
  return _state;
}

/*
 * The getCurrent() function returns the current input state.
 * It does not call readValue() and therefore does not update.
 * Valid only after having called readValue() at least once.
 */

BtnState ButtonReader::getCurrent(void)
{
  return _state;
}
