#ifndef communicativeSlopeDetector.h
#define communicativeSlopeDetector .h

#include "Arduino.h"
#include "slopeDetector.h"
#include "button.h"
#include "bus.h"

class CommunicativeSlopeDetector : public SlopeDetector {
private:
  unsigned short _id;
  MessageType _messageOnSlopeUp;
  MessageType _messageOnSlopeDown;
  Bus* _commBus;

protected:
  virtual void onSlopeUp() override;
  virtual void onSlopeDown() override;

public:
  CommunicativeSlopeDetector(unsigned short, ThrottleButton*, Bus*);
  void setMessageOnSlopeUp(MessageType message);
  void setMessageOnSlopeDown(MessageType message);
};

#endif