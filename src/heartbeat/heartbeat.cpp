#include "heartbeat.h";

Heartbeat::Heartbeat() {
  Serial.println("Heartbeat initialization");
  _timestamp = millis();
  _led = 10;
  _state = false;
  _isInitialRun = true;

  pinMode(_led, OUTPUT);
  digitalWrite(_led, _state == true ? LOW : HIGH);

  Serial.println("Heartbeat is initialized");
}

void Heartbeat::act() {
  unsigned long now = millis();
  if (now - _timestamp > _hysteresisMillis || _isInitialRun == true) {
    _isInitialRun = false;
    _timestamp = now;
    digitalWrite(_led, _state == true ? LOW : HIGH);
    _state = !_state;
    Serial.print("Heartbeat ");
    Serial.println(now, BIN);
  }
}
