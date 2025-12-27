#include "./filter.h"

static const short coefficients[10] = {
  7342, 5873, 4699, 3759, 3007,
  2406, 1925, 1540, 1232, 984
};

Filter::Filter() {
  for (unsigned short i = 0; i < SAMPLES_COUNT; i++) {
    _samples[i] = 0;
  }
}

unsigned short Filter::process(unsigned short value) {
  _samples[_index] = value;

  long acc = 0;

  short j = (short)_index;

  for (unsigned short k = 0; k < SAMPLES_COUNT; ++k) {
    acc += (long)_samples[(unsigned short)j] * (long)coefficients[k];

    j -= 1;
    if (j < 0) {
      j = (short)(SAMPLES_COUNT - 1);
    }
  }

  acc += (acc >= 0) ? (1L << 14) : -(1L << 14);
  long y = acc >> 15;

  _index += 1;
  if (_index >= SAMPLES_COUNT) {
    _index = 0;
  }

  return saturateToUShort(y);
}

unsigned short Filter::saturateToUShort(long v) {
  if (v <= 0L) {
    return (unsigned short)0;
  }

  if (v >= 65535L) {
    return (unsigned short)65535;
  }

  return (unsigned short)v;
}