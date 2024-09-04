#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include "Arduino.h"

#include "../domain.h";
#include "../printer/printer.h";

class MessageBus {
private:
  Message* _messages;
  unsigned short _capacity;
  unsigned short _size;
  void extend();

public:
  MessageBus();
  ~MessageBus();

  void publish(const Message&);
  void clear();
  bool isAny();
  void printStats();
  unsigned short getSize();
  Message& operator[](unsigned short) const;
};


#endif