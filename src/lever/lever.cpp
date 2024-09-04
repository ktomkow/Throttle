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

  Serial.print("Physical State: ");
  Serial.println(_physicalState);

  Serial.print("Min read: ");
  Serial.print(_minRead);
  Serial.print(" Max read: ");
  Serial.println(_maxRead);
  Serial.println("***********************");
}

void Lever::init() {
  Serial.println("***********************");
  Serial.print("Lever: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.println(" initialization STARTED");

  _isInitialized = true;
  _physicalState = analogRead(_pin);
  _logicState = recalculateLogicalState();
  reportLogicalState();

  Serial.print("Lever: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.println(" initialization FINISHED");
  Serial.println("***********************");
}

void Lever::act() {
  if (_isInitialized != true) {
    return;
  }

  _physicalState = analogRead(_pin);
  unsigned short logicState = recalculateLogicalState();

  // do not report if nothing changed
  if (logicState == _logicState) {
    return;
  }

  _logicState = logicState;
  reportLogicalState();
}

void Lever::handle(const ButtonStateChangedPayload& payload) {
  // if (payload.state == ACTIVE_INPUT_STATE) {
  //   printState();
  // }
}

unsigned short Lever::recalculateLogicalState() {
  return map(_physicalState, _minRead, _maxRead, _minLogical, _maxLogical);
}

void Lever::reportLogicalState() {
  Message message;
  message.type = MSG_POTENTIOMETER_STATE_CHANGED;
  message.payload.potentiometerStateChangedPayload.id = _id;
  message.payload.potentiometerStateChangedPayload.state = _logicState;

  Publisher::publish(message);
}