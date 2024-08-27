#include <AUnit.h>

#include "../src/dataBus/dataBus.h"
#include "../src/domain.h"


test(dataBus_whenNothingPushed_isAny_shouldBeFalse) {
  // Arrange
  DataBus dataBus;

  // Act
  bool result = dataBus.isAny();

  // Assert
  assertEqual(false, result);
}


test(dataBus_whenPushed_shouldBeAvailableThroughEnumerator) {
  // Arrange
  DataBus dataBus;

  // Act
  BusMessage message;
  message.type = MSG_EMPTY_MESSAGE;
  dataBus.push(message);

  // Assert
  // assertEqual(false, result);
}
