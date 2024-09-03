// #ifndef potentiometer.h
// #define potentiometer.h

// #include "Arduino.h"
// #include "bus.h"

// class ThrottlePotentiometer {
//   private:
//     const unsigned short _calibrationSamplesCount = 20;
//     bool _isInitialized;
//     int _state;
//     int _pin;
//     bool _isCalibrationInProgress;
//     int _minValue;
//     int _maxValue;
//     void calibrationAct();

//   public: 
//     ThrottlePotentiometer(int);
//     int getPin();
//     void act();
//     void report();
//     void init();
//     int getState();
//     void startMinValueCalibration();
//     void startMaxValueCalibration();
// };

// #endif