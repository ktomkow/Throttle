#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Arduino.h"

#include "../domain.h"
#include "../messageBus/messageBus.h"

class Publisher {
  protected:
    MessageBus* _bus;

  public:
    Publisher(const MessageBus*);
    virtual void publish(const Message&);
};

#endif