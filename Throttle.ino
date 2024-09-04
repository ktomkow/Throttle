#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
// #include "./src/messageBus/messageBus.h"
#include "./src/debugSubscriber/debugSubscriber.h"
#include "./src/button/button.h"
// #include "./src/subscriber/subscriber.h"
#include "./src/mediator/mediator.h"
#include "./src/lever/lever.h"

Heartbeat* heartbeat;
// MessageBus* messageBus;
// DebugSubscriber* subscriber;
Button* firstButton;
Mediator* mediator;
Lever* lever;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initialized Serial");

  heartbeat = new Heartbeat();

  mediator = new Mediator();
  // messageBus = new MessageBus();
  // subscriber = new DebugSubscriber(messageBus);

  firstButton = new Button(2, 2, mediator);

  lever = new Lever(38, A0, mediator);

  mediator->subscribe(lever);
  mediator->subscribe(firstButton);

  firstButton->init();
  lever->init();
  lever->printState();

  Serial.flush();

  Serial.println();
  Serial.println("==========================");
  Serial.println("***** END  OF  SETUP *****");
  Serial.println("==========================");
  Serial.println();
  Serial.flush();

  delay(10000);
}

void loop() {
  heartbeat->act();
  firstButton->act();
  lever->act();
}
