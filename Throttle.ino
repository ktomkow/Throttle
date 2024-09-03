#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
#include "./src/messageBus/messageBus.h"

Heartbeat* heartbeat;
MessageBus* messageBus;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initialized Serial");

  heartbeat = new Heartbeat();

  messageBus = new MessageBus();
  messageBus->printStats();

  // Przykładowe wiadomości
  BusMessage message1;
  message1.type = MSG_BUTTON_STATE_CHANGED;
  message1.payload.buttonStateChangePayload.id = 1;
  message1.payload.buttonStateChangePayload.state = ACTIVE_INPUT_STATE;

  BusMessage message2;
  message2.type = MSG_POTENTIOMETER_STATE_CHANGED;
  message2.payload.potentiometerStateChangedPayload.id = 2;
  message2.payload.potentiometerStateChangedPayload.state = 512;

  // Dodanie wiadomości do tablicy
  messageBus->publish(message1);
  messageBus->publish(message2);
  messageBus->printStats();
  messageBus->printContent();

  
  messageBus->clear();

  Serial.flush();
}

void loop() {
  heartbeat->act();
  delay(10);
}
