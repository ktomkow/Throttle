#include "Arduino.h"

#include "../domain.h"

void printMessage(const Message& message) {
  Serial.println("----------------------------------");
  Serial.print("Message Type: ");
  switch (message.type) {
    case MSG_BUTTON_STATE_CHANGED:
      Serial.println("MSG_BUTTON_STATE_CHANGED");
      Serial.print("Button ID: ");
      Serial.println(message.payload.buttonStateChangePayload.id);
      Serial.print("Button State: ");
      switch (message.payload.buttonStateChangePayload.state) {
        case UNDEFINED_INPUT_STATE:
          Serial.println("UNDEFINED_INPUT_STATE");
          break;
        case INACTIVE_INPUT_STATE:
          Serial.println("INACTIVE_INPUT_STATE");
          break;
        case ACTIVE_INPUT_STATE:
          Serial.println("ACTIVE_INPUT_STATE");
          break;
      }
      break;

    case MSG_POTENTIOMETER_STATE_CHANGED:
      Serial.println("MSG_POTENTIOMETER_STATE_CHANGED");
      Serial.print("Potentiometer ID: ");
      Serial.println(message.payload.potentiometerStateChangedPayload.id);
      Serial.print("Potentiometer State: ");
      Serial.println(message.payload.potentiometerStateChangedPayload.state);
      break;

    case MSG_CONFIG_MODE_CHANGED:
      Serial.println("MSG_CONFIG_MODE_CHANGED");
      Serial.print("Config Mode Active: ");
      Serial.println(message.payload.configModeChangedPayload.isActive ? "true" : "false");
      break;

    case MSG_EMPTY_MESSAGE:
    default:
      Serial.println("MSG_EMPTY_MESSAGE or Undefined");
      break;
  }

  Serial.println("----------------------------------");
}