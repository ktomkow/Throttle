#include "./subscriber.h"

Subscriber::Subscriber(DataBus& bus) {
  _bus = bus;
}

void Subscriber::act() {
  Collection<BusMessage>::Enumerator enumerator = _bus.getEnumerator();
  while (enumerator.getNext()) {
    Serial.println("Found one!");
    BusMessage message = enumerator.getCurrent();
    switch (message.type) {
      case MSG_BUTTON_STATE_CHANGED:
        ButtonStateChangedPayload payload = message.payload.buttonStateChangePayload;
        Serial.println("Handling MSG_BUTTON_STATE_CHANGED");
        Serial.print(" : ");
        Serial.println(payload.state);
        return;
      default:
        Serial.print("Unknown/not implemented message type ");
        Serial.println(message.type);
        return;
    }
  }
}
