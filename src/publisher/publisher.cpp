#include "./publisher.h"

Publisher::Publisher(const Mediator* mediator) {
  _mediator = mediator;
}

void Publisher::publish(const Message& message) {
  _mediator->publish(message);
}