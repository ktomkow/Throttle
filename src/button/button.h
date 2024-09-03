#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

#include "../domain.h"
#include "../messageBus/messageBus.h"

class Button {
private:
  short _id;
  MessageBus* _bus;
  const unsigned int _hysteresisMillis = 50;
  InputState _state;
  InputState _lastRead;
  bool _isInitialized;
  int _pin;
  unsigned long _readSinceTimestamp;

protected:
  virtual void onActiveStateEntered();
  virtual void onInactiveStateEntered();
  BusMessage createPayload();
  void publish();

public:
  Button(MessageBus* bus, int pin, short id);
  int getPin();
  void act();
  void init();
  InputState getState();
};

#endif