#ifndef LEVER_H
#define LEVER_H

#include "Arduino.h"
#include "../domain.h"
#include "../subscriber/subscriber.h"
#include "../publisher/publisher.h"
#include "../mediator/mediator.h"

class Lever : public Subscriber, public Publisher {
private:
  bool _isInitialized;
  unsigned short _id;
  int _pin;
  unsigned short _physicalState = 0;
  unsigned short _logicState = 0;
  unsigned short _minRead = 0;
  unsigned short _maxRead = 1023;
  unsigned short _minLogical = 0;
  unsigned short _maxLogical = 255;
  unsigned short recalculateLogicalState();
  void reportLogicalState();

protected:
  virtual void handle(const ButtonStateChangedPayload&) override;

public:
  Lever(unsigned short id, int pin, const Mediator* mediator);
  void printState();
  void init();
  void act();
};

#endif