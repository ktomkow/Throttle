#include "heartbeat.h";

Heartbeat::Heartbeat() {
  Serial.println("Heartbeat initialization STARTED");
  _timestamp = millis();

  Serial.println("Heartbeat initialization FINISHED");
}

void Heartbeat::act() {
  unsigned long now = millis();
  if (now - _timestamp > _hysteresisMillis) {
    _timestamp = now;
    Serial.print("Heartbeat ");
    Serial.println(now, BIN);
  }
}
