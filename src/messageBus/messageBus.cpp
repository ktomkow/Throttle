#include "Arduino.h"
#include "messageBus.h"

MessageBus::MessageBus() {
  Serial.println("MessageBus initialization STARTED");

  _size = 0;
  _capacity = 4;
  _messages = new Message[_capacity];

  Serial.println("MessageBus initialization FINISHED");
}

MessageBus::~MessageBus() {
  delete[] _messages;
}

void MessageBus::publish(const Message& message) {
  if (_size >= _capacity) {
    extend();
  }

  _messages[_size++] = message;
}

Message& MessageBus::operator[](unsigned short index) const {
  return _messages[index];
}

void MessageBus::clear() {
  delete[] _messages;
  _messages = nullptr;
  _size = 0;
  _capacity = 4;
  _messages = new Message[_capacity];
}

bool MessageBus::isAny() {
  return _size > 0;
}

unsigned short MessageBus::getSize() {
  return _size;
}

void MessageBus::extend() {
  _capacity = _capacity + 2;
  Message* newMessages = new Message[_capacity];

  for (unsigned short i = 0; i < _size; ++i) {
    newMessages[i] = _messages[i];
  }

  delete[] _messages;
  _messages = newMessages;
}

void MessageBus::printStats() {
  Serial.print("Current messageBus size: ");
  Serial.println(_size);
  Serial.print("Current messageBus capacity: ");
  Serial.println(_capacity);
}
