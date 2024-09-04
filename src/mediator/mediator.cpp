#include "./mediator.h"

Mediator::Mediator() {
  _firstSubscriber = nullptr;
}

void Mediator::subscribe(const Subscriber* subscriber) {
  Serial.print("Registering subscriber ");
  Serial.println(subscriber->getId());

  if (_firstSubscriber == nullptr) {
    _firstSubscriber = new SubscriberItem();
    _firstSubscriber->subscriber = subscriber;
    _firstSubscriber->next = nullptr;
    return;
  }

  SubscriberItem* current = _firstSubscriber;
  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = new SubscriberItem();
  current->next->subscriber = subscriber;
  current->next->next = nullptr;
}

void Mediator::publish(const Message& message) {}

void Mediator::printSubscribers() {
  if (_firstSubscriber == nullptr) {
    Serial.println("No subscribers at all");
    return;
  }

  Serial.println("List of subscribers:");
  SubscriberItem* current = _firstSubscriber;
  while (current != nullptr) {
    Serial.println(current->subscriber->getId());
    current = current->next;
  }
}