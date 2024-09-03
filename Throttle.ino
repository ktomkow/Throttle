#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
#include "./src/messageBus/messageBus.h"
#include "./src/subscriber/subscriber.h"
#include "./src/throttleButton/throttleButton.h"

Heartbeat* heartbeat;
MessageBus* messageBus;
Subscriber* subscriber;
ThrottleButton* firstButton;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initialized Serial");

  heartbeat = new Heartbeat();

  messageBus = new MessageBus();
  subscriber = new Subscriber(messageBus);

  firstButton = new ThrottleButton(messageBus, 2, 2);

  messageBus->printStats();

  firstButton->init();

  Serial.println();
  Serial.println("==========================");
  Serial.println("***** END  OF  SETUP *****");
  Serial.println("==========================");
  Serial.println();
  Serial.flush();
}

void loop() {
  heartbeat->act();
  firstButton->act();
  subscriber->act();
  messageBus->clear();
  delay(10);
}
