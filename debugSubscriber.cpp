#include "debugSubsriber.h"

DebugSubscriber::DebugSubscriber(Bus* commBus) {
  _commBus = commBus;
}

void DebugSubscriber::act() {
  MessageType message = _commBus->getCurrent();
  if (message == None) {
    return;
  }

  Serial.print("*/dbg ");
  printMessageNicely(message);
}