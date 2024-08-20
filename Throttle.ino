// #include "button.h"
// #include "potentiometer.h"
// #include "slopeDetector.h"
// #include "bus.h"
// #include "communicativeSlopeDetector.h"
// #include "debugSubsriber.h"
// #include "src/masterInclude.h"

// ThrottleButton buttons[1] = {
//   ThrottleButton(3)
// };

// ThrottleButton aButton(2);
// SlopeDetector foo(&aButton);

// ThrottlePotentiometer pot(A0);

// Bus buss;

// CommunicativeSlopeDetector detector(0, &aButton, &buss);

// DebugSubscriber dbgSubscriber(&buss);

// Queue q;

// void setup() {
//   Serial.begin(9600);
//   while (!Serial)
//     ;

//   for (unsigned int i = 0; i < 1; i++) {
//     buttons[i].init();
//   }

//   aButton.init();
//   pot.init();
//   detector.init();

//   Serial.println("Setup initialized");

//   detector.setMessageOnSlopeUp(ConfigModeStarted);
//   detector.setMessageOnSlopeDown(ConfigModeFinished);
// }

// int i = 0;

// void loop() {
//   int a = q.getOne();
//   Serial.println(a);
//   aButton.act();
//   detector.act();
//   dbgSubscriber.act();

//   buss.pop();
//   // delay(1000);
//   // foo.saySomething();

//   // aButton.act();

//   // for (unsigned int i = 0; i < 1; i++) {
//   //   buttons[i].act();
//   // }
// }

