#include "./lever.h"

Lever::Lever(unsigned short id, int pin, const Mediator* mediator)
  : Publisher(mediator) {
  Serial.print("Lever ");
  Serial.print(id);
  Serial.println(" constructor STARTED");

  _id = id;
  _pin = pin;
  _isInitialized = false;

  Serial.print("Lever ");
  Serial.print(id);
  Serial.println(" constructor FINISHED");
}

void Lever::printState() {
  Serial.println("***********************");
  Serial.print("Lever: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.print(" is initialized: ");
  Serial.println(_isInitialized);

  Serial.print("State: ");
  Serial.println(_state);

  Serial.print("Min read: ");
  Serial.print(_minRead);
  Serial.print(" Max read: ");
  Serial.println(_maxRead);
  Serial.println("***********************");
}

void Lever::init() {
  Serial.print("Lever ");
  Serial.print(_id);
  Serial.println(" initialization STARTED");

  _isInitialized = true;
  _state = analogRead(_pin);

  Serial.print("Lever ");
  Serial.print(_id);
  Serial.println(" initialization FINISHED");
}

void Lever::act() {
  if(_isInitialized != true) {
    return;
  }

  _state = analogRead(_pin);
}