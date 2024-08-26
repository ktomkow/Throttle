#include <AUnit.h>

#include "../src/enumerable/enumerable.h"
#include "../src/enumerable/enumerable.cpp"

test(collection_initialSizeShouldBeZero) {
  // Arrange
  Collection<int> ints;

  // Act
  int size = ints.getSize();

  // Assert
  assertEqual(size, 0);
}


test(collection_push) {
  // Arrange
  Collection<int> ints;

  ints.push(5);
  ints.push(1);

  // Act
  Collection<int>::Enumerator a = ints.getEnumerator();
  bool isEmpty = a.getNext() == false;

  // Assert
  assertEqual(isEmpty, false);
}
