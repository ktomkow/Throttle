#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Arduino.h"

#include "../domain.h"

class Subscriber {

protected:
  virtual void handle(const ButtonStateChangedPayload&) {}
  virtual void handle(const PotentiometerStateChangedPayload&) {}
  virtual void handle(const ConfigModeChangedPayload&) {}

public:
  void handle(const Message&);
};

#endif