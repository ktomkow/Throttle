#ifndef slopeDetector.h
#define slopeDetector .h

#include "Arduino.h"
#include "button.h"

class SlopeDetector {
private:
  bool _isPreinitialized;
  bool _isInitialized;
  ThrottleButton* _button;
  bool _lastState;

protected:
  virtual void onSlopeUp();
  virtual void onSlopeDown();

public:
  SlopeDetector(ThrottleButton* btn);
  void init();
  void act();
};

#endif