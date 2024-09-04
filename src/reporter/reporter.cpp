#include "./reporter.h"

Reporter::Reporter(Joystick_* joystick) {
  _joystick = joystick;
  _isInitialized = false;
}

void Reporter::init() {
  _isInitialized = true;
}

void Reporter::handle(const ButtonStateChangedPayload& payload) {
  if(_isInitialized != true) {
    return;
  }

  short buttonId = payload.id;
  if (payload.state == ACTIVE_INPUT_STATE) {
    _joystick->pressButton(buttonId);
  } else {
    _joystick->releaseButton(buttonId);
  }
}