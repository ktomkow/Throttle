#include <AUnit.h>

#include "../src/enumerable/enumerable.h"
#include "../src/enumerable/enumerable.cpp"


test(collection_push) {
  // Arrange
  Collection<int> mycollection;

  mycollection.push(5);

  // Act

  // Assert
  assertEqual(1, 0);
}
