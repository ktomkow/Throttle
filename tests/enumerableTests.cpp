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
  Collection<int>::Enumerator a = ints.getEnumerator();
  bool isEmpty = a.getNext() == false;

  // Assert
  assertEqual(false, isEmpty);
}

test(collection_enumerator_pushAndEnumerableAndGetPushedItem) {
  // Arrange
  Collection<int> ints;

  ints.push(13);

  // Act
  Collection<int>::Enumerator a = ints.getEnumerator();
  a.getNext();
  int result = a.getCurrent();

  // Assert
  assertEqual(13, result);
}
