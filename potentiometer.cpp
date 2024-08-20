#include "potentiometer.h"


ThrottlePotentiometer::ThrottlePotentiometer(int pin) {
  _isInitialized = false;
  _state = 0;
  _pin = pin;
  _minValue = 13;
  _maxValue = 1011;
  _isCalibrationInProgress = false;
}

int ThrottlePotentiometer::getPin() {
  return _pin;
}

int ThrottlePotentiometer::getState() {
  return _state;
}

void ThrottlePotentiometer::report() {
}

void ThrottlePotentiometer::init() {
  Serial.print("Initialized potentiometer on PIN: ");
  Serial.println(_pin);

  _isInitialized = true;
}

void ThrottlePotentiometer::act() {
  if (_isInitialized == false) {
    return;
  }

  if(_isCalibrationInProgress == true) {
    calibrationAct();
  }

  int currentState = analogRead(_pin);
  if (currentState < _minValue) {
    currentState = _minValue;
  }

  if (currentState > _maxValue) {
    currentState = _maxValue;
  }

  _state = currentState;
  Serial.println(_state);
}

void ThrottlePotentiometer::calibrationAct() {
  if (_isCalibrationInProgress == false) {
    return;
  }

}

void ThrottlePotentiometer::startMinValueCalibration() {
  if (_isCalibrationInProgress == true) {
    return;
  }

  _isCalibrationInProgress = true;
}

void ThrottlePotentiometer::startMaxValueCalibration() {
  if (_isCalibrationInProgress == true) {
    return;
  }

  _isCalibrationInProgress = true;
}