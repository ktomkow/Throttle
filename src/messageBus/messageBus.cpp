#include "Arduino.h"
#include "messageBus.h"

MessageBus::MessageBus() {
  Serial.println("MessageBus initialization");

  _size = 0;
  _capacity = 4;
  _messages = new BusMessage[_capacity];

  Serial.println("MessageBus is initialized");
}

MessageBus::~MessageBus() {
  delete[] _messages;
}

void MessageBus::publish(const BusMessage& busMessage) {
  if (_size >= _capacity) {
    extend();
  }

  _messages[_size++] = busMessage;
}

BusMessage& MessageBus::operator[](unsigned short index) const {
  return _messages[index];
}

void MessageBus::clear() {
  delete[] _messages;
  _messages = nullptr;
  _size = 0;
  _capacity = 4;
  _messages = new BusMessage[_capacity];
}

bool MessageBus::isAny() {
  return _size > 0;
}

unsigned short MessageBus::getSize() {
  return _size;
}

void MessageBus::extend() {
  _capacity = _capacity + 2;
  BusMessage* newMessages = new BusMessage[_capacity];

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

void MessageBus::printContent() {
  for (unsigned short i = 0; i < _size; i++) {
    Serial.print("Message ");
    Serial.print(i);
    Serial.println(":");
    printBusMessage(_messages[i]);
    Serial.println("-----------------------");
  }
}
