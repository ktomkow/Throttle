#ifndef LEVER_H
#define LEVER_H

#include "Arduino.h"
#include "../domain.h"
#include "../subscriber/subscriber.h"
#include "../publisher/publisher.h"
#include "../mediator/mediator.h"
#include "../filter/filter.h"

class Lever : public Subscriber, public Publisher {
private:
  bool _isInitialized;
  bool _useDebugOutput;
  unsigned short _id;
  int _pin;
  unsigned short _physicalState = 0;
  unsigned short _logicState = 0;
  unsigned short _minPhysicalRead = 200;
  unsigned short _borderline = 500;
  unsigned short _maxPhysicalRead = 900;
  unsigned short _borderOffset = 5;
  unsigned short _minLogicRead = 0;
  unsigned short _maxLogicRead = 255;
  unsigned short recalculateLogicalState();
  void reportLogicalState();
  unsigned short makeRead();
  void calibrate();
  Filter* _filter;

protected:
  virtual void handle(const ButtonStateChangedPayload&) override;

public:
  Lever(unsigned short id, int pin, bool useDebugOutput, const Mediator* mediator);

  void printState();
  void init();
  void act();
};

#endif
