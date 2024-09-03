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

// =======================

#include "./src/domain.h"
#include "./src/dataBus/dataBus.h"
#include "./src/subscriber/subscriber.h"
#include "./src/throttleButton/throttleButton.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat.h"
#include "./src/enumerable/enumerable.h"

DataBus* bus;
Subscriber* subscriber;
ThrottleButton* btn;

bool problem = false;

Picker* picker;
Heartbeat* heartbeat;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;


  Serial.println("Initialized Serial");

  picker = new Picker();

  Serial.println("Initialized Picker");

  heartbeat = new Heartbeat(*picker);

  Serial.println("Initialized Heartbeat");

  bus = new DataBus();
  subscriber = new Subscriber(*bus);
  // btn = new ThrottleButton(*bus, 2, 2);

  // Serial.println("Initializing..");

  // btn->init();

  // Serial.println("Initialized!");

  // BusMessage message1;
  // message1.type = MSG_BUTTON_STATE_CHANGED;
  // message1.payload.buttonStateChangePayload.id = 1;
  // message1.payload.buttonStateChangePayload.state = ACTIVE_INPUT_STATE;

  // BusMessage message2;
  // message2.type = MSG_POTENTIOMETER_STATE_CHANGED;
  // message2.payload.potentiometerStateChangedPayload.id = 2;
  // message2.payload.potentiometerStateChangedPayload.state = 512;

  // BusMessage message3;
  // message3.type = MSG_CONFIG_MODE_CHANGED;
  // message3.payload.configModeChangedPayload.isActive = true;

  // printBusMessage(message1);
  // printBusMessage(message2);
  // printBusMessage(message3);

  // subscriber->act();
  Serial.println("===============================");

  Collection<int> *ints;
  ints = new Collection<int>();
  Serial.println("Ints alive");

  ints->push(50);
  ints->push(51);
  // // ints.push(52);

  int size = ints->getSize();
  Serial.print("Ints Size: ");
  Serial.println(size);


  Serial.println("===============================");

  // delay(1000);
}

void loop() {
  if (!Serial) {
    problem = true;
  }

  if (problem == true && !!Serial) {
    Serial.print("There was problem with serial");
    problem = false;
  }
  heartbeat->act();
  // subscriber->act();
  // Serial.println("Loop");
  // btn->act();u
  // subscriber->act();
  // bus->clear();
  delay(10);
}
