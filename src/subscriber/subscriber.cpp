#include "./subscriber.h"

Subscriber::Subscriber(DataBus& bus) {
  _bus = bus;
}

void Subscriber::clear(){
  _bus.clear();
}