
#include <AUnit.h>

#include "../src/queue.h"

test(bar) {
  // Arrange
  Queue q;

  // Act
  int result = q.getOne();

  // Assert
  assertEqual(result, 0);
}
