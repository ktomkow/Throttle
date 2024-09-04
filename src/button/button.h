#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

#include "../domain.h"
#include "../subscriber/subscriber.h"
#include "../publisher/publisher.h"
#include "../mediator/mediator.h"

class Button : public Subscriber, public Publisher {
private:
  short _id;
  const unsigned int _hysteresisMillis = 50;
  InputState _state;
  InputState _lastRead;
  bool _isInitialized;
  int _pin;
  unsigned long _readSinceTimestamp;

protected:
  virtual void onActiveStateEntered();
  virtual void onInactiveStateEntered();
  Message createPayload();
  void publish();

public:
  Button(unsigned short id, int pin, const Mediator* mediator);
  int getPin();
  void act();
  void init();
  InputState getState();
};

#endif