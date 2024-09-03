#include "./src/domain.h"
#include "./src/printer/printer.h"
#include "./src/heartbeat/heartbeat.h"
#include "./src/messageBus/messageBus.h"
#include "./src/subscriber/subscriber.h"

Heartbeat* heartbeat;
MessageBus* messageBus;
Subscriber* subscriber;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Initialized Serial");

  heartbeat = new Heartbeat();

  messageBus = new MessageBus();
  subscriber = new Subscriber(messageBus);
  // messageBus->printStats();

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
  Serial.println("Now printContent");
  messageBus->printContent();

  Serial.println("End of printContent");

  // Serial.println("Now go through");

  // for (unsigned short i = 0; i < messageBus->getSize(); ++i) {
  //   Serial.print("Accessing element ");
  //   Serial.print(i);
  //   Serial.println(" via operator[]:");
  //   printBusMessage((*messageBus)[i]);  // Wywołanie funkcji printBusMessage
  //   Serial.println("-----------------------");
  // }


  // Serial.println("End of go through");

  Serial.println();
  Serial.println("==========================");
  Serial.println("***** END  OF  SETUP *****");
  Serial.println("==========================");
  Serial.println();
  Serial.flush();
}

void loop() {
  heartbeat->act();
  subscriber->act();
  messageBus->clear();
  delay(10);
}
