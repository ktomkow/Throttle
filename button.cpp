// #include "button.h"


// MyBtn::MyBtn(int pin) {
//   _isInitialized = false;
//   _state = false;
//   _lastRead = false;
//   _pin = pin;
//   _readSinceTimestamp = 0;
// }

// int MyBtn::getPin() {
//   return _pin;
// }

// bool MyBtn::getState() {
//   return _state;
// }

// void MyBtn::report() {
  
// }

// void MyBtn::act() {
//   if (_isInitialized == false) {
//     return;
//   }

//   unsigned long nowTimestamp = millis();
//   int currentRead = digitalRead(_pin) == 0 ? true : false;

//   if (_lastRead == currentRead) {
//     if (nowTimestamp - _readSinceTimestamp >= _hysteresisMillis) {
//       if (currentRead != _state) {
//         if (currentRead == true) {
//           onActiveStateEntered();
//         } else {
//           onInactiveStateEntered();
//         }
//       }
//     }
//   } else {
//     _readSinceTimestamp = nowTimestamp;
//   }

//   _lastRead = currentRead;
// }

// void MyBtn::init() {
//   pinMode(_pin, INPUT);

//   _readSinceTimestamp = millis();
//   _isInitialized = true;

//   _lastRead = digitalRead(_pin) == 0 ? true : false;
//   _state = _lastRead;

//   Serial.print("Initialized button on PIN: ");
//   Serial.println(_pin);
// }

// void MyBtn::onActiveStateEntered() {
//   _state = 1;
// }

// void MyBtn::onInactiveStateEntered() {
//   _state = 0;
// }

// bool MyBtn::isInitialized() {
//   return _isInitialized;
// }