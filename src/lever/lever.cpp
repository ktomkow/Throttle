#include "./lever.h"

Lever::Lever(unsigned short id, int pin, bool useDebugOutput, const Mediator* mediator)
  : Publisher(mediator) {
  Serial.print("Lever ");
  Serial.print(id);
  Serial.println(" constructor STARTED");

  _id = id;
  _pin = pin;
  _isInitialized = false;
  _useDebugOutput = useDebugOutput;
  _filter = new Filter();

  Serial.print("Lever ");
  Serial.print(id);
  Serial.println(" constructor FINISHED");
}

void Lever::printState() {
  Serial.println("***********************");
  Serial.print("Lever: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.print(" is initialized: ");
  Serial.println(_isInitialized);

  Serial.print("Physical State: ");
  Serial.println(_physicalState);

  Serial.print("Min physical read: ");
  Serial.print(_minPhysicalRead);
  Serial.print(" Max physical read: ");
  Serial.println(_maxPhysicalRead);
  Serial.println("***********************");
}

void Lever::init() {
  Serial.println("***********************");
  Serial.print("Lever: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.println(" initialization STARTED");

  _isInitialized = true;
  _physicalState = makeRead();
  _logicState = recalculateLogicalState();
  reportLogicalState();

  Serial.print("Lever: ");
  Serial.print(_id);
  Serial.print(" on PIN: ");
  Serial.print(_pin);
  Serial.println(" initialization FINISHED");
  Serial.println("***********************");
}

void Lever::act() {
  if (_isInitialized != true) {
    return;
  }

  _physicalState = makeRead();
  unsigned short logicState = recalculateLogicalState();

  // do not report if nothing changed
  if (logicState == _logicState) {
    return;
  }

  // todo: change this - when trend is continuous diff should be smaller
  // do not report if difference is small
  unsigned short diff = (_logicState > logicState) ? _logicState - logicState : logicState - _logicState;
  if (diff < 3) {
    return;
  }

  _logicState = logicState;
  reportLogicalState();

  if (_useDebugOutput) {
    Serial.print("Lever_");
    Serial.print(_id);
    Serial.print(":");
    Serial.println(_logicState);
  }
}

void Lever::handle(const ButtonStateChangedPayload& payload) {
  if (payload.state == ACTIVE_INPUT_STATE && payload.id == 9) {
    calibrate();
  }
}

unsigned short Lever::recalculateLogicalState() {
  short valueToMap = _physicalState;
  if (valueToMap > _maxPhysicalRead) {
    valueToMap = _maxPhysicalRead;
  }

  if (valueToMap < _minPhysicalRead) {
    valueToMap = _minPhysicalRead;
  }

  return map(valueToMap, _minPhysicalRead, _maxPhysicalRead, _minLogicRead, _maxLogicRead);
}

unsigned short Lever::makeRead() {
  unsigned short readValue = analogRead(_pin);
  return _filter->process(readValue);
}

void Lever::reportLogicalState() {
  Message message;
  message.type = MSG_POTENTIOMETER_STATE_CHANGED;
  message.payload.potentiometerStateChangedPayload.id = _id;
  message.payload.potentiometerStateChangedPayload.state = _logicState;

  Publisher::publish(message);
}

void Lever::calibrate() {
  unsigned short currentValue = makeRead();
  if (currentValue > _borderline) {
    _maxPhysicalRead = currentValue - _borderOffset;
  } else {
    _minPhysicalRead = currentValue + _borderOffset;
  }
}
