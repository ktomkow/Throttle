#ifndef debugSubscriber.h
#define debugSubscriber.h

#include "Arduino.h"
#include "bus.h"

class DebugSubscriber {
  private:
    Bus* _commBus;

  public:
    DebugSubscriber(Bus*);
    void act();
};

#endif