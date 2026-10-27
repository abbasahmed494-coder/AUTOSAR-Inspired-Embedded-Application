#include "Rte_SensorMonitor.h"
#include "SensorDriver.h"
#include "LedDriver.h"

void Rte_SensorMonitor_Init(void) {
  SensorDriver_Init();
  LedDriver_Init();
}

bool Rte_Read_SensorData(float *temperatureC, float *humidityPercent) {
  return SensorDriver_Read(temperatureC, humidityPercent);
}

void Rte_Write_WarningLed(bool active) {
  LedDriver_SetWarning(active);
}
