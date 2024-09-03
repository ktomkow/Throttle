#include "Arduino.h"
#include "messageBus.h"

MessageBus::MessageBus() {
  Serial.println("MessageBus initialization");
  Serial.println("MessageBus is initialized");
}

MessageBus::~MessageBus() {
  delete _messages;
}

void MessageBus::publish(const BusMessage& busMessage) {}
void MessageBus::clear() {}
bool MessageBus::isAny() {
  return false;
}