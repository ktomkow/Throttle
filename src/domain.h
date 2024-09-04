#ifndef DOMAIN_H
#define DOMAIN_H

enum InputState {
  UNDEFINED_INPUT_STATE = 0,
  INACTIVE_INPUT_STATE = 1,
  ACTIVE_INPUT_STATE = 2,
};


enum MessageType {
  MSG_EMPTY_MESSAGE = 0,
  MSG_CONFIG_MODE_CHANGED = 1,
  MSG_BUTTON_STATE_CHANGED = 2,
  MSG_POTENTIOMETER_STATE_CHANGED = 3
};

struct ButtonStateChangedPayload {
  short id;
  InputState state;
};

struct PotentiometerStateChangedPayload {
  short id;
  int state;
};

struct ConfigModeChangedPayload {
  bool isActive;
};

union Payload {
  ButtonStateChangedPayload buttonStateChangePayload;
  PotentiometerStateChangedPayload potentiometerStateChangedPayload;
  ConfigModeChangedPayload configModeChangedPayload;
};

struct Message {
  MessageType type;
  Payload payload;
};

#endif