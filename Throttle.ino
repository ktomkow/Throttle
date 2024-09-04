#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
#include "./src/messageBus/messageBus.h"
#include "./src/debugSubscriber/debugSubscriber.h"
#include "./src/button/button.h"
#include "./src/subscriber/subscriber.h"
#include "./src/mediator/mediator.h"

Heartbeat* heartbeat;
MessageBus* messageBus;
DebugSubscriber* subscriber;
Button* firstButton;
Mediator* mediator;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initialized Serial");

  heartbeat = new Heartbeat();

  messageBus = new MessageBus();
  subscriber = new DebugSubscriber(messageBus);

  firstButton = new Button(messageBus, 2, 2);

  messageBus->printStats();

  firstButton->init();

  Serial.println();
  Serial.println("==========================");
  Serial.println("***** END  OF  SETUP *****");
  Serial.println("==========================");
  Serial.println();
  Serial.flush();

  Subscriber* sub1 = new Subscriber();
  Subscriber* sub2 = new Subscriber();
  Subscriber* sub3 = new Subscriber();

  Serial.print("Sub 1 id: ");
  Serial.println(sub1->getSubscriberId());
  Serial.print("Sub 2 id: ");
  Serial.println(sub2->getSubscriberId());
  Serial.print("Sub 3 id: ");
  Serial.println(sub3->getSubscriberId());

  mediator = new Mediator();
  mediator->subscribe(sub1);
  mediator->subscribe(sub2);
  mediator->subscribe(sub3);
  mediator->printSubscribers();

  delay(10000);
}

void loop() {
  heartbeat->act();
  firstButton->act();
  subscriber->act();
  messageBus->clear();
  delay(10);
}
