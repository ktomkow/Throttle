#include "./subscriber.h"

Subscriber::Subscriber(DataBus& bus) {
  Serial.println("Subscriber initialization begins");
  _bus = bus;

  Serial.println("Subscriber initialized");
}

void Subscriber::act() {
  Serial.println("Subscriber act called");
  Serial.println(_bus.isAny());
  if (_bus.isAny() == true) {
    Serial.println("Bus not empty");
  } else {
    Serial.println("Bus empty");
  }


  // Collection<BusMessage>::Enumerator enumerator = _bus.getEnumerator();
  // while (enumerator.getNext()) {
  //   printBusMessage(enumerator.getCurrent());
  // }
}
