// #include "slopeDetector.h"

// SlopeDetector::SlopeDetector(MyBtn* btn) {
//   _button = btn;
//   _isInitialized = false;
//   _isPreinitialized = false;
//   _lastState = false;
// }

// void SlopeDetector::init() {
//   if (_isPreinitialized == true || _isInitialized == true) {
//     return;
//   }

//   _isPreinitialized = true;

//   if(_isInitialized == false &&_button->isInitialized() == true) {
//     _lastState = _button->getState();
//     _isInitialized = true;
//   }
// }

// void SlopeDetector::act() {
//   if (_isPreinitialized == false) {
//     return;
//   }

//   if (_isInitialized == false) {
//     init();
//     return;
//   }

//   int currentState = _button->getState();

//   if(currentState != _lastState) {
//     if(currentState == true) {
//       onSlopeUp();
//     } else {
//       onSlopeDown();
//     }
//   }

//   _lastState = currentState;
// }

// void SlopeDetector::onSlopeUp() { }

// void SlopeDetector::onSlopeDown() { }
