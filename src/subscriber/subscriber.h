#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Arduino.h"

#include "../domain.h"

static unsigned short subscriberCounter = 0;

class Subscriber {

protected:
  unsigned short _id;
  virtual void handle(const ButtonStateChangedPayload&) {}
  virtual void handle(const PotentiometerStateChangedPayload&) {}
  virtual void handle(const ConfigModeChangedPayload&) {}

public:
  Subscriber();
  void handle(const Message&);
  unsigned short getId();
};

#endif