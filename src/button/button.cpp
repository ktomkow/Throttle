#include "./button.h"

Button::Button(MessageBus* bus, int pin, short id) {
  _id = id;
  _bus = bus;
  _pin = pin;
  _state = UNDEFINED_INPUT_STATE;
  _lastRead = UNDEFINED_INPUT_STATE;
  _readSinceTimestamp = 0;
  _isInitialized = false;
}

int Button::getPin() {
  return _pin;
}

InputState Button::getState() {
  return _state;
}

void Button::init() {
  Serial.print("Initializing button Id: ");
  Serial.print(_id);
  Serial.print(" On PIN: ");
  Serial.println(_pin);


  pinMode(_pin, INPUT);

  _readSinceTimestamp = millis();

  _isInitialized = true;


  _lastRead = digitalRead(_pin) == 0 ? ACTIVE_INPUT_STATE : INACTIVE_INPUT_STATE;
  _state = _lastRead;

  Serial.print("Initialized button on PIN: ");
  Serial.println(_pin);

  if (_lastRead == ACTIVE_INPUT_STATE) {
    onActiveStateEntered();
  } else {
    onInactiveStateEntered();
  }
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

BusMessage Button::createPayload() {
  BusMessage message;
  message.type = MSG_BUTTON_STATE_CHANGED;
  message.payload.buttonStateChangePayload.id = _id;
  message.payload.buttonStateChangePayload.state = _state;

  return message;
}

void Button::publish() {
  BusMessage busMessage = createPayload();
  _bus->publish(busMessage);
}