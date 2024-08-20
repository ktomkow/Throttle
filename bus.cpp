#include "bus.h"

void printMessageNicely(MessageType message) {
  switch (message) {
    case 1:
      Serial.println("ConfigModeStarted (1)");
      return;
    case 2:
      Serial.println("ConfigModeFinished (2)");
      return;
    case 3:
      Serial.println("CalibrationLeftClicked (3)");
      return;
    case 4:
      Serial.println("CalibrationRightClicked (4)");
      return;
    default:
      Serial.println("None");
      return;
  }
}

Bus::Bus() {
  _currentCapacity = 4;
  _currentSize = 0;

  _messages = new MessageType[_currentSize];
}

void Bus::publish(MessageType message) {
  if (message == None) {
    return;
  }

  if (_currentSize == _currentCapacity) {
    extend();
  }

  _messages[_currentSize] = message;
  _currentSize++;
}

void Bus::pop() {
  if (_currentSize > 0) {
    _currentSize--;
  }
}

void Bus::extend() {
  unsigned short newCapacity = _currentCapacity + 2;
  MessageType* oldMessages = _messages;

  delete[] _messages;

  _messages = new MessageType[newCapacity];

  for (unsigned short i = 0; i < _currentCapacity; i++) {
    _messages[i] = oldMessages[i];
  }

  _currentCapacity = newCapacity;
}

MessageType Bus::getCurrent() {
  if (_currentSize == 0) {
    return None;
  }

  return _messages[_currentSize - 1];
}

unsigned short Bus::getCapacity() {
  return _currentCapacity;
}

unsigned short Bus::getSize() {
  return _currentSize;
}

void Bus::print() {
  Serial.println("=========");
  Serial.print("Size: ");
  Serial.println(getSize());
  Serial.print("Capacity: ");
  Serial.println(getCapacity());
  for (unsigned short i = 0; i < _currentSize; i++) {
    Serial.println(_messages[i]);
  }
  Serial.println("=========");
}