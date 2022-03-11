# ButtonReader
#### A "feature poor" Arduino library to get notified when a button (or switch) changes its state.

When a button is pressed or when a switch is turned on or off, there is a short time frame (some milliseconds) in which the digital input of the Arduino changes rapidly from to high to low and back several times. This is called bouncing.

A **ButtonReader** eliminates this bouncing and returns one of four possible states:

- *isPassive*
  - this will be the state most of the time. The button is not pressed, or the switch is open.
- *isPressed*
  - when the button is pressed (or the switch is closed), the *isPressed* code will be returned once.
- *isActive*
  - as long as the button is held down (or the switch is closed), this will be the code returned.
- *isReleased*
  - finally, when the button is released, this code will be returned once. Thereafter, the state will be *isPassive* again, completing an entire "push button" cycle.

And that is all there is to it. There are no other features like button press counting or the like. If you need more features, please use one of the many tried and true libraries like https://www.arduino.cc/reference/en/libraries/ezbutton/

Please refer to the example at https://github.com/railduino/ButtonReader/blob/main/examples/ReadButton/ReadButton.ino for the intended use of this library.

This library is published under the MIT license, please see https://github.com/railduino/ButtonReader/blob/main/LICENSE.

Enjoy!





