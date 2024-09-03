#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include "Arduino.h"

#include "../domain.h";
#include "../printer/printer.h";

class MessageBus {
private:
  BusMessage* _messages;
  unsigned short _capacity;
  unsigned short _size;
  void extend();

public:
  MessageBus();
  ~MessageBus();

  void publish(const BusMessage& busMessage);
  void clear();
  bool isAny();
  void printStats();
  void printContent();
  unsigned short getSize();
  BusMessage& operator[](unsigned short index) const;
};


#endif