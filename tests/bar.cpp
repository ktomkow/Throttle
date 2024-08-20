
#include <AUnit.h>

#include "../src/masterInclude.h"

test(bar) {
  // Arrange
  Queue q;

  // Act
  int result = q.getOne();

  // Assert
  assertEqual(result, 0);
}
