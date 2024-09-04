#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
#include "./src/button/button.h"
#include "./src/mediator/mediator.h"
#include "./src/lever/lever.h"
#include "./src/reporter/reporter.h"

#include <Joystick.h>

Joystick_ Joystick;

Heartbeat* heartbeat;
Button* firstButton;
Mediator* mediator;
Lever* lever;
Reporter* reporter;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initialized Serial");

  heartbeat = new Heartbeat();

  mediator = new Mediator();

  firstButton = new Button(2, 2, mediator);

  lever = new Lever(38, A0, mediator);

  reporter = new Reporter(&Joystick);

  mediator->subscribe(lever);
  mediator->subscribe(firstButton);
  mediator->subscribe(reporter);

  firstButton->init();
  lever->init();
  lever->printState();

  Joystick.begin(false);
  Joystick.setXAxisRange(0, 255);
  Joystick.setXAxis(98);

  reporter->init();

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

  Joystick.sendState();
}
