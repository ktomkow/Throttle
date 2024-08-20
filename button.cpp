#include "button.h"


ThrottleButton::ThrottleButton(int pin) {
  _isInitialized = false;
  _state = false;
  _lastRead = false;
  _pin = pin;
  _readSinceTimestamp = 0;
}

int ThrottleButton::getPin() {
  return _pin;
}

bool ThrottleButton::getState() {
  return _state;
}

void ThrottleButton::report() {
  
}

void ThrottleButton::act() {
  if (_isInitialized == false) {
    return;
  }

  unsigned long nowTimestamp = millis();
  int currentRead = digitalRead(_pin) == 0 ? true : false;

  if (_lastRead == currentRead) {
    if (nowTimestamp - _readSinceTimestamp >= _hysteresisMillis) {
      if (currentRead != _state) {
        if (currentRead == true) {
          onActiveStateEntered();
        } else {
          onInactiveStateEntered();
        }
      }
    }
  } else {
    _readSinceTimestamp = nowTimestamp;
  }

  _lastRead = currentRead;
}

void ThrottleButton::init() {
  pinMode(_pin, INPUT);

  _readSinceTimestamp = millis();
  _isInitialized = true;

  _lastRead = digitalRead(_pin) == 0 ? true : false;
  _state = _lastRead;

  Serial.print("Initialized button on PIN: ");
  Serial.println(_pin);
}

void ThrottleButton::onActiveStateEntered() {
  _state = 1;
}

void ThrottleButton::onInactiveStateEntered() {
  _state = 0;
}

bool ThrottleButton::isInitialized() {
  return _isInitialized;
}