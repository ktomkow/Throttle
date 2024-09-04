#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
#include "./src/button/button.h"
#include "./src/mediator/mediator.h"
#include "./src/lever/lever.h"

Heartbeat* heartbeat;
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
}

void loop() {
  heartbeat->act();
  firstButton->act();
  lever->act();
}
