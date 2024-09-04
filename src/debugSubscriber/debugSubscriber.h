#ifndef DEBUGSUBSCRIBER_H
#define DEBUGSUBSCRIBER_H

#include "Arduino.h"

#include "../domain.h"
#include "../messageBus/messageBus.h"
#include "../printer/printer.h"

class DebugSubscriber {
  private:
    MessageBus* _bus;

  public:
    DebugSubscriber(const MessageBus* bus);
    void act();
};


#endif