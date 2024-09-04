#include "./publisher.h"

Publisher::Publisher(const MessageBus* bus) {
  _bus = bus;
}

void Publisher::publish(const Message& message) {
  _bus->publish(message);
}