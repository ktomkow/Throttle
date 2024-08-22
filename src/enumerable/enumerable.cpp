#include "enumerable.h"

template<typename T>
MyArray<T>::MyArray() {
  _capacity = 4;
  _size = 0;
  _collection = new T[_capacity];
}

template<typename T>
void MyArray<T>::extend() {
  unsigned short newCapacity = _capacity + 2;
  T* oldCollection = _collection;

  delete[] _collection;

  _collection = new T[newCapacity];

  for (unsigned short i = 0; i < _capacity; i++) {
    _collection[i] = oldCollection[i];
  }

  _capacity = newCapacity;
}