#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Arduino.h"

#include "../domain.h"
#include "../dataBus/dataBus.h"

class Subscriber {
  private:
    DataBus& _bus;

  public:
    Subscriber(DataBus& bus);
    void act();
};


#endif