#include "communicativeSlopeDetector.h"


CommunicativeSlopeDetector::CommunicativeSlopeDetector(unsigned short id, ThrottleButton* btn, Bus* commBus)
  : SlopeDetector(btn) {
  _id = id;
  _commBus = commBus;
  _messageOnSlopeUp = None;
  _messageOnSlopeDown = None;
}

void CommunicativeSlopeDetector::onSlopeUp() {
  _commBus->publish(_messageOnSlopeUp);
}

void CommunicativeSlopeDetector::onSlopeDown() {
  _commBus->publish(_messageOnSlopeDown);
}

void CommunicativeSlopeDetector::setMessageOnSlopeUp(MessageType message) {
  _messageOnSlopeUp = message;
}

void CommunicativeSlopeDetector::setMessageOnSlopeDown(MessageType message) {
  _messageOnSlopeDown = message;
}