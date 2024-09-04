#include "./mediator.h"

Mediator::Mediator() {
  Serial.println("Mediator initialization STARTED");
  _firstSubscriber = nullptr;
  Serial.println("Mediator initialization FINISHED");
}

void Mediator::subscribe(const Subscriber* subscriber) {
  Serial.print("Registering subscriber ");
  Serial.println(subscriber->getSubscriberId());

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

void Mediator::publish(const Message& message) {
  if (_firstSubscriber == nullptr) {
    return;
  }

  SubscriberItem* current = _firstSubscriber;
  while (current != nullptr) {
    current->subscriber->handle(message);
    current = current->next;
  }
}

void Mediator::printSubscribers() {
  if (_firstSubscriber == nullptr) {
    Serial.println("No subscribers at all");
    return;
  }

  Serial.println("List of subscribers:");
  SubscriberItem* current = _firstSubscriber;
  while (current != nullptr) {
    Serial.println(current->subscriber->getSubscriberId());
    current = current->next;
  }
}