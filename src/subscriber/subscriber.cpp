#include "./subscriber.h"

Subscriber::Subscriber() {
  _id = ++subscriberCounter;
}

unsigned short Subscriber::getId() {
  return _id;
}

void Subscriber::handle(const Message& message) {
  switch (message.type) {
    case MSG_BUTTON_STATE_CHANGED:
      handle(message.payload.buttonStateChangePayload);
      return;

    case MSG_POTENTIOMETER_STATE_CHANGED:
      handle(message.payload.potentiometerStateChangedPayload);
      return;

    case MSG_CONFIG_MODE_CHANGED:
      handle(message.payload.configModeChangedPayload);
      return;

    case MSG_EMPTY_MESSAGE:
    default:
      return;
  }
}