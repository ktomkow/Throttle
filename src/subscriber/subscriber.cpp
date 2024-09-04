#include "./subscriber.h"

Subscriber::Subscriber(const MessageBus* bus) {
  Serial.println("Subscriber initialization STARTED");
  _bus = bus;

  Serial.println("Subscriber initialization FINISHED");
}

void Subscriber::act() {
  for (unsigned short i = 0; i < _bus->getSize(); ++i) {
    printMessage((*_bus)[i]);
  }
}
