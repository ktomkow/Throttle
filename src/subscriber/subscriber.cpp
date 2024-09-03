#include "./subscriber.h"

Subscriber::Subscriber(const MessageBus* bus) {
  Serial.println("Subscriber initialization begins");
  _bus = bus;

  Serial.println("Subscriber initialized");
}

void Subscriber::act() {
  for (unsigned short i = 0; i < _bus->getSize(); ++i) {
    printBusMessage((*_bus)[i]);
  }
}
