#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include "Arduino.h"


class Picker {
public:
  unsigned long take();
};

unsigned long Picker::take() {
  return millis();
}

class Heartbeat {
private:
  unsigned long _timestamp;
  int _led;
  bool _state;
  const unsigned int _hysteresisMillis = 1000;
  Picker& _picker;
public:
  void act();
  Heartbeat(Picker&);
};

Heartbeat::Heartbeat(Picker& picker) {
  _timestamp = millis();
  _picker = picker;
  _led = 10;
  _state = false;

  pinMode(_led, OUTPUT);                            // pin as output.
  digitalWrite(_led, _state == true ? LOW : HIGH);  // pin low

  Serial.println("Heartbeat is initialized");
}

void Heartbeat::act() {

  unsigned long now = millis();
  if (now - _timestamp > _hysteresisMillis) {
    _timestamp = now;
    digitalWrite(_led, _state == true ? LOW : HIGH);  // pin low
    _state = !_state;
    Serial.print("Heartbeat ");
    Serial.println(_picker.take(), BIN);
  }
}

#endif