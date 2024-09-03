#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include "Arduino.h"

class Heartbeat {
private:
  unsigned long _timestamp;
  int _led;
  bool _state;
  const unsigned int _hysteresisMillis = 1000;

public:
  void act();
  Heartbeat();
};


#endif