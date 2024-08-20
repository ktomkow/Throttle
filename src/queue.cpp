#include "queue.h"

Queue::Queue() {
  _i = 0;
}

int Queue::getOne() {
  return _i++;
}