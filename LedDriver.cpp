#include "LedDriver.h"

namespace {
  constexpr uint8_t WARNING_LED_PIN = 7;
}

void LedDriver_Init(void) {
  pinMode(WARNING_LED_PIN, OUTPUT);
  digitalWrite(WARNING_LED_PIN, LOW);
}

void LedDriver_SetWarning(bool active) {
  digitalWrite(WARNING_LED_PIN, active ? HIGH : LOW);
}
