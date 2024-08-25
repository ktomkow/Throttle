#ifndef enumerable.h
#define enumerable .h

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


#endif