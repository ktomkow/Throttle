#include <AUnit.h>

#include "../src/enumerable/enumerable.h"
#include "../src/enumerable/enumerable.cpp"

test(collection_initialSizeShouldBeZero) {
  // Arrange
  Collection<int> ints;

  // Act
  int size = ints.getSize();

  // Assert
  assertEqual(0, size);
}


test(collection_enumerator_pushThenGetNextShouldReturnTrue) {
  // Arrange
  Collection<int> ints;

  ints.push(5);

  // Act
  Collection<int>::Enumerator enumerator = ints.getEnumerator();
  bool isEmpty = enumerator.getNext() == false;

  // Assert
  assertEqual(false, isEmpty);
}

test(collection_enumerator_pushAndEnumerableAndGetPushedItem) {
  // Arrange
  Collection<int> ints;

  ints.push(13);

  // Act
  Collection<int>::Enumerator enumerator = ints.getEnumerator();
  enumerator.getNext();
  int result = enumerator.getCurrent();

  // Assert
  assertEqual(13, result);
}

test(collection_enumerator_pushManyElementsAndGetThemInSameOrder) {
  // Arrange
  Collection<int> ints;

  ints.push(1);
  ints.push(70);
  ints.push(12567);
  ints.push(-257);
  ints.push(122);

  // Act
  Collection<int>::Enumerator enumerator = ints.getEnumerator();
  enumerator.getNext();
  int first = enumerator.getCurrent();
  enumerator.getNext();
  int second = enumerator.getCurrent();
  enumerator.getNext();
  int third = enumerator.getCurrent();
  enumerator.getNext();
  int fourth = enumerator.getCurrent();
  enumerator.getNext();
  int fifth = enumerator.getCurrent();

  // Assert
  assertEqual(1, first);
  assertEqual(70, second);
  assertEqual(12567, third);
  assertEqual(-257, fourth);
  assertEqual(122, fifth);
}

test(collection_whenClearedThenSizeZero_enumerator_getNextIsFalse) {
  // Arrange
  Collection<int> ints;

  // Act
  ints.push(5);
  ints.push(5);
  ints.push(5);
  ints.push(5);
  ints.clear();
  int size = ints.getSize();

  Collection<int>::Enumerator enumerator = ints.getEnumerator();
  bool isEmpty = enumerator.getNext() == false;

  // Assert
  assertEqual(0, size);
  assertEqual(true, isEmpty);
}
