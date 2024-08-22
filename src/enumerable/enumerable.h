#ifndef enumerable.h
#define enumerable.h

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
  // ~SimpleArray();
  // virtual Enumerator<T> getEnumerator() override;
};


#endif