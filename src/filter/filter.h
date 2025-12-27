#ifndef FILTER_H
#define FILTER_H

class Filter {
private:
  static constexpr unsigned short SAMPLES_COUNT = 10;
  unsigned short _samples[SAMPLES_COUNT];
  unsigned short _index;
  static unsigned short saturateToUShort(long v);
public:
  Filter();
  unsigned short process(unsigned short value);
};

#endif