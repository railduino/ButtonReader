/*
 * ButtonReader - Reliably get button/toggle/switch input
 *
 * Copyright (c) 2022 Volker Wiegand <volker@railduino.de>
 * Distributed under MIT license - see LICENSE for details
 *
 */

#ifndef ButtonReader_h
#define ButtonReader_h

#include "Arduino.h"

const unsigned long defaultTimer = 50;

enum BtnState {
  isPassive,
  isPressed,
  isActive,
  isReleased
};

/*
 * For a detailed description of the interface see the .cpp file
 */

class ButtonReader {
  public:
    ButtonReader(int pin, unsigned long timer);
    ButtonReader(int pin);

    BtnState readState(void);
    BtnState getCurrent(void);

  private:
    unsigned long _timer;
    unsigned long _seen;
    int _pin;
    int _curr;
    int _last;
    int _prev;
    BtnState _state;
    bool _startup;
};

#endif
