#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Arduino.h"

#include "../domain.h"
#include "../messageBus/messageBus.h"
#include "../printer/printer.h"

class Subscriber {
  private:
    MessageBus* _bus;

  public:
    Subscriber(const MessageBus* bus);
    void act();
};


#endif