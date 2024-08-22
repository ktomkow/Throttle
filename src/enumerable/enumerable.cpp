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

  T* newCollection = new T[newCapacity];

  for (unsigned short i = 0; i < _size; i++) {
    newCollection[i] = _collection[i];
  }

  delete[] _collection;

  _collection = newCollection;
  _capacity = newCapacity;
}

template<typename T>
void MyArray<T>::push(T* element) {
}