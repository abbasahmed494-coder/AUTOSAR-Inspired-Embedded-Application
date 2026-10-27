#include "SensorMonitor.h"

const unsigned long TASK_PERIOD_MS = 2000;
unsigned long lastRunMs = 0;

void setup() {
  Serial.begin(115200);
  SensorMonitor_Init();
}

void loop() {
  const unsigned long now = millis();
  if (now - lastRunMs >= TASK_PERIOD_MS) {
    lastRunMs = now;
    SensorMonitor_Run();
  }
}
