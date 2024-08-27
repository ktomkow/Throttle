#ifndef bus.h
#define bus.h

#include "Arduino.h"

enum MessageType {
  None = 0,
  ConfigModeStarted = 1,
  ConfigModeFinished = 2,
  CalibrationLeftClicked = 3,
  CalibrationRightClicked = 4
};

enum BusMessageType {
  EmptyMessage = 0,
  ConfigModeChanged = 1,
  ButtonStateChanged = 2,
  PotentiometerStateChanged = 3
};

void printMessageNicely(MessageType);

struct ButtonStateChangedPayload {
  unsigned short id;
  bool newState;
};

struct PotentiometerStateChangedPayload {
  unsigned short id;
  unsigned short newState;
};

struct ConfigModeChangedPayload {
  bool isActive;
};

union Payload {
  ButtonStateChangedPayload buttonStateChangePayload;
  PotentiometerStateChangedPayload potentiometerStateChangedPayload;
  ConfigModeChangedPayload configModeChangedPayload;
};

struct BusMessage {
  BusMessageType messageType;
  Payload payload;
};

class Bus {
private:
  MessageType* _messages;
  unsigned short _currentCapacity;
  unsigned short _currentSize;
  void extend();

public:
  Bus();
  void pop();
  MessageType getCurrent();
  void publish(MessageType);
  unsigned short getCapacity();
  unsigned short getSize();
  void print();
};

#endif