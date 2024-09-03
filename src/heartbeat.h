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

Heartbeat::Heartbeat(Picker& picker) {
  Serial.println("Heartbeat initialization")
  _timestamp = millis();
  _picker = picker;
  _led = 10;
  _state = false;

  pinMode(_led, OUTPUT);
  digitalWrite(_led, _state == true ? LOW : HIGH);

  Serial.println("Heartbeat is initialized");
}

void Heartbeat::act() {

  unsigned long now = millis();
  if (now - _timestamp > _hysteresisMillis) {
    _timestamp = now;
    digitalWrite(_led, _state == true ? LOW : HIGH);
    _state = !_state;
    Serial.print("Heartbeat ");
    Serial.println(_picker.take(), BIN);
  }
}

#endif