#include "./debugSubscriber.h"

DebugSubscriber::DebugSubscriber(const MessageBus* bus) {
  Serial.println("DebugSubscriber initialization STARTED");
  _bus = bus;

  Serial.println("DebugSubscriber initialization FINISHED");
}

void DebugSubscriber::act() {
  for (unsigned short i = 0; i < _bus->getSize(); ++i) {
    printMessage((*_bus)[i]);
  }
}
