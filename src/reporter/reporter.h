#ifndef REPORTER_H
#define REPORTER_H

#include "Arduino.h"
#include <Joystick.h>

#include "../domain.h"
#include "../subscriber/subscriber.h"
#include "../publisher/publisher.h"
#include "../mediator/mediator.h"

class Reporter : public Subscriber {
private:
  Joystick_* _joystick;
  bool _isInitialized;

protected:
  virtual void handle(const ButtonStateChangedPayload&) override;
  virtual void handle(const PotentiometerStateChangedPayload&) override;

public:
  Reporter(Joystick_*);
  void init();
};

#endif