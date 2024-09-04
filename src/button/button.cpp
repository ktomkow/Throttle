#include "./button.h"

Button::Button(unsigned short id, int pin, const Mediator* mediator)
  : Publisher(mediator) {
  Serial.print("Button ");
  Serial.print(id);
  Serial.println(" constructor STARTED");

  _id = id;
  _pin = pin;
  _state = UNDEFINED_INPUT_STATE;
  _lastRead = UNDEFINED_INPUT_STATE;
  _readSinceTimestamp = 0;
  _isInitialized = false;

  Serial.print("Button ");
  Serial.print(id);
  Serial.println(" constructor FINISHED");
}

int Button::getPin() {
  return _pin;
}

InputState Button::getState() {
  return _state;
}

void Button::init() {
  Serial.println("***********************");
  Serial.print("Button: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.println(" initialization STARTED");

  pinMode(_pin, INPUT);

  _readSinceTimestamp = millis();

  _isInitialized = true;

  _lastRead = digitalRead(_pin) == 0 ? ACTIVE_INPUT_STATE : INACTIVE_INPUT_STATE;
  _state = _lastRead;

  if (_lastRead == ACTIVE_INPUT_STATE) {
    onActiveStateEntered();
  } else {
    onInactiveStateEntered();
  }

  Serial.print("Button: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.println(" initialization FINISHED");
  Serial.println("***********************");
}

void Button::act() {
  if (_isInitialized == false) {
    return;
  }

  unsigned long nowTimestamp = millis();
  int currentRead = digitalRead(_pin) == 0 ? ACTIVE_INPUT_STATE : INACTIVE_INPUT_STATE;

  if (_lastRead == currentRead) {
    if (nowTimestamp - _readSinceTimestamp >= _hysteresisMillis) {
      if (currentRead != _state) {
        if (currentRead == ACTIVE_INPUT_STATE) {
          onActiveStateEntered();
        } else {
          onInactiveStateEntered();
        }
      }
    }
  } else {
    _readSinceTimestamp = nowTimestamp;
  }

  _lastRead = currentRead;
}

void Button::onActiveStateEntered() {
  _state = ACTIVE_INPUT_STATE;
  publish();
}

void Button::onInactiveStateEntered() {
  _state = INACTIVE_INPUT_STATE;
  publish();
}

Message Button::createPayload() {
  Message message;
  message.type = MSG_BUTTON_STATE_CHANGED;
  message.payload.buttonStateChangePayload.id = _id;
  message.payload.buttonStateChangePayload.state = _state;

  return message;
}

void Button::publish() {
  Message message = createPayload();
  Publisher::publish(message);
}