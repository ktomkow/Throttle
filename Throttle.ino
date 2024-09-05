#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
#include "./src/button/button.h"
#include "./src/mediator/mediator.h"
#include "./src/lever/lever.h"
#include "./src/reporter/reporter.h"

#include <Joystick.h>

#define BUTTONS_COUNT 10

Joystick_ Joystick;

Heartbeat* heartbeat;
Mediator* mediator;
Button* buttons[BUTTONS_COUNT];
Lever* lever;
Reporter* reporter;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initialized Serial");

  heartbeat = new Heartbeat();

  Serial.println("Joystick initialization STARTED");
  Joystick.begin(false);
  Joystick.setXAxisRange(0, 255);
  Serial.println("Joystick initialization FINISHED");

  mediator = new Mediator();

  buttons[0] = new Button(0, 2, mediator);
  buttons[1] = new Button(1, 3, mediator);
  buttons[2] = new Button(2, 4, mediator);
  buttons[3] = new Button(3, 5, mediator);
  buttons[4] = new Button(4, 6, mediator);
  buttons[5] = new Button(5, 7, mediator);
  buttons[6] = new Button(6, 10, mediator);
  buttons[7] = new Button(7, 14, mediator);
  buttons[8] = new Button(8, 15, mediator);
  buttons[9] = new Button(9, 16, mediator);

  lever = new Lever(38, A0, mediator);

  reporter = new Reporter(&Joystick);

  mediator->subscribe(lever);
  mediator->subscribe(reporter);
  
  for (unsigned short i = 0; i < BUTTONS_COUNT; i++) {
    mediator->subscribe(buttons[i]);
  }

  lever->init();
  lever->printState();

  for (unsigned short i = 0; i < BUTTONS_COUNT; i++) {
    buttons[i]->init();
  }

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
  lever->act();

  for (unsigned short i = 0; i < BUTTONS_COUNT; i++) {
    buttons[i]->act();
  }

  Joystick.sendState();
}
