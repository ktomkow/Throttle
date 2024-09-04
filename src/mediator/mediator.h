#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Arduino.h"
#include "../domain.h"
#include "../subscriber/subscriber.h"

struct SubscriberItem {
  Subscriber* subscriber;
  SubscriberItem* next;
};

class Mediator {
private:
  SubscriberItem* _firstSubscriber;

public:
  Mediator();
  void subscribe(const Subscriber*);
  void publish(const Message& message);
  void printSubscribers();
};

#endif