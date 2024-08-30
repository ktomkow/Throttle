#include "./dataBus.h"



DataBus::DataBus() {
  _messages = new Collection<BusMessage>();
}

DataBus::~DataBus() {
  delete _messages;
}

void DataBus::publish(BusMessage& busMessage) {
  _messages->push(busMessage);
}

Collection<BusMessage>::Enumerator DataBus::getEnumerator() {
  return _messages->getEnumerator();
}

void DataBus::clear() {
  _messages->clear();
}

bool DataBus::isAny() {
  return _messages->getSize() > 0;
}


void DataBus::hello(short id) {
  Serial.print(id);
  Serial.println(" Says 'hello'");
}
