#ifndef THROTTLEBUTTON_H
#define THROTTLEBUTTON_H

#include "Arduino.h"

#include "../domain.h"
#include "../messageBus/messageBus.h"

class ThrottleButton {
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
  ThrottleButton(MessageBus* bus, int pin, short id);
  int getPin();
  void act();
  void init();
  InputState getState();
};

#endif