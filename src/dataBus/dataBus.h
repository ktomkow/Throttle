#ifndef dataBus.h
#define dataBus.h

enum BusMessageType {
  MSG_EMPTY_MESSAGE = 0,
  MSG_CONFIG_MODE_CHANGED = 1,
  MSG_BUTTON_STATE_CHANGED = 2,
  MSG_POTENTIOMETER_STATE_CHANGED = 3
};

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
  BusMessageType type;
  Payload payload;
};

struct QueuedBusMessage {
  BusMessage busMessage;
  BusMessage* next;
};

class DataBus {
  private:
    QueuedBusMessage* _first;
  
  public:
    DataBus();
    void push(BusMessage* busMessage);
    QueuedBusMessage getFirst();
};

#endif