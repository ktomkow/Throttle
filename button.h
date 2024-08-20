#ifndef button.h
#define button.h

#include "Arduino.h"

class ThrottleButton {
  private:
    const unsigned int _hysteresisMillis = 50;
    bool _isInitialized;
    bool _state;
    bool _lastRead;
    int _pin;
    unsigned long _readSinceTimestamp;
  
  protected:
    virtual void onActiveStateEntered();
    virtual void onInactiveStateEntered();

  public: 
    ThrottleButton(int);
    int getPin();
    void act();
    void report();
    void init();
    bool getState();
    bool isInitialized();
};

#endif