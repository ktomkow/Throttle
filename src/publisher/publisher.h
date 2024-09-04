#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Arduino.h"

#include "../domain.h"
#include "../mediator/mediator.h"

class Publisher {
  protected:
    Mediator* _mediator;

  public:
    Publisher(const Mediator*);
    virtual void publish(const Message&);
};

#endif