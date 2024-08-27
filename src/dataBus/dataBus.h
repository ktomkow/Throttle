#ifndef DATABUS_H
#define DATABUS_H

#include "../domain.h";
#include "../enumerable/enumerable.h";


class DataBus {
private:
  Collection<BusMessage>* _messages;

public:
  DataBus();
  // ~DataBus();
  // void push(BusMessage& busMessage);
  // // Collection<BusMessage>::Enumerator getEnumerator();
  // void clear();
  // bool isAny();
};

#endif