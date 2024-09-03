#include "./dataBus.h"

#include "Arduino.h"

DataBus::DataBus() {
  Serial.println("DataBus initialization begins");
  _messages = new Collection<BusMessage>();

  // BusMessage message3;
  // message3.type = MSG_CONFIG_MODE_CHANGED;
  // message3.payload.configModeChangedPayload.isActive = true;
  // _messages->push(message3);

  Serial.println("DataBus initialized");
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
  Serial.print("Data bus collection size: ");
  delay(10);
  int size = _messages->getSize();
  delay(10);
  Serial.println(size);
  delay(10);
  return _messages->getSize() > 0;
}


void DataBus::hello(short id) {
  Serial.print(id);
  Serial.println(" Says 'hello'");
}
