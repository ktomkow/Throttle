#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include "Arduino.h"

class Heartbeat {
private:
  unsigned long _timestamp;
  const unsigned int _hysteresisMillis = 3000;

public:
  void act();
  Heartbeat();
};


#endif