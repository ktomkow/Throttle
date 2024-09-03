#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include "Arduino.h"

#include "../domain.h";

class MessageBus {
private:
  BusMessage* _messages;

public:
  MessageBus();
  ~MessageBus();

  void publish(const BusMessage& busMessage);
  void clear();
  bool isAny();
};

#endif