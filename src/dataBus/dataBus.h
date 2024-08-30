#ifndef DATABUS_H
#define DATABUS_H

#include "Arduino.h"

#include "../domain.h";
#include "../enumerable/enumerable.h";


class DataBus {
private:
  Collection<BusMessage>* _messages;

public:
  DataBus();
  ~DataBus();
  void publish(BusMessage& busMessage);
  Collection<BusMessage>::Enumerator getEnumerator();
  void clear();
  bool isAny();
  void hello(short);
};

#endif