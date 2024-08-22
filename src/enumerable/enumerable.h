#ifndef enumerable.h
#define enumerable .h

template<typename T>
class Enumerator {
public:
  // virtual void moveNext();
  // virtual T* getCurrent();
};

template<typename T>
class Enumerable {
public:
  // virtual Enumerator<T> getEnumerator();
};

template<typename T>
// class MyArray : public Enumerable<T> {
class MyArray {

private:
  T* _collection;
  int _capacity;
  int _size;
  void extend();
public:
  MyArray();
  void push(T*);
  // virtual Enumerator<T> getEnumerator() override;
};

#endif