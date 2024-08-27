#ifndef ENUMERABLE_H
#define ENUMERABLE_H

template<typename T>
class Collection {
private:
  T* _collection;
  int _capacity;
  int _size;
  void extend();

public:
  Collection();
  void push(const T&);
  void clear();
  int getSize();
  ~Collection();

  class Enumerator {
  private:
    Collection* _array;
    unsigned short _currentIndex;

  public:
    Enumerator(Collection& collection);

    T& getCurrent();

    bool getNext();
  };

  virtual Enumerator getEnumerator();
};

template<typename T>
Collection<T>::Collection() {
  _capacity = 4;
  _size = 0;
  _collection = new T[_capacity];
}

template<typename T>
void Collection<T>::extend() {
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
Collection<T>::~Collection() {
  delete[] _collection;
}


template<typename T>
void Collection<T>::push(const T& element) {
  if (_size >= _capacity) {
    extend();
  }

  _collection[_size++] = element;
}

template<typename T>
void Collection<T>::clear() {
  _size = 0;
}

template<typename T>
int Collection<T>::getSize() {
  return _size;
}


template<typename T>
Collection<T>::Enumerator::Enumerator(Collection& collection) {
  _array = &collection;
  _currentIndex = -1;
}

template<typename T>
T& Collection<T>::Enumerator::getCurrent() {
  return _array->_collection[_currentIndex];
}

template<typename T>
bool Collection<T>::Enumerator::getNext() {
  if (_currentIndex + 1 < _array->getSize()) {
    _currentIndex++;
    return true;
  }
  return false;
}

template<typename T>
typename Collection<T>::Enumerator Collection<T>::getEnumerator() {
  return Enumerator(*this);
}

#endif