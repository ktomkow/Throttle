#include "./throttleButton.h"

ThrottleButton::ThrottleButton(DataBus& bus, int pin, short id) {
  _id = id;
  _bus = bus;
  _pin = pin;
  _state = UNDEFINED_INPUT_STATE;
  _lastRead = UNDEFINED_INPUT_STATE;
  _readSinceTimestamp = 0;
  _isInitialized = false;
}

int ThrottleButton::getPin() {
  return _pin;
}

InputState ThrottleButton::getState() {
  return _state;
}

void ThrottleButton::init() {
  pinMode(_pin, INPUT);

  _readSinceTimestamp = millis();
  _isInitialized = true;

  _lastRead = digitalRead(_pin) == 0 ? ACTIVE_INPUT_STATE : INACTIVE_INPUT_STATE;
  _state = _lastRead;

  Serial.print("Initialized button on PIN: ");
  Serial.println(_pin);
}

void ThrottleButton::act() {
  if (_isInitialized == false) {
    return;
  }

  unsigned long nowTimestamp = millis();
  int currentRead = digitalRead(_pin) == 0 ? ACTIVE_INPUT_STATE : INACTIVE_INPUT_STATE;

  if (_lastRead == currentRead) {
    if (nowTimestamp - _readSinceTimestamp >= _hysteresisMillis) {
      if (currentRead != _state) {
        if (currentRead == true) {
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

void ThrottleButton::onActiveStateEntered() {
  _state = ACTIVE_INPUT_STATE;
  publish();
}

void ThrottleButton::onInactiveStateEntered() {
  _state = INACTIVE_INPUT_STATE;
  publish();
}

BusMessage ThrottleButton::createPayload() {
  ButtonStateChangedPayload buttonChangedPayload;
  buttonChangedPayload.id = _id;
  buttonChangedPayload.state = _state;

  BusMessageType messageType = MSG_BUTTON_STATE_CHANGED;

  Payload messagePayload;
  messagePayload.buttonStateChangePayload = buttonChangedPayload;

  BusMessage message;
  message.type = messageType;
  message.payload = messagePayload;
}

void ThrottleButton::publish() {
  BusMessage busMessage = createPayload();
  _bus.publish(busMessage);
}