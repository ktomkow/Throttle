#include "./reporter.h"

Reporter::Reporter(Joystick_* joystick) {
  _joystick = joystick;
  _isInitialized = false;
}

void Reporter::init() {
  _isInitialized = true;
}

void Reporter::handle(const ButtonStateChangedPayload& payload) {
  if (_isInitialized != true) {
    return;
  }

  short buttonId = payload.id;
  if (payload.state == ACTIVE_INPUT_STATE) {
    _joystick->pressButton(buttonId);
  } else {
    _joystick->releaseButton(buttonId);
  }
}

void Reporter::handle(const PotentiometerStateChangedPayload& payload) {
  if (_isInitialized != true) {
    return;
  }

  switch (payload.id) {
    case 40:
      _joystick->setXAxis(payload.state);
      break;
    case 41:
      _joystick->setYAxis(payload.state);
      break;
    case 42:
      _joystick->setZAxis(payload.state);
      break;
    case 43:
      _joystick->setRxAxis(payload.state);
      break;
    case 44:
      _joystick->setRyAxis(payload.state);
      break;
    case 45:
      _joystick->setRzAxis(payload.state);
      break;
    default:
      break;
  }
  // _joystick->setXAxis(payload.state);
}